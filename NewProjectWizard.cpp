#include "NewProjectWizard.h"

NewProjectWizard::NewProjectWizard(wxFrame* frame)
{
	Create(frame, wxID_ANY, "New Project Wizard", wxNullBitmap, wxDefaultPosition,
                   wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER);
	first_page = new TemplatePage(this);
	InfoPage* second_page = new InfoPage(this);
	SetupPage* third_page = new SetupPage(this);
	second_page->Chain(third_page);
	first_page->Chain(second_page);
}

TemplatePage::TemplatePage(wxWizard *parent) : wxWizardPageSimple(parent)
{
	wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
	wxBannerWindow* title = new wxBannerWindow(this, wxTOP);
	title->SetBitmap(wxNullBitmap);
	title->SetText(_("New Project"), _("Select the project template from the list below"));
	title->SetGradient(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE), wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));
	title->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOWTEXT));
	sizer->Add(title, wxSizerFlags().Expand());
	SetSizerAndFit(sizer);
}

InfoPage::InfoPage(wxWizard *parent) : wxWizardPageSimple(parent)
{
	wxString Path("C:\\Z");
	wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
	//wxBoxSizer* nameline = new wxBoxSizer(wxHORIZONTAL);
	
	
	wxBannerWindow* title = new wxBannerWindow(this, wxTOP);
	title->SetBitmap(wxNullBitmap);
	title->SetText(_("New Project"), _("Set the project and name"));
	title->SetGradient(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE), wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));
	title->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOWTEXT));
	
	wxFlexGridSizer* flexsizer = new wxFlexGridSizer(0, 2, 0, 0);
	flexsizer->SetFlexibleDirection(wxBOTH);
	flexsizer->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);
	flexsizer->AddGrowableCol(1);
	wxStaticText* name_title = new wxStaticText(this, wxID_ANY, "Project Name:");
	wxStaticText* path_title = new wxStaticText(this, wxID_ANY, "Project Path:");
	wxTextCtrl* project_name = new wxTextCtrl(this, ID_ProjectName, wxEmptyString, wxDefaultPosition, wxDefaultSize);
	wxTextCtrl* project_path = new wxTextCtrl(this, ID_ProjectPath, Path, wxDefaultPosition, wxDefaultSize);
	wxButton* choosepath = new wxButton(this, ID_ChoosePath, "...", wxDefaultPosition, wxSize(30,-1));
	flexsizer->Add(name_title, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, wxBorder(5));
	flexsizer->Add(project_name, 0, wxLEFT|wxTOP|wxBOTTOM|wxEXPAND, wxBorder(5));
	flexsizer->Add(path_title, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, wxBorder(5));
	wxBoxSizer* pathline = new wxBoxSizer(wxHORIZONTAL);
	pathline->Add(project_path, 0, wxLEFT|wxTOP|wxBOTTOM|wxEXPAND, wxBorder(5));
	pathline->Add(choosepath, 0, wxLEFT|wxTOP|wxBOTTOM, wxBorder(5));
	flexsizer->Add(pathline, wxSizerFlags(0).Expand());
	
	
	
	sizer->Add(title, wxSizerFlags().Expand());
	//nameline->Add(name_title);
	//nameline->Add(project_name, wxSizerFlags(0).Expand());
	//pathline->Add(path_title);
	//pathline->Add(project_path, wxSizerFlags(0).Expand());
	//pathline->Add(choosepath, wxSizerFlags(0));
	sizer->Add(flexsizer, wxSizerFlags(0).Expand());
	//sizer->Add(pathline);
	SetSizerAndFit(sizer);
}

SetupPage::SetupPage(wxWizard *parent) : wxWizardPageSimple(parent)
{
	wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
	wxBannerWindow* title = new wxBannerWindow(this, wxTOP);
	title->SetBitmap(wxNullBitmap);
	title->SetText(_("New Project"), _("Select the project toolchain"));
	title->SetGradient(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE), wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));
	title->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOWTEXT));
	sizer->Add(title, wxSizerFlags().Expand());
	SetSizerAndFit(sizer);
}
