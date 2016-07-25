#include "display.hh"

void display_rom_size(unsigned char romsize)
{
	unsigned char rsize;

	switch (romsize)
	{
	case 0x09:
		rsize = 4;
		break;
	case 0x08:
		rsize = 4;
		break;
	case 0x0a:
		rsize = 8;
		break;
	case 0x0b:
		rsize = 16;
		break;
	case 0x0c:
		rsize = 32;
		break;
	case 0x0d:
		rsize = 64;
		break;
	}
	printf("rom size : %dMb\n", rsize);
}

void display_expension_ram_size(unsigned char ers)
{
	unsigned int val = 0;

	switch (ers)
	{
	case 0x00:
		val = 0;
		break;
	case 0x01:
		val = 16;
		break;
	case 0x03:
		val = 64;
		break;
	case 0x05:
		val = 256;
		break;
	case 0x06:
		val = 512;
		break;
	case 0x07:
		val = 1024;
		break;
	}
	printf("expension ram size : %d\n", val);
}

void display_chipset_type(unsigned char cT)
{
	printf("chipset : ");
	if (cT == 0x00 || cT == 0x01 || cT == 0x02)
	{
		printf(" ** No enhancement chipset ** ");
		if (cT == 0x01)
			printf("ROM + RAM\n");
		else if (cT == 0x02)
			printf("ROM + RAM + SRAM\n");
		else
			printf("\n");
	}
	else
	{
		if ((cT >> 4) == 0x01)
			  printf("super fx\n");
		else if ((cT >> 4) == 0x02)
		  printf("OBC-1\n");
		else if ((cT >> 4) == 0x03)
		  printf("SA-1\n");
		else if ((cT >> 4) == 0x0f)
		  printf("C4\n");
		else if ((cT >> 4) == 0x0e)
		  printf("chiptset other\n");
		else if ((cT >> 4) == 0x00)
		  printf("DSP\n");
		else if ((cT >> 4) == 0x04)
		  printf("S-DD1\n");

		if ((cT & 0x3) == 0x3)
		  printf("Rom + Enhancement Chip\n");
		else if ((cT & 0x4) == 0x4)
		  printf("Rom + Enhancement Chip + RAM ROM\n");
		else if ((cT & 0x5) == 0x5)
		  printf("Rom + Enhancement Chip + RAM ° SRAM\n");
		else if ((cT & 0x6) == 0x6)
		  printf("Rom + Enhancement Chip + SRAM\n");
  }
}

#include <math.h>

void display_rom_map_mode(char mode)
{
	printf("rom mode : ");
	if ((mode >> 4) & 1 && (mode >> 5) & 1)
		printf("FastROM\n");
	else
		printf("SlowROM\n");
}


void display_header(s_header *gameHead, char lrom)
{
	int srm;

	printf("*********** HEADER INFO START *********\n");
	fwrite("game name : ", 1, 12, stdout); fwrite(gameHead->gameTitle, 1, 21, stdout); fwrite("\n", 1, 1, stdout);
	srm = gameHead->sRamSize;
	(lrom == 1) ? printf("rom type : LoRom\n") : printf("rom type : HiRom\n");
	display_rom_size(gameHead->romSize);
	display_rom_map_mode(gameHead->mapMode);
	if (srm != 0)
		printf("sram size (.srm) : %d(Kb)\n", 1 << (gameHead->sRamSize + 3));
	else
		printf("sram size (.srm) : 0(Kb)\n");
	display_chipset_type(gameHead->cartType);
	printf("dest code : %x\n", gameHead->destCode);
	fwrite("game code : ", 1, 12, stdout); fwrite(gameHead->gamecode, 1, 4, stdout); fwrite("\n", 1, 1, stdout);
	printf("********** HEADER INFO END *************\n\n\n");
}


void display_binary_value(char *v)
{
	char b;

	printf("addr = %p\n\n", v);
	b = 7;
	while (b >= 0)
	{
		(*v & (1 << b--)) ? printf("1") : printf("0");
	}
	printf("end\n");
}
