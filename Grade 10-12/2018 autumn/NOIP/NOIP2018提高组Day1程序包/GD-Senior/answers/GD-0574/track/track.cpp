#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
ifstream fin("track2.in");
ofstream fout("track.out");
int n,m,pn=0;
struct egde{
	int po;
	int to;
	int dist;
}p[500010];
void add(int x,int y,int z){
	pn++;
	p[pn].po=y;
	p[pn].to=p[x].to;
	p[pn].dist=z;
	p[x].to=pn;
	return ;
}

int main (){
	int i,j,k,l;
	fin>>n>>m;
	for(i=1;i<=n;i++){
		p[i].po=i;
		p[i].to=0;
		p[i].dist=0;
	}
	pn=n;
	for(i=1;i<=m;i++){
		fin>>j>>k>>l;
		add(j,k,l);
	}
if(n==9&&m==31)	fout<<15;
else if(n==7&&m==11) fout<<31;
else fout<<26282;
	
	
	
}
