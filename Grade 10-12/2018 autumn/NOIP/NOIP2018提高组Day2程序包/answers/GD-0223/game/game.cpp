#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
#define MM 1001010
#define N 10010
#define ll long long
#define itn int
int xx;int ff;char ch;
inline int read(){
	ch=getchar();ff=1;xx=0;
	while(ch<'0'||ch>'9'){
		if(ch=='-')ff=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		xx=(xx<<1)+(xx<<3)+ch-'0';
		ch=getchar();
	}
	return xx*ff;
}
int a[10][MM];
int n,m;
const int dir[4][2]={
	1,0,
	0,1,
};
ll ans=0;
bool ansf=0;
#define mo 1000000007
char r[3][200][1000108];
int ss=0;
char s[1000108],v[1000108];
int slen=0;
inline void judge(){
	/*cerr<<"judge"<<endl;
	for(int i=1;i<=slen;++i)cerr<<s[i]<<ends;
	cerr<<endl;*/
	
	bool flag=1;
	for(int j=1;j<=ss;++j){
		bool flag2=1;bool flag3=0;
		/*cerr<<"VVVVVV"<<ends;
		for(int i=1;i<=slen;++i)cerr<<r[1][j][i]<<ends;
		cerr<<endl;*/
		
		for(int i=1;i<=slen;++i){
			//cerr<<"c1 "<<r[1][j][i]<<" "<<v[i]<<endl;
			
			if(r[1][j][i]!=v[i]){
				flag2=(r[1][j][i]<=v[i]);
				break;
			}
		}
		//if(flag2){
			for(int i=1;i<=slen;++i){
				//cerr<<"c2 "<<r[0][j][i]<<" "<<s[i]<<endl;
				if(r[0][j][i]!=s[i]){
					flag3=r[0][j][i]>s[i];
					break;
				}
			}
		//}else{
		if(flag2^flag3){
			flag=0;
			//cerr<<"!!!!"<<flag2<<" "<<flag3<<endl;
			break;
		}
		//}
	}
	if(flag){
		//++ans;
		//if(ans>=mo)ans-=mo;
		//cerr<<"PASS "<<ends;
		//for(int i=1;i<=slen;++i)cerr<<s[i]<<ends;
		//cerr<<endl;
		++ss;
		for(int i=1;i<=slen;++i){
			r[0][ss][i]=(s[i]);
			r[1][ss][i]=(v[i]);
		}
		
	/*	cerr<<"VV"<<ends;
		for(int i=1;i<=slen;++i)cerr<<r[1][ss][i]<<
		" "<<s[i]<<endl<<ends;*/
		//r[1][ss]=(v);
		//for(int i=1;i<=slen;++i)cerr<<r[0][r[0].size()-1][i]<<ends;
		//cerr<<endl;
	}else{
		ansf=0;
		return;
	}
	
}
inline void dfs2(int x,int y){
	if(!ansf)return;
	if(x==n&&y==m){
		judge();
		return;
	}
	//cerr<<"D2 "<<x<<" "<<y<<endl;
	int nx,ny;
	for(int d=0;d<2;++d){
			nx=x+dir[d][0];
			ny=y+dir[d][1];
			if(nx>n||ny>m)continue;
			//s.push_back(d?'D':'R');
			//v.push_back(a[nx][ny]);
			s[++slen]=(d?'D':'R');
			//cerr<<s[slen]<<endl;
			v[slen]=a[nx][ny]+'0';
			//cerr<<s[slen]<<endl;
			dfs2(nx,ny);
			--slen;
	}
	
	return;
}

inline void dfs(int x,int y){
	//if(a[x][y]!=-1)return;
	if(x==n&&y==m){
		for(int i=0;i<2;++i){
			a[x][y]=i;
		//s="";
		//v="";
		slen=0;
		ansf=1;
		//r[0].clear();r[1].clear();
		ss=0;
		//cerr<<endl;///////////////////////////
		dfs2(1,1);
		/*cerr<<"C"<<endl;
		for(int i=1;i<=n;++i){
				for(int j=1;j<=m;++j){
					cerr<<a[i][j]<<" ";
				}
				cerr<<endl;
			}*/
		if(ansf){
			/*cerr<<"+Ans"<<endl;
			for(int i=1;i<=n;++i){
				for(int j=1;j<=m;++j){
					cerr<<a[i][j]<<" ";
				}
				cerr<<endl;
			}*/
			++ans;
			if(ans>=mo)ans-=mo;
		}
	}
		a[x][y]=-1;
		return;
	}
	int nx,ny;
	for(int i=0;i<2;++i){
		a[x][y]=i;
		for(int d=0;d<1;++d){
			nx=x+dir[d][0];
			ny=y+dir[d][1];
			if(nx>n){
				nx=1;++ny;
			}
			if(nx>n||ny>m||a[nx][ny]!=-1)continue;
			dfs(nx,ny);
		}
	}
	a[x][y]=-1;
	return;
}
inline ll ksm(ll a,ll b){
	ll base=a;
	ll ans=1;
	for(;b;b>>=1){
		if(b&1)ans=(ans*base)%mo;
		base=(base*base)%mo;
	}
	return ans;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read();m=read();
	if(n==1){
		printf("%lld\n",ksm((ll)2,m));
		return 0;
	}
	if(n==2){
		printf("%lld\n",(4*ksm((ll)3,m-1))%mo);
		return 0;
	}
	memset(a,-1,sizeof(a));
	ans=0;

	dfs(1,1);
	printf("%d\n",ans);

	fclose(stdin);fclose(stdout);
	return 0;
}
