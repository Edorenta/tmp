"use strict";

/* LET'S KEEP TRACK OF THE WINDOW SIZE */

var win = {
    w : Math.max(document.documentElement.clientWidth, window.innerWidth || 0),
    h : Math.max(document.documentElement.clientHeight, window.innerHeight || 0),
};
var bar_w;

/* HOW ABOUT WE MAKE THE USER ABLE TO MESS AROUND WITH THE COLORS */

var color_picker = new iro.ColorPicker("#picker", {
  width: win.h / 5,
  height: win.h / 5,
  color: {r: 255, g: 0, b: 0},
  markerRadius: 10,
  padding: 0,
  sliderMargin: 24,
  sliderHeight: 36,
  borderWidth: 2,
  borderColor: "#b4b4b4",
  anticlockwise: true,
});

/* AND SHOW HIM WHAT COLOR HE IS ON */

var clr_caption = document.getElementById("clr_caption");

// https://rakujira.jp/projects/iro/docs/guide.html#color-change
color_picker.on("color:change", function(color){
  clr_caption.innerHTML = [
    "hex: " + color.hexString,
    "rgb: " + color.rgbString,
    "hsl: " + color.hslString,
  ].join("<br>");
});

/* THE FOLLOWING FUNCTION CODE USES P5JS FOR CANVAS RENDERING AND IS THE CORE OF THE VISUALIZER */

var ptr = [];
var details_pane;
var details_box;
var speed_slider;
var speed_box;
var container;
var commands_list;
var unsorted_list;
var op_details;
var op_count;
var op_list;
var int_list;
var max;
var min;
var mult;
var data;
var stack = [];
var bars = [];
var it = 0;
var canvas;
var nb_int;
var nb_op;
var x_g_pad = win.w / 9.2;
var x_pad = x_g_pad / 4;
var looping = false;

Array.prototype.max = function() {
    return Math.max.apply(null, this);
};

Array.prototype.min = function() {
    return Math.min.apply(null, this);
};

class Stack {
    constructor(op, a, b) {
        this.a = a;
        this.b = b;
        this.op = op;
    }
}

class Bars {
    constructor(pass) {
        this.a = [];
        this.b = [];
        this.op = pass.op;
        this.na = pass.a ? Object.keys(pass.a).length : 0;
        this.nb = pass.b ? Object.keys(pass.b).length : 0;
        this.nx = this.na + this.nb;
        this.step = (win.w / 2.2) / Math.max(this.na, this.nb);
        for (let i = 0; i < this.na; i++) 
            this.a[i] = pass.a[i] - min + 1;
        for (let i = 0; i < this.nb; i++)
            this.b[i] = pass.b[i] - min + 1;
    }
    display() {
        for(let i = 0; i < 8; i++) ptr[i].classList.add("hidden");
        this.step = (win.w / 2.2) / Math.max(this.na, this.nb);
        let x;
        let y;
        let moved_a = [];
        let moved_b = [];
        op_count = 'Operation #' + it;
        switch (this.op) {
            case 'sa':
                op_details = 'SA\nswaps a[0] and a[1]'
                moved_a[0] = 0;
                moved_a[1] = 1;
                break;
            case 'sb':
                op_details = 'SB\nswaps b[0] and b[1]'
                moved_b[0] = 0;
                moved_b[1] = 1;
                break;
            case 'ss':
                op_details = 'SS\nswaps a[0] and a[1]\nswaps b[0] and b[1]'
                moved_a[0] = 0;
                moved_a[1] = 1;
                moved_b[0] = 0;
                moved_b[1] = 1;
                break;
            case 'pa':
                op_details = 'PA\nswaps a[0] and a[last]'
                moved_a[0] = 0;
                moved_b[0] = 0;
                break;
            case 'pb':
                op_details = 'PB\nswaps b[0] and b[last]'
                moved_a[0] = 0;
                moved_b[0] = 0;
                break;
            case 'ra':
                op_details = 'RA\nrotates a:\npushs a[last] to front of a[0]\nremoves a[last]'
                moved_a[0] = this.na - 1;
                break;
            case 'rb':
                op_details = 'RB\nrotates b:\npushs b[last] to front of b[0]\nremoves b[last]'
                moved_b[0] = this.nb - 1;
                break;
            case 'rr':
                op_details = 'RR\nrotates a and b:\npushs a[last] to front of a[0]\nremoves a[last]\npushs b[last] to front of b[0]\nremoves b[last]'
                moved_a[0] = this.na - 1;
                moved_b[0] = this.nb - 1;
                break;
            case 'rra':
                op_details = 'RRA\nreverse rotates a:\npushs a[0] after a[last]\npops a[0]'
                moved_a[0] = 0;
                break;
            case 'rrb':
                op_details = 'RRB\nreverse rotates b:\npushs b[0] after b[last]\npops b[0]'
                moved_b[0] = 0;
                break;
            case 'rrr':
                op_details = 'RRA\nreverse rotates a and b'
                moved_a[0] = 0;
                moved_b[0] = 0;
                break;
            default:
                moved_a[0] = this.na;
                moved_a[1] = this.na;
                moved_b[0] = this.nb;
                moved_b[1] = this.nb;
        }
        strokeWeight(1);
        stroke(color(211,140,0));
        fill(color(50,50,50));
        let ptr_index = 0;
        for (let i = 0; i < this.na; i++) {
            y = this.a[i] * mult;
            x = x_pad + (this.step) * i;
            if (i == moved_a[0] || i == moved_a[1]) {
                move_ptr(x, ptr_index++);
                fill(color(211,140,0));
                stroke(color(50,50,50));
                rect(x, -y, this.step - 2, y);
                stroke(color(211,140,0));
                fill(color(50,50,50));
            }
            else rect(x, -y, this.step - 2, y);
        }
        stroke(color(0,180,0));
        fill(color(50,50,50));
        for (let i = 0; i < this.nb; i++) {
            y = this.b[i] * mult;
            x = (win.w / 2) + x_pad + (this.step) * i;
            if (i == moved_b[0] || i == moved_b[1]) {
                move_ptr(x, ptr_index++);
                fill(color(0,180,0));
                stroke(color(50,50,50));
                rect(x, -y, this.step - 2, y);
                stroke(color(0,180,0));
                fill(color(50,50,50));
            }
            else rect(x, -y, this.step - 2, y);
        }
        if (looping && it == (nb_op)) {
            document.getElementById('bt1').innerHTML = looping ? "▶ START" : "▣ STOP";
            looping ? noLoop() : loop();
            looping = looping ? 0 : 1;
        }
    }
}

function move_ptr(x, i) {
    ptr[i].style.left = x + 'px';
    ptr[i + 4].style.left = x + 'px';
    ptr[i].classList.remove("hidden");
    ptr[i + 4].classList.remove("hidden");
}

function refresh_box() {
    bar_w = container.offsetWidth;
    speed_box.style.left = Math.round(((bar_w - 14) * (speed_slider.value) / 60) - 21, 0) + 'px';
    set_speed();
}

function get_stacks(int_list, op_list) {
    nb_op = op_list.length;
    for (let i = 0; i <= nb_op; i++) {
        if (i == 0) {
            stack[i] = new Stack('init', int_list, null);
            //console.log("i:", i, "list[0]: ", stack[i].a[0], "list[1]: ", stack[i].a[1], "op:", stack[i].op); console.log(stack[i].a);
        }
        else
        {
            let dump_a = stack[i - 1].a ? stack[i - 1].a.slice(0) : null;
            let dump_b = stack[i - 1].b ? stack[i - 1].b.slice(0) : null;
            stack[i] = new Stack(op_list[i - 1], dump_a, dump_b);
            let a_last = stack[i].a ? stack[i].a.length - 1 : 0;
            let b_last = stack[i].b ? stack[i].b.length - 1 : 0;
            switch (stack[i].op) {
                case 'ss':
                case 'sa':
                    if (stack[i].a && typeof stack[i].a[0] !== 'undefined' && typeof stack[i].a[1] !== 'undefined'){
                        [stack[i].a[0], stack[i].a[1]] = [stack[i].a[1], stack[i].a[0]];
                    }
                    if (stack[i].op == 'sa')
                        break;
                case 'sb':
                    if (stack[i].b && typeof stack[i].b[0] !== 'undefined' && typeof stack[i].b[1] !== 'undefined')
                        [stack[i].b[0], stack[i].b[1]] = [stack[i].b[1], stack[i].b[0]]; 
                    break;
                case 'pa':
                    if (stack[i].b) {
                        if (!(stack[i].a)) stack[i].b = [];
                        stack[i].a.unshift(stack[i].b[0]);
                        stack[i].b.shift();
                    }
                    break;
                case 'pb':
                    if (stack[i].a) {
                        if (!(stack[i].b)) stack[i].b = [];
                        stack[i].b.unshift(stack[i].a[0]);
                        stack[i].a.shift();
                    }
                    break;
                case 'rr':
                case 'ra':
                    if (stack[i].a && typeof stack[i].a[a_last] !== 'undefined') {
                        stack[i].a.push(stack[i].a[0]);
                        stack[i].a.shift();
                    }
                    if (stack[i].op == 'ra')
                        break;
                case 'rb':
                    if (stack[i].b && typeof stack[i].b[b_last] !== 'undefined') {
                        stack[i].b.push(stack[i].b[0]);
                        stack[i].b.shift();
                    }
                    break;
                case 'rrr':
                case 'rra':
                    if (stack[i].a && typeof stack[i].a[a_last] !== 'undefined') {
                        stack[i].a.unshift(stack[i].a[a_last]);
                        stack[i].a.pop();
                    }
                    if (stack[i].op == 'rra')
                        break;
                case 'rrb':
                    if (stack[i].b && typeof stack[i].b[b_last]) {
                        stack[i].b.unshift(stack[i].b[b_last]);
                        stack[i].b.pop();
                    }
                    break;
            }
            //console.log("i:", i, "op:", stack[i].op); console.log("A:", stack[i].a, "B:", stack[i].b);
        }
    }
}

function setup() {
    noLoop();
    ptr[0] = document.getElementById('ptr_1');
    ptr[1] = document.getElementById('ptr_2');
    ptr[2] = document.getElementById('ptr_3');
    ptr[3] = document.getElementById('ptr_4');
    ptr[4] = document.getElementById('ptr_5');
    ptr[5] = document.getElementById('ptr_6');
    ptr[6] = document.getElementById('ptr_7');
    ptr[7] = document.getElementById('ptr_8');
    details_box = document.getElementById("show_details");
    details_pane = document.getElementById("details_pane");
    op_details = document.getElementById('op_details').innerHTML;
    op_count = document.getElementById('op_count').innerHTML;
    speed_slider = document.getElementById('speed_slider');
    speed_box = document.getElementById('speed_box');
    container = document.getElementById('speed_set');
    commands_list = document.getElementById('commands').innerHTML;
    unsorted_list = document.getElementById('int_list').innerHTML;
    canvas = createCanvas(win.w, win.h);
    //canvas.position(0, 0);
    //canvas.style('display', 'absolute');
    bar_w = container.offsetWidth;
    speed_slider.addEventListener('input', refresh_box);
    speed_box.addEventListener('input', refresh_box);
    //document.getElementById("title_div").className '+=' "rubberBand animated";
    op_list = JSON.parse(commands_list).commands;
    int_list = JSON.parse(unsorted_list).unsorted_list;
    //nb_int = Object.keys(int_list).length;
    nb_int = int_list.length;
    nb_op = op_list.length;
    max = int_list.max();
    min = int_list.min();
    mult = (win.h / 1.5) / (max - min);
    get_stacks(int_list, op_list);
    for (let pass = 0; pass <= nb_op; pass++)
        bars[pass] = new Bars(stack[pass]);
}

function canvas_resize() {
    win.w = Math.max(document.documentElement.clientWidth, window.innerWidth || 0);
    win.h = Math.max(document.documentElement.clientHeight, window.innerHeight || 0);
    resizeCanvas(win.w, win.h, true);
}

function windowResized() {
    canvas_resize();
    set_origin();
    set_speed();
    bars[it].display();
}

function set_origin() {
    translate(0, height / 6 * 5); //set bottom left as origin
    background(0);
    stroke(color(150,150,150));
    strokeWeight(1);
    line(0, 0, win.w, 0);
    line(win.w / 2, 0, win.w / 2, -win.h / 6 * 4.15);
}

function set_speed() {
    frameRate(speed_box.value * 1);
}

function draw() {
    canvas_resize();
    set_origin();
    set_speed();
    bars[it].display();
    if (it < nb_op) it++;
}

function _reset() {
    it = 0;
    redraw();
    looping == false ? noLoop() : 0;
}

function _next() {
    //for(let i = 0; i < 8; i++) ptr[i].classList.remove("hidden");
    redraw();
    noLoop();
}

function _prev() {
    //for(let i = 0; i < 8; i++) ptr[i].classList.remove("hidden");
    it = it > 1 ? it -= 2 : 0;
    redraw();
    noLoop();
}

function _switch() {
    document.getElementById('bt1').innerHTML = looping ? "▶ START" : "▣ STOP";
    //if (looping) for(let i = 0; i < 4; i++) ptr[i].classList.remove("hidden"); //toggle = add or remove depending on previous state
    if (!looping) for(let i = 0; i < 8; i++) ptr[i].classList.add("hidden");
    noLoop();
    looping ? noLoop() : loop();
    looping = looping ? 0 : 1;
    it == nb_int ? _reset() : 0;
}

function toggle_details() {
    if (details_box.checked == true) details_pane.classList.remove("hidden");
    else details_pane.classList.add("hidden");
}