class TreeAncestor {
public:
    vector<vector<int>> up;
    int log;
    TreeAncestor(int n, vector<int>& parent) {
        log = 0;
        while ((1 << log) <= n) log++;
        up = vector<vector<int>>(n, vector<int>(log, -1));
        for(int i =0;i<n;i++){
            up[i][0]=parent[i];
        }
        for (int j=1;j<log;j++) {
            for (int i=0;i<n;i++) {
                if (up[i][j - 1] != -1) {
                    up[i][j] = up[up[i][j - 1]][j - 1];
                } 
            }
        }
    }

    int getKthAncestor(int node, int k) {
        for (int i = 0; i < log; i++) {
            if ((1 << i) & k) {
                node = up[node][i];
                if (node == -1) break;
            }
        }
        return node;
    }
};
