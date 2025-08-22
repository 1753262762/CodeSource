// 获取.tabbar下的所有div
const divs=document.querySelectorAll('.tabbar div');

// 遍历所有div，并绑定鼠标移动事件
divs.forEach((item)=>{
    item.addEventListener('mousemove',function(e){
        // 计算底部光晕的水平位置
        let left=e.clientX - item.getBoundingClientRect().x;
        // 将计算好的位置赋值给CSS自定义变量--left
        item.style.setProperty('--left',left+'px');
    })
})