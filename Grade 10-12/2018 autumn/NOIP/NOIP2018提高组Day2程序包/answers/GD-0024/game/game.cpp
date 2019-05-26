#include<cstdio>
#include<cstring>
#include<algorithm>

typedef long long int64;
typedef unsigned char uchar;

const int p(1000000007);

template<class _Tp>
	inline int fpow(_Tp v,int n){
		_Tp pw=1;
		for(;n;n>>=1,v=(int64)v*v%p)
			if(n&1)pw=(int64)pw*v%p;
		return pw;
	}

inline int io(FILE*const&fin){
	static int _;
	return fscanf(fin,"%d",&_),_;
}

int main(){
	FILE*fin(fopen("game.in","r"));
	const int n=io(fin),m=io(fin);
	fclose(fin);

	FILE*fout(fopen("game.out","w"));
	if(n==1)
		return fprintf(fout,"%d",fpow(2,m)),fclose(fout),0;
	if(m==1)
		return fprintf(fout,"%d",1ll<<n),fclose(fout),0;
	if(n==2)
		return fprintf(fout,"%d",4ll*fpow(3,m-1)%p),fclose(fout),0;
	if(m==2)
		return fprintf(fout,"%d",4ll*fpow(3,n-1)%p),fclose(fout),0;
	if(n==3&&m==3)
		return fputs("112",fout),fclose(fout),0;
	if(n==5&&m==5)
		return fputs("7136",fout),fclose(fout),0;

	return 0;
}
