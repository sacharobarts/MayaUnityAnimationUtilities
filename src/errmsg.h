#ifndef _ERRMSG_H
#define _ERRMSG_H
#include <iostream>
#include <maya/MGlobal.h>
#ifdef NO_ERR
#define ERROR_OUT(...)
#else
#define ERROR_OUT(...)     VariadicToOutputErrorStream(__VA_ARGS__);
#endif

class VariadicToOutputErrorStream
{
public:
	template<typename Value, typename... Values>
	VariadicToOutputErrorStream(Value v, Values... vs)
	{
		std::ostringstream oss;
		using expander = int[];
		oss << v; // first
		(void)expander {
			0, (oss << m_separator << vs, void(), 0)...
		};
		MGlobal::displayError(MString("[ERROR]: ") + oss.str().c_str());
		
	}
	~VariadicToOutputErrorStream()
	{
	}

private:
	const std::string m_separator = " ";
};

#endif