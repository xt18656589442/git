#include "tcpserver.h"

using namespace std;

void TcpServer::StartServer()
{
	int intSocketDomain   = AF_INET;
	int intSocketType     = SOCK_STREAM;
	int intSocketProtocol = 0;
	int intSocketFd       = 0;
	int intSocketListenBl = 1;

	intSocketFd = socket(intSocketDomain, intSocketType, intSocketProtocol);
	if (intSocketFd == -1)
	{
		perror("Creating Socket Error");
		return;
	}
	struct sockaddr_in socketAddr;
	socklen_t socketAddrLen    = sizeof(socketAddr);
	socketAddr.sin_family      = AF_INET;
	socketAddr.sin_port        = htons(8080);
	socketAddr.sin_addr.s_addr = htonl(inet_addr("0.0.0.0"));
	if (bind(intSocketFd, (const struct sockaddr *)&socketAddr, socketAddrLen) == -1)
	{
		perror("Binding Socket Error");
		return;
	}
	if (listen(intSocketFd, intSocketListenBl) == -1)
	{
		perror("Listening Socket Error");
		return;
	}
	while(bStopServerInd)
	{
		int intAccptFd = accept(intSocketFd, (struct sockaddr *)&socketAddr, &socketAddrLen);
		if (intAccptFd == -1)
		{
			perror("Accepting Socket Error");
			return;
		}
		else
		{
			cout << intAccptFd << " Connected" << endl;
		}
		Transfer(intAccptFd);
	}
	close(intSocketFd);
	return;
}



TcpServer::TcpServer()
{
	bStopServerInd  = true;
	dataBufCapacity = 512;
}

void TcpServer::StopServer()
{
	bStopServerInd = false;
}

void TcpServer::Transfer(int intAccptFd)
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
			cout << transferDataBuf << endl;
		}
	}
	return;
}

