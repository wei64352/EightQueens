#include"EightQueenPuzzle.h"
#include<iostream>
#include<cstdlib>
#include<time.h>

using namespace std;

EightQueen::EightQueen(int length)
{
	this->CB_row = this->CB_col = length;

	this->ChessBoard = new int*[this->CB_row];
	for (int i = 0; i < this->CB_row; i++)
	{
		this->ChessBoard[i] = new int[this->CB_col];
	}
}

EightQueen::~EightQueen()
{
	for (int i = 0; i < this->CB_row; i++)
	{
		delete[] this->ChessBoard[i];
	}
	delete[] this->ChessBoard;
}

int EightQueen::CreateThePuzzle()
{
	int num, NullCount, RandNum, landmark_row, landmark_col, ptr_row, ptr_col, bol = 1;
	
	srand(time(NULL));

	for (int i = 0; i < this->CB_row; i++)
	{
		NullCount = 0;
		for (int j = 0; j < this->CB_col; j++) // �p��C�C�ٳѤU�h�֪Ů�i�H��
		{
			if (this->ChessBoard[i][j] < 0)

				NullCount++;

		}
		if (NullCount == 0) // ���p�S���Ů�,�N���s�ӹL
		{
			DeletePuzzle();
			bol = 0;
			break;
		}
		else
		{
			RandNum = (rand() % NullCount) + 1;
			for (int j = 0; j < this->CB_col; j++)
			{
				if (this->ChessBoard[i][j] < 0)
				{
					if (RandNum == 1)
					{
						this->ChessBoard[i][j] = 1;
						landmark_row = i, landmark_col = j;
						break;
					}
					else

						RandNum--;

				}
			}
			// �N���i�H���\�񪺮�l���е�
			ptr_row = landmark_row + 1, ptr_col = landmark_col;
			while (ptr_row < this->CB_row) // �V�U�ʸ�
			{
				this->ChessBoard[ptr_row][ptr_col] = 0;
				ptr_row++;
			}
			ptr_row = landmark_row + 1, ptr_col = landmark_col - 1;
			while (ptr_row < this->CB_row && ptr_col > 0) // �V���U�ʸ�
			{
				this->ChessBoard[ptr_row][ptr_col] = 0;
				ptr_row++, ptr_col--;
			}
			ptr_row = landmark_row + 1, ptr_col = landmark_col + 1;
			while (ptr_row < this->CB_row && ptr_col < this->CB_col) // �V�k�U�ʸ�
			{
				this->ChessBoard[ptr_row][ptr_col] = 0;
				ptr_row++, ptr_col++;
			}
		}
	}
	return bol;
}

void EightQueen::DeletePuzzle()
{
	for (int i = 0; i < this->CB_row; i++)
	{
		for (int j = 0; j < this->CB_col; j++)
		{
			this->ChessBoard[i][j] = -1;
		}
	}
	
}

void EightQueen::PrintPuzzle()
{

	for (int i = 0; i < this->CB_row; i++)
	{
		for (int j = 0; j < this->CB_col; j++)
		{			
			if (this->ChessBoard[i][j] == 1)

				cout << "��";

			else

				cout << "��";

		}
		cout << endl;
	}
}