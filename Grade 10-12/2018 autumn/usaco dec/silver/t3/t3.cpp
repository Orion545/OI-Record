#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<vector>
#define id(i,j) ((i-1)*10+j)
#define ll long long
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
const int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};
int n,m,tot,a[110][20],f[1010],mark[1010];
vector<int>tmp;
inline int find(int x){return ((f[x]<0)?x:(f[x]=find(f[x])));}
inline void join(int x,int y){
	x=find(x);y=find(y);
	if(x==y) return;
	f[x]+=f[y];f[y]=x;
}
int main(){
	freopen("mooyomooyo.in","r",stdin);
	freopen("mooyomooyo.out","w",stdout);
	n=read();m=read();int i,j,ti,tj,k,flag=1;char ss[20];
	for(i=n;i>=1;i--){
		scanf("%s",ss);
		for(j=1;j<=10;j++) a[i][j]=(ss[j-1]-'0');
	}
	tot=n*10;
	while(flag){
		for(i=1;i<=tot;i++) f[i]=-1;
		for(i=1;i<=n;i++){
			for(j=1;j<=10;j++){
				if(a[i][j]==0) continue;
				for(k=0;k<4;k++){
					ti=i+dx[k];tj=j+dy[k];
					if(ti<1||ti>n||tj<1||tj>10) continue;
					if(a[ti][tj]==a[i][j]) join(id(i,j),id(ti,tj));
				}
			}
		}
		memset(mark,0,sizeof(mark));flag=0;
		for(i=1;i<=tot;i++) if(f[i]<=-m) mark[i]=1;
		for(i=1;i<=n;i++){
			for(j=1;j<=10;j++){
				if(mark[(k=find(id(i,j)))]){
//					cout<<"clear "<<i<<' '<<j<<'\n';
					flag=1;
					a[i][j]=0;
				}
			}
		}
		/*
		cout<<"after clear\n";
		for(i=n;i>=1;i--){
			for(j=1;j<=10;j++) cout<<a[i][j];
			cout<<'\n';
		}
		*/
		for(j=1;j<=10;j++){
			tmp.clear();
			for(i=1;i<=n;i++) if(a[i][j]) tmp.push_back(a[i][j]);
			for(i=0;i<tmp.size();i++) a[i+1][j]=tmp[i];
			for(i=tmp.size()+1;i<=n;i++) a[i][j]=0;
		}
		/*
		cout<<"finish loop "<<flag<<'\n';
		for(i=n;i>=1;i--){
			for(j=1;j<=10;j++) cout<<a[i][j];
			cout<<'\n';
		}
		*/
	}
	for(i=n;i>=1;i--){
		for(j=1;j<=10;j++) cout<<a[i][j];
		cout<<'\n';
	}
}
