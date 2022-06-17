//preprocessor directives
#include <iostream>
#include<iomanip>
#include "TTT.h"
using namespace std;

TicTacToe::TicTacToe()
{
		//Intializing with zero
		square[3][3] = 0;  //initializing the whole 2D 3x3 array with 0, every entry is 0
		int n = 10;//number to initialize. First box, row 0 column 0 is named 10, and like that row and column change and boxes are named from 10 to 18
		//nested loop used because we are accessing 2D array
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				square[i][j] = n++;
			}

		}
		//Box Print
		//function calling
		display();
		//checkwin
		checkwin();
		data();
}
void TicTacToe::display()
{
	cout << "\t ---  ---  ---\n\t|";
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << setw(2) << setfill('0') << square[i][j] << " | ";

		}
		cout << "\n\t ---  ---  ---\n\t|";

	}
}
void TicTacToe::data()
{
	for (int i = 1; i < 5; i++)
	{
		//Player 1
		challenger();
		display();
		result = checkwin();
		if (result == 1) {
			find();
			exit(0);
		}

		//Player 2
		opponent();
		display();
		result = checkwin();
		if (result == 2) {
			find();
			exit(0);
		}
	}
	find();

}
void TicTacToe::challenger() {
	cout << "\n Player " << player1 << " Enter the Box: ";
	cin >> box;
	check();//giving arguments to mark()

	mark(player1, row, col);

}
void TicTacToe::opponent() {
	cout << "\n Player " << player2 << " Enter the Box: ";
	cin >> box;
	check();//giving paramters to mark()

	mark(player2, row, col);

}
void TicTacToe::check() {
check:
	while (1) //infinite loop
	{
		if (box == 10)
		{
			row = 0;
			col = 0;
			goto exit;
		}
		else if (box == 11)
		{
			row = 0;
			col = 1;
			goto exit;
		}
		else if (box == 12)
		{
			row = 0;
			col = 2;
			goto exit;
		}
		else if (box == 13)
		{
			row = 1;
			col = 0;
			goto exit;
		}
		else if (box == 14)
		{
			row = 1;
			col = 1;
			goto exit;
		}
		else if (box == 15)
		{
			row = 1;
			col = 2;
			goto exit;
		}
		else if (box == 16)
		{
			row = 2;
			col = 0;
			goto exit;
		}
		else if (box == 17)
		{
			row = 2;
			col = 1;
			goto exit;
		}
		else if (box == 18)
		{
			row = 2;
			col = 2;
			goto exit;
		}
		else
		{
			cout << "Wrong Entry!\n";
			cout << "Enter box# again: ";
			cin >> box;
			goto check;
		}
	}
exit:
	if (1) {};//null statement
}
void TicTacToe::find() {
	if (result == 1)
	{
		cout << "\n Congratualtions! player " << player1 << " has Won \n";
		flag = 1;


	}
	else if (result == 2)
	{
		cout << "\n Congratualtions! player " << player2 << " has Won \n";
		flag = 1;

	}
	else if (flag == 0) {
		cout << " \n Sorry, The game is a draw \n";
	}
	else {
		//null statement, doesnot matter if you write else or not
	}
}
void TicTacToe::mark(int player, int row, int col)
{
	if (player == 1)
	{
		//Player1
		if (square[row][col] == 1 || square[row][col] == 2) {
			cout << " !!!Wrong Input!!!Enter Box# agian: ";
			challenger();
		}
		else {
			square[row][col] = 1;
		}
	}
	else {
		//Player2
		if (square[row][col] == 1 || square[row][col] == 2) {
			cout << " !!!Wrong Input!!!Enter Box# agian: ";
			opponent();
		}
		else {
			square[row][col] = 2;
		}
	}
}
int TicTacToe::checkwin()
{
	if (square[0][0] == square[0][1] && square[0][1] == square[0][2])  //1st row
	{
		if (square[0][0] == 1)
			return 1;
		else
			return 2;
	}
	else if (square[1][0] == square[1][1] && square[1][1] == square[1][2]) //2nd row
	{
		if (square[1][0] == 1)
			return 1;
		else
			return 2;
	}
	else if (square[2][0] == square[2][1] && square[2][1] == square[2][2])  //3rd row
	{
		if (square[2][0] == 1)
			return 1;
		else
			return 2;
	}
	else if (square[0][0] == square[1][0] && square[1][0] == square[2][0]) //1st column
	{
		if (square[0][0] == 1)
			return 1;
		else
			return 2;
	}
	else if (square[0][1] == square[1][1] && square[1][1] == square[2][1]) //2nd column
	{
		if (square[0][1] == 1)
			return 1;
		else
			return 2;
	}
	else if (square[0][2] == square[1][2] && square[1][2] == square[2][2])  //3rd column
	{
		if (square[0][2] == 1)
			return 1;
		else
			return 2;
	}
	else if (square[0][0] == square[1][1] && square[1][1] == square[2][2]) //primary diagonal
	{
		if (square[0][0] == 1)
			return 1;
		else
			return 2;
	}
	else if (square[0][2] == square[1][1] && square[1][1] == square[2][0]) //secondary diagonal
	{
		if (square[0][2] == 1)
			return 1;
		else
			return 2;
	}
	else {
		return 0;
	}
}
