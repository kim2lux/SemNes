#include "header.hh"
#include "display.hh"
#include "main.h"
#include "dbg.hh"

int snes::header::loadRom()
{
	std::ifstream myReadFile;
	myReadFile.open(filename, std::ios::binary);
	myReadFile.seekg(0, myReadFile.end);
	this->romSize = myReadFile.tellg();
	romdata = (char *)malloc(romSize);
	if (romdata == NULL)
		ERR("error can't alloc rom into memory");
	memset(romdata, 0x00, romSize);
	myReadFile.seekg(0, myReadFile.beg);
	if (myReadFile.is_open())
		myReadFile.read(romdata, romSize);
	else
		ERR("can't open rom file");
	myReadFile.close();
	return 0;
}


int	snes::header::checkSum(s_header *gameHead)
{
	if (!(gameHead->CheckSum + gameHead->CompCheck == 0xffff))
		ERR("checksum NOK");
#ifdef _DEBUG
	printf("check sum OK\n");
#endif
	return 0;
}


s_header *snes::header::parseHeader()
{
	s_header	*gameHead;

	loadRom();
	gameHead = (s_header *)malloc(sizeof(s_header));
	memcpy(gameHead, romdata + OFFSET_LOWROM, sizeof(s_header)); // start rom datas
	dbg::getInstance()->trace(gameHead, sizeof(s_header));
	display_header(gameHead);
	checkSum(gameHead);
	return (gameHead);
}

snes::header::header(char *file) : filename(file)
{
	std::cout << "game file : " << file << std::endl;
}
