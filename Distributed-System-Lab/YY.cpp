#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

const int MAX = 10000 + 7;
const int INF = INT_MAX;
vector <int> G[MAX];
vector <int> cost[MAX];
int d[MAX];

struct data {
    int city;
    int dest;

    bool operator < (const data &d) const {
        // small means where d.dest is small
        return d.dest < dest;
    }
};


int dijkstra(int src, int des, int n)
{
    for(int i = 0; i <= n; i++) {
        d[i] = INF;
    }
    priority_queue <data> PQ;
    data u, v;

    u.city = src;
    u.dest = 0;

    PQ.push(u);
    d[src] = 0;

    while(!PQ.empty())
    {
        u = PQ.top(); PQ.pop();
        int sz = G[u.city].size();

        for(int i = 0; i < sz; i++)
        {
            v.city = G[u.city][i];
            v.dest = d[u.city] + cost[u.city][i];

            if(d[v.city] > v.dest)
            {
                d[v.city] = v.dest;
                PQ.push(v);
            }
        }
    }
    return d[des];

}

int main()
{
    // freopen("input.txt", "r+", stdin);

    int tc, v, k, a, b, c;
    int src, des;

    cin >> tc;
    for(int t = 0; t < tc; t++)
    {
        cin >> v >> k;
        for(int e = 0; e < k; e++)
        {
            cin >> a >> b >> c;

            G[a].push_back(b);
            cost[a].push_back(c);
        }
        cin >> src >> des;
        int min_dist = dijkstra(src, des, v);

        if(min_dist != INF) {
            cout << min_dist << endl;
        }
        else {
            cout << "NO" << endl;
        }

        // clear
        for(int i = 0; i < v; i++) {
            G[i].clear();
            cost[i].clear();
        }
    }

    return 0;
}
