class Solution {
public:
    string convertDateToBinary(string date) {
    int year = stoi(date.substr(0, 4));
    int month = stoi(date.substr(5, 2));
    int day = stoi(date.substr(8, 2));
    
    string yearBin = bitset<12>(year).to_string();
    yearBin = yearBin.substr(yearBin.find('1'));  
    
    string monthBin = bitset<4>(month).to_string();
    monthBin = monthBin.substr(monthBin.find('1'));  
    
    string dayBin = bitset<5>(day).to_string();
    dayBin = dayBin.substr(dayBin.find('1'));  
  
    return yearBin + "-" + monthBin + "-" + dayBin;
        
    }
};