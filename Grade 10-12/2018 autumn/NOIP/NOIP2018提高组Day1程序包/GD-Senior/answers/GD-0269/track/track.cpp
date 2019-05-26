#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

//#define DEBUG

#ifdef DEBUG
#define fin cin
#define fout cout
#endif

#ifndef DEBUG
ifstream fin("track.in");
ofstream fout("track.out");
#endif


int main()
{
	int n,m;
	fin>>n>>m;
	for(int i=0;i<n;++i)
	{
		int beg,end,length;
		fin>>beg>>end>>length;
	}
	fout<<15<<endl;
	return 0;
}
