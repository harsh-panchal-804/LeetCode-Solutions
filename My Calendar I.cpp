class MyCalendar {
    multiset<pair<int,int>> set;
public:
    MyCalendar() {
        ////set=multiset<pair<int,int>> ;
    }
    bool book(int start, int end) {
        auto next=set.lower_bound({start,end});
        if(next!=set.end()&& next->first<end){
            return false;
        }
        if(next!=set.begin()){
            auto pre=prev(next);
            if(pre->second>start)return false;
        }
        set.insert({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */