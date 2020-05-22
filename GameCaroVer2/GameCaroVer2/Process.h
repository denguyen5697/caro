#pragma once

//Ham kiem tra ket qua.
//Flag:		-1_bi chan, 0_het duong, 1_do tiep
//Return:	1_Thang, 0_Chua thang
int Is_Win(int Board[MAX][MAX], int IdRow, int IdCol);

//Kiem tra het o danh
//Return:	1_Het cho, 0_Con trong
int Is_Full_Board(int Board[MAX][MAX]);

//Chon vi tri danh co
//Input:	a: Ban co
//			x,y: Vi tri tren man hinh
//			player: Nguoi choi
//			game_mode: che do choi.
//			tmp: Vi tri nuoc di truoc
position Choose_Position(int a[MAX][MAX], int x, int y, int player, int game_mode, position tmp);

//Luot choi cua nguoi choi player
//Input:	x,y: toa do.
//			a: mang luu ban co.
//			player: luot cua nguoi choi.
//			next_turn: luot tiep theo.
//			game_mode: che do choi.
//			tmp: ve tri danh co.
//Return:	1 thang, 0 chua thang
int Set_Turn(int x, int y, int a[MAX][MAX], int player, int &next_turn, int game_mode, position &tmp);

//Khoi tao lai ban co.
void Reset_Board(int a[MAX][MAX]);

//Dieu huong co tro tren ban co
//Input:	x,y toa do ve.
//			old_pos: toa do luot di truoc.
//			left, right, up, down: ma phim dieu huong.
//			set: ma phim dat quan.
//Return:	Vi tri dat quan moi.
position Navigation(int x, int y, position old_pos, int left, int right, int up, int down, int set);

//Tim vi tri gia tri lon nhat
//Input:	a: Mang gia tri.
//			row, col: so dong va so cot.
//			row_max, col_max: chi so phan tu lon nhat.
void Get_Max_Id(int a[][MAX], int row, int col, int &row_max, int &col_max);