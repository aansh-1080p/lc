class Solution {
public:
    void findSuspicious(vector<vector<int>> & edges, vector<bool> & visited, int node){
        if(visited[node]){
            return;
        }
        visited[node] = true;

        for(int x: edges[node]){
            findSuspicious(edges, visited, x);
        }

        return;
    }

    bool isInvokingSusp(const vector<int> & invokes, const vector<bool> & visited){
        for(int i=0; i<invokes.size(); i++){
            if(visited[invokes[i]]){
                return true;
            }
        }
        return false;
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> edges(n, vector<int>());

        for(int i=0; i<invocations.size(); i++){
            int first = invocations[i][0];
            int sec = invocations[i][1];

            edges[first].push_back(sec);
        }

        vector<bool> visited(n,false);

        findSuspicious(edges, visited, k);

        for(int i=0; i<n; i++){
            if(!visited[i] && isInvokingSusp(edges[i], visited)){
                vector<int> def(n);
                iota(def.begin(), def.end(), 0);
                return def;

            }
        }

        vector<int> res;

        for(int i=0; i<n; i++){
            if(!visited[i]){
                res.push_back(i);
            }
        }

        return res;

    }
};