class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i=digits.size()-1;
        vector<int> ans;
        digits[i]+=1;
        while(digits[i]>9 && i>0){
            digits[i]=(digits[i])%10;
            i--;
            digits[i]=(digits[i]+1);
        }
        if(digits[0]>9){
            ans.push_back(1);
            ans.push_back(0);
            for(int  i=1;i<digits.size();i++){
                ans.push_back(digits[i]);
            }
            return ans;
        }
        else{
        return digits;}

        
    }
};