function sumIndexes(arr, a, b, arg) {
  return (a + b === arg) ? arr.indexOf(a) + arr.indexOf(b) : 0;
}

function pairwise(arr, arg) {
  let sum = 0;
    arr.reduce((acc, curr) => {
      console.log(acc + " : " + curr);
      console.log(acc + curr);
      sum += sumIndexes(arr, acc, curr, arg);
      return acc;
    });
  return sum;
}

pairwise([1,4,2,3,0,5], 7);
