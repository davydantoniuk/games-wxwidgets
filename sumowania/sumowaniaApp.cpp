/***************************************************************
 * Name:      sumowaniaApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Davyd Antoniuk ()
 * Created:   2023-10-26
 * Copyright: Davyd Antoniuk ()
 * License:
 **************************************************************/

#include "sumowaniaApp.h"

//(*AppHeaders
#include "sumowaniaMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(sumowaniaApp);

bool sumowaniaApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	sumowaniaDialog Dlg(0);
    	SetTopWindow(&Dlg);
    	Dlg.ShowModal();
    	wxsOK = false;
    }
    //*)
    return wxsOK;

}
