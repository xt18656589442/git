#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <thread>

class NetworkServer
{
	private:
		int intSocketDomain; // IPv4 or IPv6 etc.
		int intSocketType; // Server Type: UDP or TCP
		bool bStopServerInd; // Indication for stop the Server
		char* transferDataBuf; // Buffer for Data
		ssize_t dataBufCapacity; // Buffer Capacity
		short intPortNumber; // Server Port Number
		int intSocketFd;
		struct sockaddr_in socketAddr;
		size_t socketAddrLen;
		std::string strServerName;
		std::string strSeverIpAddr;
		void claim_server();
		void init_Config();
	public:
		NetworkServer();
		NetworkServer(const std::string &ServerName, \
				int SocketDomainm, int SocketType, int BufCapacity);
		void StartServer();
		void StopServer();
		void Transfer(int fd);
};

