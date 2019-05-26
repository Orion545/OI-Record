#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
int n,q,f[301000],a[701000][2],d[301000][2],ly[301000],lb[301000],lb1,sd[301000];
int l,r,x,y;
void zf(int s){
	for(int k=s;a[k][0]!=0;k=a[k][1])
	if(a[k][0]!=ly[s]){
		lb1++;lb[lb1]=a[k][0];ly[a[k][0]]=s;sd[a[k][0]]=sd[s]+1;
	}
	return;
}
void dp(int s){
	if(s==ly[l]||s==ly[r]) return;
	int ans=0,ans1=f[s],k;
	for(k=s;a[k][0]!=0;k=a[k][1])
	if(a[k][0]!=ly[s]){
		dp(a[k][0]);
		ans+=d[a[k][0]][1];
		ans1+=min(d[a[k][0]][0],d[a[k][0]][1]);
	}
	d[s][0]=ans;d[s][1]=ans1;
	return;
}
void dp1(int s,int w,int e){
	int ans=0,ans1=f[s],k;
	if(w==1){
		for(k=s;a[k][0]!=0;k=a[k][1])
		if(a[k][0]!=ly[s]){
			dp(a[k][0]);
			ans+=d[a[k][0]][1];
			if(a[k][0]!=e)
			ans1+=min(d[a[k][0]][0],d[a[k][0]][1]);
			else ans1+=d[a[k][0]][1];
		}
		d[s][0]=ans;d[s][1]=ans1;
	}
	else{
		for(k=s;a[k][0]!=0;k=a[k][1])
		if(a[k][0]!=ly[s]){
			dp(a[k][0]);
			if(a[k][0]!=e)
			ans1+=min(d[a[k][0]][0],d[a[k][0]][1]);
			else ans1+=d[a[k][0]][0];
		}
		d[s][1]=ans1;d[s][0]=ans1;
	}
	return;
}
void dp2(int s){
	int ans=0,ans1=f[s],k;
	if(x==1&&y==1){
		for(k=s;a[k][0]!=0;k=a[k][1])
		if(a[k][0]!=ly[s]){
			dp(a[k][0]);
			ans+=d[a[k][0]][1];
			if(a[k][0]!=l&&a[k][0]!=r)
			ans1+=min(d[a[k][0]][0],d[a[k][0]][1]);
			else ans1+=d[a[k][0]][1];
		}
		d[s][0]=ans;d[s][1]=ans1;
	}
	else{
		for(k=s;a[k][0]!=0;k=a[k][1])
		if(a[k][0]!=ly[s]){
			dp(a[k][0]);
			if(a[k][0]!=l&&a[k][0]!=r)
			ans1+=min(d[a[k][0]][0],d[a[k][0]][1]);
			else{
			if(a[k][0]==l) ans1+=d[a[k][0]][x];
			else ans1+=d[a[k][0]][y];	
			}
		}
		d[s][1]=ans1;d[s][0]=ans1;
	}
	return;
}
void sr(){
	string s;
	scanf("%d%d",&n,&q);cin>>s;
	int i,j,k,x,y,p=n+1;
	for(i=1;i<=n;i++){
		a[i][0]=0;scanf("%d",&f[i]);
	}
	for(i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		a[p][0]=a[x][0];
		a[p][1]=a[x][1];
		a[x][0]=y;
		a[x][1]=p;
		p++;
		a[p][0]=a[y][0];
		a[p][1]=a[y][1];
		a[y][0]=x;
		a[y][1]=p;
		p++;
	}
	lb1=1;lb[1]=1;sd[1]=1;ly[1]=0;
	for(i=1;i<=lb1;i++)zf(lb[i]);
	dp(1);
	return;
}
int pd(int l,int x,int r,int y){
	if(x==1||y==1)return 0;
	for(int k=l;a[k][0]!=0;k=a[k][1])
	if(a[k][0]==r){
		printf("%d\n",-1);return -1;
	}
	return 0;
}

void cl(){
	for(;q>0;q--){
		scanf("%d%d%d%d",&l,&x,&r,&y);
		if(pd(l,x,r,y)==0){
			if(ly[l]==ly[r]) dp2(ly[l]);
			else
			if(sd[l]>=sd[r]){
			dp1(ly[l],x,l);
			dp1(ly[r],y,r);	
			}
			else
			if(sd[r]>sd[l]){
			dp1(ly[r],y,r);	
			dp1(ly[l],x,l);		
			}
			dp(1);printf("%d\n",min(d[1][0],d[1][1]));
		}
	}
	return;
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	sr();
	cl();
	return 0;
}
