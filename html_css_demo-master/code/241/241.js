// 监听鼠标移动事件
document.addEventListener("mousemove",(e)=>{
    // 动态设置CSS变量--x、--y以表示当前鼠标位置
    document.documentElement.style.setProperty('--x',e.clientX);
    document.documentElement.style.setProperty('--y',e.clientY);
})