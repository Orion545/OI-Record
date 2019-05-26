#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

const int maxn=300000;

ifstream fin("track.in");
ofstream fout("track.out");
int n,m;
long long ans=0,now=0;
int head[maxn],to[maxn],v[maxn],l[maxn];
int nr[maxn],s[maxn],que[maxn];
bool vis[maxn];


void init(){
	int i,j,k,f,t,w,ln,tail;
	fin>>n>>m;
	tail=0;
	memset(head,0,sizeof(head));
	memset(nr,0,sizeof(nr));
	for(i=1;i<=n-1;i++){
		fin>>f>>t>>w;
		nr[f]++;
		nr[t]++;
		tail++;
		to[tail]=t;
		v[tail]=w;
		l[tail]=head[f];
		head[f]=tail;
		tail++;
		to[tail]=f;
		v[tail]=w;
		l[tail]=head[t];
		head[t]=tail;
	}
}

void check1(){
	int i;
	for(i=1;i<=n;i++) cout<<head[i]<<" ";
	cout<<endl;
	for(i=1;i<=2*n-2;i++) cout<<v[i]<<" ";
	cout<<endl;
	for(i=1;i<=2*n-2;i++) cout<<to[i]<<" ";
	cout<<endl;
	for(i=1;i<=2*n-2;i++) cout<<l[i]<<" ";
	cout<<endl;
	for(i=1;i<=n;i++) cout<<nr[i]<<" ";
	cout<<endl;
}

void dfs(int p){
	int i,j,k,t,f,w;
	f=s[p];
	if(nr[f]==1&&p!=1) return;
	j=head[f];
	
	while(j>0){
		t=to[j];
		if(vis[t]==0){
			vis[t]=1;
			now=now+v[j];
			s[p+1]=to[j];
			dfs(p+1);
			if(now>ans) ans=now;
			now=now-v[j];
		}
		
		j=l[j]; 
	}
	//for(i=1;i<=p;i++) cout<<s[i]<<" ";
	//cout<<endl;
	//cout<<"ans:"<<ans<<endl;
}

int main(){
	int i,j,k;
	init();
	if(m!=1) return 0;
	else{
			
		for(i=1;i<=n;i++){
			if(nr[i]==1){
				vis[i]=1;now=0;ans=0;
				memset(vis,0,sizeof(vis));
				s[1]=i;
				dfs(1);
			
			}
		}
	fout<<ans;
	}
	fin.close();
	fout.close();
	return 0;
}
