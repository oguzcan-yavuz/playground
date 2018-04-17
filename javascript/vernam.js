function binaryToStr(bin) {
    let s = [];
    bin = bin.split("");
    for(let i = 0; i < bin.length; i += 8)
        s.push(String.fromCharCode(parseInt(bin.slice(i, i + 8).join(""), 2)));
    return s.join('');
}

function charToBinary(c) {
    return c.charCodeAt(0).toString(2).padStart(8, "0");
}

function splitter(args) {
    let r = [];
    for(let key in arguments) {
        if(arguments.hasOwnProperty(key))
            r.push(arguments[key].split(""));
    }
    return r;
}

function vernamCrypt(p, k) {
    if(p.length !== k.length)
        throw "Uzunluklar esit degil!";
    let r = [];
    [p, k] = splitter(p, k);
    for(let i = 0; i < p.length; i++) {
        let pToBin = charToBinary(p[i]);
        let kToBin = charToBinary(k[i]);
        for(let j = 0; j < 8; j++)
            r.push(pToBin[j] ^ kToBin[j]);
    }
    return r.join('');
}

function vernamDecrypt(c, k) {
    if(c.length / 8 !== k.length)
        throw "Uzunluklar esit degil!";
    let r = [];
    [c, k] = splitter(c, k);
    for(let i = 0; i < c.length; i += 8) {
        let kToBin = charToBinary(k[i / 8]);
        for(let j = 0; j < 8; j++)
            r.push(c[i + j] ^ kToBin[j]);
    }
    return r.join('');
}

// let a = "aa";
// let b = "aa";
//
// let c = vernamCrypt(a, b);
// let p = vernamDecrypt(c, b);
//
// console.log(c);
// console.log(binaryToStr(c));
// console.log(p);
// console.log(binaryToStr(p));
console.log(vernamDecrypt("0100101101001110", "aa"));
console.log(vernamCrypt("aa", "aa"));
