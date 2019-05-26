#include<cstdio>

typedef long long int64;
typedef unsigned char uchar;

const int maxn(100000);

inline int Min(const int&x,const int&y)
	{return x<y?x:y;}

namespace IOManager{
	const int FILESZ(131072);
	char buf[FILESZ];
	const char*ibuf=buf,*tbuf=buf;
	
	struct IOManager{
		FILE*fin;
		
		IOManager():fin(fopen("road.in","r")){}
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

int d[maxn+1];

int main(){
	const int n=io;
	for(int i=1;i<=n;++i)
		d[i]=io;

	int64 s=0;
	for(int i=1;i<=n;++i)
		s+=d[i];
	for(int i=2;i<=n;++i)
		s-=Min(d[i-1],d[i]);

	FILE*fout=fopen("road.out","w");
	fprintf(fout,"%lld",s);
	fclose(fout);

	return 0;
}

