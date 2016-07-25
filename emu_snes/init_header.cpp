#include "header.hh"
#include "display.hh"
#include "main.h"
#include "dbg.hh"
#include <assert.h>

int snes::header::loadRom()
{
	std::ifstream myReadFile;
	myReadFile.open(filename, std::ios::binary);
	if (!myReadFile.is_open())
		ERR("can't open rom file");
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
		return (-1);
	return 0;
}


s_header *snes::header::parseHeader()
{

	s_header      *gameHead;
	gameHead = (s_header *)malloc(sizeof(s_header));
	std::ofstream outfile("headers.txt", std::ofstream::out | std::ofstream::app);
	memcpy(gameHead, romdata + OFFSET_LOWROM, sizeof(s_header)); // start rom datas
	if (checkSum(gameHead) == 0)
	{
		dbg::getInstance()->trace(gameHead, sizeof(s_header));
		outfile.write(romdata + OFFSET_LOWROM, sizeof(s_header));
		display_header(gameHead, 1);
	}
	else
	{
		memcpy(gameHead, romdata + OFFSET_HIGHROM, sizeof(s_header)); // start rom datas
		outfile.write(romdata + OFFSET_HIGHROM, sizeof(s_header));
		if (checkSum(gameHead) == 0)
		{
			dbg::getInstance()->trace(gameHead, sizeof(s_header));
			display_header(gameHead, 0);
		}
		else
			ERR("can't retrieve game header\n");
	}
	return (gameHead);
}

snes::header::header(char *file) : filename(file)
{
	loadRom();
	assert(romdata != NULL);
	std::cout << "game file : " << file << std::endl;
}
