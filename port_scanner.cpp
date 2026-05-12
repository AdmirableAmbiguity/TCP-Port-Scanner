#include<iostream>
#include<winsock2.h>

#pragma comment(lib,"ws2_32.lib")

using namespace std;

int main()
{
    WSADATA wsa;

    WSAStartup(MAKEWORD(2,2), &wsa);

    string ip;
    int start;
    int end;

    cout<<"Enter IP Address : ";
    cin>>ip;

    cout<<"Enter Starting Port : ";
    cin>>start;

    cout<<"Enter Ending Port : ";
    cin>>end;

    cout<<"\nScanning...\n";

    for(int i=start;i<=end;i++)
    {
        SOCKET s;

        s = socket(AF_INET, SOCK_STREAM, 0);

        sockaddr_in server;

        server.sin_family = AF_INET;
        server.sin_port = htons(i);
        server.sin_addr.s_addr = inet_addr(ip.c_str());

        int connectStatus;

        connectStatus = connect(s, (sockaddr*)&server, sizeof(server));

        if(connectStatus == 0)
        {
            cout<<"Port "<<i<<" is Open"<<endl;
        }
        else
        {
            // closed port
        }

        closesocket(s);
    }

    cout<<"\nScanning Finished"<<endl;

    WSACleanup();

    return 0;
}