#include<stdio.h>
#include"include/ParseUrl.h"
#include"include/ConnectToServer.h"
#include<string>
#include<iostream>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<fstream>

using namespace std;
string Url;
string Protocol,User,Password,Domain,Path,Port;
int main(int argc,char* argv[]){
    // Parse URL
    //std::cout << "input URL" << std::endl;
    //std::cin >> Url;
    Url = "http://43.143.131.87:8070/";
    ParseURL(Url,Protocol,Domain,Port,Path,User,Password);
    //Create Socket
    int soc = ConnectToServer(Domain,Port);
    std::cout << soc << std::endl;
    //Open File
    std::ifstream is(argv[1],ifstream::in);
    if(!is.is_open())
    {
        std::cout<<"file open failed " << std::endl;
    }
    //Send Size To Server
    is.seekg(0,is.end);
    int FileSize = is.tellg();
    send(soc,&FileSize,sizeof(int),0);
    std::cout << "send size " << FileSize << std::endl;

    is.seekg(0,is.beg);
    char * buffer = new char[FileSize];
    is.read(buffer,FileSize);
    //Recv Flag and Send Picture To Server
    int flag = 1;
    recv(soc,&flag,sizeof(int),0);
    std:: cout<< "recv size " << flag << std::endl;
    if(flag == FileSize) 
    {
        send(soc,buffer,FileSize,0);
    }
    std::cout << "buffer size" << FileSize << std::endl;
}