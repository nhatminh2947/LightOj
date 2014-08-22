//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: G - Leading and Trailing
// Verdict: 
//******************************************************************

#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <iostream>

using namespace std;

class BigNum
{
    string n;
    public:
        BigNum()
        {
            n = "";
        }
        
        friend istream& operator >> (istream &is, BigNum &n)
        {
            is >> n;
            return is;
        }
        
        friend ostream& operator << (ostream &os, BigNum &n)
        {
            os << n;
            return os;
        }
        
        BigNum operator * (BigNum a)
        {
            int 
        }
};

int main()
{
    freopen("G.INP","r",stdin);
    freopen("G.OUT","w",stdout);
    int tcs;
    scanf(" %d ",&tcs);
    for(int t = 1 ; t <= tcs ; t++)
    {
        BigNum n;
        int k;
        cin >> n >> k;
    }
    return 0;
}
