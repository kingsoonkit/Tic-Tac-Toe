#include "gameSrc.h"


Grid::Grid()
{
	spaceVt.insert(spaceVt.end(), 3, std::vector<char>(3, '-')); 
}



void Grid::assign_player(int row, int column, char playerToken)
{
	spaceVt[row][column] = playerToken;
}



void Grid::print_layout()
{
	// Print whole grid layout, with each space wtih "coordinates" of 2 indexes. (2D vectors)
	std::cout << "----------------------------------------------------------\n";
	std::cout << " \t\t -\x1a [1]   [2]   [3]  (Columns)\n";
	std::cout << " \t\t\x19\n";
	std::cout << " \t\t[1]  " << spaceVt[0][0] << "  |  " << spaceVt[0][1] << "  |  " << spaceVt[0][2] << std::endl;
	std::cout << " \t\t   -----+-----+-----\n";
	std::cout << " \t\t[2]  " << spaceVt[1][0] << "  |  " << spaceVt[1][1] << "  |  " << spaceVt[1][2] << std::endl;
	std::cout << " \t\t   -----+-----+-----\n";
	std::cout << " \t\t[3]  " << spaceVt[2][0] << "  |  " << spaceVt[2][1] << "  |  " << spaceVt[2][2] << std::endl;
	std::cout << "\n\t       (Rows)" << std::endl;
	std::cout << "----------------------------------------------------------\n";
}



bool Grid::check_win_or_draw()
{
	if (spaceVt[0][0] == 'X' && spaceVt[0][1] == 'X' && spaceVt[0][2] == 'X' ||   // All possible winning conditons for Player X
		spaceVt[1][0] == 'X' && spaceVt[1][1] == 'X' && spaceVt[1][2] == 'X' ||
		spaceVt[2][0] == 'X' && spaceVt[2][1] == 'X' && spaceVt[2][2] == 'X' ||
		spaceVt[0][0] == 'X' && spaceVt[1][0] == 'X' && spaceVt[2][0] == 'X' ||
		spaceVt[0][1] == 'X' && spaceVt[1][1] == 'X' && spaceVt[2][1] == 'X' ||
		spaceVt[0][2] == 'X' && spaceVt[1][2] == 'X' && spaceVt[2][2] == 'X' ||
		spaceVt[0][0] == 'X' && spaceVt[1][1] == 'X' && spaceVt[2][2] == 'X' ||
		spaceVt[2][0] == 'X' && spaceVt[1][1] == 'X' && spaceVt[0][2] == 'X')
	{
		print_layout();
		std::cout << "\n\t   [  P L A Y E R   X   W I N S  ]\n";
		std::cout << "\t   [  P L A Y E R   X   W I N S  ]\n";
		std::cout << "\t   [  P L A Y E R   X   W I N S  ]\n";
		return true;    // check_win_or_draw() will return a true
	}
	else if (spaceVt[0][0] == 'O' && spaceVt[0][1] == 'O' && spaceVt[0][2] == 'O' ||  // All possible winning conditons for Player O
		spaceVt[1][0] == 'O' && spaceVt[1][1] == 'O' && spaceVt[1][2] == 'O' ||
		spaceVt[2][0] == 'O' && spaceVt[2][1] == 'O' && spaceVt[2][2] == 'O' ||
		spaceVt[0][0] == 'O' && spaceVt[1][0] == 'O' && spaceVt[2][0] == 'O' ||
		spaceVt[0][1] == 'O' && spaceVt[1][1] == 'O' && spaceVt[2][1] == 'O' ||
		spaceVt[0][2] == 'O' && spaceVt[1][2] == 'O' && spaceVt[2][2] == 'O' ||
		spaceVt[0][0] == 'O' && spaceVt[1][1] == 'O' && spaceVt[2][2] == 'O' ||
		spaceVt[2][0] == 'O' && spaceVt[1][1] == 'O' && spaceVt[0][2] == 'O')
	{
		print_layout();
		std::cout << "\n\t   [  P L A Y E R   O   W I N S  ]\n";
		std::cout << "\t   [  P L A Y E R   O   W I N S  ]\n";
		std::cout << "\t   [  P L A Y E R   O   W I N S  ]\n";
		return true;     // check_win_or_draw() will return a true
	}
	return false;
}


