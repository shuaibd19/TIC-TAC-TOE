#include <iostream>

using namespace std;

char cell[9] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I' };

//function used for the drawing of the board state
void dispBoard();
bool winningState();

int main()
{
	int moveCount = 0;
	char choice = '/';
	char playerSprite;
	int player = 1;
	bool gameWon = false;
	while (!gameWon)
	{
		gameWon = winningState();
		if (moveCount == 9)
		{
			break;
		}
		dispBoard();
		player = (player % 2) ? 1 : 2;
		cout << "Player Number " << player << " please select a character: ";
		cin >> choice;
		choice = toupper(choice);

		playerSprite = (player == 1) ? 'X' : 'O';

		if (choice == 'A' && cell[0] == 'A')
		{
			cell[0] = playerSprite;
		}

		else if (choice == 'B' && cell[1] == 'B')
		{
			cell[1] = playerSprite;
		}

		else if (choice == 'C' && cell[2] == 'C')
		{
			cell[2] = playerSprite;
		}

		else if (choice == 'D' && cell[3] == 'D')
		{
			cell[3] = playerSprite;
		}

		else if (choice == 'E' && cell[4] == 'E')
		{
			cell[4] = playerSprite;
		}

		else if (choice == 'F' && cell[5] == 'F')
		{
			cell[5] = playerSprite;
		}

		else if (choice == 'G' && cell[6] == 'G')
		{
			cell[6] = playerSprite;
		}

		else if (choice == 'H' && cell[7] == 'H')
		{
			cell[7] = playerSprite;
		}

		else if (choice == 'I' && cell[8] == 'I')
		{
			cell[8] = playerSprite;
		}

		else
		{
			cout << "INVALID MOVE!! :-O\n";
			exit(1);
		}
		player = player + 1;
		moveCount++;
	}

	if ((moveCount % 2) == 1)
	{
		player = 2;
	}
	else
	{
		player = 1;
	}

	if (gameWon)
	{
		cout << "Player: " << player << " has won!\n\n";
	}
	else
		cout << "Game Drawn!!\n\n";


	return 0;
}

void dispBoard()
{
	system("cls");
	cout << "TIC-TAC-TOE\n\n";
	cout << "Player 1 - X   Player 2 - O\n\n\n";
	cout << "     |     |     " << endl;
	cout << "  " << cell[0] << "  |  " << cell[1] << "  |  " << cell[2] << endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << cell[3] << "  |  " << cell[4] << "  |  " << cell[5] << endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << cell[6] << "  |  " << cell[7] << "  |  " << cell[8] << endl;
	cout << "     |     |     " << endl << endl;
}

bool winningState()
{
	bool gameWon = false;

	if (cell[0] == cell[1] && cell[1] == cell[2])
	{
		gameWon = true;
		return gameWon;
	}

	else if (cell[3] == cell[4] && cell[4] == cell[5])
	{
		gameWon = true;
		return gameWon;
	}

	else if (cell[6] == cell[7] && cell[7] == cell[8])
	{
		gameWon = true;
		return gameWon;
	}

	else if (cell[0] == cell[3] && cell[3] == cell[6])
	{
		gameWon = true;
		return gameWon;
	}

	else if (cell[1] == cell[4] && cell[4] == cell[7])
	{
		gameWon = true;
		return gameWon;
	}

	else if (cell[2] == cell[5] && cell[5] == cell[8])
	{
		gameWon = true;
		return gameWon;
	}

	else if (cell[0] == cell[4] && cell[4] == cell[8])
	{
		gameWon = true;
		return gameWon;
	}

	else if (cell[2] == cell[4] && cell[4] == cell[6])
	{
		gameWon = true;
		return gameWon;
	}

	else return gameWon;
}
