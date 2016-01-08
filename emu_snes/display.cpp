#include "display.hh"

void display_header(s_header *gameHead)
{
	printf("game name : %s\n", gameHead->gameTitle);
	printf("rom size : %dMb\n", gameHead->RomSize);
	printf("ram size : %xMb\n", gameHead->RamSize);
	printf("map mode rom : %x\n", gameHead->mapMode);
	printf("dest code : %x\n", gameHead->destCode);
}


void display_binary_value(char *v)
{
	char b;

	printf("addr = %p\n\n", v);
	b = 7;
	while (b >= 0)
	{
		if (*v & (1 << b))
			printf("1");
		else
			printf("0");
		--b;
	}
	printf("end\n");
}
