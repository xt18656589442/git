#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>

class TcpServer
{
	private:
		bool bStopServerInd;
		char* transferDataBuf;
		ssize_t dataBufCapacity;
	public:
		TcpServer();
		void StartServer();
		void StopServer();
		void Transfer(int fd);
};

