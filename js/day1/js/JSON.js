let xiaoming = {
    name: "xiaoming",
    age: 20,
    gender: "male",
    height: 170,
    garments: ["shirt", "pants", "shoes"]
}
let s = JSON.stringify(xiaoming, null, ' ');
console.log(s);