#include "stdafx.h"
#include "Process.h"

int Is_Win(int Board[MAX][MAX], int IdRow, int IdCol)
{
	//Khai bao mang luu huong kiem tra.
	int dx[4] = { -1, -1, -1, 0 };
	int dy[4] = { -1, 0, 1, -1 };

	//Khai bao bien co do huong 1, do huong 2.
	int  Flag1, Flag2;

	//Khai bao bien dem so luong tren duong.
	int dem;

	//Cac cau lenh kiem tra dieu kien.
	for (int i = 0; i < 4; i++)
	{
		Flag1 = Flag2 = 1;
		dem = 1;

		//Bien tang chi so do tim
		int p = 1;

		while (Flag1 == 1 || Flag2 == 1)
		{
			//Do theo huong thu nhat.
			if (Flag1 == 1)
			{
				if ((IdRow + p*dx[i] < 0 || IdRow + p*dx[i] >= MAX) || (IdCol + p*dy[i] < 0 || IdCol + p*dy[i] >= MAX))
				{
					Flag1 = 0;
				}
				else
				{
					if (Board[IdRow][IdCol] == Board[IdRow + p*dx[i]][IdCol + p*dy[i]])
					{
						dem++;
					}
					else
					{
						if (Board[IdRow + p*dx[i]][IdCol + p*dy[i]] != 0)
						{
							Flag1 = -1;
						}
						else
						{
							Flag1 = 0;
						}
					}
				}
			}

			//Do theo huong thu 2
			if (Flag2 == 1)
			{
				if ((IdRow - p*dx[i] < 0 || IdRow - p*dx[i] >= MAX) || (IdCol - p*dy[i] < 0 || IdCol - p*dy[i] >= MAX))
				{
					Flag2 = 0;
				}
				else
				{
					if (Board[IdRow][IdCol] == Board[IdRow - p*dx[i]][IdCol - p*dy[i]])
					{
						dem++;
					}
					else
					{
						if (Board[IdRow - p*dx[i]][IdCol - p*dy[i]] != 0)
						{
							Flag2 = -1;
						}
						else
						{
							Flag2 = 0;
						}
					}
				}
			}
			p++;
		}

		//Dieu kien thang.
		if (dem == 5 && (Flag1 != -1 || Flag2 != -1))
		{
			return 1;
		}
	}
	return 0;
}
//---------------------------------------------------------------------------------

int Is_Full_Board(int Board[MAX][MAX])
{
	//Duyet het ban co de tim vi tri trong.
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			if (Board[i][j] == 0)
			{
				return 0;
			}
		}
	}
	return 1;
}
//---------------------------------------------------------------------------------

position Choose_Position(int a[MAX][MAX], int x, int y, int player, int game_mode, position tmp)
{
	do
	{
		Draw_Move_Stt(x + 13, y, player, game_mode);

		//Chon vi tri.
		if (1 == player)
			tmp = Navigation(x, y, tmp, 97, 100, 119, 115, 32);
		else
			tmp = Navigation(x, y, tmp, 75, 77, 72, 80, 13);

		//Truong hop thoat ban co.
		if (tmp.x == -1)
			return tmp;

		//Truong hop chon hop le.
		if (a[tmp.x - 1][tmp.y - 1] == 0)
			break;
	} while (1);

	//Thiet lap gia tri tra ve.
	a[tmp.x - 1][tmp.y - 1] = player;
	return tmp;
}
//---------------------------------------------------------------------------------

int Set_Turn(int x, int y, int a[MAX][MAX], int player, int &next_turn, int game_mode, position &tmp)
{
	tmp = Choose_Position(a, x, y, player, game_mode, tmp);

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

void Reset_Board(int a[MAX][MAX])
{
	//Dat lai gia tri mac dinh.
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			a[i][j] = 0;
		}
	}
}
//---------------------------------------------------------------------------------

position Navigation(int x, int y, position old_pos, int left, int right, int up, int down, int set)
{
	char c;
	gotoxy(x + 2 + (old_pos.y - 1) * 4, y + old_pos.x * 2 - 1);

	//Kiem tra phim nhap.
	do 
	{
		c = _getch();
		if (left == c)
		{
			if (old_pos.y > 1)
				old_pos.y -= 1;
		}
		if (right == c)
		{
			if (old_pos.y < MAX)
				old_pos.y += 1;
		}
		if (up == c)
		{
			if (old_pos.x > 1)
				old_pos.x -= 1;
		}
		if (down == c)
		{
			if (old_pos.x < MAX)
				old_pos.x += 1;
		}
		gotoxy(x + 2 + (old_pos.y - 1) * 4, y + old_pos.x * 2 - 1);
	} while (c != set && c != 27);

	//Truong hop thoat ban.
	if (27 == c)
	{
		old_pos.x = old_pos.y = -1;
	}

	//Tra ve vi tri danh.
	return old_pos;
}
//---------------------------------------------------------------------------------

void Get_Max_Id(int a[][MAX], int row, int col, int &row_max, int &col_max)
{
	row_max = col_max = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (a[i][j] > a[row_max][col_max])
			{
				row_max = i;
				col_max = j;
			}
		}
	}
}