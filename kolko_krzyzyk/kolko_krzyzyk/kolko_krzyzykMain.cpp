/***************************************************************
 * Name:      kolko_krzyzykMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Antoniuk Davyd ()
 * Created:   2023-11-16
 * Copyright: Antoniuk Davyd ()
 * License:
 **************************************************************/

#include "kolko_krzyzykMain.h"
#include <wx/msgdlg.h>
#include <iostream>
using namespace std;
//(*InternalHeaders(kolko_krzyzykDialog)
#include <wx/intl.h>
#include <wx/settings.h>
#include <wx/string.h>
//*)

#undef _
#define _(s) wxString::FromUTF8(s)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(kolko_krzyzykDialog)
const long kolko_krzyzykDialog::ID_CHECKBOX1 = wxNewId();
const long kolko_krzyzykDialog::ID_BITMAPBUTTON1 = wxNewId();
const long kolko_krzyzykDialog::ID_BUTTON1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(kolko_krzyzykDialog,wxDialog)
    //(*EventTable(kolko_krzyzykDialog)
    //*)
END_EVENT_TABLE()

kolko_krzyzykDialog::kolko_krzyzykDialog(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(kolko_krzyzykDialog)
    wxFlexGridSizer* FlexGridSizer1;
    wxGridSizer* GridSizer1;

    Create(parent, wxID_ANY, _("Kółko i Krzyżyk"), wxDefaultPosition, wxDefaultSize, wxSTAY_ON_TOP|wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER|wxCLOSE_BOX|wxMAXIMIZE_BOX|wxMINIMIZE_BOX, _T("wxID_ANY"));
    FlexGridSizer1 = new wxFlexGridSizer(3, 0, 0, 0);
    FlexGridSizer1->AddGrowableCol(0);
    FlexGridSizer1->AddGrowableRow(1);
    CheckBox1 = new wxCheckBox(this, ID_CHECKBOX1, _("zacyna człowiek"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
    CheckBox1->SetValue(true);
    FlexGridSizer1->Add(CheckBox1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer1 = new wxGridSizer(3, 3, 0, 0);
    BitmapButton1 = new wxBitmapButton(this, ID_BITMAPBUTTON1, wxNullBitmap, wxDefaultPosition, wxSize(40,40), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON1"));
    BitmapButton1->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INFOBK));
    GridSizer1->Add(BitmapButton1, 1, wxALL|wxEXPAND, 5);
    FlexGridSizer1->Add(GridSizer1, 1, wxALL|wxEXPAND, 5);
    Button1 = new wxButton(this, ID_BUTTON1, _("nowa gra"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    FlexGridSizer1->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(FlexGridSizer1);
    FlexGridSizer1->Fit(this);
    FlexGridSizer1->SetSizeHints(this);

    Connect(ID_CHECKBOX1,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&kolko_krzyzykDialog::OnCheckBox1Click);
    Connect(ID_BITMAPBUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&kolko_krzyzykDialog::OnBitmapButton1Click);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&kolko_krzyzykDialog::OnButton1Click1);
    //*)
    pola[0] = BitmapButton1;
    for(int i=1;i<9;i++)
    {
        pola[i] = new wxBitmapButton(this, ID_BITMAPBUTTON1+i+1, wxNullBitmap, wxDefaultPosition, wxSize(40,40), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_CHECKBOX1")); //wxString::Format("ID_BITMAPBUTTON%d", i + 1)
        pola[i]->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INFOBK));
        GridSizer1->Add(pola[i], 1, wxALL|wxEXPAND, 5);
        Connect(pola[i]->GetId(),wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&kolko_krzyzykDialog::OnBitmapButton1Click);
    }
    for(int i=0;i<9;i++)
    {
        id2nr[pola[i]->GetId()]= i;
    }
    SetIcon(wxICON(aaaa));
}

void kolko_krzyzykDialog::OnBitmapButton1Click(wxCommandEvent& event)
{
    int id = event.GetId();
    int numer = id2nr[id]+1;
    wxString w = "klik: ";
    w << numer;
    wxMessageBox(w);
}

kolko_krzyzykDialog::~kolko_krzyzykDialog()
{
    //(*Destroy(kolko_krzyzykDialog)
    //*)
}

void kolko_krzyzykDialog::OnQuit(wxCommandEvent& event)
{
    Close();
}

void kolko_krzyzykDialog::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}



void kolko_krzyzykDialog::OnCheckBox1Click(wxCommandEvent& event)
{
}

void kolko_krzyzykDialog::OnButton1Click(wxCommandEvent& event)
{
}

void kolko_krzyzykDialog::OnButton1Click1(wxCommandEvent& event)
{

}
