#ifndef INIT_HH
#define INIT_HH

#include <iostream>
#include "emulator.hh"
#include "opcode.h"
#pragma pack(push, 2)

#define OFFSET_LOWROM 0x7FB0
#define OFFSET_HIGHROM 0xFFB0

typedef unsigned int u32;

struct  s_header
{
	char	makecode[2];
	char	gamecode[4];
	char	c[7];
	char	ERS; //expansion ram size
	char	spV;
	char	cartSubNum;
	char	gameTitle[21];
	char	mapMode;
	char	cartType;
	char	romSize;
	char	sRamSize;
	char	destCode;
	char	nospecified;
	char	maskRomVersion;
	unsigned short	CompCheck;
	unsigned short	CheckSum;
};

#pragma pack(pop)

#define SIZE_ROM 4000000

namespace snes
{
	using namespace std;
	class header
	{
	public:
		header(char *file);
		int loadRom();
		int checkSum(s_header *);
		s_header * parseHeader();
		char *romdata;
		u32  romSize;
	private:
		string filename;

	};
}

#endif 