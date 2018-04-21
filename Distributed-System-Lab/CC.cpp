#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

const int MAX = 20000 + 7;
const int INF = INT_MAX;
vector <int> G[MAX];
vector <int> cost[MAX];

struct data {
    int server;
    int cost;

    bool operator < (const data &other) const {
        return other.cost < cost;
    }
};


int dijkstra(int n, int s, int t)
{
    int d[n + 1];

    for(int i = 0; i <= n; i++) {
        d[i] = INF;
    }
    priority_queue <data> PQ;
    data u, v;

    u.server = s;
    u.cost = 0;
    d[s] = 0;

    PQ.push(u);

    while(!PQ.empty())
    {
        u = PQ.top(); PQ.pop();
        int sz = G[u.server].size();

        for(int i = 0; i < sz; i++)
        {
            v.server = G[u.server][i];
            v.cost = u.cost + cost[u.server][i];

            if(d[v.server] > v.cost) {
                d[v.server] = v.cost;
                PQ.push(v);
            }
        }
    }

    return d[t];
}


int main()
{
    // freopen("input.txt", "r+", stdin);

    int tc, n, m, s, t;
    int u, v, w;

    cin >> tc;
    for(int k = 1; k <= tc; k++)
    {
        cin >> n >> m >> s >> t;
        for(int i = 0; i < m; i++)
        {
            cin >> u >> v >> w;

            G[u].push_back(v);
            G[v].push_back(u);

            cost[u].push_back(w);
            cost[v].push_back(w);
        }

        int time_require = dijkstra(n, s, t);

        cout << "Case #" << k << ": ";
        if(time_require != INF) {
            cout << time_require << endl;
        }
        else {
            cout << "unreachable" << endl;
        }

        for(int i = 0; i < n; i++) {
            G[i].clear();
            cost[i].clear();
        }
    }


    return 0;
}
