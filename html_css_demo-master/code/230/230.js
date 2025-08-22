const container=document.querySelector('.container');
const boxs=document.querySelectorAll('.box');
container.style.height=`${boxs.length}00%`;
// 定义当前页面的索引
let pageIndex=0;
// 定义是否允许滚动
let pageScroll=true;
// 定义上一次页面的索引
let prevIndex=0;

// 向上滚动
function scrollUp(){
    if(pageIndex>0 && pageScroll){
        prevIndex=pageIndex;
        pageIndex--;
        scrollToPage(pageIndex);
    }else if(pageIndex<=0){
        pageIndex=0;
    }
}
// 向下滚动
function scrollDown(){
    if(pageIndex<boxs.length-1 && pageScroll){
        prevIndex=pageIndex;
        pageIndex++;
        scrollToPage(pageIndex);
    }else if(pageIndex>=boxs.length-1){
        pageIndex=boxs.length-1;
    }
}
// 滚动到指定页面
function scrollToPage(pageIndex){
    container.style.top=`-${pageIndex}00%`;
    pageScroll=false;
    scrollTimer();
}
// 设置定时器，等待500毫秒后，允许再次滚动
function scrollTimer(){
    setTimeout(() => {
        pageScroll=true;
    }, 500);
}
// 鼠标滚轮事件
function mouseWheel(e){
    if(e.wheelDelta){
        if(e.wheelDelta>0){
            scrollUp();
        }else{
            scrollDown();
        }
    }else{
        if(e.detail>0){
            scrollDown();
        }else{
            scrollUp();
        }
    }
}
// 添加鼠标滚轮事件
document.onmousewheel=mouseWheel;
document.addEventListener('DOMMouseScroll',mouseWheel,false);
// 设置滚动记录
history.scrollRestoration='manual';