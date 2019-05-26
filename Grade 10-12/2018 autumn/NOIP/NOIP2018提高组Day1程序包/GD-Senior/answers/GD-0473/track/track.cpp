//¶þ·Ö´ð°¸ 
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>

using namespace std;

struct node{int to,next,dis;}e[100020],e2[100020];
bool flag1=false,flag2=false;
bool vis[100020];
bool vis2[100020];
int n,m,cnt,sum[100020],need=0,head2[100020],cnt2,head[100020];
int a,b,c,all=0,maxn=-324320328,fro=1;
//inline int read(){
//	int sum=0;bool flag=false;char c=getchar();
//	while(c<'0'||c>'9') {if(c=='-') flag=true; c=getchar();}
//	while(c>='0'&&c<='9') {sum=(sum<<1)+(sum<<3)+c-'0';c=getchar();}
//	return ((flag)?-sum:sum);
//	
//}
bool cmp(node a,node b){
	return a.dis>b.dis;
}
//inline bool chk(int x){
//	
//	
//}
inline void chk2(int x,int st){
	int have=0;
	if(need==0) return ;
//	cout << " ffd " << st << endl;
	for(int i=st+1;i<=n;i++){
		if(have<x) have=sum[i]-sum[st];
		if(have>=x) {need--;chk2(x,i);break;}
	}
}
bool ju=false;
inline void dfs1(int st){
	if(ju) return ;
	int have=0;
	vis2[st]=true;
	for(int i=head[st];i;i=e[i].next){
		int u=e[i].to;
		have++;
		if(!vis2[u]){
			vis2[u]=true;
			
			dfs1(u);
			vis2[u]=false;
		}
	}
	if(have==1) fro=st,ju=true;//,cout << "SDF" << endl
	vis2[st]=false;	
}
inline void dfs(int st,int now){
	vis[st]=true;
	for(int i=head[st];i;i=e[i].next){
		int u=e[i].to;
		if(!vis[u]){
			vis[u]=true;
			if(maxn<now+e[i].dis) maxn=now+e[i].dis;
			dfs(u,now+e[i].dis);
			vis[u]=false;
		}
		
	}
	vis[st]=false;
	return ;
}

int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d",&n);scanf("%d",&m);
	for(int i=1;i<n;i++){
		scanf("%d",&a);scanf("%d",&b);scanf("%d",&c);all+=c;
		if(a!=1) flag1=true;
		if(b!=(a+1)) flag2=true;
		sum[i+1]=sum[i]+c;
		e[++cnt].to=b;e[cnt].next=head[a];e[cnt].dis=c;head[a]=cnt;
		e2[++cnt2].to=b;e2[cnt2].next=head2[a];e2[cnt2].dis=c;head2[a]=cnt2;
		e[++cnt].to=a;e[cnt].next=head[b];e[cnt].dis=c;head[b]=cnt;
	}
	if(!flag1){
		sort(e2+1,e2+cnt+1,cmp);
//		for(int i=1;i<=cnt2;i++) cout << e2[i].dis << "  --> ";
		int ans=e2[m].dis;
		printf("%d",ans);
	}
	else if(!flag2){
		int l=0,r=all,mid=0,ans2=-100;
		while(l<=r){
			mid=(l+r)>>1;
			need=m;
			chk2(mid,1);
			if(need<=0){
				l=mid+1;
				ans2=mid;
			}
			else{
				r=mid-1;
//				cout << "s2b : " << need << endl;
			}
		}	
		printf("%d",ans2);		
	}	
	else if(m==1){
//		memset(vis,false,sizeof(vis));
		dfs1(1);
//		cout << "s2 : " << fro << endl;
		dfs(fro,0);
		printf("%d",maxn);
	}
	else{
//		int l=0,r=all,mid=0,ans1=-100;
//		while(l<=r){
//			mid=(l+r)>>1;
//			if(chk(mid)){
//				
//			}
//			else{
//				
//			}
//		}		
	}

	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}







