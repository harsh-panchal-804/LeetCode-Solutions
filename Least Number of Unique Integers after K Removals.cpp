class Solution {

public:

    static bool cmp(pair<int,int>& a, pair<int,int>& b){

        return a.second<b.second;

    }

    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {

        unordered_map<int,int> map;

        vector<pair<int,int>> vec;

        for(auto i : arr){

            map[i]++;

        }

        for(auto i : map){

            vec.push_back(i);

        }

        sort(vec.begin(),vec.end(),cmp);

        int ans=vec.size();

        for(auto i : vec){

            cout<<i.second<<" ";

        }

        for(auto i : vec){

            if(k>=i.second){

                k-=i.second;

                ans--;

            }

            else{

              

                break;

            }

            

        }

        return ans;

        

    }

};