#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <chrono> 

using namespace std;





int main(){
    //code takes user input for file name
    inputusrfile:
    string filename;
    cout << "Type your csv file path: ";
    cin >> filename; // get user input from the keyboard
    cout << "Your File is: " << filename<<endl;

    //import csv file to "file"
    ifstream file(filename.c_str());

    //outputdata is an array of vectors used to represent a table with GridID | SumCount | Sum(Count*depth)
    vector <int> outputdata[3];
    
    //skip first line of csv file (Skip Headers)
    string line;
    getline(file, line);

    //test if file was loaded
    if(line.empty()){
        cout<<"file not loaded"<<endl;
        goto inputusrfile;
    }else{
        cout<<"File Loaded..."<<endl;
        cout<<"Running..."<<endl;
    }


    //vector V is use to hold current line of csv file
    vector<int> v;
    
}