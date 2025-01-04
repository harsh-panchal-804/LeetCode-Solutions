class MyCalendarTwo {
public:
    map<int,int> map;
    MyCalendarTwo() {
        
    }
    bool book(int start, int end) {
        map[start]++;
        map[end]--;
        int total=0;
        for(auto i : map){
            total+=i.second;
            if(total>2){
                map[start]--;
                map[end]++;
                if(!map[start])map.erase(start);
                if(!map[end])map.erase(end);
                return false;
            }
        }
        return true;
        
        
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */