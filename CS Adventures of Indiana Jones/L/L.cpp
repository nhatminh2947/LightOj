//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Number: L
// Verdict: Accepted
//******************************************************************
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#define INF 999999999
#define PI 3,1415926535

using namespace std;

char data[85][85];
char s[55];
bool check[85][85];
int F[85][85];
int tcs,r,c;

int dx[]={-1, 0 , 1};
int dy[]={ 1, 2 , 1};

bool in(int x,int y)
{
    return (1<=y && y<=r && 1<=x && x<=c);
}

int DP()
{
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
            F[i][j]=0;
    for(int j=1;j<=c;j++)
        if(check[1][j]) F[1][j]=1;
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
        {
            for(int k=0;k<3 && check[i][j];k++)
            {
                int xx=j+dx[k];
                int yy=i+dy[k];
                if(in(xx,yy) && check[yy][xx])
                    F[yy][xx]+=F[i][j]%1000003;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=c;i++)
    {
        ans+=F[r][i];
        ans%=1000003;
    }
    return ans;
}

int main()
{
    //freopen("L.INP","r",stdin);
    //freopen("L.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int i=1;i<=tcs;i++)
    {
        scanf(" %d %d ",&r,&c);
        gets(s);
        int len=strlen(s);
        for(int k=1;k<=r;k++)
            for(int j=1;j<=c;j++)
            {
                check[k][j]=false;
                scanf(" %c ",&data[k][j]);
                for(int l=0;l<len;l++)
                {
                    if(s[l]==data[k][j])
                    {
                        check[k][j]=true;
                        break;
                    }
                }
            };
        printf("Case %d: %d\n",i,DP()%1000003);
    }
    return 0;
}
