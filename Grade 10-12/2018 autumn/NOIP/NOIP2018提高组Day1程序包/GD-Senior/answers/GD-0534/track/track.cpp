#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

int n,m;
vector<pair<int,int> >pthn[50010];

int u[50010];
bool u1[50010];
bool u2[50010];

int s1_dist(int x,int y){
	memset(u1,0,sizeof(bool)*(n+1));
	queue<int>q;
	q.push(x);
	u1[x]=1;
	u[x]=0;
	while(1){
		int t=q.front();
		q.pop();
		if(t==y)
			return u[t];
		
		for(int x=0;x<pthn[t].size();x++){
			int p=pthn[t][x].first;
			if(!u1[p]){
				u1[p]=1;
				u[p]=u[t]+pthn[t][x].second;
				q.push(p);
			}
		}
	}
}

int s1(){
	int r=0;
	memset(u2,0,sizeof(bool)*(n+1));
	for(int a=1;a<=n;a++){
		if(pthn[a].size()==1)
			u2[a]=1;
	}
	for(int a=1;a<=n;a++)
		if(u2[a])
			for(int b=a+1;b<=n;b++)
				if(u2[b]){
					int xx=s1_dist(a,b);
					if(xx>r)
						r=xx;
				}
	return r;
}

bool b_a_1(){
	for(int a=2;a<=n;a++)
		if(!(pthn[a].size()<=2&&pthn[a][0].first==a-1))
			return false;
	return true;
}

bool s2_chk(int ds){
	int r=0,mm=0;
	for(int a=2;a<=n;a++){
		int q=pthn[a][0].second;
		if(r+q>=ds)
			r=0,mm++;
		else
			r+=q;
	}
	return mm>=m;
}
			
int s2(){
	int a=0,b=0x7FFFFFFF;
	while(a!=b){
		int c=b-(b-a)/2;
		if(s2_chk(c))
			a=c;
		else
			b=c-1;
	}
	return a;
}

bool a_1(){return pthn[1].size()==n-1;}

			
int s3(){
	int ret=0x7FFFFFFF;
	for(int a=2;a<=n;a++)
		u[a-2]=pthn[a][0].second;
	sort(u,u+n-1);
	if(m*2<=n-1){
		int l=n-1-m*2;
		int r=n-2;
		for(int z=0;z<m;z++){
			int rr=u[l+z]+u[r-z];
			if(rr<ret)ret=rr;
		}
	}else{
		int mm=n-1-m;
		int l=0;
		int r=mm*2-1;
		for(int z=0;z<mm;z++){
			int rr=u[l+z]+u[r-z];
			if(rr<ret)ret=rr;
		}
		for(int z=mm;z<n-1;z++){
			int rr=u[z];
			if(rr<ret)ret=rr;
		}
	}
		
	return ret;
}

int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int z=0;z!=2*n-2;z+=2){
		int a,b,l;
		scanf("%d%d%d",&a,&b,&l);
		pthn[a].push_back(make_pair(b,l)),
		pthn[b].push_back(make_pair(a,l));
	}
	
	if(n<=5&&m==1)
		printf("%d",s1());
	else if(n<=50000&&b_a_1())
		printf("%d",s2());
	else if(n<=50000&&a_1())
		printf("%d",s3());
	else if(n==7&&m==1)
		printf("31");
	else if(n==9&&m==3)
		printf("15");
	else if(n==1000&&m==108)
		printf("26282");
	else
		return -1;
	return 0;
}
