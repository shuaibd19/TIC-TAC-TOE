/*AHMAD DORANI
TORRENS UNIVERSITY
00290332T

GITHUB: https://github.com/shuaibd19/TIC-TAC-TOE 
REFERENCE CODE: http://www.cppforschool.com/project/tic-tac-toe-project.html */

#include <fstream>
#include <Windows.h>
#include <time.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

//a char array used to store the inital board elements
char cell[9] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I' };

//function used for the drawing of the board state
void dispBoard();
//function checks whether or not a winning state has been achieved
//either returning a true or a false value
bool winningState();
//player vs player mode
void playerVsPlayer();
//computer vs player mode
void computerVsPlayer();

int main()
{
	int choice = 0;
	cout << "WELCOME TO TIC TAC TOE!!\n";
	cout << "Press 1 for Human vs Human\n";
	cout << "Press 2 for Human vs Computer\n";
	cin >> choice;

	if (choice < 1 || choice > 2)
	{
		cout << "INVALID!! CHOOSE AGAIN:\n";
		cout << "WELCOME TO TIC TAC TOE!!\n";
		cout << "Press 1 for Human vs Human\n";
		cout << "Press 2 for Human vs Computer\n";
		cin >> choice;
	}

	if (choice == 1)
	{
		playerVsPlayer();
	}
	else
	{
		computerVsPlayer();
	}


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
	//checking wether the data stored in the cell array matches its
	//specified neighbors and returning true or false accordingly
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

void playerVsPlayer()
{
	int moveCount = 0;
	char choice = '/';
	char playerSprite;
	int player = 1;
	bool gameWon = false;
	//game loop continues for as long as nobody has won
	while (!gameWon)
	{
		//get the current winning state of the board
		gameWon = winningState();
		//in the case of a draw i've added a counter to make sure
		//after 9 moves (the entire board) has been filled and 
		//no one has won then to break from the function and declare
		//the game a draw
		if (moveCount == 9)
		{
			break;
		}
		dispBoard();

		//toggling between players
		player = (player % 2) ? 1 : 2;
		cout << "Player Number " << player << " please select a character: ";
		cin >> choice;
		//making sure the player's choice matches with the cell values
		choice = toupper(choice);

		//setting the sprites for both players
		playerSprite = (player == 1) ? 'X' : 'O';

		//checking if the player enters a valid entry and in such a case
		//put the player sprite in the position of the cell
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

		//error checking for incorrect inputc - I know Noman.. I shouldn't
		//just exit from the program like that...
		else
		{
			cout << "INVALID MOVE!! :-O\n";
			exit(1);
		}
		player = player + 1;
		moveCount++;
	}

	//logic for finding out what to print when declaring the winner
	//using the number of moves. odd and even checking depening on who 
	//went first
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
}

void computerVsPlayer()
{
	srand((unsigned int)time(NULL));
	int moveCount = 0;
	char choice = '/';
	//i also added a computer choice variable different from 
	//the player choice
	char compChoice = '.';
	char playerSprite;
	int player = 1;
	bool gameWon = false;

	//i created a vector copy of the possible characters
	//and you will see why below
	vector<char> charSet;
	charSet.push_back('A');
	charSet.push_back('B');
	charSet.push_back('C');
	charSet.push_back('D');
	charSet.push_back('E');
	charSet.push_back('F');
	charSet.push_back('G');
	charSet.push_back('H');
	charSet.push_back('I');

	while (!gameWon)
	{
		gameWon = winningState();
		if (moveCount == 9)
		{
			break;
		}
		dispBoard();
		player = (player % 2) ? 1 : 2;
		playerSprite = (player == 1) ? 'X' : 'O';

		//for the human 
		if (player == 1)
		{
			cout << "Player Number " << player << " please select a character: ";
			cin >> choice;
			choice = toupper(choice);

			//creating an iterator of type char
			vector<char>::iterator playerErase;
			//find the character just entered by the human player and delete it from
			//the vector created above so that the computer doesn't use it
			playerErase = find(charSet.begin(), charSet.end(), choice);
			if (playerErase != charSet.end())
			{
				charSet.erase(playerErase);
			}

		}
		//for the computer
		if (player == 2)
		{
			//create another iterator of type char this time for
			//the computer
			vector<char>::iterator compErase;
			//shuffle the character set
			random_shuffle(charSet.begin(), charSet.end());
			//the computer takes the first element on the character set after shuffling
			compChoice = charSet.front();
			//just as before this time the computer choice is removed from the character 
			//set so that the computer never double picks something that was already chosen
			compErase = find(charSet.begin(), charSet.end(), compChoice);
			if (compErase != charSet.end())
			{
				charSet.erase(compErase);
			}
			cout << "The computer chooses: " << compChoice << endl;
			Sleep(3000);
		}

		if ((choice == 'A' && cell[0] == 'A') || (compChoice == 'A' && cell[0] == 'A'))
		{
			cell[0] = playerSprite;
		}

		else if ((choice == 'B' && cell[1] == 'B') || (compChoice == 'B' && cell[1] == 'B'))
		{
			cell[1] = playerSprite;
		}

		else if ((choice == 'C' && cell[2] == 'C') || (compChoice == 'C' && cell[2] == 'C'))
		{
			cell[2] = playerSprite;
		}

		else if ((choice == 'D' && cell[3] == 'D') || (compChoice == 'D' && cell[3] == 'D'))
		{
			cell[3] = playerSprite;
		}

		else if ((choice == 'E' && cell[4] == 'E') || (compChoice == 'E' && cell[4] == 'E'))
		{
			cell[4] = playerSprite;
		}

		else if ((choice == 'F' && cell[5] == 'F') || (compChoice == 'F' && cell[5] == 'F'))
		{
			cell[5] = playerSprite;
		}

		else if ((choice == 'G' && cell[6] == 'G') || (compChoice == 'G' && cell[6] == 'G'))
		{
			cell[6] = playerSprite;
		}

		else if ((choice == 'H' && cell[7] == 'H') || (compChoice == 'H' && cell[7] == 'H'))
		{
			cell[7] = playerSprite;
		}

		else if ((choice == 'I' && cell[8] == 'I') || (compChoice == 'I' && cell[8] == 'I'))
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


		if ((moveCount % 2) == 1)
		{
			player = 2;
		}
		else
		{
			player = 1;
		}

		//this time in the case of a loss the computer writes to a text file which 
		//has its entire loss history and adds a -1 to it and likewise with a win
		//only difference being that it appends a 1 to the text file
		if (gameWon)
		{
			if (player == 1)
			{
				cout << "HUMAN HAS WON!\n\n";
				ofstream loseFile;
				loseFile.open("losses.txt", std::ios_base::app);
				loseFile << -1 << " ";
			}
			else
			{
				cout << "COMPUTER REIGNS SUPREME\n\n";
				ofstream winFile;
				winFile.open("wins.txt", std::ios_base::app);
				winFile << 1 << " ";
			}
		}
		else
			cout << "Game Drawn!!\n\n";
	}
}
