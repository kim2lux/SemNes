#include "emulator.hh"


int	snes::Emu::init(char *filename)
{
	header = new snes::header(filename);
	assert(header != NULL);
	dbg::getInstance()->setOutFile("dbg.txt");
	header->parseHeader();
	romdata = header->romdata;

	cpu = new snes::cpu();
	assert(cpu != NULL);
	return (0);
}

snes::Emu::Emu(char * filename)
{
	init(filename);	
}

snes::Emu::~Emu()
{
	dbg::getInstance()->deleteInstance();
	delete dbg::getInstance();
}
