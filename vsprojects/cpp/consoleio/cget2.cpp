/* How to get output of wget into variable
   with popen() */

#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <string>



int main() {
    
    char buffer[128];

    std::string result = "";

    FILE* pipe = popen("wget -q -O - http://localhost:47800/api/v1/bacnet/devices/1000/objects/0.26", "r");
    
    if (!pipe) throw std::runtime_error("popen() failed!");
    
    try {
        while (fgets(buffer, sizeof buffer, pipe) != NULL) {
            result += buffer;
        }
    } catch (...) {
        pclose(pipe);
        throw;
    }

   std::cout<<result;

    pclose(pipe);

    return 0;
}/* C++ methods for file input and output */


