class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> answer;
        int i=0;
        int j=0;
        double d=0;
        while(i< nums1.size() && j<nums2.size()){
            if(nums1[i] < nums2[j]) {
                answer.push_back(nums1[i]);
                i++;

            } 
            else {
                answer.push_back(nums2[j]);
                j++;
            }



        }

        while(i<nums1.size()){
            answer.push_back(nums1[i]);
            cout<<nums1[i];
            i++;

        }

        while(j<nums2.size()){
            answer.push_back(nums2[j]);
            j++;
            
            
        }

        
        int mid = answer.size() / 2;
        if(answer.size() % 2 == 0) 
        {
            return (answer[mid-1] + answer[mid]) / 2.0;
        } else {
            return answer[mid];
        }

        
    }
};