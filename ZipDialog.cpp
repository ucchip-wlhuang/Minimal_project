#include "ZipDialog.h"

ZipDialog::ZipDialog(wxWindow *parent)
			:wxDialog(parent, wxID_ANY, "Import Template ZipFile")
{
	wxBoxSizer* dlgbox = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* dlgbox1 = new wxBoxSizer(wxHORIZONTAL);
	wxStaticText* pathtext = new wxStaticText(this, wxID_ANY, "Path: ");
	zip_path = new wxTextCtrl(this, ID_ZipPath, wxEmptyString, wxDefaultPosition, wxSize(300,-1));
	btn_choose = new wxButton(this, ID_ChooseBtn, "...", wxDefaultPosition, wxSize(40,-1));
	dlgbox1->Add(pathtext, 0, wxALL|wxALIGN_CENTER_VERTICAL, wxBorder(10));
	dlgbox1->Add(zip_path, 1, wxALL|wxALIGN_CENTER_VERTICAL, wxBorder(10));
	dlgbox1->Add(btn_choose, 0, wxALL|wxALIGN_CENTER_VERTICAL, wxBorder(10));
	wxBoxSizer* dlgbox2 = new wxBoxSizer(wxHORIZONTAL);
	btn_ok = new wxButton(this, ID_Unzip, "Import", wxDefaultPosition, wxDefaultSize);
	btn_all = new wxButton(this, ID_UnzipAll, "All zipfiles under template_dir", wxDefaultPosition, wxDefaultSize);
	btn_help = new wxButton(this, ID_Help, "Help", wxDefaultPosition, wxDefaultSize);
	dlgbox2->Add(btn_help, 0, wxALL, wxBorder(10));
	dlgbox2->Add(btn_all, 0, wxALL, wxBorder(10));
	dlgbox2->Add(btn_ok, 0, wxALL, wxBorder(10));
	
	dlgbox->Add(dlgbox1, 0, wxTOP|wxBOTTOM, wxBorder(20));
	dlgbox->Add(dlgbox2, 0, wxALIGN_CENTER);
	SetSizerAndFit(dlgbox);
	
	this->Bind(wxEVT_BUTTON, &ZipDialog::OnShowChoice, this, ID_ChooseBtn);
	this->Bind(wxEVT_BUTTON, &ZipDialog::OnTips, this, ID_Help);
	this->Bind(wxEVT_BUTTON, &ZipDialog::OnImport, this, ID_Unzip);
	this->Bind(wxEVT_BUTTON, &ZipDialog::OnUnzipAll, this, ID_UnzipAll);
}

ZipDialog::~ZipDialog()
{
	this->Unbind(wxEVT_BUTTON, &ZipDialog::OnShowChoice, this, ID_ChooseBtn);
	this->Unbind(wxEVT_BUTTON, &ZipDialog::OnTips, this, ID_Help);
	this->Unbind(wxEVT_BUTTON, &ZipDialog::OnImport, this, ID_Unzip);
	this->Unbind(wxEVT_BUTTON, &ZipDialog::OnUnzipAll, this, ID_UnzipAll);
}

void ZipDialog::OnShowChoice(wxCommandEvent& event)
{
	wxUnusedVar(event);
    const wxString ALL(wxT("Zip File (*.zip)|*.zip"));
    wxFileDialog dlg(this, _("Open File"), wxEmptyString, wxEmptyString, ALL, wxFD_OPEN | wxFD_FILE_MUST_EXIST, wxDefaultPosition);
    if(dlg.ShowModal() == wxID_OK) {
		*zip_path<<dlg.GetPath();
    }	
}

void ZipDialog::OnTips(wxCommandEvent& event)
{
	wxMessageBox("Tips:\n    This plugin is to unzip the template.zip.", "Help", wxOK, this);
}

void ZipDialog::OnImport(wxCommandEvent& event)
{
	wxMessageBox("Tips:\n    This plugin is to unzip the template.zip.", "Help", wxOK, this);
}

void ZipDialog::OnUnzipAll(wxCommandEvent& event)
{
	wxMessageBox("Tips:\n    This plugin is to unzip the template.zip.", "Help", wxOK, this);
}

