#include "dbg.hh"
#include <assert.h>

dbg *dbg::m_instance = NULL;

dbg::dbg()
{
#ifdef _DEBUG
	outfile = NULL;
	printf("debug initialized\n");
#endif
}

void dbg::setOutFile(char * filename)
{
	if (outfile == NULL)
		outfile = new std::ofstream(filename);
}

dbg * dbg::getInstance()
{
	if (m_instance == NULL)
		m_instance = new dbg();
	return m_instance;
}

void	dbg::deleteInstance()
{
	delete dbg::m_instance->outfile;
}

int dbg::trace(void * data, unsigned int size)
{
	assert(outfile != NULL);
	outfile->write((const char *)data, size);
	return 0;
}
