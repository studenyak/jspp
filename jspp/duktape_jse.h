#pragma once
#include <string>
#include "jse.h"

namespace stood
{
	class DuktapeJSE : public JSE
	{
	public:
		DuktapeJSE(void);
		~DuktapeJSE(void);
		int eval(typeSourceCode& source_code);

		int eval_from_file(const std::string& strFileName);

		int eval_with_params(
			const std::string& strFileName,
			const std::string& strFunction,
			const std::string& strJsonParams);
	};
}
