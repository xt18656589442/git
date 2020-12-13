#include "network_Server.h"

using namespace std;

NetworkServer::NetworkServer()
{
	intSocketDomain = AF_INET;
	intSocketType   = SOCK_STREAM;
	intPortNumber   = 8080;
	strSeverIpAddr  = "0.0.0.0";
	dataBufCapacity = 512;
	transferDataBuf = new char[dataBufCapacity];
	strServerName   = "Server Adminitrator";
	claim_server();
	init_Config();
}

NetworkServer::NetworkServer(const string & ServerName, int SocketDomain, int SocketType, int BufCapacity)
{
	strServerName   = ServerName;
	intSocketDomain = SocketDomain;
	intSocketType   = SocketType;
	dataBufCapacity = BufCapacity;
	claim_server();
	init_Config();
}

inline void NetworkServer:: claim_server()
{
	cout << ">>> " << strServerName << " <<<" << endl;
}

inline void NetworkServer::init_Config()
{
	socketAddrLen = sizeof(socketAddr);
	socketAddr.sin_family      = intSocketDomain;
	socketAddr.sin_port        = htons(intPortNumber);
	socketAddr.sin_addr.s_addr = htonl(inet_addr((char *)strSeverIpAddr.data()));
}

void NetworkServer::StartServer()
{
	intSocketFd = socket(intSocketDomain, intSocketType, 0);
	if (intSocketFd == -1)
	{
		perror("Creating Socket Error");
		return;
	}
	if (bind(intSocketFd, (const struct sockaddr *)&socketAddr, socketAddrLen) == -1)
	{
		perror("Binding Socket Error");
		return;
	}
	if (listen(intSocketFd, 0) == -1)
	{
		perror("Listening Socket Error");
		return;
	}
	int intAccptFd = accept(intSocketFd, (struct sockaddr *)&socketAddr, &socketAddrLen);
	if (intAccptFd == -1)
	{
		perror("Accepting Socket Error");
		return;
	}
	else
	{
		cout << intAccptFd << " Connected" << endl;
		Transfer(intAccptFd);
	}
	close(intSocketFd);
	return;
}



void NetworkServer::StopServer()
{
	bStopServerInd = false;
}

void NetworkServer::Transfer(int intAccptFd)
{
	ssize_t numRecv = 0;
	transferDataBuf = new char[512];
	while(1)
	{

		if(numRecv = recv(intAccptFd, transferDataBuf, dataBufCapacity, 0) == 0)
		{
			perror("Recv Error");
			return;
		}
		else
		{
			cout << transferDataBuf;
		}
	}
	return;
}

