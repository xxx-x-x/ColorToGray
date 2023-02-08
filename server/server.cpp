#include<stdio.h>
#include<iostream>
#include<sys/socket.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<fstream>
using namespace std;
int main(){
    int server = socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in seraddr;
    seraddr.sin_family=AF_INET;
    seraddr.sin_addr.s_addr= htonl(INADDR_ANY);
    seraddr.sin_port = htons(8070);
    if(bind(server,(sockaddr*)&seraddr,sizeof(seraddr))==-1){
        std:: cout << "server bind failed !" << std::endl;
    }

    if(listen(server,10)==-1){
        std:: cout << "server listen failed !" << std:: endl;
    }

    struct sockaddr_in cliaddr;
    socklen_t st = sizeof(cliaddr);
    int client = accept(server,(struct sockaddr*)&cliaddr,&st);
    
    //int client = accept(server,(struct sockaddr*)&cliaddr,(socklen_t*)sizeof(cliaddr));
    //checkout file size
    int size;
    recv(client,&size,sizeof(int),0);
    std::cout << size << std::endl;
    char* buffer = new char[size];
    send(client,&size,sizeof(int),0);

    //save file
    recv(client,buffer,size,0);
    ofstream os("./2.png",ios::out);
    os.write(buffer,size);
    std::cout << "Write success" << std::endl;
    return 0;
}