#include <iostream>
#include <set>
#include <sstream>
#include <vector>

using namespace std;

bool prefixStrings(vector<string>& a, vector<string>& b)
{
    set<string> st;
    stringstream ss;
    for(string& s : a) {
        ss << s;
	st.insert(ss.str());
    }

    for(string& t : b) {
        if(st.find(t) == st.end())
            return false;
    }

    return true;
}

int main()
{
    vector<string> a = {"one", "two", "three"};
    vector<string> b = {"onetwo", "one"};
    cout << prefixStrings(a, b) << endl;
    return 0;
}
