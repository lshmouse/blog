#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <queue>
#include <map>
#include <list>

using namespace std;

#define uint32_t unsigned int

static const int maxn = 128;

int n;
uint32_t A[maxn];
uint32_t Edge[maxn][maxn];
int Back[maxn];
bool flag[maxn];

bool dfs(int from, uint32_t min_value) {
	for(int to = 0; to < n; to ++){
		if (Edge[from][to]>= min_value){
			if (flag[to] == false){
				flag[to] = true;
				int tmp = Back[to];
				Back[to] = from;
				if (tmp == -1 || dfs(tmp, min_value)){
					return true;
				}
				Back[to] = tmp;
			}
		}
	}
	return false;
}

bool check(uint32_t min_value) {
	for (int i =0; i <n; ++i) {
		Back[i] = -1;
	}	
	for (int i = 0; i < n; ++i){
		for(int j = 0; j < n; j++) {
			flag[j] = false;
		}
		if (!dfs(i, min_value)) return false;
	}
	return true;
}

int main(){
	while(1 == scanf("%d", &n)) {
		for (int i = 0; i < n; i++) {
			scanf("%u", &A[i]);
		}
		for (int i = 0; i < n; ++i) 
			for (int j = 0; j < n; j++) 
				Edge[i][j]= A[i]^A[j];
		int ret = 0;
		int begin = 0;
		int end = 32;
		while (begin <= end) {
			int mid = begin + (end - begin) / 2;
			if (check(1u << mid)) {
				ret = mid;
				begin = mid + 1;
			} else {
				end = mid -1;
			}
		}		
		printf("%d\n", ret);
	}
    return 0;
}
