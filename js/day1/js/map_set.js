let m = new Map([
    ['Michael', 95],
    ['Bob', 85],
    ['Alice', 75]
]);
console.log(m.get('Michael'));
m.set('Tom', 65);
console.log(m.has('Tom'));

let s = new Set([1, 2, 3, 4, 5, 5, 4, 3, 2, 1]);
for (let key of s) {
    console.log(key);
}
s.delete(5);
console.log('\n');
for (let key of s) {
    console.log(key);
}
console.log('\n')
for (let key of m) {
    console.log(key);
}
console.log('\n')
s.forEach(function (value) {
    console.log(value)
});