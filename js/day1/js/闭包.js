//原始写法
function SumAdd(arr) {
    return arr.reduce(function (x, y) {
        return x + y;
    });
};
console.log(SumAdd([1, 2, 3, 4, 5]));

//使用闭包
function NewSumAdd(arr) {
    let res = function () {
        return arr.reduce(function (x, y) {
            return x + y;
        })
    }
    return res;
}
let f = NewSumAdd([1, 2, 3, 4, 5]);
// console.log(f);
console.log(f());