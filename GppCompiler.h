#include <wx/wx.h>
#include <string>

using namespace std;

class GppCompiler {
public:
    // Default constructor with no arguments
    GppCompiler();

    // Destructor
    ~GppCompiler();

    // Method to compile the code with G++, taking linker flags as a parameter
    void runGpp(const wxString& folderPath, const wxArrayString& sourceFiles, const wxString& outputFile,
                const wxString& flags, const int& optimizationLevel);

private:
    // No private member variables are needed
    wxString optimizationLevelToString(const int& ol);
};
