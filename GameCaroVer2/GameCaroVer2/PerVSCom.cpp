#include "stdafx.h"
#include "PerVSCom.h"

int Eval_Path(int a[MAX][MAX], int player, int i, int j, int dx, int dy, int &count_pos)
{
	int f_stop1 = 0;
	int f_stop2 = 0;
	int f_empty = 0;
	int count = 1;

	//Xet huong nguoc.
	if (i - dx >= 0 && i - dx < MAX && j - dy >= 0 && j - dy < MAX)
	{
		if (a[i - dx][j - dy] != player && a[i - dx][j - dy] != 0)
		{
			f_stop1 = 1;
		}
		if (a[i - dx][j - dy] == player)
		{
			count_pos++;
			return Eval_Path(a, player, i - dx, j - dy, dx, dy, count_pos);
		}
	}
	else
		f_stop1 = -1;

	//Xet huong xuoi
	for (int k = 1; k <= 5; k++)
	{
		if (i + k * dx >= 0 && i + k * dx < MAX && j + k * dy >= 0 && j + k * dy < MAX)
		{
			if (a[i + k * dx][j + k * dy] == player)
			{
				count++;
			}

			if (a[i + k * dx][j + k * dy] == 0 && k <= 4)
				f_empty++;

			if (a[i + k * dx][j + k * dy] != player && a[i + k * dx][j + k * dy] != 0)
			{
				f_stop2 = 1;
				break;
			}
		}
		else
			f_stop2 = -1;
	}

	//Luong gia
	//Truong hop bi chan hai dau.
	if (f_stop1 == 1 && f_stop2 == 1)
		return 0;

	//Truong hop duong 1
	if (count == 1)
		return 10;

	//Truong hop duong 2
	if (count == 2)
	{
		//xoo-
		if (f_stop1 == 1)
			return 0;
		//-oo-
		if (a[i][j] == a[i + dx][j + dy])
			return 40;
	}

	//Truong hop duong 3
	if (count == 3)
	{
		//xooo-
		if (f_stop1 == 1)
			return 0;

		//-ooo-
		if (a[i][j] == a[i + dx][j + dy] && a[i][j] == a[i + 2 * dx][j + 2 * dy])
			return 500;

		//o-oo-- hoac oo-o--
		if (f_empty == 2 && a[i][j] == a[i + 3 * dx][j + 3 * dy] && a[i + 4 * dx][j + 4 * dy] == 0)
			return 200;

		//-oo--o- hoac -o--oo-
		if (f_empty >= 2)
			return 0;
	}

	//Truong hop duong 4
	if (count == 4)
	{
		//xoooo-
		if (f_stop1 == 1)
		{
			//Truong hop o dang xet bi chan dau duong 4
			if (count_pos == 0)
				return 0;
			//Truong hop o dang xet nam giua hoac cuoi duong 4
			else
				return 800;
		}

		//-oooo-
		if (a[i + 4 * dx][j + 4 * dy] == 0 && a[i][j] == a[i + dx][j + dy]
			&& a[i][j] == a[i + 2 * dx][j + 2 * dy] && a[i][j] == a[i + 3 * dx][j + 3 * dy])
			return 1500;

		//-oooox
		if (f_stop2 == 1)
			return 200;

		//-o-ooo- hoac -o--ooo-
		return 100;
	}

	//Truong hop duong 5
	if (count == 5)
	{
		//-ooooo-
		if (f_empty == 0)
			return 2000;

		//Truong hop bi chan dau tren
		if (f_stop1 == 1)
		{
			//Truong hop 5 quan lien nhau
			if (f_empty == 0)
			{
				if (count_pos == 0)
					return 500;
				else
					return 1500;
			}
			//xo-oooo
			else
				return 0;
		}
		//Truong hop bi chan dau duoi
		if (f_stop2 == 1)
			return 800;
	}

	return 0;
}
//---------------------------------------------------------------------------------

int Eval_Pos(int a[MAX][MAX], int player, int i, int j)
{
	//Cac huong di
	int dx[] = { 0, 1, 1, 1 };
	int dy[] = { 1, 1, 0, -1 };

	int result = 0;

	//Tinh diem nuoc di.
	for (int k = 0; k < 4; k++)
	{
		int count_pos = 0;
		result += Eval_Path(a, player, i, j, dx[k], dy[k], count_pos);
	}

	return result;
}
//---------------------------------------------------------------------------------

position Find_Pos(int a[MAX][MAX])
{
	int mark[MAX][MAX] = { 0 };

	//Cho diem cac vi tri con trong tren ban co.
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			if (a[i][j] == 0)
			{
				//Truong hop voi nguoi choi 1
				a[i][j] = 1;
				mark[i][j] = Eval_Pos(a, 1, i, j);
				//Truong hop voi nguoi choi 1
				a[i][j] = 2;
				mark[i][j] += Eval_Pos(a, 2, i, j);
				a[i][j] = 0;
			}
			else
				mark[i][j] = 0;
		}
	}

	int row_max, col_max;

	//Tim vi tri diem cao nhat
	Get_Max_Id(mark, MAX, MAX, row_max, col_max);
	
	position pos;
	pos.x = row_max + 1;
	pos.y = col_max + 1;
	a[row_max][col_max] = 1;
	return pos;
}
//---------------------------------------------------------------------------------

void Per_Vs_Com(int x, int y, int a[MAX][MAX], int &next_turn, int &stt, int game_mode, position &tmp, int first_player)
{
	//The hien ban co hien tai
	Draw_Current_Board(x, y, a);
	int f_first = 0;

	//Danh co.
	do
	{
		stt = Set_Turn_PvC(x, y, a, next_turn, next_turn, game_mode, tmp);
		if (first_player == 2 && f_first == 0)
		{
			f_first++;
			tmp.x = tmp.x + 1;
			tmp.y = tmp.y + 1;
			a[tmp.x - 1][tmp.y - 1] = 1;
			Set_Chess(x, y, 1, tmp);
			next_turn = 2;
		}
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
//---------------------------------------------------------------------------------

int Set_Turn_PvC(int x, int y, int a[MAX][MAX], int player, int &next_turn, int game_mode, position &tmp)
{
	//Chon nuoc co
	if (player == 2)
	{
		tmp = Choose_Position(a, x, y, player, game_mode, tmp);
	}
	else
		tmp = Find_Pos(a);

	//Truong hop thoat ban co.
	if (tmp.x == -1)
		return -1;

	//Dat quan co.
	Set_Chess(x, y, player, tmp);

	//Doi luot choi.
	if (player == 1)
	{
		next_turn = 2;
	}
	else
	{
		next_turn = 1;
	}

	//Kiem tra thang thua.
	int stt = Is_Win(a, tmp.x - 1, tmp.y - 1);
	if (stt)
	{
		Draw_Win_Stt(x + 13, y, player, game_mode);
	}

	//Kiem tra ban co con trong.
	if (Is_Full_Board(a))
	{
		system("cls");
		gotoxy(x, y);
		printf("Ban co muon tao ban co moi. (y hoac n)");
		char check = _getch();
		if (check == 'y' || check == 'Y')
		{
			Reset_Board(a);
			Draw_Current_Board(x, y, a);
			return 0;
		}
		else
			return -2;
	}

	return stt;
}
//---------------------------------------------------------------------------------