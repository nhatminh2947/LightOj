//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: A - Parity
// Verdict: Accepted
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

int main()
{
    //freopen("A.INP","r",stdin);
    //freopen("A.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int t=1;t<=tcs;t++)
    {
        scanf(" %lld ",&n);
        int cnt=0;
        while(n)
        {
            if(n%2==1) cnt++;
            n/=2;
        }
        printf("Case %d: ",t);
        if(cnt%2==0)
            printf("even\n");
        else printf("odd\n");
    }
    return 0;
}
