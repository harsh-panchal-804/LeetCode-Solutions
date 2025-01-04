class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> vec1(26,0);
        vector<int> vec2(26,0);
        for(auto i : s){
            vec1[i-'a']++;
        }
        for(auto i : t){
            vec2[i-'a']++;
        }
        int steps=0;
        for(auto i : vec1){
           cout<<i<<"";
        }
        cout<<""<<endl;


        for(auto i : vec2){
           cout<<i<<"";
        }



        for(int i=0;i<26;i++){
            if(vec2[i]<vec1[i]){
                steps+=(vec1[i]-vec2[i]);
            }
           
        }
        return steps;

        
    }
};