//
//  gGames.cpp
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


vi forbidden[5];
/**
 0 => undetermined
 -1 => false
 1 => true
 **/
char isValidArrangement[1<<16];
int tc, n, m, e, k, b, f;

int isPossible (int line, int step)
{
    int numberOfPeople = __builtin_popcount(line);
    if (numberOfPeople == 1) {
        return isValidArrangement[line] = 1;
    }
    if ( isValidArrangement[line] != 0) {
        return isValidArrangement[line];
    }
    isValidArrangement[line] = 1;
    FORL(i, 0, forbidden[step].size()) {
        if ( (line & forbidden[step][i]) == forbidden[step][i] ) {
            return isValidArrangement[line] = -1;
        }
    }
    
    FORL(part1, 1, 1<<(1<<n)) {
        if (__builtin_popcount(part1) * 2 == numberOfPeople) {
            int part2 = part1 ^ ((1<<(1<<n)) - 1);
            
            if (isValidArrangement[part1] != -1 && isValidArrangement[part2] != -1) {
                isValidArrangement[line] = (isPossible(part1, step-1) == 1 && isPossible(part2, step-1) == 1) ? 1 : -1;
                
                if ( isValidArrangement[line] == 1) return 1;
            }
        }
    }
    
    return isValidArrangement[line];
};

int main(int argc, const char * argv[])
{
    cin>>tc;
    FORLE(caseNo, 1, tc) {
        
        cout<<"Case #"<<caseNo<<": ";
        cin>>n>>m;
        memset(isValidArrangement, 0, sizeof(char) * (1<<(1<<n)));
        FORLE(i, 1, n) {
            forbidden[i].clear();
        }
        
        FORL(i, 0, m) {
            cin>>e>>k>>b;
            e--;
            FORL(j, 0, b) {
                cin>>f;
                f--;
                int friends = (1<<e) | (1<<f);
                forbidden[k].push_back(friends);
            }
        }
        if (isPossible( ( 1<<(1<<n) ) - 1, n) == 1) {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }
    
    return 0;
}