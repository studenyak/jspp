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

		int eval_from_file(const std::string& strFileName)
		{
			return engine.eval_from_file(strFileName);
		}

	private:
		jse engine;
	};
}
