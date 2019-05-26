#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define MOD 1000000007
using namespace std;
int n,K,m,len;
int f[110][2][100010],g[100010];
 
inline void FWT(int *A){
	int i,j;
	for(i=1;i<len;i<<=1)
		for(j=0;j<len;++j)
			if(j&i) A[j]=(A[j]+A[j^i])%MOD;
}
inline void IFWT(int *A){
	int i,j;
	for(i=1;i<len;i<<=1)
		for(j=0;j<len;++j)
			if(j&i) A[j]=(A[j]-A[j^i]+MOD)%MOD;
}
inline void rev(int *fr,int *to){for(int i=0;i<len;++i)to[(len-1)^i]=fr[i];}
 
inline void DP(){
	int i,j,k;
	for(i=0;i<K;++i){
		int sta=0;
		for(j=0;j<(1<<K);++j)
			if(j&(1<<i))sta|=(1<<j);
		f[0][0][sta]++;
	}
	rev(f[0][0],f[0][1]);
	FWT(f[0][0]);
	FWT(f[0][1]);
	for(i=1;i<=n;++i){
		memcpy(f[i][0],f[i-1][1],sizeof(int)*len);
		int *t=f[i][0];
		for(j=0;j<i;++j)
			for(k=0;k<len;++k)
				t[k]=(t[k]+1ll*f[j][1][k]*f[i-1-j][0][k])%MOD;
		memcpy(g,t,sizeof(int)*len);
		IFWT(g);
		rev(g,f[i][1]);
		FWT(f[i][1]);
	}
	IFWT(f[n][0]);
}
 
char ch[10010];
int back[10010],st[10010],top=0;
int head[10010],v[10010],nxt[10010],ty[10010],tot=0,cnt=0;
bool c[65536][2];
inline void add_edge(int s,int e){
	tot++;
	v[tot]=e;
	nxt[tot]=head[s];
	head[s]=tot;
}
void solve(int l,int r,int f){
	cnt++;
	int pre=cnt;
	if(f)add_edge(f,cnt);
	if(r==l+1||r==l){
		if(isdigit(ch[r])) ty[cnt]=ch[r]-'1';
		else ty[cnt]=K;
		return;
	}
	if(ch[l+1]=='~'){
		ty[cnt]=K+1;
		solve(l+2,r-1,cnt);
	}
	else{
		ty[cnt]=K+2;
		if(ch[l+1]=='('){
			solve(l+1,back[l+1],pre);
			solve(back[l+1]+3,r-1,pre);
		}
		if(ch[l+1]=='x'){
			solve(l+1,l+2,pre);
			solve(l+5,r-1,pre);
		}
		if(ch[l+1]=='Q'){
			solve(l+1,l+1,pre);
			solve(l+4,r-1,pre);
		}
	}
}
bool dfs(int k,int sta){
	if(ty[k]<=K){
		if(sta&(1<<ty[k]))return true;
		return false;
	}
	if(ty[k]==K+1)return !dfs(v[head[k]],sta);
	else{
		bool ans2=dfs(v[head[k]],sta);
		bool ans1=dfs(v[nxt[head[k]]],sta);
		return ((!ans1)|ans2);
	}
}
 
int Ans;
void search(int u,int sta){
	if(u==(1<<K)){
		Ans=(Ans+f[n][0][sta])%MOD;
		return;
	}
	if(c[u][0])search(u+1,sta);
	if(c[u][1])search(u+1,sta|(1<<u));
}
 
int main(){
	scanf("%d%d",&n,&K);
	len=(1<<(1<<K));
	DP();
	scanf("%d",&m);
	while(m--){
		cnt=0;tot=0;
		memset(head,0,sizeof(head));
		scanf("%s",ch+1);
		int L=strlen(ch+1);
		for(int i=1;i<=L;++i)
			if(ch[i]=='(')st[++top]=i;
			else if(ch[i]==')'){
				back[st[top]]=i;
				back[i]=st[top--];
			}
		solve(1,L,0);
		bool flag=1;
		for(int i=0;i<(1<<K);++i){
			c[i][0]=dfs(1,i);
			c[i][1]=dfs(1,i+(1<<K));
			if(c[i][0]==0&&c[i][1]==0){
				puts("0");
				flag=0;
				break;
			}
		}
		if(flag){
			Ans=0;
			search(0,0);
			printf("%d\n",Ans);
		}
	}
	return 0;
}
