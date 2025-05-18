const http = require('http');

const server = http.createServer((req,res) => {
    if (req.url === '/') {
        res.write('Hello World');
        res.end();
    }
    if (req.url === '/menu') {
        res.write('Food menu being displayed');
        res.end();
    }
    if (req.url === '/api/users') {
        res.write('Users list being viewed');
        res.end();
    }
});

server.listen(5000);
console.log("Listening at port 5000...");