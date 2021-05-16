#include <iostream>
#include <bitset>
#include <string>
#include <vector>

using namespace std;
#define MAX_BIT 128

bool incrementBinaryNumber(bitset<MAX_BIT>& bit)
{
    for(int i = 0; i < bit.size(); ++i) {
        if(bit.test(i)) {
            bit.reset(i);
        }
	else {
            bit.set(i);
	    return true;
	}
    }
    return false;
}

vector<int> incrementBinaryNumber(string num, vector<char>& opr)
{
    bitset<MAX_BIT> bit(num);
    vector<int> ret;
    for(char c : opr) {
        if(c == '?')
            ret.push_back(bit.count());
	else if (c == '+')
            incrementBinaryNumber(bit);
    }

    return ret;
}

int main()
{
    string num = "1101";
    vector<char> opr = {'?','+','+','?','+','+','?','+','?','?','+','?'};
    vector<int> ret = incrementBinaryNumber(num, opr);
    for(int i : ret) {
        cout << i << endl;
    }
    return 0;
}
