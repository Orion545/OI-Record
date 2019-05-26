#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const ll N=5e4+10;
ll mp[N*2][2],t[N*2],lst[N],rt,ln;
ll f[N][2],cnt[N],Len,mid,tot,ans,n,m;
ll d[N*4],bz[N],ds[N],de[N],b1,b2,b3,b4;
void dfs(ll x,ll la){
	ll st=d[0];
	f[x][1]=f[x][0]=0;
	ll mx1=0,mx2=0,b1,b2;
	for(ll c=lst[x];c;c=t[c]){
		ll y=mp[c][1];
		if(y==la)continue;
		dfs(y,x);
		if(!mx1){
			mx1=y;
			b1=mp[c][0];
		}else{
			mx2=y;
			b2=mp[c][0];
		}
	}
	if(cnt[x]==1){
		f[x][1]=f[x][0]=0;
		return;
	}
	if(cnt[x]>=3){
		if(x==5){
			ll xxx=0;
		}
		ll o=0;
		f[x][1]=f[mx1][1]+f[mx2][1];
		if(f[mx1][0]+b1>=Len)f[x][1]++,o+=1;
		if(f[mx2][0]+b2>=Len)f[x][1]++,o+=2;
		if(o==3){
			f[x][0]=0;
			return;
		}
		if(!o){
			if(f[mx1][0]+b1+f[mx2][0]+b2>=Len){
				f[x][1]++;f[x][0]=0;
				return;
			}else{
				f[x][0]=max(f[mx1][0]+b1,f[mx2][0]+b2);
				return;
			}
		}
		if(o==1)mx1=mx2,b1=b2;
		f[x][0]=f[mx1][0]+b1;
	}
	if(cnt[x]==2){
		f[x][1]=f[mx1][1];
		if(f[mx1][0]+b1>=Len){
			f[x][1]++;
			f[x][0]=0;
			return;
		}else
			f[x][0]=f[mx1][0]+b1;
	}
}
bool pd(ll mid,ll bz){
	if(bz==1){
		ll ret=0,sum=0,st=1;
		for(ll i=2;i<=n;i++){
			sum=de[i]-de[st];
			if(sum>=mid){
				ret++;sum=0;
				st=i;
			}
		}
		return (ret>=m);
	}
	if(bz==2){
		cnt[rt]++;
		dfs(rt,0);
		cnt[rt]--;
		return (f[rt][1]>=m);
	}
}
void work(ll bz){
	ll l=0,r=tot/m,mid;
	while(l<=r){
		mid=l+r>>1;
		Len=mid;
		if(!pd(mid,bz)){
			r=mid-1;
		}else{
			l=mid+1;
			ans=mid;
		}
	}
}
void gt(){
	for(ll c=lst[1];c;c=t[c])
		ds[mp[c][1]]=mp[c][0];
}
void add(ll x,ll y,ll z){
	mp[++ln][1]=y;mp[ln][0]=z;
	t[ln]=lst[x];lst[x]=ln;
}
ll dt[N*4];
ll Bfs(ll a){
	memset(ds,127,sizeof(ds));
	ll en=1;
	dt[1]=a;
	ds[a]=0;
	ds[0]=0;
	ll ret=0;
	for(ll st=1;st<=en;st++){
		ll x=dt[st];
		for(ll c=lst[x];c;c=t[c]){
			ll y=mp[c][1];
			if(ds[x]+mp[c][0]<ds[y]){
				ds[y]=ds[x]+mp[c][0];
				dt[++en]=y;
				if(ds[y]>ds[ret])ret=y;
			}
		}
	}
	return ret;
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	tot=0;
	b1=b2=b3=b4=0;
	if(m!=1)b1=1;
	for(ll i=1;i<=n-1;i++){
		ll x,y,z;
		scanf("%lld%lld%lld",&x,&y,&z);
		de[y]=z;
		if(y!=x+1)b3=1;
		if(x!=1)b2=1;
		add(x,y,z);add(y,x,z);
		cnt[x]++;cnt[y]++;
		tot+=z;
	}
	for(ll i=2;i<=n;i++)de[i]+=de[i-1];
	for(ll i=1;i<=n;i++){
		if(cnt[i]>3)b4=1;
	}
	if(!b1){
		ll p=Bfs(1);
		ll q=Bfs(p);
		printf("%lld",ds[q]);
		return 0;
	}
	if(!b2){
		gt();
		ans=1<<30;
		sort(ds+1,ds+n+1);
		if(m<=(n-1)/2){
			for(ll i=n,j=n-(m*2)+1;i>j;i--,j++){
				ans=min(ans,ds[i]+ds[j]);
			}
		}else{
			ll p=m*2-(n-1);
			ans=ds[n-p+1];
			for(ll i=2,j=n-p;i<j;i++,j--){
				ans=min(ans,ds[i]+ds[j]);
			}
		}
		printf("%lld",ans);
		return 0;
	}
	if(!b3){
		work(1);
	}
	if(!b4){
		for(ll i=1;i<=n;i++){
			if(cnt[i]<=2){
				rt=i;break;
			}
		}
		work(2);
	}
	printf("%lld",ans);
	return 0;
}
