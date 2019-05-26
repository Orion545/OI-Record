#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define ll long long
using namespace std;
inline ll read(){
	ll re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
inline int gcd(int x,int y){
	if(y==0) return x;
	return gcd(y,x%y);
}
inline int getlcm(int x,int y){
	return x/gcd(x,y)*y;
}
int lis[110],cntl,vis[10010],trans[110][10];
void init(){
	int i,j,tmp,k,cur;cntl=0;
	for(i=1;i<10;i++){
		lis[++cntl]=i;
		vis[i]=cntl;
		trans[0][i]=i;
	}
	for(i=2;i<10;i++,cntl=cur){
		cur=cntl;
		for(j=1;j<=cntl;j++){
			for(k=1;k<10;k++){
				tmp=getlcm(k,lis[j]);
				if(!vis[tmp])lis[++cur]=tmp,vis[tmp]=cur;
				trans[j][k]=vis[tmp];
			}
			trans[j][0]=j;
		}
	}
}
ll f[20][50][2520];int t[20],len;
ll dfs(int pos,int lcm,int s,int lim){
	if(!pos) return lcm&&(s%lis[lcm]==0);
	if(!lim&&~f[pos][lcm][s]) return f[pos][lcm][s];
	ll re=0;int i,tmp,end=(lim?t[pos]:9);
	for(i=0;i<=end;i++){
//		tmp=(lcm?(vis[getlcm(lis[lcm],max(i,1))]):i);
//		re+=dfs(pos-1,tmp,(s*10+i)%2520,lim&&(i==end));
		re+=dfs(pos-1,trans[lcm][i],(s*10+i)%2520,lim&&(i==end));
	}
	if(!lim) f[pos][lcm][s]=re;
	return re;
}
ll solve(ll x){
	len=0;ll tmp=x;memset(f,-1,sizeof(f));
	while(tmp){
		t[++len]=tmp%10ll;
		tmp/=10ll;
	}
	return dfs(len,0,0,1);
}
int main(){
	init();ll T=read(),l,r;
	while(T--){
		l=read();r=read();
		printf("%lld\n",solve(r)-solve(l-1));
	}
}
