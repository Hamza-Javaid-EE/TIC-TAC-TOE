//preprocessor directives
#include <iostream>
#include<iomanip>
using namespace std;



//class name
class TicTacToe
{
	//private data members, cannot be accessed outside class or by subclasses
private:
	int square[3][3];
	int row;
	int col;
	int box;
	int result = 0;
	int flag = 0;
	int player1 = 1;
	int player2 = 2;
	//public methods
public:
	// default constructor, automatically called when you create an object
	TicTacToe();
	//Display
	void display();
	//data
	void data();
	//Player 1
	void challenger();
	//Player 2
	void opponent();
	//check
	void check();
	//find who wins
	void find();

	//mark
	//if its player 1's turn, so it will put a 1 in that box, and it will put a 2 in player 2's turn
	void mark(int, int, int);
	//Checkwin
	int checkwin();

};//class ends
