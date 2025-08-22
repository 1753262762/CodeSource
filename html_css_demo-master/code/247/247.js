// 获取所有item
const items=document.querySelectorAll('.img-item');

// 遍历所有item
for(let i=0;i<items.length;i++){
    // 第几行
    const r=Math.floor(i / 3);
    // 第几列
    const c=i % 3;
    const bgX=-c * 100 + '%';
    const bgY=-r * 100 + '%';
    // 设置CSS自定义变量
    items[i].style.setProperty('--bgX', bgX);
    items[i].style.setProperty('--bgY', bgY);
}