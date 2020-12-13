#include <iostream>
#include "network_server/network_Server.h"

using namespace std;

int main(void)
{
    NetworkServer TcpServer1;
    TcpServer1.StartServer();
    return 0;
}
