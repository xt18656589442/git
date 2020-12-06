#include <stdlib.h>

int main(int argc, const char *argv[])
{
	double i;
	for(i=0;i < 65536;i++)
		system("nc 0.0.0.0 8080");

	return 0;
}
