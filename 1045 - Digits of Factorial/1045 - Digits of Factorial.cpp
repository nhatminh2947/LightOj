//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 1045 - Digits of Factorial
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

using namespace std;

#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define dw(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define sz(s) (int)s.size()
#define read(x) cin >> x
#define read2(x,y) cin >> x >> y
#define read3(x,y,z) cin >> x >> y >> z
#define out(x) cout << x
#define DEBUG(x) cout << #x << " = " << x << endl

#define ull unsigned long long
#define ll long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define BIT(n) (1<<(n))
#define AND(a,b) ((a) & (b))
#define OR(a,b) ((a)  (b))
#define XOR(a,b) ((a) ^ (b))
#define sqr(x) ((x) * (x))

typedef pair<int,int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 1000000

double a[maxN+5];

void preCal()
{
    a[0] = 0;
    a[1] = 0;
    fr(i,2,1e6) a[i] = a[i-1] + log10(i);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("1045 - Digits of Factorial.INP","r",stdin);
    freopen("1045 - Digits of Factorial.OUT","w",stdout);
    #endif
    
    preCal();
    int tcs,n,b;
    scanf(" %d ",&tcs);
    
    fr(t,1,tcs)
    {
        scanf(" %d %d ",&n,&b);
        //double ans = a[n];
        double ans = a[n]/log10(b) + 1;
        printf("Case %d: %d\n",t,int(ans));
    }
    
    return 0;
}
