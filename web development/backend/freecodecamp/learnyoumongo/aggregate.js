const mongo = require('mongodb').MongoClient;
const dbName = "learnyoumongo";
const url = "mongodb://localhost:27017/" + dbName;

mongo.connect(url, (err, db) => {
    if(err) throw err;
    var givenSize = process.argv[2];
    var dbObj = db.db(dbName);
    var cursor = dbObj.collection("prices");
    var match = { $match: { size: givenSize } };
    var group = { $group: { _id: 'avgPrice', avgPrice: { $avg: '$price' } } };
    cursor.aggregate([match, group]).toArray((err, results) => {
        if(err) throw err;
        console.log(results[0]["avgPrice"].toFixed(2));
        db.close();
    });
});
