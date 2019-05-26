#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define ll long long
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int cnt[10][10]={
{0,0,0,0,0,0,0,0,0,0},
{0,1,2,3,4,5,6,7,8,9},
{0,1,2,2,3,4,4,5,6,6},
{0,1,1,2,2,3,3,4,4,5},
{0,1,1,2,2,2,3,3,4,4},
{0,1,1,2,2,2,3,3,3,4},
{0,1,1,1,2,2,2,3,3,3},
{0,1,1,1,2,2,2,3,3,3},
{0,1,1,1,2,2,2,2,3,3},
{0,1,1,1,2,2,2,2,3,3}};
int ans[7][7]={
{0,0,0,0,0,0,0},
{0,1,2,3,4,5,6},
{0,1,1,3,10,15,21},
{0,1,2,10,12,35,30},
{0,1,2,0,0,0,0},
{0,1,4,0,0,0,0},
{0,1,4,6,0,0,0}};
int main(){
	int T=read();
	while(T--){
		int n=read(),m=read();
		cout<<cnt[n][m]<<' '<<ans[n][m]<<'\n';
	}
}
