#include"include/ParseUrl.h"
#include<string>
#include<stdio.h>
#include<iostream>
using namespace std;

void ParseURL(string & Url, string & Protocol, string & Domain, string & Port, string & Path, string & User, string & Password)
{
    int Lpro,Lpath;
//  http://43.143.131.87:8080/microsoft.txt 
//  http://xx-xzh.xyz:80/microsoft.txt
//  https://xzh:123321@xx-xzh.xyz:80/microsoft.txt
//  https://xzh:123321@xx-xzh.xyz/microsoft.txt
    Lpro = Url.find("//");
    Protocol = Url.substr(0,Lpro-1);
    string resPath = Url.substr(Lpro+2);

    Lpath = resPath.find("/");
    Path = resPath.substr(Lpath);
    string resDomain;
    resDomain = Url.substr(Lpro+2,Lpath);
    if(resDomain.find('@')!= -1){
        string tmpDomain = resDomain.substr(resDomain.find('@')+1);
        int temp = resDomain.substr(0,resDomain.find('@')).find(':');
        User = resDomain.substr(0,resDomain.find('@')).substr(0,temp);
        Password = resDomain.substr(0,resDomain.find('@')).substr(temp+1);
        if(tmpDomain.find(':')!=-1){
            Domain = tmpDomain.substr(0,tmpDomain.find(':'));
            Port = tmpDomain.substr(tmpDomain.find(':')+1);
        }else{
            Domain = tmpDomain;
            Port = "80";
        }
     }else{
        if(resDomain.find(':')!=-1){
            Domain = resDomain.substr(0,resDomain.find(':'));
            Port = resDomain.substr(resDomain.find(':')+1);
        }else{
            Domain = resDomain;
            Port ="80";
        }
        User = "";
        Password = "";
    }
    cout << "Protocol:" << Protocol << endl;
    cout << "User:" << User << endl;
    cout << "Password:" << Password << endl;
    cout << "Domain:" << Domain << endl;
    cout << "Port:" << Port << endl;
    cout << "Path:" << Path << endl << endl << endl;

}