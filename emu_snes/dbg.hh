#ifndef __DBG_HH
#define __DBG_HH

#include <fstream>
#include <sstream>
#include <string>
#include <cerrno>
#include <iostream>
#include <assert.h>

inline void error(char *msg, int line, char *file)
{
	printf("************************************************************************\nerror : %s\nline\
		: %d\nfile : %s\n************************************************************************\n", msg, line, file);
	exit(-1);
}

#define ERR(s) error(s, __LINE__, __FILE__)
class dbg
{
private:
	//func
	dbg(char *file);
	dbg();
	//properties
	std::ofstream *outfile;
	static dbg *m_instance;

public:
	void	setOutFile(char *filename);
	static dbg * getInstance();
	static void deleteInstance();
	int trace(void *data, unsigned int size);
};


#endif