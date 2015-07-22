#include "duktape\duktape.h"
#include "duktape_jse.h"

namespace stood
{

	DuktapeJSE::DuktapeJSE(void)
	{
	}

	DuktapeJSE::~DuktapeJSE(void)
	{
	}

	int DuktapeJSE::eval(std::string& source_code)
	{
		duk_context *ctx = duk_create_heap_default();
		duk_eval_string(ctx, source_code.c_str());
		duk_destroy_heap(ctx);
		return 0;
	}

	int DuktapeJSE::eval_from_file(const std::string& strFileName)
	{
		duk_context* ctx = duk_create_heap_default();
		duk_eval_file(ctx, strFileName.c_str());
		duk_destroy_heap(ctx);
		return 0;
	}

	const std::string& DuktapeJSE::eval_with_params(const std::string& strFileName,
													const std::string& strFunction,
													const std::string& strJsonParams)
	{
		duk_context* ctx = duk_create_heap_default();

		duk_eval_file(ctx, strFileName.c_str());
		duk_compile_file(ctx, 0, strFileName.c_str());
		duk_pop(ctx);
		
		std::string strFuncWithParams = strFunction;
		strFuncWithParams.append("(");
		strFuncWithParams.append(strJsonParams);
		strFuncWithParams.append(");");
		
		duk_eval_string(ctx, strFuncWithParams.c_str());
		m_strResult = duk_get_string(ctx, -1);
		duk_pop(ctx);
		duk_destroy_heap(ctx);

		return m_strResult;
	}
}