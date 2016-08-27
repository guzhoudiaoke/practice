// 筛法求素数
void get_prime(int n)
{
    for (int i = 1; i <= n; i++)
        is_prime[i] = 1;

    for (int i = 2; i <= sqrt(n); i++) {
        if (is_prime[i]) {
            for (int j = i+i; j <= n; j += i) {
                if (j % i == 0) {
                    is_prime[j] = 0;
                }
            }
        }
    }
}

// dijkstra: 给定一个起点s，找出s到所有其他节点的最短路
void dijkstra(graph *g, int start)
{
    bool intree[MAXV];
    int i, j, distance[MAXV], v, w, weight, dist;

    for (i = 1; i <= g->nvertices; i++) {
        intree[i] = 0;
        distance[i] = MAXINT;
        parent[i] = -1;
    }

    distance[start] = 0;
    v = start;
    while (intree[v] == 0) {
        intree[v] = TRUE;
        for (i = 0; i < g->degree[v]; i++) {
            w = g->edges[v][i].v;
            weight = g->edges[v][i].weight;
            if (distance[w] > distance[v] + weight) {
                distance[w] = distance[v] + weight;
                parent[w] = v;
            }
        }

        v = 1;
        dist = MAXINT;
        for (i = 1; i <= g->nvertices; i++) {
            if (intree[i] == 0 && dist > distance[i]) {
                dist = distance[i];
                v = i;
            }
        }
    }
}

//
