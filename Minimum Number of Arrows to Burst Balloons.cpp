class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int ans=points.size();
        sort(points.begin(),points.end());
        vector<int> prev{points[0][0],points[0][1]};
        for(int i=1;i<points.size();i++){
            if(points[i][0]<=prev[1]){
                ans--;
                prev={points[i][0],min(prev[1],points[i][1])};
            }
            else{
                prev[0]=points[i][0];
                prev[1]=points[i][1];
            }
        }
        
        return ans;
    }
};