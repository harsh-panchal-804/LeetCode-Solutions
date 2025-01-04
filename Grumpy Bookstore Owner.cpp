class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int index=0;
        int maxdiff=0;
        for(auto &i : grumpy){
            if(i==1)i=0;
            else i=1;
            cout<<i<<" ";
        }
        cout<<endl;
        for(int i=0;i<customers.size()-minutes+1;i++){
            int ndiff=0;
            int mdiff=0;
            int difference=0;
            for(int j=0;j<minutes;j++){
                ndiff+=customers[i+j]*grumpy[i+j];
                mdiff+=customers[i+j];
            }
            cout<<"m ,n "<<mdiff<<" "<<ndiff<<endl;
            difference=mdiff-ndiff;
            cout<<"At "<<i<<" "<<difference<<endl;
            if(difference>maxdiff){
                index=i;
                maxdiff=difference;
            }
        }
        cout<<"INDEX  "<<index<<endl;
        for(int k=0;k<minutes;k++){
            grumpy[index+k]=1;
        }
        int ans=0;
        for(int i=0;i<customers.size();i++){
            ans+=customers[i]*grumpy[i];
        }
        return ans;
        
    }
};