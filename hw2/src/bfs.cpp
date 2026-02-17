#include <search.hpp>

void bfs(Graph &G, int start, int destination) {
    Queue<int> queue;
    G.reset();
    // YOUR CODE HERE
    G.setVisited(start);
    queue.push(start);
    //END OF MY CODE
    while (!queue.empty()) {
        int u = queue.pop();
        // YOUR CODE HERE
        G.setVisited(u);
        //END OF MY CODE
        int numberOfAdjacencyNodes = G.e[u].size();
        LinkedListNode<int> *p = G.e[u].getRoot();
        for (int i = 0; i < numberOfAdjacencyNodes; i += 1, p = p->next) {
            int v = p->value;
            // YOUR CODE HERE
            if(!G.isVisited(v)){
                G.setVisited(v);
                queue.push(v);
                G.setTrace(v, u);
            }
            //END OF MY CODE
        }
    }
}
