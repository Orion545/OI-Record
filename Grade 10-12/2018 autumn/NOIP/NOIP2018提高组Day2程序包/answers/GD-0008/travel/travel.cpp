#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

const int maxn=5050;
//const int maxm=3050;
ifstream fin("travel.in");
ofstream fout("travel.out");
int n,m;
bool g[maxn][maxn];
int s[maxn],ne[maxn],l[maxn];
bool vis[maxn];
string ss;
bool k=0;

void init(){
	int i,j,f,t;
	memset(g,0,sizeof(g));
	fin>>n>>m;
	for(i=1;i<=m;i++){
		fin>>f>>t;
		g[f][t]=1;
		g[t][f]=1;
	}
}

void check1(){
	int i,j;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++) cout<<g[i][j]<<" ";
		cout<<endl;
	}
}

int next(int f){
	int i;
	for(i=ne[f]+1;i<=n;i++){
		if(g[f][i]==1) return i;
	}
	return n+1;
}

int last(int f){
	int i;
	for(i=ne[f]-1;i>=0;i--){
		if(g[f][i]==1) return i;
	}
	return 0;
}


void search(int p){
	/*cout<<endl<<endl;
	for(int i=1;i<=n;i++) cout<<s[i]<<" ";
	cout<<endl;
	*/
	
	int i,j,f,t,q,nx;
	if(p==n){
		k=1; 
		return;
	}
	f=s[p];
	for(t=ne[f];t<=n&&k==0;t++){
	//cout<<f<<" "<<t<<" "<<g[f][t]<<endl;	
		if(g[f][t]==1&&vis[t]==0){
			if(p==1){
				ne[f]=t;
				vis[t]=1;s[p+1]=t;l[p+1]=p;
				search(p+1);
			}else{
				ne[f]=t;
				nx=next(s[l[p]]);
				/*
				cout<<"nx:"<<nx<<" ";
				cout<<"vis"<<vis[nx]<<endl;
				*/
				if(t<=nx&&vis[t]==0){
					//cout<<"in"<<"vis["<<t<<"]="<<vis[t]<<endl;
						vis[t]=1;s[p+1]=t;l[p+1]=p;
						search(p+1);
						if(k==0) vis[t]=0;
					if(nx<=n&&vis[nx]==0&&k==0){
						vis[t]=0;
						vis[nx]=1;s[p+1]=nx;l[p+1]=l[p];
						ne[l[p]]=nx;
						search(p+1);
						if(k==0){
							vis[nx]=0;
							ne[l[p]]=last(s[l[p]]);
						} 
					}
				}else{
					bool flag=0;
					if(vis[nx]==0&&nx<=n){
						vis[nx]=1;
						flag=1;
						s[p+1]=nx;l[p+1]=l[p];
						ne[l[p]]=nx;
						search(p+1);
						if(k==0){
							vis[nx]=0;
							ne[l[p]]=last(s[l[p]]);
						} 
					}
					
					if(k==0&&vis[t]==0){
						if(flag==1) vis[nx]=0;
						vis[t]=1;s[p+1]=t;l[p+1]=p;
						search(p+1);
						if(k==0) vis[t]=0;
					}
				}
			}	
		}
	}
	
	q=p;
	while(l[q]!=0){
		nx=next(s[l[q]]);
		//cout<<"nx "<<nx<<endl;
		if(nx<=n&&vis[nx]==0&&k==0){
			vis[nx]=1;s[p+1]=nx;l[p+1]=l[q];
			search(p+1);
		}
		q=l[q];
	}
	return;
}

void find(){
	memset(ne,0,sizeof(ne));
	s[0]=-1;
	s[1]=1;
	l[1]=0;vis[1]=1;
	ne[0]=maxn;
	search(1);
}

int main(){
	init();
	find();
	for(int i=1;i<=n;i++) fout<<s[i]<<" ";
	fin.close();
	fout.close();
	return 0;
}
