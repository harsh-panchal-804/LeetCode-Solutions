class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(auto i:matrix){
            cout<<"here";
            cout<<i[i.size()-1];
            if(i[i.size()-1]>=target && i[0]<=target){
                cout<<"bfwiueh";
                for(auto j:i){
                    if(j==target){
                        cout<<j<<endl;
                        return true;
                    }
                }
            }

        }
        return false;
        
    }
};