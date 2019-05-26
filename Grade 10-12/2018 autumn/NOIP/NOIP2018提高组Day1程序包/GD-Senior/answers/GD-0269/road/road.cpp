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
ifstream fin("road.in");
ofstream fout("road.out");
#endif

int road[100005];

int reduce_road(int b,int e)
{
	int zero_count = 0;
	int min_n = 10005;
	
	for(int i=b;i<e;++i)
		if(road[i]==0)
			++zero_count;
	if(zero_count==e-b)	return 0;
	
	int count = 0;
	int x = -1;
	for(int i=b;i<e;++i)
	{
		if(road[i]==0)
		{
			x = i;
			break;
		}
		else if(road[i]<=min_n)	min_n = road[i];
	}	
	if(x==-1)
	{
		for(int i=b;i<e;++i)
			road[i] -= min_n;
		count += reduce_road(b,e);
	}
	else
	{
		int _x = x;
		for(int i=b;i<x;++i)
			road[i] -= min_n;
		for(int i=b;i<_x;++i)
		{
			if(road[i]==0)
			{
				x = i;
				break;
			}
		}
		if(x==e-1)
		{
			count += reduce_road(b,x);
		}
		else
		{
			count += reduce_road(b,x) + reduce_road(x+1,e);
		}
	}
	
	if(x == 0 || min_n>=10005)	return count;
	else	return count+min_n;
}

int main()
{
	memset(road,-1,sizeof(road));
	int n;
	fin>>n;
	for(int i=0;i<n;++i)
		fin>>road[i];
	fout<<reduce_road(0,n)<<endl;
	return 0;
}
