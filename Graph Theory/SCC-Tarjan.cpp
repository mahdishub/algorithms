struct SCC {
    vector<vector<int>> graph; // adjacencyList representation of a graph.
    vector<int> component; // component array
    vector<int> low; // low link values array
    vector<int> discovery; // discovery time array
    stack<int> stk; // stack to maintain
    vector<bool> onStack; // to maintain which nodes are on stack
    int time = 0;
    int componentCount = 0;
    int maxN;
    int lowestNode, highestNode;
    SCC() {};

    SCC(vector<vector<int>>& graph, int lowestNode, int highestNode) {
        maxN = graph.size();
        this->graph = graph;
        this->lowestNode = lowestNode;
        this->highestNode = highestNode;
        component.resize(maxN);
        low.resize(maxN);
        discovery.resize(maxN, -1);
        onStack.resize(maxN);
    }

private:
    void dfs(int src) {
        component[src] = src;
        discovery[src] = low[src] = time++;
        stk.push(src);
        onStack[src] = true;

        for (int dest: graph[src]) {
            if (discovery[dest] == -1) {
                dfs(dest);
                low[src] = min(low[src], low[dest]);
            } else if (onStack[dest]) {
                low[src] = min(low[src], discovery[dest]);
            }
        }

        if (low[src] == discovery[src]) {
            componentCount++;
            while (true) {
                int top = stk.top();
                stk.pop();

                component[top] = src;
                onStack[top] = false;

                if (top == src) break;
            }
        }
    }

public:
    void generateSCCComponents() {
        for (int i = lowestNode; i <= highestNode; i++) {
             if (discovery[i] == -1) {
                dfs(i);
            }
        }
    }

    inline int findComponent(int node) {
        return component[node];
    }

    inline bool isFromDifferentComponent(int node1, int node2) {
        return component[node1] != component[node2];
    }

    vector<vector<int>> getDagGraph() {
        vector<vector<int>> dagGraph;
        dagGraph.resize(maxN);

        for (int u = lowestNode; u <= highestNode; u++) {
            for (int v: graph[u]) {
                if (isFromDifferentComponent(u,v)) {
                    dagGraph[u].push_back(v);
                }
            }
        }

        return dagGraph;
    }

    int getComponentCount() {
        return componentCount;
    }
};
