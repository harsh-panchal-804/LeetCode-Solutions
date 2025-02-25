class Solution {
public:
    bool check(int x,vector<vector<int>>& tasks){
        int n=tasks.size();
        if(tasks[0][1]>x)return false;
        x-=tasks[0][0];
        if(x<=0)return false;
        for(int i=1;i<n;i++){
            if(tasks[i][1]>x)return false;
            x-=tasks[i][0];
           
        }
        return true;
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        if(tasks.size()==1){
            return tasks[0][1];
        }
        sort(tasks.begin(),tasks.end(),[&](vector<int>& a,vector<int>& b){
            return a[1]-a[0] > b[1]-b[0];
        });
        int low=1;
        int high=1e9+2000;
        int ans=-1;
        while(low<=high){
            int mid= (low+high)/2;
            if(check(mid,tasks)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};