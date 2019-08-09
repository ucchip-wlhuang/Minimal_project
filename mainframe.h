
#include "globals.h"
#include "NewText.h"
#include "NewProjectWizard.h"
#include "ZipDialog.h"

class MyApp : public wxApp
{
public:
    virtual bool OnInit() wxOVERRIDE;   //override virtual interface on base function
};

class MyFrame : public wxFrame
{
public:
    MyFrame(const wxString& title, const wxSize &size = wxDefaultSize, const wxPoint &pos = wxDefaultPosition);     //constructed function   wxSize(770,650)
    wxAuiNotebook* CreateNote();
    wxAuiNotebook* right_win_un;
    // event handlers (these functions should _not_ be virtual)
    void OnQuit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnUndo(wxCommandEvent& event);
    void OnNew(wxCommandEvent& event);
	void OnNewProjectWizard(wxCommandEvent& event);
	void OnOpenWorkspace(wxCommandEvent& event);
	void OnRmFile(wxCommandEvent& event);
	void OnUpdatemenu(wxUpdateUIEvent& event);
    

private:
    wxBitmap page_bmp;
    int client_w, client_h;
    // event table
    wxDECLARE_EVENT_TABLE();
	wxMenu *fileMenu = new wxMenu;
    wxMenu *helpMenu = new wxMenu;
    wxMenu *editMenu = new wxMenu;
    wxMenu *viewMenu = new wxMenu;
    wxMenu *wizardMenu = new wxMenu;
	
    wxMenu *newFile = new wxMenu;
};

// ----------------------------------------------------------------------------
// constants
// ----------------------------------------------------------------------------

// IDs for the controls and the menu commands
//IDs can be defined fr eely, by enum auto save different numbers
enum
{
    Minimal_Quit = 200,
    Minimal_About,
    Minimal_Undo,
    Minimal_WordWrap,
    Minimal_EmpFile,
    Minimal_Workspace, 
    Minimal_New,
    Minimal_Output,
    Minimal_Debugger,
    Minimal_White,
    Minimal_Black,
	Minimal_Newproject,
	Minimal_RmFile
};

// ----------------------------------------------------------------------------
// event tables and other macros for wxWidgets
// ----------------------------------------------------------------------------
//这个macro目的是将事件标识与事件处理绑定,以标识所在单位进行绑定，发生重复标识的情况，后续不会更改绑定事件
wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_MENU(Minimal_New,  MyFrame::OnNew)
    EVT_MENU(Minimal_Quit,  MyFrame::OnQuit)
    EVT_MENU(Minimal_About, MyFrame::OnAbout)
    EVT_MENU(Minimal_Undo, MyFrame::OnUndo)
	EVT_MENU(Minimal_Newproject, MyFrame::OnNewProjectWizard)
	EVT_MENU(Minimal_Workspace, MyFrame::OnOpenWorkspace)
	EVT_MENU(Minimal_RmFile, MyFrame::OnRmFile)
	EVT_UPDATE_UI(Minimal_WordWrap, MyFrame::OnUpdatemenu)
wxEND_EVENT_TABLE()

wxIMPLEMENT_APP(MyApp);     //implement app