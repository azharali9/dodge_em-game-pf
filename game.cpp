//============================================================================
// Name        : game.cpp
// Author      : Hassan Mustafa
// Version     :
// Copyright1   : (c) Reserved
// Description : Basic 2D game of Dodge 'Em...
//============================================================================

#ifndef DODGE_CPP_
#define DODGE_CPP_
#include "util.h"
#include <iostream>
#include<string>
#include "graphics.h"
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;
#include <fstream>



int sx=50;
int sy=40;
int gy=400;
int gx=760;
int mx=20;
int my=20;
int ftemp=0;
int sx1=760;
int sy1=640;
int x_food1=780;
int scored=0;
int live=3;
int xf1[8]={50,140,230,350,470,590,670,750};
int yf1[8]={640,640,640,640,640,640,640,640};
int xf2[8]={50,140,230,350,470,590,670,750};
int yf2[8]={560,560,560,560,560,560,560,560};
int xf3[8]={50,140,230,350,470,590,670,750};
int yf3[8]={480,480,480,480,480,480,480,480};
int xf4[8]={50,140,230,350,470,590,670,750};
int yf4[8]={410,410,410,410,410,410,410,410};
int xf5[8]={50,140,230,350,470,590,670,750};
int yf5[8]={270,270,270,270,270,270,270,270};
int xf6[8]={50,140,230,350,470,590,670,750};
int yf6[8]={190,190,190,190,190,190,190,190};
int xf7[8]={50,140,230,350,470,590,670,750};
int yf7[8]={120,120,120,120,120,120,120,120};
int xf8[8]={50,140,230,350,470,590,670,750};
int yf8[8]={40,40,40,40,40,40,40,40};

//food for level 2



int xfb1[8]={50,140,230,350,470,590,670,750};
int yfb1[8]={640,640,640,640,640,640,640,640};
int xfb2[8]={50,140,230,350,470,590,670,750};
int yfb2[8]={560,560,560,560,560,560,560,560};
int xfb3[8]={50,140,230,350,470,590,670,750};
int yfb3[8]={480,480,480,480,480,480,480,480};
int xfb4[8]={50,140,230,350,470,590,670,750};
int yfb4[8]={410,410,410,410,410,410,410,410};
int xfb5[8]={50,140,230,350,470,590,670,750};
int yfb5[8]={270,270,270,270,270,270,270,270};
int xfb6[8]={50,140,230,350,470,590,670,750};
int yfb6[8]={190,190,190,190,190,190,190,190};
int xfb7[8]={50,140,230,350,470,590,670,750};
int yfb7[8]={120,120,120,120,120,120,120,120};
int xfb8[8]={50,140,230,350,470,590,670,750};
int yfb8[8]={40,40,40,40,40,40,40,40};

bool menu=true, newGame=false, highScore=false, help=false, pauseGame=false,  l=false;
bool left1=false, right1=false, up1 = false, down1 = false, def=true;
bool down=false, up=false;
int width, height;
string res="0"; 
string lv="3";
string re;

	int sx2=40,sy2=30,sx3=40, sy3=30;

//coordiates of green car in the menu

float cx=20;
float cy=600;

//coordinates of red car in the menu

float dx=750;
float dy=600;
	
//coordinates of players car 

float x=380;
float y=610;

//coordinates of opponents car


float qx = 750; 
float qy = 30;


void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}




int d=0;

void scoreLive();



void gamePlayer(){
	float width = 10; 
	float height = 10;
	float* color = colors[GREEN]; 
	float radius = 3.0;
	DrawRoundRect(x,y,width,height,color,radius); // bottom left1 tyre
	DrawRoundRect(x+width*3,y,width,height,color,radius); // bottom right1 tyre
	DrawRoundRect(x+width*3,y+height*4,width,height,color,radius); // top right1 tyre
	DrawRoundRect(x,y+height*4,width,height,color,radius); // top left1 tyre
	DrawRoundRect(x, y+height*2, width, height, color, radius/2); // body left1 rect
	DrawRoundRect(x+width, y+height, width*2, height*3, color, radius/2); // body center rect
	DrawRoundRect(x+width*3, y+height*2, width, height, color, radius/2); // body right1 rect

}

// void makefood(){
// 			for(int i=0;i<8;i++){
// 			DrawRectangle(xf1[i],yf1[i]-40, mx,my, colors[RED]);
	
// 	}
// }


void MenuCar(){
	cx+=10;
	float width = 10; 
	float height = 10;
	float* color = colors[GREEN]; 
	float radius = 3.0;
	DrawRoundRect(cx,cy,width,height,color,radius); // bottom left1 tyre
	DrawRoundRect(cx+width*3,cy,width,height,color,radius); // bottom right1 tyre
	DrawRoundRect(cx+width*3,cy+height*4,width,height,color,radius); // top right1 tyre
	DrawRoundRect(cx,cy+height*4,width,height,color,radius); // top left1 tyre
	DrawRoundRect(cx, cy+height*2, width, height, color, radius/2); // body left1 rect
	DrawRoundRect(cx+width, cy+height, width*2, height*3, color, radius/2); // body center rect
	DrawRoundRect(cx+width*3, cy+height*2, width, height, color, radius/2); // body right1 rect
		// 		makefood();
		// checkfoodMenu();

		

}


void opponentPlayer(){
	
float qwidth = 10; 
	float qheight = 10;
	float* qcolor = colors[RED]; 
	float qradius = 3.0;
	DrawRoundRect(qx,qy,qwidth,qheight,qcolor,qradius); // bottom left1 tyre
	DrawRoundRect(qx+qwidth*3,qy,qwidth,qheight,qcolor,qradius); // bottom right1 tyre
	DrawRoundRect(qx+qwidth*3,qy+qheight*4,qwidth,qheight,qcolor,qradius); // top right1 tyre
	DrawRoundRect(qx,qy+qheight*4,qwidth,qheight,qcolor,qradius); // top left1 tyre
	DrawRoundRect(qx, qy+qheight*2, qwidth, qheight, qcolor, qradius/2); // body left1 rect
	DrawRoundRect(qx+qwidth, qy+qheight, qwidth*2, qheight*3, qcolor, qradius/2); // body center rect
	DrawRoundRect(qx+qwidth*3, qy+qheight*2, qwidth, qheight, qcolor, qradius/2); // body right1 rect
}




void checkfoodTop(){
		for(int i=0; i<8; i++){
			if(x==xf1[i] and y>=yf1[i]-40 and y<=yf1[i]+40){
				xf1[i]=xf1[i]+5000;
				DrawRoundRect(xf1[i],yf1[i], mx,my, colors[RED]);
				scored++;
				res=to_string(scored);
			}	

		}
		scoreLive();

}

void checkfood1(){
		for(int i=0; i<8; i++){
			if(x==xf2[i] and y>=yf2[i]-40 and y<=yf2[i]+40){
				xf2[i]=xf2[i]+5000;
				DrawRoundRect(xf2[i],yf2[i], mx,my, colors[RED]);
				scored++;
				res=to_string(scored);
			}	
		}
		scoreLive();

}



void checkfood2(){
		for(int i=0; i<8; i++){
			if(x==xf3[i] and y>=yf3[i]-40 and y<=yf3[i]+40){
				xf3[i]=xf3[i]+5000;
				DrawRoundRect(xf3[i],yf3[i], mx,my, colors[RED]);
				scored++;
				res=to_string(scored);
			}	
		}
		scoreLive();

}



void checkfood3(){
		for(int i=0; i<8; i++){
			if(x==xf4[i] and y>=yf4[i]-40 and y<=yf4[i]+40){
				xf4[i]=xf4[i]+5000;
				DrawRoundRect(xf4[i],yf4[i], mx,my, colors[RED]);
				scored++;
				res=to_string(scored);
			}	
		}
		scoreLive();

}


void checkfood4(){
		for(int i=0; i<8; i++){
			if(x==xf5[i] and y>=yf5[i]-40 and y<=yf5[i]+40){
				xf5[i]=xf5[i]+5000;
				DrawRoundRect(xf5[i],yf5[i], mx,my, colors[RED]);
				scored++;
				res=to_string(scored);
			}	
		}
		scoreLive();

}

void checkfood5(){
		for(int i=0; i<8; i++){
			if(x==xf6[i] and y>=yf6[i]-40 and y<=yf6[i]+40){
				xf6[i]=xf6[i]+5000;
				DrawRoundRect(xf6[i],yf6[i], mx,my, colors[RED]);
				scored++;
				res=to_string(scored);
			}	
		}
		scoreLive();

}

void checkfood6(){
		for(int i=0; i<8; i++){
			if(x==xf7[i] and y>=yf7[i]-40 and y<=yf7[i]+40){
				xf7[i]=xf7[i]+5000;
				DrawRoundRect(xf7[i],yf7[i], mx,my, colors[RED]);
				scored++;
				res=to_string(scored);
			}	
		}
		scoreLive();

}

void checkfoodBottom(){
		for(int i=0; i<8; i++){
			if(x==xf8[i] and y>=yf8[i]-40 and y<=yf8[i]+40){
				xf8[i]=xf8[i]+5000;
				DrawRoundRect(xf8[i],yf8[i], mx,my, colors[RED]);
				scored++;
				res=to_string(scored);

			}	
		}
		scoreLive();

}

void checkfoodTopb(){
		for(int i=0; i<8; i++){
			if(x==xfb1[i] and y>=yfb1[i]-40 and y<=yfb1[i]+40){
				xfb1[i]=xfb1[i]+5000;
				DrawRoundRect(xfb1[i],yfb1[i], mx,my, colors[RED]);
				scored++;
				res=to_string(scored);
			}	

		}
		scoreLive();

}

void checkfoodb1(){
		for(int i=0; i<8; i++){
			if(x==xfb2[i] and y>=yfb2[i]-40 and y<=yfb2[i]+40){
				xf2[i]=xf2[i]+5000;
				DrawRoundRect(xf2[i],yf2[i], mx,my, colors[RED]);
				scored++;
				res=to_string(scored);
			}	
		}
		scoreLive();

}



void checkfoodb2(){
		for(int i=0; i<8; i++){
			if(x==xfb3[i] and y>=yfb3[i]-40 and y<=yfb3[i]+40){
				xfb3[i]=xfb3[i]+5000;
				DrawRoundRect(xfb3[i],yfb3[i], mx,my, colors[RED]);
				scored++;
				res=to_string(scored);
			}	
		}
		scoreLive();

}



void checkfoodb3(){
		for(int i=0; i<8; i++){
			if(x==xfb4[i] and y>=yfb4[i]-40 and y<=yfb4[i]+40){
				xfb4[i]=xfb4[i]+5000;
				DrawRoundRect(xfb4[i],yfb4[i], mx,my, colors[RED]);
				scored++;
				res=to_string(scored);
			}	
		}
		scoreLive();

}


void checkfoodb4(){
		for(int i=0; i<8; i++){
			if(x==xfb5[i] and y>=yfb5[i]-40 and y<=yfb5[i]+40){
				xfb5[i]=xfb5[i]+5000;
				DrawRoundRect(xfb5[i],yfb5[i], mx,my, colors[RED]);
				scored++;
				res=to_string(scored);
			}	
		}
		scoreLive();

}

void checkfoodb5(){
		for(int i=0; i<8; i++){
			if(x==xfb6[i] and y>=yfb6[i]-40 and y<=yfb6[i]+40){
				xfb6[i]=xfb6[i]+5000;
				DrawRoundRect(xfb6[i],yfb6[i], mx,my, colors[RED]);
				scored++;
				res=to_string(scored);
			}	
		}
		scoreLive();

}

void checkfoodb6(){
		for(int i=0; i<8; i++){
			if(x==xfb7[i] and y>=yfb7[i]-40 and y<=yfb7[i]+40){
				xfb7[i]=xfb7[i]+5000;
				DrawRoundRect(xfb7[i],yfb7[i], mx,my, colors[RED]);
				scored++;
				res=to_string(scored);
			}	
		}
		scoreLive();

}

void checkfoodBottomb(){
		for(int i=0; i<8; i++){
			if(x==xf8[i] and y>=yf8[i]-40 and y<=yf8[i]+40){
				xf8[i]=xf8[i]+5000;
				DrawRoundRect(xf8[i],yf8[i], mx,my, colors[RED]);
				scored++;
				res=to_string(scored);

			}	
		}
		scoreLive();

}

void checkDodge(){
if(x==qx+10 and x>=qx-10 and y>=qy-10 and y<=qy+10){
	live--;
	lv=to_string(live);
}
scoreLive();

}



	
void scoreLive(){
	if(res>="64"){

					ofstream outputFile;
					re;
					re=res;
					outputFile.open( "scores.txt");
					outputFile<<re<< endl;
					outputFile.close();
					cout<<"Done"<<endl;
				}
DrawString( 250, 750,"SCORE", colors[GREEN]);
DrawString( 340, 750,res, colors[RED]);
DrawString( 450, 750,"LIVES", colors[GREEN]);
DrawString( 550, 750, lv, colors[RED]);
}


void MenuOpponentCar(){
	dx-=10;
	float width = 10; 
	float height = 10;
	float* color = colors[RED]; 
	float radius = 3.0;
	DrawRoundRect(dx,dy,width,height,color,radius); // bottom left1 tyre
	DrawRoundRect(dx+width*3,dy,width,height,color,radius); // bottom right1 tyre
	DrawRoundRect(dx+width*3,dy+height*4,width,height,color,radius); // top right1 tyre
	DrawRoundRect(dx,dy+height*4,width,height,color,radius); // top left1 tyre
	DrawRoundRect(dx, dy+height*2, width, height, color, radius/2); // body left1 rect
	DrawRoundRect(dx+width, dy+height, width*2, height*3, color, radius/2); // body center rect
	DrawRoundRect(dx+width*3, dy+height*2, width, height, color, radius/2); // body right1 rect

}



void GameMenu(){
	glClearColor(2/*Red Component*/, 1,	//148.0/255/*Green Component*/,
			1.0/*Blue Component*/, 0/*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //up1date the colors
	DrawString( 350, 750, "DODGE 'EM", colors[GREEN]);
	DrawString( 370, 500, "START(s)", colors[GREEN]);
	DrawString( 340, 400, "HIGH SCORE(h)", colors[GREEN]);
	DrawString( 370, 300, "HELP(z)", colors[GREEN]);
	DrawString( 365, 200, "EXIT(esc)", colors[GREEN]);
	DrawLine( 0, 550, 1000, 550, 20, colors[GREEN]);
	DrawLine( 330, 550, 330, 180, 20, colors[GREEN]);
	DrawLine( 530, 550, 530, 180, 20, colors[GREEN]);
	DrawLine( 330, 184, 530, 184, 20, colors[GREEN]);
	

	
//range of player cars travel in main menu

	
		if(cx<=390){ 
			MenuCar();
		}
		
		else if(cx==400){
				cx=20;
				MenuCar();
			}

//range of opponent cars travel in main menu

		if(dx>=390){ 
			MenuOpponentCar();
		}
		else if(cx==400){
			dx=750;
			MenuOpponentCar();


	}

	glutSwapBuffers();
}


void GamePause(){
	glClearColor(2/*Red Component*/, 1,	//148.0/255/*Green Component*/,
			1.0/*Blue Component*/, 0/*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //up1date the colors
	DrawString( 350, 750, "GAME PAUSED", colors[GREEN]);
	DrawString( 370, 500, "RESUME(s)", colors[GREEN]);
	DrawString( 340, 400, "HIGH SCORE(h)", colors[GREEN]);
	DrawString( 370, 300, "HELP(z)", colors[GREEN]);
	DrawString( 365, 200, "EXIT(esc)", colors[GREEN]);
	

	glutSwapBuffers();
}

//data reading 

void inputscore(){
	ifstream inputFile;
					inputFile.open( "scores.txt");
					inputFile>>re;
					
					DrawString( 380, 550, re, colors[GREEN]);
					inputFile.close();
					cout<<"Done"<<endl;
}



void gameOver(){
	glClearColor(2/*Red Component*/, 1,	//148.0/255/*Green Component*/,
			1.0/*Blue Component*/, 0/*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //up1date the colors
	DrawString( 330, 400, "GAME OVER", colors[GREEN]);

	glutSwapBuffers();
}
void score(){
	glClearColor(2/*Red Component*/, 1,	//148.0/255/*Green Component*/,
			1.0/*Blue Component*/, 0/*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //up1date the colors
	DrawString( 330, 750, "HIGH SCORES", colors[GREEN]);
	inputscore();
	DrawString( 80, 75, "BACK(m)", colors[GREEN]);
	DrawLine(20, 80, 40, 100, 5, colors[RED]);
	DrawLine(20, 80, 40, 60, 5, colors[RED]);
	DrawLine(20, 80, 80, 80, 5, colors[RED]);
					
	 help=false;
		  newGame=false;
	glutSwapBuffers();

}

void gmaelevel2(){
	glClearColor(2/*Red Component*/, 1,	//148.0/255/*Green Component*/,
			1.0/*Blue Component*/, 0/*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //up1date the colors
	

DrawString( 20, 750, "LEVEL", colors[GREEN]);
DrawString( 110, 750, "2", colors[RED]);
		
def=true;

//food
for(int i=0;i<8;i++){
			DrawRectangle(xfb1[i],yfb1[i], mx,my, colors[BLUE]);
			checkfoodTop();
	}
for(int i=0;i<8;i++){
			DrawRectangle(xfb2[i],yfb2[i], mx,my, colors[BLUE]);
			checkfood1();
	}
for(int i=0;i<8;i++){
			DrawRectangle(xfb3[i],yfb3[i], mx,my, colors[BLUE]);
			checkfood2();
	}
for(int i=0;i<8;i++){
			DrawRectangle(xfb4[i],yfb4[i], mx,my, colors[BLUE]);
			checkfood3();
	}
for(int i=0;i<8;i++){
			DrawRectangle(xfb5[i],yfb5[i], mx,my, colors[BLUE]);
			checkfood4();
	}
for(int i=0;i<8;i++){
			DrawRectangle(xfb6[i],yfb6[i], mx,my, colors[BLUE]);
			checkfood5();
	}
for(int i=0;i<8;i++){
			DrawRectangle(xfb7[i],yfb7[i], mx,my, colors[BLUE]);
			checkfood6();
	}
for(int i=0;i<8;i++){
			DrawRectangle(xfb8[i],yfb8[i], mx,my, colors[BLUE]);
			checkfoodBottom();
	}

//players motion with keys
	
	if (right1){
	
		x+=5;
		left1=false;
		up1=false;
		down1=false;
		}
		  
	
	else 
		
		if(left1){
		right1=false;
		up1=false;
		down1=false;
		x-=5;
	
}


	else 
	
		if(up1){
		y+=55;
		left1=false;
		right1=false;
		down1=true;
	}

	else
		
		if(down1){
		y-=5;
		right1=false;
		up1=false;
		left1=false;
	}
if(!def){
	
	gamePlayer();

}
if(def){

	//vertical down motion

	 if(x==750 and y>=20){
		y-=5;
		gamePlayer();
	}

	//horizontal left motion

	if(y==10 and x>=60){
		x-=5;
		gamePlayer();
	}
	
	//vertical up motion
		
	if(x==50 && y<= 600){
	y+=5;
	gamePlayer();
	}
	
	//top rigth motion

	if(y>610){
	x+=5;
	gamePlayer();
	}
	

}














 //opponents car

//left downward motion

 if(qx==750 and qy<=610){
	qy+=10;
	opponentPlayer();
}
else 
if(qy==620 and qx>=40){
	qx-=10;
	opponentPlayer();
} else
	if(qx==30 and qy>=30){
		qy-=10;

	opponentPlayer();
}

//bottom right motion

	else
if(qy==20 and qx<=390){
	qx+=10;
	opponentPlayer();
}

//bottom half up

else if(qx==400 and qy<=90){
	qy+=10;
	opponentPlayer();
}

//lane2 rigth motion

else if(qy==100 and qx>=400 and qx<=650){
	qx+=10;
	opponentPlayer();

}

//lane2 up motion

else if(qx==660 and qy<=530){
	qy+=10;
	opponentPlayer();
}

//lane2 left motion

else if(qy==540 and qx>=150){
	qx-=10;
	  opponentPlayer();
}

//left lane2 downward motion

else if(qx==140 and qy>=100){
	qy-=10;
	opponentPlayer();
}

//lane 2 half right motion

else if(qy==90 and qx<=380){
	qx+=10;
	opponentPlayer();
}

//lane 2 bottom half up motion

else if(qx==390 and qy<=160){
	qy+=10;
	opponentPlayer();
}

//lane 3 right motion

else if(qy==170 and qx>=390 and qx<=570){
	qx+=10;
	opponentPlayer();
}

//lane 3 up motion

else if(qx==580 and qy<=450){
	qy+=10;
	opponentPlayer();
}

//lane 3 top left motion

else if(qy==460 and qx>=230){
	qx-=10;
	opponentPlayer();
}

//lane 3 left down motion

else if(qx==220 and qy>=170){
	qy-=10;
	opponentPlayer();
}

//lane 3 bottom rigth motion

else if(qy==160 and qx<=370){
	qx+=15;
	opponentPlayer();
}


else if(qx==385 and qy<=250){
	qy+=10;
	opponentPlayer();
}

//lane 4 right mortion

else if(qy==260 and qx>=385 and qx<=475){
	qx+=10;
	opponentPlayer();
}

//lane 4 up motion

else if(qx==485 and qy<=370){
	qy+=10;
	opponentPlayer();
}

//lane 4 left motion

else if(qy==380 and qx>=355){
	qx-=10;
	opponentPlayer();
}

//lane 4 left downward motion

else if(qx==345 and qy>=260){
	qy-=10;
	opponentPlayer();
}

//lane 4 right  motion

else if(qy==250 and qx<=365){
	qx+=10;
	opponentPlayer();
}


//arena 

	int gap_turn = 60;
	int sx = 20;
	int sy = 10;
	int swidth = 800/2 - gap_turn/2; // half width
	int sheight = 10;
	float *scolor = colors[RED];


	DrawRectangle(sx-1, sy-10, swidth-10, sheight, scolor); // bottom left1
	DrawRectangle(sx+90, sy+70, swidth-100, sheight, scolor); // bottom left1
	DrawRectangle(sx+180, sy+150, swidth-190, sheight, scolor); // bottom left1
	DrawRectangle(sx+260, sy+220, swidth-270, sheight, scolor); // bottom left1
	
	

	DrawRectangle(sx + swidth + gap_turn, sy-10, swidth+1, sheight, scolor); // bottom right1
	DrawRectangle(sx + swidth + gap_turn, sy+70, swidth-90, sheight, scolor); // bottom right1
	DrawRectangle(sx + swidth + gap_turn, sy+150, swidth-175, sheight, scolor); // bottom right1
	DrawRectangle(sx + swidth + gap_turn, sy+220, swidth-260, sheight, scolor); // bottom right1



	DrawRectangle(sx+swidth*2+gap_turn, (sy-20)+sheight, sheight*2, swidth-70, scolor); // right1 down1
	DrawRectangle((sx-100)+swidth*2+gap_turn, (sy+60)+sheight, sheight*2, swidth-150, scolor); // right1 down1
	DrawRectangle((sx-185)+swidth*2+gap_turn, (sy+140)+sheight, sheight*2, swidth-230, scolor); // right1 down1
	DrawRectangle((sx-270)+swidth*2+gap_turn, (sy+210)+sheight, sheight*2, swidth-300, scolor); // right1 down1




	DrawRectangle(sx+swidth*2+gap_turn, (sy+sheight)-60+swidth+gap_turn, sheight*2, swidth-70, scolor); // right1 up1
	DrawRectangle((sx-100)+swidth*2+gap_turn, (sy+sheight)-60+swidth+gap_turn, sheight*2, swidth-150, scolor); // right1 up1 mini
	DrawRectangle((sx-185)+swidth*2+gap_turn, (sy+sheight)-60+swidth+gap_turn, sheight*2, swidth-230, scolor); // right1 up1 mini 2
	DrawRectangle((sx-270)+swidth*2+gap_turn, (sy+sheight)-60+swidth+gap_turn, sheight*2, swidth-300, scolor); // right1 up1 mini 2


	DrawRectangle(sx + swidth + gap_turn, sy+670, swidth+1, sheight, scolor); // top right1
	DrawRectangle(sx + swidth + gap_turn, sy+590, swidth-90, sheight, scolor); // top left1 mini
	DrawRectangle(sx + swidth + gap_turn, sy+510, swidth-175, sheight, scolor); // top left1 mini 2
	DrawRectangle(sx + swidth + gap_turn, sy+440, swidth-260, sheight, scolor); // top left1 mini 2


	DrawRectangle(sx-1, sy+670, swidth-10, sheight, scolor); // top left1
	DrawRectangle(sx+90, sy+590, swidth-100, sheight, scolor);//2
	DrawRectangle(sx+180, sy+510, swidth-190, sheight, scolor);//3
	DrawRectangle(sx+260, sy+440, swidth-270, sheight, scolor);//3



	DrawRectangle(sx+370, sy+350, swidth-300, sheight-50, scolor); //centre



	DrawRectangle(sx-sheight*2, (sy+sheight)-60+swidth+gap_turn, sheight*2, swidth-70, scolor); // left1 up1
	DrawRectangle((sx+100)-sheight*2, (sy+sheight)-60+swidth+gap_turn, sheight*2, swidth-150, scolor); // left1 up1 2
	DrawRectangle((sx+190)-sheight*2, (sy+sheight)-60+swidth+gap_turn, sheight*2, swidth-230, scolor); // left1 up1 3
	DrawRectangle((sx+270)-sheight*2, (sy+sheight)-60+swidth+gap_turn, sheight*2, swidth-300, scolor); // left1 up1 4



	DrawRectangle(sx-sheight*2, (sy-20)+sheight, sheight*2, swidth-80, scolor); // left1 down1
	DrawRectangle((sx+100)-sheight*2, sy+sheight+60, sheight*2, swidth-160, scolor); // left1 down1 mini
	DrawRectangle((sx+190)-sheight*2, sy+sheight+140, sheight*2, swidth-240, scolor); // left1 down1 imni 3
	DrawRectangle((sx+270)-sheight*2, (sy+210)+sheight, sheight*2, swidth-300, scolor); // left1 down1 imni 2




	


	checkDodge();


	glutPostRedisplay();
			

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void gamehelp(){
	glClearColor(2/*Red Component*/, 1,	//148.0/255/*Green Component*/,
			1.0/*Blue Component*/, 0/*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //up1date the colors
	DrawString( 380, 750, "HELP", colors[GREEN]);
	DrawString( 20, 500, "To move the car left press left key, for right right key, for left left key and for down ", colors[GREEN]);
	DrawString( 20, 400, "down key. Grab all the gifts to proceed to the next level. In case of a collission with ", colors[GREEN]);
	DrawString( 20, 300, "the opponent, 1 life is lost. You have 3 lives to grab all the gifts. There are 4 levels ", colors[GREEN]);
	DrawString( 20, 200, "in the game. ", colors[GREEN]);
	DrawString( 80, 75, "BACK(m)", colors[GREEN]);
	DrawLine(20, 80, 40, 100, 5, colors[RED]);
	DrawLine(20, 80, 40, 60, 5, colors[RED]);
	DrawLine(20, 80, 80, 80, 5, colors[RED]);
	highScore=false;
	newGame=false;
	glutSwapBuffers();
}




void GameDisplay(){
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

if(newGame==true){
	
	glClearColor(2/*Red Component*/, 1,	//148.0/255/*Green Component*/,
			1.0/*Blue Component*/, 0/*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //up1date the colors

	// calling some functions from util.cpp file to help students

	//Square at 400,20 position
	//DrawSquare( 400 , 20 ,40,colors[RED]); 
	//Square at 250,250 position
	//DrawSquare( 250 , 250 ,20,colors[GREEN]); 
	//Display Score
	
	//Triangle at 300, 450 position
	//DrawTriangle( 300, 450 , 340, 450 , 320 , 490, colors[MISTY_ROSE] ); 
	// Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)
	//Circle at 50, 670 position
	//Line from 550,50 to 550,480 with width 10
	//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
	//DrawLine( 550 , 50 ,  550 , 480 , 10 , colors[MISTY_ROSE] );	
	

DrawString( 20, 750, "LEVEL", colors[GREEN]);
DrawString( 110, 750, "1", colors[RED]);
		




//food

for(int i=0;i<8;i++){
			DrawRectangle(xf1[i],yf1[i], mx,my, colors[RED]);
			checkfoodTop();
	}
for(int i=0;i<8;i++){
			DrawRectangle(xf2[i],yf2[i], mx,my, colors[RED]);
			checkfood1();
	}
for(int i=0;i<8;i++){
			DrawRectangle(xf3[i],yf3[i], mx,my, colors[RED]);
			checkfood2();
	}
for(int i=0;i<8;i++){
			DrawRectangle(xf4[i],yf4[i], mx,my, colors[RED]);
			checkfood3();
	}
for(int i=0;i<8;i++){
			DrawRectangle(xf5[i],yf5[i], mx,my, colors[RED]);
			checkfood4();
	}
for(int i=0;i<8;i++){
			DrawRectangle(xf6[i],yf6[i], mx,my, colors[RED]);
			checkfood5();
	}
for(int i=0;i<8;i++){
			DrawRectangle(xf7[i],yf7[i], mx,my, colors[RED]);
			checkfood6();
	}
for(int i=0;i<8;i++){
			DrawRectangle(xf8[i],yf8[i], mx,my, colors[RED]);
			checkfoodBottom();
	}


	
	if (right1){
	
		x+=10;
		left1=false;
		up1=false;
		down1=false;
		}
		  
	
	else 
		
		if(left1){
		right1=false;
		up1=false;
		down1=false;
		x-=10;
	
}


	else 
	
		if(up1){
		y+=10;
		left1=false;
		right1=false;
		down1=true;
	}

	else
		
		if(down1){
		y-=10;
		right1=false;
		up1=false;
		left1=false;
	}
if(!def){
	
	gamePlayer();

}
if(def){

	//vertical down motion

	 if(x==750 and y>=20){
		y-=10;
		gamePlayer();
	}

	//horizontal left motion

	if(y==10 and x>=60){
		x-=10;
		gamePlayer();
	}
	
	//vertical up motion
		
	if(x==50 && y<= 600){
	y+=10;
	gamePlayer();
	}

	if(y>=610){
		x+=10;
		gamePlayer();
	}

}




 //opponents car

//left downward motion

 if(qx==750 and qy<=610){
	qy+=10;
	opponentPlayer();
}
else 
if(qy==620 and qx>=40){
	qx-=10;
	opponentPlayer();
}
 else
	if(qx==30 and qy>=30){
		qy-=10;

	opponentPlayer();
}

//bottom right motion

	else
if(qy==20 and qx<=390){
	qx+=10;
	opponentPlayer();
}

//bottom half up

else if(qx==400 and qy<=90){
	qy+=10;
	opponentPlayer();
}

//lane2 rigth motion

else if(qy==100 and qx>=400 and qx<=650){
	qx+=10;
	opponentPlayer();

}

//lane2 up motion

else if(qx==660 and qy<=530){
	qy+=10;
	opponentPlayer();
}

//lane2 left motion

else if(qy==540 and qx>=150){
	qx-=10;
	  opponentPlayer();
}

//left lane2 downward motion

else if(qx==140 and qy>=100){
	qy-=10;
	opponentPlayer();
}

//lane 2 half right motion

else if(qy==90 and qx<=380){
	qx+=10;
	opponentPlayer();
}

//lane 2 bottom half up motion

else if(qx==390 and qy<=160){
	qy+=10;
	opponentPlayer();
}

//lane 3 right motion

else if(qy==170 and qx>=390 and qx<=570){
	qx+=10;
	opponentPlayer();
}

//lane 3 up motion


else if(qx==580 and qy<=450){
	qy+=10;
	opponentPlayer();
}

//lane 3 top left motion

else if(qy==460 and qx>=230){
	qx-=10;
	opponentPlayer();
}

//lane 3 left down motion

else if(qx==220 and qy>=170){
	qy-=10;
	opponentPlayer();
}

//lane 3 bottom rigth motion

else if(qy==160 and qx<=370){
	qx+=15;
	opponentPlayer();
}


else if(qx==385 and qy<=250){
	qy+=10;
	opponentPlayer();
}

//lane 4 right mortion

else if(qy==260 and qx>=385 and qx<=475){
	qx+=10;
	opponentPlayer();
}

//lane 4 up motion

else if(qx==485 and qy<=370){
	qy+=10;
	opponentPlayer();
}

//lane 4 left motion

else if(qy==380 and qx>=355){
	qx-=10;
	opponentPlayer();
}

//lane 4 left downward motion

else if(qx==345 and qy>=260){
	qy-=10;
	opponentPlayer();
}

//lane 4 right  motion

else if(qy==250 and qx<=375){
	qx+=10;
	opponentPlayer();
}


	// Drawing Arena

	int gap_turn = 60;
	int sx = 20;
	int sy = 10;
	int swidth = 800/2 - gap_turn/2; // half width
	int sheight = 10;
	float *scolor = colors[GREEN];


	DrawRectangle(sx-1, sy-10, swidth-10, sheight, scolor); // bottom left1
	DrawRectangle(sx+90, sy+70, swidth-100, sheight, scolor); // bottom left1
	DrawRectangle(sx+180, sy+150, swidth-190, sheight, scolor); // bottom left1
	DrawRectangle(sx+260, sy+220, swidth-270, sheight, scolor); // bottom left1
	
	

	DrawRectangle(sx + swidth + gap_turn, sy-10, swidth+1, sheight, scolor); // bottom right1
	DrawRectangle(sx + swidth + gap_turn, sy+70, swidth-90, sheight, scolor); // bottom right1
	DrawRectangle(sx + swidth + gap_turn, sy+150, swidth-175, sheight, scolor); // bottom right1
	DrawRectangle(sx + swidth + gap_turn, sy+220, swidth-260, sheight, scolor); // bottom right1



	DrawRectangle(sx+swidth*2+gap_turn, (sy-20)+sheight, sheight*2, swidth-70, scolor); // right1 down1
	DrawRectangle((sx-100)+swidth*2+gap_turn, (sy+60)+sheight, sheight*2, swidth-150, scolor); // right1 down1
	DrawRectangle((sx-185)+swidth*2+gap_turn, (sy+140)+sheight, sheight*2, swidth-230, scolor); // right1 down1
	DrawRectangle((sx-270)+swidth*2+gap_turn, (sy+210)+sheight, sheight*2, swidth-300, scolor); // right1 down1




	DrawRectangle(sx+swidth*2+gap_turn, (sy+sheight)-60+swidth+gap_turn, sheight*2, swidth-70, scolor); // right1 up1
	DrawRectangle((sx-100)+swidth*2+gap_turn, (sy+sheight)-60+swidth+gap_turn, sheight*2, swidth-150, scolor); // right1 up1 mini
	DrawRectangle((sx-185)+swidth*2+gap_turn, (sy+sheight)-60+swidth+gap_turn, sheight*2, swidth-230, scolor); // right1 up1 mini 2
	DrawRectangle((sx-270)+swidth*2+gap_turn, (sy+sheight)-60+swidth+gap_turn, sheight*2, swidth-300, scolor); // right1 up1 mini 2


	DrawRectangle(sx + swidth + gap_turn, sy+670, swidth+1, sheight, scolor); // top right1
	DrawRectangle(sx + swidth + gap_turn, sy+590, swidth-90, sheight, scolor); // top left1 mini
	DrawRectangle(sx + swidth + gap_turn, sy+510, swidth-175, sheight, scolor); // top left1 mini 2
	DrawRectangle(sx + swidth + gap_turn, sy+440, swidth-260, sheight, scolor); // top left1 mini 2


	DrawRectangle(sx-1, sy+670, swidth-10, sheight, scolor); // top left1
	DrawRectangle(sx+90, sy+590, swidth-100, sheight, scolor);//2
	DrawRectangle(sx+180, sy+510, swidth-190, sheight, scolor);//3
	DrawRectangle(sx+260, sy+440, swidth-270, sheight, scolor);//3



	DrawRectangle(sx+370, sy+350, swidth-300, sheight-50, scolor); //centre



	DrawRectangle(sx-sheight*2, (sy+sheight)-60+swidth+gap_turn, sheight*2, swidth-70, scolor); // left1 up1
	DrawRectangle((sx+100)-sheight*2, (sy+sheight)-60+swidth+gap_turn, sheight*2, swidth-150, scolor); // left1 up1 2
	DrawRectangle((sx+190)-sheight*2, (sy+sheight)-60+swidth+gap_turn, sheight*2, swidth-230, scolor); // left1 up1 3
	DrawRectangle((sx+270)-sheight*2, (sy+sheight)-60+swidth+gap_turn, sheight*2, swidth-300, scolor); // left1 up1 4



	DrawRectangle(sx-sheight*2, (sy-20)+sheight, sheight*2, swidth-80, scolor); // left1 down1
	DrawRectangle((sx+100)-sheight*2, sy+sheight+60, sheight*2, swidth-160, scolor); // left1 down1 mini
	DrawRectangle((sx+190)-sheight*2, sy+sheight+140, sheight*2, swidth-240, scolor); // left1 down1 imni 3
	DrawRectangle((sx+270)-sheight*2, (sy+210)+sheight, sheight*2, swidth-300, scolor); // left1 down1 imni 2
	

	checkDodge();


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	if(live<=0){
		gameOver();
	}

	if(scored>=64){
			
			gmaelevel2();

		}


		
	
	glutSwapBuffers(); // do not modify this line.. or draw anything below this line
}

	else if(menu==true){
 
		GameMenu();

	}
		else if(highScore==true){
	
		score();
}
	else if(help==true){
	
		gamehelp();
}
else if(pauseGame==true){
	
		GamePause();
}


}


void NonPrintableKeys(int key, int x, int y) {
	if (key== GLUT_KEY_LEFT /*GLUT_KEY_left1 is constant and contains ASCII for left1 arrow key*/) {
		// what to do when left1 key is pressed...
	def=false;
		up1 =false;
		down1 = false;
		left1 = true; 
		right1= false;
	

	gamePlayer();




	} else if (key== GLUT_KEY_RIGHT /*GLUT_KEY_right1 is constant and contains ASCII for right1 arrow key*/) {

		def=false;
		up1 =false;
		down1 = false;
		left1 = false; 
		right1= true;


	
	gamePlayer();






	} else
	
	 if (key== GLUT_KEY_UP/*GLUT_KEY_up1 is constant and contains ASCII for up1 arrow key*/) {
		

		def=false;
		up1 =true;
		down1 = false;
		left1 = false; 
		right1= false;
		gamePlayer();

	}

	else if (key== GLUT_KEY_DOWN/*GLUT_KEY_down1 is constant and contains ASCII for down1 arrow key*/) {
			def=false;
			up1 =false;
			down1 = true;
			left1 = false; 
			right1= false;
			
	gamePlayer();
}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}

	if (key == 's' || key == 'S'){
		newGame=true;
		menu=false;
		if(highScore==true){
			newGame=false;
		}
		if(help==true){
			newGame=false;
		}
	
	}

	if (key == 'm' || key == 'M'){
		menu=true;
		highScore=false;
		help=false;
		if(newGame=true){
			menu=false;
		}
	
	}
	if (key == 'h' || key == 'H'){
		highScore=true;
		menu=false;
		if(help==true){
			highScore=false;
		}
		
	}
		if (key == 'z' || key == 'Z'){
		menu=false;
		help=true;
	

		
	}
		if (key == 'p' || key == 'P'){
		newGame=false;
		pauseGame=true;


		
	}
	if(key=='a' or key=='A'){
		l=true;
	}
	
			

	
}


void MousePressedAndMoved(int x, int y) {
	
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {

	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (left1, Middle or right1), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left1 button
			{


		//cout << GLUT_down << " " << GLUT_up << endl;

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right1 button
			{

	}
	glutPostRedisplay();

}
/*
 * our gateway main function
 * */

void Timer(int m) {
// implement your functionality here
 glutPostRedisplay();
 // once again w4 tell the library to call our Timer function after next 1000/FPS
 glutTimerFunc(50.0, Timer, 0);
}










int main(int argc, char*argv[]) {


	//b = new Board(60, 60); // create a new board object to use in the Display Function ...

	int width = 850, height = 850; // i have set my window size to be 800 x 600
	//b->InitalizeBoard(width, height);

	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("Dodge 'Em"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.
	
	glutDisplayFunc(GameMenu); // tell library which function to call for drawing Canvas.
	glutDisplayFunc(score); // tell library which function to call for drawing Canvas.
	glutDisplayFunc(gamehelp); // tell library which function to call for drawing Canvas.
	glutDisplayFunc(gameOver); // tell library which function to call for drawing Canvas.
	glutDisplayFunc(GamePause); // tell library which function to call for drawing Canvas.
	
	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for printable ASCII characters
	// glutSpecialFunc(NonPrintableKeysMenu); // tell library which function to call for printable ASCII characters




	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse
	

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* AsteroidS_CPP_ */
