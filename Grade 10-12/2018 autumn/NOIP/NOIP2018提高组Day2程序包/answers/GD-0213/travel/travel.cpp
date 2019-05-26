#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,f;
int x[100000],y[100000],vn[100000],s[300000];
int book[100000],book1[100000],st[100000];
void dfsx(int v){
	if(book1[v]){
		f=v;
		return ;
	}
	printf("%d ",v);
	book[v]=1;
	for(int i=vn[v];i<vn[v+1];++i){
		if(book[s[i]]==0){
			dfsx(s[i]);
		}
	}
	return ;
}
void dfs2(int v,int l){
	printf("%d ",v);
	//cout<<v<<" "<<l<<endl;
	book[v]=1;
	int i,fx;
	for(i=vn[v];i<vn[v+1];++i){
		if(book[s[i]]==0&&book1[s[i]]==0){
			dfsx(s[i]);
		}
		if(book1[s[i]])break;
	}
	if(s[i]>l){
		for(;i<vn[v+1];++i){
			if(book[s[i]]==0&&book1[s[i]]==0){
				dfsx(s[i]);
			}
		}
		return ;
	}
	for(;i<vn[v+1];++i){
		if(book1[s[i]]&&book[s[i]]==0){
			fx=l;
			for(int j=i+1;j<vn[v+1];++j){
				if(book1[s[j]]==0&&book[s[j]]==0){
					//cout<<endl<<endl<<"ass"<<endl<<endl;
					if(s[j]<fx)
					fx=s[j];
				}
			}
			dfs2(s[i],fx);
		}
		if(book1[s[i]]==0&&book[s[i]]==0){
			dfsx(s[i]);
		}
	}
}
void dfs1(int v,int l,int step){
	if(book[v]){
		f=1;
		for(int i=book[v];i<step;++i)book1[st[i]]=1;
		return ;
	}
	book[v]=step;
	st[step]=v;
	for(int i=vn[v];i<vn[v+1];++i){
		if(s[i]!=l){
			dfs1(s[i],v,step+1);
		}
		if(f){
			break;
		}
	}
	book[v]=0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;++i){
		scanf("%d %d",x+i,y+i);
		vn[x[i]]++;
		vn[y[i]]++;
	}
	for(int i=1;i<=n+1;++i){
		vn[i]+=vn[i-1];
	}
	for(int i=0;i<m;++i){
		s[--vn[x[i]]]=y[i];
		s[--vn[y[i]]]=x[i];
	}
	for(int i=1;i<=n;++i){
		sort(s+vn[i],s+vn[i+1]);
	}
	dfsx(1);
	return 0;
}
