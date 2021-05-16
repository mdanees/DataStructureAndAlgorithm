/*
Uber HackTag
problem 1
You are given a text represented as a string t, and a string s of length 3. Your task is to count the number of indices i, such that titi+2ti+4 = s.
Example
For t = "azcabcab" and s = "acb", the output should be almostSubstring(t, s) = 2.
t0t2t4 = "acb" = s;
t1t3t5 = "zac" ≠ s;
t2t4t6 = "cba" ≠ s;
t3t5t7 = "acb" = s.
For t = "" and s = "xyz", the output should be almostSubstring(t, s) = 0.
Input/Output
[execution time limit] 4 seconds (py3)
[input] string t
A text represented as a string consisting of lowercase English letters.
Guaranteed constraints:
0 ≤ t.length ≤ 1000.
[input] string s
A string of length 3 consisting of lowercase English letters.
Guaranteed constraints:
s.length = 3.
[output] integer
The number of indices i, such that titi+2ti+4 = s.
*/

#include <iostream>
#include <string>
using namespace std;

int almostSubstring(string t, string s){
    int counter = 0;
    
    for(int j= 0; j <= t.length(); j += 2){
        if(t[j] == s[0] && t[j+2] == s[1] && t[j+4] == s[2] ){
            counter++;
        }
    }
    
    for(int j = 1; j <= t.length(); j += 2){
        if( t[j] == s[0] && t[j+2] == s[1] && t[j+4] == s[2]){
            counter++;
        }
    }
    
    return counter;
}

int main()
{
    string t = "azcabcab", s = "acb";
    cout << almostSubstring(t, s) << endl;
	cout << almostSubstring("", "xyz") << endl;
    return 0;
}