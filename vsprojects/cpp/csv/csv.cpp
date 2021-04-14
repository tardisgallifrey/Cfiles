#include <fstream>
#include <iostream>
#include <sstream>
#include <string>


int main(int argc, char* argv[] )
{

     int arg_num;
     std::string csv_buffer;
     std::string filename_buffer;
     std::ofstream usr_text;

     if( argc == 2)
     {
            //get command line arg (only 1)
            std::istringstream arg_v(argv[1]);

            //convert to number??
            arg_v >> arg_num;

            //print it out
            std::cout << arg_num << std::endl;

            //Ask the user for a name??
            std::string usr_string;
            std::cout << "Enter a string: ";
            
            getline(std::cin,usr_string); // gets string entered before user hits return
            
            //open the file for writing
            usr_text.open("drinks.csv", std::ofstream::out | std::ofstream::app ); 

            //if user string is 'good', then proceed
            if(usr_text.good())
            {
                 usr_text << usr_string << std::endl; // write string to file with linefeed
            }
            else
            {
                 std::cout<<"Could not create file..."<< std::endl;
            }

    }
    else
    {

        std::cout << "Usage: csv 'num' : where 'num' is" << std::endl;
        std::cout << "           the number of records you desire." << std::endl;

    }

return 0;
}
