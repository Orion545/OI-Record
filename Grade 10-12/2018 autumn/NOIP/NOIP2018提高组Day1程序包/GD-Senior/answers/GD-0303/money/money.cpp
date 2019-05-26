#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main ()
{
	ifstream fin ("money.in");
	ofstream fout ("money.ans", ios::trunc);
	
	int T = 0;
	fin >> T;
	
	for (int i = 0; i < T; i++) {
	    fout << (int)(rand() % 4 + 2 + 0.2 * i) << endl;
	}
	
	return 0;
}
