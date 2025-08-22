function* Fibonacci() {
    let first = 0,
        second = 1;
    while (true) {
        yield first;
        [first, second] = [second, first + second];
    }
}

let f = Fibonacci();
console.log(f.next());
console.log(f.next());
console.log(f.next());
console.log(f.next());
console.log(f.next());