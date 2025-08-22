function getAge() {
    return new Date().getFullYear() - this.birth;
}
let xiaoming = {
    name: '小明',
    birth: 1990,
    age: getAge
};

console.log(xiaoming.age());
console.log(getAge.apply(xiaoming, []));
console.log(getAge.apply(xiaoming,[]));