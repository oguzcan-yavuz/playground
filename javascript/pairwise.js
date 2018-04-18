function checkSum(arr, a, b, arg) {
    if(a + b === arg)
        console.log("a: " + a + " a index: " + arr.indexOf(a) + " b: " + b + " b index: " + arr.indexOf(b) + " indexSum: " + (arr.indexOf(a) + arr.indexOf(b)));
    // TODO: indexOf fonksiyonuna, ayni elemanlar verilince aradaki ayrimi dogal olarak yapmiyor, belli bir
    // indexten sonrasina baktirmak lazim, indexOf ikinci parametre olarak start indexi aliyor. start indexi belirle.
    // TODO: ayrica eslesen bir ciftin iki elemani da tekrar kullanilamiyor.

    // gen yerine iterator yap. dizinin kopyasini olusturmamak icin. ayrica entries kullan. pair olan elemanlari NaN yap.
    return (a + b === arg) ? sumOfIndexes(arr, a, b) : 0;
}

function sumOfIndexes(arr, a, b) {
    return arr.indexOf(a) + arr.indexOf(b);
}

function* reduceFromHead(arr) {
    let i = 0;
    while(i < arr.length)
        yield arr.slice(i++);
}

function checkArrValues(arr, reducedArr, arg) {
  let sumOfReducedArrIndexes = 0;
  reducedArr.reduce((acc, cur) => {
    sumOfReducedArrIndexes += checkSum(arr, acc, cur, arg);
    return acc;
  });
  return sumOfReducedArrIndexes;
}

function pairwise(arr, arg) {
    let totalSumOfIndexes = 0;
    let reducedArrGen = reduceFromHead(arr);
    for(let reducedArr of reducedArrGen)
        totalSumOfIndexes += checkArrValues(arr, reducedArr, arg);
    return totalSumOfIndexes;
}

console.log(pairwise([0, 0, 0, 0, 1, 1], 1));
