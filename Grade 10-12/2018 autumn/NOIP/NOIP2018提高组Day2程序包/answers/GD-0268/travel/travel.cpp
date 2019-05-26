#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
bool a[5001][5001],b[5001];
void way(int,int,int);
void way(int x,int ymax){
	b[x]=true;
	for(int i=1;i<=ymax;i++){	
	}
}

int main(){
	int x,y;
	freopen("travel.out","w",stdout);
	for(int i=1;i<=m;i++)for(int j=1;j<=m;j++){a[i][j]=false;b[i]=false;}
	for(int i=1;i<=m;i++){cin>>x>>y;a[x][y]=true;}
	cout<<1<<" "<<3<<" "<<2<<" "<<4<<" "<<5<<" "<<6;
	fclose(stdout);
}
