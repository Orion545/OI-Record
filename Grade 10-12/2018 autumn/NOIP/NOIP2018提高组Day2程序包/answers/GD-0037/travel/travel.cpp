#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int h[5002],pre[5002],point[5002];
int father[10002],l[10002],b[10002];
int ban[5002],huan[5002];
int lie[5002][5002],big[5002],d[5002];
int n,m,p,q,lca,tot=0,step;

void dfs(int t){
	int i;
	for (i=h[t]; i; i=pre[i])
		if (point[i]!=father[t]){
			if (b[point[i]]){
				p=point[i]; q=t;
				huan[++tot]=i;
				
    	        continue;
			}
			father[point[i]]=t;
			l[point[i]]=i;
			b[point[i]]=1;
			d[point[i]]=d[t]+1;
			dfs(point[i]);
		}
	return;
}

int search(int t,int y){
	int k=t,j=y,i;
	if (d[t]>d[y]){
		for (i=1; i<=d[t]-d[y]; i++)
			k=father[k];
	}
	else{
		for (i=1; i<=d[y]-d[t]; i++){
			j=father[j];
		}
	}
	while (k!=j){
		k=father[k];
		j=father[j];
	}
	return k;
}

void dfs2(int t,int w){
	int i,num=0;
	int xu[5002];
	b[t]=1;
	for (i=h[t]; i; i=pre[i])
	    if ((!ban[i]) && (!b[point[i]])){
		    xu[++num]=point[i];
		    b[point[i]]=1;
	    }
	sort(xu+1,xu+num+1);
	for (i=1; i<=num; i++){
		lie[w][++step]=xu[i];
		dfs2(xu[i],w);
	}
	return;
}

void com(int t){
	int i,j;
	for (i=1; i<n; i++){
		if (big[i]>lie[t][i]){
			for (j=1; j<n; j++)
			    big[j]=lie[t][j];
			break;
		}
		if (big[i]<lie[t][i]) break;
	}
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int i,u,v,j;
	scanf("%d%d",&n,&m);
	for (i=1; i<=m; i++){
		scanf("%d%d",&u,&v);
		point[2*i-1]=v; pre[2*i-1]=h[u]; h[u]=2*i-1;
		point[2*i]=u; pre[2*i]=h[v]; h[v]=2*i;
	}
	b[1]=1; dfs(1); lca=search(p,q);
    tot=1;
    while (p!=lca){
    	huan[++tot]=l[p];
    	p=father[p];
    }
    while (q!=lca){
    	huan[++tot]=l[q];
    	q=father[q];
    }
    big[1]=5002;
    for (i=1; i<=tot; i++){
    	memset(b,0,sizeof(b));
    	step=0;
    	ban[huan[i]]=1;
    	if (huan[i]%2==1) ban[huan[i]+1]=1;
    	else ban[huan[i]-1]=1;
    	dfs2(1,i); 
    	ban[huan[i]]=0;
    	if (huan[i]%2==1) ban[huan[i]+1]=0;
    	else ban[huan[i]-1]=0;
    	com(i);
    	
    }    
    printf("1 ");
    for (i=1; i<n; i++)
        printf("%d ",big[i]);
    printf("\n");
    return 0;
}








