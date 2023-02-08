#include"include/ConnectToServer.h"
#include<string>
#include<netinet/in.h>
#include<arpa/inet.h>

int ConnectToServer(std::string& domain,std::string& port)
{
    static int soc = socket(AF_INET,SOCK_STREAM,0);
    sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(domain.c_str());
    server.sin_port = htons(stoi(port));
    connect(soc,(sockaddr*)&server,sizeof(server));
    return soc;
}