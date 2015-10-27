//
//  gCube.cpp
//  apac
//
//  Created by shawpan on 8/23/15.
//  Copyright (c) 2015 shawpan. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;


long nValues[1100];

int main(int argc, const char * argv[])
{
    long tc, i, n, m, j, l, r, d, k;
    long double a;
    cin >> tc;
    for (i=1; i<= tc; i++) {
        cout << "Case #" <<i <<":" <<endl;
        cin >> n >> m;
        for (j=0; j<n; j++) {
            cin >> nValues[j];
        }
        for (j=0; j<m; j++) {
            cin >> l >> r;
            d = r - l + 1;
            a = 1.0;
            for (k=l; k<=r; k++) {
                a *= (long double)pow(nValues[k], 1.0/(long double)d);
            }
            printf("%.9Lf\n", a);
        }
    }
}