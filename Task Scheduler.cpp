class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
       unordered_map<char,int> map;
       ////if(n==1) return tasks.size();
       ///sort(tasks.begin(),tasks.end());
       int s=tasks.size();
       for(auto i : tasks) map[i]++;
       vector<int> vec(s*n,-1);
       vector<int> uni(26,0);
       for(auto i: tasks){
            uni[i-'A']++;
       }
       sort(uni.begin(),uni.end(),greater<int>());
       int i=0;
       int ans=-1;
       

       for(int i=0;i<uni.size();i++){
            if(uni[i]>0){
                cout<<uni[i]<<endl;
            for(int j=0;j<uni[i];j++){
                cout<<"j==" << j<<"i== "<<i<<endl;
                ans=max(ans,j*(n+1)+i);
            }
            }
       }
       if(ans+1<=s) return s;
       else return ans+1;
    }
       
};