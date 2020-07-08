#include <iostream>
#include <time.h>
#include <conio.h>
using namespace std;
enum eDir { STOP = 0, LEFT = 1, UPLEFT = 2, DOWNLEFT = 3, RIGHT = 4, UPRIGHT = 5, DOWNRIGHT = 6};
class cBall
{
private:
	int x, y;
	int originalX, originalY;
	eDir direction;
public:
	cBall(int posX, int posY)
	{
		originalX = posX;
		originalY = posY;
		x = posX; y = posY;
		direction = STOP;
	}
	void Reset()
	{
		x = originalX; y = originalY;
		direction = STOP;
	}
	void changeDirection(eDir d)
	{
		direction = d;
	}
	void randomDirection()
	{
		direction = (eDir)((rand() % 6) + 1);
	}
	inline int getX() { return x; }
	inline int getY() { return y; }
	inline eDir getDirection() { return direction; }
	void Move()
	{
		switch (direction)
		{
		case STOP:
			break;
		case LEFT:
			x--;
			break;
		case RIGHT:
			x++;
			break;
		case UPLEFT:
			x--; y--;
			break;
		case DOWNLEFT:
			x--; y++;
			break;
		case UPRIGHT:
			x++; y--;
			break;
		case DOWNRIGHT:
			x++; y++;
			break;
		default:
			break;
		}
		int ballx = ball->getX();
		int bally = ball->getY();
		int player1x = player1->getX();
		int player2x = player2->getX();
		int player1y = player1->getY();
		int player2y = player2->getY();

		//left paddle
		for (int i = 0; i < 4; i++)
			if (ballx == player1x + 1)
				if (bally == player1y + i)
					ball->changeDirection((eDir)((rand() % 3) + 4));

		//right paddle
		for (int i = 0; i < 4; i++)
			if (ballx == player2x - 1)
				if (bally == player2y + i)
					ball->changeDirection((eDir)((rand() % 3) + 1));

		//bottom wall
		if (bally == height - 1)
			ball->changeDirection(ball->getDirection() == DOWNRIGHT ? UPRIGHT : UPLEFT);
		//top wall
		if (bally == 0)
			ball->changeDirection(ball->getDirection() == UPRIGHT ? DOWNRIGHT : DOWNLEFT);
		//right wall
		if (ballx == width - 1)
			ScoreUp(player1);
		//left wall
		if (ballx == 0)
			ScoreUp(player2);
	}
	void Run()
	{
		while (!quit)
		{
			Draw();
			Input();
			Logic();
		}
	}
};
int main()
{
	cGameManger c(40, 20);
	c.Run();
	return 0;
}
