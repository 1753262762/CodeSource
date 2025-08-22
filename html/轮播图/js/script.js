window.onload = function () {
    let imglist = document.querySelectorAll('.imglist>a')
    let leftBtn = document.querySelector('.leftBtn')
    let rightBtn = document.querySelector('.rightBtn')
    let btnlist = document.querySelectorAll('.btnlist>span')
    let index = 0;
    let time;
    autoplay();
    btnClick();

    function autoplay() {
        time = setInterval(() => {
            index == imglist.length - 1 ? index = 0 : index++;
            public()
        }, 2500)
    }
    leftBtn.onclick = function () {
        clearInterval(time);
        index == 0 ? index = imglist.length - 1 : index--;
        public()
        autoplay();
    }
    rightBtn.onclick = function () {
        clearInterval(time);
        index == imglist.length - 1 ? index = 0 : index++;
        public()
        autoplay();
    }

    function public() {
        for (let i = 0; i < imglist.length; i++) {
            imglist[i].classList.remove('show');
            btnlist[i].classList.remove('che');
        }
        imglist[index].classList.add('show');
        btnlist[index].classList.add('che');
    }

    function btnClick() {
        for (let i = 0; i < btnlist.length; i++) {
            btnlist[i].onclick = function () {
                clearInterval(time);
                index = i;
                public();
                autoplay();
            }
        }
    }
}