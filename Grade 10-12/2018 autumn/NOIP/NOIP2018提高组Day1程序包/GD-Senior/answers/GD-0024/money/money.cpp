#include<cstdio>
#include<bitset>
#include<algorithm>

typedef long long int64;
typedef unsigned char uchar;

const int maxn(25000);

namespace IOManager{
	const int FILESZ(131072);
	char buf[FILESZ];
	const char*ibuf=buf,*tbuf=buf;

	struct IOManager{
		FILE*fin;
		
		IOManager():fin(fopen("money.in","r")){}
		~IOManager(){fclose(fin);}
		
		inline char gc()
			{return(ibuf==tbuf)&&(tbuf=(ibuf=buf)+fread(buf,1,FILESZ,fin),ibuf==tbuf)?EOF:*ibuf++;}

		template<class _Tp>
			inline operator _Tp(){
				_Tp s=0;char c=gc();
				for(;c<'0'||'9'<c;c=gc());
				for(;'0'<=c&&c<='9';c=gc())
					s=s*10+c-48;
				return s;
			}
	};
}IOManager::IOManager io;

std::bitset<maxn+10>b;
int a[maxn+1];

int main(){
	FILE*fout=fopen("money.out","w");

	for(int T=io;T;--T){
		b.reset();b[0]=1;
	
		const int n=io;
		for(int i=1;i<=n;++i)
			a[i]=io;
		std::sort(a+1,a+n+1);

		int ans=0;
		for(int i=1;i<=n;++i)
			if(!b[a[i]]){
				++ans;
				for(int j=a[i];j<=a[n];j+=j)
					b|=b<<j;
			}

		fprintf(fout,"%d\n",ans);
	}

	fclose(fout);
	return 0;
}

