#ifndef __RETORNO__
#define __RETORNO__

#include <string>

using namespace std;

enum RET
{
	RET_OK = 0,
	RET_ERRO_RESER_INPUT = -1,
	RET_ERRO_VOl_MIN = -2,
	RET_ERRO_VOl_MAX = -3,
	RET_ERRO_FAIXA = -4,
	RET_ERRO_FAIXA_SUPER_INFER = -5,


};

class Messagem
{

public:
	string traducaoMessagem(RET tipo);

};

#endif
