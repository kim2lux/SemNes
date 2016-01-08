#ifndef INIT_HH
#define INIT_HH

#include <iostream>
#include "opcode.h"


#define SIZE_ROM 4000000

namespace snes
{
	using namespace std;
	class init
	{
	public:
		init(char *file);
		int loadRom(char *);
		int checkSum(s_header *);
		s_header * parseHeader(char *rawData);
		char *romdata;
	private:
		string filename;

	};
}

#endif