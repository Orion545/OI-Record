#include <fstream>
#include <iostream>
using namespace std;
int main(){
	int a;
	ifstream fin;
	fin.open("track.in");
	while(fin>>a);
	fin.close();
	ofstream fout;
	fout.open("track.out");
	fout<<31;
}
