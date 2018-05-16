#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <ctime>
#include <cstring>
#include <algorithm>
#define MAXSIZE 10010
#define MAXN 20
#define MAXND MAXN / 10
#define MAXVERTEX 100010
#define MAXEDGE 3000010
#define INF 99999999
#define nil NULL
typedef long long ll;
using namespace std;

int n;
int w[MAXN][MAXN];
int lx[MAXN],ly[MAXN];
int matched[MAXN];
int slack[MAXN];
bool s[MAXN],t[MAXN];

bool match(int i){
    s[i]=1;
    for(int j=1;j<=n;j++){
        int cnt=lx[i]+ly[j]-w[i][j];
        if(cnt==0&&!t[j]){
            t[j]=1;
            if(!matched[j]||match(matched[j])){
                matched[j]=i;
                return 1;
            }
        }
        else{
            slack[j]=min(slack[j],cnt);
        }
    }
    return 0;
}

void update(){
    int a=INF;
    for(int i=1;i<=n;i++){
        if(!t[i])a=min(a,slack[i]);
    }
    for(int i=1;i<=n;i++){
        if(s[i])lx[i]-=a;
        if(t[i])ly[i]+=a;
    }
}

void km(){
    memset(matched,0,sizeof(matched));
    memset(lx,0,sizeof(lx));
    memset(ly,0,sizeof(ly));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            lx[i]=max(lx[i],w[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        memset(slack,0x3f,sizeof(slack));
        while(1){
            memset(s,0,sizeof(s));
            memset(t,0,sizeof(t));
            if(match(i))break;
            else update();
        }
    }
}

int main()
{
    while(~scanf("%d",&n)){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                scanf("%d",&w[i][j]);
            }
        }
        km();
        int ans=0;
        for(int i=1;i<=n;i++){
            ans+=lx[i];
            ans+=ly[i];
        }
        printf("%d\n",ans);
    }
    return 0;
}
