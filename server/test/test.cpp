#include <iostream>

using namespace std;

int main(int argc, const char *argv[])
{
/*	double i;
	for(i=0;i < 65536;i++)
		system("nc 0.0.0.0 8080");
*/
	const char *p = "0.0.0.0";
	string Str = string (p);
	cout << Str << endl;
	cout << "========" << endl;
	string Str2 = "0.0.0.0";
	char *p1 = (char *)Str2.data();
	cout << p1 <<endl;

	return 0;
}
