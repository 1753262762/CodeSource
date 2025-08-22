const canvas = document.querySelector(".canvas");
const ctx = canvas.getContext("2d");

// 获取设备像素比
const pixelRatio = window.devicePixelRatio || 1;

// 创建雪花的数组
const snowflakes = [];

// 定义雪花的构造函数
class Snowflake {
  constructor() {
    // 雪花的x坐标，随机生成
    this.x = Math.random() * canvas.width;
    // 雪花的y坐标，随机生成
    this.y = Math.random() * canvas.height;
    // 雪花的最大尺寸
    const maxSize = 3;
    // 雪花的尺寸，随机生成
    this.size = Math.random() * (maxSize - 1) + 1;
    // 雪花的速度，尺寸乘以0.35
    this.velocity = this.size * 0.35;
    // 雪花的透明度
    const opacity = this.size / maxSize;
    // 雪花的填充颜色、透明度
    this.fill = `rgb(255 255 255 / ${opacity})`;
    // 雪花的风速
    this.windSpeed = (Math.random() - 0.5) * 0.1;
    // 雪花的风的角度
    this.windAngle = Math.random() * Math.PI * 2;
  }
  // 判断雪花是否超出画布
  isOutsideCanvas() {
    return this.y > canvas.height + this.size;
  }
  // 重置雪花的坐标
  reset() {
    this.x = Math.random() * canvas.width;
    this.y = -this.size;
  }
  // 更新雪花的坐标
  update() {
    this.windAngle += this.windSpeed;
    this.wind = Math.cos(this.windAngle) * 0.5;

    this.x += this.wind;
    this.y += this.velocity;

    if (this.isOutsideCanvas()) {
      this.reset();
    }
  }
  // 绘制雪花
  draw() {
    ctx.beginPath();
    ctx.arc(this.x, this.y, this.size, 0, Math.PI * 2);
    ctx.fillStyle = this.fill;
    ctx.fill();
    ctx.closePath();
  }
}

// 创建雪花的函数
const createSnowflakes = () => {
  // 计算雪花的数量，根据画布的宽高比计算
  snowflakeCount = Math.floor(window.innerWidth * window.innerHeight / 1400);

  // 循环创建雪花的实例
  for (let i = 0; i < snowflakeCount; i++) {
    snowflakes.push(new Snowflake());
  }
};

// 重置画布的函数
const resizeCanvas = () => {
  // 获取画布的宽高
  const width = window.innerWidth;
  const height = window.innerHeight;
  // 设置画布宽高
  canvas.width = width * pixelRatio;
  canvas.height = height * pixelRatio;
  canvas.style.width = width + "px";
  canvas.style.height = height + "px";
  // 设置画布的缩放比例
  ctx.scale(pixelRatio, pixelRatio);
  // 清空雪花的数组
  snowflakes.length = 0;
  // 重新创建雪花的实例
  createSnowflakes();
};

// 监听画布的resize事件,调用resizeCanvas函数
window.addEventListener("resize", resizeCanvas);

resizeCanvas();

// 渲染函数
const render = () => {
  requestAnimationFrame(render);

  // 清空画布
  ctx.clearRect(0, 0, canvas.width, canvas.height);
  // 遍历雪花的数组,更新雪花的坐标,绘制雪花
  snowflakes.forEach((snowflake) => {
    snowflake.update();
    snowflake.draw();
  });
};

// 开始渲染
render();
