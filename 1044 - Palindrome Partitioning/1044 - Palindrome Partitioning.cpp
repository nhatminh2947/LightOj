//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 1044 - Palindrome Partitioning
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
char s[1005];
bool p[1005][1005];
int F[1005];


void pre_cal()
{
    int len = strlen(s);
    p[len-1][len-1] = true;
    for(int i = 0 ; i < len-1 ; i++)
    {
        p[i][i] = true;
        p[i+1][i] = (s[i] == s[i+1]);
    }
    for(int i = len-1 ; i >= 0 ; i--)
        for(int j = i+1 ; j < len ; j++)
            if(s[i] == s[j])
                p[i][j] = p[i+1][j-1];
            else p[i][j] = false;
    
}

int main()
{
    //freopen("1044 - Palindrome Partitioning.INP","r",stdin);
    //freopen("1044 - Palindrome Partitioning.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int t = 1 ; t <= tcs ; t++)
    {
        scanf(" %s ",&s);
        pre_cal();
        int sz = strlen(s);
        
        fill(F,F+sz+3,INF);
        F[0] = 0;
        
        for(int i = 1 ; i <= sz ; i++)
            for(int j = 1 ; j <= i ; j++)
                if(p[j-1][i-1])
                    F[i] = min(F[i],F[j-1]+1);
        
        printf("Case %d: %d\n",t,F[sz]);
    }
    return 0;
}
