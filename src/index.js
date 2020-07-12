const express = require('express');
const cors = require('cors');
// const routes = require('./routes');

const SerialPort = require('serialport');
const socketIo = require('socket.io');
const http = require('http');

const app = express();
const server = http.createServer(app);

//add files statics
app.use(express.static('public'));
app.get('/', (req, res, next) => {
    res.sendFile(__dirname + '/public/index.html');//
});

server.listen(3000, () => {
    console.log('run server: 192.168.1.78')
});

const io = socketIo.listen(server);

//Read serial
const  ReadLine = SerialPort.parsers.Readline;

//read string, bits...
const parser = new ReadLine({delimiter:'\r\n'})
const mySerial = new SerialPort('/dev/ttyUSB0', {
    baudRate:9600
});

mySerial.pipe(parser);

mySerial.on('open', () => {

    console.log('Connection init');
    
    //value serial
    parser.on('data', (data)=>{

        console.log('data', data);
        var dado = parseInt(data);
        
        //emit valor popenciometro
        io.emit("serial:data", {
            value: data
        });
    });

});

//recebendo dado a web e assando para o serial
io.sockets.on('connection', (socket) => {
    console.log('open socket');
    socket.on('btnAction', (btn) =>{
        var dadoWeb = btn.value
        console.log('dadoWeb', dadoWeb);
        mySerial.write(dadoWeb);
        console.log('Enviando'+ dadoWeb+ ' para serial')
    });
});
