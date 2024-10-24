/***************************************************************
 * Name:      rownanieMain.h
 * Purpose:   Defines Application Frame
 * Author:    Davyd ()
 * Created:   2023-10-04
 * Copyright: Davyd ()
 * License:
 **************************************************************/

#ifndef ROWNANIEMAIN_H
#define ROWNANIEMAIN_H

//(*Headers(rownanieDialog)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class rownanieDialog: public wxDialog
{
    public:

        rownanieDialog(wxWindow* parent,wxWindowID id = -1);
        virtual ~rownanieDialog();

    private:

        //(*Handlers(rownanieDialog)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnInit(wxInitDialogEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnTextCtrl2Text(wxCommandEvent& event);
        void OnInit1(wxInitDialogEvent& event);
        //*)

        //(*Identifiers(rownanieDialog)
        static const long ID_STATICTEXT1;
        static const long ID_STATICTEXT2;
        static const long ID_TEXTCTRL3;
        static const long ID_STATICTEXT3;
        static const long ID_TEXTCTRL1;
        static const long ID_STATICTEXT4;
        static const long ID_TEXTCTRL2;
        static const long ID_BUTTON1;
        //*)

        //(*Declarations(rownanieDialog)
        wxButton* Button1;
        wxStaticText* StaticText1;
        wxStaticText* StaticText2;
        wxStaticText* StaticText3;
        wxStaticText* StaticText4;
        wxTextCtrl* TextCtrl1;
        wxTextCtrl* TextCtrl2;
        wxTextCtrl* TextCtrl3;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // ROWNANIEMAIN_H
