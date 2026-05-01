#include <graph.hpp>
#include <msort.hpp>
#include <disjoint_set.hpp>
#include <queue>

struct EdgeKeyComparison
{
    constexpr bool operator()(const Edge &a, const Edge &b) const noexcept
    {
        return a.w > b.w;
    }
};


std::vector<Edge> constructMSTPrim(Graph &G)
{
    std::vector<Edge> edges = G.exportEdges(); // Graph's edges

    std::priority_queue<Edge, std::vector<Edge>, EdgeKeyComparison> heap;
    // If you want to use heap to optimize the minimum searching, you can use heap defined as above
    //      Insert: heap.push(Edge(u, -1, distance));
    //      Get Minimum: top = heap.top(); u = top.u; distance = top.w;
    //      Remove top: heap.pop(); (this function usually goes after the get minimum method)

    std::vector<Edge> mst;
    // YOUR CODE HERE
    int n = G.getN();
    if (n == 0) return mst;

    std::vector<bool> visited(n, false);

    int start = 0;
    visited[start] = true;

    for (const Edge& e : edges) {
        if (e.u == start || e.v == start) {
            heap.push(e);
        }
    }

    while (!heap.empty() && static_cast<int>(mst.size()) < n - 1) {
        Edge e = heap.top();
        heap.pop();

        int next = -1;

        if (visited[e.u] && !visited[e.v]) {
            next = e.v;
        } else if (visited[e.v] && !visited[e.u]) {
            next = e.u;
        } else {
            continue;
        }

        mst.push_back(e);
        visited[next] = true;

        for (const Edge& ne : edges) {
            if ((ne.u == next && !visited[ne.v]) ||
                (ne.v == next && !visited[ne.u])) {
                heap.push(ne);
            }
        }
    }

    return mst;
}
