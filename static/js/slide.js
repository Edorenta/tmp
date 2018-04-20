(function($){
  $.fn.slideBar = function(){
    var elem = $(this);
    var children = elem.find(".list");
    var length = children.length;
    var width = children.eq(0).width();
    elem.css("width", length*width + 'px');
    var index = 0;
      setTime(index,0);
    $(".slide-dot .dot").hover(function(){
        index = $(this).index();
        $(".archi-left .list").eq(index).fadeIn();
        $(".archi-left .list").eq(index).siblings().css("display","none");
        elem.stop().animate({"left": -(index*width) + 'px'});
        $(".slide-dot .dot").eq(index).addClass('active').siblings().removeClass('active');
        clearInterval(interval);
    },function(){
        prev = index-1;
        if(index >= length-1) prev = 0;
        if(index <=0) prev = 4;
        setTime(index,prev);
    });
    var interval;
    function setTime(index,prev) {
        console.log(index ,prev);
        var speed = 1;
        if(index >= length -1) speed = -1;
        if(index <= 0) speed = 1;
        interval = setInterval(function(){
            prev = index;
            index+=speed;
            var current = index;
            $(".archi-left .list").eq(current).fadeIn();
            $(".archi-left .list").eq(current).siblings().css("display","none");
            $(".archi-left .list").eq(index).siblings().css("display","none");

            elem.stop().animate({"left": -(index*width) + 'px'});
            $(".slide-dot .dot").eq(index).addClass('active').siblings().removeClass('active');
            if(index >= length -1) speed = -1;
            if(index <= 0) speed = 1;

        },5000);
    }
  }
})(jQuery);