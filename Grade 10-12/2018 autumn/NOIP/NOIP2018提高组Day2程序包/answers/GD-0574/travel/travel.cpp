#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
ifstream fin("travel.in");
ofstream fout("travel.out");
struct point{
	int po;
	int to;
}p[100001];
int vis[6000];
int dui[2][6000];
int n,m,pn=0,dn[2]={0};
int  du[6000];

void pu(int x,int z){
	int i,j;
	dui[z][++dn[z]]=x;
	j=dn[z];
	while(dui[z][j/2]>dui[z][j]){
		dui[z][j]=dui[z][j/2];
		j/=2;
	}
	dui[z][j]=x;
	return ;
}

void poi(int z){
	int i,j,p;
	dui[z][1]=dui[z][dn[z]];
	i=dui[z][1];
	dn[z]--;
	p=1;
	while(p!=0){
		j=p*2;
		if(j+1<=dn[z]&&dui[z][j]>dui[z][j+1]) j++;
		if(j>dn[z]||dui[z][j]>i){
			dui[z][p]=i;
			p=0;
		}
		else{
			dui[z][p]=dui[z][j];
			p=j;
		}
	}
	return ;
}

void add(int x,int y){
	pn++;
	p[pn].po=y;
	p[pn].to=p[x].to;
	p[x].to=pn;
	return ;
}
int main (){
	int i,j,k;
	cin>>n>>m;
	
	for(i=1;i<=n;i++) {
		p[i].po=i;
		p[i].to=0;
		vis[i]=0;
		du[i]=0;
	}
	pn=n;
	for(i=1;i<=m;i++){
		cin>>j>>k;
		du[k]++;
	//	cout<<j<<" "<<k<<endl;
		add(j,k);
		add(k,j);
	}
     k=0;
	pu(1,0);
	vis[1]++;
	while(k<n){
	j=dui[0][1]; 
	poi(0);
		//vis[j]++;
		k++;
		cout<<j<<" ";
			
		if(du[p[j].po]==0&&j!=1){
			//fout<<p[i].po<<" ";
		//k++;
			for(int t=p[p[j].po].to;t;t=p[t].to)
			if(du[p[t].po]==1&&vis[p[t].po]==0) pu(p[t].po,1);
			else du[p[t].po]--;
			while(dn[1]>0) {
				cout<<dui[1][1]<<" ";
				vis[dui[1][1]]++;
				poi(1);
				k++;
			}
		vis[p[j].po]++;
		}
		else
		for(i=p[j].to;i;i=p[i].to)
if(vis[p[i].po]==0){
  vis[p[i].po]++;
	 pu(p[i].po,0);
}
//	 cout<<p[i].po<<" "<<endl;
	}

//	cout<<dn<<endl;
	//for(i=1;i<=dn;i++) cout<<dui[i]<<"  ";
//	cout<<endl;
 
//cout<<endl;
//	for(i=1;i<=n;i++) cout<<vis[i]<<" ";
//cout<<endl<<endl;
//	for(i=1;i<=pn;i++) cout<<i<<"  "<<p[i].po<<" "<<p[i].to<<endl;
	fin.close();
	fout.close();
	return 0;
}
