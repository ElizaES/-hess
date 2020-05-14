//#include "pch.h"
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#define MAP_SIZE 8

using namespace std;

void SetBoard(char **board) {

	for (int i = 0; i < MAP_SIZE; i++)
	{
		for (int j = 0; j < MAP_SIZE; j++)
		{
			if (i % 2 == 0 && j % 2 == 1 || i % 2 == 1 && j % 2 == 0) {
				board[i][j] = '&';//white
			}
			else {
				board[i][j] = '_'; //black
			}
		}
	}
}

void DrawBoard(char **board) {

	cout << " ";
	for (int i = 0; i < MAP_SIZE; i++)
	{
		cout << i;
	}
	cout << endl;

	for (int i = 0; i < MAP_SIZE; i++)
	{
		cout << i;
		for (int j = 0; j < MAP_SIZE; j++)
		{
			cout << board[i][j];
		}
		cout << endl;
	}

}

char CheckColor(char **board, int X, int Y) {

	char color;

	if (X % 2 == 0 && Y % 2 == 1 || X % 2 == 1 && Y % 2 == 0) {
		color = '&';//white
	}
	else {
		color = '_'; //black
	}

	return color;

}

void SetWhiteBlackFigures(char **board, int white_num, int black_num, char white, char black) {

	int X_pos;
	int Y_pos;

	for (int i = white_num; i > 0;)
	{
		X_pos = rand() % 8;
		Y_pos = rand() % 8;

		if (board[X_pos][Y_pos] == '&' || board[X_pos][Y_pos] == '_')  {
			board[X_pos][Y_pos] = white;
			i--;
		}
	}

	for (int i = black_num; i > 0;)
	{
		X_pos = rand() % 8;
		Y_pos = rand() % 8;

		if (board[X_pos][Y_pos] == '&' || board[X_pos][Y_pos] == '_') {
			board[X_pos][Y_pos] = black;
			i--;
		}
	}


}

int StepFigure(char **board, int X, int Y, int white, int black, char side, char updown, int step_quantity) {
	char kolor_gonca = board[X][Y];

    if (kolor_gonca == black || kolor_gonca == white){

        // w lewo do gory
        if (side == 'l' && updown == 'g') {
            if (X - step_quantity < 0 || Y - step_quantity < 0 ){
                    cout << "Nie mozna ruszyc ";
                    Sleep(700);
                    return 0;
            }
            for (int i = 1; i < step_quantity; i++){
                if (!(board[X-i][Y-i] == '&' || board[X-i][Y-i] == '_')){
                    cout << "Nie mozna ruszyc ";
                    Sleep(700);
                    return 0;
                }
            }
            board[X-step_quantity][Y-step_quantity] = kolor_gonca;
            board[X][Y] = CheckColor(board, X, Y);
        }

        // w lewo w dol
        if (side == 'l' && updown == 'd') {
            if (X + step_quantity >= MAP_SIZE || Y - step_quantity < 0 ){
                    cout << "Nie mozna ruszyc ";
                    Sleep(700);
                    return 0;
            }
            for (int i = 1; i < step_quantity; i++){
                if (!(board[X+i][Y-i] == '&' || board[X+i][Y-i] == '_')){
                    cout << "Nie mozna ruszyc ";
                    Sleep(700);
                    return 0;
                }
            }
            board[X+step_quantity][Y-step_quantity] = kolor_gonca;
            board[X][Y] = CheckColor(board, X, Y);
       }

        // w prawo do gory
        if (side == 'p' && updown == 'g') {
            if (X - step_quantity < 0 || Y + step_quantity >= MAP_SIZE ){
                    cout << "Nie mozna ruszyc ";
                    Sleep(700);
                    return 0;
            }
            for (int i = 1; i < step_quantity; i++){
                if (!(board[X-i][Y+i] == '&' || board[X-i][Y+i] == '_')){
                    cout << "Nie mozna ruszyc ";
                    Sleep(700);
                    return 0;
                }
            }
            board[X-step_quantity][Y+step_quantity] = kolor_gonca;
            board[X][Y] = CheckColor(board, X, Y);
        }

        // w prawo w dol
        if (side == 'p' && updown == 'd') {
            if (X + step_quantity >= MAP_SIZE || Y + step_quantity >= MAP_SIZE ){
                    cout << "Nie mozna ruszyc ";
                    Sleep(700);
                    return 0;
            }
            for (int i = 1; i < step_quantity; i++){
                if (!(board[X+i][Y+i] == '&' || board[X+i][Y+i] == '_')){
                    cout << "Nie mozna ruszyc ";
                    Sleep(700);
                    return 0;
                }
            }
            board[X+step_quantity][Y+step_quantity] = kolor_gonca;
            board[X][Y] = CheckColor(board, X, Y);
        }

    }
	else {
		cout << "Wybrales puste pole";
		Sleep(700);
	}
    return 1;
}

int HitFigure(char **board, int X, int Y, int white, int black, char side, char updown, int step_quantity) {
	char kolor_gonca = board[X][Y];
	char kolor_przecivnika;

    if (kolor_gonca == black || kolor_gonca == white){

        // w lewo do gory
        if (side == 'l' && updown == 'g') {
            if (X - step_quantity < 0 || Y - step_quantity < 0 ){
                    cout << "Nie trafil";
                    Sleep(700);
                    return 0;
            }
            for (int i = 1; i < step_quantity; i++){
                if (!(board[X-i][Y-i] == '&' || board[X-i][Y-i] == '_')){
                    cout << "Nie trafil";
                    Sleep(700);
                    return 0;
                }
            }
            if (kolor_gonca == black && board[X-step_quantity][Y-step_quantity] == white || kolor_gonca == white && board[X-step_quantity][Y-step_quantity] == black){
                board[X-step_quantity][Y-step_quantity] = kolor_gonca;
                board[X][Y] = CheckColor(board, X, Y);
            }
            else {
                cout << "Nie trafil";
                Sleep(700);
                return 0;
            }
        }

        // w lewo w dol
        if (side == 'l' && updown == 'd') {
            if (X + step_quantity >= MAP_SIZE || Y - step_quantity < 0 ){
                    cout << "Nie trafil";
                    Sleep(700);
                    return 0;
            }
            for (int i = 1; i < step_quantity; i++){
                if (!(board[X+i][Y-i] == '&' || board[X+i][Y-i] == '_')){
                    cout << "Nie trafil";
                    Sleep(700);
                    return 0;
                }
            }
            if (kolor_gonca == black && board[X+step_quantity][Y-step_quantity] == white || kolor_gonca == white && board[X+step_quantity][Y-step_quantity] == black){
                board[X+step_quantity][Y-step_quantity] = kolor_gonca;
                board[X][Y] = CheckColor(board, X, Y);
            }
            else {
                cout << "Nie trafil";
                Sleep(700);
                return 0;
            }
       }

        // w prawo do gory
        if (side == 'p' && updown == 'g') {
            if (X - step_quantity < 0 || Y + step_quantity >= MAP_SIZE ){
                    cout << "Nie trafil";
                    Sleep(700);
                    return 0;
            }
            for (int i = 1; i < step_quantity; i++){
                if (!(board[X-i][Y+i] == '&' || board[X-i][Y+i] == '_')){
                    cout << "Nie trafil";
                    Sleep(700);
                    return 0;
                }
            }
            if (kolor_gonca == black && board[X-step_quantity][Y+step_quantity] == white || kolor_gonca == white && board[X-step_quantity][Y+step_quantity] == black){
                board[X-step_quantity][Y+step_quantity] = kolor_gonca;
                board[X][Y] = CheckColor(board, X, Y);
            }
            else {
                cout << "Nie trafil";
                Sleep(700);
                return 0;
            }
        }

        // w prawo w dol
        if (side == 'p' && updown == 'd') {
            if (X + step_quantity >= MAP_SIZE || Y + step_quantity >= MAP_SIZE ){
                    cout << "Nie trafil";
                    Sleep(700);
                    return 0;
            }
            for (int i = 1; i < step_quantity; i++){
                if (!(board[X+i][Y+i] == '&' || board[X+i][Y+i] == '_')){
                    cout << "Nie trafil";
                    Sleep(700);
                    return 0;
                }
            }
            if (kolor_gonca == black && board[X+step_quantity][Y+step_quantity] == white || kolor_gonca == white && board[X+step_quantity][Y+step_quantity] == black){
                board[X+step_quantity][Y+step_quantity] = kolor_gonca;
                board[X][Y] = CheckColor(board, X, Y);
            }
            else {
                cout << "Nie trafil";
                Sleep(700);
                return 0;
            }
        }

    }
	else {
		cout << "Wybrales puste pole";
		Sleep(700);
	}
    return 1;
}

int main()
{
	srand(time(NULL));
	char **board = new char*[MAP_SIZE];
	int white_quantity = 0;
	int black_quantity = 0;
	char opcja;
	int X_kord = 0;
	int Y_kord = 0;
	int step_quantity = 0;
	char side, updown;
	char white = 'w'; char black = 'b';

	//make dynamic array
	for (int i = 0; i < MAP_SIZE; i++)
	{
		board[i] = new char[MAP_SIZE];
	}

	/////////////////////////////////

	SetBoard(board);
	DrawBoard(board);
	cout << "\nIle bialych goncow chcesz umiescic na planszy: ";
	cin >> white_quantity;
	cout << "\nIle czarnych goncow chcesz umiescic na planszy: ";
	cin >> black_quantity;
	SetWhiteBlackFigures(board, white_quantity, black_quantity, white, black);

	while (true)
	{

		system("cls");
		DrawBoard(board);

		cout << "\nChcesz ruszyc (wpisz r) czy bic (wpisz b): ";
		cin >> opcja;

		switch (opcja)
		{
		case 'r':

			cout << "Ktorym goncem chcesz ruszyc, podaj namiary ";
			cout << "x: ";
			cin >> X_kord;
			cout << "y: ";
			cin	>> Y_kord;
			cout << "strone (l/p):";
			cin >> side;
			cout << "(g/d):";
			cin >> updown;
			cout << "liczbe krokow:";
			cin >> step_quantity;

			StepFigure(board, X_kord, Y_kord, white, black, side, updown, step_quantity);

			break;

		case 'b':

			cout << "Ktorym goncem chcesz bic, podaj namiary ";
			cout << "x: ";
			cin >> X_kord;
			cout << "y: ";
			cin	>> Y_kord;
			cout << "strone (l/p):";
			cin >> side;
			cout << "(g/d):";
			cin >> updown;
			cout << "liczbe krokow:";
			cin >> step_quantity;
			HitFigure(board, X_kord, Y_kord, white, black, side, updown, step_quantity);

			break;

		case 'q':

			return 0;
		default:
			break;
		}

	}

	//delete dynamical array
	////////////////////////////
	for (int i = 0; i < MAP_SIZE; i++)
	{
		delete[] board[i];
	}

	delete[] board;

	return 0;
}
