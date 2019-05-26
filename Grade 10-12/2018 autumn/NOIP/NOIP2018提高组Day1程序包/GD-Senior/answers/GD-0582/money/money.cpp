#include <stdio.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
const bool local=0;
void read(int &x){
	int c;
	c=getchar();
	while((c<'0')||(c>'9'))c=getchar();
	x=0;
	while((c>='0')&&(c<='9')){
		x=x*10+(c^48);
		c=getchar();
	}
	return;
}
int T,f[25002],c[102],ans,mc,chong,j;
bool hc[25002];
int n,temp;
int main(){
	if (local){
		freopen("money2.in","r",stdin);
	}else{
		freopen("money.in","r",stdin);
		freopen("money.out","w",stdout);
	}
	read(T);
	while(T--){
		read(n);
		ans=0;
		mc=0;
		chong=0;
		memset(f,0,sizeof f);
		memset(hc,0,sizeof hc);
		f[0]=1;
		for (int i=0;i<n;++i) {
			j=i-chong;
			read(c[j]);
			if (c[j]>mc) mc=c[j];
			if (!hc[c[j]]) {
				hc[c[j]]=1;
			}else{
				++chong;
			}
		}
		if (hc[1]){
			printf("1\n");
			continue;
		}
		n-=chong;
		for (int v=1;v<=mc;++v)if(f[v]<=1){
			for (int i=0;i<n;++i){
				temp=c[i];
				if (v>=temp) {
					f[v]+=f[v-temp];
					if (f[v]>1) break;
				}
			}
		} 
		for (int i=0;i<n;++i) if (f[c[i]]==1) ++ans;
		printf("%d\n",ans);
	}
	return 0;
}
