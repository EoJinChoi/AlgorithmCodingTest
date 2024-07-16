#include <iostream>
#include <string>
using namespace std;

int main()
{
    string sNum = "1234";
    string sNum_d = "1234.56";
    int inum = stoi(sNum);
    long lnum = stol(sNum);
    double dnum = stod(sNum_d);
    float fnum = stof(sNum_d);

    cout << inum << " " << lnum << " " << dnum << " " << fnum << "\n";

    inum = 1234;
    lnum = 1234;
    dnum = 1234.56;
    fnum = 1234.56f;
    string intToString = to_string(inum);
    string longToString = to_string(lnum);
    string doubleToString = to_string(dnum);
    string floatToString = to_string(fnum);

    cout << intToString << " " << longToString << " " << doubleToString << " " << floatToString << "\n";
}