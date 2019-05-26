#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int n,m,lim,a[1010][1010],sum[1010][1010];
int main(){
	char s[1010];
	n=read();m=read();lim=read();int i,j,k,cnt,tl,tr;
	for(i=1;i<=n;i++){
		scanf("%s",s);
		for(j=1;j<=m;j++){
			a[i][j]=(s[j-1]=='0');
			sum[i][j]=sum[i][j-1]+a[i][j];
		}
	}
	int l=1,r=1000,mid,flag;
	while(l<r){
		mid=(l+r)>>1;flag=0;mid++;
//		cout<<"do "<<mid<<'\n';
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				cnt=0;
//				cout<<"	centered "<<i<<' '<<j<<' '<<sqrt(mid)<<'\n';
				for(k=i-(int)sqrt((long double)mid);k<=i+(int)sqrt((long double)mid);k++){
					tl=j-(int)sqrt((long double)(mid-(i-k)*(i-k)));tr=j+(int)sqrt((long double)(mid-(i-k)*(i-k)));
//					cout<<"		row "<<k<<' '<<tl<<' '<<tr<<'\n';
					if(k<=0){cnt+=tr-tl+1;continue;}
					if(k>n){cnt+=tr-tl+1;continue;}
					if(tl<=0) cnt+=1-tl,tl=1;
					if(tr>m) cnt+=tr-m,tr=m;
					cnt+=sum[k][tr]-sum[k][tl-1];
					if(cnt>lim) break;
				}
//				cout<<"now cnt "<<cnt<<'\n';
				if(cnt<=lim){flag=1;break;}
			}
			if(flag==1) break;
		}
		if(flag) l=mid;
		else r=mid-1;
	}
	printf("%d\n",mid);
}
