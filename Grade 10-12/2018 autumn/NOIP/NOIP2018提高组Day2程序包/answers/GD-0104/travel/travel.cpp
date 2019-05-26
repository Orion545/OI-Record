#include<bits/stdc++.h>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef double db;
typedef long long LL;

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		int s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return -s;
	}
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int N = 5005;

int n,m;
int e[N][N];
int sx,sy;
bool vis[N];
int ans[N];
int que[N],k;

void getque(int x){
	que[++k]=x;
	vis[x]=1;
	fo(i,1,e[x][0])
	if (!vis[e[x][i]]){
		int y=e[x][i];
		if((!(x==sx&&y==sy))&&(!(x==sy&&y==sx)))getque(y);
	}
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=get();m=get();
	fo(i,1,m){
		int x=get(),y=get();
		e[x][++e[x][0]]=y;
		e[y][++e[y][0]]=x;
	}
	fo(i,1,n)sort(e[i]+1,e[i]+1+e[i][0]);
	ans[1]=n+1;
	if (m==n){
		fo(Sx,1,n){
			fo(Sy,1,e[Sx][0]){
				sx=Sx,sy=e[Sx][Sy];
				if (sx>sy)continue;
				fo(i,1,n)vis[i]=0;
				k=0;
				getque(1);
				if (k<n)continue;
				bool yes=1;
				fo(i,1,n)
				if(que[i]!=ans[i]){yes=(que[i]<ans[i]);break;}
				if (yes)fo(i,1,n)ans[i]=que[i];
			}
		}
	}
	else{
		getque(1);
		fo(i,1,n)ans[i]=que[i];
	}
	fo(i,1,n)printf("%d%c",ans[i],i==n?'\n':' ');
	return 0;
}
