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
		m_strResult = "";
		duk_context* ctx = duk_create_heap_default();
		if(!ctx)
		{
			printf("Failed to create a Duktape heap.\n");
			return m_strResult;
		}

		if( duk_peval_file(ctx, strFileName.c_str()) != 0 )
		{
			printf("Error: %s\n", duk_safe_to_string(ctx, -1));
			duk_destroy_heap(ctx);
			return m_strResult;
		}
		
        duk_push_global_object(ctx);
        duk_get_prop_string(ctx, -1, strFunction.c_str());
		duk_push_string(ctx, strJsonParams.c_str());
        if (duk_pcall(ctx, 1) != 0)
            printf("Error: %s\n", duk_safe_to_string(ctx, -1));
        else
            printf("%s\n", duk_safe_to_string(ctx, -1));

		m_strResult = duk_get_string(ctx, -1);
		duk_pop(ctx);
		duk_destroy_heap(ctx);

		return m_strResult;
	}

	const std::string& DuktapeJSE::analyzeSNSS(const std::string& strJsFileName,
												const std::string& strSNSSFileName,
												const std::string& strJsonParams)
	{
		/*duk_context* ctx = duk_create_heap_default();

		duk_eval_file(ctx, strJsFileName.c_str());
		duk_compile_file(ctx, 0, strJsFileName.c_str());
		duk_pop(ctx);
		
		std::string strFuncWithParams = "analyzeSNSS";
		
		void* pBuf = duk_push_fixed_buffer(ctx, 64);
		char* chSrc = "Kakaja to hojnau s 'tim bufferom";
		memcpy(pBuf, chSrc, strlen(chSrc));

		strFuncWithParams.append("(");
		strFuncWithParams.append(strJsonParams);
		strFuncWithParams.append(strJsonParams);
		strFuncWithParams.append(");");
		
		duk_eval_string(ctx, strFuncWithParams.c_str());
		m_strResult = duk_get_string(ctx, -1);
		duk_pop(ctx);
		duk_destroy_heap(ctx);*/

		return m_strResult;
	}
}