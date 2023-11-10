#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
char c;

int main()
{
  string fileIn;
  string fileOut;
  vector<int> outputX;
  vector<int> outputY;

  double Lx, Ly;
  uint32_t Nx, Ny;

  // cout << "Enter Input file ";
  // cin >> fileIn;
  // cout << "Enter Output file ";
  // cin >> fileOut;

  if (fileIn.empty())
  {
    fileIn = "inputs.inp";
  }
  if (fileOut.empty())
  {
    fileOut = "x.dat";
  }
  cout << fileIn.c_str() << endl;
  cout << fileOut.c_str() << endl;

  ifstream inputMessageFile(fileIn.c_str());   // ifstream inputMessageFile("inputs.inp");
  ofstream outputXFile(fileOut.c_str()); // ofstream outputMessageFile("output.dat");
  string line;
  // int count(0);

  if (inputMessageFile.fail())
  {
    cerr << "Error opening input file";
    return -1;
  }
  if (outputXFile.fail())
  {
    cerr << "Error opening/creating output file";
    return -1;
  }
  outputXFile.flush();

  getline(inputMessageFile, line);
  if (line.find(" ") != (size_t)-1)
  {
    Lx = stod(line.substr(0, line.find(" ")));
  }
  getline(inputMessageFile, line);
  if (line.find(" ") != (size_t)-1)
  {
    Ly = stod(line.substr(0, line.find(" ")));
  }
  getline(inputMessageFile, line);
  if (line.find(" ") != (size_t)-1)
  {
    string str = line.substr(0, line.find(" "));
    Nx = static_cast<uint32_t>(stoul(str));
  }
  getline(inputMessageFile, line);
  if (line.find(" ") != (size_t)-1)
  {
    string str = line.substr(0, line.find(" "));
    Ny = static_cast<uint32_t>(stoul(str));
  }
  cout << Lx <<" "<<typeid(Lx).name()<< endl;
  cout << Ly <<" "<<typeid(Ly).name()<< endl;
  cout << Nx <<" "<<typeid(Nx).name()<< endl;
  cout << Ny <<" "<<typeid(Ny).name()<< endl;
  
  double dx = Lx/Nx;
  double dy = Ly/Ny;
  // cout << dy;
  for (double i = -0.5 * dx; i < Lx+dx; i += dx)
  {
    outputX.push_back(i);
    outputXFile << i << endl;
    // cout << i<< endl; 
  }
  outputXFile.close();

    fileOut = "y.dat";  
  ofstream outputYFile(fileOut.c_str());

   if (outputYFile.fail())
  {
    cerr << "Error opening/creating output file";
    return -1;
  }
  for (double i = -0.5 * dy; i < Ly+dy; i += dy)
  {
    outputY.push_back(i);
    outputYFile << i << endl;
    // cout << i<< endl; 
  }
outputYFile.close();
  

  inputMessageFile.close();
  

  return 0;
}
