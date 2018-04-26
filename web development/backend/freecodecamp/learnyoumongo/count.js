const mongo = require('mongodb').MongoClient;
const dbName = "learnyoumongo";
const url = "mongodb://localhost:27017/" + dbName;

mongo.connect(url, (err, db) => {
    if(err) throw err;
    var age = parseInt(process.argv[2]);
    var dbObj = db.db(dbName);
    var cursor = dbObj.collection("parrots");
    var query = { age: { $gt: age } };
    cursor.count(query, (err, count) => {
        if(err) throw err;
        console.log(count);
        db.close();
    });
});
