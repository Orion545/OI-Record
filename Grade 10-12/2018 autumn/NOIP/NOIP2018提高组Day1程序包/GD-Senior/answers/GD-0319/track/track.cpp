#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<vector>
using namespace std;
struct edge{
	int t,l;
	edge (int a,int b){
		t=a; l=b;
	} 
};
vector<edge> a[50001];
int n,m,ex;
long long z,y,hf;
void swp(int &a,int &b){
	int c=a; a=b; b=c;
}
void kp(vector<int> &a,int z,int y){
	int i=z,j=y,n=a[(z+y)/2];
	while (i<=j){
		while (a[i]<n) i++;
		while (a[j]>n) j--;
		if (i<=j) swap(a[i++],a[j--]);
	}
	if (i<y) kp(a,i,y);
	if (z<j) kp(a,z,j);
}
long long cs(int fa,int x){
	vector<int> c; c.clear();
	for (int i=0;i<a[x].size();i++){
		if (a[x][i].t!=fa){
			c.push_back(a[x][i].l+cs(x,a[x][i].t));
			if (ex>=m) return 0;
		}
	}
	if (c.empty()) return 0;
	kp(c,0,c.size()-1);
	int z=0,y=c.size()-1;
	long long s=0;
	while (y>=z&&c[y]>=hf){ex++; y--;}
	while (z<=y){
		while ((z<y&&c[z]+c[y]<hf)||(z==y)){
			s=c[z];
			z++;
		}
		if (z<y){
			z++; y--;
			ex++;
		}
	}
	return s;
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	z=10000; 
	for (int i=1;i<n;i++){
		int xi,yi,zi;
		scanf("%d%d%d",&xi,&yi,&zi);
		a[xi].push_back(edge(yi,zi));
		a[yi].push_back(edge(xi,zi));
		y+=zi;
		if (zi<z) z=zi;
	}
	while (z<=y){
		hf=(z+y)/2;
		ex=0;
		cs(0,1);
		if (ex>=m) z=hf+1;
		else y=hf-1;
	}
	printf("%lld\n",y);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
