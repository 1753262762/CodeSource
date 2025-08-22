let second=``;
for(let i=0;i<60;i++){
    let div=`<div id="second${i+1}" style="font-size:20px;width:100%;text-align:right;position:absolute;display:inline-block;transform:rotate(${(i-1)*-6}deg);">${i+1} 秒</div>`;
    second=second+div;
}
document.querySelector('.second-box').innerHTML=second;

let minute=``;
for(let i=0;i<60;i++){
    let div=`<div id="minute${i+1}" style="font-size:20px;width:100%;text-align:right;position:absolute;display:inline-block;transform:rotate(${i*-6}deg);">${i+1} 分</div>`;
    minute=minute+div;
}
document.querySelector('.minute-box').innerHTML=minute;

let hour=``;
for(let i=0;i<24;i++){
    let div=`<div id="hour${i+1}" style="font-size:20px;width:100%;text-align:right;position:absolute;display:inline-block;transform:rotate(${i*-15}deg);">${i+1} 时</div>`;
    hour=hour+div;
}
document.querySelector('.hour-box').innerHTML=hour;

let day=``;
// 每个月的天数
let _days=[31,28,31,30,31,30,31,31,30,31,30,31];
let _now=new Date();
let _year=_now.getFullYear();
let _month=_now.getMonth();
// 判断闰年的天数 二月为29天
if(_year%4===0 && (_year%100!==0 || _year%400===0)){
    _days[1]=29;
}
// 计算平均角度
let _deg=360/_days[_month];
for(let i=0;i<_days[_month];i++){
    let div=`<div id="day${i+1}" style="font-size:20px;width:100%;text-align:right;position:absolute;display:inline-block;transform:rotate(${i*-1*_deg}deg);">${i+1} 日</div>`;
    day=day+div;
}
document.querySelector('.day-box').innerHTML=day;

let month=``;
for(let i=0;i<12;i++){
    let div=`<div id="month${i+1}" style="font-size:20px;width:100%;text-align:right;position:absolute;display:inline-block;transform:rotate(${i*-30}deg);">${i+1} 月</div>`;
    month=month+div;
}
document.querySelector('.month-box').innerHTML=month;

let second360=0;
let minute360=0;
let hour360=0;
let day360=0;
let month360=0;

let oldsecond=0;
let oldminute=0;
let oldhour=0;
let oldday=0;
let oldmonth=0;

function transformBox(){
    let nowDate=new Date();
    let second=nowDate.getSeconds();
    let minute=nowDate.getMinutes();
    let hour=nowDate.getHours();
    let day=nowDate.getDate();
    let month=nowDate.getMonth();
    let year=nowDate.getFullYear();
    if(second===0 && oldsecond!==second){
        second360=second360+1;
    }
    if(minute===0 && oldminute!==minute){
        minute360=minute360+1;
    }
    if(hour===0 && oldhour!==hour){
        hour360=hour360+1;
    }
    if(day===0 && oldday!==day){
        day360=day360+1;
    }
    if(month===0 && oldmonth!==month){
        month360=month360+1;
    }
    document.querySelector('.second-box').style.transform=`rotate(${second360*360+(second-1)*6}deg)`;
    document.querySelector('.minute-box').style.transform=`rotate(${minute360*360+(minute-1)*6}deg)`;
    document.querySelector('.hour-box').style.transform=`rotate(${hour360*360+(hour-1)*15}deg)`;
    document.querySelector('.day-box').style.transform=`rotate(${day360*360+(day-1)*_deg}deg)`;
    document.querySelector('.month-box').style.transform=`rotate(${month360*360+month*30}deg)`;
    document.querySelector('.year-box').innerHTML=year+' 年';
    let nowDates=document.querySelectorAll('.now-date');
    nowDates.forEach((ele)=>{
        ele.classList='';
    });
    document.querySelector(`#second${second+1}`).classList='now-date';
    document.querySelector(`#minute${minute===0?'60':minute}`).classList='now-date';
    document.querySelector(`#hour${hour===0?'24':hour}`).classList='now-date';
    document.querySelector(`#day${day}`).classList='now-date';
    document.querySelector(`#month${month+1}`).classList='now-date';

    oldsecond=second;
    oldminute=minute;
    oldhour=hour;
    oldday=day;
    oldmonth=month;
}
transformBox();
setInterval(()=>{
    transformBox();
},1000);