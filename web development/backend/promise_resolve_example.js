function f() {
    return Promise.resolve("A");
}

function t() {
    return "A";
}

console.log(f());
f().then((value) => console.log(value));

console.log(t());
