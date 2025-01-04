class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int count=0;
        int l=limit;
        int i=0;
        int j=people.size()-1;
        while(i<=j){
            if(people[i]+people[j]<=limit){
                i++;
            }
            count++;
            j--;
        }
        
        /// 1 2 4 5
        return count;
        
    }
};