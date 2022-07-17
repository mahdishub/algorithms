struct SCC {
    vector<vector<int>> adjacencyList; // adjacencyList representation of a graph.
    vector<int> component; // component array
    vector<int> low; // low link values array
    vector<int> discovery; // discovery time array
    stack<int> stk; // stack to maintain
    vector<bool> onStack; // to maintain which nodes are on stack
    int time = 0;
    int componentCount = 0;
    int maxN;
    SCC() {};

    SCC(vector<vector<int>>& adjacencyList) {
        maxN = adjacencyList.size();
        this->adjacencyList = adjacencyList;
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

        for (int dest: adjacencyList[src]) {
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
        for (int i = 0; i < adjacencyList.size(); i++) {
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

    vector<vector<int>>& getDagGraph() {
        vector<vector<int>> dagGraph(adjacencyList.size());

        for (int i = 0; i < adjacencyList.size(); i++) {
            for (int j: adjacencyList[i]) {
                if (isFromDifferentComponent(i,j)) {
                    dagGraph[i].push_back(j);
                }
            }
        }

        return dagGraph;
    }

    int getComponentCount() {
        return componentCount;
    }
};
