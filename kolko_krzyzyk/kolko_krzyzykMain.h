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
#include "kik.h"
using namespace std;
//(*Headers(kolko_krzyzykDialog)
#include <wx/bmpbuttn.h>
#include <wx/button.h>
#include <wx/checkbox.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/timer.h>
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
        void OnButton1Click(wxCommandEvent& event);
        void OnTimer1Trigger(wxTimerEvent& event);
        //*)

        //(*Identifiers(kolko_krzyzykDialog)
        static const long ID_CHECKBOX1;
        static const long ID_BITMAPBUTTON1;
        static const long ID_BUTTON1;
        static const long ID_STATICTEXT1;
        static const long ID_TIMER1;
        //*)

        //(*Declarations(kolko_krzyzykDialog)
        wxBitmapButton* BitmapButton1;
        wxButton* Button1;
        wxCheckBox* CheckBox1;
        wxStaticText* StaticText1;
        wxTimer Timer1;
        //*)

        DECLARE_EVENT_TABLE()
        double remainingTimeInSeconds;
        wxBitmapButton* pola[9]; //dodano

        wxBitmap rysunki[3];

        map<int,int> id2nr; //dodano

        kik gra;

        int licznik = 0;
        double czas;
};

#endif // KOLKO_KRZYZYKMAIN_H
