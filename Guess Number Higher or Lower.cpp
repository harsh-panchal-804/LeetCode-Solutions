/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long int l=1;
        long long int r=n;
        
        while(true){
            long long int mid=(l+r)/2;
            int res=guess(mid);
            if(res==0) return mid;
            if(res>0) l=mid+1;
            else r=mid-1;
        }
        
    }
};