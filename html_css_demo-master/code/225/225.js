// 要操作的元素
const rangeValue=document.querySelector('#range-value');
const range=document.querySelector('input[type="range"]');
const fillArea=document.querySelector('.fill-area');

// 滑块滑动函数
function handleMouseMove(value){
    // hue-rotate是CSS中的颜色滤镜，可以设置不同的度数来改变颜色
    const hueRotate="hue-rotate("+value+"deg)";

    // 设置进度数值
    rangeValue.textContent=value;
    // 设置颜色滤镜
    rangeValue.style.filter=hueRotate;

    // 设置滑动条的颜色滤镜
    range.style.filter=hueRotate;

    // 显示渐变背景，改变黑色背景的宽度及位置
    fillArea.style.left=value+'vw';
    fillArea.style.width=100-value+'vw';
    fillArea.style.filter=hueRotate;
}