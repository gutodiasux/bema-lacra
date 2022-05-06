/*****************************************************************************
       Projeto Bematech SeñaEs
       Bematech International Corp.
******************************************************************************
       Módulo:    CSenaBemaDll.cpp
       Arquivo:   CSenaBemaDll.cpp
       Autor:     Guilherme Pereira
       Descrição:
       Criado em: 06/03/2007
       Histórico:
******************************************************************************/

#include "CSenaBemaDll.h"

/*------------------------------------------------------------------------------
FUNÇÃO      : CSenaBemaDll
AUTOR       : Guilherme Pereira
DATA        : 06.03.2007
DESCRIÇÃO   : Construtor da classe CSenaBemaDll
PARÂMETROS  :
RETORNOS    :
OBSERVAÇÕES :
------------------------------------------------------------------------------*/
CSenaBemaDll::CSenaBemaDll()
{
	//Carrega a DLL na memória.
	//hLib = LoadLibrary("C:\\WINDOWS\\system32\\NewSQL32RERO.dll");
	hLib = LoadLibrary("NewSQL32RERO.dll");

	if(hLib == NULL) //Verifica se houve erro.
	{
		FreeLibrary(hLib);
		return;
	}

	//Obtém o endereço das funções contidas na DLL.
	P_SetDataBaseName = (NEWSQL32RERO_DLL)GetProcAddress(hLib, "SetDataBaseName");
}

/*------------------------------------------------------------------------------
FUNÇÃO      : ~CSenaBemaDll
AUTOR       : Guilherme Pereira
DATA        : 06.03.2007
DESCRIÇÃO   : Destrutor da classe CSenaBemaDll
PARÂMETROS  :
RETORNOS    :
OBSERVAÇÕES :
------------------------------------------------------------------------------*/
CSenaBemaDll::~CSenaBemaDll()
{
	FreeLibrary(hLib);
}


/*------------------------------------------------------------------------------
FUNÇÃO      : BemaDownloadMFK
AUTOR       : Guilherme Pereira
DATA        : 26.01.2007
DESCRIÇÃO   :
PARÂMETROS  :
RETORNOS    :
OBSERVAÇÕES :
------------------------------------------------------------------------------*/
unsigned int CSenaBemaDll::GenerarSena(std::string NumeroSerial, std::string Marca, std::string RIF, std::string NIT)
{
	if(P_SetDataBaseName != NULL)
	{
		//preparar a string de parâmetro
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

