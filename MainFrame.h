#include <wx/wx.h>
#include <string>

using namespace std;

class MainFrame : public wxFrame
{
public:
    MainFrame(const wxString& title);
    
private:
    wxString folderPath;
    wxString linkerFlags;
    wxArrayString scannedFiles;
    wxArrayString inFiles;
    wxString outFile;
    int optimizationLevel;
    wxListBox* FileListBox;
    void OnFolderPathCtrlChanged(wxCommandEvent& evt);
    void OnLinkerFlagsCtrlChanged(wxCommandEvent& evt);
    void OnScanFolderButtonClicked(wxCommandEvent& evt);
    void OnFileListBoxChanged(wxCommandEvent& evt);
    void OnOptimizationLevelRadioBoxChanged(wxCommandEvent& evt);
    void OnJobsSpinCtrlChanged(wxSpinEvent& evt);
    void OnOutputFileNameCtrlChanged(wxCommandEvent& evt);
    void OnCompileButtonClicked(wxCommandEvent& evt);
    void OnRunCheckBoxClicked(wxCommandEvent& evt);
    wxArrayString convertVectorTowxArrayString(vector<string>& inVector);
    wxDECLARE_EVENT_TABLE();
};
