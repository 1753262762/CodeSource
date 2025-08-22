// 当DOM内容加载完成时触发动画
document.addEventListener("DOMContentLoaded", () => {
  // 定义要显示的文本
  const text = "HELLO WORLD";
  // 获取用于显示动画的容器元素
  const container = document.querySelector(".animated-text");

  //   循环为每个字符创建一个span元素，包括空格
  text.split("").forEach((char) => {
    const span = document.createElement("span");
    span.className = "letter";
    span.innerHTML = char === " " ? "&nbsp;" : char;
    container.appendChild(span);
  });

  //   获取所有的字母元素
  const letters = document.querySelectorAll(".letter");
  const totalLetters = letters.length;
  //   延迟增量，单位毫秒
  const delayIncrement = 100;

  //   定义一个缓动函数，用于动画平滑过渡
  function easeInOutQuart(t) {
    return t < 0.5 ? 8 * t * t * t * t : 1 - 8 * --t * t * t * t;
  }

  //   动画函数
  function animateLetters(forward = true) {
    letters.forEach((letter, index) => {
      // 计算延迟时间，使用缓动函数进行平滑处理
      const normalizedIndex =
        Math.max(index, totalLetters - 1 - index) / (totalLetters - 1);
      const easedDelay = easeInOutQuart(normalizedIndex);
      const delay = easedDelay * (totalLetters - 1) * delayIncrement;

      //   使用setTimeout实现动画效果
      setTimeout(() => {
        letter.style.setProperty("--wght", forward ? 700 : 100);
        letter.style.setProperty("--wdth", forward ? 300 : 150);
        letter.style.setProperty("--opacity", forward ? 1 : 0.25);
        letter.style.setProperty(
          "--letter-spacing",
          forward ? "0.05em" : "0em"
        );
      }, delay);
    });

    // 设置下一个动画周期的超时，实现动画循环播放
    setTimeout(() => {
      animateLetters(!forward);
    }, 4000);
  }

  //   开始播放动画
  animateLetters();
});
