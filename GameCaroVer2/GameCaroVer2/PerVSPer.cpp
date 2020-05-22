#include "stdafx.h"
#include "PerVSPer.h"

void Per_Vs_Per(int x, int y, int a[MAX][MAX], int &next_turn, int &stt, int game_mode, position &tmp)
{
	//Ve ban co
	Draw_Current_Board(x, y, a);

	//Danh co.
	do
	{
		stt = Set_Turn(POS_X, POS_Y, a, next_turn, next_turn, game_mode, tmp);
	} while (stt == 0);

	//Truong hop thang.
	if (stt == 1)
	{
		_getch();
	}

	//Truong hop het ban co.
	if (stt == -2)
	{
		system("cls");
		gotoxy(POS_X, POS_Y);
		printf("Ban co da het cho. Nhan phim bat ky de thoat.");
		_getch();
	}
}