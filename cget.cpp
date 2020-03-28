/* C++ methods for file input and output */
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream out_file;
    ifstream in_file;
    string line;

    out_file.open("beef.txt", ios_base::trunc);
    if (out_file.is_open())
    {
        out_file << "beef" << endl;
        out_file.close();
    }

    in_file.open("beef.txt");
    if (in_file.is_open())
    {
        getline(in_file, line);
        in_file.close();

        cout << "File contains:" << endl;
        cout << line << endl;
    }

    cout << "Enter what you would like to be contained in the file" << endl;
    getline(cin, line);

    out_file.open("beef.txt", ios_base::trunc);
    if (out_file.is_open())
    {
        out_file << line << endl;
        out_file.close();
    } 

    in_file.open("beef.txt");
    if (in_file.is_open())
    {
        getline(in_file, line);
        in_file.close();

        cout << "File now contains:" << endl;
        cout << line << endl;
    }

    return 0;
}
