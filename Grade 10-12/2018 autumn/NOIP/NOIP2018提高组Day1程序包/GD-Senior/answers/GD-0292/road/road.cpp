#include<bits/stdc++.h>
using namespace std;
const int N=100010;

int n;
inline int rd(){
	char ch;int f=0,w=1;
	ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){f=f*10+(ch-'0');ch=getchar();}
	return f*w;
}
bool fl=true;
int fr,cnt=0;
struct hs{
	int up1,up2,z;
}b[N];
int a[N],upp=0,now,minn=10000000;
long long ans=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=rd();
	for(int i=1;i<=n;i++)a[i]=rd(),minn=min(minn,a[i]);
	for(int i=1;i<=n;i++)a[i]-=minn;ans=minn;
	fr=1;now=a[fr];
	for(int i=1;i<=n;i++){
		if(a[i]>=now&&i<=n){
		    while(a[i]>=now&&i<=n){
			    now=a[i];i++;
		    }
	    }
	    if(a[i]<now){
	    	b[++cnt].z=now;b[cnt].up1=a[fr];
		    while(a[i]<now&&i<=n){
			    now=a[i];i++;
		    }
		    fr=i-1;
		    b[cnt].up2=a[fr];
	    }
	    i=i-1;
	}
	for(int i=1;i<cnt;i++){
		ans+=(b[i].z-b[i].up2);
		b[i].up1=min(b[i].up1,max(0,b[i].up2));b[i+1].up1=min(b[i].up1,b[i+1].up1);
	}
	ans+=(b[cnt].z-min(b[cnt].up1,b[cnt].up2));
	printf("%lld",ans);
	return 0;
}
