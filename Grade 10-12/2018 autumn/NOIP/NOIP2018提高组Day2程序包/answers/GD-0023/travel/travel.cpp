#include<cstdio>
using namespace std;
struct arr{
	int x,y,next;
}edge[12000];
int d[6000],tot,n,m,w,k[5100],s[5100],ls[5100];
bool p[5100],f[5100][5100];

int add(int x,int y){
	edge[++w].x=x; edge[w].y=y;
	edge[w].next=ls[edge[w].x]; ls[edge[w].x]=w;
	edge[++w].x=y; edge[w].y=x;
	edge[w].next=ls[edge[w].x]; ls[edge[w].x]=w;
}

int sss(int x){
	d[++tot]=x;
	for (int i=1;i<=n;i++)
		if (f[x][i]&&p[i]){
			p[i]=false;
			sss(i);
		}
}

int ss(int x,int y){
	if (s[1]!=0)
		for (int i=1;i<=y;i++)
			if (d[i]<s[i]) break;
			else if (d[i]>s[i]) return 0;
	if (y==n){
		bool f=true;
		if (s[1]!=0)
			for (int i=1;i<=n;i++)
				if (d[i]>s[i]){
					f=false;
					break;
				}
				else 
				if (d[i]<s[i]) break;
		if (f) 
			for (int i=1;i<=n;i++)
				s[i]=d[i];
		return 0;
	} 
	if (x!=1) ss(k[x],y);
	int i=ls[x];
	while (i!=0){
		if (p[edge[i].y]){
			p[edge[i].y]=false;
			k[edge[i].y]=x;
			d[y+1]=edge[i].y;
			ss(edge[i].y,y+1);
			p[edge[i].y]=true;
		}
		i=edge[i].next;
	}
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		f[x][y]=f[y][x]=true;
	}
	for (int i=1;i<=n;i++)
		p[i]=true;
	p[1]=false;
	d[1]=1;
	if (m==n-1){
		tot=0;
		sss(1);
		for (int i=1;i<=n;i++)
			printf("%d ",d[i]);
	}
	else{
		ss(1,1);
		for (int i=1;i<=n;i++)
			printf("%d ",s[i]);
	}
	printf("\n");
	fclose(stdin);fclose(stdout);
}
