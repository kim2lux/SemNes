#ifndef opcode_h
#define opcode_h

#pragma pack(push, 2)

#define OFFSET_LOWROM 0x7FB0
#define OFFSET_HIGHROM 0xFFB0

struct  s_header
{
	short	makecode;
	char	gamecode[4];
	char	c[7];
	char	ERS; //expansion ram size
	char	spV;
	char	cartSubNum;
	char	gameTitle[21];
	char	mapMode;
	char	cartType;
	char	RomSize;
	char	RamSize;
	char	destCode;
	char	nospecified;
	char	maskRomVersion;
	unsigned short	CompCheck;
	unsigned short	CheckSum;
};

#pragma pack(pop)

#endif