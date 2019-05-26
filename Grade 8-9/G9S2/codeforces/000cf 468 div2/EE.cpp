#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define inf 1e9
using namespace std;
char s[200010];int a[200010],cnt[10],c[10];
int main(){
	int i,j,T,n,tot,now;
	cin>>T;
	while(T--){
		scanf("%s",s);n=strlen(s);tot=0;now=n-1;
		for(i=0;i<n;i++) a[i+1]=s[i]-'0',cnt[a[i+1]]++;
		for(i=0;i<10;i++) cnt[i]%=2,tot+=cnt[i];
		while(tot){
			if(tot>n-now) goto renew;
			if(cnt[a[now+1]-1]){
				cnt[a[now+1]-1]--;
				 
			}
			for(i=a[now+1]-2;i>=0;i--){
				if(cnt[i]){
					if((n-tot-now)%2==0){
						for(j=1;j<=now;j++) printf("%d",a[i]);
						printf("%d",i);now++;
						for(;now+tot-1<=n;now++) printf("9");
						for(j=9;j>=0;j--) 
							if(i!=j&&cnt[j]) printf("%d",j);
					}
				}
			}
			renew:
			tot-=cnt[now];cnt[now]=!cnt[now];tot+=cnt[now--];
		}
	}
}
