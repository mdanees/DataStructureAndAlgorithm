#include <vector>
#include <string>
#include <iostream>
#include <regex>

using namespace std;

int brokenKeyboard(string text, vector<char> letters)
{
	int ans = 0;
	char ch[26] = {0};
	
	std::transform(text.begin(), text.end(), text.begin(),
		[](unsigned char c) { return std::tolower(c); });
	std::regex regex("\\ ");
	std::vector<std::string> words(
		std::sregex_token_iterator(text.begin(), text.end(), regex, -1),
		std::sregex_token_iterator()
	);

	if (letters.size() == 0)
		return words.size();

	for (char c : letters) {
		c = tolower(c);
		ch[c - 'a']++;
	}

	bool found = true;
	for (auto& w : words) {
		found = true;
		for (char c : w) {
			if (isalpha(c) && ch[c - 'a'] == 0) {
				found = false;
				break;
			}
		}

		if (found)
			++ans;
	}

	return ans;
}


int main()
{
	string text1 = "Hello,?! this is CodeSignal!";
	vector<char> letters1 = {'e', 'i', 'h', 'l', 'o', 'S'};
	string text2 = "? !";
	vector<char> letters2 = { 'e', 'i', 'h', 'l', 'o', 'S' };
	string text3 = "? !o e E";
	vector<char> letters3 = { 'e', 'i', 'h', 'l', 'o', 'S' };
	string text4 = "Hi, this is Chris!";
	vector<char> letters4 = { 'r', 's', 't', 'o', 'c', 'h' };
	string text5 = "3 + 2 = 5";
	vector<char> letters5;

	cout << brokenKeyboard(text1, letters1) << endl; // 2
	cout << brokenKeyboard(text2, letters2) << endl; // 2
	cout << brokenKeyboard(text3, letters3) << endl; // 4
	cout << brokenKeyboard(text4, letters4) << endl; // 0
	cout << brokenKeyboard(text5, letters5) << endl; // 5
	
	return 0;
}