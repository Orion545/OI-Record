#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<queue>
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
int n,m,k,A,B,bel[510],flag,ans;
int mp[110][110],dx[8],dy[8],d[110][110],ql[10010],qr[10010],in[110][110];
void solve(int num,int opx,int opy){
	int i,j,x,y,tx,ty,head=0,tail=1;
//	cout<<"solve "<<num<<' '<<opx<<' '<<opy<<'\n';
//	for(i=1;i<=k;i++) cout<<i<<' '<<bel[i]<<'\n';
	for(i=1;i<=n;i++) for(j=1;j<=m;j++){
		if(mp[i][j]==-1) in[i][j]=1;
		else in[i][j]=0;
		d[i][j]=1e9;
	}
//	for(i=1;i<=n;i++){
//		cout<<'	';
//		for(j=1;j<=m;j++) cout<<mp[i][j]<<' ';
//		cout<<'\n';
//	}
	ql[0]=opx;qr[0]=opy;in[opx][opy]=1;d[opx][opy]=0;
	while(head<tail){
		x=ql[head];y=qr[head];head++;
//		cout<<"	bfs "<<x<<' '<<y<<'\n';
		for(i=0;i<8;i++){
			tx=x+dx[i];ty=y+dy[i];
//			cout<<"		try "<<' '<<i<<' '<<dx[i]<<' '<<dy[i]<<' '<<tx<<' '<<ty<<' '<<in[tx][ty]<<'\n';
			if(tx<1||tx>n||ty<1||ty>m||in[tx][ty]) continue;
			d[tx][ty]=d[x][y]+1;
			in[tx][ty]=1;
			ql[tail]=tx;qr[tail]=ty;
			tail++;
		}
	}
	for(i=1;i<=n;i++) for(j=1;j<=m;j++){
		if(mp[i][j]!=bel[num]+k) continue;
//		cout<<"get pos "<<i<<' '<<j<<' '<<mp[i][j]<<' '<<d[i][j]<<'\n';
		if(d[i][j]>=1e9) flag=0;
		else ans+=d[i][j];
		return;
	}
}
int main(){
	memset(mp,0,sizeof(mp));
	n=read();m=read();k=read();A=read();B=read();int i,j,t2,t1,out=1e9;char s[110];
	dx[1]=dx[3]=dy[5]=dy[7]=A;
	dx[0]=dx[2]=dy[4]=dy[6]=-A;
	dy[0]=dx[4]=dy[1]=dx[5]=B;
	dy[2]=dx[6]=dy[3]=dx[7]=-B;
	for(i=1;i<=n;i++){
		scanf("%s",s);
		for(j=0;j<m;j++){
			if(s[j]=='*') mp[i][j+1]=-1;
		}
	}
	for(i=1;i<=k;i++){
		t1=read();t2=read();
		mp[t1][t2]=i;
	}
	for(i=1;i<=k;i++){
		t1=read();t2=read();
		mp[t1][t2]=i+k;
	}
	for(i=1;i<=k;i++) bel[i]=i;
	do{
		ans=0;flag=1;
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				if(mp[i][j]>=1&&mp[i][j]<=k)
					solve(mp[i][j],i,j);
				if(!flag) break;
			}
			if(!flag) break;
		}
//		cout<<"final "<<flag<<' '<<out<<' '<<ans<<'\n';
		if(flag) out=min(out,ans);
	}while(next_permutation(bel+1,bel+k+1));
	if(out<1e9) cout<<out<<'\n';
	else puts("-1");
}
