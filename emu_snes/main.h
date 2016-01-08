#ifndef main_h
#define main_h


#include <fstream>
#include <sstream>
#include <string>
#include <cerrno>
#include <iostream>

inline void error(char *msg, int line, char *file)
{
	printf("************************************************************************\nerror : %s\nline : %d\nfile : %s\n************************************************************************\n", msg, line, file);
	exit(-1);
}

#define ERR(s) error(s, __LINE__, __FILE__)

#include "cpu.h"
#include "opcode.h"

#endif