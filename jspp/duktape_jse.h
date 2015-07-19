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
	};
}
