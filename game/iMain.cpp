#include "iGraphics.h"
#include "bitmap_loader.h"
#include"variable.h"
#include"Animations.h"
#include"graphics.h"
#include"scores.h"
#include<iostream>

using namespace std;




void iDraw()
{
	graphicscode();

}



void iMouseMove(int mx, int my)
{

}


void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//cout << mx <<endl<< my << endl;
		//to start game
		if (my >= 400 && my <= 447){ n = 1; }

		//to enter manual
		if (my >= 340 && my <= 387){ n = 2; } 

		//to enter controls
		if (my >= 280 && my <= 327){ n = 3; }

		//to enter music
		if (my >= 220 && my <= 267){ n = 4; }

		//to enter high score
		if (my >= 160 && my <= 207){ n = 5; }

		//to quit
		if (my >= 100 && my <= 147){ n = 6; }


	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{

	}
}


void iKeyboard(unsigned char key)
{
	if (key == 'a')
	{


	}

	if (key == 'm')				//controlling the music
	{
		if (musicOn)
		{
			musicOn = false;
			PlaySound(0, 0, 0);
		}
		else
		{
			musicOn = true;
			PlaySound("music\\GameMusic.wav", NULL, SND_LOOP | SND_ASYNC);
		}

	}
	if (key == 'e')
	{
		n = 7;
	}

	if (key == 'c')
	{

	}

	if (key == 'r')
	{

	}

	if (key == ' ')
	{


	}

	if (key == '\b')
	{
		n = 0;
	}

}
void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_HOME)
	{
		game = true;
	}


	if (key == GLUT_KEY_RIGHT)			//movement of the basket at right  
	{
		if (basketx <= 425)
			basketx += 10;

	}
	if (key == GLUT_KEY_LEFT)			//movement of the basket at left
	{
		if (basketx>5)
			basketx -= 10;

	}
	if (key == GLUT_KEY_F3)
	{

	}


	if (key == GLUT_KEY_END)
	{
		exit(0);
	}



}
void iPassiveMouse(int a, int b)
{

}





int main()
{
	iSetTimer(5, move1);		//timer for the movement of chicken 1
	iSetTimer(5, move2);		//timer for the movement of chicken 2
	iSetTimer(5, move3);		//timer for the movement of chicken 3
	iSetTimer(5, moveDim1);		//timer for the movement of regular egg
	iSetTimer(5, moveDim2);		//timer for the movement of black egg
	iSetTimer(5, moveDim3);		//timer for the movement of bonus egg
	iSetTimer(6, movestool);		//timer for the movement of stool

	iInitialize(sWidth, sHeight, "catch the EGGS");


	background[0] = iLoadImage("image\\menu\\menu.png");
	//egg
	egg[0] = iLoadImage("image\\game\\egg.png");
	egg[1] = iLoadImage("image\\game\\egg1.png");
	egg[2] = iLoadImage("image\\game\\egg2.png");

	//stool
	stool[0] = iLoadImage("image\\game\\stool.png");


	//homepage & menu buttons
	background[1] = iLoadImage("image\\options\\button (1).png");
	background[2] = iLoadImage("image\\options\\button (2).png");
	background[3] = iLoadImage("image\\options\\button (3).png");
	background[4] = iLoadImage("image\\options\\button (4).png");
	background[5] = iLoadImage("image\\options\\high.png");
	background[6] = iLoadImage("image\\options\\button (6).png");
	background[7] = iLoadImage("image\\options\\gamename.jpg");


	//game
	background[8] = iLoadImage("image\\level\\game.png");
	background[14] = iLoadImage("image\\level\\game1.png");
	background[15] = iLoadImage("image\\level\\game2.png");


	//chicken
	chicken[0] = iLoadImage("image\\game\\chicken1.png");
	chicken[1] = iLoadImage("image\\game\\chicken2.png");
	chicken[2] = iLoadImage("image\\game\\chicken3.png");


	//gameover
	over[0] = iLoadImage("image\\game\\over.png");

	//control page
	background[9] = iLoadImage("image\\options\\Control page.png");

	//manual
	background[10] = iLoadImage("image\\options\\manual.png");

	//music
	background[11] = iLoadImage("image\\options\\music.png");

	//highscore
	background[12] = iLoadImage("image\\options\\highscore.png");


	if (musicOn)
		PlaySound("music\\GameMusic.wav", NULL, SND_LOOP | SND_ASYNC);

	iStart();

	return 0;
}
