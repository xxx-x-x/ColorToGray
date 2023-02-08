#ifndef __ConnectToServer_H__
#define __ConnectToserver_H__
#include<sys/socket.h>
#include<sys/types.h>
#include<string>
//input Server_IP and Server_Port
//return a ClientSocket
int ConnectToServer(std::string& domain,std::string& port);


#endif