#include <fstream>
#include <iostream>
#include <sstream>
#include <string>


int main(int argc, char* argv[] ){

int arg_num;
std::string csv_buffer;
std::string filename_buffer;
std::ofstream file_handle;

if( argc == 2){

  std::istringstream arg_v(argv[1]);
  arg_v >> arg_num;
  std::cout << arg_num << std::endl;

  //string usr_string;

  //cout << "Enter a string: ";

  //getline(cin,usr_string); // gets string entered before user hits return

  //ofstream usr_text("drinks.csv", ios::out ); 

  //if(usr_text.good()) // make sure file was created ok
  //{
    //usr_text << usr_string << endl; // write string to file with linefeed
 
  //}else{

    // cout<<"Could not create file..."<<endl;
  //}
}else{

 std::cout << "Usage: csv 'num' : where 'num' is" << std::endl;
 std::cout << "           the number of records you desire." << std::endl;

}
return 0;
}
