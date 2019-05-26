#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,vi[5085],top,flag=0,flag2=0,cnt=0,f,mp[5085][5085],ans[5088],fa[5089],fro[5087],r[5086];
int a=0,b=0;
void addEdge(int x,int y){
	mp[x][0]++;
	mp[x][mp[x][0]]=y;
}
int getf(int x){
	if(fa[x]==x)return x;
	int k=getf(fa[x]);
	fa[x]=k;
	return k;
}
void mer(int x,int y){
	fa[getf(x)]=getf(y);
}
void dfs(int x){
	vi[x]=1;
	for(int i=1;i<=mp[x][0];i++){
		if(!vi[mp[x][i]]){
			top++;
			fro[mp[x][i]]=x;
			ans[top]=mp[x][i];
			dfs(mp[x][i]);
		}
		else{
			if((fro[x]!=mp[x][i])&&(!flag)){
				int k=x;
				r[mp[x][i]]=1;
				while(k!=mp[x][i])r[k]=1,k=fro[k];
				flag=1;
			}
		}
	}
}
void dfs2(int x){
	vi[x]=1;
	if(r[x]&&(!flag)){
		if(!flag2)
			for(int i=1;i<=mp[x][0];i++){
				if(r[mp[x][i]]&&(mp[x][i]!=x)){
					if(!a)a=mp[x][i];
					else b=mp[x][i];
					flag2=1;
					f=x;
				}
			}
		//printf("[%d,%d]\n",a,b);
		if(mp[x][0]>2||cnt){
			for(int i=1;i<=mp[x][0];i++)
				if(!vi[mp[x][i]]){
					top++;
					ans[top]=mp[x][i];
					if(x!=f&&mp[x][i]<b)cnt++;
					dfs2(mp[x][i]);
					if(x!=f&&mp[x][i]<b)cnt--;
			}
		}
		else{
			if((mp[x][1]>b&&(!vi[mp[x][1]])) || (vi[mp[x][1]]&&mp[x][2]>b&&(!vi[mp[x][2]]))){
				flag=1;
				top++;
				ans[top]=b;
				dfs2(b);
			}
				for(int i=1;i<=mp[x][0];i++)
				if(!vi[mp[x][i]]){
				top++;
				ans[top]=mp[x][i];
				dfs2(mp[x][i]);
			}
		}
	}
	else{
		for(int i=1;i<=mp[x][0];i++)
			if(!vi[mp[x][i]]){
				top++;
				ans[top]=mp[x][i];
				dfs2(mp[x][i]);
			}
	}
	//for(int i=1;i<=mp[x][0];i++){
		
	//}
	
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	top=0;
	memset(mp,0,sizeof(mp));
	for(int i=1;i<=m;i++){
		int xx,yy;
		scanf("%d%d",&xx,&yy);
		addEdge(xx,yy);
		addEdge(yy,xx);
	}
	for(int i=1;i<=n;i++){
		sort(mp[i]+1,mp[i]+1+mp[i][0]);
		vi[i]=0;
		fa[i]=i;
		r[i]=0;
	}
	ans[1]=1;top=1;
	dfs(1);
	for(int i=1;i<n;i++)printf("%d ",ans[i]);
	printf("%d",ans[n]);
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=mp[i][0];j++)printf("%d ",mp[i][j]);
		cout<<endl;
	}*/
	
	fclose(stdin);fclose(stdout);
	return 0;	
}
