/*
 * Bipartite graph max match
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <vector>

using namespace std;

class BipartiteGraph {
public:
    explicit BipartiteGraph(int nodes): m_nodes(nodes), m_connection(nodes) {
        for(int i = 0; i < m_nodes; i++) {
            m_connection[i].resize(m_nodes);
            for (int j = 0; j < m_nodes; j++) {
                m_connection[i][j] = false;
            }
        }
    }
    void AddEdge(int a, int b) {
        m_connection[a][b] = true;
    }

    int MaxMatch() {
        int match = 0;
        m_back.resize(m_nodes);
        for (int i = 0; i < m_nodes; i++) {
            m_back[i] = -1;
        }
        m_flag.resize(m_nodes);
        for (int i = 0; i < m_nodes; i++) {
            for (int j = 0; j < m_nodes; j++) {
                m_flag[j] = false;
            }
            if (DFS(i)) match ++;
        }
        return match;
    }
private:
    bool DFS(int k) {
        for (int i = 0; i < m_nodes; i++) {
            if (m_connection[k][i] && (!m_flag[i])) {
                m_flag [i] = true;
                int tmp = m_back[i];
                m_back[i] = k;
                if (tmp == -1 || DFS(tmp)) {
                    return true;
                }
                m_back[i] = tmp;
            }
        }
        return false;
    }
private:
    int m_nodes;
    vector< vector<bool> > m_connection;
    vector<int> m_back;
    vector<int> m_flag;
};

int main() {
    int T;
    scanf("%d", &T);
    while (T-- > 0) {
        int n, k;
        scanf("%d%d", &n, &k);
        vector<int> V(n);
        BipartiteGraph graph(n);
        for (int i = 0; i < n; i++){
            scanf("%d", &V[i]);
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n ;j++) {
                if (abs(V[i] - V[j]) >= k) {
                    graph.AddEdge(i, j);
                }
            } 
        }
        printf("%d\n", n - graph.MaxMatch());
    }
    return 0;
}
