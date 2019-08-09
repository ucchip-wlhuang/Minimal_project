#include "globals.h"

enum
{
	ID_ZipPath = 2000,
	ID_ChooseBtn,
	ID_UnzipAll,
	ID_Unzip,
	ID_Help
};

class ZipDialog : public wxDialog
{
public:
	ZipDialog(wxWindow *parent);
	~ZipDialog();
	void OnShowChoice(wxCommandEvent& event);
	void OnTips(wxCommandEvent& event);
	void OnImport(wxCommandEvent& event);
	void OnUnzipAll(wxCommandEvent& event);
private:
	wxTextCtrl* zip_path;
	wxButton* btn_choose;
	wxButton* btn_ok;
	wxButton* btn_all;
	wxButton* btn_help;
};