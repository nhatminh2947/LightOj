//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 1128 - Greatest Parent
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
#include <cctype>
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

int T[100005];
int val[100005];
int P[100005][20];
int L[100005];

void build()
{
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; 1 << j < n ; j++)
			P[i][j] = -1;
	
	for(int i = 0 ; i < n ; i++)
		P[i][0] = T[i];
	
	for(int j = 1 ; 1 << j < n ; j++)
		for(int i = 0 ; i < n ; i++)
			if(P[i][j-1] != -1)
				P[i][j] = P[P[i][j-1]][j-1];
}

int main()
{
	freopen("1128 - Greatest Parent.INP","r",stdin);
	freopen("1128 - Greatest Parent.OUT","w",stdout);
	scanf(" %d ",&tcs);
	for(int t = 1 ; t <= tcs ; t++)
	{
		scanf(" %d %d ",&n,&q);
		L[0] = 0;
		for(int i = 1 ; i < n ; i++)
		{
			int p,v;
			scanf(" %d %d ",&p,&v);
			L[i] = L[p]+1;
			T[i] = p;
			val[i] = v;
		}
		
		
	}
	return 0;
}

