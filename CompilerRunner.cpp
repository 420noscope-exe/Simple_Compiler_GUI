#include <CompilerRunner.h>
#include <string>

using namespace std;

CompilerRunner::CompilerRunner(){
private:
    string folderPath = "";
    string linkerFlags = "";
    string outputFileName = "";
    string optimizationLevel = "";
    string jobs = "";
    string selectedFiles = "";
}

void CompilerRunner::setFolderPath(string fp){
    folderPath = fp;
}

void CompilerRunner::setLinkerFlags(string lf){
    linkerFlags = lf;   
   }
    
void CompilerRunner::setOutputFileName(string ofn){
    outputFileName = ofn;
}
    
void CompilerRunner::setOptimizationLevel(int ol){
    switch(ol) {
        case 0:
            optimizationLevel = "";
            break;
        case 1:
            optimizationLevel = "-O1";
            break;
        case 2;
            optimizationLevel = "-O2";
            break;
        case 3;
            optimizationLevel = "-O3";
            break;
    }
        
}

void CompilerRunner::setJobs(int j){
    if (j > 1){
        jobs = "-j " + to_string(j);
    }
    else
    {
    jobs = "";
    }
}


