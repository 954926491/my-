const ws=require("ws");
const express=require('express');
const WebSocketServer=ws.Server;

var app=express();

app.use(express.static(__dirname));

let server = app.listen(3000);

var wss=new WebSocketServer({
    server: server
    //port: 3000
});

wss.broadcast=function broadcast(market,userData){
    wss.clients.forEach(function each(client){
        if(market==1){
            client.send(userData.name+": "+userData.msg);
        } else if(market==0){
            client.send(userData+"退出聊天室");
        }
    });
};

wss.on("connection",function(ws){
    ws.send("你是第"+wss.clients.length+"位");
    ws.on('message',function(msg){
        var obj=eval('(' + msg + ')');
        this.user=obj;
        if(typeof this.user.msg!="undefined"){
            wss.broadcast(1,obj);
        }
    });
    ws.on('close',function(close){
        try{
            wss.broadcast(0,this.user.name);
        }
        catch(e){
            console.log('刷新界面');
        }
    });
});