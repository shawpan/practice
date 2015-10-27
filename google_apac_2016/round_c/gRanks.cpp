//
//  gRanks.cpp
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
typedef vector<string> vstr;

inline void FREOPEN (string s) {
    freopen ((s + ".in").c_str (), "r", stdin);
    freopen ((s + ".out").c_str (), "w", stdout);
}

#define FORL(var,start,end) for (int (var)=(start);(var)<(end);++(var))
#define FORLE(var,start,end) for (int (var)=(start);(var)<=(end);++(var))
#define FORLER(var,start,end) for (int (var)=(start);(var)>=(end);--(var))

struct Athlete {
    int totalScore;
    string name;
};

bool sortDec (ll  i,ll j) { return (i > j); }
bool finalSort (Athlete  &i,Athlete &j) {
    return i.totalScore != j.totalScore ? (i.totalScore > j.totalScore) : i.name < j.name;
}

int main(int argc, const char * argv[])
{
    int tc, p,s[101], n, m;
    map<string,vll> athletes;
    vector<Athlete> result;
    cin>>tc;
    
    FORLE(caseNo, 1, tc) {
        athletes.clear();
        result.clear();
        cout<<"Case #"<<caseNo<<":"<<endl;
        cin>>p;
        FORL(i, 0, p) {
            cin>>s[i];
        }
        cin>>n;
        FORL(i, 0, n) {
            string name;
            int w;
            cin>>w;
            FORL(j,0, p) {
                cin>>name;
                athletes[name].push_back(w * s[j]);
            }
        }
        cin>>m;
        
        for(map<string, vll>::iterator it = athletes.begin(); it != athletes.end(); ++it) {
            sort(it->second.begin(), it->second.end(), sortDec);
            Athlete a;
            a.totalScore = 0;
            a.name = it->first;
            FORL(i, 0, min((int)it->second.size(), m)) {
                a.totalScore += it->second[i];
            }
            result.push_back(a);
        }
        sort(result.begin(), result.end(), finalSort);
        FORL(i, 0, result.size()) {
            int rank = 1;
            FORLER(j, i-1, 0) if (result[j].totalScore > result[i].totalScore) rank++;
            cout<<rank<<": "<<result[i].name<<endl;
        }
        
    }
}