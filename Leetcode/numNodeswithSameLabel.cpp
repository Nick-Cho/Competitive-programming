class Solution {
public:
    
    vector<int> dfs(int node, int parent, string& labels, vector<int>& ans, vector<vector<int>>& adjList){
        vector<int> letterCount(26);
        letterCount[labels[node] - 'a'] = 1;
        for (auto& child : adjList[node]){
            if (child == parent){
                continue;
            }
            vector<int> childCounts = dfs(child, node, labels, ans, adjList);
            for (int i = 0; i < 26; i++) {
                letterCount[i] += childCounts[i];
            }
        }
        ans[node] = letterCount[labels[node] - 'a'];
        return letterCount;
    }


    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        int num_edges = edges.size();
        vector<vector<int>> adjList(n);
        for (int i=0; i<num_edges; i++){
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> ans(n,1);
        dfs(0,-1, labels, ans, adjList);
        return ans;
    }
};