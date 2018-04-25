var modular = require('./modular.js');
modular('.', 'md', function(err, files) {
        files.map((file) => console.log(file));
    }
)
