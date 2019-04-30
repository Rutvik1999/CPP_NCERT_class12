#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#define KeyUp       72
#define KeyDown     80
#define KeyLeft     75
#define keyRight    77

int gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirecton dir;
void Setup()
{
	gameOver = 0;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
}
void Draw()
{
	system("cls"); //system("clear");
	for (int i = 0; i < width+2; i++)
		cout << "-";
	cout << endl;

	for ( i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0)
				cout << "|";
			if (i == y && j == x)
				cout << "O";
			else if (i == fruitY && j == fruitX)
				cout << "F";
			else
			{
				int print = 0;
				for (int k = 0; k < nTail; k++)
				{
					if (tailX[k] == j && tailY[k] == i)
					{
						cout << "o";
						print = 1;
					}
				}
				if (!print)
					cout << " ";
			}


			if (j == width - 1)
				cout << "|";
		}
		cout << endl;
	}

	for (i = 0; i < width+2; i++)
		cout << "-";
	cout << endl;
	cout << "Score:" << score << endl;
}

void Input()
{
	if (kbhit())
	{
		switch (getch())
		{
		case KeyLeft:
			dir = LEFT;
			break;
		case keyRight:
			dir = RIGHT;
			break;
		case KeyUp:
			dir = UP;
			break;
		case KeyDown:
			dir = DOWN;
			break;
		case 'x':
			gameOver = 1;
			break;
		}
	}
}
void Logic()
{
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;
	for (int i = 1; i < nTail; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
	switch (dir)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;
	}
	//if (x > width || x < 0 || y > height || y < 0)
	//	gameOver = 1;
	if (x >= width) x = 0; else if (x < 0) x = width - 1;
	if (y >= height) y = 0; else if (y < 0) y = height - 1;

	for (i = 0; i < nTail; i++)
		if (tailX[i] == x && tailY[i] == y)
			gameOver = 1;

	if (x == fruitX && y == fruitY)
	{
		score += 10;
		fruitX = rand() % width;
		fruitY = rand() % height;
		nTail++;
	}
}
int main()
{
	Setup();
	while (!gameOver)
	{
		Draw();
		Input();
		Logic();
		int i;
		cout<<"Game over ! "<<endl;
		cin>>i;
		for(double s = (-1); s<110000;s++)
		{   }
	}
	return 0;
}
