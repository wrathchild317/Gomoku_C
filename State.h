#ifndef __STATE_H__
#define __STATE_H__

#include <iostream>
#include <string>
#include <list>
#include <utility>
#include <map>

typedef std::pair<int, int> coordinate;
typedef std::pair<coordinate, int> board_cell;
typedef std::map<coordinate, int> pieces;
typedef std::map<coordinate, int> board;
typedef std::string string;


class State {
	/* State static constants */
	public:
		static const int EMPTY = 0;
		static const int DARK = 1;
		static const int LIGHT = 2;
		static const int NUM_CONNECTED = 5;
		static const double TIME_LIMIT = 29.5;
	/* Private Member Variables */
	private:
		int size; //represent dimension of board N*N
		pieces* light_pieces; //holds all coordinates where LIGHT has placed a piece
		pieces* dark_pieces; //holds all coordinates where DARK has placed a piece
		board* Board; //map of coordinates that are EMPTY,LIGHT, or DARK
		int num_filled; //number of cells filled
		int current_player; //player who's picks an actions
		bool is_winning_board; //if a player has five in a row
		int winner; //holds the player that wins either LIGHT, DARK, or EMPTY.

	/* Public methods */

	public:
		/* Big 3 functions plus assignment operator */
		State(int size, int current_player);
		State(const State & other);
		State & operator= (const State & other);
		~State();

		bool is_empty();
		bool is_full();
		bool is_coord_within_range(const coordinate & coord);
		bool is_valid_move(const coordinate & coord);
		void move(const coordinate & coord);
		void is_winning(const coordinate & coord);
		int recursively_check_size(const coordinate & coord, const coordinate & direction, const int & previous_player);
		std::list<coordinate> actions();

};

#endif