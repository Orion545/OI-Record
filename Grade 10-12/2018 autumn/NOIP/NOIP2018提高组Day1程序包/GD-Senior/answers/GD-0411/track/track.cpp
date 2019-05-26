#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<climits>
#include<cctype>
#include<algorithm>
#include<queue>
#include<stack>
#include<string>
#include<set>
#include<map>
#include<vector>
using namespace std;
const int N=50005;
int n,m,u,v,d,cnt,l=1,r,mid,ans,tot,head[N],to[N*2],nxt[N*2],dd[N*2];
bool use[N];
namespace path{
	int ans,f[N][2];
	void dfs1(int pre,int u){
		int v;
		for(int i=head[u];i;i=nxt[i]){
			v=to[i];
			if(v!=pre){
				dfs1(u,v);
				if(f[v][0]+dd[i]>=f[u][0]){
					f[u][1]=f[u][0];
					f[u][0]=f[v][0]+dd[i];
				}else if(f[v][0]+dd[i]>f[u][1]){
					f[u][1]=f[v][0]+dd[i];
				}
			}
		}
		ans=max(ans,f[u][0]);
	}
	void dfs2(int pre,int u,int d){
		ans=max(ans,d+f[u][0]);
		int v;
		for(int i=head[u];i;i=nxt[i]){
			v=to[i];
			if(v!=pre){
				if(f[v][0]+dd[i]==f[u][0]){
					dfs2(u,v,max(d,f[u][1])+dd[i]);
				}else{
					dfs2(u,v,max(d,f[u][0]+dd[i]));
				}
			}
		}
	}
	int solve(){
		dfs1(0,1);
		dfs2(0,1,0);
		return ans;
	}
}
struct data{
	int x,y;
	data(){}
	data(int x,int y):x(x),y(y){}
	bool operator < (const data &n) const{
		return x==n.x?y<n.y:x<n.x;
	}
};
const double alpha=0.75;
int nc,ch[N*10][2],del[N*10],siz[N*10],sizt[N*10],pos[N*10];
data val[N*10];
struct tree{
	int *goat,root;
	tree(){root=0;}
	int rnk(data v){
		int k=root,res=1;
		while(k){
			if(val[k]<v){
				res+=siz[ch[k][0]]+del[k];
				k=ch[k][1];
			}else{
				k=ch[k][0];
			}
		}
		return res;
	}
	data kth(int x){
		int k=root;
		while(k){
			if(del[k]&&x==siz[ch[k][0]]+1){
				return val[k];
			}else if(x<=siz[ch[k][0]]+del[k]){
				k=ch[k][0];
			}else{
				x-=siz[ch[k][0]]+del[k];
				k=ch[k][1];
			}
		}
		return data(0,0);
	}
	void dfs(int k){
		if(!k){
			return;
		}
		dfs(ch[k][0]);
		if(del[k]){
			pos[++pos[0]]=k;
		}
		dfs(ch[k][1]);
	}
	void build(int &k,int l,int r){
		if(l>r){
			k=0;
			return;
		}
		int mid=(l+r)/2;
		k=pos[mid];
		build(ch[k][0],l,mid-1);
		build(ch[k][1],mid+1,r);
		siz[k]=sizt[k]=siz[ch[k][0]]+siz[ch[k][1]]+1;
	}
	void rebuild(int &k){
		pos[0]=0;
		dfs(k);
		build(k,1,pos[0]);
	}
	void insert(int &k,data v){
		if(!k){
			k=++nc;
			siz[k]=del[k]=sizt[k]=1;
			val[k]=v;
			ch[k][0]=ch[k][1]=0;
			return;
		}
		siz[k]++;
		sizt[k]++;
		if(v<val[k]){
			insert(ch[k][0],v);
		}else{
			insert(ch[k][1],v);
		}
		if(sizt[k]*alpha<max(sizt[ch[k][0]],sizt[ch[k][1]])){
			goat=&k;
		}
	}
	void insert(data v){
		goat=0;
		insert(root,v);
		if(goat){
			rebuild(*goat);
		}
	}
	void erase(int k,int x){
		if(del[k]&&x==siz[ch[k][0]]+1){
			del[k]=0;
			siz[k]--;
			return;
		}
		siz[k]--;
		if(x<=siz[ch[k][0]]+del[k]){
			erase(ch[k][0],x);
		}else{
			erase(ch[k][1],x-siz[ch[k][0]]-del[k]);
		}
	}
	void erase(data v){
		erase(root,rnk(v));
	}
	data lower_bound(data v){
		return kth(rnk(v));
	}
};
void adde(int u,int v,int d){
	to[++cnt]=v;
	nxt[cnt]=head[u];
	dd[cnt]=d;
	head[u]=cnt;
}
int dfs(int pre,int u){
	int v;
	vector<data> vec;
	tree st;
	for(int i=head[u];i;i=nxt[i]){
		v=to[i];
		if(v!=pre){
			int tmp=dfs(u,v)+dd[i];
			if(tmp>=mid){
				tot++;
				continue;
			}
			vec.push_back(data(tmp,v));
			st.insert(data(tmp,v));
		}
	}
	sort(vec.begin(),vec.end());
	int sz=vec.size();
	data tmp;
	for(int i=0;i<sz;i++){
		if(!use[vec[i].y]){
			st.erase(vec[i]);
			tmp=st.lower_bound(data(mid-vec[i].x,0));
			if(!tmp.y){
				st.insert(vec[i]);
				continue;
			}
			tot++;
			use[vec[i].y]=true;
			use[tmp.y]=true;
			st.erase(tmp);
		}
	}
	for(int i=sz-1;i>=0;i--){
		if(!use[vec[i].y]){
			return vec[i].x;
		}
	}
	return 0;
}
bool check(){
	memset(use,0,sizeof(use));
	nc=tot=0;
	dfs(0,1);
	return tot>=m;
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++){
		scanf("%d%d%d",&u,&v,&d);
		adde(u,v,d);
		adde(v,u,d);
	}
	r=path::solve();
	while(l<=r){
		mid=(l+r)/2;
		if(check()){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	printf("%d\n",ans);
	return 0;
}
