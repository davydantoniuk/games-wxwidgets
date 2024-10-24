/***************************************************************
 * Name:      kolko_krzyzykMain.h
 * Purpose:   Defines Application Frame
 * Author:    Antoniuk Davyd()
 * Created:   2023-11-16
 * Copyright: Antoniuk Davyd()
 * License:
 **************************************************************/

#ifndef KOLKO_KRZYZYKMAIN_H
#define KOLKO_KRZYZYKMAIN_H
#include <map>
using namespace std;
//(*Headers(kolko_krzyzykDialog)
#include <wx/bmpbuttn.h>
#include <wx/button.h>
#include <wx/checkbox.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
//*)

class kolko_krzyzykDialog: public wxDialog
{
    public:

        kolko_krzyzykDialog(wxWindow* parent,wxWindowID id = -1);
        virtual ~kolko_krzyzykDialog();

    private:

        //(*Handlers(kolko_krzyzykDialog)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnBitmapButton1Click(wxCommandEvent& event);
        void OnCheckBox1Click(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnButton1Click1(wxCommandEvent& event);
        //*)

        //(*Identifiers(kolko_krzyzykDialog)
        static const long ID_CHECKBOX1;
        static const long ID_BITMAPBUTTON1;
        static const long ID_BUTTON1;
        //*)

        //(*Declarations(kolko_krzyzykDialog)
        wxBitmapButton* BitmapButton1;
        wxButton* Button1;
        wxCheckBox* CheckBox1;
        //*)

        DECLARE_EVENT_TABLE()

        wxBitmapButton* pola[9]; //dodano
        map<int,int> id2nr; //dodano
};

#endif // KOLKO_KRZYZYKMAIN_H
