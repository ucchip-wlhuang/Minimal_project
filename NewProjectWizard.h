#include "globals.h"
#include "dvtemplatesmodel.h"
#include <wx/wizard.h>

enum
{
	ID_ProjectName = 2000,
	ID_ProjectPath,
	ID_ChoosePath
};

class NewProjectWizard : public wxWizard
{
public:
	NewProjectWizard(wxFrame* frame);
	wxWizardPage* GetFirstPage(){
		return first_page;
	}
private:
	wxWizardPageSimple* first_page;
	//wxObjectDataPtr<DVTemplatesModel> dv_templatesModel;
};

class TemplatePage : public wxWizardPageSimple
{
public:
	TemplatePage(wxWizard *parent);
private:
	wxObjectDataPtr<DVTemplatesModel> dv_templatesModel;
};

class InfoPage : public wxWizardPageSimple
{
public:
	InfoPage(wxWizard *parent);
};

class SetupPage : public wxWizardPageSimple
{
public:
	SetupPage(wxWizard *parent);
};

//wxBEGIN_EVENT_TABLE(NewProjectWizard, wxWizard)
//wxEND_EVENT_TABLE()