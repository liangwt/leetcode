#include <vector>

using namespace std;

template <typename T>
bool vector_equal(vector<T> r1, vector<T> r2)
{

    sort(r1.begin(), r1.end());
    sort(r2.begin(), r2.end());

    return r1 == r2;
}

template <typename T>
bool vector_equal(vector<vector<T>> r1, vector<vector<T>> r2)
{

    auto f = [](vector<T> r) {
        sort(r.begin(), r.end());
        return r;
    };

    transform(r1.begin(), r1.end(), r1.begin(), f);
    transform(r2.begin(), r2.end(), r2.begin(), f);

    sort(r1.begin(), r1.end());
    sort(r2.begin(), r2.end());

    return r1 == r2;
}