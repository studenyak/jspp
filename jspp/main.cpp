// jspp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "javascript_engine.h"
#include "duktape_jse.h"
#include <string>

using namespace stood;

int eval_from_file(std::string& strArg)
{
	return 0;
}

int eval_source(std::string& strArg)
{
	strArg.erase(0, std::string("--source=").size());
	
	JavascriptEngine<DuktapeJSE> js_engine;
	js_engine.eval(strArg);
	return 0;
}

int eval_hello_world(void)
{
	JavascriptEngine<DuktapeJSE> js_engine;
	std::string source_code("print('Hello javascript world!');");
	js_engine.eval(source_code);
	return 0;
}

int main(int argc, char* argv[])
{
	std::cout << "Try my javascript engine" << std::endl;

	if( argc == 2  )
	{
		std::string strArg(argv[1]);
		if(strArg.find(std::string("--file=")) != std::string::npos)
			return eval_from_file(strArg);
		else if(strArg.find(std::string("--source=")) != std::string::npos)
			return eval_source(strArg);
		else
			return eval_hello_world();
	}


	return eval_hello_world();
}

