#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cmath>
using namespace std;
bool road[5005][5005],p[5005];
int n,m,u,v,journey[5005],before[5005];
int main(){
	FILE *fin,*fout;
	fin=fopen("travel.in","rb");
	fout=fopen("travel.out","wb");
	memset(road,false,sizeof(road));
	memset(p,false,sizeof(p));
	memset(journey,0,sizeof(journey));
	memset(before,0,sizeof(before));
	fscanf(fin,"%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		fscanf(fin,"%d%d",&u,&v);
		road[u][v]=true;
		road[v][u]=true;
	}
	int count=0,now=1;
	while (count<n){
		p[now]=true;
		count++;
		journey[count]=now;
		for (int i=1;i<=n;i++)
		 if ((road[now][i]==true)&&(!p[i])) {
		 	before[i]=now;
			now=i;
		 	break;
		 }
		 if (p[now]) {
		 	int x=now;
		 	while (x>0){
		 		x=before[x];
		 	    for (int i=1;i<=n;i++)
		         if ((road[x][i]==true)&&(!p[i])){
		     	  before[i]=x;
				  now=i;
		     	  break;	
		     	}
		     	 if (!p[now]) break;
		 }   
		 }
	}
	for (int i=1;i<=n;i++)
	 fprintf(fout,"%d",journey[i]);
	fclose(fin);
	fclose(fout);
	return 0; 
}
