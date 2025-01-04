class Solution {
public:
    bool reorderedPowerOf2(int n) {
        if(n==1) return true;
        string t=to_string(n);
        sort(t.begin(),t.end());
        string temp;
        for(int i=1;i<=32;i++){
            long long val=pow(2,i);
            temp=to_string(val);
            sort(temp.begin(),temp.end());
            if(temp==t)return true;
        }
        return false;
        
    }
};
/// 512
/// 125 521