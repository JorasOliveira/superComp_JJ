#include <iostream>
#include <string>
#include <fstream> // file stream

using namespace std;

int main(){

    string file_name = "dummy_file.txt";

    ofstream file(file_name); // ofstream is the output file stream

    //is always good practice to check if the file has beem sucessfully opened

    if (file.is_open()){
        cout << "file has been opened" << endl;
    } else {
        cerr << "ERROR while atempting to open file" << endl;
        return 1;
    }

    file << "this is a dummy file" << endl;
    file << "it contains nothing of importance" << endl;
    file << "DO NOT CONTINUE TO READ IT, for it will have no significance to you." << endl;

    file.close(); // closing the file, good practice to always close the file when done

    ifstream file2(file_name); // ifstream is the input file stream

    if (file2.is_open()){
        cout << "file has been opened" << endl;
    } else {
        cerr << "ERROR while atempting to open file" << endl;
        return 1;
    }

    string line;

    while (getline(file2, line)){ // getline is a function that reads a line from the file and stores it in the string line
        cout << line << endl;
    }

    file.close();


    return 0;
}
