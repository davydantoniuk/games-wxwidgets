/***************************************************************
 * Name:      sumowaniaMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Davyd Antoniuk ()
 * Created:   2023-10-26
 * Copyright: Davyd Antoniuk ()
 * License:
 **************************************************************/

#include "sumowaniaMain.h"
#include <wx/msgdlg.h>
#include "dodawania.h"

//(*InternalHeaders(sumowaniaDialog)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/settings.h>
#include <wx/string.h>
//*)

#undef _
#define _(s) wxString::FromUTF8(s) // polski litery

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

//(*IdInit(sumowaniaDialog)
const long sumowaniaDialog::ID_STATICTEXT1 = wxNewId();
const long sumowaniaDialog::ID_BUTTON1 = wxNewId();
const long sumowaniaDialog::ID_TEXTCTRL1 = wxNewId();
const long sumowaniaDialog::ID_CHECKBOX1 = wxNewId();
const long sumowaniaDialog::ID_CHECKBOX2 = wxNewId();
const long sumowaniaDialog::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(sumowaniaDialog,wxDialog)
    //(*EventTable(sumowaniaDialog)
    //*)
END_EVENT_TABLE()

sumowaniaDialog::sumowaniaDialog(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(sumowaniaDialog)
    wxBoxSizer* BoxSizer1;
    wxFlexGridSizer* FlexGridSizer1;
    wxFlexGridSizer* FlexGridSizer2;
    wxFlexGridSizer* FlexGridSizer3;
    wxFlexGridSizer* FlexGridSizer4;

    Create(parent, wxID_ANY, _("sumowania"), wxDefaultPosition, wxDefaultSize, wxSTAY_ON_TOP|wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER|wxCLOSE_BOX|wxMAXIMIZE_BOX|wxMINIMIZE_BOX, _T("wxID_ANY"));
    SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOWTEXT));
    SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_SCROLLBAR));
    FlexGridSizer1 = new wxFlexGridSizer(4, 1, 0, 0);
    FlexGridSizer1->AddGrowableCol(0);
    FlexGridSizer1->AddGrowableRow(3);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Sumowania liczb z pliku tekstowego"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE, _T("ID_STATICTEXT1"));
    wxFont StaticText1Font(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("@Microsoft JhengHei"),wxFONTENCODING_DEFAULT);
    StaticText1->SetFont(StaticText1Font);
    FlexGridSizer1->Add(StaticText1, 1, wxALL|wxEXPAND, 5);
    FlexGridSizer2 = new wxFlexGridSizer(1, 2, 0, 0);
    FlexGridSizer2->AddGrowableCol(1);
    Button1 = new wxButton(this, ID_BUTTON1, _("Wybierz plik"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    FlexGridSizer2->Add(Button1, 1, wxALL|wxEXPAND, 5);
    TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, _("jeszce nie wybrany..."), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    TextCtrl1->Disable();
    FlexGridSizer2->Add(TextCtrl1, 1, wxALL|wxEXPAND, 5);
    FlexGridSizer1->Add(FlexGridSizer2, 1, wxALL|wxEXPAND, 5);
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    FlexGridSizer3 = new wxFlexGridSizer(1, 1, 0, 0);
    CheckBox1 = new wxCheckBox(this, ID_CHECKBOX1, _("pomiń 1.wiersz"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
    CheckBox1->SetValue(true);
    FlexGridSizer3->Add(CheckBox1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(FlexGridSizer3, 1, wxALL|wxEXPAND, 5);
    FlexGridSizer4 = new wxFlexGridSizer(1, 1, 0, 0);
    CheckBox2 = new wxCheckBox(this, ID_CHECKBOX2, _("pomiń 1.kolumnę"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX2"));
    CheckBox2->SetValue(false);
    FlexGridSizer4->Add(CheckBox2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(FlexGridSizer4, 1, wxALL|wxEXPAND, 5);
    FlexGridSizer1->Add(BoxSizer1, 1, wxALL|wxEXPAND, 5);
    Button2 = new wxButton(this, ID_BUTTON2, _("Oblicz"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    FlexGridSizer1->Add(Button2, 1, wxALL|wxEXPAND, 5);
    SetSizer(FlexGridSizer1);
    FileDialog1 = new wxFileDialog(this, _("Wybierz plik"), wxEmptyString, wxEmptyString, _("*.txt"), wxFD_DEFAULT_STYLE|wxFD_FILE_MUST_EXIST, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
    FlexGridSizer1->Fit(this);
    FlexGridSizer1->SetSizeHints(this);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&sumowaniaDialog::OnButton1Click);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&sumowaniaDialog::OnButton2Click);
    Connect(wxID_ANY,wxEVT_INIT_DIALOG,(wxObjectEventFunction)&sumowaniaDialog::OnInit);
    //*)



    SetIcon(wxICON(aaaa));
}

sumowaniaDialog::~sumowaniaDialog()
{
    //(*Destroy(sumowaniaDialog)
    //*)
}

void sumowaniaDialog::OnQuit(wxCommandEvent& event)
{
    Close();
}

void sumowaniaDialog::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

/*std::string w2s(const wxString & w){
    return std::string(w.mb_str(wxConvUTF8));
}

void sumowaniaDialog::OnButton2Click(wxCommandEvent& event)
{
    dodawania d(w2s (TextCtrl1->GetValue()),CheckBox1->IsChecked(),CheckBox2->IsChecked());  //w2s (TextCtrl->GetValue())
    if (d.OK()) {
            wxMessageBox(_(d.komunikat ()),_ ("Sukces!"), wxICON_INFORMATION);
    } else {
        wxMessageBox (_(d.komunikat ()),_("Problem"), wxICON_ERROR);
    }
}
*/
////

void sumowaniaDialog::OnButton2Click(wxCommandEvent& event)
{
    dodawania d(TextCtrl1->GetValue().ToStdString(),CheckBox1->GetValue(),CheckBox2->GetValue());  //w2s (TextCtrl->GetValue())
    if (d.OK()) {
        wxString w;
        w << d.wynik();
        wxMessageBox(_("suma wynosi: ")+w,_ ("sukces!"), wxICON_INFORMATION);
    } else {
        wxMessageBox (_("nie udało się obliczyć sumy,problem z otwarciem pliku:("),_("błąd"), wxICON_ERROR);
    }
}



void sumowaniaDialog::OnInit(wxInitDialogEvent& event)
{
}

void sumowaniaDialog::OnButton1Click(wxCommandEvent& event)
{
        if (FileDialog1->ShowModal()!=wxID_CANCEL)
        TextCtrl1->SetValue(FileDialog1->GetPath());
}
