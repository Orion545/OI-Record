#include<bits/stdc++.h>
using namespace std;
int mpp[1001][1001];
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x,y,w;
		cin>>x>>y>>w;
		mpp[x][y]=w;
		mpp[y][x]=w;
	}
	for(int x=1;x<=n;x++){	
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				mpp[i][j]=min(mpp[i][j],mpp[i][x]+mpp[x][j]);
			}
		}
	}
	int minn=0x7ffff;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
				minn=min(mpp[i][j],minn);	
		}
	}
	cout<<minn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

