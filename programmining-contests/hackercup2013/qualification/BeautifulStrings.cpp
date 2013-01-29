#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>

#define maxn 1024

using namespace std;

char input[maxn];
int calc[26];

int main() {
	int cases;
	scanf("%d", &cases);
	gets(input);
	for (int k = 0; k < cases; ++k) {
		gets(input);
		int length = strlen(input);
		memset(calc, 0, 26 * sizeof(calc[0]));
		for (int i = 0; i < length; i++) {
        	if (input[i] >= 'a' && input[i] <= 'z') calc[input[i] - 'a']++;
        	if (input[i] >= 'A' && input[i] <= 'Z') calc[input[i] - 'A']++;  
		}
		sort(calc, calc + 26);
		int sum = 0;
		for (int i = 25; i >=0 ; --i) {
			sum += (i + 1) * calc[i];
		}
		printf("Case #%d: %d\n", k + 1, sum);
	}
	return 0;
}
