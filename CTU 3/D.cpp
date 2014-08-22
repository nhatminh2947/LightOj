//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: D
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

int tcs;

long long mod(string x, long long m) {
    long long d = 0;
    long long sz=x.size();
    for (long long i=0;i<sz;i++)
    {
        //if(x[i]=='-') continue;
        d = (d * 10 + x[i] - '0') % m;
    }
    return d;
}

int main()
{
    //freopen("D.INP","r",stdin);
    //freopen("D.OUT","w",stdout);
    string a;
    long long b;
    scanf(" %d ",&tcs);
    for(int t=1;t<=tcs;t++)
    {
        printf("Case %d: ",t);
        cin>>a>>b;
        if(a[0]=='-') a.erase(0,1);
        b=abs(b);
        //cout<<a<<" "<<b<<endl;
        long long res=mod(a,b);
        if(res==0) printf("divisible\n");
        else printf("not divisible\n");
    }
    return 0;
}
