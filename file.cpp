#include <iostream>
#include <fstream>
using namespace std;

// ifstream inStream;    // input 전용 stream
// ofstream outStream;   // output 전용 stream
// file 선언하면 file open은 자동으로 수행

int main(){
    ifstream f1("a.dat");     // input file stream
    ofstream f2("b.dat");     // output file stream   
    int a, b; 
    if(!f1) 
        cout<<"File open error: the file does not exist.\n";
    else{
        f1>>a>>b;
        f2<<a*b;
        f1.close();
        f2.close();
    }
}
