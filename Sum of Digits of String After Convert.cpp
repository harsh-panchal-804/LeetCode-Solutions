class Solution {
public:
    int getLucky(string s, int k) {
        string temp="";
        for(int i=0;i<s.size();i++){
            int x=s[i]-'a'+1;
            ////cout<<x<<"\n";
            temp+=(to_string(x));
        }
        cout<<temp<<"\n";
        function<string(string)> convert=[&](string a){
            int temp=0;
            for(auto &i :a){
                temp+=(i-'0');
            }
            return to_string(temp);
        };
        while(k--){
            temp=convert(temp);
        }
        return stoi(temp);
    }
};