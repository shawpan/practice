//
//  gMatrix.cpp
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
#include <queue>
#include <set>
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

#define SIZE 3010

int tc, n, k, c, x;
int a[SIZE], b[SIZE];
int m1[SIZE][SIZE], m2[SIZE][SIZE];

int main(int argc, const char * argv[])
{
    cin>>tc;
    FORLE(caseNo, 1, tc) {
        cout<<"Case #"<<caseNo<<": ";
        cin >> n >> k >> c >> x;
        
        FORLE(i, 1, n) cin>>a[i];
        
        FORLE(i, 1, n) cin>>b[i];
        
        FORLE(i, 1, n) {
            FORLE(j, 1, n) {
                m1[i][j] = ( ((ll)a[i] * i + (ll)b[j] * j) + c ) % x;
            }
        }
        
        FORLE(i, 1, n) {
            multiset<int, greater<int> > q;
            FORLE(j, 1, k) q.insert(m1[i][j]);
            FORLE(j, 1, n-k+1) {
                int mx = *(q.begin());
                q.erase(q.find(m1[i][j]));
                m2[i][j] = mx;
                if (j+k <= n) q.insert(m1[i][j+k]);
            }
        }
        
        ll sum = 0;
        FORLE(j, 1, n-k+1) {
            multiset<int, greater<int> > q;
            FORLE(i, 1, k) q.insert(m2[i][j]);
            FORLE(i, 1, n-k+1) {
                int mx = *(q.begin());
                sum += mx;
                q.erase(q.find(m2[i][j]));
                if (i+k <= n) q.insert(m2[i+k][j]);
            }
        }
        
        cout<<sum<<endl;
    }
    
    return 0;
}