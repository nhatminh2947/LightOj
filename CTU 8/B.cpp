//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code:
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
    int lf,rg;
}tower;

int tcs,n;
tower data[1005],jump[1005];

int dij()
{
    set< pair<int,pair<int,int> > > s;
    
    s.insert(make_pair(data[0].lf,make_pair(0,0)));
    s.insert(make_pair(data[0].rg,make_pair(0,1)));
    
    while(!s.empty())
    {
        pair<int,pair<int,int> > tmp=*s.begin();
        
        int pos=tmp.second.first;
        int dis=tmp.first;
        int lr=tmp.second.second;
        
        s.erase(tmp);
        
        if(lr==0)
        {
            
        }
    }
}

int main()
{
    freopen("B.INP","r",stdin);
    freopen("B.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int t=1;t<=tcs;t++)
    {
        scanf(" %d ",&n);
        for(int i=0;i<n;i++)
            scanf(" %d ",&data[i].lf);
        for(int i=0;i<n;i++)
            scanf(" %d ",&data[i].rg);
            
        for(int i=1;i<n;i++)
            scanf(" %d ",&jump[i].lf);
        for(int i=1;i<n;i++)
            scanf(" %d ",&jump[i].rg);
        
        int res=dij();
        printf("Case %d: %d\n",t,res);
    }
    return 0;
}
