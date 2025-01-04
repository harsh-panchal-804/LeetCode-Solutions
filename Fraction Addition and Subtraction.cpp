class Solution {
public:
    string fractionAddition(string exp) {
        vector<string> parts;
        int i=0;
        int n=exp.size();
        string temp="";
        while(i<n){
            if(exp[i]=='/'){
                temp+=exp[i];
                i++;
                while(exp[i]>='0'&& exp[i]<='9'){
                    temp+=exp[i];
                    i++;
                }
                parts.push_back(temp);
                temp="";
                ///i+=2;
            }
            else{
                temp+=exp[i];
                i++;
            } 
        }
        function<string(string ,string)> solve=[&](string a,string b)->string{
            int sign_a=1;
            int sign_b=1;
            if(a[0]=='-'){
                sign_a=-1;
                a.erase(a.begin()+0);
            }
            else if(a[0]=='+')a.erase(a.begin()+0);
            if(b[0]=='-'){
                sign_b=-1;
                b.erase(b.begin()+0);
            }
            else if(b[0]=='+')b.erase(b.begin()+0);
            int slash_a = a.find('/');
            int slash_b = b.find('/');
            int num_a = stoi(a.substr(0, slash_a));       
            int den_a = stoi(a.substr(slash_a + 1));      
            int num_b = stoi(b.substr(0, slash_b));      
            int den_b = stoi(b.substr(slash_b + 1));  

            int ans_den=(den_a*den_b)/__gcd(den_a,den_b);
            // cout<<a<<"\n";
            // cout<<b<<"\n";
            // cout<<"ans den "<<ans_den<<"\n";
            // cout<<"nums a "<<num_a<<"  "<<" den_a "<<den_a<<"\n";
            // cout<<"deem a "<<num_b<<"  "<<" den_b "<<den_b<<"\n";
            int ans_num=((ans_den/den_a)*sign_a*num_a)+((ans_den/den_b)*sign_b*num_b);
            while(__gcd(abs(ans_num),abs(ans_den))!=1){
                int x=__gcd(abs(ans_num),abs(ans_den));
                ans_num/=x;
                ans_den/=x;
            }
            if(ans_num==0)return "0/1";
            string ret="";
            ret+=(to_string(ans_num));
            ret.push_back('/');
            ret+=to_string(ans_den);
            cout<<"final is  "<<ret<<"\n";
            return ret;
        };
        if(parts.size()==1)return parts[0];
        // for(auto i : parts)cout<<i<<"  ";
        // cout<<"\n";

        string tans=solve(parts[0],parts[1]);
        // cout<<tans<<"\n";
        int j=2;
        while(j<parts.size()){
            tans=solve(tans,parts[j]);
            // cout<<tans<<"\n";
            j++;
        }
       
        return tans;

    }
};