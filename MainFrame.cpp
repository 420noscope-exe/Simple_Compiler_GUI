#include "MainFrame.h"
#include <wx/wx.h>
#include <wx/spinctrl.h>
#include <iostream>

enum IDs{
    FOLDER_PATH_CTRL_ID = 2,
    LINKER_FLAGS_CTRL_ID = 3,
    SCAN_FOLDER_BUTTON_ID = 4,
    FILE_LIST_BOX_ID = 5,
    OPTIMIZATION_LEVEL_RADIO_BOX_ID = 6,
    JOBS_SPIN_CTRL_ID = 7,
    OUTPUT_FILE_NAME_CTRL_ID = 8,
    COMPILE_BUTTON_ID = 9,
    RUN_CHECK_BOX = 10
};

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_TEXT(FOLDER_PATH_CTRL_ID, MainFrame::OnFolderPathCtrlChanged)
    EVT_TEXT(LINKER_FLAGS_CTRL_ID, MainFrame::OnLinkerFlagsCtrlChanged)
    EVT_BUTTON(SCAN_FOLDER_BUTTON_ID, MainFrame::OnScanFolderButtonClicked)
    EVT_LISTBOX(FILE_LIST_BOX_ID, MainFrame::OnFileListBoxChanged)
    EVT_RADIOBOX(OPTIMIZATION_LEVEL_RADIO_BOX_ID, MainFrame::OnOptimizationLevelRadioBoxChanged)
    EVT_SPINCTRL(JOBS_SPIN_CTRL_ID, MainFrame::OnJobsSpinCtrlChanged)
    EVT_TEXT(OUTPUT_FILE_NAME_CTRL_ID, MainFrame::OnOutputFileNameCtrlChanged)
    EVT_BUTTON(COMPILE_BUTTON_ID, MainFrame::OnCompileButtonClicked)
    EVT_CHECKBOX(RUN_CHECK_BOX, MainFrame::OnRunCheckBoxClicked)
wxEND_EVENT_TABLE()
    
MainFrame::MainFrame(const wxString& title): wxFrame(nullptr, wxID_ANY, title) {
    wxPanel* panel = new wxPanel(this);
    
    wxStaticText* folderPathStatic = new wxStaticText(panel, wxID_ANY, "Folder Path:", wxPoint(100,50));
    
    wxTextCtrl* folderPathCtrl = new wxTextCtrl(panel, FOLDER_PATH_CTRL_ID, "/path/to/files", wxPoint(200,50), wxSize(550,-1));
    
    wxStaticText* linkerFlagsStatic = new wxStaticText(panel, wxID_ANY, "Linker Flags:", wxPoint(500,100));
    
    wxTextCtrl* linkerFlagsCtrl = new wxTextCtrl(panel, LINKER_FLAGS_CTRL_ID, "-flags", wxPoint(350,150), wxSize(400,-1));
    
    wxButton* scanFolderButton = new wxButton(panel, SCAN_FOLDER_BUTTON_ID, "Scan Folder", wxPoint(100,100), wxSize(100, 35), wxBU_LEFT);
    
    wxArrayString choices;
    choices.Add("Selct an Item");
    choices.Add("Item A");
    choices.Add("Item B");
    choices.Add("Item C");
    
    wxListBox* FileListBox = new wxListBox(panel, FILE_LIST_BOX_ID, wxPoint(100, 150), wxSize(200, 250), choices, wxLB_MULTIPLE);
    
    wxStaticText* optimizationLevelStatic = new wxStaticText(panel, wxID_ANY, "Optimization Level:", wxPoint(500,200));
    
    wxArrayString optimizationLevelChoices;
    optimizationLevelChoices.Add("none");
    optimizationLevelChoices.Add("-O1");
    optimizationLevelChoices.Add("-O2");
    optimizationLevelChoices.Add("-O3");
    
    wxRadioBox* optimizationLevelRadioBox = new wxRadioBox(panel, OPTIMIZATION_LEVEL_RADIO_BOX_ID, "", wxPoint(450,225), wxDefaultSize, optimizationLevelChoices);
    
    wxStaticText* jobsStatic = new wxStaticText(panel, wxID_ANY, "Jobs:", wxPoint(500,300));
    
    wxSpinCtrl* jobsSpinCtrl = new wxSpinCtrl(panel, JOBS_SPIN_CTRL_ID, "1", wxPoint(550, 300), wxSize(120, -1), wxSP_ARROW_KEYS, 1);
    
    wxStaticText* outputFileNameStatic = new wxStaticText(panel, wxID_ANY, "Output File Name:", wxPoint(100,450));
    
    wxTextCtrl* outputFileNameCtrl = new wxTextCtrl(panel, OUTPUT_FILE_NAME_CTRL_ID, "a.out", wxPoint(250,450), wxSize(450,-1));
    
    wxButton* compileButton = new wxButton(panel, COMPILE_BUTTON_ID, "Compile", wxPoint(300,500), wxSize(100, 35));
    
    CreateStatusBar();
    
    wxCheckBox* runCheckBox = new wxCheckBox(panel, RUN_CHECK_BOX, "Run after compile?", wxPoint(400,505));
    
    wxTextCtrl* outputText = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(100,550), wxSize(600,200), wxTE_MULTILINE | wxHSCROLL);
    
    //FileListBox->Select(0);
    
    
    /*wxButton* button = new wxButton(panel, wxID_ANY, "button", wxPoint(150,50), wxSize(100, 35), wxBU_LEFT);
    
    wxCheckBox* checkbox = new wxCheckBox(panel, wxID_ANY, "CheckBox", wxPoint(550,55));
    
    wxStaticText* staticText = new wxStaticText(panel, wxID_ANY, "Static Text", wxPoint(120,150));
    
    wxTextCtrl* textCtrl = new wxTextCtrl(panel, wxID_ANY, "editable text", wxPoint(500,145), wxSize(200,-1));
    
    wxSlider* slider = new wxSlider(panel, wxID_ANY, 25, 0, 100, wxPoint(100,250), wxSize(200, -1));
    
    wxGauge* gauge = new wxGauge(panel, wxID_ANY, 100, wxPoint(500, 255), wxSize(200, -1));
    gauge->SetValue(50);
    
    wxArrayString choices;
    choices.Add("Selct an Item");
    choices.Add("Item A");
    choices.Add("Item B");
    choices.Add("Item C");
    
    wxChoice* choice = new wxChoice(panel, wxID_ANY, wxPoint(150, 375), wxSize(200, -1), choices);
    choice->Select(0);
    
    wxSpinCtrl* spinCtrl = new wxSpinCtrl(panel, wxID_ANY, "", wxPoint(550, 375), wxSize(120, -1));
    
    wxListBox* listBox = new wxListBox(panel, wxID_ANY, wxPoint(150, 475), wxSize(100,-1), choices);
    listBox->Select(0);
    
    wxRadioBox* radioBox = new wxRadioBox(panel, wxID_ANY, "Radio Box", wxPoint(475,475), wxDefaultSize, choices);*/
}

void MainFrame::OnFolderPathCtrlChanged(wxCommandEvent& evt){
    wxString str = wxString::Format("Folder path changed to %s", evt.GetString());
    std::cout << str << std::endl;
    wxLogStatus(str);
}

void MainFrame::OnLinkerFlagsCtrlChanged(wxCommandEvent& evt){
    wxString str = wxString::Format("Linker flags changed to %s", evt.GetString());
    std::cout << str << std::endl;
    wxLogStatus(str);
}

void MainFrame::OnScanFolderButtonClicked(wxCommandEvent& evt){
    std::cout << "Scanned folder at provided path." << std::endl;
    wxLogStatus("Scanned folder at provided path.");
}

void MainFrame::OnFileListBoxChanged(wxCommandEvent& evt){
    std::cout << "Selected files changed." << std::endl;
    wxLogStatus("Selected files changed.");
}

void MainFrame::OnOptimizationLevelRadioBoxChanged(wxCommandEvent& evt){
    wxString str = wxString::Format("Optimization level changed to %d", evt.GetSelection());
    std::cout << str << std::endl;
    wxLogStatus(str);
}

void MainFrame::OnJobsSpinCtrlChanged(wxSpinEvent& evt){
    wxString str = wxString::Format("Number of jobs changed to %d", evt.GetSelection());
    std::cout << str << std::endl;
    wxLogStatus(str);
}

void MainFrame::OnOutputFileNameCtrlChanged(wxCommandEvent& evt){
    wxString str = wxString::Format("Output file name changed to %s", evt.GetString());
    std::cout << str << std::endl;
    wxLogStatus(str);
}

void MainFrame::OnCompileButtonClicked(wxCommandEvent& evt){
    std::cout << "Compile button clicked." << std::endl;
    wxLogStatus("Compile button clicked.");
}

void MainFrame::OnRunCheckBoxClicked(wxCommandEvent& evt){
    wxString str = wxString::Format("Run after compile was changed to %s", evt.IsChecked() ? "true" : "false");
    std::cout << str << std::endl;
    wxLogStatus(str);
}
