#include "DialogoDerivada.h"

// Implementaci�n de la clase derivada de di�logo

DialogoDerivada::DialogoDerivada(wxFrame *parent) : MyDialog1(parent)
{

}

DialogoDerivada::~DialogoDerivada()
{

}


// M�todo de evento a�adido
void DialogoDerivada::DialogClose(wxCommandEvent& event)
{
    this->Close();
}
