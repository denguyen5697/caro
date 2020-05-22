#pragma once

#define MAX 15			//Kich thuoc cua ban co.
#define POS_X 7			//Toa do x tren man hinh.
#define POS_Y 13		//Toa do y tren man hinh.

//Cau truc luu vi tri dat quan co
struct position
{
	int x, y;
};

//Cai dat kich thuoc man hinh
void Set_Window(int Width, int Height);

//Dat mau chu.
void Set_Color(WORD color);

//Chuyen con tro de vi tri x, y.
void gotoxy(int x, int y);

//Ve ban co kich thuoc tuy y
//Input:	x,y: Toa do ve.
//			n: Kich thuoc
void Draw_Game_Board(int x, int y, int n);

//In quan co ra man hinh
//Input:	x,y: Toa do ve.
//			player: Nguoi choi.
//			pos: Vi tri tren ban co.
void Set_Chess(int x, int y, int player, position pos);

//In ra ban co hien tai.
//Input:	x,y: Toa do ve.
//			a: Ban co hien tai.
void Draw_Current_Board(int x, int y, int a[MAX][MAX]);

//Ve bieu tuong game caro.
//Input:	x,y: toa do ve.
void Draw_Intro_Img(int x, int y);

//Ve khung the hien luot di.
//Input:	x,y: toa do ve.
//			player: luot cua nguoi choi.
//			game_mode: che do choi.
void Draw_Move_Stt(int x, int y, int player, int game_mode);

//Ve tinh trang thang.
//Input:	x,y: toa do ve.
//			player: nguoi choi thang.
//			game_mode: che do choi.
void Draw_Win_Stt(int x, int y, int player, int game_mode);

//Ve khung hinh chu nhat.
//Input:	x,y: toa do ve.
//			width, height: kich thuoc hinh chu nhat.
void Draw_Rectangle(int x, int y, int width, int height);