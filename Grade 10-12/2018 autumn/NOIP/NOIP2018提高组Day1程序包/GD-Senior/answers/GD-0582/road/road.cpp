#include <stdio.h>
#include <stdlib.h>
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
int n,a,p,ans;
int main(){
	freopen("road.in","r",stdin);
	if (!local){
		freopen("road.out","w",stdout);
	}
	read(n);
	read(a);
	while(--n){
		read(p);
		if (p<a){
			ans+=a-p;
		}
		a=p;
	}
	ans+=p;
	printf("%d\n",ans);
	return 0;
}
