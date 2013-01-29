// Copyright (C) 2012 - Tencent Inc.
// Author: Liu Shaohui (struggleliu@tencent.com)
//
// Created: 04/15/2012 14:53:42
// Description:
//

#include <stdio.h>

#include <algorithm>
#include <vector>

#define LL long long

using namespace std;

class Choice {
public:
    explicit Choice(LL k): m_k(k) {
        Init();
    }
    void Exclude(LL a) {
        vector<int> cur;
        for (int i = 0; i < m_primes.size(); i++) {
            int t = 0;
            while (a % m_primes[i] == 0) {
                a = a / m_primes[i];
                t++;
            }
            cur.push_back(t);
            if (t < m_used[i]) return;
        }
        for (int i = 0; i < m_primes.size(); i++) {
            m_used[i] = cur[i];
        }
    }
    LL GetNum() {
        LL ret = 1;
        for(int i = 0; i < m_nums.size(); i++){
            if (m_used[i] > m_nums[i]) return 0;
            ret = ret * (m_nums[i] - m_used[i] + 1);
        }
        return ret - 1;
    }
private:
    void Init() {
        bool flag[kMaxValue];
        for (LL i = 0; i < kMaxValue; i++) flag[i] = true;
        flag[0] = flag[1] = false;
        flag[2] = true;
        LL tmp = m_k;
        for (LL i = 2; i < kMaxValue; i++) {
            if (i > tmp) break;
            if (flag[i]) {
                int t = 0;
                while (tmp % i == 0) {
                    tmp = tmp / i;
                    t++;
                }

                if (t > 0) {
                    m_primes.push_back(i);
                    m_nums.push_back(t);
                }

                for (LL j = i; i * j < kMaxValue; j ++) {
                    flag [i * j] = false;
                }
            }
        }
        if (tmp != 1) {
            m_primes.push_back(tmp);
            m_nums.push_back(1);
        }
        for (int i = 0; i < m_nums.size(); i++) {
            // printf("%lld %d\n", m_primes[i], m_nums[i]);
            m_used.push_back(0);
        }
    }
private:
    static const int kMaxValue = 4000000;
    LL m_k;
    vector<LL> m_primes;
    vector<int> m_nums;
    vector<int> m_used;
};

int main() {
    int n;
    LL k, a;
    scanf("%d%lld", &n, &k);
    Choice choice(k);
    for(int i = 0; i < n; i++) {
        scanf("%lld", &a);
        choice.Exclude(a);
    }
    printf("%lld\n", choice.GetNum());
    return 0;
}
