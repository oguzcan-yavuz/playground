const mongo = require("mongodb").MongoClient;
const dbName = process.argv[2];
const url = "mongodb://localhost:27017/" + dbName;

mongo.connect(url, (err, db) => {
    if(err) throw err;
    var dbObj = db.db(dbName);
    var users = dbObj.collection('users');
    var query = { name: "Tina" };
    var updateData = { $set: { age: 40 } };
    users.update(query, updateData, (err, data) => {
        if(err) throw err;
        db.close();
    });
});
