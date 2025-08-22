// Slider类用于创建一个滑动器实例，管理图片的展示和切换
class Slider{
    // 构造函数，初始化Slider对象
    constructor(slider){
        // 初始化滑动对象
        this.slider=slider;
        // 获取图片显示区域
        this.display=slider.querySelector('.image-display');
        // 获取所有导航按钮并转换为数组
        this.navButtons=Array.from(slider.querySelectorAll('.nav-button'));
        // 上一张按钮
        this.prevButton=slider.querySelector('.prev-button');
        // 下一张按钮
        this.nextButton=slider.querySelector('.next-button');
        // 获取导航
        this.sliderNavigation=slider.querySelector('.slider-navigation');
        // 初始化当前焦点图索引
        this.currentSlideIndex=0;
        // 初始化预加载图片对象
        this.preloadedImages={};
        // 执行初始化操作
        this.initialize();
    }

    // 初始化操作
    initialize(){
        // 初始化滑动功能
        this.setupSlider();
        // 预加载图片
        this.preloadImages();
        // 绑定事件监听器
        this.eventListeners();
    }

    // 设置初始状态，显示第一张图片
    setupSlider(){
        this.showSlide(this.currentSlideIndex);
    }

    // 显示指定索引的图片，并更新导航按钮的状态
    showSlide(index){
        this.currentSlideIndex=index;
        const navButtonImg=this.navButtons[this.currentSlideIndex].querySelector('img');
        if(navButtonImg){
            const imgClone=navButtonImg.cloneNode();
            this.display.replaceChildren(imgClone);
        }
        this.updateNavButtons();
    }

    // 更新导航按钮的状态，设置当前选择的导航按钮的aria-selected属性
    updateNavButtons(){
        this.navButtons.forEach((button,buttonIndex)=>{
            const isSelected=buttonIndex===this.currentSlideIndex;
            button.setAttribute('aria-selected',isSelected);
            if(isSelected) button.focus();
        })
    }

    // 预加载所有导航按钮相关的图片，以提高加载效率
    preloadImages(){
        this.navButtons.forEach((button)=>{
            const imgElement=button.querySelector('img');
            if(imgElement){
                const imgSrc=imgElement.src;
                if(!this.preloadedImages[imgSrc]){
                    this.preloadedImages[imgSrc]=new Image();
                    this.preloadedImages[imgSrc].src=imgSrc;
                }
            }
        })
    }

    // 添加事件监听器，监听键盘事件和导航按钮点击事件
    eventListeners(){
        document.addEventListener('keydown',(event)=>{
            this.handleAction(event.key);
        });
        this.sliderNavigation.addEventListener('click',(event)=>{
            const targetButton=event.target.closest('.nav-button');
            const index=targetButton ? this.navButtons.indexOf(targetButton) : -1;
            if(index!==-1){
                this.showSlide(index);
            }
        })
        this.prevButton.addEventListener('click',()=>this.handleAction('prev'));
        this.nextButton.addEventListener('click',()=>this.handleAction('next'));
    }
    // 根据不同的动作切换图片或跳转到指定图片
    handleAction(action){
        if(action==='Home'){
            this.currentSlideIndex=0;
        }else if(action==='End'){
            this.currentSlideIndex=this.navButtons.length-1;
        }else if(action==='ArrowRight'||action==='next'){
            this.currentSlideIndex=(this.currentSlideIndex+1) % this.navButtons.length;
        }else if(action==='ArrowLeft'||action==='prev'){
            this.currentSlideIndex=(this.currentSlideIndex-1+this.navButtons.length) % this.navButtons.length;
        }

        this.showSlide(this.currentSlideIndex);
    }
}

// 创建一个Slider实例，传递.image-slider容器作为参数
const ImageSlider=new Slider(document.querySelector('.image-slider'));