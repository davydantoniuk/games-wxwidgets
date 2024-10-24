/***************************************************************
 * Name:      sumowaniaMain.h
 * Purpose:   Defines Application Frame
 * Author:    Davyd Antoniuk ()
 * Created:   2023-10-26
 * Copyright: Davyd Antoniuk ()
 * License:
 **************************************************************/

#ifndef SUMOWANIAMAIN_H
#define SUMOWANIAMAIN_H

//(*Headers(sumowaniaDialog)
#include <wx/button.h>
#include <wx/checkbox.h>
#include <wx/dialog.h>
#include <wx/filedlg.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class sumowaniaDialog: public wxDialog
{
    public:

        sumowaniaDialog(wxWindow* parent,wxWindowID id = -1);
        virtual ~sumowaniaDialog();


    private:

        //(*Handlers(sumowaniaDialog)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnCheckBox2Click(wxCommandEvent& event);
        void OnButton2Click(wxCommandEvent& event);
        void OnCheckBox1Click(wxCommandEvent& event);
        void OnInit(wxInitDialogEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        //*)

        //(*Identifiers(sumowaniaDialog)
        static const long ID_STATICTEXT1;
        static const long ID_BUTTON1;
        static const long ID_TEXTCTRL1;
        static const long ID_CHECKBOX1;
        static const long ID_CHECKBOX2;
        static const long ID_BUTTON2;
        //*)

        //(*Declarations(sumowaniaDialog)
        wxButton* Button1;
        wxButton* Button2;
        wxCheckBox* CheckBox1;
        wxCheckBox* CheckBox2;
        wxFileDialog* FileDialog1;
        wxStaticText* StaticText1;
        wxTextCtrl* TextCtrl1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // SUMOWANIAMAIN_H
