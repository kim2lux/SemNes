#include "emulator.hh"


int	snes::Emu::init(char *filename)
{
	//init debug
	dbg::getInstance()->setOutFile("dbg.txt");

	//header parsing
	header = new snes::header(filename);
	assert(header != NULL);
	header->parseHeader();
	romdata = header->romdata;

	//cpu init & start
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
