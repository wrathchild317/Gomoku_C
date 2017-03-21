#include "State.h"
#include <cassert>

/* Big 3 */

/*Constructor*/
State::State(const int size, const int current_player) :
			size(size), current_player(current_player) {

	this->light_pieces = new pieces();
	this->dark_pieces = new pieces();
	this->num_filled = 0;
	this->is_winning_board = false;
	this->winner = State::EMPTY;
	this->Board = new board();
	for(int i=0; i < size; i++){
		for(int j=0; j < size; j++){
			coordinate coord = coordinate(i,j);
			this->Board->insert(board_cell(coord, State::EMPTY));
		}
	}
}

/*Copy Constructor*/
State::State(const State & other) :
			size(other.size), num_filled(other.num_filled), current_player(other.current_player), 
			is_winning_board(other.is_winning_board), winner(other.winner) {

	this->light_pieces = new pieces(*(other.light_pieces));
	this->dark_pieces = new pieces(*(other.dark_pieces));
	this->Board = new board(*(other.Board));
}

/*Assignment Operator Overload*/
State& State::operator= (const State & other) {
	assert(this->size == other.size);

	if (this != &other) {   
    	//not self-assignment continue please ...
    	//delete all objects in the heap

    	delete this->light_pieces;
    	delete this->dark_pieces;
    	delete this->Board;

    	//now make copies of the original board
    	this->light_pieces = new pieces(*(other.light_pieces));
		this->dark_pieces = new pieces(*(other.dark_pieces));
		this->Board = new board(*(other.Board));

		this->num_filled = other.num_filled;
		this->current_player = other.current_player;
		this->is_winning_board = other.is_winning_board;
		this->winner = other.winner;

	}

  	return *this;
}

/* Destructor */
State::~State() {

	delete this->light_pieces;
    delete this->dark_pieces;
    delete this->Board;
}

/* Extra Class Operations */

bool State::is_empty() {
	return this->num_filled == 0;
}

bool State::is_full() {
	return this->num_filled == (this->size * this->size);
}

bool State::is_coord_within_range(const coordinate & coord) {
	int row = coord.first;
	int col = coord.second;
	return row >= 0 && col >= 0 && row < this->size && col < this->size;
}

bool State::is_valid_move(const coordinate & coord) {
	return is_coord_within_range(coord) && (*(this->Board))[coord] == State::EMPTY;
}

void State::move(const coordinate & coord) {

}

void State::is_winning(const coordinate & coord) {

}

int State::recursively_check_size(const coordinate & coord, const coordinate & direction, const int & previous_player) {
	return -999;
}

std::list<coordinate> State::actions() {
	return std::list<coordinate>();
}

/* Helper functions for printing out board */

std::ostream & operator <<(std::ostream& os, const coordinate& c)  {  
    os << "(" << c.first << ", " << c.second << ")";  
    return os;  
}  

std::ostream & operator <<(std::ostream& os, const board_cell& bc) {
  os << bc.first << " -> " << bc.second;
  return os;
}

std::ostream & operator <<(std::ostream& os, const board& b) {
  os << "[ ";
  
  for(board::const_iterator it = b.begin(); it != b.end(); ++it) {
    os << "{" << (*it) << "} ";
  }
  
  os << " ]";
  
  return os;
}

