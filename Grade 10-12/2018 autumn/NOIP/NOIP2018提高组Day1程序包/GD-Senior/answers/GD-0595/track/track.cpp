//NOIP2018day1T3	2018.11.10	先打部分分
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define INF 2147483647
using namespace std;
int way[100100][3],far[50100],num,head,last,tail,n,m,i,j,k,l[100100],ans,a,b,c,d,dep[50100],f[50100][20],bfs[50100],dist[50100];
bool sit1,sit2,sit3,ask[500100],have[500100];
int read(){
	int ans=0;char c=getchar();
	while(c < '0' || c > '9')	c=getchar();
	while(c >= '0' && c <= '9'){ans=(ans<<1)+(ans<<3)+c-48;c=getchar();}
	return ans;
}
int lo(int x){
	if(x == 0)	return -1;
	int ans=0;
	while(x != 0){x=(x>>1);ans++;}
	return ans;
}
int lca(int x,int y){
	if(dep[x] < dep[y])	swap(x,y);
	int i,j,k;
	for(k=lo(x);k >= 0;k--)
		if(dep[f[x][k]] >= dep[y])
			x=f[x][k];
	if(x == y)	return y;
	else	for(k=lo(x);k >= 0;k--)
				if(f[x][k] != f[y][k]){
					x=f[x][k];y=f[y][k];
				}
	return f[x][0];
}
bool cmp1(int a,int b){return a > b;}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n=read();m=read();
	sit2=true;
	for(i=1;i <= n-1;i++){
		a=read();b=read();c=read();
		l[i]=c;
		if(a != 1)	sit2=false;	
		way[++num][0]=b;way[num][1]=c;way[num][2]=far[a];far[a]=num;
		way[++num][0]=a;way[num][1]=c;way[num][2]=far[b];far[b]=num;
	}
	if(sit2){
		sort(l+1,l+n,cmp1);
		i=1;
		ans=INF;
		while(m+i <= n && m-i+1 > 0){
			ans=min(ans,l[m-i+1]+l[m+i]);
			i++;
		}
		for(j=1;j <=m-i+1;j++)	ans=min(ans,l[j]);
		printf("%d\n",ans);
		return 0;
	}
	if(m == 1){
		bfs[1]=tail=1;d=head=last=0;ask[1]=true;dist[1]=0;	
		while(head < tail){
			d++;
			head=last+1;last=tail;
			for(i=1;i <= last;i++){
				j=far[bfs[i]];
				while(j > 0){
					if(ask[way[j][0]] == false){
						have[bfs[i]]=true;
						ask[way[j][0]]=true;
						dep[way[j][0]]=d;
						dist[way[j][0]]=dist[bfs[i]]+way[j][1];
						f[way[j][0]][0]=bfs[i];
						bfs[++tail]=way[j][0];
					}
					j=way[j][2];
				}
			}
		}
		for(k=1;k <= lo(n);k++)//预处理树上倍增 
			for(i=1;i <= n;i++)
				if(dep[i] >= (1<<k))	f[i][k]=f[f[i][k-1]][k-1];
		ans=0;
		for(i=2;i <= n;i++)	ans=max(ans,dist[i]);
		num=0;
		for(i=1;i <= n;i++)
			if(have[i] == false)	l[++num]=i;
		for(i=1;i <= num;i++)
			for(j=1;j <= num;j++)
				if(i != j){
					ans=max(ans,dist[l[i]]+dist[l[j]]-2*dist[lca(l[i],l[j])]);
				}
		printf("%d\n",ans);
		return 0;
	}
	ans=INF;
	for(i=1;i <= 2*(n-1);i++)	ans=min(ans,way[i][1]);
	printf("%d\n",ans);
	return 0;
}
