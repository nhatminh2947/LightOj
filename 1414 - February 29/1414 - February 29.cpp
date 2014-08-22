//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 1414 - February 29
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

map<string,int> M;
int day[15] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void init()
{
    M["January"] = 1;
    M["February"] = 2;
    M["March"] = 3;
    M["April"] = 4;
    M["May"] = 5;
    M["June"] = 6;
    M["July"] = 7;
    M["August"] = 8;
    M["September"] = 9;
    M["October"] = 10;
    M["November"] = 11;
    M["December"] = 12;
}

int main()
{
    freopen("1414 - February 29.INP","r",stdin);
    freopen("1414 - February 29.OUT","w",stdout);
    int tcs;
    char s[100];
    scanf(" %s ",s);
    sscanf(s," %d ",&tcs);
    init();
    for(int t = 1 ; t <= tcs ; t++)
    {
        int y1,d1,m1,y2,d2,m2;
        char m[15];
        gets(s);
        sscanf(s,"%s %d, %d",&m,&d1,&y1);
        m1 = M[m];
        gets(s);
        sscanf(s,"%s %d, %d",&m,&d2,&y2);
        m2 = M[m];
        
        int ans = (y2/4 - y2/100 + y2/400) - (y1/4 - y1/100 + y1/400);
        
        DEBUG(y2/4);
        DEBUG(y2/100);
        DEBUG(y2/400);
        DEBUG(y1/4);
        DEBUG(y1/100);
        DEBUG(y1/400);
        if(m1 > 2 && ((y1%4 == 0 && y1%100) || y1%400 == 0))
            ans--;
        
        if(((y2%4 == 0 && y2%100) || y2%400 == 0) && ((m2 == 1) || (m2 == 2 && (d2 <= 28))))
            ans--;
        
        
        printf("Case %d: %d\n",t,ans);
    }
    return 0;
}

