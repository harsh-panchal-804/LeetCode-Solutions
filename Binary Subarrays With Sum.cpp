class Solution {

public:

    int numSubarraysWithSum(vector<int>& nums, int goal) {

        vector<int> prefix(nums.size());

        unordered_map<int,int> map;

        int count=0;

        prefix[0]=nums[0];

        for(int i=1;i<nums.size();i++){

            prefix[i]=prefix[i-1]+nums[i];

        }

        cout<<"Prefix is ";

        for(auto i : prefix){

            cout<<i<<" ";

        }

        for(int i=0;i<prefix.size();i++){

            if(prefix[i]==goal) count++;

            if(map.find(prefix[i]-goal)!=map.end()){

                count+=map[prefix[i]-goal];

            }

            map[prefix[i]]++;

            

        }

        return count;



        

    }

};