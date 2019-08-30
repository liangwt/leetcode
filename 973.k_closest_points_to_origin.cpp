/**
 * We have a list of points on the plane.  Find the K closest points to the origin (0, 0).
 *
 * (Here, the distance between two points on a plane is the Euclidean distance.)
 *
 * You may return the answer in any order.  The answer is guaranteed to be unique (except for the order that it is in.)
 *
 *
 *
 * Example 1:
 *
 * Input: points = [[1,3],[-2,2]], K = 1
 * Output: [[-2,2]]
 * Explanation:
 * The distance between (1, 3) and the origin is sqrt(10).
 * The distance between (-2, 2) and the origin is sqrt(8).
 * Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
 * We only want the closest K = 1 points from the origin, so the answer is just [[-2,2]].
 * Example 2:
 *
 * Input: points = [[3,3],[5,-1],[-2,4]], K = 2
 * Output: [[3,3],[-2,4]]
 * (The answer [[-2,4],[3,3]] would also be accepted.)
 *
 *
 * Note:
 *
 * 1 <= K <= points.length <= 10000
 * -10000 < points[i][0] < 10000
 * -10000 < points[i][1] < 10000
 */

/**
 *  使用优先队列：
 *
 *  c++默认的 priority_queue 模板有 3 个参数，其中两个有默认的参数；
 *    第一个参数是存储对象的类型，
 *    第二个参数是存储元素的底层容器，
 *    第三个参数是函数对象，它定义了一个用来决定元素顺序的断言。
 *    因此模板类型是：
 *      template <typename T, typename Container=std::vector<T>, typename Compare=std::less<T>> class priority_queue
 *
 *  所以最大值在前面
 */

#include <vector>
#include <queue>

#include <assert.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int K) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pri;
        pair<int, int> t;
        int distance;

        for (int i = 0; i < K && i < points.size(); ++i) {
            pri.push(make_pair(points[i][0] * points[i][0] + points[i][1] * points[i][1], i));
        }

        for (int i = K; i < points.size(); ++i) {
            t = pri.top();
            distance = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            if (t.first > distance) {
                pri.pop();
                pri.push(make_pair(distance, i));
            }
        }

        vector<vector<int>> ret;

        while (!pri.empty()) {
            t = pri.top();
            pri.pop();
            ret.push_back(points[t.second]);
        }

        return ret;
    }
};

int main() {
    Solution s;

    vector<vector<int>> p1 = {
        {1,  3},
        {-2, 2},
    };
    assert(s.kClosest(p1, 1) == vector<vector<int>>({{-2, 2}}));

    vector<vector<int>> p2 = {
        {3,  3},
        {5,  -1},
        {-2, 4},
    };
    assert(s.kClosest(p2, 2) == vector<vector<int>>({{-2, 4},
                                                     {3,  3}}));

    vector<vector<int>> p3 = {};
    assert(s.kClosest(p3, 1) == vector<vector<int>>({}));

    return 0;
}