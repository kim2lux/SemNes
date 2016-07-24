#ifndef EMULATOR_HH
#define EMULATOR_HH

#include "header.hh"
#include "cpu.hh"
#include "dbg.hh"

typedef unsigned char u8;
typedef unsigned int  u32;

namespace snes
{
	class header;
	class cpu;
	class Emu
	{
	public:
		Emu(char * filename);
		~Emu();
		int				init(char * filename);

		snes::header	*header;
		snes::cpu		*cpu;
		char			*romdata;
	private:

	};


}

#endif