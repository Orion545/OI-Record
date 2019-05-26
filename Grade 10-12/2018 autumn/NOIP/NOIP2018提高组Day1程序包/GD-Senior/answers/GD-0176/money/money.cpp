#include<bits/stdc++.h>
#define maxval 25000
using namespace std;
int t,n,cnt,val[110];
bool o[maxval*2];
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		cnt=0;
		for(int i=1;i<=n;i++){scanf("%d",&val[i]);}
		for(int i=1;i<=maxval;i++){o[i]=false;}
		sort(val+1,val+n+1);
		o[0]=true;
		for(int i=1;i<=n;i++){
			if(o[val[i]]){continue;}
			cnt++;
			for(int j=val[i];j<=maxval;j++){if(o[j-val[i]]==true) o[j]=true;}
		}
		printf("%d\n",cnt);
	}
}
