/**
 * Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings.
 *
 * Example 1:
 *
 * Input: [[0,30],[5,10],[15,20]]
 * Output: false
 * Example 2:
 *
 * Input: [[7,10],[2,4]]
 * Output: true
 * NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.
 */

/**
 * 只需要按照开始时间排序，然后逐个对比开始时间是否在前一个时间对的结束时间之前即可
 */

#include <vector>

using namespace std;

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> x, vector<int> y) -> bool { return x[0] < y[0]; });

        for (int i = 0; i < (int) intervals.size() - 1; i++) {
            if (intervals[i + 1][0] < intervals[i][1]) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution s;

    vector<vector<int>> i1 = {
        {0,  30},
        {5,  10},
        {15, 20},
    };
    assert(!s.canAttendMeetings(i1));

    vector<vector<int>> i2 = {
        {7, 10},
        {2, 4},
    };
    assert(s.canAttendMeetings(i2));

    vector<vector<int>> i3 = {};
    assert(s.canAttendMeetings(i3));

    vector<vector<int>> i4 = {
        {0,  9},
        {5,  11},
        {10, 20},
    };
    assert(!s.canAttendMeetings(i4));

    return 0;
}