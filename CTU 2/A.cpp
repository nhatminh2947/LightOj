//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: A
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

int tcs;
long long n;
long long F[25];
bool vis[25];
bool check;
long long sum;

int frac()
{
    F[0]=1;
    F[1]=1;
    for(long long i=2;i<=20;i++)
        F[i]=F[i-1]*i;
}

int main()
{
    //freopen("A.INP","r",stdin);
    //freopen("A.OUT","w",stdout);
    scanf(" %d ",&tcs);
    frac();
    for(int t=1;t<=tcs;t++)
    {
        scanf(" %lld ",&n);
        printf("Case %d: ",t);
        stack<int> s;
        bool lock=false;
        for(int i=20;i>=0;i--)
        {
            if(n>=F[i])
            {
                s.push(i);
                n-=F[i];
                if(n==0)
                {
                    while(!s.empty())
                    {
                        printf("%d!",s.top());
                        if(s.size()!=1) printf("+");
                        s.pop();
                    }
                    lock=true;
                    break;
                }
            }
        }
        if(!lock) printf("impossible");
        printf("\n");
    }
    return 0;
}
