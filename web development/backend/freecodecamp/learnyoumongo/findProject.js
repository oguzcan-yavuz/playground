const mongo = require('mongodb').MongoClient;
const url = "mongodb://localhost:27017/learnyoumongo";

mongo.connect(url, (err, db) => {
    if(err) throw err;
    var age = parseInt(process.argv[2]);
    var dbObj = db.db("learnyoumongo");
    var query = { age: { $gt: age } };
    var projection = { _id: false, name: true, age: true };
    var cursor = dbObj.collection('parrots').find(query).project(projection);
    cursor.toArray((err, documents) => {
        if(err) throw(err);
        console.log(documents);
    });
    db.close();
});

