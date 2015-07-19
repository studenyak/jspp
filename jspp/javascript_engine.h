#pragma once

#include <string>
#include "jse.h"

namespace stood
{
	template <class jse> 
	class JavascriptEngine
	{
	public:
		int eval(typeSourceCode& source_code)
		{
			return engine.eval(source_code);
		}

	private:
		jse engine;
	};
}
