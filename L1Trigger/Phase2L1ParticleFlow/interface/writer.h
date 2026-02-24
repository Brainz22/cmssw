#ifndef WRITER_H
#define WRITER_H

#include <fstream> // Required for std::ifstream
#include <iostream> // Required for std::cout
#include <cstdlib> // For getenv
#include <string>  // For std::string
#include <iostream> // For output
#include <cmath>
#include <vector>
#include <filesystem> // Required for std::filesystem
#include "ap_fixed.h"

class Writer{
    public:
        //constructor
        Writer();

        //member functions
        bool fileExists(const std::string& fileName);
        std::string getEnvironmentVariable(const std::string& varName);
        void write(const std::vector<float>& array, ap_fixed<14,8,AP_TRN,AP_SAT,0> score);
        //void write(ap_fixed<12,6,AP_TRN,AP_SAT,0>* array, ap_fixed<14,8,AP_TRN,AP_SAT,0> score);

};

#endif // WRITER_H