//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 1116 - Ekka Dokka
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

#define int64 long long
#define u64 unsigned long long
#define PI 3.1415926535897932384626433832795
#define read(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
#define DEBUG(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)
#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define maxN 123456
#define INF 1000111222

using namespace std;



int main()
{
    freopen("1116 - Ekka Dokka.INP","r",stdin);
    freopen("1116 - Ekka Dokka.OUT","w",stdout);

    int tcs;
    scanf(" %d ",&tcs);
    for(int t = 1 ; t <= tcs ; t++)
    {
        //cout << "AAAAAAAAAAAAAA" << endl;
        u64 n;
        scanf(" %llu ",&n);
        printf("Case %d: ",t);
        if(n % 2)
        {
            printf("Impossible\n");
            continue;
        }
        //cout << "BBBBBBBBBBBBBBBBB" << endl;
        u64 ans,tmp = 1;
        //DEBUG(n);
        while(tmp < n)
        {
            //DEBUG(tmp);
            tmp = tmp << 1;
            if(n % tmp == 0 && ((n / tmp) % 2 == 1))
            {
                ans = tmp;
                //DEBUG(ans);
            }
            //DEBUG(tmp);
        }
        
        printf("%llu %llu\n",n/ans,ans);
    }

    return 0;
}
