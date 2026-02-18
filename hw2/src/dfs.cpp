#include <search.hpp>

void dfs(Graph &G, int start, int destination) {
    Stack<int> stack;
    G.reset();
    // YOUR CODE HERE
    stack.push(start);
    //END MY CODE HERE
    while (!stack.empty()) {
        int u = stack.pop();
        // YOUR CODE HERE
        if(!G.isVisited(u)){
            G.setVisited(u);
        }
        if(u == destination){
            return;
        }
        //END OF MY CODE HERE
        int numberOfAdjacencyNodes = G.e[u].size();
        LinkedListNode<int> *p = G.e[u].getRoot();
        for (int i = 0; i < numberOfAdjacencyNodes; i += 1, p = p->next) {
            int v = p->value;
            // YOUR CODE HERE 
            if (!G.isVisited(v)) {
                G.setVisited(v);
                G.setTrace(v, u);   // needed for path
                stack.push(v);
            }
            //END OF MY CODE HERE
        }
    }
}
