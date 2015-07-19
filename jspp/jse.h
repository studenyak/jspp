#pragma once

#include <string>

namespace stood
{
	typedef std::string typeSourceCode;

	class JSE
	{
	public:
		virtual int eval(typeSourceCode& source_code) = 0;
	};
}