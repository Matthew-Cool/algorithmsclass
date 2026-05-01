#include <graph.hpp>
#include <msort.hpp>
#include <disjoint_set.hpp>


std::vector<Edge> constructMSTKruskal(Graph &G)
{
    std::vector<Edge> edges = G.exportEdges(); // Graph's edges
    // DisjointSet djs(G.n);
    // Use Disjoint Set to check whether two vertices are on the same set
    // Usage: Check djs.isOnSameSet(u, v); Check is u and v is on the same set or not
    //              djs.join(u, v); Join sets of u and v into the same set

    std::vector<Edge> mst;
    DisjointSet djs(G.getN());
    // YOUR CODE HERE

    if (!edges.empty()) {
        msort(edges, 0, static_cast<int>(edges.size()) - 1);
    }

    for (const Edge& e : edges) {
        if (!djs.isOnSameSet(e.u, e.v)) {
            djs.join(e.u, e.v);
            mst.push_back(e);

            if (static_cast<int>(mst.size()) == G.getN() - 1) {
                break;
            }
        }
    }

    return mst;
}
