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
	
	wxDataViewCtrl* dv_templates = new wxDataViewCtrl(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxDV_ROW_LINES|wxDV_SINGLE);
	dv_templates->SetFocus();
	dv_templates->AppendIconTextColumn(_("Template"), dv_templates->GetColumnCount(), wxDATAVIEW_CELL_INERT, 450, wxALIGN_LEFT, wxDATAVIEW_COL_RESIZABLE);
	dv_templatesModel = new DVTemplatesModel;   //create new class base on wxDataViewModel
	dv_templates->AssociateModel(dv_templatesModel.get());  //dv_templatesModel.gets()
	
	sizer->Add(title, wxSizerFlags().Expand());
	sizer->Add(dv_templates, 1, wxALL|wxEXPAND, wxBorder(5));
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
	wxStaticText* name_title = new wxStaticText(this, wxID_ANY, "Project Name: ");
	wxStaticText* path_title = new wxStaticText(this, wxID_ANY, "Project Path: ");
	wxTextCtrl* project_name = new wxTextCtrl(this, ID_ProjectName, wxEmptyString, wxDefaultPosition, wxDefaultSize);
	wxTextCtrl* project_path = new wxTextCtrl(this, ID_ProjectPath, Path, wxDefaultPosition, wxDefaultSize);
	wxButton* choosepath = new wxButton(this, ID_ChoosePath, "...", wxDefaultPosition, wxSize(30,-1));
	flexsizer->Add(name_title, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, wxBorder(5));
	flexsizer->Add(project_name, 0, wxLEFT|wxTOP|wxBOTTOM|wxEXPAND, wxBorder(5));
	flexsizer->Add(path_title, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, wxBorder(5));
	wxBoxSizer* pathline = new wxBoxSizer(wxHORIZONTAL);
	pathline->Add(project_path, 1, wxLEFT|wxTOP|wxBOTTOM|wxEXPAND, wxBorder(5));
	pathline->Add(choosepath, 0, wxLEFT|wxTOP|wxBOTTOM, wxBorder(5));
	flexsizer->Add(pathline, wxSizerFlags(0).Expand());
	
	sizer->Add(title, wxSizerFlags().Expand());
	sizer->Add(flexsizer, wxSizerFlags(0).Expand());
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
	
	
	wxFlexGridSizer* flexsizer = new wxFlexGridSizer(0, 2, 0, 0);
	flexsizer->SetFlexibleDirection(wxBOTH);
	flexsizer->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);
	flexsizer->AddGrowableCol(1);
	wxStaticText* compiler_title = new wxStaticText(this, wxID_ANY, "Compiler: ");
	wxStaticText* debugger_title = new wxStaticText(this, wxID_ANY, "Debugger: ");
	wxStaticText* buildsystem_title = new wxStaticText(this, wxID_ANY, "Build System: ");
	wxArrayString CompilerArr;
	CompilerArr.Add("Hello");
	CompilerArr.Add("World");
	wxArrayString DebuggerArr;
	wxArrayString BuildSystemArr;
	wxChoice* compiler_choice = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, CompilerArr);
	wxChoice* debugger_choice = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, DebuggerArr);
	wxChoice* buildsystem_choice = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, BuildSystemArr);
	flexsizer->Add(compiler_title, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, wxBorder(5));
	flexsizer->Add(compiler_choice, 0, wxLEFT|wxTOP|wxBOTTOM|wxEXPAND, wxBorder(5));
	flexsizer->Add(debugger_title, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, wxBorder(5));
	flexsizer->Add(debugger_choice, 0, wxLEFT|wxTOP|wxBOTTOM|wxEXPAND, wxBorder(5));
	flexsizer->Add(buildsystem_title, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, wxBorder(5));
	flexsizer->Add(buildsystem_choice, 0, wxLEFT|wxTOP|wxBOTTOM|wxEXPAND, wxBorder(5));

	sizer->Add(title, wxSizerFlags().Expand());
	sizer->Add(flexsizer, wxSizerFlags(0).Expand());
	SetSizerAndFit(sizer);
}
