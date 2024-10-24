/***************************************************************
 * Name:      kolko_krzyzykApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Antoniuk Davyd()
 * Created:   2023-11-16
 * Copyright: Antoniuk Davyd()
 * License:
 **************************************************************/

#include "kolko_krzyzykApp.h"

//(*AppHeaders
#include "kolko_krzyzykMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(kolko_krzyzykApp);

bool kolko_krzyzykApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	kolko_krzyzykDialog Dlg(0);
    	SetTopWindow(&Dlg);
    	Dlg.ShowModal();
    	wxsOK = false;
    }
    //*)
    return wxsOK;

}
