#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <vector>


class Grid
{
public:
	// the Grid class data members (public)
	std::vector<std::vector<char>> spaceVt;
	Grid();
	void assign_player(int row, int column, char playerToken);
	void print_layout();
	bool check_win_or_draw();
};


#endif
