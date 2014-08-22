//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 1347 - Aladdin and the Magical Lamp
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
#define maxN 100000

string s,a,b,c;
int n;
int SA[maxN+5];
int RA[maxN+5];
int tmp[maxN+5];
int cnt[maxN+5];
int Phi[maxN+5];
int PLCP[maxN+5];
int LCP[maxN+5];
int Owner[maxN+5];

int getOwner(int k)
{
    if(k < sz(a)) return 0;
    if(k < sz(a) + 1 + sz(b)) return 1;
    return 2;
}

void countingSort(int k)
{
    int maxi = max(300,n);
    int sum = 0;
    
    memset(cnt,0,sizeof(cnt));
    rep(i,n)
        cnt[i+k < n ? RA[i+k] : 0]++;
    
    for(int i = 0 ; i < maxi ; i++)
    {
        int t = cnt[i];
        cnt[i] = sum;
        sum += t;
    }
    
    rep(i,n)
        tmp[cnt[SA[i] + k < n ? RA[SA[i]+k] : 0]++] = SA[i];
        
    rep(i,n)
        SA[i] = tmp[i];
}

void constructSA()
{
    rep(i,n) RA[i] = s[i] - '.';
    rep(i,n) SA[i] = i;
    
    for(int k = 1 ; k < n ; k <<= 1)
    {
        countingSort(k);
        countingSort(0);
        
        int r = tmp[SA[0]] = 0;
        
        for(int i = 1 ; i < n ; i++)
            tmp[SA[i]] = (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;
        
        rep(i,n) RA[i] = tmp[i];
    }
}

void computeLCP()
{
    int L = 0;
    Phi[SA[0]] = -1;
    for(int i = 1 ; i < n ; i++)
        Phi[SA[i]] = SA[i-1];
    
    rep(i,n)
    {
        if(Phi[i] == -1)
        {
            PLCP[i] = 0;
            continue;
        }
        
        while(s[i+L] == s[Phi[i]+L]) L++;
        
        PLCP[i] = L;
        L = max(L-1,0);
    }
    
    for(int i = 1 ; i < n ; i++)
        LCP[i] = PLCP[SA[i]];
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("1347 - Aladdin and the Magical Lamp.INP","r",stdin);
    freopen("1347 - Aladdin and the Magical Lamp.OUT","w",stdout);
    #endif
    
    int tcs;
    
    scanf("%d",&tcs);
    
    fr(t,1,tcs)
    {
        getchar();
        read3(a,b,c);
        
        s = a + '.' + b + '.' + c;
        n = sz(s);
        
        constructSA();
        computeLCP();
        
        int ans = 0;
        for(int i = 4 ; i < n ; i++)
        {
            int u = getOwner(SA[i]);
            int v = getOwner(SA[i-1]);
            int w = getOwner(SA[i-2]);
            
            if(u == v || u == w || v == w) continue;
            ans = max(ans, min(LCP[i],LCP[i-1]));
        }
        
        printf("Case %d: %d\n",t,ans);
    }
    
    return 0;
}
