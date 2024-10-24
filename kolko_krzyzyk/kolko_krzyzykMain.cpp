/***************************************************************
 * Name:      kolko_krzyzykMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Antoniuk Davyd ()
 * Created:   2023-11-16
 * Copyright: Antoniuk Davyd ()
 * License:
 **************************************************************/
//project-BUILD_OPTIONS-static linking
//upx.github.io // upxwin64
//upx kik\..exe
// https://www.createinstall.com/
#include "kolko_krzyzykMain.h"
#include <wx/msgdlg.h>
#include <iostream>
#include "kik.h"
using namespace std;
//(*InternalHeaders(kolko_krzyzykDialog)
#include <wx/bitmap.h>
#include <wx/image.h>
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
const long kolko_krzyzykDialog::ID_STATICTEXT1 = wxNewId();
const long kolko_krzyzykDialog::ID_TIMER1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(kolko_krzyzykDialog,wxDialog)
    //(*EventTable(kolko_krzyzykDialog)
    //*)
END_EVENT_TABLE()

kolko_krzyzykDialog::kolko_krzyzykDialog(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(kolko_krzyzykDialog)
    wxFlexGridSizer* FlexGridSizer1;
    wxFlexGridSizer* FlexGridSizer2;
    wxGridSizer* GridSizer1;

    Create(parent, wxID_ANY, _("Kółko i Krzyżyk"), wxDefaultPosition, wxDefaultSize, wxSTAY_ON_TOP|wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER|wxCLOSE_BOX|wxMAXIMIZE_BOX|wxMINIMIZE_BOX, _T("wxID_ANY"));
    SetClientSize(wxSize(800,800));
    FlexGridSizer1 = new wxFlexGridSizer(3, 0, 0, 0);
    FlexGridSizer1->AddGrowableCol(0);
    FlexGridSizer1->AddGrowableRow(1);
    CheckBox1 = new wxCheckBox(this, ID_CHECKBOX1, _("zacżyna człowiek"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
    CheckBox1->SetValue(true);
    FlexGridSizer1->Add(CheckBox1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer1 = new wxGridSizer(3, 3, 0, 0);
    BitmapButton1 = new wxBitmapButton(this, ID_BITMAPBUTTON1, wxBitmap(wxImage(_T("png/pusty.png"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON1"));
    BitmapButton1->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INFOBK));
    GridSizer1->Add(BitmapButton1, 1, wxALL|wxEXPAND, 5);
    FlexGridSizer1->Add(GridSizer1, 1, wxALL|wxEXPAND, 5);
    FlexGridSizer2 = new wxFlexGridSizer(0, 2, 0, 0);
    FlexGridSizer2->AddGrowableCol(0);
    Button1 = new wxButton(this, ID_BUTTON1, _("nowa gra"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    FlexGridSizer2->Add(Button1, 1, wxALL|wxEXPAND, 5);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("9999.9"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    FlexGridSizer2->Add(StaticText1, 1, wxALL, 5);
    FlexGridSizer1->Add(FlexGridSizer2, 1, wxALL|wxEXPAND, 5);
    SetSizer(FlexGridSizer1);
    Timer1.SetOwner(this, ID_TIMER1);
    Timer1.Start(17, false);
    SetSizer(FlexGridSizer1);
    Layout();

    Connect(ID_CHECKBOX1,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&kolko_krzyzykDialog::OnButton1Click);
    Connect(ID_BITMAPBUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&kolko_krzyzykDialog::OnBitmapButton1Click);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&kolko_krzyzykDialog::OnButton1Click);
    Connect(ID_TIMER1,wxEVT_TIMER,(wxObjectEventFunction)&kolko_krzyzykDialog::OnTimer1Trigger);
    //*)
    pola[0] = BitmapButton1;

    rysunki[0]=wxBitmap(wxImage("png/pusty.png"));
    rysunki[1]=wxBitmap(wxImage("png/kolko.png"));
    rysunki[2]=wxBitmap(wxImage("png/krzyz.png"));

    for(int i=1;i<9;i++)
    {
        pola[i] = new wxBitmapButton(this, wxNewId(), rysunki[0], wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_CHECKBOX1")); //wxString::Format("ID_BITMAPBUTTON%d", i + 1)
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



/*
auto wynik=gra.co_dalej();

int poz,rys;
tie(poz,rys)=gra.co_dalej();

auto[poz,rys]=gra.co_dalej();
*/


void kolko_krzyzykDialog::OnBitmapButton1Click(wxCommandEvent& event)
{
    int id = event.GetId();
    int numer = id2nr[id];
    int rys = gra.ruch_czlowieka(numer);
    if (rys == 0) {
        return;
    }
    pola[numer]->SetBitmap(rysunki[rys]);
    int rezultat = gra.rezultat();
    wxString message;
    if (rezultat == 1) {
        Timer1.Stop();
        wxMessageBox(wxString::Format(_("Koniec gry, remis! Czas gry: %.2lf sekund."), czas),_("Koniec..."));
        gra.restart(true);
    } else if (rezultat == 2) {
        Timer1.Stop();
        wxMessageBox(wxString::Format(_("Koniec gry, wygrałeś! Czas gry: %.2lf sekund."), czas),_("Koniec :)"));
        gra.restart(true);
    } else if (rezultat == 3) {
        Timer1.Stop();
        wxMessageBox(wxString::Format(_("Koniec gry, zwycięstwo komputera! Czas gry: %.2lf sekund."), czas), _("Koniec :("));
        gra.restart(true);
    } else {
        std::pair<int, int> ruch_komputera = gra.co_dalej();
        int numer_komputera = ruch_komputera.first;
        int rys_komputera = ruch_komputera.second;
        pola[numer_komputera]->SetBitmap(rysunki[rys_komputera]);
        int rezultat_komputera = gra.rezultat();
        if (rezultat_komputera == 1) {
            Timer1.Stop();
            wxMessageBox(wxString::Format(_("Koniec gry, remis! Czas gry: %.2lf sekund."), czas),_("Koniec..."));
            gra.restart(true);
        } else if (rezultat_komputera == 2) {
            Timer1.Stop();
            wxMessageBox(wxString::Format(_("Koniec gry, wygrałeś! Czas gry: %.2lf sekund."), czas),_("Koniec :)"));
            gra.restart(true);
        } else if (rezultat_komputera == 3) {
            Timer1.Stop();
            wxMessageBox(wxString::Format(_("Koniec gry, zwycięstwo komputera! Czas gry: %.2lf sekund."), czas), _("Koniec :("));
            gra.restart(true);
        }
    }
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




void kolko_krzyzykDialog::OnButton1Click(wxCommandEvent& event)
{
    for (int i = 0; i < 9; i++) {
        pola[i]->SetBitmap(rysunki[0]);
    }
    gra.restart(CheckBox1->GetValue());
    if (!CheckBox1->GetValue()) {
        std::pair<int, int> ruch_komputera = gra.co_dalej();
        int numer_komputera = ruch_komputera.first;
        int rys_komputera = ruch_komputera.second;
        pola[numer_komputera]->SetBitmap(rysunki[rys_komputera]);
    }
    Timer1.Stop();
    licznik=0;
    Timer1.Start();
}

void kolko_krzyzykDialog::OnTimer1Trigger(wxTimerEvent& event)
{
    licznik++;
    czas = licznik*Timer1.GetInterval()/1000.0;
    wxString czasStr = wxString::Format(wxT("%.2lf"), czas);
    StaticText1->SetLabel(czasStr);
}
