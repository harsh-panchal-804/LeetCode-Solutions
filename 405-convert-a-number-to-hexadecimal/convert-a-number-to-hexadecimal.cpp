class Solution {
public:
    string toHex(int num) {
        if(!num)return "0";

        string ans = "";
        string hexDgt = "0123456789abcdef";
        uint32_t n = static_cast<uint32_t> (num);

        while(n){
            int rem = n % 16;
            ans = hexDgt[rem] + ans;
            n /= 16;
        }
        return ans;
    }
};