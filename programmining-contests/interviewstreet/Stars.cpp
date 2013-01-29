// Copyright (C) 2012 - Tencent Inc.
// Author: Liu Shaohui (struggleliu@tencent.com)
//
// Created: 10/15/2012 10:43:18
// Description:

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

#define maxn 128
#define llong long long

struct Point{
    int x, y, w;
};

int n, sum;
Point points[maxn];

bool cmp(const Point&a, const Point& b) {
	if(a.x != b.x) return a.x < b.x;
	else return a.y < b.y;
}

llong divide(int i, int j, int k) {
	llong ax = 1LL * points[i].x - points[k].x;
	llong ay = 1LL * points[i].y - points[k].y;
	
	llong bx = 1LL * points[j].x - points[k].x;
	llong by = 1LL * points[j].y - points[k].y;
	
	return (ax *by - bx*ay);
}

int Calc(int a, int b) {
    int sum_left = 0;
    vector<int> lines;
    for(int i = 0; i < n; i++) {
        if (divide(a, b, i) > 0) {
            sum_left += points[i].w;
        } else if (divide(a ,b , i) == 0) {
            lines.push_back(i);
        }
    }
    
	int ret = min(sum_left, sum - sum_left);
	
	int tmp = 0;
	for(int i = 0; i < lines.size(); i++){
        tmp += points[lines[i]].w;
        ret = max(ret, min(sum_left + tmp, sum - sum_left - tmp));
    }
    
    tmp = 0;
    for(int i = 0; i < lines.size(); i++){
        tmp += points[lines[lines.size() - 1 - i]].w;
        ret = max(ret, min(sum_left + tmp, sum - sum_left - tmp));
    }
    return ret;
}

int Solve() {
    sort(points, points + n, cmp);
	int ret = 0;
    for (int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j ++) {
            ret = std::max(ret, Calc(i, j));
        }
    }
    return ret;
}

int main() {
    while (1 == scanf("%d", &n)) {
        sum = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d%d%d", &points[i].x, &points[i].y, &points[i].w);
            sum += points[i].w;
        }
		printf("%d\n", Solve());
    }
    return 0;
}
