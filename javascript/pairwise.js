function pairwise(arr, arg) {
    let sums = 0;
    for(let i = 0; i < arr.length - 1; i++) {
        let j = i + 1;
        for(let j = i + 1; j < arr.length; j++) {
            if(arr[i] + arr[j] === arg) {
                sums += i + j;
                arr[i] = undefined;
                arr[j] = undefined;
                break;
            }
        }
    }
    return sums;
}

console.log(pairwise([0, 0, 0, 0, 1, 1], 1));
console.log(pairwise([1, 1, 1], 2));
console.log(pairwise([1, 4, 2, 3, 0, 5], 7));
