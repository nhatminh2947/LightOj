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

int n,tcs;
double res[100000005];

void AC()
{
    res[1]=1;
    for(int i=2;i<=100000000;i++)
    {
        res[i]=res[i-1]+double(1/double(i));
    }
}

int main()
{
    freopen("A.INP","r",stdin);
    freopen("A.OUT","w",stdout);
    AC();
    scanf(" %d ",&tcs);
    for(int t=1;t<=tcs;t++)
    {
        scanf(" %d ",&n);
        printf("Case %d: %.9lf\n",t,res[n]);
    }
    return 0;
}
