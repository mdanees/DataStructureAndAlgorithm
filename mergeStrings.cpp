/*
You are implementing your own programming language and you've decided to add support for merging strings. A typical merge function would take two strings s1 and s2, and return the lexicographically smallest result that can be obtained by placing the symbols of s2 between the symbols of s1 in such a way that maintains the relative order of the characters in each string.

For example, if s1 = "super" and s2 = "tower", the result should be merge(s1, s2) = "stouperwer".

You'd like to make your language more unique, so for your merge function, instead of comparing the characters in the usual lexicographical order, you'll compare them based on how many times they occur in their respective initial strings (fewer occurrences means the character is considered smaller). If the number of occurrences are equal, then the characters should be compared in the usual lexicographical way. If both number of occurences and characters are equal, you should take the characters from the first string to the result. Note that occurrences in the initial strings are compared - they do not change over the merge process.

Given two strings s1 and s2, return the result of the special merge function you are implementing.

Example

    For s1 = "dce" and s2 = "cccbd", the output should be
    mergeStrings(s1, s2) = "dcecccbd".

All symbols from s1 goes first, because all of them have only 1 occurrence in s1 and c has 3 occurrences in s2.
*/
// author : Mohammed Anees
// 04/24/2021
// email id: mohammed.anees@outlook.com

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string mergeStrings(string s1, string s2)
{
    string ans;
    char ch1[26] = {0};
    char ch2[26] = {0};

    for (char x : s1)
        ++ch1[x - 97];
    for (char x : s2)
        ++ch2[x - 97];

    string::iterator it1 = s1.begin();
    string::iterator it2 = s2.begin();

    while (1) {
        if (it1 != s1.end() && it2 != s2.end()) {    
            if (ch1[*it1 - 97] < ch2[*it2 - 97]) {
                ans.push_back(*it1);
                ++it1;
            }
            else if ( ch1[*it1-97] > ch2[*it2-97] ) {
                ans.push_back(*it2);
                ++it2;
            }
            else if (*it1 <= *it2) {
                ans.push_back(*it1);
                ++it1;
            }
            else {
                ans.push_back(*it2);
                ++it2;
            }
        }
        else if (it1 != s1.end()) {
            ans.push_back(*it1);
            ++it1;
        }
        else if (it2 != s2.end()) {
            ans.push_back(*it2);
            ++it2;
        }
        else
            break;
    }

    return ans;
}

int main(int argc, char* argv[])
{
    cout << mergeStrings("super","tower")<<endl;
    cout << mergeStrings("dec", "cccbd")<<endl;

    return 0;
}
