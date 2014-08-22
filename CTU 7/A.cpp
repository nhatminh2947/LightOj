//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: A - Donation
// Verdict:
//******************************************************************
#include <iostream>
#include <iomanip>
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
#define INF 1000000000
#define PI 3.1415926535897932384626433832795
#define read(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
#define DEBUG(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)

using namespace std;

typedef struct
{
    int i,j,c;
}room;

int tcs,n;
int lab[100];
room data[105];
int cable[105][105];

int getRoot(int u)
{
    if(lab[u]==u) return u;
    return lab[u]=getRoot(lab[u]);
}

void unionset(int a,int b)
{
    lab[a]=b;
}

bool cmp(room a,room b)
{
    return a.c<b.c;
}

int main()
{
    freopen("A.INP","r",stdin);
    freopen("A.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int t=1;t<=tcs;t++)
    {
        
        int c;
        int sum=0;
        int cnt=0;
        scanf(" %d ",&n);
        
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                cable[i][j]=0;
        
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                scanf(" %d ",&c);
                cable[i][j]=c;
                if(i==j)
                    sum+=c;
                else if(i>j)
                {
                    if(cable[i][j]>=cable[j][i] && cable[i][j]!=0)
                    {
                        if(cable[j][i]==0)
                        {
                            data[cnt].i=i;
                            data[cnt].j=j;
                            data[cnt].c=cable[i][j];
                            cnt++;
                        }
                        else
                        {
                            sum+=cable[i][j];
                            data[cnt].i=i;
                            data[cnt].j=j;
                            data[cnt].c=cable[j][i];
                            cnt++;
                        }
                    }
                    else if(cable[i][j]<cable[j][i])
                    {
                        if(cable[i][j]==0)
                        {
                            data[cnt].i=i;
                            data[cnt].j=j;
                            data[cnt].c=cable[j][i];
                            cnt++;
                        }
                        else
                        {
                            sum+=cable[j][i];
                            data[cnt].i=i;
                            data[cnt].j=j;
                            data[cnt].c=cable[i][j];
                            cnt++;
                        }
                    }
                    
                    
                }
            }
        
        for(int i=0;i<n;i++)
            lab[i]=i;
        
        sort(data,data+cnt,cmp);
        
        for(int i=0;i<cnt;i++)
        {
            int r1=getRoot(data[i].i);
            int r2=getRoot(data[i].j);
            int cost=data[i].c;
            
            if(r1!=r2)
                unionset(r1,r2);
            else
                sum+=cost;
            
        }
        
        bool fn=true;
        for(int i=0;i<(n-1);i++)
            if(getRoot(i)!=getRoot(i+1))
            {
                fn=false;
                break;
            }
        
        if(fn) printf("Case %d: %d\n",t,sum);
        else printf("Case %d: -1\n",t);
    }
    return 0;
}
