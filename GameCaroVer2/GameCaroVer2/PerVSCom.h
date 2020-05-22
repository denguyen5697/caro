#pragma once

//Danh gia do nguy hiem cua mot duong.
//Input:	a: Mang luu ban co
//			player: Luot choi duoc so sanh
//			i, j: Chi so tren mang a
//			dx, dy: Huong do tim tren a.
//			count_pos: kiem tra xem co phai chay de quy khong.
//Return:	Diem cho tung duong di. Diem cang cao cang nguy hiem.
int Eval_Path(int a[MAX][MAX], int player, int i, int j, int dx, int dy, int &count_pos);

//Danh gia do nguy hiem cua mot vi tri co.
//Input:	a: Mang luu ban co
//			player: Luot cua nguoi choi.
//			i, j: Chi so tren mang a.
//Return:	Diem cho vi tri. Diem cang cao cang nguy hiem.
int Eval_Pos(int a[MAX][MAX], int player, int i, int j);

//Tim vi tri tot nhat de danh co
//Input:	a: Mang luu ban co.
//Return:	Tra ve vi tri tot nhat de danh co.
position Find_Pos(int a[MAX][MAX]);

//Di nuoc co
//Input:	x,y: Toa do ve ban co.
//			a: Mang luu ban co.
//			player: Luot nguoi choi.
//			next_turn: Luot tiep theo.
//			game_mode: che do choi.
//			tmp: vi tri danh co.
//Return:	Trang thai chuong trinh.
int Set_Turn_PvC(int x, int y, int a[MAX][MAX], int player, int &next_turn, int game_mode, position &tmp);

//Nguoi danh voi may.
//Input:	x,y: Toa do ve ban co.
//			a: Mang luu ban co.
//			next_turn: Luot tiep theo.
//			game_mode: che do choi.
//			tmp: vi tri danh co.
//			first_player: nguoi choi dau.
void Per_Vs_Com(int x, int y, int a[MAX][MAX], int &next_turn, int &stt, int game_mode, position &tmp, int first_player);