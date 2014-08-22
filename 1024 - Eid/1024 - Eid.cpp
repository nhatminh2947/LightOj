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
#define int64 long long
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

class BigNum
{
    string n;
    public:
        BigNum()
        {
            n = "";
        }
        
        BigNum(string a)
        {
            n = a;
        }
        
        BigNum operator * (int64 k)
        {
            BigNum res;
            int64 sz = n.size();
            int64 r = 0;
            for(int64 i = sz-1 ; i >= 0 ; i--)
            {
                r = (n[i] - '0')*k + r;
                res.n = char(r%10 + '0') + res.n;
                r /= 10;
            }
            
            while(r)
            {
                res.n = char(r%10 + '0') + res.n;
                r /= 10;
            }
            
            return res;
        }
        
        friend ostream& operator << (ostream &os, BigNum m)
        {
            os << m.n;
            return os;
        }
        
};

int64 pre_cal[10005];
vector<int64> primes;
bool check[10005];

void sieve()
{
    for(int64 i = 0 ; i <= 10000 ; i++)
        check[i] = true;
    
    for(int64 i = 2 ; i <= 10000 ; i++)
    {
        if(check[i])
        {
            primes.pb(i);
            for(int64 j = i ; i*j <= 10000 ; j++)
                check[i*j] = false;
        }
    }
}

void primeFactorize(int64 m)
{
    int64 sz = primes.size();
    int64 i = 0;
    
    if(!check[m])
    {
        while(m != 1)
        {
            if(m % primes[i] == 0)
            {
                int64 k = 1;
                while(m % primes[i] == 0)
                {
                    m /= primes[i];
                    k *= primes[i];
                }
                pre_cal[primes[i]] = max(pre_cal[primes[i]],k);
            }
            i++;
        }
    }
    else pre_cal[m] = m;
}

int main()
{
    freopen("1024 - Eid.INP","r",stdin);
    freopen("1024 - Eid.OUT","w",stdout);
    int64 tcs;
    sieve();
    scanf(" %lld ",&tcs);
    for(int64 t = 1 ; t <= tcs ; t++)
    {
        int64 n;
        for(int64 i = 0 ; i <= 10000 ; i++)
            pre_cal[i] = -INF;
        
        scanf(" %lld ",&n);
        for(int64 i = 0 ; i < n ; i++)
        {
            int64 tmp;
            scanf(" %lld ",&tmp);
            primeFactorize(tmp);
        }
        
        BigNum ans("1");
        vector<int64> cal;
        int64 k = 1;
        
        int64 sz = primes.size();
        for(int64 i = 0 ; i < sz ; i++)
        {
            if(pre_cal[i] > 1)
                k *= pre_cal[i];
            if(k > 1000)
            {
                cal.pb(k);
                k = 1;
            }
        }
        
        if(k != 1)
            cal.pb(k);
        
        sz = cal.size();
        for(int64 i = 0 ; i < sz ; i++)
            ans = ans * cal[i];
        
        printf("Case %lld: ",t);
        cout << ans << endl;
    }
    
    return 0;
}
