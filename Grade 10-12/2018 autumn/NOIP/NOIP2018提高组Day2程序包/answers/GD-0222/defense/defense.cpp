#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
int n,m,p[100003],u,v,vis[100003],ans[100003],ans1=0;
string type;

int so(int l,int r){
	if(l>=r) return 0;
	int ss,d[r+1][2],i,j,k;
	d[l][0]=0;d[l][1]=p[l];
	for(j=l+1;j<=r;j++){
		d[j][0]=d[j-1][1];
	d[j][1]=min(d[j-1][0]+p[j],d[j-1][1]+p[j]);
	}
	if(d[r][0]>d[r][1]) return d[r][1];
	else return d[r][0];
}
int main(){
	int i,j,k,a,x,b,y;
	ifstream fin;
	fin.open("defense.in");
	fin>>n>>m;
	fin>>type;
	for(i=1;i<=n;i++) fin>>p[i];
	for(i=1;i<n;i++) fin>>u>>v;
	for(i=1;i<=m;i++){
		fin>>a>>x>>b>>y;
		if(a>b){
			k=x;x=y;y=k;
			k=a;a=b;b=k;
		}
		if((a-b==1||b-a==1)&&x==0&&y==0){
			ans1++;ans[ans1]=-1;
		}
		else{
			int s=0;
			if(x==1&&y==0){
				s=s+so(1,a-1)+p[a]+so(a+1,b-2)+p[b-1]+so(b+2,n)+p[b+1];
				if(a==b-1) s=s-p[a];
			}
			if(x==0&&y==1){
			    s=s+so(1,a-2)+p[a-1]+so(a+2,b-1)+p[a+1]+p[b]+so(b+1,n);
			    if(a+1==b) s=s-p[b];
			}
			if(x==1&&y==1){
				s=s+so(1,a-1)+so(a+1,b-1)+so(b+1,n)+p[a]+p[b];
			}
			if(x==0&&y==0){
				s=s+so(1,a-2)+p[a-1]+so(a+2,b-2)+p[a+1]+p[b-1]+so(b+2,n)+p[b+1];
				if(a+1==b-1) s=s-p[b-1];
			}
			ans1++;ans[ans1]=s;
		}
		memset(vis,0,sizeof vis);
	}
	fin.close();
	ofstream fout;
	fout.open("defense.out");
	for(i=1;i<=m;i++) fout<<ans[i]<<endl;
	return 0;
}
