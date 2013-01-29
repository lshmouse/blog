// Copyright_half (C) 2012 - Tencent Inc.
// Author: Liu Shaohui (struggleliu@tencent.com)
//
// Created: 10/15/2012 20:35:16
// Description: Median ,using two multiset

#include <stdio.h>
#include <iostream>

#include <algorithm>
#include <set>

using namespace std;

multiset<int> left_half, right_half;

void balance() {
    if (left_half.size() > right_half.size()) {
        multiset<int>::iterator iter = left_half.end();
        --iter;
        right_half.insert(*iter);
        left_half.erase(iter);
    }

    if (right_half.size() > left_half.size() + 1) {
        multiset<int>::iterator iter = right_half.begin();
        left_half.insert(*iter);
        right_half.erase(iter);
    }
}

int main() {
    int n;
    while (1 == scanf("%d", &n)) {

        left_half.clear();
        right_half.clear();

        char key[16];
        int v;

        for (int i = 0; i < n; i++) {

            scanf("%s%d", key, &v);
            if (key[0] == 'r') {

                multiset<int>::iterator left_half_itr = left_half.find(v);
                multiset<int>::iterator right_half_itr = right_half.find(v);

                if (left_half_itr != left_half.end()) {
                    left_half.erase(left_half_itr);
                } else if (right_half_itr != right_half.end()) {
                    right_half.erase(right_half_itr);
                } else {
                    printf("Wrong!\n");
                    continue;
                }
            } else if (key[0] == 'a') { // add
                if (right_half.size() == 0) {
                    right_half.insert(v);
                } else if (v < (*right_half.begin())){
                    left_half.insert(v);
                } else {
                    right_half.insert(v);
                }
            }

            balance();

            if (left_half.size() + right_half.size() == 0) {
                printf("Wrong!\n");
            } else if(left_half.size() + 1 == right_half.size()) {
                printf("%d\n", *right_half.begin());
            } else if (left_half.size() == right_half.size()){
                multiset<int>::iterator iter = left_half.end();
                --iter;
                long long sum = *iter;
                sum += *right_half.begin();

                if (sum % 2 == 0){
                    printf("%lld\n", sum / 2);
                } else {
                    printf("%lld.5\n", sum / 2);
                }

            }
        }
    }
    return 0;
}
