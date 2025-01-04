class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        vector<vector<int>> vec(n,vector<int> (n,0));
        int x=0;
        int y=0;
        for(auto i : commands){
            if(i=="UP"){
                x--;
            }
            else if(i=="DOWN"){
                x++;
            }
            else if(i=="LEFT"){
                y--;
            }
            else if(i=="RIGHT"){
                y++;
            }
        }
        return (x*n)+y;
        

        
    }
};