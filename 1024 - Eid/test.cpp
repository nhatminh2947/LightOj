//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 1024 - Eid
// Verdict: 
//******************************************************************

#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <ctime>

#define pb push_back
#define test printf("I'm here\n")
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
        
        BigNum operator * (int k)
        {
            BigNum res;
            int sz = n.size();
            int r = 0;
            for(int i = sz-1 ; i >= 0 ; i--)
            {
                int d = (n[i] - '0')*k + r;
                res.n = char(d%10 + '0') + res.n;
                r = d/10;
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

int pre_cal[10005];
vector<int> primes;
bool check[10005];

void sieve()
{
    for(int i = 0 ; i <= 10000 ; i++)
        check[i] = true;
    
    for(int i = 2 ; i <= 10000 ; i++)
    {
        if(check[i])
        {
            primes.pb(i);
            for(int j = i ; i*j <= 10000 ; j++)
                check[i*j] = false;
        }
    }
}

int primeFactorize(int m)
{
    int sz = primes.size();
    for(int i = 0 ; primes[i] <= m ; i++)
    {
        if(m % primes[i] == 0)
        {
            int k = primes[i];
            int p = 0;
            while(m % k == 0)
            {
                k *= primes[i];
                p++;
            }
            
            pre_cal[primes[i]] = max(pre_cal[primes[i]],p);
        }
    }
}

int main()
{
    //freopen("1024 - Eid.INP","r",stdin);
    freopen("1024 - Eid.INP","w",stdout);
    int tcs = 225;
    
    printf("%d\n",tcs);
    for(int t = 1 ; t <= tcs ; t++)
    {
        printf("%lld %d\n",rand(),rand()%INF);
    }
    
    return 0;
}
