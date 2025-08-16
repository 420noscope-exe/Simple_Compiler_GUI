#include "GppCompiler.h"
#include <cstdlib>  // For system() function
#include <wx/wx.h>
#include <string>

using namespace std;

// Constructor implementation
GppCompiler::GppCompiler() = default;

// Destructor implementation
GppCompiler::~GppCompiler() = default;

// Method implementation to compile the code
void GppCompiler::runGpp(const wxArrayString& sourceFiles, const wxString& outputFile,
                         const wxString& flags, const int& optimizationLevel) {
    wxString command = "g++ ";  //The g++ command.
    
    command += optimizationLevelToString(optimizationLevel);  //Calls the ToString
    
    wxString sourceFilesString = "";
    
    for (const wxString& file : sourceFiles)
    {
        sourceFilesString += file + " ";
    }
    
    // Add source file
    command += sourceFilesString;
    
    // Add output option and file
    command += "-o " + outputFile;
    
    if (!flags.empty()) {
        // Append linker flags after the -o option
        command += " " + flags;
    }
    
    // Execute the compilation command
    std::cout << command << std::endl;
    system(command.c_str());
}

wxString GppCompiler::optimizationLevelToString(const int& ol) {  //takes in an int from the radioButtons in MainFrame.cpp, converts it to an approraite string
    wxString str;
    
    switch(ol) {
        case 0:
            str = "";
            break;
        case 1:
            str = "-O1 ";
            break;
        case 2:
            str = "-O2 ";
            break;
        case 3:
            str = "-O3 ";
            break;
    }
    return str;
}

