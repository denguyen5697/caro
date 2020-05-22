#pragma once

//Lay gia tri thoi gian he thong.
//Input:	time_str: Mang luu dinh dang thoi gian.
void Get_Current_Time(char time_str[]);

//Luu game hien tai.
//Input:	a: Ban co.
//			n: Kich thuoc ban co.
//			next_turn: Luot di tiep theo.
//			game_mode: Che do choi.
//Return:	1_Thanh cong, 0: That bai.
int Save_Game(int a[MAX][MAX], int n, int next_turn, int game_mode);

//Tai mot van da luu.
//Input:	a: Ban co.
//			n: Kich thuoc ban co.
//			next_turn: Luot di tiep theo.
//			game_mode: Che do choi.
//			x,y: Toa do man hinh.
//Return:	1_Thanh cong, 0_That bai.
int Load_Game(int a[MAX][MAX], int n, int &next_turn, int &game_mode, int x, int y);