//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 1043 - Triangle Partitioning
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
#define maxN 123456
#define INF 1000111222

using namespace std;

double ab,ac,bc,r,h;

double area1(double a, double b, double c)
{
	double p = (a + b + c) / 2;
	return sqrt(p*(p-a)*(p-b)*(p-c));
}

double area2(double a, double b, double h)
{
	return (a + b) * h / 2;
}

double area3(double bc, double H)
{
	return bc*H/2;
}

double bSearch(double x)
{
	double lo1 = 0;
	double hi1 = bc;
	double lo2 = 0;
	double hi2 = h;
	double lo3 = 0;
	double hi3 = ab;
	double height, de, ad;
	for(int i = 0 ; i < 100 ; i++)
	{
		de = (lo1 + hi1) / 2;
		height = (lo2 + hi2) / 2;
		ad = (lo3 + hi3) / 2;
		
		double ade = area3(de,height);
		double bced = area2(de,bc,h - height);
		double ratio = ade / bced;
		if(ratio <= r)
		{
			lo1 = de;
			lo2 = height;
			lo3 = ad;
		}
		else
		{
			hi1 = de;
			hi2 = height;
			hi3 = ad;
		}
	}
	
	return ad;
}

int main()
{
	freopen("1043 - Triangle Partitioning.INP","r",stdin);
	freopen("1043 - Triangle Partitioning.OUT","w",stdout);
	int tcs;
	scanf(" %d ",&tcs);
	for(int t = 1 ; t <= tcs ; t++)
	{
		scanf(" %lf %lf %lf %lf ",&ab,&ac,&bc,&r);
		double S = area1(ab,bc,ac);
		h = 2*S / bc;
		
		double ad = bSearch(r);
		printf("Case %d: %.10lf\n",t,ad);
	}
	return 0;
}

