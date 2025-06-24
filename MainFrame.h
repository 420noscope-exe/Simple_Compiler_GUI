#include <wx/wx.h>

class MainFrame : public wxFrame
{
public:
    MainFrame(const wxString& title);
    
private:
    void OnFolderPathCtrlChanged(wxCommandEvent& evt);
    void OnLinkerFlagsCtrlChanged(wxCommandEvent& evt);
    void OnScanFolderButtonClicked(wxCommandEvent& evt);
    void OnFileListBoxChanged(wxCommandEvent& evt);
    void OnOptimizationLevelRadioBoxChanged(wxCommandEvent& evt);
    void OnJobsSpinCtrlChanged(wxSpinEvent& evt);
    void OnOutputFileNameCtrlChanged(wxCommandEvent& evt);
    void OnCompileButtonClicked(wxCommandEvent& evt);
    void OnRunCheckBoxClicked(wxCommandEvent& evt);
    wxDECLARE_EVENT_TABLE();
};
