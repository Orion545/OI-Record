#include<iostream>
#include<cstring> 
using namespace std;
int main(){
	int n,dis[101][101],op,ed;cin>>n;
	memset(dis,0x7f,sizeof(dis));
	int a,b,c;
	for(int i=1;i<=n;i++){
		cin>>a>>b>>c;
		dis[a][b]=c;
	}
	cin>>op>>ed;
	
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(i!=j&&i!=k&&j!=k)
					if(dis[i][j]>dis[i][k]+dis[k][j])
						dis[i][j]=dis[i][k]+dis[k][j];
	
	cout<<dis[op][ed];
}
