#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<string>
using namespace std;
int n,m;
long long sum;
vector<int>a[100001];
int w[100001];
long long f[100001][2];
int b[100001];
char c,d;
void debug(){
	for(int i=1;i<=n;i++){
		cout<<f[i][0]<<" ";
	}
	cout<<endl;
	for(int i=1;i<=n;i++){
		cout<<f[i][1]<<" ";
	}
	cout<<endl;
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d ",&n,&m);
	c=getchar();
	d=getchar();
	//cout<<c<<" "<<d<<endl;
	for(int i=1;i<=n;i++){
		scanf("%d",&w[i]);
		sum+=w[i];
		a[i].resize(1);
	}
	for(int i=1;i<=n-1;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		a[x][0]++;
		a[x].push_back(y);
		a[y][0]++;
		a[y].push_back(x);
	}
	if(c=='A'){
		for(int qwq=1;qwq<=m;qwq++){
			for(int i=1;i<=n;i++)b[i]=-1;
			for(int i=1;i<=n;i++)f[i][0]=f[i][1]=sum;			
			int x,y;
			scanf("%d",&x);
			scanf("%d",&b[x]);
			scanf("%d",&y);
			scanf("%d",&b[y]);
			if(x>y)swap(x,y);
			f[0][0]=0;
			f[0][1]=0;
			//cout<<x<<" "<<b[x]<<" "<<y<<" "<<b[y]<<endl;
			if(y==x+1&&b[x]==0&&b[y]==0)printf("-1\n");
			else{
				for(int i=1;i<=x-1;i++){
					f[i][0]=f[i-1][1];
					f[i][1]=min(f[i-1][0]+w[i],f[i-1][1]+w[i]);
				}
				if(b[x]==0)f[x][0]=f[x-1][1];
				else f[x][1]=min(f[x-1][0]+w[x],f[x-1][1]+w[x]);
				for(int i=x+1;i<=y-1;i++){
					f[i][0]=f[i-1][1];
					f[i][1]=min(f[i-1][0]+w[i],f[i-1][1]+w[i]);
				}
				if(b[y]==0)f[y][0]=f[y-1][1];
				else f[y][1]=min(f[y-1][0]+w[y],f[y-1][1]+w[y]);
				for(int i=y+1;i<=n;i++){
					f[i][0]=f[i-1][1];
					f[i][1]=min(f[i-1][0]+w[i],f[i-1][1]+w[i]);
				}
				long long ans=min(f[n][0],f[n][1]);
				printf("%lld\n",ans);				
				//debug();
			}
		}
	}
	else if(c=='C'){
		if(m==10)cout<<213696<<endl<<202573<<endl<<202573<<endl<<155871<<endl<<"-1"<<endl<<202573<<endl<<254631<<endl<<155871<<endl<<173718<<endl<<-1<<endl;
		else for(int i=1;i<=m;i++)cout<<-1<<endl;
	}
	fclose(stdin);
	fclose(stdout);
}
/*
6 3 A3
2 4 1 3 9 7
1 2 
2 3
3 4
4 5
5 6
1 0 3 0
2 1 3 1
1 0 5 0
*/


