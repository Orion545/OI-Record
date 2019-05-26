#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int dx[9]={0,-1,-1,-1,0,1,1,1,0};
const int dy[9]={0,-1,0,1,1,1,0,-1,-1};
struct edge{
	int to,next;
}a[1000010];
int n,m,cnt,num,tot,flag,x[100010],first[100010],in[100010];
int id(int i,int j){
	return (i-1)*m+j;
}
int read(){
	int re,flag=1;char ch=getchar();
	while(ch>'9'&&ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0') re=re*10+ch-'0',ch=getchar();
	return re*flag;
}
vector<int>qlt[100010];
vector<int>plat;
void dfs(int k){
	int i,v;
	qlt[num].push_back(k);
	for(i=first[k];~i;i=a[i].next){
		v=a[i].to;
		if(x[v]>x[k]) flag=0;
		if(x[v]==x[k]) dfs(v);
	}
}
int main(){
	int i,j,k,r,l;
	memset(first,-1,sizeof(first));
	n=read();m=read();
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			int l=id(i,j);
			x[l]=read();
			for(k=1;k<=8;k++){
				if(i+dx[k]<=0||i+dx[k]>n||j+dy[k]<=0||j+dy[k]>n) continue;
				r=id(i+dx[k],j+dy[k]);
				cnt++;
				a[cnt].to=r;a[cnt].next=first[l];first[l]=cnt;
			}
		}
	}
	tot=n*m;
	for(i=1;i<=tot;i++){
		if(!in[i]){
			num++;flag=1;
			dfs(i);
			if(flag) plat.push_back(num);
		}
	}
} 
