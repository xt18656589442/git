#include <iostream>
#include <thread>
using namespace std;

void fun()
{	
	const char *p = "0.0.0.0";
	string Str = string (p);
	cout << Str << endl;
	cout << "========" << endl;
	string Str2 = "0.0.0.0";
	char *p1 = (char *)Str2.data();
	cout << p1 <<endl;
	cout << (1 > 2 ? "hello": "world") << endl;
}

int main(int argc, const char *argv[])
{
/*	double i;
	for(i=0;i < 65536;i++)
		system("nc 0.0.0.0 8080");
*/
	thread client(fun);

	return 0;
}
