class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& cust) {
        double wait=0;
        int time=0;
        for(int i=0;i<cust.size();i++){
            int arrival=cust[i][0];
            int dur=cust[i][1];
            int tempwait=0;
            if(time<arrival){
               time=arrival;
            }
            tempwait = time-arrival+dur;
            wait+=tempwait;
            time+=dur;
            
        }
        return wait/cust.size();
        
    }
};