#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
#include<iostream>
using namespace std;

int dep[100005];
int st[18][100005],lg[100005];
int stn[18][100005];
int n,ans=0;

void init(){
	for(int i=0;i<n;i++){
		st[0][i]=dep[i];
		stn[0][i]=i;
	}
	double l2=log(2.0);
	for(int i=1;i<=n;i++){
		double l=log(i*1.0)/l2;
		//printf("lg%d=%lf\n",i,l);
		lg[i]=l;
	}
	for(int i=1;i<18;i++){
		for(int j=0;(j+(1<<i))<=n;j++){
			int a=st[i-1][j],b=st[i-1][j+(1<<(i-1))];
			if(a>b){
				st[i][j]=b;
				stn[i][j]=stn[i-1][j+(1<<(i-1))];
			}else{
				st[i][j]=a;
				stn[i][j]=stn[i-1][j];
			}
			//printf("st[%d][%d]=%d n=%d  y=%d\n",i,j,st[i][j],stn[i][j],(1<<(i-1)));
		}
	}
}

int q(int l,int r,int &dep,int &ind){
	int l2l=lg[r-l+1];
	//printf("q l=%d r=%d len=%d lg=%d\n",l,r,r-l+1,l2l);
	int a=st[l2l][l],b=st[l2l][r-(1<<(l2l))+1];
	if(a<b){
		dep=a;
		ind=stn[l2l][l];
	}else{
		dep=b;
		ind=stn[l2l][r-(1<<(l2l))+1];
	}
}

void dig(int l,int r,int curd){
	if(l>r)return;
	int dp,ind;
	q(l,r,dp,ind);
	int delta=dp-curd;
	//printf("cur=%d ind=%d l=%d r=%d curd=%d delt=%d\n",dp,ind,l,r,curd,delta);
	ans+=delta;
	dig(l,ind-1,dp),dig(ind+1,r,dp);
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d",&dep[i]);
	}
	init();
	dig(0,n-1,0);
	
	
	cout<<ans;
	
	return 0;
}
