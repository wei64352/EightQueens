#include<iostream>
#include"EightQueenPuzzle.h"

using namespace std;

int main()
{
	int num, count = 1;

	cout << "�п�J�ѽL�j�p: ";
	cin >> num;

	EightQueen eq(num);

	while (eq.CreateThePuzzle() == 0)
	{
		eq.CreateThePuzzle();
		count++;
	}
	eq.PrintPuzzle();
	cout << "\n" << count;

	system("pause");
	return 0;
}