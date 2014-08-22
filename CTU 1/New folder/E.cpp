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
#define INF 1000000000
#define PI 3.1415926535897932384626433832795
#define read(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
#define DEBUG(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)

using namespace std;

int tcs;
char a[1000000],b[1000000];

int main()
{
    freopen("E.INP","r",stdin);
    freopen("E.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int t=1;t<=tcs;t++)
    {
        scanf(" %s %s ",&a,&b);
        int lena=strlen(a);
        int lenb=strlen(b);
        int cnt=0;
        for(int i=0;i<lena;i++)
        {
            bool check=true;
            for(int j=0;j<lenb && check && i+j<lena;j++)
            {
                if(a[i+j]!=b[j]) check=false;
            }
            if(check) cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
