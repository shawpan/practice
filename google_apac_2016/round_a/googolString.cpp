//
//  googolString.cpp
//  apac
//
//  Created by shawpan on 8/23/15.
//  Copyright (c) 2015 shawpan. All rights reserved.
//

#include <iostream>

using namespace std;

int detremine(long k)
{
    while ( (k % 4) != 3 && (k%2 == 0 && k > 4)) k >>=1;
    
    return (k%4 == 3 ? 1 : 0);
}

int main(int argc, const char * argv[])
{
    long tc, i, k;
    cin >> tc;
    for(i=1;i<=tc;++i) {
        cin >> k;
        cout << "Case #"<<i<<":"<<" "<<detremine(k)<<endl;
    }
    
    return 0;
}

