// 要操作的元素
const container=document.querySelector('.container');
const topLayer=container.querySelector('.top');
const handle=container.querySelector('.handle');
// 初始化skew和delta为0
let skew=0,delta=0;

// 判断container的class中是否包含'skewed'
if(container.className.indexOf('skewed')>-1){
    // 将skew设为1000
    skew=1000;
}

container.addEventListener('mousemove',function(e){
    // 计算鼠标移动的距离
    delta=(e.clientX - window.innerWidth / 2) * 0.5;
    // 设置handle的左边距
    handle.style.left=e.clientX + delta + 'px';
    // 设置topLayer的宽度
    topLayer.style.width=e.clientX + skew + delta + 'px';
})