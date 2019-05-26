#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
struct node{
	int s,x,next;
}l[1100010],r[1100010];
int n,a[30],firstl[10010],firstr[10010],totl,totr;
void dfs1(int k,int sum,int s){
//	cout<<k<<ends<<sum<<ends<<s<<endl;
	if(k==n/2+1){
		if(sum>=0){
			l[++totl].s=s;l[totl].x=sum;
			l[totl].next=firstl[s];firstl[s]=totl;
		}
		return;
	}
	dfs1(k+1,sum,s);
	dfs1(k+1,sum+a[k],s|(1<<(k-1)));
	dfs1(k+1,sum-a[k],s|(1<<(k-1)));
}
void dfs2(int k,int sum,int s){
	if(k==n/2){
		if(sum>=0){
			r[++totr].s=s;r[totr].x=sum;
			r[totr].next=firstr[s];firstr[s]=totr;
		} 
		return;
	}
	dfs2(k-1,sum,s);
	dfs2(k-1,sum+a[k],s|(1<<(n-k)));
	dfs2(k-1,sum-a[k],s|(1<<(n-k)));
}
bool vis[5001000]={0};
bool cmp(node x,node y){
	return x.x<y.x;
}
int main(){
	int i,p1,p2,tmp1,tmp2,ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	dfs1(1,0,0);dfs2(n,0,0);
	sort(l+1,l+totl+1,cmp);sort(r+1,r+totr+1,cmp);
//	cout<<endl<<endl;
//	for(i=1;i<=totl;i++) cout<<l[i].x<<ends<<l[i].s<<endl;
//	cout<<endl<<endl;
//	for(i=1;i<=totr;i++) cout<<r[i].x<<ends<<r[i].s<<endl;
//	cout<<endl<<endl;
	p1=1;p2=1;
	while(p1<=totl&&p2<=totr){
		if(l[p1].x>r[p2].x){
			p2++;continue;
		}
		if(l[p1].x<r[p2].x){
			p1++;continue;
		}
//		cout<<p1<<ends<<p2<<endl;
		tmp1=p1;tmp2=p2;
		while(l[p1].x==l[tmp1].x) p1++;
		while(r[p2].x==r[tmp2].x){
			for(i=tmp1;i<p1;i++){
				if(!vis[((r[p2].s)<<(n/2))|l[i].s]){
//					cout<<"	suc "<<p2<<ends<<i<<endl;
					ans++;vis[((r[p2].s)<<(n/2))|l[i].s]=1;
				}
			}
			p2++;
		}
	}
	printf("%d",ans-1);
}
