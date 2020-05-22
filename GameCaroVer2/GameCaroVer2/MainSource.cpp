//Main Source 

#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	//---------------------------------------------------
	int main_choice = 1;
	int option_choice = 1;
	int mode_choice = 1;	//Trang thai che do choi. Mac dinh 1 la nguoi voi may, 2 la nguoi voi nguoi.
	int firstplayer_choice = 1;	//Trang thai nguoi choi mot co quyen di truoc. 1 la co, 2 la khong
	int a[MAX][MAX] = { 0 };
	int next_turn = firstplayer_choice;
	//Trang thai co nguoi thang hay khong.
	//Gia tri: 1-co, 0-khong, -1-thoat, -2-het cho, khong tao moi.
	int stt;
	position pos;
	//---------------------------------------------------
	//Cai dat kich thuoc man hinh va mau chu
	Set_Window(80, 50);
	Set_Color(15);
	//---------------------------------------------------
	do
	{
		main_choice = Choose_Main_Menu(POS_X, POS_Y, 7);
		switch (main_choice)
		{
		case 1:		//New game
			system("cls");

			//Dat lai ban co trong.
			Reset_Board(a);

			//Khoi tao vi tri tro dau tien
			pos.x = pos.y = 1;
			next_turn = firstplayer_choice;

			if (mode_choice == 1)
			{
				if (firstplayer_choice == 1)
				{
					int mid = MAX / 2;
					a[mid][mid] = 1;
					next_turn = 2;
				}
				Per_Vs_Com(POS_X, POS_Y, a, next_turn, stt, mode_choice, pos, firstplayer_choice);
			}
			else
			{
				Per_Vs_Per(POS_X, POS_Y, a, next_turn, stt, mode_choice, pos);
			}
			break;
		case 2:		//Load game
			if (Load_Game(a, 15, next_turn, mode_choice, POS_X, POS_Y))
			{
				system("cls");

				//In thong tin hien tai.
				if (1 == mode_choice)
				{
					gotoxy(POS_X, POS_Y);
					printf("Che do choi hien tai la nguoi vs may.");
				}
				else
				{
					gotoxy(POS_X, POS_Y);
					printf("Che do choi hien tai la nguoi vs nguoi.");
				}
				gotoxy(POS_X, POS_Y + 2);
				printf("Luot choi tiep theo cua nguoi choi %d.", next_turn);
				_getch();

				//Khoi tao vi tri tro dau tien
				pos.x = pos.y = 1;
				if (mode_choice == 1)
				{
					Per_Vs_Com(POS_X, POS_Y, a, next_turn, stt, mode_choice, pos, firstplayer_choice);
				}
				else
				{
					Per_Vs_Per(POS_X, POS_Y, a, next_turn, stt, mode_choice, pos);
				}
			}
			break;
		case 3:		//Save game
			system("cls");
			gotoxy(POS_X, POS_Y);

			//In thong tin.
			if (Save_Game(a, 15, next_turn, mode_choice))
			{
				printf("Luu game thanh cong. Nhan phim bat ky de quay lai.\n");
				_getch();
			}
			else
			{
				printf("Khong the luu game. Nhan phim bat ky de quay lai.\n");
				_getch();
			}
			break;
		case 4:		//Options
			Choose_Options(POS_X, POS_Y, mode_choice, firstplayer_choice);
			break;
		case 5:		//Help
			Print_Help(POS_X, POS_Y);
			break;
		case 6:		//About
			Print_About(POS_X, POS_Y);
			break;
		case 7:		//Exit
		{
				  if (stt == -2 || stt == 1)
					  break;
				  system("cls");
				  gotoxy(POS_X, POS_Y);
				  printf("Ban co muon luu van co hien tai hay khong? (y hay n): ");
				  fflush(stdin);

				  char check;
				  scanf_s("%c", &check);
				  fflush(stdin);

				  if (check == 'y' || check == 'Y')
				  {
					  gotoxy(POS_X, POS_Y + 2);
					  if (Save_Game(a, 15, next_turn, mode_choice))
					  {
						  printf("Luu game thanh cong.\n");
						  _getch();
					  }
					  else
					  {
						  printf("Khong the luu game.\n");
						  _getch();
					  }
				  }
				  else
				  {
					  gotoxy(POS_X, POS_Y + 2);
					  printf("Game khong luu.");
					  _getch();
				  }
				  break;
		}
		default:
			break;
		}
	} while (7 != main_choice);

	return 0;
}