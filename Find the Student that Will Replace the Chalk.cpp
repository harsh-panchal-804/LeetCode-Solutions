class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum=accumulate(chalk.begin(),chalk.end(),0ll);
        int n=chalk.size();
       //// long long temp=sum;
        while(k>=sum){
            k-=sum;
        }
        cout<<k<<"\n";
        int i=0;
        while(i<n&&k>=chalk[i]){
            k-=chalk[i];
            i++;
        }
        return i;
        
    }
};