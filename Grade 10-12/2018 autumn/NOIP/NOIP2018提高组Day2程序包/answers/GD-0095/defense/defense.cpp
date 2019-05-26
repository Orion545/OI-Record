#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct type{
	char a;
	int b;
}Ty;
int n,m;
int p[100010],f[100010][2];
int last[100010],next[200000],to[200000];
int a,b,x,y,num;
int ans;
void add(int x,int y){
	next[++num]=last[x];
	last[x]=num;
	to[num]=y;
}
void gettype(){
	char c;
	c=getchar();
	while(c==' ')
		c=getchar();
	Ty.a=c;
	c=getchar();
	Ty.b=c-'0';
}
void get(int w,int fa){
	int sum0=0,sum1=0;
	for(int j=last[w];j;j=next[j]){
		if(to[j]!=fa){
			get(to[j],w);
			if((w==a&&x==0)||(w==b&&y==0)||(w!=a&&w!=b))
				sum0+=f[to[j]][1];
			if((w==a&&x==1)||(w==b&&y==1)||(w!=a&&w!=b))
				sum1+=min(f[to[j]][0],f[to[j]][1]);
		}
	}
	if(a==b)
		return ;
	if((w==a&&x==1)||(w==b&&y==1)||(w!=a&&w!=b)){
		f[w][1]=sum1+p[w];
		if(w==1)
			ans=min(ans,f[w][1]);
	}
	if((w==a&&x==0)||(w==b&&y==0)||(w!=a&&w!=b)){
		f[w][0]=sum0;
		if((w==a&&x==0)||(w==b&&y==0)){
			if(w==a){
				a=fa;
				x=1;
			}
			else{
				b=fa;
				y=1;
			}
		}
		
		if(w==1)
			ans=min(ans,f[w][0]);
	}
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);
	gettype();
	for(int i=1;i<=n;i++)
		scanf("%d",&p[i]);
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	for(int i=1;i<=m;i++){
		memset(f,0x7f,sizeof(f));
		ans=f[1][0];
		scanf("%d%d%d%d",&a,&x,&b,&y);
		get(1,0);
		if(ans!=f[0][0])
			printf("%d\n",ans);
		else printf("-1\n");
	}
	return 0;
}
