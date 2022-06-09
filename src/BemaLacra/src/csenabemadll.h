#ifndef BEMASENADLL_H
#define BEMASENADLL_H

#include <windows.h> 
#include <string>
using namespace std;

#include "SenaDLLFunctions.h"
#include "BemaSenaDefs.h"

class CSenaBemaDll
{
	HINSTANCE hLib;
	//BEMA_DLL_SENA                p_BemaSena;
	NEWSQL32RERO_DLL               P_SetDataBaseName;

	public:

	CSenaBemaDll();
	~CSenaBemaDll();
	unsigned int GenerarSena(std::string NumeroSerial, std::string Marca, std::string RIF, std::string NIT);
};

#endif
