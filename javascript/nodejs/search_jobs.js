const rp = require('request-promise-native');

function get_companies() {
    // example: https://maps.googleapis.com/maps/api/place/nearbysearch/json?location=-33.8670522,151.1957362&radius=500&type=restaurant&keyword=cruise&key=YOUR_API_KEY
    const api_key = "AIzaSyCeaN9xCVnbdfAl6ZGAEu6g8n1mwW2aMMw";
    const location = "41.013725,28.9187643";
    const radius = "8000";
    const keyword = encodeURIComponent("yazılım");
    let page_token = "";
    let query_url = "https://maps.googleapis.com/maps/api/place/nearbysearch/json?location="
        + location + "&radius=" + radius + "&keyword=" + keyword + "&key=" + api_key + "&pagetoken=" + page_token;

    rp({ uri: query_url, resolveWithFullResponse: true }).then(function(response) {
        console.log(response)
    }).catch(console.log)
}

get_companies();
