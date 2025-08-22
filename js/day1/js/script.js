var r = 123.456;
console.log(r);

function hello() {
    'use strict';
    // helloString="Hello World";//strict mode error
    // console.log(helloString);
}
hello();
let name = "John";
let age = 30;
let message = `My name is ${name} and I am ${age} years old.`;
console.log(message);
let xiaohong = {
    name: "小红",
    'middle-school': 'NO.1 Middle School'
};
xiaohong.hasOwnProperty('name'); //true
xiaohong.hasOwnProperty('age'); //false
for (let key in xiaohong) {
    console.log(key);
}
let a = ['a', 'b', 'c', 'd'];
for (let i = 0; i < a.length; ++i) {
    console.log(a[i]);
}
for (let i of a) {
    console.log(i);
}