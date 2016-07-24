#include "main.h"
#include "emulator.hh"

int main(int ac, char **av)
{
#ifdef _DEBUG
	printf("%s\n", av[1]);
#endif
	snes::Emu e(av[1]);
}
