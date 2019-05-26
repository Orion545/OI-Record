/*  
ID: marcoli2  
LANG: C++  
TASK: transform  
*/  
#include<cstdio>  
#include<cstring>  
#include<iostream>  
#include<algorithm>  
using namespace std;  
int map[11][11];  
int map1[11][11];  
int map2[11][11];  
int maps[11][11];  
int n;  
int bijiao()
{  
    int i,j;  
    for(i=0;i<n;i++)  
    {  
        for(j=0;j<n;j++)  
        {  
            if(map2[i][j]!=maps[i][j])return 0;  
        }  
    }  
    return 1;  
}  
void zhi() 
{  
    int i,j;  
    for(i=0;i<n;i++)  
    {  
        for(j=0;j<n;j++)  
        {  
            map1[i][j]=map2[i][j];  
        }  
    }  
}  
void fanzhuan()
{  
    int i,j;  
    for(j=0;j<n;j++)  
    {  
        for(i=n-1;i>=0;i--)  
        {  
            map2[j][n-1-i]=map1[i][j];  
        }  
    }  
}  
int dos()//进行1~3步的翻转  
{  
    zhi();  
    fanzhuan();  
    if(bijiao())return 1;  
    zhi();  
    fanzhuan();  
    if(bijiao())return 2;  
    zhi();  
    fanzhuan();  
    if(bijiao())return 3;  
    return 0;  
}  
int jing()
{  
    int i,j;  
    for(i=0;i<n;i++)  
    {  
        for(j=0;j<n;j++)  
        {  
            map2[i][j]=map[i][n-j-1];  
        }  
    }  
    if(bijiao())return 1;  
    return 0;  
}  
int main()  
{  
    freopen("transform.in","r",stdin);  
    freopen("transform.out","w",stdout);  
    cin>>n;  
    getchar();  
    int i,j;  
    char c;  
    for(i=0;i<n;i++)  
    {  
        for(j=0;j<n;j++)  
        {  
            c=getchar();  
            if(c=='@')map[i][j]=map1[i][j]=map2[i][j]=0;  
            else map[i][j]=map1[i][j]=map2[i][j]=1;  
        }  
        getchar();  
    }  
    for(i=0;i<n;i++)  
    {  
        for(j=0;j<n;j++)  
        {  
            c=getchar();  
            if(c=='@')maps[i][j]=0;  
            else maps[i][j]=1;  
        }  
        getchar();  
    }  
    int leapp;  
    leapp=0;  
    if(bijiao())leapp=1;  
    if(1)  
    {  
        int leap;  
        leap=dos();  
        if(leap)cout<<leap<<endl;  
        else if(jing())cout<<"4"<<endl;  
        else  
        {  
            if(dos())  
            {  
                cout<<"5"<<endl;  
            }  
            else if(leapp) cout<<"6"<<endl;  
            else cout<<"7"<<endl;  
        }  
  
    } 
    return 0;  
} 
