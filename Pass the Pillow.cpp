class Solution {
public:
    int passThePillow(int n, int time) {
      int d=time/(n-1);
      int r=time%(n-1);
      return d&1? n-r:r+1;
    }
};