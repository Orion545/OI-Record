#include<bits/stdc++.h>
using namespace std;

int n;
long long ans=0;
int b[100002];

struct road{
	int num;
	int pos;
	int flag;
}a[100002];

bool cmp(const road x,const road y){
	if(x.num!=y.num){
		return x.num<y.num;
	}else{
		return x.pos<y.pos;
	}
}


void dfs(int l,int r,int yijian,int dangqianmin,int minpos){
	if(l>r){
		return;
	}
	
	if(l==r){
		ans+=dangqianmin;
		return;
	}
	ans+=dangqianmin;
	
	road find1,find2;
	int f1=0,f2=0;
	for(int i=1;i<=n;i++){
		int q=a[i].num-dangqianmin-yijian;
		if(a[i].flag==0 && q>0 && a[i].pos>=l && a[i].pos<=minpos-1){
			find1=a[i];
			a[i].flag==1;
			f1=1;
			break;
		}
	}
	for(int i=1;i<=n;i++){
		int q=a[i].num-dangqianmin-yijian;
		if(a[i].flag==0 && q>0 && a[i].pos>=minpos+1 && a[i].pos<=r){
			find2=a[i];
			a[i].flag==1;
			f2=1;
			break;
		}
	}
	if(f1==1)
		dfs(l,minpos-1,yijian+dangqianmin,find1.num-dangqianmin-yijian,find1.pos);
	if(f2==1)
		dfs(minpos+1,r,yijian+dangqianmin,find2.num-dangqianmin-yijian,find2.pos);
	return;
	
}

int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int input;
		scanf("%d",&input);
		b[i]=input;
		a[i].num=input;
		a[i].pos=i;
	}
	sort(a+1,a+n+1,cmp);
	
	a[1].flag=1;
	dfs(1,n,0,a[1].num,a[1].pos);
	
	cout<<ans;
	
	return 0;
}
