//
//  gFiles.cpp
//  apac
//
//  Created by shawpan on 10/24/15.
//  Copyright (c) 2015 shawpan. All rights reserved.
//

#include <iostream>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<string> vstr;

inline void FREOPEN (string s) {
    freopen ((s + ".in").c_str (), "r", stdin);
    freopen ((s + ".out").c_str (), "w", stdout);
}

#define FORL(var,start,end) for (int (var)=(start);(var)<(end);++(var))
#define FORLE(var,start,end) for (int (var)=(start);(var)<=(end);++(var))
#define FORLER(var,start,end) for (int (var)=(start);(var)>=(end);--(var))

ll minValue = 1000000000000000000LL;
ll maxValue = -1000000000000000000LL;

ll getMaxEstimate (ll percent, ll value)
{
    ll left = 1;
    ll right = 1000000000000000000LL;
    ll ans;
    while (right >= left) {
        ll mid = (left + right) / 2;
        if ((value * 100) / mid > percent) {
            left = mid + 1;
        } else {
            right = mid - 1;
            ans = mid;
        }
    }
    
    return ans;
};

ll getMinEstimate (ll percent, ll value)
{
    ll left = 1;
    ll right = 1000000000000000000LL;
    ll ans;
    while (right >= left) {
        ll mid = (left + right) / 2;
        if ((value * 100) / mid < percent) {
            right = mid - 1;
        } else {
            left = mid + 1;
            ans = mid;
        }
    }
    
    return ans;
};

int main(int argc, const char * argv[])
{
    ll tc, n, p, k;
    cin>>tc;
    FORLE(caseNo, 1, tc) {
        
        minValue = 1000000000000000000LL;
        maxValue = -1000000000000000000LL;
        cout<<"Case #"<<caseNo<<": ";
        cin>>n;
        FORL(i, 0, n) {
            cin>>p>>k;
            if (p == 100) {
                minValue = maxValue = k;
            }
            ll minEstimate = getMinEstimate(p, k);
            ll maxEstimate = getMaxEstimate(p, k);
            
            minValue = minValue < minEstimate ? minValue : minEstimate;
            maxValue = maxValue > maxEstimate ? maxValue : maxEstimate;
        }
        if ( minValue != maxValue) {
            cout<< "-1"<<endl;
        } else {
            cout<<minValue<<endl;
        }
    }
    
    return 0;
}