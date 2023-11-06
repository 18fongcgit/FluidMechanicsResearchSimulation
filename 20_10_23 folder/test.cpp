#include <iostream>
#include <fstream>
#include <string>
using namespace std;
char c;

int main()
{
    string fileIn;
    string fileOut;

    cout << "Enter Input file";
    cin >> fileIn;
    cout << "Enter Output file";
    cin >> fileOut;

    if(fileIn.empty()) {
        fileIn = "inputs.inp";
    }if(fileOut.empty()) {
        fileOut = "output.dat";
    }
    cout << fileIn.c_str() << endl;
    cout << fileOut.c_str() << endl;

    ifstream inputMessageFile(fileIn.c_str()); // ifstream inputMessageFile("inputs.inp");
    ofstream outputMessageFile(fileOut.c_str()); // ofstream outputMessageFile("output.dat");
    string line;
    int count(0);

    if (inputMessageFile.fail())
    {
        cerr << "Error opening input file";
        return -1;
    }
    if (outputMessageFile.fail())
    {
        cerr << "Error opening/creating output file";
        return -1;
    }
    outputMessageFile.flush();
    while (getline(inputMessageFile,line)) 
    {
        if (line.find(" ") != (size_t) -1) 
        {
            outputMessageFile << line.substr(0,line.find(" ")) << endl;
        }
        count ++;
        cout<< count;
    }
    inputMessageFile.close();
    outputMessageFile.close();

    return 0;
}
