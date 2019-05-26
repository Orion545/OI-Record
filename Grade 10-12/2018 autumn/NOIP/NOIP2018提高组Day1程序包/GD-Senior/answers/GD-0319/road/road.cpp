#include<iostream>
#include<cstdlib>
#include<cstdio> 
#include<cmath>
#include<queue>
using namespace std;
int n;
int a[100010][18][2];
long long ex=0;

struct cc{
	int z,y,x;
	cc (int a,int b,int c){
		z=a; y=b; x=c;
	}
};
queue<cc>bfs;

void ccc(int z,int y,int x){
	if (z==y){
		ex+=a[z][0][0]-x;
		return;
	}
	int c=(int)log2(y-z+1);
	int zi=a[z][c][0];
	int yi=a[y-(1<<c)+1][c][0];
	if (zi<yi){
		ex+=zi-x;
		int m=a[z][c][1];
		if (m>z) bfs.push(cc(z,m-1,zi));
		if (m<y) bfs.push(cc(m+1,y,zi));
	}
	else{
		ex+=yi-x;
		int m=a[y-(1<<c)+1][c][1];
		if (m>z) bfs.push(cc(z,m-1,yi));
		if (m<y) bfs.push(cc(m+1,y,yi));
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i][0][0]);
		a[i][0][1]=i;
	}
	for (int j=1;j<=log2(n);j++){
		for (int i=1;i+(1<<j)-1<=n;i++){
			if (a[i][j-1][0]<a[i+(1<<(j-1))][j-1][0]){
				a[i][j][0]=a[i][j-1][0];
				a[i][j][1]=a[i][j-1][1];
			}
			else{
				a[i][j][0]=a[i+(1<<(j-1))][j-1][0];
				a[i][j][1]=a[i+(1<<(j-1))][j-1][1];
			}
		}
	}
	bfs.push(cc(1,n,0));
	while (!bfs.empty()){
		ccc(bfs.front().z,bfs.front().y,bfs.front().x);
		bfs.pop();
	}
	printf("%lld\n",ex);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

