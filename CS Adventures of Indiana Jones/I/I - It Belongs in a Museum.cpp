//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Number: I - It Belongs in a Museum
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

int tcs,r,c;
char data[105][105];

int dx[]={-1,-1,-1, 0, 0, 1, 1, 1};
int dy[]={-1, 0, 1,-1, 1,-1, 0, 1};

bool in(int x,int y)
{
    return (0<=x && x<c && 0<=y && y<r);
}

void DFS(int y,int x)
{
    data[y][x]='.';
    for(int i=0;i<8;i++)
    {
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(in(xx,yy) && data[yy][xx]=='@')
            DFS(yy,xx);
    }
}

int main()
{
    //freopen("I - It Belongs in a Museum.INP","r",stdin);
    //freopen("I - It Belongs in a Museum.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int i=1;i<=tcs;i++)
    {
        int cnt=0;
        scanf(" %d %d ",&r,&c);
        for(int j=0;j<r;j++)
            gets(data[j]);
        for(int j=0;j<r;j++)
            for(int k=0;k<c;k++)
            {
                if(data[j][k]=='@')
                {
                    DFS(j,k);
                    cnt++;
                }
            }
        printf("Case %d: %d\n",i,cnt);
    }
    return 0;
}
