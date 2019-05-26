#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstring>
int n,m;
int a[5001][5001];
bool vis[10001];
int p[10000];
int ji[5001];
int ans[5001];
int js=1;
int small(int y){
	int t;
	t=5002;
	for(int i=1;i<=y;i++){
		if(p[i]<=t and vis[p[i]]==true){
			t=p[i];
		}
	}
	vis[t]=false;
	return t;
}
void xz(int x){
	p[1]=x;
	int tail=1;
	while(js<=n){
		ans[js]=small(tail);
		int bl;
		bl=ans[js];
		js++;
	    for(int i=1;i<=n;i++){
	        if(a[bl][i]==1){
	 		    tail++;
	 		    p[tail]=i;
	        }
	    }
	}
	return ;
}
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	memset(a,0,sizeof(a));
	for(int i=1;i<=5001;i++){
		vis[i]=true;
	}
	cin>>n>>m;
	int x,y;
	for(int i=1;i<=m;i++){
		cin>>x>>y;
		a[x][y]=1;
		a[y][x]=1;
	}
	xz(1);
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<" ";
	}
	
	
	return 0;
}
