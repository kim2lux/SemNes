#ifndef CPU_H
#define CPU_H

#include "dbg.hh"

namespace snes {

	class cpu
	{
	public:
		cpu()
		{
			dbg::getInstance()->trace("cpu init", 10);
		}
	};
}

#endif