#include "stdafx.h"
#include "SaveAndLoad.h"
#include <time.h>

void Get_Current_Time(char time_str[])
{
	time_t current_time = time(NULL);
	tm time_ptr;

	//Lay tung gia tri thoi gian.
	localtime_s(&time_ptr, &current_time);

	//Dinh dang chuoi chua gia tri thoi gian.
	strftime(time_str, 80, "%H_%M_%d_%m_%Y.CR", &time_ptr);
}
//---------------------------------------------------------------------------------

int Load_Game(int a[MAX][MAX], int n, int &next_turn, int &game_mode, int x, int y)
{
	system("cls");
	FILE* fsavename;	//Chi file chua ten cac van co duoc luu.
	FILE* fsave;		//Chi file chua tinh trang van co.
	char filename[21];	//Chuoi luu ten file.
	int i = 1;			//Dieu khien vi tri xuat man hinh.

	errno_t error = fopen_s(&fsavename, "SavedGame.txt", "r");
	if (0 == error)
	{
		//Neu mo file luu cac ten saved game thanh cong.
		gotoxy(x, y);
		printf("-------- Cac Van Co Da Luu ----------");

		//In danh sach cac van co
		while (1)
		{
			if (fgets(filename, 21, fsavename) != NULL)
			{
				i++;
				gotoxy(x, y + i);
				puts(filename);
			}
			else
				break;
		}
		fclose(fsavename);

		//Chon file de mo.
		gotoxy(x, y + i + 2);
		printf("Nhap ten file ban muon mo: ");
		fgets(filename, 21, stdin);
		fflush(stdin);
		filename[19] = 0;

		error = fopen_s(&fsave, filename, "r");
		if (0 == error)
		{
			//Neu mo file luu game dang choi thanh cong.

			//Doc gia tri.
			fscanf_s(fsave, "%d\n", &game_mode);
			fscanf_s(fsave, "%d\n", &next_turn);
			for (int k = 0; k < n; k++)
			{
				for (int j = 0; j < n; j++)
				{
					fscanf_s(fsave, "%d ", &a[k][j]);
				}
				fscanf_s(fsave, "\n");
			}

			//In thong bao.
			gotoxy(x, y + i + 4);
			printf("Mo file thanh cong. Nhan phim bat ky de choi.");
			_getch();
			fclose(fsave);
			return 1;
		}
		else
		{
			//Neu mo file luu game dang choi khong thanh cong.
			gotoxy(x, y + 4 + i);
			printf("Khong the mo file. Xin kiem tra lai ten.");
			_getch();
			return 0;
		}
	}
	else
	{
		//Neu mo file luu cac ten saved game khong thanh cong.
		gotoxy(x, y + 4 + i);
		printf("Khong the tai lai game. Nhan phim bat ky de quay lai.");
		_getch();
		return 0;
	}
}
//---------------------------------------------------------------------------------

int Save_Game(int a[MAX][MAX], int n, int next_turn, int game_mode)
{
	FILE* fsave;
	FILE* fsavename;
	char filename[21];

	//Dat ten file luu.
	Get_Current_Time(filename);

	errno_t error = fopen_s(&fsave, filename, "w");
	if (0 == error)
	{
		//Ghi du lieu.
		fprintf(fsave, "%d\n", game_mode);
		fprintf(fsave, "%d\n", next_turn);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				fprintf(fsave, "%d ", a[i][j]);
			}
			fprintf(fsave, "\n");
		}
		fclose(fsave);

		//Ghi danh sach ten file luu.
		error = fopen_s(&fsavename, "SavedGame.txt", "a");
		if (0 == error)
		{
			fputs(filename, fsavename);
			fprintf(fsavename, "\n");
			fclose(fsavename);
		}
		return 1;
	}
	else
		return 0;
}
//---------------------------------------------------------------------------------