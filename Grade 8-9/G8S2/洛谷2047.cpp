#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
double a[110][110],dis[110][110],n,m;
double impt[110]={0};
void floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(i!=k){
				for(int j=1;j<=n;j++){
					if(i!=j&&j!=k){
						if(a[i][k]+a[k][j]<a[i][j]){
//							cout<<i<<ends<<j<<ends<<k<<endl;
							a[i][j]=a[i][k]+a[k][j];
							dis[i][j]=dis[i][k]*dis[k][j];
//							cout<<dis[i][j]<<endl;
						}
						else if(a[i][k]+a[k][j]==a[i][j]){
//							cout<<"*** "<<i<<ends<<j<<ends<<k<<endl;
							dis[i][j]+=dis[i][k]*dis[k][j];
//							cout<<dis[i][j]<<endl;
						}
					}
				}
			}
		}
	}
	/*
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<dis[i][j]<<ends;
		}
		cout<<endl;
	}cout<<endl<<endl;
	*/
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(i!=k){
				for(int j=1;j<=n;j++){
					if(i!=j&&j!=k){
						if(a[i][k]+a[k][j]!=a[i][j]||dis[i][j]==0) continue;
//						cout<<i<<ends<<j<<ends<<k<<endl;
						impt[k]+=(dis[i][k]*dis[k][j])/dis[i][j];
					}
				}
			}
		}
	}
}
int main(){
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	int ta,tb,tc;
	memset(a,127,sizeof(a));
	for(int i=1;i<=m;i++){
		cin>>ta>>tb>>tc;
		a[ta][tb]=a[tb][ta]=tc;
		dis[ta][tb]=dis[tb][ta]=1;
	}
	floyd();
	for(int i=1;i<=n;i++){
		printf("%.3f\n",impt[i]);
	}
}
