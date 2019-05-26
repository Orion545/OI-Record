#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
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
char s[101010];
double w[26]={0,1,12,14,16,19,23,24,27,28,31,32,35.5,39,40,55,56,64,65,108,127,137,178.5,195,197,201};
int check(int l,int r){
	if(l==r){
		switch(s[l]){
			case 'H': return 1;
			case 'C': return 2;
			case 'N': return 3;
			case 'O': return 4;
			case 'F': return 5;
			case 'P': return 10;
			case 'S': return 11;
			case 'K': return 13;
			case 'I': return 20;
		}
	}
	else{
		switch(s[l]){
			case 'N': return 6;
			case 'M':
				if(s[r]=='g') return 7;
				if(s[r]=='n') return 15;
			case 'A':
				if(s[r]=='l') return 8;
				if(s[r]=='u') return 24;
				if(s[r]=='g') return 19;
			case 'S':
				if(s[r]=='i') return 9;
			case 'C':
				if(s[r]=='a') return 14;
				if(s[r]=='l') return 12;
				if(s[r]=='u') return 17;
			case 'F':
				if(s[r]=='e') return 16;
			case 'Z': return 18;
			case 'B': return 21;
			case 'P': return 23;
			case 'H':
				if(s[r]=='f') return 22;
				if(s[r]=='g') return 25;
		}
	}
}
int main(){
	scanf("%s",s);int n=strlen(s),i;
	bool brak=0;
	double first=0,second=0;
	for(i=0;i<n;i++){
//		cout<<i<<' '<<s[i]<<'\n';
		if(s[i]=='~') break;
		if(s[i]=='('){
			brak=1;second=0;
			continue;
		}
		if(s[i]==')'){
			brak=0;
			if(s[i+1]=='_'){
				i+=3;
				double tmp=0;
				while(s[i]>='0'&&s[i]<='9') tmp=tmp*10,tmp+=(s[i]-'0'),i++;
				second*=tmp;
			}
//			cout<<"finish second "<<i<<' '<<second<<'\n';
			first+=second;
			continue;
		} 
		if(s[i]>='A'&&s[i]<='Z'){
			int type;
			if(s[i+1]>='a'&&s[i+1]<='z') type=check(i,i+1),i++;
			else type=check(i,i);
			double val=w[type];
			if(s[i+1]=='_'){
				i+=3;
				double tmp=0;
				while(s[i]>='0'&&s[i]<='9') tmp=tmp*10,tmp+=(s[i]-'0'),i++;
				val*=tmp;
			}
//			cout<<"get "<<type<<' '<<i<<' '<<val<<'\n';
			if(brak) second+=val;
			else first+=val;
		}
	}
	if(i!=n){
		if(s[i]=='~') i++;
		double tmp=0;
		if(s[i]<'0'||s[i]>'9') tmp=1;
		else{
		while(s[i]>='0'&&s[i]<='9') tmp=tmp*10,tmp+=(s[i]-'0'),i++;
			
		}
		first+=18*tmp;
	}
	cout<<first<<'\n';
	
}
