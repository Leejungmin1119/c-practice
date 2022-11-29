#include <stdio.h>
#pragma warning (disable : 4996)
#include <math.h>
#include <string.h>
#include <windows.h>
#include <winCon.h>
#include <conio.h>
#include <time.h>

#include "extern_메인함수.cpp"

extern int omog_position_x;
extern int omog_position_y;
void print_black_omog();
void print_white_omog();

int omog_check_up()//오목 
{
	int index_x = ((omog_position_x - 80) / 2) - 1;

	if (turn_check == false && omog_arr_xy[index_x][omog_position_y - 15] == 0)//player 1 
	{
		omog_arr_xy[index_x][omog_position_y - 15] = 1;

		if (what_black == false)
		{
			print_black_omog();
		}
		else
		{
			print_white_omog();
		}

		return 1;
	}

	else if (turn_check == true && omog_arr_xy[index_x][omog_position_y - 15] == 0)//player 2
	{
		omog_arr_xy[index_x][omog_position_y - 15] = 2;
		if (what_black == true)
		{
			print_black_omog();
		}
		else
		{
			print_white_omog();
		}

		return 1;
	}

	return 0;
}
