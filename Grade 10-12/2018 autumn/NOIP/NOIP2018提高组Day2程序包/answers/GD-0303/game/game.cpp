#include <iostream>
#include <fstream>

using namespace std;

const int bigPrime = 1000000000 + 7;

unsigned long long factorial (unsigned long n) 
{
	if (n != 1) {
		return n * factorial(n - 1);
	} else {
		return 1;
	}
}

int main ()
{
	ifstream fin ("game.in");
	ofstream fout ("game.ans", ios::trunc);
	
	int h = 0;
	int w = 0;
	fin >> h >> w;
	
	fout << h * h * w * w - h - w << endl;
	
	return 0;
}
