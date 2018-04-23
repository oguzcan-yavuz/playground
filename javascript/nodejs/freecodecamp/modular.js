module.exports = function(search, extension, callback) {
    // reads the directory
    var fs = require('fs');
    var path = require('path');
    var list = [];
    extension = "." + extension;
    fs.readdir(search, function(err, data) {
        // gives an error if there is an error accurs
        if(err) return callback(err);
        // checks every item in data
        data.forEach(function(file) {
        // if the extension of the file is same with the user provides, prints it to the screen
            if(path.extname(file) === extension) {
                list.push(file);
            }
        });
        return callback(err, list);
    });
};
