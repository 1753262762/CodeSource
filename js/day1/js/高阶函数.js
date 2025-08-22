function pow2(x) {
    return x * x;
}
let arr1 = [1, 2, 3, 4, 5];
let arr2 = arr1.map(pow2); //map传入的是函数对象本身
console.log(arr1);
console.log(arr2);

let arr3 = [1, 2, 3, 4, 5];
console.log(arr3.reduce(function (a, b) {
    return a + b;
}));
//or
let arr4 = [1];
console.log(arr4.reduce(function (a, b) {
    return a + b;
}, 0));
let arr5 = [1, 2, 3, 4, 5];
console.log(arr5.reduce(function (a, b) {
    return a * 10 + b;
})); // 12345

let arr6 = [1, 2, 3, 4, 5];
let ReseutArr6 = arr6.filter(function (a) {
    return a % 2 == 0;
});
console.log(ReseutArr6);
//filter()关键在于实现筛选函数
//实例
let fruits = ["apple", "banana", "orange", "grape", "pear", "banana", "apple"];
let ResultFruits = fruits.filter(function (element, index, self) {
    return self.indexOf(element) === index;
});
console.log(ResultFruits);

let arr7 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20];
let PrimeArr7 = arr7.filter(function (x) {
    if (x <= 1) return false;
    for (let i = 2; i <= Math.sqrt(x); ++i) {
        if (x % i == 0) return false;
    }
    return true;
});
console.log(PrimeArr7);
//or
arr7.forEach(x => console.log(x));