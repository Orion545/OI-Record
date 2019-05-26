#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;	
struct vn{
	int x,y,l;
}v[50009];
int n,m,c1=1,c2=1;
bool cmp1(vn x,vn y){
	return(x.l>=y.l);
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++){
		scanf("%d%d%d",&v[i].x,&v[i].y,&v[i].l);
		if(v[i].x!=1)c1=0;
		if(v[i].y-v[i].x!=1)c2=0;
	}
	if(c1){
		sort(v+1,v+n,cmp1);
		//for(int i=1;i<n;i++)printf("%d ",v[i].l);
		if(m<=(n-1)/2){
			int a,mmin=19260817;
			for(int i=1;i<=m;i++){
				a=v[i].l+v[m*2+1-i].l;
				if(a<mmin)mmin=a;
			}
			printf("%d",mmin);
		}
		else{
			int a,mmin;
			n--;
			mmin=v[m*2-n].l;
			for(int i=m*2-n+1;i<=m*3-n+1;i++){
				a=v[i].l+v[2*m+1-i].l;
				if(a<mmin)mmin=a;
			}
			printf("%d",mmin);
		}
	}
	else if(c2){
		int b[50003],sum=0;
		for(int i=1;i<n;i++){
			b[v[i].x]=v[i].l;
			sum+=b[v[i].x];	
		}
		int l=0,r=sum/m,mid=(l+r)/2;
		while(l<r){
			int t1=0,t2=m,t3=sum;
			for(int i=1;i<n;i++){
				if(t2==1)break;
				t1+=b[i];
				t3-=b[i];
				if(t1>=mid){
					t2--;
					t1=0;
				}
			}
			if(t3<mid)r=mid-1;
			if(t3>=mid)l=mid+1;
			mid=(l+r)/2;
		}
		printf("%d",r);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
