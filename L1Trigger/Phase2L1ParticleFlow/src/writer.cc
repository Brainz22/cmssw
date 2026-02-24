//This is a script to write an array into a .txt file and save it under $CMSSW_BASE/src/

#include "L1Trigger/Phase2L1ParticleFlow/interface/writer.h"


// Constructor
Writer::Writer() {
    std::cout << "YESSIR! Writer object created." << std::endl;
}

bool Writer::fileExists(const std::string& fileName) {
    std::ifstream file(fileName);
    return file.good(); // Returns true if the file stream is in a good state (file opened successfully)
}

std::string Writer::getEnvironmentVariable(const std::string& varName) {
    const char* value = std::getenv(varName.c_str());
    if (value != nullptr) {
        return std::string(value);
    } else {
        // Return an empty string or handle the case where the variable is not found
        return ""; 
    }
}


void Writer::write(const std::vector<float>& array, ap_fixed<14,8,AP_TRN,AP_SAT,0> score ) {
//void Writer::write(ap_fixed<12,6,AP_TRN,AP_SAT,0>* array, ap_fixed<14,8,AP_TRN,AP_SAT,0> score ) {

//int main() {
    
    // define paths and check that path has been created

    std::string cmssw_src_path = getEnvironmentVariable("CMSSW_BASE") + "/src/";
    if (!cmssw_src_path.empty()) {
        std::cout << "CMSSW/src PATH: " << cmssw_src_path << std::endl;
    } else {
        std::cout << "CMSSW/src PATH environment variable not found because of wrong environment variable." << std::endl;
    }

    // Check that we are indeed accessing a directory

    // Create a std::filesystem::path object
    std::filesystem::path p(cmssw_src_path);
    
    // Check if the path exists and is a directory
    if (std::filesystem::is_directory(p)) {
        //std::cout << "Directory '" << cmssw_src_path << "' exists." << std::endl;
    } else {
        std::cout << "Directory '" << cmssw_src_path << "' does not exist or is not a directory." << std::endl;
    }


    //work with file
    std::string filePath = cmssw_src_path + "output.txt";
    if (fileExists(filePath)) {
        //std::cout << "File exists: " << filePath << std::endl;

        // append a lines to existing file

        //std::ofstream outputFile("output.txt", std::ios::app);
        std::ofstream outputFile(filePath, std::ios::app);
        if (outputFile.is_open()) {
            //std::cout << "Appending to file..." << std::endl;

            //outputFile << "This line will be appended and the numbers below." << std::endl;
            //for (size_t i = 0; i < array.size(); i++){
            for (size_t i = 0; i < 140; i++){
                        outputFile << array[i]  << ",";  
                 }
            outputFile << score << std::endl;

            outputFile.close();
        }else{

            std::cout << "ERROR: Failed to open file. Issues with the given path." << std::endl;

        }
    }         

     else {
        std::cout << "File does not exist: " << filePath << std::endl;

        std::cout << "Creating file from scratch because it does not exist." << std::endl;

         // 1. Create an ofstream object and open the file "output.txt"
        //std::ofstream outputFile("output.txt");
        std::ofstream outputFile(filePath);

        if (!outputFile.is_open()) {
             std::cout << "ERROR: Failed to open file. Issues with the given path." << std::endl;
        }else{



                // 2. Check if the file was opened successfully

                if (outputFile.is_open()) {
                    // 3. Write data to the file
                    //outputFile << "Hello, world! This is a line of text." << std::endl;
                    //outputFile << "write strings, numbers, and other variables: ";

                    for (size_t i = 0; i < 140; i++){
                        outputFile << array[i]  << ",";  
                 }

                    outputFile << score << std::endl;
                    
                    //outputFile << "Another line of text." << std::endl;

                    // 4. Close the file
                    outputFile.close();

                    //std::cout << "Data has been written to: " << filePath << std::endl;

                }
            }
        
    }

}