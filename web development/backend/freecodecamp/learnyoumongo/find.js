const mongo = require('mongodb').MongoClient;
const url = "mongodb://localhost:27017/learnyoumongo";

mongo.connect(url, (err, db) => {
    var age = parseInt(process.argv[2]);
    var dbObj = db.db("learnyoumongo");
    var cursor = dbObj.collection('parrots').find({ age: { $gt: age } });
    cursor.toArray((err, documents) => {
        if(err) throw err;
        console.log(documents);
    });
    db.close();
});
