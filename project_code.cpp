

#include <iostream>
#include <windows.h> 

using namespace std;
#include "StackArr.cpp"
#include "StackArr.h"


StackArr s1, s2;
int number2;
int level;

int perfect_puzzzel[9][9] =       // 1 2 2 4 5 6 7 8 9
/* 1*/{ {5,3,4,6,7,8,9,1,2} ,
/* 2 */ {6,7,2,1,9,5,3,4,8} ,
/* 3 */ {1,9,8,3,4,2,5,6,7} ,
/* 4 */ {8,5,9,7,6,1,4,2,3} ,
/* 5 */ {4,2,6,8,5,3,7,9,1} ,
/* 6 */ {7,1,3,9,2,4,8,5,6} ,
/* 7 */ {9,6,1,5,3,7,2,8,4} ,
/* 8 */ {2,8,7,4,1,9,6,3,5} ,
/* 9 */ {3,4,5,2,8,6,1,7,9} };

//Header Of The Functions
void start_menu();     ////// first function in the console

void firstt(int number);    /////// function to display the levels of the game

void showgame(int number2);  /////// fuction to display the level which the user choose it 

bool col_check(int arr[9][9], int num, int col);    ///////// function to check the number is repeat in column or not

bool raw_check(int arr[9][9], int  num, int  raw);     ///////// function to check the number is repeat in row or not

void showpuzzel(int& steps, int puzzzel[9][9]);     /////// function has the ability to show the game in the 3 levels 

void checkindex(int& steps, int puzzzel[9][9]);  ////////  function to check the index is correct and empty ..

void undo( int& steps, int  arr[9][9]/* StackArr s1, StackArr s2*/);

bool check_win(int& steps, int  arr[9][9]);

void End_game(string end);


int main()
{
	start_menu();

	return 0;
}


void start_menu()
{
	system("cls");
	int num;
	cout << "--------------------------------SUDOKU-------------------------" << endl;
	cout << "[1] START" << endl;
	cout << "[2] instructions" << endl;
	cout << "[3] EXIT" << endl;
	cout << "---------------------------------------------------------------" << endl;

	cout << "Please Enter Number From [1] to [3] " << endl;
	cin >> num;
	firstt(num);

}



void firstt(int number)
{
	switch (number)
	{
	case 1:
	{
		system("cls");
		cout << "[1] EASY" << endl;
		cout << "[2] MEDIUM" << endl;
		cout << "[3] HARD" << endl;
		cout << "---------------------------------------------------" << endl;
		cout << "[4] BACK" << endl;
		cout << "press the number of your choice " << endl;
		cin >> number2;
		showgame(number2);

		break;
	}
	case 2:
	{
		void instructions();
		{
			int num_TO_exit;
			system("cls");
			cout << "[*] - Only use the numbers 1 to 9, Avoid trying to guess the solution to the puzzle, " << endl;
			cout << "[*] - Only use each number once in each row, column, & grid, " << endl;
			cout << "[*] - Use the process of elimination as a tactic, " << endl;
			cout << "[*] - Use cross - hatching and penciling in techniques." << endl;
			cout << "---------------------------------------" << endl;
			cout << " Enter [1] To Back " << endl;
			cin >> num_TO_exit;
			while (num_TO_exit == 1)
			{
				start_menu();
				break;
			}
		}
		break;
	}
	case 3:
	{
		system("cls");
		break;
	}

	default:
	{
		cout << "Enter corret number ";
		break;
	}

	}
}



void showgame(int number2)
{
	system("cls");

	
	switch (number2)
	{
	case 1:
	{
		void easy();
		{
			level = 1;
			int steps = 23;
			int puzzzel[9][9] =        // 1 2 2 4 5 6 7 8 9
				/* 1*/{ { 0 ,3,4,6, 0 , 0 , 0,1,2} ,
				/* 2 */ {6 , 0 ,2,1,9,5,3,4,8} ,
				/* 3 */ {1, 0 ,8,3,4,2,5,6,7} ,
				/* 4 */ {8, 0 ,9,7,0,1,4, 0 ,3} ,
				/* 5 */ {4, 2, 0 ,8,0,3,7, 0 ,1} ,
				/* 6 */ {7,1,3, 0 ,2,4,8, 0,6} ,
				/* 7 */ {9,0,1, 0 ,3,7,2,8,4} ,
				/* 8 */ {2,8,7,  0 , 0,9,6,3,5} ,
				/* 9 */ {3, 0 , 0 , 0, 0,6, 0 ,7,9} };
			showpuzzel(steps, puzzzel);
			//int row, column;
			while (steps >= 0)
			{

				checkindex(steps, puzzzel);


			}

		}

		break;
	}
	case 2:
	{
		void midiam();
		{
			level = 2;
			int steps = 36;
			int puzzzel[9][9] =        // 1 2 2 4 5 6 7 8 9
				/* 1*/{ { 0 ,3, 0 ,6, 0 , 0 , 0, 0,2} ,
				/* 2 */ {6 , 0 ,2,1,0 ,5,3, 0 ,8} ,
				/* 3 */ {1, 0 ,8,0 ,0 ,2, 0,6,7} ,
				/* 4 */ {8, 0 ,9,7,0,1,4, 0 ,3} ,
				/* 5 */ {4,  0, 0 , 0,0,3,7, 0 ,1} ,
				/* 6 */ {7,1,3, 0 ,2, 0 ,8, 0,6} ,
				/* 7 */ {9,0,1, 0 ,3, 0 ,2,8,4} ,
				/* 8 */ {2,8,7,  0 , 0,9, 0 ,3,5} ,
				/* 9 */ {3, 0 , 0 , 0, 0,6, 0 ,7,0} };
			showpuzzel(steps, puzzzel);
			//int row, column;
			while (steps >= 0)
			{

				checkindex(steps, puzzzel);


			}
		}

		break;
	}
	case 3:
	{
		void hard();
		{
			level = 3;
			int steps = 45;
			int puzzzel[9][9] =        // 1 2 2 4 5 6 7 8 9
				/* 1*/{ { 0 ,3, 0 ,6, 0 , 0 , 0, 0,2} ,
				/* 2 */ {0 , 0 ,2,1,0 ,0,3, 0 ,0} ,
				/* 3 */ {1, 0 ,8,0 ,0 ,2, 0,6,7} ,
				/* 4 */ {8, 0 ,9,0,0,1,4, 0 ,0} ,
				/* 5 */ {4,  0, 0 , 0,0,3,7, 0 ,1} ,
				/* 6 */ {7,1,3, 0 ,2, 0 ,8, 0,6} ,
				/* 7 */ {9,0,1, 0 ,3, 0 ,2,0,0} ,
				/* 8 */ {2,0,0,  0 , 0,9, 0 ,3,5} ,
				/* 9 */ {3, 0 , 0 , 0, 0,6, 0 ,7,0} };
			showpuzzel(steps, puzzzel);
			//int row, column;
			while (steps >= 0)
			{

				checkindex(steps, puzzzel);


			}
		}

		break;
	}
	case 4:
	{
		start_menu();
		break;
	}
	default:
		cout << "Enter corret number ";
		break;
	}

}






bool col_check(int arr[9][9], int num, int col)
{
	bool first = false;



	for (int raw = 0; raw < 9; raw++)
	{



		if (arr[raw][col - 1] == num)
		{
			cout << " the number is exist in the same coulmn" << endl;
			first = false;
			break;

		}
		else
		{
			first = true;
		}




	}

	return first;
}

bool raw_check(int arr[9][9], int  num, int  raw)
{
	bool second = false;

	for (int col = 0; col < 9; col++)
	{



		if (arr[raw - 1][col] == num)
		{
			cout << " the number is exist in the same coulmn" << endl;
			second = false;
			break;
		}
		else
		{
			second = true;
		}




	}

	return second;
}

void showpuzzel(int& steps, int puzzzel[9][9])
{
	cout << "you have " << steps << " empty feilds. \n" << endl;

	
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << " | ";
			if (puzzzel[i][j] == 0)
			{
				cout << " ";
			}
			else
				cout << puzzzel[i][j];


		}
		cout << " | ";

		if ((i + 1) % 3 == 0)
		{
			cout << endl;
			cout << " -------------------------------------";
		}
		cout << endl;
	}
}

void undo( int& steps ,int  arr[9][9] )
{
	char undo;
	while (true)
	{
		cout << " If You Want To Undo enter [ u ] if not enter [ c ]" <<endl;
		cin >> undo;
		if (undo == 'u' || undo == 'U')
		{
			arr[s1.Top()-1][s2.Top()-1] = 0;
			steps++;
			s1.Pop();
			s2.Pop();
			system("cls");
			showpuzzel(steps, arr);
			
		}
		else if (undo == 'c' || undo == 'C')
		{

			break;
		}
	}
}

void checkindex(int& steps, int puzzzel[9][9])
{
	int row, column;
	string end ;
	if (steps == 0)
	{

		if (check_win(steps, puzzzel))
		{
			end = "you win";
			End_game(end);
			
			
		}
		else
		{
			end = "you lose";
			End_game(end);

		}
	}
	
	if ((level==1 && steps <23 )|| (level == 2 && steps < 36)|| (level == 3 && steps < 45))
	{
		undo(steps, puzzzel);
		
	}
	system("cls");
	showpuzzel(steps, puzzzel);
	cout << "enter number of row " << endl;
	cin >> row;
	cout << "enter number of column " << endl;
	cin >> column;

	bool valid = false;
	while (!valid)
	{


		if (row - 1 >= 0 && row - 1 <= 8 && column - 1 >= 0 && column - 1 <= 8 && puzzzel[row - 1][column - 1] == 0)
		{
			valid = true;
			s1.Push(row);
			s2.Push(column);
		}
		else
		{
			valid = false;
			cout << "Please Enter Valid Index" << endl;
			cout << "enter number of row " << endl;
			cin >> row;
			
			cout << "enter number of column " << endl;
			cin >> column;
			
		}
	
		
	}

	if (valid)
	{
		int num;

		while (true)
		{
			

			cout << " Enter the Number You Want between 1 and 9 " << endl;
			cin >> num;
			if (!(num > 9 || num < 1))
			{

				break;
			}
			else
			{
				cout << "enter number between 1 and 9 " << endl;
				cin >> num;
				if (!(num > 9 || num < 1))
				{
					break;
				}
				else
				{
					continue;
				}

			}
		}
		if (col_check(puzzzel, num, column) && raw_check(puzzzel, num, row) /*&& check( puzzzel , num )*/)
		{
			puzzzel[row - 1][column - 1] = num;
			steps--;
		}

		system("cls");
		showpuzzel(steps, puzzzel);
	}


}


bool check_win(int& steps, int  arr[9][9])
{
	bool win = false;
	if (steps == 0)
	{
		for (int i = 0 ; i < 9; i++)
		{
			for (int j = 0 ; j < 9; j++)
			{
				if (perfect_puzzzel[i][j] == arr[i][j])

					win = true;
				else
				{
					win = false;
					break;
				}
				    
			}
		}
	}

	

	return win;
}
void End_game(string end)
{
	int x;
	system("cls");
	cout << end;
	cout << " press 0 to go back else press any key ";
	cin >> x;
	if (x == 0)
	{
		start_menu();
	}
	else
	{
		system("CloseWindow");
	}


}