#include<stdio.h>
int n,m,i,j,v[100005],h[100005],a,b,x,y,w[100005],dan[100005],shu[100005],s;
char c[5];
struct ha{
	int a,b,n;
}d[200005];
void charu(int a,int b){
	d[++j].a=a,d[j].b=b;
	d[j].n=h[a],h[a]=j;
	d[++j].a=b,d[j].b=a;
	d[j].n=h[a],h[a]=j;
}
void dfs(int a){
	int i,b;
	if(v[a]%2)dan[a]+=w[a];
	else shu[a]+=w[a];
	for(i=h[a];i;i=d[i].n){
		b=d[i].b;
		if(!v[b]){
			v[b]=v[a]+1;
			dfs(b);
			dan[a]+=shu[b];
			shu[a]+=dan[b];
		}
	}
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d %d %s",&n,&m,c);
	if(c[0]=='A'){
		for(i=1;i<=n;i++){
			scanf("%d",&w[i]);
			if(i%2)w[0]+=w[i];
			else s+=w[i];	
		}
		for(i=1;i<n;i++)scanf("%d%d",&x,&y);
		if(c[1]=='1'){
			for(i=1;i<=m;i++){
				scanf("%d%d%d%d",&x,&y,&a,&b);
				if((a%2)==1){	
					if(b==1)printf("%d\n",w[0]);
					else printf("-1\n");
				}
				else{
					if(b==0)printf("%d\n",w[0]);
					else printf("-1\n");
				}
			}			
		}
		else{
			for(i=1;i<=m;i++){
				scanf("%d%d%d%d",&x,&y,&a,&b);
				if((x%2)!=(a%2)){
					if(y==b){
						printf("-1\n");	
						continue;	
					}				
				}
				else {
					if(y!=b){
						printf("-1\n");
						continue;
					}	
				}
				if((a%2)==1){	
					if(b==1)printf("%d\n",w[0]);
					else printf("%d\n",s);
				}
				else{
					if(b==0)printf("%d\n",w[0]);
					else printf("%d\n",s);
				}				
			}			
		}
	}
	else{
		for(i=1;i<=n;i++){
			scanf("%d",&w[i]);	
		}
		for(i=1;i<n;i++){
			scanf("%d%d",&a,&b);
			charu(a,b);
		}
		v[1]=1,dfs(1);
		for(i=1;i<=m;i++){
			scanf("%d%d",&x,&y,&a,&b);
			if(c[1]=='1'){
				if(a%2&&b==0)printf("-1\n");
				else if(a%2&&b==1)printf("%d\n",dan[1]);
				else if(!(a%2)&&b==0)printf("%d\n",dan[1]);
				else printf("-1\n");
			}
		}
	}
	return 0;
}
