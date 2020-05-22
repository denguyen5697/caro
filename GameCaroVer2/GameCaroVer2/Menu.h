#pragma once

//In main menu tren toa do x, y
void Print_Main_Menu(int x, int y);

//Chon cac chuc nang trong menu
//Input:	x, y: Toa do in menu. 
//			n: So luong chuc nang trong menu.
//Return:	So chi menu tuong ung.
int Choose_Main_Menu(int x, int y, int n);

//In options menu tai toa do x, y
//Input:	x,y: toa do.
//			game_mode: che do choi.
//			first_player: nguoi di truoc.
void Print_Options(int x, int y, int game_mode, int first_player);

//In menu tro giup
//Input:	x,y: toa do.
void Print_Help(int x, int y);

//In menu gioi thieu
//Input: x,y: toa do.
void Print_About(int x, int y);

//Chon cac chuc nang trong menu tuy chinh
//Input:	x, y: Toa do in menu. 
//			game_mode: che do choi.
//			first_player: nguoi choi di truoc.
void Choose_Options(int x, int y, int &game_mode, int &first_player);