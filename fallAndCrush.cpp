/*You are running a gravity simulation involving falling boxes and breakable obstacles. The situation is represented by two rectangular matrices of equal dimensions, board and strengths.

Each cell of the matrix board contains one of three characters:

    '.', which means that the cell is empty;
    '*', which means that the cell contains an obstacle;
    '#', which means that the cell contains a box.

The matrix strengths shows the strength of each obstacle - the maximum number of boxes that can be stacked on top of the obstacle without it breaking.

    If board{i}{j} = '*' then strengths{i}{j} is a positive integer;
    Otherwise, strengths{i}{j} = 0 (if board{i}{j} is '.' or '#').

The boxes each fall down as far as possible, until hitting an obstacle, another grounded box, or the bottom of the board. If the amount of boxes directly on top of an obstacle exceeds its strength, then the obstacle is crushed under the pressure and the boxes above continue falling.

Given board and strengths, your task is to return the state of the board after all boxes have fallen.

Example

    For

board = {{'.', '#', '#', '#', '*'},
         {'#', '#', '.', '#', '#'},
         {'.', '.', '.', '#', '.'},
         {'.', '.', '*', '*', '#'},
         {'*', '#', '.', '.', '*'},
         {'.', '*', '.', '.', '.'}}

strengths = {{0, 0, 0, 0, 2},
             {0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0},
             {0, 0, 1, 1, 0},
             {3, 0, 0, 0, 1},
             {0, 2, 0, 0, 0}}

the output should be

fallAndCrush(board, strengths) = {{".", ".", ".", ".", "*"},
                                  {".", ".", ".", ".", "."},
                                  {".", ".", "#", ".", "."},
                                  {"#", "#", "*", "#", "."},
                                  {"*", "#", ".", "#", "#"},
                                  {".", "#", ".", "#", "#"}}

Example

    For

board = {{'#', '#', '#'},
         {'#', '#', '#'},
         {'#', '#', '#'},
         {'.', '.', '.'},
         {'*', '*', '*'},
         {'*', '*', '*'},
         {'*', '*', '*'}};

strengths = {{0, 0, 0},
             {0, 0, 0},
             {0, 0, 0},
             {0, 0, 0},
             {1, 3, 2},
             {2, 1, 3},
             {3, 2, 1}}

the output should be

fallAndCrush(board, strengths) = {{".", ".", "."},
                                  {".", "#", "."},
                                  {".", "#", "#"},
                                  {"#", "#", "#"},
                                  {"#", "*", "#"},
                                  {"#", "*", "*"},
                                  {"*", "*", "*"}}

Example

Input/Output

    {execution time limit} 0.5 seconds (cpp)

    {input} array.array.char board

    A matrix that shows where the boxes and obstacles are located. The matrix consists only of characters '.', '*', and '#'.

    Guaranteed constraints:
    3 ≤ board.length ≤ 100,
    3 ≤ board{i}.length ≤ 100.

    {input} array.array.integer strengths

    A matrix representing the strengths of the obstacles. The matrix consists of non-negative integers.

    Guaranteed constraints:
    3 ≤ strengths.length ≤ 100,
    3 ≤ strengths{i}.length ≤ 100,
    0 ≤ strengths{i}{j} ≤ 100.

    {output} array.array.char

    Return a matrix representing the state of the board after all of the boxes have fallen.
*/

#include <vector>
#include <iostream>

using namespace std;

vector<vector<char>> fallAndCrush(vector<vector<char>> board, vector<vector<int>> strengths) {
	int n = board.size();
	int m = board[0].size();
	int h = 0;

	vector<vector<char>> ans(n, vector<char>(m, '.'));

	for (int j = 0; j < m; ++j) {
		h = 0;
		for (int i = 0; i < n; ++i) {
			if (board[i][j] == '#')
				++h;
			else if (board[i][j] == '*') {
				if (h > 0 && h <= strengths[i][j])
				{
					int x = i;
					if (h <= strengths[i][j]) {
						ans[i][j] = '*';
						--x;
					}

					for (; x >= 0; --x)
					{
						if (h > 0) {
							ans[x][j] = '#';
							--h;
						}
						else if (h == 0) {
							if (board[x][j] == '*')
							{
								ans[x][j] = '*';
								break;
							}
						}
					}
					h = 0;
				}
				else
					ans[i][j] = '*';
			}
			if (i == n-1 && h > 0)
			{
				for (int x = i; x >= 0; --x)
				{
					if (h > 0) {
						ans[x][j] = '#';
						--h;
					}
					else if (h == 0) {
						if (board[x][j] == '*')
						{
							ans[x][j] = '*';
							break;
						}
					}
				}
			}
		}
	}

	return ans;
}

int main()
{
	vector<vector<char>> board1 = { {'.', '#', '#', '#', '*'},
								{'#', '#', '.', '#', '#'},
								{'.', '.', '.', '#', '.'},
								{'.', '.', '*', '*', '#'},
								{'*', '#', '.', '.', '*'},
								{'.', '*', '.', '.', '.'} };

	vector<vector<int>> strengths1 = { {0, 0, 0, 0, 2},
									{0, 0, 0, 0, 0},
									{0, 0, 0, 0, 0},
									{0, 0, 1, 1, 0},
									{3, 0, 0, 0, 1},
									{0, 2, 0, 0, 0} };

	vector<vector<char>> board2 = { {'#', '#', '#'},
		 {'#', '#', '#'},
		 {'#', '#', '#'},
		 {'.', '.', '.'},
		 {'*', '*', '*'},
		 {'*', '*', '*'},
		 {'*', '*', '*'} };

	vector<vector<int>> strengths2 = { {0, 0, 0},
				 {0, 0, 0},
				 {0, 0, 0},
				 {0, 0, 0},
				 {1, 3, 2},
				 {2, 1, 3},
				 {3, 2, 1} };

	vector<vector<char>> ans1 = fallAndCrush(board1, strengths1);
	vector<vector<char>> ans2 = fallAndCrush(board2, strengths2);
	
	for(auto v : ans1) {
		for(char c : v)
			cout << c << " ";
		cout << endl;
	}

	for(auto v : ans2) {
		for(char c : v)
			cout << c << " ";
		cout << endl;
	}
	
	return 0;
}
