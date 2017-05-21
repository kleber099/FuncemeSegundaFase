#include "controleReservatorio.h"
#include "reservatorio.h"
#include "Faixa.h"

#include <array>

#include <wx/wxprec.h>
#include <wx/grid.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

class InterfaceReservatorio : public wxApp
{
public:
	virtual bool OnInit();
};

class FrameInterface : public wxFrame
{
public:
	FrameInterface(const wxString& title, const wxPoint& pos, const wxSize& size);

private:
	wxTextCtrl* inicialInput;
	wxTextCtrl* minimoInput;
	wxTextCtrl* maximoInput;

	wxGrid* grid;
	int quantRows;
	vector<Faixa> faixas;

	void AddLinha(wxCommandEvent& event);
	void RemoveLinha(wxCommandEvent& event);
	void AlterarGrid(wxGridEvent& event);
	Reservatorio criarReservatorio(int* retorno);
	Faixa criarFaixa(wxGridEvent& event, int* retorno);
	int atualizarFaixas(wxGridEvent& event, Faixa faixa);
	void atualizaGrid(vector<Tupla>& tuplas);

	wxDECLARE_EVENT_TABLE();
};

enum
{
	ID_Hello = 1,
	ID_Linha = 2,
	ID_Remover = 3
};

//Handle de eventos
wxBEGIN_EVENT_TABLE(FrameInterface, wxFrame)
EVT_BUTTON(ID_Linha, FrameInterface::AddLinha)
EVT_BUTTON(ID_Remover, FrameInterface::RemoveLinha)
EVT_GRID_CELL_CHANGED(FrameInterface::AlterarGrid)
wxEND_EVENT_TABLE()


wxIMPLEMENT_APP(InterfaceReservatorio);

//Criando a Interface Gráfica
bool InterfaceReservatorio::OnInit()
{
	FrameInterface *frame = new FrameInterface("Reservatorio", wxPoint(50, 50), wxSize(800, 600));
	frame->Show(true);
	return true;
}

//Criando o frame principal
FrameInterface::FrameInterface(const wxString& title, const wxPoint& pos, const wxSize& size)
	: wxFrame(NULL, wxID_ANY, title, pos, size)
{
	//criando o painel que serão adicionado os elementos na interface
	wxPanel* const panel = new wxPanel(this);

	//label e campo inicial do reservatório
	wxStaticText* inicial = new wxStaticText(panel, wxID_ANY, "Inicial(hm^3)", wxPoint(10, 10));
	inicialInput = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(100, 10));

	//label e campo minimo do reservatório
	wxStaticText* minimo = new wxStaticText(panel, wxID_ANY, "Mínimo(hm^3)", wxPoint(10, 50));
	minimoInput = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(100, 50));

	//label e campo maximo do reservatório
	wxStaticText* maximo = new wxStaticText(panel, wxID_ANY, "Máximo(hm^3)", wxPoint(10, 90));
	maximoInput = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(100, 90));

	wxButton* add = new wxButton(panel, ID_Linha, "Adicionar Linha", wxPoint(10, 130));
	wxButton* remove = new wxButton(panel, ID_Remover, "Remover Linha", wxPoint(120, 130));

	//criando a tabela que armazena as faixas
	grid = new wxGrid(panel, wxID_ANY, wxPoint(10, 170), wxSize(382, 1000));
	grid->CreateGrid(0, 3);
	grid->SetColSize(0, 100);
	grid->SetColSize(1, 100);
	grid->SetColSize(2, 100);

	//label das tabelas
	grid->SetColLabelValue(0, "Limite\nInferior(hm^3)");
	grid->SetColLabelValue(1, "Limite\nSuperior(hm^3)");
	grid->SetColLabelValue(2, "Prioridade");

	quantRows = 0;
}

//Recebe um evento e adiciona uma linha no grid
void FrameInterface::AddLinha(wxCommandEvent& event)
{
	grid->AppendRows(1);
	quantRows++;

	//setando o limite inferior e a prioridade 
	grid->SetReadOnly(quantRows - 1, 0);
	grid->SetReadOnly(quantRows - 1, 2);

	//atribuindo o valor da prioridade
	grid->SetCellValue(quantRows - 1, 2, std::to_string(quantRows));
}

//Recebe um evento e remove a ultima linha no grid
void FrameInterface::RemoveLinha(wxCommandEvent& event)
{
	//será removido caso a quantidade de linhas forem maior que 0
	if (quantRows > 0) {
		grid->DeleteRows(quantRows - 1);

		quantRows--;

		//removendo a útima faixa
		faixas.erase(faixas.begin() + quantRows);
	}
}

//Recebe um evento de grid e calcula o valor da faixa inferior
void FrameInterface::AlterarGrid(wxGridEvent& event)
{
	//ciando um reservatório
	int retorno = 0;
	Reservatorio reservatorio = criarReservatorio(&retorno);

	//Mostrar erro causa tenha algum dado invalido no reservatorio
	if (retorno != 0)
	{
		wxLogMessage("Erro!!!");
	}
	else
	{
		//Criando uma faixa
		Faixa faixa = criarFaixa(event, &retorno);

		//Mostrar erro causa tenha algum dado invalido na faixa
		if (retorno != 0)
		{
			wxLogMessage("Erro!!!");
		}
		else
		{
			//atualizar o vvetor de faixas
			retorno = atualizarFaixas(event, faixa);

			//retorna erro caso a faixa mais acima tenha um valor maior ou igual a faixa mais abaixo
			if (retorno != 0)
			{
				wxLogMessage("Erro!!!");
			}
			else
			{
				//Executando o controle do reservatorio e faixa e calculando as o volume das zonas de prioridades
				ControllerReservatorio ctrReser;
				vector<Tupla>tuplas = ctrReser.atualizar(reservatorio, faixas);

				//atualizando o grid da interface
				atualizaGrid(tuplas);
			}
		}
	}
}


//Criação e validação do Reservatório
Reservatorio FrameInterface::criarReservatorio(int* retorno)
{
	double inicial = 0;
	double minimo = 0;
	double maximo = 0;

	wxString strInicial = inicialInput->GetValue();
	wxString strMinimo = minimoInput->GetValue();
	wxString strMaximo = maximoInput->GetValue();

	strInicial.ToDouble(&inicial);
	strMinimo.ToDouble(&minimo);
	strMaximo.ToDouble(&maximo);

	Reservatorio resevatorio(inicial, minimo, maximo);
	*retorno = resevatorio.validar();

	return resevatorio;
}

//Criação e validação da Faixa
Faixa FrameInterface::criarFaixa(wxGridEvent& event, int* retorno)
{
	int linha = event.GetRow();
	int coluna = event.GetCol();

	double valorFaixa = 0;

	wxString valor = grid->GetCellValue(linha, coluna);
	valor.ToDouble(&valorFaixa);

	Faixa faixa(linha + 1, valorFaixa);
	*retorno = faixa.validar();

	return faixa;
}

//Atualização do vetor de faixas, caso não haja a faixa no vetor é adicionado uma nova faixa
int FrameInterface::atualizarFaixas(wxGridEvent& event, Faixa faixa)
{
	int retorno = 0;
	int linha = event.GetRow();

	//adicionandod uma nova faixa
	if (linha == faixas.size()) {
		faixas.push_back(faixa);
	}
	else { //atualizando a faixa
		faixas[linha] = faixa;
	}

	//recuperando o indice o volume da ultima faixa
	int indice = faixas.size() - 1;
	double validacaoFaixa = faixas[indice].getFaixaSuperior();

	//verificando se existe alguma faixa mais acima com o volume maior ou igual a uma faixa mais abaixo
	for (int i = indice - 1; i >= 0; i--) {
		if (faixas[i].getFaixaSuperior() >= validacaoFaixa) {
			retorno = -5; //atualizando o erro
			break;
		}

		validacaoFaixa = faixas[i].getFaixaSuperior();
	}

	return retorno;
}

//atualizando o grid da interface gráfica
void FrameInterface::atualizaGrid(vector<Tupla>& tuplas)
{
	//percorrendo as tuplas com formato Tupla<prioridade, Volume e atualizando os dados do grid
	for (size_t i = 0; i < tuplas.size(); i++)
	{
		int prioridade;
		double volume;
		tie(prioridade, volume) = tuplas[i];

		wxString resp(std::to_string(volume));

		grid->SetCellValue(resp, i, 0);
	}
}



