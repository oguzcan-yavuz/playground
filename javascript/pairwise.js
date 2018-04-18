function handlePair(arr, i, j) {
    arr[i] = undefined;
    arr[j] = undefined;
    return i + j;
}

function pairwise(arr, arg) {
    let sumOfIndexes = 0;
    for(let i = 0; i < arr.length - 1; i++) {
        let j = i + 1;
        while(j < arr.length) {
            if(arr[i] + arr[j] === arg) {
                sumOfIndexes += handlePair(arr, i, j);
                break;
            }
            j++;
        }
    }
    return sumOfIndexes;
}

console.log(pairwise([0, 0, 0, 0, 1, 1], 1));
console.log(pairwise([1, 1, 1], 2));
console.log(pairwise([1, 4, 2, 3, 0, 5], 7));
