/***************************************************************
 * Name:      rownanieMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Igor ()
 * Created:   2023-10-04
 * Copyright: Igor i Viktor ()
 * License:
 **************************************************************/

#include "rownanieMain.h"
#include <wx/msgdlg.h>
#include "rozwiazanie.h" //lub #include <rozwiazanie.h>
//(*InternalHeaders(rownanieDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

#undef _
#define _(s) wxString::FromUTF8(s)  // polski litery

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

//(*IdInit(rownanieDialog)
const long rownanieDialog::ID_STATICTEXT1 = wxNewId();
const long rownanieDialog::ID_STATICTEXT2 = wxNewId();
const long rownanieDialog::ID_TEXTCTRL3 = wxNewId();
const long rownanieDialog::ID_STATICTEXT3 = wxNewId();
const long rownanieDialog::ID_TEXTCTRL1 = wxNewId();
const long rownanieDialog::ID_STATICTEXT4 = wxNewId();
const long rownanieDialog::ID_TEXTCTRL2 = wxNewId();
const long rownanieDialog::ID_BUTTON1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(rownanieDialog,wxDialog)
    //(*EventTable(rownanieDialog)
    //*)
END_EVENT_TABLE()

rownanieDialog::rownanieDialog(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(rownanieDialog)
    wxBoxSizer* BoxSizer1;
    wxFlexGridSizer* FlexGridSizer1;
    wxFlexGridSizer* FlexGridSizer2;
    wxFlexGridSizer* FlexGridSizer3;
    wxFlexGridSizer* FlexGridSizer4;

    Create(parent, wxID_ANY, _("Antoniuk Davyd"), wxDefaultPosition, wxDefaultSize, wxSTAY_ON_TOP|wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER|wxCLOSE_BOX|wxMAXIMIZE_BOX|wxMINIMIZE_BOX, _T("wxID_ANY"));
    FlexGridSizer1 = new wxFlexGridSizer(4, 1, 0, 0);
    FlexGridSizer1->AddGrowableCol(0);
    FlexGridSizer1->AddGrowableRow(3);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Szukanie miejsca zerowego funkcji metodą bisekcji"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE, _T("ID_STATICTEXT1"));
    FlexGridSizer1->Add(StaticText1, 1, wxALL|wxEXPAND, 5);
    FlexGridSizer2 = new wxFlexGridSizer(1, 2, 0, 0);
    FlexGridSizer2->AddGrowableCol(1);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("wzór funkcji f(x):"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    FlexGridSizer2->Add(StaticText2, 1, wxALL|wxEXPAND, 5);
    TextCtrl3 = new wxTextCtrl(this, ID_TEXTCTRL3, _("x^2+2*x-3"), wxDefaultPosition, wxSize(194,23), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    FlexGridSizer2->Add(TextCtrl3, 1, wxALL|wxEXPAND, 5);
    FlexGridSizer1->Add(FlexGridSizer2, 1, wxALL|wxEXPAND, 5);
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    FlexGridSizer3 = new wxFlexGridSizer(1, 2, 0, 0);
    FlexGridSizer3->AddGrowableCol(1);
    StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("lewy:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    FlexGridSizer3->Add(StaticText3, 1, wxALL|wxEXPAND, 5);
    TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, _("0"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    FlexGridSizer3->Add(TextCtrl1, 1, wxALL|wxEXPAND, 5);
    BoxSizer1->Add(FlexGridSizer3, 1, wxALL|wxEXPAND, 5);
    FlexGridSizer4 = new wxFlexGridSizer(1, 2, 0, 0);
    FlexGridSizer4->AddGrowableCol(1);
    StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("prawy:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    FlexGridSizer4->Add(StaticText4, 1, wxALL|wxEXPAND, 5);
    TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, _("10"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    FlexGridSizer4->Add(TextCtrl2, 1, wxALL|wxEXPAND, 5);
    BoxSizer1->Add(FlexGridSizer4, 1, wxALL|wxEXPAND, 5);
    FlexGridSizer1->Add(BoxSizer1, 1, wxALL|wxEXPAND, 5);
    Button1 = new wxButton(this, ID_BUTTON1, _("Oblicz"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    FlexGridSizer1->Add(Button1, 1, wxALL|wxEXPAND, 5);
    SetSizer(FlexGridSizer1);
    FlexGridSizer1->Fit(this);
    FlexGridSizer1->SetSizeHints(this);

    Connect(ID_TEXTCTRL2,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&rownanieDialog::OnTextCtrl2Text);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&rownanieDialog::OnButton1Click);
    Connect(wxID_ANY,wxEVT_INIT_DIALOG,(wxObjectEventFunction)&rownanieDialog::OnInit1);
    //*)
    SetIcon(wxICON(aaaa));
}

rownanieDialog::~rownanieDialog()
{
    //(*Destroy(rownanieDialog)
    //*)
}

void rownanieDialog::OnQuit(wxCommandEvent& event)
{
    Close();
}

void rownanieDialog::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void rownanieDialog::OnInit(wxInitDialogEvent& event)
{
}
std::string w2s(const wxString & w){
    return std::string(w.mb_str(wxConvUTF8));
}
void rownanieDialog::OnButton1Click(wxCommandEvent& event)
{
    rozwiazanie r(w2s (TextCtrl3->GetValue()), w2s(TextCtrl1->GetValue()),
                   w2s (TextCtrl2->GetValue()));
    if (r.OK()) {
            wxMessageBox(_(r.komunikat ()),_ ("Sukces!"), wxICON_INFORMATION);
    } else {
        wxMessageBox (_(r.komunikat ()),_("Problem"), wxICON_ERROR);
    }
}

void rownanieDialog::OnTextCtrl2Text(wxCommandEvent& event)
{
}


void rownanieDialog::OnInit1(wxInitDialogEvent& event)
{
}
