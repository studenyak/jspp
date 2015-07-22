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

		const std::string& eval_with_params(const std::string& strFileName,
											const std::string& strFunction,
											const std::string& strJsonParams)
		{
			return engine.eval_with_params(strFileName, strFunction, strJsonParams);
		}

	private:
		jse engine;
	};
}
