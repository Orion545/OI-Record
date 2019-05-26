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
ifstream fin("money.in");
ofstream fout("money.out");
#endif

int N[105];
bool cut[105];

bool show_money(int big_one,int mod_one)
{
	bool if_cut = 0;
	int x = big_one%mod_one;
	if(x==0)	return true;
	if(x == big_one)	return false;
	for(int i=0;N[i]<=x;++i)
		if(cut[i]==false && show_money(x,N[i]))
		{
			if_cut = true;
			break;
		}
	return if_cut;
}

int cut_money(int n)
{
	for(int i=1;i<n-1;++i)
		if(cut[i] == false)
			for(int j=i+1;j<n;++j)
				if(cut[j]==false	&&	N[j]%N[i] == 0)
					cut[j] = true;
	for(int i=n-1;i>0;--i)
		if(cut[i] == false)
		{
			for(int j = 0;j<i;++j)
				if(cut[j]==false && show_money(N[i],N[j]))
				{
					cut[i] = true;
					break;
				}
		}
	int count = 0;
	for(int i=0;i<n;++i)
		if(cut[i] == false)
			++count;
	#ifdef DEBUG
	if(show_money(16,13))
		fout<<"True"<<endl;
	for(int i=0;i<n;++i)
		if(cut[i] == false)
			fout<<N[i]<<" ";
	fout<<endl;
	#endif
	return count;
}

int main()
{
	int t,n;
	fin>>t;
	for(int i=0;i<t;++i)
	{
		memset(N,0,sizeof(N));
		memset(cut,0,sizeof(cut));
		fin>>n;
		for(int j=0;j<n;++j)
			fin>>N[j];
		sort(N,N+n);
		if(N[0]==1)	fout<<1;
		else	fout<<cut_money(n)<<endl;
	}
	return 0;
}
