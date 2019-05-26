#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x;
}

bool cmp(int l,int r){
	return l<r;
}

int ans=0;
int a[101];
bool hehe[25001];
int n,t;

int main(){
	int i,j;
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	t=read();
	while(t){
		t--;
		memset(hehe,0,sizeof(hehe));
		ans=0;
		n=read();
		for(i=1;i<=n;i++){
			a[i]=read();
		}
		sort(a+1,a+1+n,cmp);
		for(i=1;i<=n;i++){
			if(hehe[a[i]]){
				continue;
			}
			ans++;
			hehe[a[i]]=true;
			for(j=1;j+a[i]<=a[n];j++){
				if(hehe[j]){
					hehe[j+a[i]]=true;
				}
			}
//			for(j=1;j<=a[n];j++){
//				printf("%d ",hehe[j]);
//			}			
//			printf("\n");
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}
