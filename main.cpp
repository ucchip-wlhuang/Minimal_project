
#include "mainframe.h"

wxAuiNotebook* MyFrame::CreateNote()
{
    GetClientSize(&client_w, &client_h);
    wxAuiNotebook* right_win_un = new wxAuiNotebook(this, wxID_ANY, wxDefaultPosition, wxSize(client_w, client_h), wxAUI_NB_CLOSE_ON_ALL_TABS | wxAUI_NB_WINDOWLIST_BUTTON);
	right_win_un->SetArtProvider(new wxAuiSimpleTabArt());
    return right_win_un;
}


// ============================================================================
// implementation
// ============================================================================

// ----------------------------------------------------------------------------
// the application class
// ----------------------------------------------------------------------------

bool MyApp::OnInit()
{
    if ( !wxApp::OnInit() )
        return false;

    MyFrame *frame = new MyFrame(wxT("Minimal wxWidgets App"), wxSize(660, 450));
    frame->Show(true);
    
    return true;
}

// ----------------------------------------------------------------------------
// main frame
// ----------------------------------------------------------------------------

// frame constructor
MyFrame::MyFrame(const wxString& title, const wxSize &size, const wxPoint &pos)
       : wxFrame(NULL, wxID_ANY, title, pos, size, wxDEFAULT_FRAME_STYLE)
{
    // set the frame icon
    wxIcon mainicon;
    mainicon.LoadFile("../sample.ico",wxBITMAP_TYPE_ICO);
    SetIcon(mainicon);
/*    wxIcon mainicon = wxICON(aaa);
    if(mainicon.IsOk() == true)
    {
        wxMessageBox("Success", "again", wxOK,this);
    }
    else
    {
        wxMessageBox("Failed","again",wxOK,this);
    }
    SetIcon(mainicon); */
      
    this->SetMinSize(wxSize(200,150));

#if wxUSE_MENUS
    wxMenu *fileMenu = new wxMenu;
    wxMenu *helpMenu = new wxMenu;
    wxMenu *editMenu = new wxMenu;
    wxMenu *viewMenu = new wxMenu;
    wxMenu *wizardMenu = new wxMenu;
	
    wxMenu *newFile = new wxMenu;
    //tree constuction
    helpMenu->Append(Minimal_About, wxT("Ab&out\tF1"), "Show about dialog");
    fileMenu->Append(Minimal_New, "New", newFile);                    //unit as menu,1:1
    newFile->Append(Minimal_New, "New Empty File\tCtrl-N", "Create new empty file");
    newFile->AppendSeparator();
    newFile->Append(Minimal_Workspace, "New Workspace", "Create new workspace");
    fileMenu->Append(Minimal_Quit, "Exit\tAlt-X", "Quit this program");
    editMenu->Append(Minimal_Undo, "Undo\tCtrl-A", "Edit the Frame");
    viewMenu->Append(Minimal_WordWrap, "Word Wrap", "I don't know");
    viewMenu->AppendSeparator();
    viewMenu->AppendCheckItem(Minimal_Output, "Output Pane", "I don't know");
    viewMenu->AppendCheckItem(Minimal_Debugger, "Debugger Pane", "I don't know");
    viewMenu->AppendSeparator();
    viewMenu->AppendRadioItem(Minimal_White, "White", "I don't know");
    viewMenu->AppendRadioItem(Minimal_Black, "Black", "I don't know");
	
	wizardMenu->Append(Minimal_Newproject, "New Project\tAlt-P", "New Project Wizard");
    
    // now append the freshly created menu to the menu bar...
    wxMenuBar *menuBar = new wxMenuBar();
    menuBar->Append(fileMenu, "File");
    menuBar->Append(editMenu, "Edit");
    menuBar->Append(viewMenu, "View");
	menuBar->Append(wizardMenu, "Wizard");
    menuBar->Append(helpMenu, "Help");

    // ... and attach this menu bar to the frame
    SetMenuBar(menuBar);
#else // !wxUSE_MENUS
    // If menus are not available add a button to access the about box
    wxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
    wxButton* aboutBtn = new wxButton(this, wxID_ANY, "About...");
    aboutBtn->Bind(wxEVT_BUTTON, &MyFrame::OnAbout, this);
    sizer->Add(aboutBtn, wxSizerFlags().Center());
#endif // wxUSE_MENUS/!wxUSE_MENUS

#if wxUSE_STATUSBAR
    // create a status bar just for fun (by default with 1 pane only)
    CreateStatusBar(1);
    SetStatusText("Welcome to wxWidgets!");
#endif // wxUSE_STATUSBAR

#if wxUSE_TOOLBAR
    wxToolBar* toolBar = new wxToolBar(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_HORIZONTAL);
    wxBitmap bmpOpen(open_xpm);
    wxBitmap bmpSave(save_xpm);
    wxBitmap bmpNew(new_xpm);
    toolBar->AddTool(Minimal_New, wxT("New"), bmpNew, wxT("Toggle button 0"), wxITEM_NORMAL);
    toolBar->AddTool(Minimal_About, wxT("Open"), bmpOpen, wxT("Toggle button 1"), wxITEM_NORMAL);
    toolBar->AddSeparator();
    toolBar->AddTool(wxID_SAVE, wxT("Save"), bmpSave, wxT("Toggle button 2"), wxITEM_CHECK);
    toolBar->Realize();
    this->SetToolBar(toolBar);
#endif

    //layout
//    wxPanel *panel = new wxPanel(this, wxID_ANY);
  
    wxBoxSizer* ver_sizer = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* hor_sizer = new wxBoxSizer(wxHORIZONTAL);
    
    page_bmp = wxArtProvider::GetBitmap(wxART_NORMAL_FILE, wxART_OTHER, FromDIP(wxSize(16,16)));   

    wxAuiNotebook* left_note = new wxAuiNotebook(this, wxID_ANY, wxDefaultPosition, wxSize(180, -1), wxAUI_NB_WINDOWLIST_BUTTON);
    wxPanel* left_win1 = new wxPanel(left_note, wxID_ANY);
    wxPanel* left_win2 = new wxPanel(left_note, wxID_ANY);
    wxPanel* left_win3 = new wxPanel(left_note, wxID_ANY);
    left_note->AddPage(left_win1, wxT("Workspace"), true, 0);
    left_note->AddPage(left_win2, wxT("Explorer"), false, 1);
    left_note->AddPage(left_win3, wxT("Textand"), false, 1);
    
    wxNotebook* bottom_note = new wxNotebook(this, wxID_ANY, wxDefaultPosition, wxSize(-1, 200));
    wxPanel* bottom_win1 = new wxPanel(bottom_note, wxID_ANY);
    wxPanel* bottom_win2 = new wxPanel(bottom_note, wxID_ANY);
    wxPanel* bottom_win3 = new wxPanel(bottom_note, wxID_ANY);
    bottom_note->AddPage(bottom_win1, wxT("Tail"), true, 0);
    bottom_note->AddPage(bottom_win2, wxT("Build"), false, 1);
    bottom_note->AddPage(bottom_win3, wxT("Search"), false, 2);
    /*
    wxToolBar* toolBar1 = new wxToolBar(bottom_win1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_VERTICAL);
    toolBar1->AddTool(Minimal_About, wxT("Open"), bmpOpen, wxT("Toggle button 1"), wxITEM_NORMAL);
    toolBar1->Realize();
    this->SetToolBar(toolBar1);
	*/
    
    right_win_un = CreateNote();
	
	hor_sizer->Add(left_note, wxSizerFlags(0).Expand());
    hor_sizer->Add(right_win_un, wxSizerFlags(1).Expand());
	ver_sizer->Add(hor_sizer, wxSizerFlags(1).Expand());
    ver_sizer->Add(bottom_note, wxSizerFlags(0).Expand());
	
    SetSizerAndFit(ver_sizer);
	
}


/*text
MyText :: MyText(wxWindow *parent, const wxPoint &pos, const wxSize &size, long style)
        : wxTextCtrl(NULL, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0)
{
}
*/


// event handlers
void MyFrame::OnQuit(wxCommandEvent& WXUNUSED(event))
{
    // true is to force the frame to close
    Close(true);
}

void MyFrame::OnAbout(wxCommandEvent& WXUNUSED(event))
{
    //Content,Titile,sign determine number and type of button,Class
    wxMessageBox(wxString::Format
                 (
                    "Welcome to %s!\n"
                    "\n"
                    "This is the minimal wxWidgets sample\n"
                    "running under %s.",
                    wxVERSION_STRING,
                    wxGetOsDescription()
                 ),
                 "About wxWidgets minimal sample",
                 wxOK | wxICON_EXCLAMATION,         //to change style of icon
                 this);
}

void MyFrame::OnUndo(wxCommandEvent& WXUNUSED(event))
{
    if(wxMessageBox("Undo Success","Undo status",wxOK | wxCANCEL,this)==wxOK)
    {
        wxMessageBox("Success", "again", wxOK,this);      //screen print:wxCANCEL will autoadd wxOK
    }
}

void MyFrame::OnNew(wxCommandEvent& WXUNUSED(event))
{
    static int i = 0;
    char str[18];
    sprintf(str, "Untitled%d", ++i);
    wxString wxstr(str);
	wxTextCtrl* newText = new NewText(right_win_un);
    right_win_un->AddPage(newText, wxstr, true, page_bmp);
}

void MyFrame::OnNewProjectWizard(wxCommandEvent& WXUNUSED(event))
{
	NewProjectWizard wiz(this);
	wiz.RunWizard(wiz.GetFirstPage());
}
