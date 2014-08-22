//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: I - Problems of History
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

int tcs;
bool n[15];

int gcd(int a,int b)
{
    if(b%a == 0)
        return a;
    return gcd(b%a,a);
}

int main()
{
    freopen("I - Problems of History.INP","r",stdin);
    freopen("I - Problems of History.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int t = 1 ; t <= tcs ; t++)
    {
        printf("Case %d: ",t);
        
        char tmp[25];
        scanf(" %s ",&tmp);
        int a,b;
        sscanf(tmp,"%d/%d",&a,&b);
        int k = gcd(max(a,b),min(a,b));
        a /= k;
        b /= k;
        int i = 1;
        fill(n,n+10,false);
        int cnt = 0;
        bool ans = false;
        while(!ans && (a*i)*(b*i) < INF)
        {
            cnt = 0;
            int aa = a*i;
            int bb = b*i;
            if(aa * bb <= 10000000)
            {
                i++;
                continue;
            }
            while(aa)
            {
                if((aa%10 != 0) && !n[aa%10])
                {
                    n[aa%10] = true;
                    cnt++;
                }
                aa /= 10;
            }
            while(bb)
            {
                if((bb%10 != 0) && !n[bb%10])
                {
                    n[bb%10] = true;
                    cnt++;
                }
                bb /= 10;
            }
            fill(n,n+10,false);
            if(cnt == 9) ans = true;
            else i++;
        }
        if(ans) printf("%d %d\n",a*i,b*i);
        else printf("impossible\n");
    }
    return 0;
}
