#ifndef EIGHTQUEENPUZZLE_H
#define EIGHTQUEENPUZZLE_H

using namespace std;

class EightQueen
{
	private:

		int **ChessBoard, CB_row, CB_col;

	public:

		EightQueen(int length_in);
		~EightQueen();
		int CreateThePuzzle();
		void DeletePuzzle();
		void PrintPuzzle();
};

#endif