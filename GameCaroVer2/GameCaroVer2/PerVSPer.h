#pragma once

//Che do danh nguoi voi nguoi
//Input:	x,y: Toa do ve.
//			a: Mang luu ban co hien tai.
//			next_turn: Luot di tiep theo.
//			stt: Co nguoi thang hay khong.
//			game_mode: che do choi.
//			tmp: Vi tri con tro chuot.
void Per_Vs_Per(int x, int y, int a[MAX][MAX], int &next_turn, int &stt, int game_mode, position &tmp);