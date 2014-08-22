//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 1082 - Array Queries
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

int a[100005];
int T[500005];

int bTree(int node, int lf, int rg)
{
	if(lf == rg)
		return T[node] = a[lf];
	
	int mid = (lf+rg)/2;
	
	bTree(node*2,lf,mid);
	bTree(node*2+1,mid+1,rg);
	
	T[node] = min(T[node*2],T[node*2+1]);
}

int search(int node, int lf, int rg, int r1, int r2)
{
	if(r1 <= lf && rg <= r2)
		return T[node];
	
	if(rg < r1 || r2 < lf)
		return INF;
	
	int mid = (lf+rg)/2;
	
	int left = search(node*2,lf,mid,r1,r2);
	int right = search(node*2+1,mid+1,rg,r1,r2);
	
	return min(left,right);
}

int main()
{
	freopen("1082 - Array Queries.INP","r",stdin);
	freopen("1082 - Array Queries.OUT","w",stdout);
	int tcs,n,q;
	scanf(" %d ",&tcs);
	for(int t = 1 ; t <= tcs ; t++)
	{
		scanf(" %d %d ",&n,&q);
		for(int i = 0 ; i < n ; i++)
			scanf(" %d ",&a[i]);
		
		bTree(1,0,n-1);
		printf("Case %d:\n",t);
		for(int i = 0 ; i < q ; i++)
		{
			int r1,r2;
			scanf(" %d %d ",&r1,&r2);
			int ans = search(1,0,n-1,r1-1,r2-1);
			printf("%d\n",ans);
		}
	}
	return 0;
}

