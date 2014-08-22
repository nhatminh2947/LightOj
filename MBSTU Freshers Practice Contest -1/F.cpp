//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: F - Setu 
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

int tcs,n;

int main()
{
    //freopen("F.INP","r",stdin);
    //freopen("F.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int t=1;t<=tcs;t++)
    {
        scanf(" %d ",&n);
        printf("Case %d:\n",t);
        string cmd;
        int k;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>cmd;
            if(cmd=="donate")
            {
                scanf(" %d ",&k);
                sum+=k;
            }
            else
            {
                printf("%d\n",sum);
            }
        }
    }
    return 0;
}
