#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

string newTextEditor(vector<string> operations) {
    stack<string> history;
    string opr;
    string str;
    string copy;

    for (int i = 0; i < operations.size(); ++i) {
        opr = operations[i];
        if (opr.substr(0, 6) == "INSERT") {
            str += opr.substr(opr.find_first_of(" ") + 1);
            history.push(opr);
        } if (opr.substr(0, 6) == "DELETE") {
            if (str.length() > 0) {
                history.push(opr + " " + str.substr(str.length() - 1));
                str.erase(str.length() - 1);
            }
        }
        else if (opr.substr(0, 4) == "COPY" && str.length() > 0) {
            int ind = atoi(opr.substr(opr.find_first_of(" ") + 1).c_str());
            copy = str.substr(ind);
        }
        else if (opr == "PASTE" && copy.length() > 0) {
            str += copy;
            history.push(opr + " " + copy);
        }
        else if (opr == "UNDO" && history.size() > 0) {
            opr = history.top();
            history.pop();

            if (opr.substr(0, 6) == "INSERT") {
                string act = opr.substr(opr.find_first_of(" ") + 1);
                if(str.length() >= act.length())
                    str.erase(str.length() - act.length());
            } if (opr.substr(0, 6) == "DELETE") {
                string act = opr.substr(opr.find_first_of(" ") + 1);
                str += act;
            }
            else if (opr.substr(0, 5) == "PASTE") {
                string act = opr.substr(opr.find_first_of(" ") + 1);
                str.erase(str.length() - act.length());
            }
        }
    }

    return str;
}


int main()
{
    vector<string> operation1 = {"INSERT Code","INSERT Signal","DELETE"};
    vector<string> operation2 = {"INSERT a","DELETE","UNDO","DELETE","COPY 2","PASTE","UNDO","INSERT b","INSERT b","COPY 0","PASTE","UNDO" };
    vector<string> operation3 = {"INSERT aaa", "DELETE" };
    vector<string> operation4 = {
                "INSERT aaa",
                "COPY 0",
                "INSERT bb",
                "PASTE" };
    vector<string> operation5 = {
                "INSERT aaa",
                "COPY 0",
                "INSERT bb",
                "PASTE",
                "UNDO" };
    vector<string> operation6 = {
                "INSERT aaa",
                "COPY 0",
                "INSERT bb",
                "PASTE",
                "UNDO",
                "UNDO" };

    vector<string> operation7 = {
                    "INSERT Da",
                    "COPY 0",
                    "UNDO",
                    "PASTE",
                    "PASTE",
                    "COPY 2",
                    "PASTE",
                    "PASTE",
                    "DELETE",
                    "INSERT aaam" };


    cout << newTextEditor(operation1) << endl;
    cout << newTextEditor(operation2) << endl;
    cout << newTextEditor(operation3) << endl;
    cout << newTextEditor(operation4) << endl;
    cout << newTextEditor(operation5) << endl;
    cout << newTextEditor(operation6) << endl;
    cout << newTextEditor(operation7) << endl;
    return 0;
}