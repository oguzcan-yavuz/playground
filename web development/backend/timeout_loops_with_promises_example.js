let condition = true;
let i = 0;

function timeout(ms) {
    return new Promise(resolve => setTimeout(resolve, ms));
}

async function t() {
    while(condition) {
        console.log("inside loop: " + i);
        await i++;
        await timeout(2000);
        if(i === 5)
            condition = false;
    }
    return i;
}

t().then(console.log);
