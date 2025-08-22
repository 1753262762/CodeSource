function init(e){
    // 检查事件目标是否在类名为“item”的元素范围内
    if(!e.target.closest(".item")) return;
    // 选择文档中data-pos属性为0的第一个div元素
    let big=document.querySelector('div[data-pos="0"]');
    // 获取事件源的父元素
    let target=e.target.parentElement;
    // 交换两个元素的位置，通过交换target和big两个DOM元素的“dataset.pos”属性值，来实现位置的交换
    [target.dataset.pos, big.dataset.pos]=[
        big.dataset.pos,
        target.dataset.pos
    ]
}

// 为窗口添加点击事件监听器
window.addEventListener("click",init,false);