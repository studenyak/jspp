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
}