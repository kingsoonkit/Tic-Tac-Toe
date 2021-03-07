#include <iostream>
#include "gameSrc.h"


void display_instruct(bool playerTurn, bool instruct)
{
	if (instruct == true)
	{
		if (playerTurn == true)
		{
			std::cout << "          P L A Y E R   X   |                     \n";
			std::cout << "          P L A Y E R   X   |                     \n";
			std::cout << "          P L A Y E R   X   |                     \n";
		} 
		else
		{
			std::cout << "                            |   P L A Y E R   O   \n";
			std::cout << "                            |   P L A Y E R   O   \n";
			std::cout << "                            |   P L A Y E R   O   \n";
		}
		std::cout << "\n Type Row and Column number, then press enter (Exp : 23)\n";
	}
}


int main()
{
	Grid grid;
	int rowInput = 0;
	int columnInput = 0;
	bool play = true;
	bool playerTurn = true;
	bool instruct = true;
	int slots = 9;

	
	// PRINT grid layout
	grid.print_layout();

	do
	{
		if (slots != 0)   // If the slots is 0 without anyone winning, then it's a draw. Look at else statement below
		{
			
			// STEP 1 : Pre-setting true for Player X, false for Player O
			display_instruct(playerTurn, instruct);
			

			// STEP 2 : Accepts row and column input, check if input is out of bound
			int input;
			std::cin >> input;


			switch (input)
			{
			case 11:
				rowInput = 1;
				columnInput = 1;
				instruct = true;
				break;
			case 12:
				rowInput = 1;
				columnInput = 2;
				instruct = true;
				break;
			case 13:
				rowInput = 1;
				columnInput = 3;
				instruct = true;
				break;
			case 21:
				rowInput = 2;
				columnInput = 1;
				instruct = true;
				break;
			case 22:
				rowInput = 2;
				columnInput = 2;
				instruct = true;
				break;
			case 23:
				rowInput = 2;
				columnInput = 3;
				instruct = true;
				break;
			case 31:
				rowInput = 3;
				columnInput = 1;
				instruct = true;
				break;
			case 32:
				rowInput = 3;
				columnInput = 2;
				instruct = true;
				break;
			case 33:
				rowInput = 3;
				columnInput = 3;
				instruct = true;
				break;
			default:
				rowInput = 0;
				columnInput = 0;
				std::cout << "\t     { O U T   O F   B O U N D }\n";
				instruct = false;
				break;
			}



			std::cout << std::endl;


			// STEP 3 : Alter space '-' into player token depending on given row and column input, then swap player turns    
			for (int row = 0; row < 3; row++)    // To loop through row index
			{
				for (int column = 0; column < 3; column++)  // To loop through column index
				{
					// If rowInput && columInput is same with the current loop value, go to player assignement. if not, scold player bcs their input is wrong :D
					if (rowInput - 1 == row && columnInput - 1 == column)
					{
						if (grid.spaceVt[rowInput - 1][columnInput - 1] == '-')   //if space is equal to "-", player slot assignment begins
						{
							if (playerTurn)  // If true, it's Player X's turn, X, returning 'X'
							{
								system("cls");
								grid.assign_player(row, column, 'X');
								playerTurn = !playerTurn;  // Swap turns
								slots--;            // Decrement each slot after each player slot assignment
								// STEP 4 : If a player won, play is assigned to false then the do while loop ends
								if (grid.check_win_or_draw() == true)
								{
									play = false;  // Do-while loop ends
								}
								else
								{
									grid.print_layout();
								}
							}
							else if (!playerTurn) // If NOT true (false), it's Player O's turn, returning 'O'
							{
								system("cls");
								grid.assign_player(row, column, 'O');
								playerTurn = !playerTurn;  // Swap turns-
								slots--;            // Decrement each slot after each player slot assignment
								if (grid.check_win_or_draw() == true)
								{
									play = false;  // Do-while loop ends
								}
								else
								{
									grid.print_layout();
								}
							}
						}
						else  // Scold player bcs the slot has been marked :D
						{
							std::cout << "       { S L O T   H A S   B E E N   T A K E N }\n";
							instruct = false;
						}
					}

				}
			}
		}
		else
		{
			std::cout << "\n\t\t[   D R A W   ]\n";
			std::cout << "\t\t[   D R A W   ]\n";
			std::cout << "\t\t[   D R A W   ]\n";

			play = false;  // Do-while loop ends
		}
	} while (play == true);
}