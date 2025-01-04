class Solution {
public:
    long findNum(long num, bool isEven) {
        long possibleNum = num;
        if (!isEven) {
            num /= 10;
        }
        while (num != 0) {
            int digit = num % 10;
            possibleNum = (possibleNum * 10) + digit;
            num /= 10;
        }
        return possibleNum;
    }
    string nearestPalindromic(string n) {
        int length = n.size();
        int mid = length / 2;
        int firsthalflen = (length % 2 == 0) ? mid : mid + 1;
        long firsthalf = stol(n.substr(0, firsthalflen));

        vector<long> result;
        result.push_back(findNum(firsthalf, (length % 2 == 0)));
        result.push_back(findNum(firsthalf + 1, (length % 2 == 0)));
        result.push_back(findNum(firsthalf - 1, (length % 2 == 0)));

        result.push_back(((long)pow(10,length))+1);
        result.push_back(((long)pow(10,length-1))-1);
        long original = stol(n);
        long ans = -1;
        long diff = LONG_MAX;

        for (long num : result) {
            if (num == original)
                continue;

            long currentDiff = abs(original - num);
            if (currentDiff < diff) {
                diff = currentDiff;
                ans = num;
            } else if (currentDiff == diff) {
                ans = min(num, ans);
            }
        }

        return to_string(ans);
    }
};