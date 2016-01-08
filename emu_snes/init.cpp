#include "init.hh"
#include "display.hh"
#include "main.h"

int snes::init::loadRom(char *file)
{
	std::ifstream myReadFile;
	myReadFile.open(file, std::ios::binary);
	std::string res;
	if (myReadFile.is_open())
		myReadFile.read(romdata, SIZE_ROM);
	else
		ERR("can't open rom file");
	myReadFile.close();
	return 0;
}


int	snes::init::checkSum(s_header *gameHead)
{
	//union t
	//{
	//	unsigned short u;
	//	unsigned char  c[2];
	//};

	//t	comp1, comp2;
	//comp1.c[1] = romdata[0x81dd];
	//comp1.c[0] = romdata[0x81dc];
	//comp2.c[1] = romdata[0x81df];
	//comp2.c[0] = romdata[0x81de];
	if (!(gameHead->CheckSum + gameHead->CompCheck == 0xffff))
		ERR("checksum NOK");
	printf("check sum OK\n");
	return 0;
}


s_header *snes::init::parseHeader(char *romdata)
{
	s_header	*gameHead;

	gameHead = (s_header *)malloc(sizeof(s_header));
	std::ofstream outfile("C:\\emusnes\\emu_snes\\Debug\\new.txt", std::ofstream::binary);
	memcpy(gameHead, romdata + OFFSET_LOWROM + 0x200, sizeof(s_header)); // start rom datas
	outfile.write(romdata + OFFSET_LOWROM + 0x200, sizeof(s_header));
	display_header(gameHead);
	checkSum(gameHead);
	return (gameHead);
}

snes::init::init(char *file) : filename(file)
{
	std::cout << "game file : " << file << std::endl;
	s_header	*gameHead;

	romdata = (char *)malloc(SIZE_ROM);
	if (romdata == NULL)
		ERR("error can't alloc rom into memory");
	memset(romdata, 0x00, SIZE_ROM);
	loadRom(file);
	gameHead = parseHeader(romdata);
	free(romdata);
}
