#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

char getComputerMove()
{
	int move;
	// generating  random number between 0 - 2
	srand(time(NULL));
	move = rand() % 3;

	// returning move based on the random number generated 
	if (move == 0)	
	{
		return 'p';		
	}

	else if (move == 1)
	{
		return 's';
	}

	return 'r';
}

// Function to return the result of the game
int getResults(char playerMove, char computerMove)
{
	// condition for draw
	if (playerMove == computerMove)
	{
		return 0;
	}

	// condition for win and loss according to game rule
	if (playerMove == 's' && computerMove == 'p')
	{
		return 1;
	}
	if (playerMove == 's' && computerMove == 'r')
	{
		return -1;
	}

	if (playerMove == 'p' && computerMove == 'r')
	{
		return 1;		
	}
	if (playerMove == 'p' && computerMove == 's')
	{
		return -1;
	}

	if (playerMove == 'r' && computerMove == 'p')
	{
		return -1;
	}
	if (playerMove == 'r' && computerMove == 's')
	{
		return 1;
	}

	return 0;
}

// driver code
int main()
{
	char playerMove;

	cout << "\n\n\n\t\t\tWelcome To Rock Paper Scissor "
			"Game\n";

	cout << "\n\t\tEnter r for the ROCK, p for PAPER, and s "
			"for SCISSOR\n\t\t\t\t\t";

	// input from the user
	while(1)
	{
		cin >> playerMove;
		if (playerMove == 'p' || playerMove == 'r' || playerMove == 's')
		{
			break;
		}
		else
		{
			cout << "\t\t\tInvalid Player Move!!! Please Try Again." << endl;
		}
	}

	// computer move
	char computerMove = getComputerMove();

	int result = getResults(playerMove, computerMove);
	
	// printing results based on who won the game
	if (result == 0)
	{
		cout << "\n\t\t\tGame Draw!\n";
	}
	
	else if (result == 1)
	{
		cout << "\n\t\t\tCongratulations! Player won the"
				"game!\n";
	}

	else
	{
		cout << "\n\t\t\tOh! Computer won the game!\n";	
	}

	// show both moves
	cout << "\t\t\tYour Move: " << playerMove << "\n";
	cout << "\t\t\tComputer's Move: " << computerMove << "\n";

	return 0;
}























