#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define N 25001
using namespace std;
void read(int &x){
	char c;int f=1;x=0;c=getchar();
	while(c>57||c<48){if(c==45)f=-1;c=getchar();}
	while(c>=48&&c<=57){x=x*10+c-48;c=getchar();}
	x*=f;
}
int T,n;
int a[N];
bool f[N];
int solve1(){
	for(int i=1;i<=n;i++)read(a[i]);
	sort(a+1,a+n+1);
	int ans=1;
	for(int i=2;i<=n;i++){
		memset(f,0,sizeof(f));
		for(int j=1;j<i;j++)f[a[j]]=1;
		for(int j=1;j<=a[i];j++){
			for(int k=1;k<i;k++)
				if(j-a[k]){
					if(f[j-a[k]]){
						f[j]=1;
						break;
					}
				}
		}
		if(!f[a[i]])ans++;
	}
	return ans;
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	read(T);
	while(T--){
		read(n);
		if(n<=25){//¼ì²é£¡£¡£¡ 
			printf("%d\n",solve1());
		}
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
/*
2
4
3 19 10 6
5
11 29 13 19 17
*/
