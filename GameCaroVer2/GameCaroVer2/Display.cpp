#include "stdafx.h"
#include "Display.h"

void Set_Window(int Width, int Height)
{
	_COORD coord;
	coord.X = Width;
	coord.Y = Height;

	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Bottom = Height - 1;
	Rect.Right = Width - 1;

	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);      // Get Handle 
	SetConsoleScreenBufferSize(Handle, coord);            // Set Buffer Size 
	SetConsoleWindowInfo(Handle, TRUE, &Rect);            // Set Window Size 
}
//---------------------------------------------------------------------------------

void Set_Color(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsoleOutput, color);
}
//---------------------------------------------------------------------------------

void gotoxy(int x, int y)
{
	COORD cor;
	cor.X = x;
	cor.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cor);
}
//---------------------------------------------------------------------------------

void Draw_Game_Board(int x, int y, int n)
{
	//Ve bien tren
	gotoxy(x, y);
	printf("%c%c", 201, 205);
	for (int i = 1; i <= n - 1; i++)
	{
		printf("%c%c%c%c", 205, 205, 209, 205);
	}
	printf("%c%c%c\n", 205, 205, 187);

	//Ve cac o trong ban co
	for (int j = 1; j <= n - 1; j++)
	{
		gotoxy(x, y + j * 2 - 1);
		printf("%c   ", 186);
		for (int i = 1; i <= n - 1; i++)
			printf("%c   ", 179);
		printf("%c   ", 186);
		printf("%d", j);
		printf("\n");

		gotoxy(x, y + j * 2);
		printf("%c%c", 199, 196);

		for (int i = 1; i <= n - 1; i++)
		{
			printf("%c%c%c%c", 196, 196, 197, 196);
		}
		printf("%c%c%c\n", 196, 196, 182);
	}

	gotoxy(x, y + n * 2 - 1);
	printf("%c   ", 186);
	for (int i = 1; i <= n - 1; i++)
		printf("%c   ", 179);
	printf("%c   ", 186);
	printf("%d", n);
	printf("\n");

	//Ve bien duoi
	gotoxy(x, y + n * 2);
	printf("%c%c", 200, 205);
	for (int i = 1; i <= n - 1; i++)
	{
		printf("%c%c%c%c", 205, 205, 207, 205);
	}
	printf("%c%c%c\n", 205, 205, 188);

	gotoxy(x, y + n * 2 + 1);
	for (int i = 1; i <= n; i++)
	{
		printf("%3d ", i);
	}
	printf("\n");
}
//---------------------------------------------------------------------------------

void Set_Chess(int x, int y, int player, position pos)
{
	//Ve cac quan co tuong ung voi nguoi choi 1 hay 2.
	if (1 == player)
	{
		Set_Color(12);
		gotoxy(x + 2 + (pos.y - 1) * 4, y + pos.x * 2 - 1);
		printf("X");
	}

	if (2 == player)
	{
		Set_Color(14);
		gotoxy(x + 2 + (pos.y - 1) * 4, y + pos.x * 2 - 1);
		printf("O");
	}

	//Cai dat lai mau chu ban dau
	Set_Color(15);
}
//---------------------------------------------------------------------------------

void Draw_Current_Board(int x, int y, int a[MAX][MAX])
{
	position tmp;

	Draw_Intro_Img(x + 8, y - POS_Y + 1);

	//Ve khung ban co.
	Draw_Game_Board(x, y, MAX);

	//Ve cac quan co.
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			if (a[i][j] != 0)
			{
				tmp.x = i + 1;
				tmp.y = j + 1;
				Set_Chess(x, y, a[i][j], tmp);
			}
		}
	}
}
//---------------------------------------------------------------------------------

void Draw_Intro_Img(int x, int y)
{
	Set_Color(14);
	gotoxy(x, y);
	printf("     ::::::::      :::     :::::::::   :::::::: ");
	gotoxy(x, y + 1);
	printf("    :+:    :+:   :+: :+:   :+:    :+: :+:    :+: ");
	gotoxy(x, y + 2);
	printf("   +:+         +:+   +:+  +:+    +:+ +:+    +:+  ");
	gotoxy(x, y + 3);
	printf("  +#+        +#++:++#++: +#++:++#:  +#+    +:+   ");
	gotoxy(x, y + 4);
	printf(" +#+        +#+     +#+ +#+    +#+ +#+    +#+    ");
	gotoxy(x, y + 5);
	printf("#+#    #+# #+#     #+# #+#    #+# #+#    #+#     ");
	gotoxy(x, y + 6);
	printf("########  ###     ### ###    ###  ########       ");
	Set_Color(15);
}
//---------------------------------------------------------------------------------

void Draw_Move_Stt(int x, int y, int player, int game_mode)
{
	//Neu che do choi hai nguoi.
	if (game_mode == 2)
	{
		if (player == 1)
			Set_Color(12);
		else
			Set_Color(14);

		gotoxy(x, y - 4);
		printf("%c", 201);
		for (int i = 1; i <= 31; i++)
			printf("%c", 205);
		printf("%c", 187);

		gotoxy(x, y - 3);
		printf("%c", 186);
		gotoxy(x + 5, y - 3);
		printf("Luot cua nguoi choi %d", player);
		gotoxy(x + 32, y - 3);
		printf("%c", 186);

		gotoxy(x, y - 2);
		printf("%c", 200);
		for (int i = 1; i <= 31; i++)
			printf("%c", 205);
		printf("%c", 188);
	}
	//Che do danh voi may
	else
	{
		if (player == 2)
		{
			Set_Color(14);

			gotoxy(x, y - 4);
			printf("%c", 201);
			for (int i = 1; i <= 31; i++)
				printf("%c", 205);
			printf("%c", 187);

			gotoxy(x, y - 3);
			printf("%c", 186);
			gotoxy(x + 10, y - 3);
			printf("Luot cua ban", player);
			gotoxy(x + 32, y - 3);
			printf("%c", 186);

			gotoxy(x, y - 2);
			printf("%c", 200);
			for (int i = 1; i <= 31; i++)
				printf("%c", 205);
			printf("%c", 188);
		}
	}
}
//---------------------------------------------------------------------------------

void Draw_Win_Stt(int x, int y, int player, int game_mode)
{
	Set_Color(10);

	gotoxy(x, y - 4);
	printf("%c", 201);
	for (int i = 1; i <= 31; i++)
		printf("%c", 205);
	printf("%c", 187);

	gotoxy(x, y - 3);
	printf("%c", 186);
	gotoxy(x + 3, y - 3);
	if (game_mode == 1)
	{
		if (player == 1)
			printf("       Ban da thua.");
		else
			printf("       Ban da thang.");
	}
	else
	{
		printf("  Nguoi choi %d da thang.", player);
	}
	gotoxy(x + 32, y - 3);
	printf("%c", 186);

	gotoxy(x, y - 2);
	printf("%c", 200);
	for (int i = 1; i <= 31; i++)
		printf("%c", 205);
	printf("%c", 188);
}
//---------------------------------------------------------------------------------

void Draw_Rectangle(int x, int y, int width, int height)
{
	int i;

	Set_Color(13);
	gotoxy(x, y);
	printf("%c", 201);
	for (i = 0; i < width; i++)
		printf("%c", 205);
	printf("%c", 187);

	for (i = 1; i < height; i++)
	{
		gotoxy(x, y + i);
		printf("%c", 186);
		gotoxy(x + width + 1, y + i);
		printf("%c", 186);
	}

	gotoxy(x, y + height);
	printf("%c", 200);
	for (i = 0; i < width; i++)
		printf("%c", 205);
	printf("%c", 188);

	Set_Color(15);
}
//---------------------------------------------------------------------------------