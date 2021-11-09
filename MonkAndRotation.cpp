#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int T;
    long val;
    vector<long> vec;
    cin >> T;

    while (T--) {
        long N, K;
        cin >> N >> K;
        vec.clear();
        vec.resize(N);

        for (long i = 0; i < N; i++) {
            cin >> val;
            vec[i] = val;
        }

        K = K % N;
        int j = N - K;

        for (long i = 0; i < N; i++) {
            cout << vec[(i+j) % N] << " ";
        }

        cout << endl;
    }
    return 0;
}
