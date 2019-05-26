#include<cstring>
#include<cstdio>
#include<algorithm>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;i++)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;i--)
#define ll long long
using namespace std;
const int N=1e5+5;
int n,a[N],z[N],zs,s[N][2],ans;
void go(int ff,int v,int l,int r){
	ans+=a[v]-a[ff];
	if(s[v][0])go(v,s[v][0],l,v-1);
	if(s[v][1])go(v,s[v][1],v+1,r);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	fo(i,1,n){
		scanf("%d",&a[i]);
		for(;zs&&a[z[zs]]>a[i];zs--)s[z[zs-1]][1]=s[i][0]=z[zs];
		z[++zs]=i;
	}
	fo(i,1,zs-1)s[z[i]][1]=z[i+1];
	go(0,z[1],1,n);
	printf("%d",ans);
	fclose(stdin);fclose(stdout);return 0;
}
