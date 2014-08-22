//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 
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

deque<int> dq;

int bSearch(int x)
{
	int lo = 0;
	int hi = dq.size();
	int mid;
	int ans;
	while(lo <= hi)
	{
		mid = (lo+hi)/2;
		if(x <= dq[mid])
		{
			hi = mid - 1;
			ans = mid;
		}
		else lo = mid + 1;
	}
	
	return ans;
}

int main()
{
	freopen("C.INP","r",stdin);
	freopen("C.OUT","w",stdout);
	int tcs;
	scanf(" %d ",&tcs);
	for(int t = 1 ; t <= tcs ; t++)
	{
		dq.clear();
		printf("Case %d:\n",t);
		int n;
		scanf(" %d ",&n);
		int a;
		scanf(" %d ",&a);
		dq.pb(a);
		puts("0");
		for(int i = 1 ; i < n ; i++)
		{
			scanf(" %d ",&a);
			if(a >= dq.back())
			{
				printf("%d\n",dq.size());
				dq.pb(a);
			}
			else if(a <= dq.front())
			{
				int cnt = 0;
				while(dq[cnt++] == a);
				printf("%d\n",cnt-1);
				dq.pf(a);
			}
			else
			{
				int pos = bSearch(a);
				if(dq[pos] == a)
				{
					while(dq[pos] == a)
						pos++;
				}
				else if(dq[pos] < a)
					pos++;
				printf("%d\n",pos);
				dq.insert(dq.begin()+pos,a);
			}
			//for(int i = 0 ; i < dq.size() ; i++)
//				printf("%d ",dq[i]);
//			printf("\n");
		}
		
	}
	return 0;
}

