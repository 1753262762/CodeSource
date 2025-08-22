function abs(x) {
    return x >= 0 ? x : -x;
}
// 或者可以这么写
// let abs = function (x) {
//     return x >= 0 ? x : -x;
// };

function add(x, y) {
    console.log(arguments);
    return x + y;
}
console.log(add(2, 3)); // 5

//rest参数用法
function foo(a, b, ...rest) {
    console.log('a = ' + a);
    console.log('b = ' + b);
    console.log(rest);
}
let xiaoming = {
    name: '小明',
    birth: 1990,
    age: function () {
        return new Date().getFullYear() - this.birth;
    }
};
console.log(xiaoming.age());