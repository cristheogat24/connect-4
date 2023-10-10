#include<iostream>
#include<string>
#include"connect4.h"
using namespace std;

int main()
{
	srand(time(NULL));

	string choice;
	string choice2;
	int rows;
	int columns;

	connect4 standard;
	connect4 withai;
	/*
	connect4 customboard(rows, columns);
	*/
	cout << "Would you like to play a standard game or a custom board game?" << endl;
	cin >> choice;
	cout << "And would you be facing someone or an AI?" << endl;
	cin >> choice2;

	if (choice == "custom")
	{
		cout << "How big wyould you like your board to be (rows then columns)." << endl;
		cin >> rows;
		cin >> columns;
	}

	if (choice == "standard" && choice2 == "someone")
	{

		while (true)
		{
			char piece1;
			char piece2;
			int place;
			standard.drawboard();
			cout << "it is X turn, please choose a column (column 0 - 6)." << endl;
			piece1 = 'X';
			cin >> place;
			standard.MakeMove(piece1, place);
			cout << "it is O turn, pleae choose a column (column 0 - 6)." << endl;
			piece2 = 'O';
			cin >> place;
			standard.MakeMove(piece2, place);
			if (standard.winner())
			{
				standard.Gameover();;
				break;
			}

		}
	}
	else if (choice == "standard" && choice2 == "AI")
	{
		while (!withai.Gameover())
		{
			withai.drawboard();
			char playerPiece;
			int place;
			playerPiece = 'X';
			cout << "You go first against the AI. Please choose a column between 0 and 6." << endl;
			cin >> place;
			withai.MakeMove(playerPiece, place);
			withai.MakeMove('O', withai.getAImove());
			withai.winner();
			if (withai.winner())
			{
				withai.Gameover();
				break;
			}
			
		}
	}
	/*
	else if (choice == "custom" && choice2 == "AI")
	{

		while (!customboard.Gameover())
		{
			customboard.drawboard();
			char playerpiece;
			int place;
			playerpiece = 'O';
			cout << "Choose which column you would like to drop your piece. (0 - 6)" << endl;
			cin >> place;
			customboard.MakeMove(playerpiece, place);
			customboard.MakeMove('X', customboard.getAImove());
			if (customboard.winner())
			{
				customboard.Gameover();;
				break;
			}
		}
	}
	
	else if (choice == "custom" && choice2 == "someone")
	{

		while (true)
		{
			char piece1;
			char piece2;
			int place;
			customboard.drawboard();
			cout << "it is X turn, please choose a column (column 0 - 6)." << endl;
			piece1 = 'X';
			cin >> place;
			customboard.MakeMove(piece1, place);
			cout << "it is O turn, pleae choose a column (column 0 - 6)." << endl;
			piece2 = 'O';
			cin >> place;
			customboard.MakeMove(piece2, place);
			if (customboard.winner())
			{
				customboard.Gameover();;
				break;
			}
			
		}

	}
	
	*/
	return 0;
}
