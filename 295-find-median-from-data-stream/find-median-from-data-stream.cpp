#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
template<class T> 
using oset=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

class MedianFinder {
public:
    int index;
    oset<pair<double,int>> set;
    MedianFinder() {
        index=0;
    }
    void addNum(int num) {
        set.insert({num,index++});

    }
    double findMedian() {
        int n=set.size();
        if(n&1){
            double mid=(*set.find_by_order((n-1)/2)).first;
            return (double)mid;
        }
        else{
            double mid1=(*set.find_by_order((n-1)/2)).first;
            double mid2=(*set.find_by_order((n-1)/2 +1)).first;
            return (mid1+mid2)/(double)2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */