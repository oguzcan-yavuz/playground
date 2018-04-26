const mongo = require('mongodb').MongoClient;
const dbName = process.argv[2];
const url = "mongodb://localhost:27017/" + dbName;

mongo.connect(url, (err, db) => {
    var collectionName = process.argv[3];
    var id = process.argv[4];
    var dbObj = db.db(dbName);
    var cursor = dbObj.collection(collectionName);
    cursor.remove({ _id: id }, (err) => {
        if(err) throw err;
        db.close();
    });
});
