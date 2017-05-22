#include "retorno.h"

string Messagem::traducaoMessagem(RET tipo)
{
	string mensagem = "";
	
	if (tipo == RET_ERRO_RESER_INPUT)
	{
		mensagem = "Os campos do reservat�rio est�o invalidos";
	}
	else if (tipo == RET_ERRO_VOl_MIN)
	{
		mensagem = "Volume Inicial n�o pode ser menor ou igual ao Volume Minimo";
	}
	else if (tipo == RET_ERRO_VOl_MAX)
	{
		mensagem = "Volume Inicial n�o pode ser maior ou igual ao Volume Maximo";
	}
	else if (tipo == RET_ERRO_FAIXA)
	{
		mensagem = "Volume Superior da Faixa invalido";
	}
	else if (tipo == RET_ERRO_FAIXA_SUPER_INFER)
	{
		mensagem = "Existem Faixas Acima com Volume Superior maior ou igual a Uma Faixa Inferior";
	}

	return mensagem;
}