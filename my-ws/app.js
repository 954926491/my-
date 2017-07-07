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

var userList=[];
var mkt=0;

wss.broadcast=function broadcast(userData){
    wss.clients.forEach(function each(client){
        client.send(userData);
    });
};

function createJSON(name,type,msg){
    return JSON.stringify({
        name: name,
        type: type,
        msg: msg
    });
}

wss.on("connection",function(ws){
    var num=JSON.stringify({
        number: wss.clients.length,
        type: 'join',
        list: userList
    });
    ws.send(num);
    ws.on('message',function(msg){

        var obj=eval('(' + msg + ')');
        this.user=obj;
        var len=wss.clients.length;

        for(var i=0;i<userList.length;i++){
            if(this.user.name==userList[i]&&userList.length!=len){
               var err=createJSON('','same','');
               ws.send(err);
               mkt=1;
               break; 
            }
            mkt=0;
        }
        if(mkt==0&&userList.length!=len){
           userList.push(this.user.name);
           console.log(userList);
          // ws.send(userList);
        }
        
        if(typeof this.user.msg!="undefined"&&mkt==0){
           // obj["type"]="chat";
           var userdata=createJSON(this.user.name,'chat',this.user.msg);
           /*JSON.stringify({
               name: this.user.name,
               msg: this.user.msg,
               type: 'chat'
           });*/
            console.log(this.user);
            wss.broadcast(userdata);
        }
    });
    ws.on('close',function(close){
        try{
            var users=createJSON(this.user.name,'close','');
            /*JSON.stringify({
                name: this.user.name,
                msg: '',
                type: 'close'
            });*/
            var target=-1;
            for(var i=0;i<userList.length;i++){
                 if(userList[i]==this.user.name){
                    target=i;
                    break;
                 }
              }
              if(target>=0){
                userList.splice(target,1);
              }
            wss.broadcast(users);
        }
        catch(e){
            console.log('刷新界面');
        }
    });
});