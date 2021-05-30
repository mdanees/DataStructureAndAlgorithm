/*Your task to check whether it is possible to construct a given array of integers from a bunch of given pieces.

More formally, you are given an array of distinct non-negative integers arr and an array of integer arrays pieces. Your task is to check whether it is possible to arrange the arrays of pieces in such a way that they can be concatenated to form an array equal to arr (containing all the same elements in the same order).

Example

    For arr = [1, 2, 5, 3] and pieces = [[5], [1, 2], [3]], the output should be shuffleThePieces(arr, pieces) = true.

    The arrays of pieces can be arranged in the order [1, 2], [5], and [3], which would be equal to arr = [1, 2, 5, 3] when concatenated.

    For arr = [1, 2, 5, 3, 6] and pieces = [[1, 2], [5], [6, 3]], the output should be shuffleThePieces(arr, pieces) = false.

    example

    There are no arrangements of pieces that would result in an array equal to arr.

    For arr = [1, 5, 4, 3, 2, 8] and pieces = [[4, 3], [1, 5], [2]], the output should be shuffleThePieces(arr, pieces) = false.

    Since the sum of the lengths of the arrays of pieces isn't equal to the length of arr, there's no way they could become equal, so the answer is false.

    For arr = [1, 5, 4, 3, 2, 8] and pieces = [[1, 5, 5], [3, 2], [8]], the output should be shuffleThePieces(arr, pieces) = false.

    Since the elements of arr aren't equal to the elements of the arrays of pieces, there's no way they could become equal, so the answer is false.

Input/Output

    [execution time limit] 0.5 seconds (cpp)

    [input] array.integer arr

    An array of pairwise distinct non-negative integers.

    Guaranteed constraints:
    1 ≤ arr.length ≤ 105,
    0 ≤ arr[i] ≤ 109.

    [input] array.array.integer pieces

    An array of arrays of non-negative integers. The total count of integers in pieces doesn't exceed 105.

    Guaranteed constraints:
    1 ≤ pieces.length ≤ 105,
    1 ≤ pieces[i].length ≤ 105,
    0 ≤ pieces[i][j] ≤ 109.

    [output] boolean

    Return true if it's possible to rearrange the arrays of pieces and concatenate them, such that the resulting array is equal to arr, otherwise return false.
*/

#include <vector>
#include <iostream>

using namespace std;

bool search(vector<int> piece, vector<int> arr)
{
	int index = -1;
	for (int i = 0; i < arr.size(); i++)
	{
		if (piece[0] == arr[i])
		{
			index = i;
			break;
		}
	}
	if (index == -1)
		return false;
	for (int i = 0; i < piece.size(); i++)
	{
		if (arr[index] == piece[i])
			index++;
		else
		{
			return false;
		}
	}
	return true;
}

bool shuffleThePieces(std::vector<int> arr, std::vector<std::vector<int>> pieces) {
	size_t siz = 0;
	for (size_t i = 0; i < pieces.size(); i++)
	{
		siz += pieces[i].size();
	}
	if (siz != arr.size())
		return false;
	for (int i = 0; i < pieces.size(); i++)
	{
		if (search(pieces[i], arr) == false)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	vector<int> arr1 = { 1, 5, 4, 3, 2, 8 };
	vector<vector<int>> pieces1 = { {1, 5, 5},{3, 2},{8} };
	
	vector<int> arr2 = { 1, 2, 5, 3 };
	vector<vector<int>> pieces2 = { {5},{1, 2},{3} };

	cout << shuffleThePieces(arr1, pieces1) << endl;
	cout << shuffleThePieces(arr2, pieces2) << endl;
	return 0;
}

