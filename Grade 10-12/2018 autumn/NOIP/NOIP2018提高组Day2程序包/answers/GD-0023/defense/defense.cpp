#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int n,m,f[100007][5],ff[100007][5],a[1000007];

int mi(int x,int y){
	if (x>y) return y;
	return x;
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);
	string ch;
	cin>>ch;
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
	}
	for (int i=1;i<=n;i++)
		ff[i][1]=ff[i][0]=1e9;
	ff[1][1]=a[1];
	ff[1][0]=0;
	ff[2][0]=a[1];
	ff[2][1]=a[2];
	ff[0][1]=1e9;
	for (int i=3;i<=n;i++){
		ff[i][1]=mi(ff[i-1][1],ff[i-1][0])+a[i];
		ff[i][1]=mi(ff[i][1],ff[i-2][1]+a[i]);
		ff[i][1]=mi(ff[i][1],ff[i-3][1]+a[i]);
		ff[i][0]=ff[i-1][1];
	}
	for (int i=1;i<=m;i++){
		int x,x1,y,y1;
		scanf("%d%d%d%d",&x,&x1,&y,&y1);
		if (x>y){
			int z=x;x=y;y=z;
		}
		if (x==y-1&&x1==0&&y1==0) printf("-1\n");
		else{
			for (int i=1;i<=x;i++)
				f[i][1]=ff[i][1],f[i][0]=ff[i][0];
			if (x1==0) f[x][1]=1e9;
			else f[x][0]=1e9;
			for (int i=x+1;i<=y;i++){
				f[i][1]=mi(f[i-1][1],f[i-1][0])+a[i];
				if (x1==0||x1==1&&i-2>=x) f[i][1]=mi(f[i][1],f[i-2][1]+a[i]);
				if (x1==0||x1==1&&i-3>=x) f[i][1]=mi(f[i][1],f[i-3][1]+a[i]);
				f[i][0]=f[i-1][1];
			}
			if (y1==0) f[y][1]=1e9;
			else f[y][0]=1e9;
			for (int i=y+1;i<=n;i++){
				f[i][1]=mi(f[i-1][1],f[i-1][0])+a[i];
				if (y1==0||y1==1&&i-2>=y) f[i][1]=mi(f[i][1],f[i-2][1]+a[i]);
				if (y1==0||y1==1&&i-3>=y) f[i][1]=mi(f[i][1],f[i-3][1]+a[i]);
				f[i][0]=f[i-1][1];
			}
			printf("%d\n",mi(f[n][1],f[n][0]));
		}
	}
	fclose(stdin);fclose(stdout);
}
