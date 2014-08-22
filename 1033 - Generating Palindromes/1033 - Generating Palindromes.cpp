//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 1033 - Generating Palindromes
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
#define int64 long long
#define u64 unsigned long long
#define PI 3.1415926535897932384626433832795
#define read(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
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

char s[105],r[105];
int F[105][105];

int main()
{
	freopen("1033 - Generating Palindromes.INP","r",stdin);
	freopen("1033 - Generating Palindromes.OUT","w",stdout);
	
	int tcs;
	scanf(" %d ",&tcs);
	for(int t = 1 ; t <= tcs ; t++)
	{
	    scanf(" %s ",&s);
	    int sz = strlen(s);
	    strcpy(r,s);
	    reverse(r,r+sz);
	    //DEBUG(s);
	    //DEBUG(r);
	    for(int i = 0 ; i <= sz ; i++)
            for(int j = 0 ; j <= sz ; j++)
                F[i][j] = 0;
        
        int ans = -INF;
        for(int i = 0 ; i < sz ; i++)
        {
            for(int j = 0 ; j < sz ; j++)
            {
                if(s[i] == r[j])
                    F[i+1][j+1] = F[i][j]+1;
                else F[i+1][j+1] = max(F[i][j+1],F[i+1][j]);
                //printf("%3d",F[i+1][j+1]);
                ans = max(ans,F[i+1][j+1]);
            }
            //printf("\n");
        }
        
        printf("Case %d: %d\n",t,sz-ans);
	}

	return 0;
}

