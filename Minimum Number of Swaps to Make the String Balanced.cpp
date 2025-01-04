class Solution {
public:
    int minSwaps(string s) 
    {
        int imbalance = 0;
        int swaps = 0;
        for(char &ch:s)
        {
            if(ch == '[')
            {
                imbalance++;
            }
            else
            {
                imbalance--;
            }
            if(imbalance<0)
            {
                swaps++;
                imbalance = 1;
            }
        }
        return swaps;
    }
};