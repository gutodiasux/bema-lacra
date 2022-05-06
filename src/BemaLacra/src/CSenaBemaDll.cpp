/*****************************************************************************
       Projeto Bematech Se�aEs
       Bematech International Corp.
******************************************************************************
       M�dulo:    CSenaBemaDll.cpp
       Arquivo:   CSenaBemaDll.cpp
       Autor:     Guilherme Pereira
       Descri��o:
       Criado em: 06/03/2007
       Hist�rico:
******************************************************************************/

#include "CSenaBemaDll.h"

/*------------------------------------------------------------------------------
FUN��O      : CSenaBemaDll
AUTOR       : Guilherme Pereira
DATA        : 06.03.2007
DESCRI��O   : Construtor da classe CSenaBemaDll
PAR�METROS  :
RETORNOS    :
OBSERVA��ES :
------------------------------------------------------------------------------*/
CSenaBemaDll::CSenaBemaDll()
{
	//Carrega a DLL na mem�ria.
	//hLib = LoadLibrary("C:\\WINDOWS\\system32\\NewSQL32RERO.dll");
	hLib = LoadLibrary("NewSQL32RERO.dll");

	if(hLib == NULL) //Verifica se houve erro.
	{
		FreeLibrary(hLib);
		return;
	}

	//Obt�m o endere�o das fun��es contidas na DLL.
	P_SetDataBaseName = (NEWSQL32RERO_DLL)GetProcAddress(hLib, "SetDataBaseName");
}

/*------------------------------------------------------------------------------
FUN��O      : ~CSenaBemaDll
AUTOR       : Guilherme Pereira
DATA        : 06.03.2007
DESCRI��O   : Destrutor da classe CSenaBemaDll
PAR�METROS  :
RETORNOS    :
OBSERVA��ES :
------------------------------------------------------------------------------*/
CSenaBemaDll::~CSenaBemaDll()
{
	FreeLibrary(hLib);
}


/*------------------------------------------------------------------------------
FUN��O      : BemaDownloadMFK
AUTOR       : Guilherme Pereira
DATA        : 26.01.2007
DESCRI��O   :
PAR�METROS  :
RETORNOS    :
OBSERVA��ES :
------------------------------------------------------------------------------*/
unsigned int CSenaBemaDll::GenerarSena(std::string NumeroSerial, std::string Marca, std::string RIF, std::string NIT)
{
	if(P_SetDataBaseName != NULL)
	{
		//preparar a string de par�metro
		std::string strInAux;
		char strIn[200];
		char strOut[200];

		strInAux = NumeroSerial + "#" + Marca + "#" + RIF + "##" + NIT + "#";
		strcpy(strIn, strInAux.c_str());

		int result = P_SetDataBaseName(strIn, strOut);

		// Need to redirect strOut by reference to the external world
		//Form1->EditSena->Text = strOut;
		return result;
	}
	else
		return RETORNO_NOK;
}

