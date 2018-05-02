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

/* THE FOLLOWING FUNCTION CODE USES P5JS FOR CANVAS RENDERING AND IS THE COREOF THE VISUALIZER */

var speed_slider;
var speed_box;
var container;
var commands_div;
var int_list_div;
var op_list;
var int_list;

var max;
var min;
var mult;
var data;
var stacks = {
    op : null,
    a : [],
    b : [],
};
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

class Bar {
    constructor(pass) {
        this.a = [];
        this.b = [];
        this.op = pass.op;
        this.na = Object.keys(pass.a).length;
        this.nb = Object.keys(pass.b).length;
        this.nx = this.na + this.nb;
        this.step = (win.w / 2.2) / Math.max(this.na, this.nb);
        for (let i = 0; i < this.na; i++) 
            this.a[i] = pass.a[i] - min + 1;
        for (let i = 0; i < this.nb; i++)
            this.b[i] = pass.b[i] - min + 1;
    }
    display() {
        this.step = (win.w / 2.2) / Math.max(this.na, this.nb);
        let x;
        let y;
        let moved_a = [];
        let moved_b = [];
        switch (this.op) {
            case 'sa':
                moved_a[0] = 0;
                moved_a[1] = 1;
                break;
            case 'sb':
                moved_b[0] = 0;
                moved_b[1] = 1;
                break;
            case 'ss':
                moved_a[0] = 0;
                moved_a[1] = 1;
                moved_b[0] = 0;
                moved_b[1] = 1;
                break;
            case 'pa':
                moved_a[0] = 0;
                moved_b[0] = 0;
                break;
            case 'pb':
                moved_a[0] = 0;
                moved_b[0] = 0;
                break;
            case 'ra':
                moved_a[0] = this.na - 1;
                break;
            case 'rb':
                moved_b[0] = this.nb - 1;
                break;
            case 'rr':
                moved_a[0] = this.na - 1;
                moved_b[0] = this.nb - 1;
                break;
            case 'rra':
                moved_a[0] = 0;
                break;
            case 'rrb':
                moved_b[0] = 0;
                break;
            case 'rrr':
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
        for (let i = 0; i < this.na; i++) {
            y = this.a[i] * mult;
            x = x_pad + (this.step) * i;
            if (i == moved_a[0] || i == moved_a[1]) {
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
                fill(color(0,180,0));
                stroke(color(50,50,50));
                rect(x, -y, this.step - 2, y);
                stroke(color(0,180,0));
                fill(color(50,50,50));
            }
            else rect(x, -y, this.step - 2, y);
        }
        if (looping && it == (nb_int - 1)) {
            document.getElementById('bt1').innerHTML = looping ? "▶ START" : "▣ STOP";
            looping ? noLoop() : loop();
            looping = looping ? 0 : 1;
        }
    }
}

function refresh_box() {
    bar_w = container.offsetWidth;
    speed_box.style.left = Math.round(((bar_w - 14) * (speed_slider.value) / 60) - 21, 0) + 'px';
    set_speed();
}

function setup() {
    noLoop();
    speed_slider = document.getElementById('speed_slider');
    speed_box = document.getElementById('speed_box');
    container = document.getElementById('speed_set');
    commands_div = document.getElementById('commands').innerHTML;
    int_list_div = document.getElementById('list').innerHTML;
    canvas = createCanvas(win.w, win.h);
    //canvas.position(0, 0);
    //canvas.style('display', 'absolute');
    bar_w = container.offsetWidth;
    speed_slider.addEventListener('input', refresh_box);
    speed_box.addEventListener('input', refresh_box);
    //document.getElementById("title_div").className '+=' "rubberBand animated";
    op_list = JSON.parse(commands_div).commands;
    int_list = JSON.parse(int_list_div).unsorted_list;
    //nb_int = Object.keys(int_list).length;
    nb_int = int_list.length;
    nb_op = commands.length;
    console.log(int_list);
    max = Math.max(int_list.max());
    min = Math.min(int_list.min());
    mult = (win.h / 1.5) / (max - min);
    for (let pass = 0; pass < nb_int; pass++)
        bar[pass] = new Bar(data[pass]);
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
    stacks[it].display();
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
    stacks[it].display();
    if (it < nb_int - 1) it++;
}

function _reset() {
    it = 0;
    redraw();
    looping == false ? noLoop() : 0;
}

function _next() {
    redraw();
    noLoop();
}

function _prev() {
    it = it > 1 ? it -= 2 : 0;
    redraw();
    noLoop();
}

function _switch() {
    document.getElementById('bt1').innerHTML = looping ? "▶ START" : "▣ STOP";
    looping ? noLoop() : loop();
    looping = looping ? 0 : 1;
    it == nb_int -1 ? _reset() : 0;
}
