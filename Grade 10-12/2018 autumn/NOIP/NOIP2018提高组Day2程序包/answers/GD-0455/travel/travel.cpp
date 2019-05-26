#include<iostream>
#include<cstdio>
using namespace std;
struct road{
	int to,lst;
};
int n,m,s[5000+5],i,t,f,p,l,fst[5000+5]={0},flag[5000+5]={0},xl[5000+5],x,mi;
road r[5000+5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(i=2;i<=2*m;i+=2){
		scanf("%d %d",&t,&f);
		
		r[i-1].to=t;r[i-1].lst=fst[f];fst[f]=i-1;
		
		r[i].to=f;r[i].lst=fst[t];fst[t]=i;
	}
	f=1;t=1;s[1]=1;flag[1]=1;
	xl[1]=1;x=1;mi=1;
	while(f<=t){
		p=s[f%5000];
		if(flag[p]==1){
			l=fst[p];
			while(l!=0){
				if(flag[r[l].to]==0)flag[r[l].to]=1;
				l=r[l].lst;
			}
			flag[p]=2;if(p==mi)mi++;
		}
		if(x!=n){
		         for(i=mi;i<=n;i++)if(flag[i]==1)break;
		         x++;xl[x]=i;
		         if(x==n)break;
		         t++;s[t%5000]=i;
		        }
		f++;
	}
	for(i=1;i<=n;i++)printf("%d ",xl[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
