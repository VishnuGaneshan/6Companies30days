/*question details
name: Invalid Transactions in an EMI
link: https://leetcode.com/problems/invalid-transactions/
submission: https://leetcode.com/problems/invalid-transactions/submissions/875574311/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    struct Trans {
        void load(string& name, string& s) {
            auto pos = s.find(',');

            name = s.substr(0, pos);

            auto ps1 = s.find(',', ++pos);
            tm = atoi(s.substr(pos, ps1 - pos).c_str());

            pos = s.find(',', ++ps1);
            sum = atoi(s.substr(ps1, pos - ps1).c_str());

            city = s.c_str() + pos + 1;
            orig = &s;
        }

        int tm;
        int sum;
        const char* city;
        string* orig;
    };

    static bool isInvalid(const Trans& r, const vector<Trans>& vv) {
        if (r.sum >= 1000) return true;
        
        for (const auto& t: vv) {
            if (abs(r.tm - t.tm) <= 60) {
                if (strcmp(r.city, t.city))
                    return true;
            }
        }
        return false;
    }
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        map<string, std::vector<Trans>> mm;

        Trans rec;
        string name;
        for (auto& s: transactions) {
            rec.load(name, s);
            mm[std::move(name)].push_back(rec);
        }
        
        vector<string> ret;

        for (const auto& pr: mm) {
            for (auto& tr: pr.second) {
                if (isInvalid(tr, pr.second))
                    ret.push_back(std::move(*tr.orig));
            }
        }
        
        return ret;
    }
};