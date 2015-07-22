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

		const std::string& eval_with_params(const std::string& strFileName,
											const std::string& strFunction,
											const std::string& strJsonParams);

		const std::string& analyzeSNSS(const std::string& strJsFileName,
										const std::string& strSNSSFileName,
										const std::string& strJsonParams);
	private:
		std::string m_strResult;
	};
}
