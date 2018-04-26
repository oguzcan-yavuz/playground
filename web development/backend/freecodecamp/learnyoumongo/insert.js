const mongo = require('mongodb').MongoClient;
const url = "mongodb://localhost:27017/learnyoumongo";

mongo.connect(url, (err, db) => {
    if(err) throw err;
    var names = { "firstName": process.argv[2], "lastName": process.argv[3] };
    var dbObj = db.db("learnyoumongo");
    var docs = dbObj.collection("docs");
    docs.insert(names, (err, data) => {
        if(err) throw err;
        console.log(JSON.stringify(names));
        db.close();
    });
});

