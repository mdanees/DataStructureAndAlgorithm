#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

int uniquesOnSegment(vector<int> v, int k)
{
    size_t n = v.size();
    std::bitset<2000> flag;
    std::vector<int>::iterator it;

    int ans = 0;
    int index = 0;
    bool found = false;

    for (int len = k; len <= n; len++)
    {
        for (int i = 0; i <= n - len; i++)
        {
            flag.reset();
            found = true;
            //cout <<"numbers[..] = [";
            for (int j = i; j < i + len; j++) {
                //cout << v[j] << ",";
                
                if (j - i > k)
                    flag.reset(v[j - i]);

                if (flag.test(v[j])) {
                    found = false;
                    break;
                }
                else
                    flag.set(v[j]);
            }
            //cout << "]" << endl;
            if (found)
                ans++;
        }
    }

    return ans;
}

int main()
{
    vector<int> v1 = { 1,2,3,4,1 };
    vector<int> v2 = { 5,5,5,5 };
    vector<int> v3 = { 1,2,1,1 };

    cout << uniquesOnSegment(v1, 3) << endl;
    cout << uniquesOnSegment(v2, 1) << endl;
    cout << uniquesOnSegment(v3, 2) << endl;
    return 0;
}