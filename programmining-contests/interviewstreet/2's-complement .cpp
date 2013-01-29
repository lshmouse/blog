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

#define llong long long

int GetBits(unsigned int a) {
	int ret = 0;
	while (a > 0) {
		ret++;
		a = a & (a -1);
	}
	return ret;
}

llong Solve(int a) {
	if (a >= 0){
		if (a == 0) return 0;
		else if ((a %2) == 0) return Solve(a - 1) + GetBits(a);
		else return 2 * Solve( a / 2) + ((llong)a + 1) / 2;
	}else {
		a++;
		// ~(-X) = X - 1
		return ((llong)(-a) + 1) * 32 - Solve(-a);
	}
}

int main(){
	int cases, a, b;
	scanf("%d",&cases);
	for (int i = 0; i< cases; ++i) {
		scanf("%d%d", &a, &b);
		if (a >= 0)
			printf("%lld\n", Solve(b) - Solve(a) + GetBits(a));
		else if (b <0)
			printf("%lld\n", Solve(a) - Solve(b + 1));
		else 
			printf("%lld\n", Solve(b) + Solve(a));
	}	
	return 0;
}
