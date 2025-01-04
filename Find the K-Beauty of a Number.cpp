class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string nums=to_string(num);
        int n=nums.size();
        int count=0;
        for(int i=0;i<n-k+1;i++){
            string temp=nums.substr(i,k);
            if(temp.size()!=k)continue;
            int x=stoi(temp);
            if(x==0)continue;
            if(num%x==0)count++;
        }
        return count;
    }
};