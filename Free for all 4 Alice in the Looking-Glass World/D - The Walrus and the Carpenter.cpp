//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: D - The Walrus and the Carpenter
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
#define maxN 123456
#define INF 1000000000
#define PI 3.1415926535897932384626433832795
#define read(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
#define DEBUG(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)
#define mp make_pair
#define ff first
#define ss second
#define pb push_back

using namespace std;

int main()
{
    //freopen("D - The Walrus and the Carpenter.INP","r",stdin);
    //freopen("D - The Walrus and the Carpenter.OUT","w",stdout);
    int tcs;
    scanf(" %d ",&tcs);
    for(int t = 1 ; t <= tcs ; t++)
    {
        unsigned long long n;
        cin >> n;
        
        unsigned long long mid,ans;
        unsigned long long lo = 0;
        unsigned long long hi = n;
        while(lo <= hi)
        {
            mid = (lo + hi) / 2;
            
            unsigned long long k;
            
            if(mid % 2 == 0)
            {
                k = mid / 2;
                k *= (mid + 1);
            }
            else
            {
                k = (mid + 1) / 2;
                k *= mid;
            }
            
            if( k > n)
                hi = mid - 1;
            else
            {
                lo = mid + 1;
                if(mid % 2 == 0)
                {
                    ans = mid / 2;
                    ans *= (mid + 1);
                }
                else
                {
                    ans = (mid + 1) / 2;
                    ans *= mid;
                }
            }
        }
        
        cout << "Case " << t << ": " << ans << " " << n - ans << endl;
    }
    return 0;
}
