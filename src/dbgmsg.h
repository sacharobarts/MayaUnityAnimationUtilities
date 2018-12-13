#ifndef _DBGMSG_H
#define _DBGMSG_H
#include <iostream>
#include <maya/MGlobal.h>
#ifdef _DEBUG
#define DEBUG_OUT(...)     VariadicToOutputStream("[",__LINE__,"]","[",__FUNCTION__,"]: ",__VA_ARGS__);
#else
#define DEBUG_OUT(...)
#endif

class VariadicToOutputStream
{
public:
	template<typename Value, typename... Values>
		VariadicToOutputStream(Value v, Values... vs)
	{
		std::ostringstream oss;
		using expander = int[];
		oss << v; // first
		(void)expander {
			0, (oss << m_separator << vs, void(), 0)...
		};
		MGlobal::displayInfo(MString("[DEBUG]") + oss.str().c_str());
	}
	~VariadicToOutputStream()
	{
	}

private:
	const std::string m_separator = " ";
};

#endif
