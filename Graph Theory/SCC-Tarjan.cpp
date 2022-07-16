struct SCC {
    vector<vector<int>> adjacencyList;
    vector<int> component;
    vector<int> lowLinkValue;
    vector<bool> visited;
    SCC() {};

    SCC(vector<vector<int>>& adjacencyList) {
        this->adjacencyList = adjacencyList;
        component.resize(adjacencyList.size());
        visited.resize(adjacencyList.size());
        lowLinkValue.resize(adjacencyList.size());
    }

    void dfs(int src) {
        visited[src] = true;
        component[src] = lowLinkValue[src] = src;

        for (int dest: adjacencyList[src]) {
            dfs()
        }
    }

    void generateSCCComponents() {

    }
};
