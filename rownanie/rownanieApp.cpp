/***************************************************************
 * Name:      rownanieApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Davyd ()
 * Created:   2023-10-04
 * Copyright: Davyd ()
 * License:
 **************************************************************/

#include "rownanieApp.h"

//(*AppHeaders
#include "rownanieMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(rownanieApp);

bool rownanieApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	rownanieDialog Dlg(0);
    	SetTopWindow(&Dlg);
    	Dlg.ShowModal();
    	wxsOK = false;
    }
    //*)
    return wxsOK;

}

