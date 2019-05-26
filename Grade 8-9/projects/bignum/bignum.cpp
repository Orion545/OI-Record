#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<vector>
#define ll long long
#define inf 0x7fffffff
using namespace std;
class bigint{
	public:
	vector<int>a;bool flag;
	bigint(){flag=0;}
	bigint(int num){flag=0;a.push_back(0);a.push_back(num);}
	void input(){
		string x;cin>>x;
		if(x[0]=='-'){
			flag=1;x.erase(0,1);
		}
		else flag=0;
		a.push_back(x.length());ll tmp=x.length();
		do{
			if(tmp<=8){
				a.push_back(0);
				for(int i=0;i<tmp;i++){
					a[a.size()-1]*=10;a[a.size()-1]+=x[i]-48;
				}
				break;
			}
			else{
				a.push_back(0);tmp-=8;
				for(int i=tmp;i<=tmp+7;i++){
					a[a.size()-1]*=10;a[a.size()-1]+=x[i]-48;
				}
			}
		}while(tmp>0);
	}
	void output(){
		if(flag) cout<<"-";
		bool f=0,ff=0;
		for(int i=a.size()-1;i>=1;i--){
			if(!f&&a[i]==0) continue;
			if(!f&&a[i]!=0){
				f=1;ff=1;cout<<a[i];continue;
			}
			if(f){
				cout<<a[i];ff=1;
			}
		}
		if(!ff) cout<<0;
		cout<<endl;
	}
	
	inline bigint operator =(bigint o){
		flag=o.flag;
		for(int i=a.size();i<o.a.size();i++) a.push_back(0);
		a[0]=o.a[0];
		for(int i=1;i<o.a.size();i++) a[i]=o.a[i];
		return *this;
	}
	
	inline int compare(bigint &o){
		if(a.size()>o.a.size())return 1;
		if(a.size()<o.a.size())return -1;
		for(int i=a.size()-1;i>=1;i--){
			if(a[i]>o.a[i]) return 1;
			if(a[i]<o.a[i]) return -1;
		}
		return 0;
	}
	inline bool operator >=(bigint &o){
		return (compare(o)>=0)?1:0;
	}
	inline bool operator <(bigint &o){
		return 1-(*this>=o);
	} 
	inline bool operator <=(bigint &o){
		return (compare(o)<=0)?1:0;
	}
	inline bool operator >(bigint &o){
		return 1-(*this<=o);
	}
	inline bool operator ==(bigint &o){
		return (compare(o)==0)?1:0;
	}
	inline bool operator !=(bigint &o){
		return 1-(*this==o);
	}
	
	inline bigint add(bigint &o){
		bigint re;
		int smasize=min(a.size(),o.a.size()),bigsize=max(a.size(),o.a.size());
		bool big;
		if(a.size()>o.a.size()) big=1;
		else big=0;
		re.a.push_back(max(a[0],o.a[0]));
		bool f;
		for(int i=1;i<smasize;i++){
			re.a.push_back(0);
			if(f) re.a[i]++;
			f=0;
			re.a[i]+=a[i]+o.a[i];
			if(re.a[i]>=100000000){
				f=1;re.a[i]%=100000000;
			}
		}
		for(int i=smasize;i<bigsize;i++){
			re.a.push_back(0);
			if(f) re.a[i]++;
			f=0;
			re.a[i]+=(big==1)?(a[i]):(o.a[i]);
			if(re.a[i]>=100000000){
				f=1;re.a[i]%=100000000;
			}
		}
		return re;
	}
	inline bigint minus(bigint &o){//this>=o; 
		bigint re;re.a.push_back(a[0]);
		for(int i=1;i<o.a.size();i++){
			re.a.push_back(0);
			if(a[i]<o.a[i]){
				a[i]+=100000000;a[i+1]--;
			}
			re.a[i]=a[i]-o.a[i];
		} 
		for(int i=o.a.size();i<a.size();i++) re.a.push_back(a[i]);
		return re;
	}
	inline bigint operator+(bigint &o){
		if(!flag&&o.flag){
			if(*this<o){
				bigint re=o.minus(*this);re.flag=1;return re;
			}
			else return minus(o);
		}
		if(flag&&!o.flag){
			if(*this>o){
				bigint re=minus(o);re.flag=1;return re;
			}
			else return o.minus(*this);
		}
		if(!flag&&!o.flag) return add(o);
		if(flag&&o.flag){
			bigint re=add(o);re.flag=1;return re;
		}
	}
	inline bigint operator -(bigint &o){
		if(!flag&&!o.flag){
			if(*this<o){
				bigint re=o.minus(*this);re.flag=1;return re;
			}
			else return minus(o);
		}
		if(flag&&o.flag){
			if(*this>o){
				bigint re=minus(o);re.flag=1;return re;
			}
			else return o.minus(*this);
		}
		if(!flag&&o.flag) return add(o);
		if(flag&&!o.flag){
			bigint re=add(o);re.flag=1;return re;
		}
	}
	inline bigint operator +=(bigint o){
		return *this+o;
	}
	inline bigint operator -=(bigint o){
		return *this-o;
	}
	
	inline bigint operator *(bigint &o){
		bigint re;
		re.flag=(flag==o.flag)?0:1;
		re.a.push_back(a[0]+o.a[0]);
		for(int i=1;i<a.size()+o.a.size();i++) re.a.push_back(0);
		for(int j=1;j<o.a.size();j++){
			for(int i=1;i<a.size();i++){
				ll tmp=a[i]*o.a[j];
				re.a[i+j-1]+=tmp%100000000;
				re.a[i+j]+=tmp/100000000;
			}
		}
		for(int i=1;i<a.size()+o.a.size();i++){
			if(re.a[i]>99999999){
				re.a[i+1]+=re.a[i]/100000000;re.a[i]%=100000000;
			}
		}
		return re;
	} 
	inline bigint operator /(bigint &o){
		bigint re(0),one(1),me=*this;
		while(me>=o){
			me=me-o;re=re+one;
		} 
		return re;
	}
	inline bigint operator %(bigint &o){
		bigint re(0),one(1),me=*this;
		while(me>=o){
			me=me-o;re=re+one;
		} 
		return me;
	}
};

inline void swap(bigint &a,bigint &b){
	bigint t;
	t=a;a=b;b=t;
}
inline bigint gcd(bigint a,bigint b){
	bigint g=a%b,zero(0);
	if(g==zero) return (a>b)?b:a;
	else return gcd(b,g); 
} 
inline bigint fac(bigint a){
	bigint one(1),re(1);
	for(bigint i(2);i<=a;i=i+one){
		re=re*i;
	}
	return re;
}

int main(){
	bigint one(1);
	bigint a,b;
	a.input();b.input();
	bigint c(1);c.output();
	c=a+b;c.output();
	c=a-b;c.output();
	c=a*b;c.output();
	c=a/b;c.output();
	c=a%b;c.output();
	c=gcd(a,b);c.output();
	
} 
