#include "stdafx.h"
#include "Menu.h"

void Print_Main_Menu(int x, int y)
{
	system("cls");
	Draw_Intro_Img(x, y - POS_Y + 1);
	gotoxy(x, y);
	printf("------------- Menu Chinh -------------");
	gotoxy(x, y + 2);
	printf("1. Game Moi");
	gotoxy(x, y + 4);
	printf("2. Tai Game");
	gotoxy(x, y + 6);
	printf("3. Luu Game");
	gotoxy(x, y + 8);
	printf("4. Tuy Chon");
	gotoxy(x, y + 10);
	printf("5. Tro Giup");
	gotoxy(x, y + 12);
	printf("6. Gioi Thieu");
	gotoxy(x, y + 14);
	printf("7. Thoat");
}
//---------------------------------------------------------------------------------

int Choose_Main_Menu(int x, int y, int n)
{
	//In menu ban dau
	Print_Main_Menu(x, y);
	int func = 1;
	gotoxy(x - 3, y + func * 2);
	printf("->");
	char c;

	//Kiem tra phim va the hien menu
	do
	{
		fflush(stdin);
		c = _getch();
		if (80 == c || 77 == c)
		{
			if (func < n)
			{
				gotoxy(x - 3, y + func * 2);
				printf("  ");
				func++;
				gotoxy(x - 3, y + func * 2);
				printf("->");
			}
		}
		if (72 == c || 75 == c)
		{
			if (func > 1)
			{
				gotoxy(x - 3, y + func * 2);
				printf("  ");
				func--;
				gotoxy(x - 3, y + func * 2);
				printf("->");
			}
		}
	} while (13 != c);

	//Tra ve gia tri menu
	return func;
}
//---------------------------------------------------------------------------------

void Print_Options(int x, int y, int game_mode, int first_player)
{
	Draw_Intro_Img(x, y - POS_Y + 1);
	Draw_Rectangle(x - 5, y - 2, 55, 12);
	gotoxy(x, y);
	printf("------------- Tuy Chon -------------");
	gotoxy(x, y + 2);
	printf("1. Che Do Choi");
	gotoxy(x, y + 4);
	printf("2. Nguoi Di Truoc");
	gotoxy(x, y + 6);
	printf("Nhan phim ESC de quay lai.");

	if (game_mode == 1)
	{
		Set_Color(11);
		gotoxy(x + 20, y + 2);
		printf("<< Mot nguoi choi >>");
		if (first_player == 1)
		{
			Set_Color(12);
			gotoxy(x + 20, y + 4);
			printf("<< May di truoc >>  ");
		}
		else
		{
			Set_Color(14);
			gotoxy(x + 20, y + 4);
			printf("<< Ban di truoc >>");
		}
	}
	else
	{
		Set_Color(9);
		gotoxy(x + 20, y + 2);
		printf("<< Hai nguoi choi >>");
		if (first_player == 1)
			Set_Color(12);
		else
			Set_Color(14);
		gotoxy(x + 20, y + 4);
		printf("<< Nguoi choi %d di truoc >>", first_player);
	}

	Set_Color(15);
}
//---------------------------------------------------------------------------------

void Print_Help(int x, int y)
{
	system("cls");
	Draw_Intro_Img(x, y - POS_Y + 1);
	Draw_Rectangle(x - 5, y - 2, 73, 28);
	gotoxy(x, y);
	printf("------------- Tro Giup -------------");
	gotoxy(x, y + 2);
	printf("\t * Luat choi:");
	gotoxy(x, y + 4);
	printf("Hai ben lien tuc thay nhau di nhung quan co X, O.");
	gotoxy(x, y + 5);
	printf("Nguoi chien thang la nguoi tao ra 5 quan co lien tuc");
	gotoxy(x, y + 6);
	printf("theo chieu doc, chieu ngang hoac cheo, ");
	gotoxy(x, y + 7);
	printf("voi dieu kien 5 quan co do khong bi chan 2 dau.");
	gotoxy(x, y + 10);
	printf("\t * Cach choi:");
	gotoxy(x, y + 12);
	printf("+ Truong hop hai nguoi choi:");
	gotoxy(x, y + 13);
	printf("Nguoi choi 1 dung phim A, W, D, S de chon vi tri o co can danh,");
	gotoxy(x, y + 14);
	printf("dung phim Space de danh co.");
	gotoxy(x, y + 15);
	printf("Nguoi choi 2 dung phim mui ten de chon vi tri o co can danh,");
	gotoxy(x, y + 16);
	printf("dung phim Enter de danh co.");
	gotoxy(x, y + 18);
	printf("+ Truong hop mot nguoi choi:");
	gotoxy(x, y + 19);
	printf("Nguoi choi dung phim mui ten de chon vi tri o co can danh,");
	gotoxy(x, y + 20);
	printf("dung phim Enter de danh co.");
	gotoxy(x, y + 22);
	printf("Nhan phim Esc de thoat ban co.");
	gotoxy(x, y + 24);
	printf("Nhan phim bat ky de quay lai.");
	_getch();
}
//---------------------------------------------------------------------------------

void Print_About(int x, int y)
{
	system("cls");
	Draw_Intro_Img(x, y - POS_Y + 1);
	Draw_Rectangle(x - 5, y - 2, 73, 22);
	gotoxy(x, y);
	printf("------------- Gioi Thieu -------------");
	gotoxy(x, y + 2);
	printf("\tNhom Phat Trien:\n");

	gotoxy(x, y + 4);
	printf("*** Ho Xuan Dung ***");
	gotoxy(x, y + 5);
	printf("\tMSSV: 1512077");
	gotoxy(x, y + 6);
	printf("\tEmail: 1512077@student.hcmus.edu.vn");
	gotoxy(x, y + 7);
	printf("\tSdt: 01285632983");

	gotoxy(x, y + 9);
	printf("*** Nguyen Tan De ***");
	gotoxy(x, y + 10);
	printf("\tMSSV: 1512109");
	gotoxy(x, y + 11);
	printf("\tEmail: 1512109@student.hcmus.edu.vn");
	gotoxy(x, y + 12);
	printf("\tSdt: 0964627370");

	gotoxy(x, y + 15);
	printf("Phien Ban Hien Tai: 2.0");
	gotoxy(x, y + 17);
	printf("Nhan phim bat ky de quay lai.");
	_getch();
}
//---------------------------------------------------------------------------------

void Choose_Options(int x, int y, int &game_mode, int &first_player)
{
	char c;
	int func = 1;

	system("cls");
	Print_Options(x, y, game_mode, first_player);
	gotoxy(x - 3, y + func * 2);
	printf("->");

	do
	{
		fflush(stdin);
		c = _getch();
		if (80 == c)
		{
			if (func == 1)
			{
				func++;
			}
		}
		if (72 == c)
		{
			if (func == 2)
			{
				func--;
			}
		}
		if (75 == c || 77 == c)
		{
			if (1 == func)
			{
				if (1 == game_mode)
					game_mode = 2;
				else
					game_mode = 1;
			}
			if (2 == func)
			{
				if (first_player == 1)
					first_player = 2;
				else
					first_player = 1;
			}
		}
		
		if (c > 0 && c != 27)
		{
			system("cls");
			Print_Options(x, y, game_mode, first_player);
			gotoxy(x - 3, y + func * 2);
			printf("->");
		}
	} while (27 != c);
}
//---------------------------------------------------------------------------------
