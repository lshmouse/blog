#include <stdio.h>
#include <vector>
#include <list>
#include <queue>

using namespace std;

#define maxn 128

int n, m;
int father[maxn],indegree[maxn], count[maxn];

void Init() {
	for(int i = 0; i < n; ++i){
		father[i] = -1;
		indegree[i] = 0;
		count[i] = 1;
	}
}

int TopologicalSort(){
	int ret = 0;
	queue<int> q;
	for(int i = 0; i< n; ++i){
		if (indegree[i]==0){
			q.push(i);
		}
	}
	while (!q.empty()){
		int from = q.front();
		q.pop();
		if(count[from]%2==0) ret++;
		int to = father[from];
		if (to != -1) {
			count[to]+= count[from];
			indegree[to]--;
			if(indegree[to]==0) {
				q.push(to);
			}
		}
	}
	return ret;
}

int main() {
	while (2 == scanf("%d%d", &n, &m)) {
		Init();
		int u, v;
		for(int i = 0; i < m; ++i) {
			scanf("%d%d", &u, &v);
			u--; v--;
			indegree[v]++;
			father[u] = v;	
		}
		printf("%d\n", TopologicalSort() - 1);
	}	
	return 0;
}
