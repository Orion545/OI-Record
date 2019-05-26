#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int n,m,x,y,ec,ccc;
vector<int> a[5010];
int ai[5010],l[5010];
bool p[5010],ir[5010];
bool pc=0;
void swp(int &x,int &y){
	int c=x; x=y; y=c;
}
void kp(vector<int> &a,int z,int y){
	int i=z,j=y,n=a[(z+y)/2];
	while (i<=j){
		while (a[i]<n) i++;
		while (a[j]>n) j--;
		if (i<=j) swp(a[i++],a[j--]);
	}
	if (i<y) kp(a,i,y);
	if (z<j) kp(a,z,j);
}

void gogo(int x){
	p[x]=1;
	if (x!=ec) printf("%d ",x);
	while (ai[x]<a[x].size()){
		if (!p[a[x][ai[x]]]) gogo(a[x][ai[x]]);
		ai[x]++;
	}
}

void r6(int x){
	p[x]=1; int c=0;
	if (x!=ec) printf("%d ",x);
	while (ai[x]<a[x].size()){
		if (!p[a[x][ai[x]]])
	    	if (!ir[a[x][ai[x]]]) gogo(a[x][ai[x]]);
	    	else c=a[x][ai[x]];
	    ai[x]++;
	}
	if (c>0) r6(c);
}
void fr(int fa,int x){
	p[x]=1;
	l[++l[0]]=x;
	for (int i=0;i<a[x].size();i++){
		if (a[x][i]==fa) continue;
	    if (!p[a[x][i]]){
	    	fr(x,a[x][i]);
	    	if (pc==1) break;
	    }
		else{
			for (int j=l[0];j>=1;j--){
				ir[l[j]]=1;
				if (l[j]==a[x][i]) break;
			}
        	pc=1;
			break;
		}
	}
	l[0]--;
	p[x]=0;
}
void rd(int xc){
	p[xc]=1;
	printf("%d ",xc);
	memset(l,0,sizeof(l));
			while (p[a[xc][ai[xc]]]||((ai[xc]<a[xc].size())&&!ir[a[xc][ai[xc]]])){
				if (!p[a[xc][ai[xc]]]) gogo(a[xc][ai[xc]]);
				ai[xc]++;
			}
			x=a[xc][ai[xc]]; 
			p[x]=1; printf("%d ",x);
			l[0]=1; l[1]=xc; ai[xc]++;
			while (p[a[x][ai[x]]] ||(a[x][ai[x]]<a[l[l[0]]][ai[l[l[0]]]])&&(ai[x]<a[x].size())){
				if (p[a[x][ai[x]]]){
					ai[x]++;
					continue;
				}
				if ((ai[xc]<a[xc].size())&&!ir[a[x][ai[x]]]){
					if (!p[a[x][ai[x]]]) gogo(a[x][ai[x]]);
					ai[x]++;
				}
				else{
					ai[x]++;
					if (ai[x]<a[x].size()){
						l[++l[0]]=x;
					}
					x=a[x][ai[x]-1];
					p[x]=1;
					if (x!=ec) printf("%d ",x);
				}
			}
			for (int i=l[0];i>1;i--){
				while (ai[l[i]]<a[l[i]].size()){
					gogo(a[l[i]][ai[l[i]]]);
					ai[l[i]]++;
				}
			}
			ec=x;
			p[ec]=0;
			while (ai[xc]<a[xc].size()){
				if (p[a[xc][ai[xc]]]){
					ai[xc]++;
					continue;
				}
				if (!ir[a[xc][ai[xc]]]){
					gogo(a[xc][ai[xc]]);
				}
				else{
					if (ai[ec]<a[ec].size()-1) r6(a[xc][ai[xc]]);
					else gogo(a[xc][ai[xc]]);
				}
				ai[xc]++;
			}
}
void gogo2(int x){
	p[x]=1;
	printf("%d ",x);
	while (ai[x]<a[x].size()){
		if (!p[a[x][ai[x]]]){
			if (ir[a[x][ai[x]]]) rd(a[x][ai[x]]);
			else gogo2(a[x][ai[x]]);
		}
		ai[x]++;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		a[x].push_back(y);
		a[y].push_back(x);
    }
    for (int i=1;i<=n;i++) kp(a[i],0,a[i].size()-1);
	if (m<n) gogo(1);
	else{
		fr(0,1);
		if (!ir[1]) gogo2(1);
		else{
			rd(1);
		}
	}
	fclose(stdin);
	fclose(stdout);
}
