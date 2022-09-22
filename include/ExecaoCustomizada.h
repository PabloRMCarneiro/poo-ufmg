#ifndef EXECAOCUSTOMIZADA_H_INCLUDED
#define EXECAOCUSTOMIZADA_H_INCLUDED
#include <exception>
#include <string.h>
#include <fstream>
#include <stdexcept>

using namespace std;

class ExecaoCustomizada : public exception
{
protected:
	char msg[100];

public:
	ExecaoCustomizada(char* e)
	{
		strcpy(msg, e);
	}
	virtual const char* what()
	{
		return msg;
	}
};

#endif // EXECAOCUSTOMIZADA_H_INCLUDED
