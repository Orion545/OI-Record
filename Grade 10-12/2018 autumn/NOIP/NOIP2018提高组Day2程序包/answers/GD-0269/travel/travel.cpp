#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
using namespace std;

//#define DEBUG

#ifdef DEBUG
#define fin cin
#define fout cout
#endif

#ifndef DEBUG
ifstream fin("travel.in");
ofstream fout("travel.out");
#endif

bool graph[5005][5005];
bool asked[5005];
bool askable[5005];
const int INF = 0x7fffffff;
int n,m;

void ask_graph(int p)
{
	asked[p] = 1;
	fout<<p<<" ";
	for(int i=1;i<=n;++i)
		if(graph[p][i] && !asked[i])
			askable[i] = 1;
	int g;
	for(g=1;g<=n;++g)
		if(graph[p][g] && askable[g])
		{
			askable[g] = 0;
			ask_graph(g);
			break;
		}
	if(g==n+1)
		for(int i=1;i<=n;++i)
			if(askable[i])
			{
				askable[i] = 0;
				ask_graph(i);
				break;
			}
}

int main()
{
	memset(asked,0,sizeof(asked));
	memset(graph,0,sizeof(graph));
	memset(askable,0,sizeof(askable));
	fin>>n>>m;
	for(int i=0;i<m;++i)
	{
		int be,en;
		fin>>be>>en;
		graph[be][en] = graph[en][be] = 1;
	}
	ask_graph(1);
	return 0;
}
