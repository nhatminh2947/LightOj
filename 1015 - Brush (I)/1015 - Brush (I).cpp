//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code:  1015 - Brush (I)
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
#define i64 long long
#define u64 unsigned long long
#define PI 3.1415926535897932384626433832795
#define read(x) scanf("%d",&x)
#define out(x) printf("%d",x)
#define DEBUG(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)
#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define maxN 123456
#define INF 1000111222

using namespace std;

int main()
{
    freopen("1015 - Brush (I).INP","r",stdin);
    freopen("1015 - Brush (I).OUT","w",stdout);
    int tcs;
    char s[4000];
    scanf(" %s ",&s);
    sscanf(s," %d ",&tcs);
    for(int t = 1 ; t <= tcs ; t++)
    {
        scanf(" %s ",&s);
        gets(s);
        //DEBUG(s);
        int sum = 0;
        int neg = 1;
        int sz = strlen(s);
        //DEBUG(sz);
        int m = 0;
        for(int i = 0 ; i < sz ; i++)
        {
            if(s[i] == ' ')
            {
                m *= neg;
                neg = 1;
                if(m > 0) sum += m;
                m = 0;
                continue;
            }
            
            if(s[i] == '-')
            {
                neg = -1;
                continue;
            }
            
            m = m*10 + (s[i] - '0');
        }
        m *= neg;
        if(m > 0) sum += m;
        printf("Case %d: %d\n",t,sum);
    }
    return 0;
}

