function spreadTest() {
    let arr = [1, 2, 3, 4, 5];
    arr.reduce((acc, cur) => {
        console.log("acc: " + acc + " : curr: " + cur);
        return [...arr, cur - 100];
    });
}

spreadTest();
