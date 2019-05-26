#include <bits/stdc++.h>
#define LL long long
#define MAXN 110
using namespace std;
 
const LL P=1000000009,P2=(1ll<<62)-(P*P)-100+(1ll<<62);
 
LL getPow(LL x,LL y){
	LL res=1;
	while(y){
		if(y&1) res=res*x%P;
		x=x*x%P;
		y>>=1;
	}
	return res;
}
 
int n,lenk;
char str[100010];
LL a0[MAXN][MAXN],a1[MAXN][MAXN];
LL b[MAXN],ansp[MAXN];
LL ans[MAXN][MAXN];
 
void poly_mul(LL *a,LL *b,int l1,int l2){
	static LL c[MAXN];
	memset(c,0,sizeof(LL)*(l1+l2+1));
	for(int i=0;i<=l1;i++) if(a[i]<0) a[i]+=P;
	for(int i=0;i<=l2;i++) if(b[i]<0) b[i]+=P;
	for(int i=0;i<=l1;i++)
		for(int j=0;j<=l2;j++)
			((c[i+j]+=a[i]*b[j])>P2)?(c[i+j]%=P):0;
	for(int i=0;i<=l1+l2;i++) a[i]=c[i]%P;
}
 
void poly_mod(LL *a,LL *b,int l1,int l2){
	LL invt=getPow(b[l2],P-2);
	for(int i=l1-l2;i>=0;i--){
		LL temp=a[i+l2]%P*invt%P;
		if(!temp) continue;
		if(temp<0) temp+=P;
		for(int j=0;j<=l2;j++)
			((a[i+j]-=temp*b[j])<-P2)?(a[i+j]%=P):0;
	}
	for(int i=0;i<=l1;i++) ((a[i]%=P)<0)?(a[i]+=P):0;
}
 
void mat_mul(LL a[MAXN][MAXN],LL b[MAXN][MAXN]){
	static LL c[MAXN][MAXN];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			LL res=0;
			for(int k=1;k<=n;k++)
				((res+=a[i][k]*b[k][j])>P2)?(res%=P):0;
			c[i][j]=res;
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			a[i][j]=c[i][j]%P;
}
 
LL calc_det(LL a[MAXN][MAXN],int x){
	if(x==n) return a[x][x];
	int pos=0;
	for(int i=x;i<=n;i++)
		if(a[i][x]){
			pos=i;
			break;
		}
	if(!pos) return 0;
	LL flag=1;
	if(pos!=x){
		flag=-1;
		for(int i=x;i<=n;i++)
			swap(a[x][i],a[pos][i]);
	}
	LL invx=getPow(a[x][x],P-2);
	for(int i=x+1;i<=n;i++)
		if(a[i][x]){
			LL temp=a[i][x]*invx%P;
			for(int j=x;j<=n;j++)
				a[i][j]=(a[i][j]-temp*a[x][j])%P;
		}
	return a[x][x]*flag*calc_det(a,x+1)%P;
}
 
void calc_b(){
	static LL y[MAXN];
	for(int x=0;x<=n;x++){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				a1[i][j]=a0[i][j];
				if(i==j) a1[i][j]-=x;
			}
		y[x]=calc_det(a1,1);
		if(y[x]<0) y[x]+=P;
		cout<<"pre "<<x<<' '<<y[x]<<'\n';
	}
	for(int i=0;i<=n;i++){
		static LL tp[MAXN];
		tp[0]=1;
		int l=0;
		LL t2=1;
		for(int j=0;j<=n;j++)
			if(i!=j){
				static LL tp2[2];
				tp2[0]=-j;
				tp2[1]=1;
				poly_mul(tp,tp2,l++,1);
				t2=t2*(i-j)%P;
			}
		t2=y[i]*getPow(t2,P-2)%P;
		for(int i=0;i<=n;i++)
			b[i]=(b[i]+tp[i]*t2)%P;
	}
	for(int i=0;i<=n;i++) if(b[i]<0) b[i]+=P;
	for(int i=0;i<=n;i++) cout<<"finish pre "<<i<<' '<<b[i]<<'\n';
}
 
void gao(){
	static LL px[MAXN];
	px[1]=1;
	ansp[0]=1;
	for(int i=lenk;i>=1;i--){
		if(str[i]=='1'){
			poly_mul(ansp,px,n-1,n-1);
			poly_mod(ansp,b,2*n-2,n);
		}
		poly_mul(px,px,n-1,n-1);
		poly_mod(px,b,2*n-2,n);
	}
}
 
void calc_ans(){
	static LL tp[MAXN][MAXN];
	for(int i=1;i<=n;i++) tp[i][i]=1;
	for(int i=0;i<n;i++) cout<<i<<' '<<ansp[i]<<'\n';
	for(int t=0;t<n;t++){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				ans[i][j]=(ans[i][j]+tp[i][j]*ansp[t])%P;
		if(t+1<n) mat_mul(tp,a0);
	}
}
 
int main(){
#ifdef DEBUG
	freopen("B.in","r",stdin);
#endif
	scanf("%d%s",&n,str+1);
	lenk=strlen(str+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%lld",&a0[i][j]);
	calc_b();
	gao();
	calc_ans();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			printf("%lld ",(ans[i][j]+P)%P);
		puts("");
	}
	return 0;
}
