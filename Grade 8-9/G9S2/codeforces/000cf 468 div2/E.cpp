#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char ss[5010];
int n,a[10010];
int cnt[30][5010][30];//第1个字母是i，第二个问j，答案是k的总数 
int num[30],tot;
int main(){
	int i,j,tmp,tt,k;double ans=0.0,tmax;
	scanf("%s",ss);n=strlen(ss);
	for(i=1;i<=n;i++) a[i]=ss[i-1]-'a'+1;
	for(i=1;i<=n;i++) a[i+n]=ss[i-1]-'a'+1;
	for(i=1;i<=n;i++){
		num[a[i]]++;
		if(num[a[i]]==1) tot++;
		for(j=2;j<=n;j++){
			cnt[a[i]][j][a[i+j-1]]++;
		}
	}
//	cout<<"tot "<<tot<<endl;
	for(i=1;i<=26;i++){
		if(num[i]==0) continue;
//		cout<<"getans "<<num[i]<<endl;
		if(num[i]==1){
			ans+=1.0/(double)n;continue;
		}
		tmax=0.0;
		for(j=2;j<=n;j++){
			tmp=tt=0;
			for(k=1;k<=26;k++){
				if(cnt[i][j][k]) tt+=cnt[i][j][k];
				if(cnt[i][j][k]==1) tmp++;
			}
			if(tt==0) continue;
//			cout<<"	vis "<<j<<ends<<tmp<<ends<<tt<<endl;
			tmax=max(tmax,(double)tmp/(double)tt);
		}
//		cout<<"tmax:"<<tmax<<endl;
		ans+=((double)num[i]/(double)n)*tmax;
//		cout<<"new ans "<<ans<<endl;
	}
	printf("%lf\n",ans);
}
