
#include "NewText.h"

NewText::NewText(wxAuiNotebook *parent)
		:wxTextCtrl(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, parent->GetSize(), wxTE_MULTILINE | wxTE_PROCESS_TAB)
{
	
}