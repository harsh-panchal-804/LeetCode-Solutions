class Seg_Tree {
    vector<int> tree;
    int n;
    public:
        Seg_Tree(vector<int>& arr) {
            n = arr.size();
            tree.resize(4 * n);
            build(arr, 1, 0, n - 1);
        }
    
        void build(vector<int>& arr, int node, int l, int r) {
            if (l == r) {
                tree[node] = arr[l];
            } else {
                int mid = (l + r) >> 1;
                build(arr, 2 * node, l, mid);
                build(arr, 2 * node + 1, mid + 1, r);
                tree[node] = tree[2 * node] + tree[2 * node + 1];
            }
        }
    
        void update(int node, int value, int idx, int l, int r) {
            if (l == r) {
                tree[node] = value;
            } else {
                int mid = (l + r) >> 1;
                if (idx <= mid) {
                    update(2 * node, value, idx, l, mid);
                } else {
                    update(2 * node + 1, value, idx, mid + 1, r);
                }
                tree[node] = tree[2 * node] + tree[2 * node + 1];
            }
        }
    
        void update(int idx, int value) {
            update(1, value, idx, 0, n - 1);
        }
    
        int query(int node, int curr_l, int curr_r, int l, int r) {
            if (curr_l > r || curr_r < l) {
                return 0;
            }
            if (l <= curr_l && curr_r <= r) {
                return tree[node];
            }
            int mid = (curr_l + curr_r) >> 1;
            int left_query = query(2 * node, curr_l, mid, l, r);
            int right_query = query(2 * node + 1, mid + 1, curr_r, l, r);
            return left_query + right_query;
        }
    
        int query(int l, int r) {
            return query(1, 0, n - 1, l, r);
        }
};


class NumArray {
public:
    Seg_Tree* tree;
    NumArray(vector<int>& nums) {
        tree=new Seg_Tree(nums);
    }
    
    void update(int index, int val) {
        tree->update(index,val);
    }
    
    int sumRange(int left, int right) {
        return tree->query(left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */