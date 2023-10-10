#pragma once
#include <iostream>
using namespace std;

class connect4
{
private:
	char grid[7][6];
	char** board;
	int columns = 7;
	int rows = 6;

	int x;
	int y;
public:
	int _columns;
	int _rows;
	
	connect4()
	{
		for (int i = 0; i < columns; i++)
			for (int j = 0; j < rows; j++)
				grid[i][j] = ' ';
		x = 0;
		y = 6;


		board = new char* [_rows];
		for (int i = 0; i < _rows; i++)
			board[i] = new char[_columns];

		
	}

	void drawboard()
	{
		for (int j = 0; j < rows; j++)
		{
			for (int i = 0; i < columns; i++)
				cout << "| " << grid[i][j] << " ";
			cout << endl;
		}
		cout << "----------------------------";
		cout << endl;
	}

	bool Gameover()
	{
		winner();
		return false;
	}

	
	char winner()
	{
		//check for horizontal win
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns - 3; j++)
			{
				if (grid[i][j] != ' ' && grid[i][j + 1] && grid[i][j] == grid[i][j + 2] && grid[i][j] == grid[i][j + 3])
				{
					return grid[i][j];
				}
			}
		}
		//check for vertical win
		for (int i = 0; i < rows - 3; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				if (grid[i][j] != ' ' && grid[i][j] == grid[i + 1][j] && grid[i][j] == grid[i + 2][j] && grid[i][j] == grid[i + 3][j])
				{
					return grid[i][j];
				}
			}
		}
		//check for diagonal win (from top left to top right)
		for (int i = 0; i < rows - 3; i++)
		{
			for (int j = 0; j < columns - 3; j++)
			{
				if (grid[i][j] != ' ' && grid[i][j] == grid[i + 1][j + 1] && grid[i][j] == grid[i + 2][j + 2] && grid[i][j] == grid[i + 3][j + 3])
				{
					return grid[i][j];
				}
			}
		}
		//check for diagonal win (from top right to top left)
		for (int i = 0; i < rows - 3; i++)
		{
			for (int j = 3; j < columns; j++)
			{
				if (grid[i][j] != ' ' && grid[i][j] == grid[i + 1][j - 1] && grid[i][j] == grid[i + 2][j - 2] && grid[i][j] == grid[i + 3][j - 3])
				{
					return grid[i][j];
				}
			}
		}

		return false;
	}

	bool MakeMove(char piece, int column)
	{
		
		if (column < 0 || column > columns)
		{
			cout << "Please don't be dumb choose a correct column." << endl;
			return false;
		}
		
		int newy = y;
		int newx = column;
		if (column == 0)
			newy = y - 1;
		else if (column == 1)
			newy = y - 1;
		else if (column == 2)
			newy = y - 1;
		else if (column == 3)
			newy = y - 1;
		else if (column == 4)
			newy = y - 1;
		else if (column == 5)
			newy = y - 1;
		else if (column == 6)
			newy = y - 1;

		grid[x][y];
		for (int x = 0; x < rows; x++) 
		{
			if (grid[column][x] == 'X' || grid[column][x] == 'O' )
			{
				newy = x - 1;
				break;
			}
		}
		
		grid[newx][newy] = piece;
		return true;
	} 
	

	int getAImove()
	{
		srand(time(NULL));
		return rand() % columns;
	}

	connect4(int& numrows, int& numcolumns)
	{
		_rows = numrows;
		_columns = numcolumns;

		board = new char* [_rows];
		for (int i = 0; i < _rows; i++)
			board[i] = new char[_columns];

		for (int i = 0; i < numrows; i++)
			for (int j = 0; j < numcolumns; j++)
				grid[i][j] = ' ';
		x = _columns;
		y = _rows;
	}
};
