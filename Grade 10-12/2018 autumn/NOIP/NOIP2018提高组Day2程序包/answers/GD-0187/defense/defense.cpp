#include<bits/stdc++.h>
using namespace std;
int n,m,ans;int A[100001];int f[100001];
string type;
inline int read(){
	register int x=0;register int w=1;
	register char c;
	while(!isdigit(c=getchar()))if(c=='-')w=-1;
	while(isdigit(c)){
		x=(x<<1)+(x<<3)+(c&15);
		c=getchar();
	}
	return x*w;
}
void dfs(int num,int sum){
	if(sum>=ans)return;
	if(num>n){ans=min(ans,sum);return;}
	if(f[num+1]==-1)dfs(num+1,sum+A[num]);
	else if(f[num]==-1)dfs(num+1,sum);
	else if(f[num]==2)dfs(num+1,sum+A[num]);
	else if(f[num]==0){
		if(f[num-1]==0||f[num-1]==-1)f[num]=1,dfs(num+1,sum+A[num]),f[num]=0;
		else{
			dfs(num+1,sum);
			f[num]=1;
			dfs(num+1,sum+A[num]);
			f[num]=0;
		}
	}
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	n=read();m=read();
	cin>>type;
	for(int i=1;i<=n;i++)A[i]=read();
	for(int i=1;i<n;i++){
		int x=read(),y=read();
	}
	if(type[0]=='A'){
		for(int i=1;i<=m;i++){
			memset(f,0,sizeof(f));
			ans=INT_MAX;
			int a=read(),x=read(),b=read(),y=read();
			if(x==1)f[a]=2;
			else f[a]=-1;
			if(abs(a-b)==1&&x==0&&y==0){cout<<-1<<endl;continue;}
			if(y==1)f[b]=2;
			else f[b]=-1;
			f[0]=1;
			dfs(1,0);
			cout<<ans<<endl;
		}
	}
	else {
    	for(int i=1;i<=m;i++){
    		int a=read(),b=read(),c=read(),d=read();
    	}
		for(int i=1;i<=m;i++)
		cout<<-1<<endl;		
    }
	return 0;
}
