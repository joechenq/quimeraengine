
#ifndef DIALOGODERIVADA_H
#define DIALOGODERIVADA_H



#include "POCFormBuilderApp.h"

#include "wx/msgdlg.h"
#include "GUIFrame.h"


// Clase derivada del di�logo. Esta clase se ha a�adido a mano, se pod�a haber generado con FormBuilder (Tools->Generate Inherit Class)

class DialogoDerivada: public MyDialog1
{
    public:
        DialogoDerivada(wxFrame *parent);
        ~DialogoDerivada();
    private:
        // Declaraci�n de m�todo de evento a�adido
        virtual void DialogClose( wxCommandEvent& event );
};

#endif // DIALOGODERIVADA_H
