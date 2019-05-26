#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define end DEEP_DARK_FANTASY
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int son[110][26],val[110],end[20],fail[110],cnt,n,m,len;
void insert(char s[],int num){
//	cout<<"insert "<<s<<' '<<num<<'\n';
	int cur=0,tmp,i;
	for(i=0;i<len;i++){
		tmp=s[i]-'A';
		if(!son[cur][tmp]) son[cur][tmp]=++cnt;
		cur=son[cur][tmp];
	}
	val[cur]=1;end[num]=cur;
//	cout<<"end of insert "<<s<<' '<<cnt<<'\n';
}
void AC(){
	queue<int>q;int i,u,v;
	for(i=0;i<26;i++){
		if(!son[0][i]) continue;
		q.push(son[0][i]);fail[son[0][i]]=0;
	}
	while(!q.empty()){
		u=q.front();q.pop();
//		cout<<"getfail "<<u<<' '<<fail[u]<<'\n';
		for(i=0;i<26;i++){
			v=son[u][i];
			if(!v) son[u][i]=son[fail[u]][i];
			else fail[v]=son[fail[u]][i],q.push(v);
		}
	}
}
struct matrix{
	double a[110][110],siz;
	matrix(int sizz=0){siz=sizz;memset(a,0,sizeof(a));}
	inline matrix operator *(matrix b){
		matrix re(siz);int i,j,k;
//		cout<<"matrix a\n";
//		for(i=0;i<=siz;i++){
//			for(j=0;j<=siz;j++) cout<<a[i][j]<<' ';
//			cout<<'\n';
//		}
//		cout<<"matrix b\n";
//		for(i=0;i<=siz;i++){
//			for(j=0;j<=siz;j++) cout<<b.a[i][j]<<' ';
//			cout<<'\n';
//		}
		for(i=0;i<=siz;i++)
			for(j=0;j<=siz;j++)
				for(k=0;k<=siz;k++)
					re.a[i][j]+=a[i][k]*b.a[k][j];
//		cout<<"matrix re\n";
//		for(i=0;i<=siz;i++){
//			for(j=0;j<=siz;j++) cout<<re.a[i][j]<<' ';
//			cout<<'\n';
//		}
		return re;
	}
};
inline void qpow(matrix &A,long long t){
	matrix re(cnt);
	for(int i=0;i<=cnt;i++) re.a[i][i]=1;
	while(t){
		if(t&1) re=A*re;
		A=A*A;t>>=1;
	}
	A=re;
}
double p[30];char s[110];
int main(){
	n=read();len=read();m=read();int i,j;double t1,t2;
	for(i=0;i<m;i++){
		t1=read();t2=read();
		p[i]=t1/t2;
	}
	for(i=1;i<=n;i++) scanf("%s",s),insert(s,i);
	AC();matrix a(cnt);
	for(i=0;i<=cnt;i++){
		if(val[i]){
			a.a[i][i]=1;continue;
		}
		for(j=0;j<m;j++){
			a.a[i][son[i][j]]+=p[j];
		}
	}
	qpow(a,1e15);
	for(i=1;i<=n;i++){
		printf("%.2lf\n",a.a[0][end[i]]);
	}
}
