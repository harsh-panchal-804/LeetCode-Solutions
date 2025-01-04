class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int killcount=0;
        int ourtime=0;
        vector<double> time(dist.size());
        int n=dist.size();
        for(int i=0;i<n;i++){
            time[i]=(double)dist[i]/speed[i];
        }
        sort(time.begin(),time.end());
        for(double t :time){
            if(t>ourtime){
                killcount++;
                ourtime++;
            }
            else{
                break;
            }

        }
        return killcount;
        
       
    }
};