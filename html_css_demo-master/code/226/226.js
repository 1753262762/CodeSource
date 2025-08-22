// next按钮
const button=document.querySelector('.btn-next');
// 图片数量
const totalElements=2;
// 图片下标
let index=0;

// 绑定next按钮点击事件
button.onclick=function(){
    // 当前图片
    var currentImage=document.getElementById(`img-${index}`);
    index++;
    if(index>=totalElements){
        // 下标超出，回到第一张
        index=0;
    }
    // 下一张图片
    var nextImage=document.getElementById(`img-${index}`);
    currentImage.classList.add('transition-start');
    currentImage.classList.add('right');
    nextImage.classList.add('transition-end');
    nextImage.classList.add('right');

    // 当前图片动画结束事件
    currentImage.onanimationend=function(){
        currentImage.classList.remove('active');
        currentImage.classList.remove('transition-start');
        currentImage.classList.remove('right');
    }
    // 下一张图片动画结束事件
    nextImage.onanimationend=function(){
        nextImage.classList.add('active');
        nextImage.classList.remove('transition-end');
        nextImage.classList.remove('right');
    }
}