class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string c = "123456789";
        vector<int>ans;

        for(int i =0;i<c.size();i++){
            for(int j =i+1;j<c.size();j++){
                int curr = stoi(c.substr(i,j-i+1));
                if(curr<=high && curr>=low)ans.push_back(curr);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};