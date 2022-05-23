//============================================================================
// Name        : .cpp
// Author      : Dr. PHD Sir. Usman the great
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Centipede...
//============================================================================

#ifndef CENTIPEDE_CPP_
#define CENTIPEDE_CPP_
//#include "Board.h"
#include "util.h"
#include <iostream>
#include<string>
#include<fstream>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;
// seed the random numbers generator by current time (see the documentation of srand for further help)...
/**
    * To understand comment style:
	* *: To understand small aspects 
	* !: For function descriptions
	* ?: For explinations
	* TODO: For pending work	
	* @param width for pramaeter specific tags.
*/

//TODO: Create blocks funtion.
//TODO: Use refrences.
//TODO: Use function in mouse click to change the pos using ref
//TODO: display gotti in new place.


void remove_all();

void dice_input(int x);
int dice_return();
void turn_input(int x);
int turn_return();
void pos_input(int x);
int pos_return();

void NonPrintableKeys(int key, int x, int y);
void SetCanvasSize(int width, int height);
void Timer(int m);
void MouseClicked(int button, int state, int x, int y);
void MouseMoved(int x, int y);
void MousePressedAndMoved(int x, int y);

void initial_display();
void start_input(unsigned char key, int x, int y);
void names();
void First_turn();
void First_turn_input(unsigned char key, int x, int y);
void dice_time(int);

string display_red_name();
string display_Green_name();
string display_purple_name();
string display_yellow_name();

void Red_name_input(unsigned char key, int x, int y);
void Green_name_input(unsigned char key, int x, int y);
void Purple_name_input(unsigned char key, int x, int y);
void Yellow_name_input(unsigned char key, int x, int y);

int Red_name_length();
int Green_name_length();
int Purple_name_length();
int Yellow_name_length();

int Red_score();
int Green_score();
int Purple_score();
int Yellow_score();

void Red_dice(int num);
void Green_dice(int num);
void Purple_dice(int num);
void Yellow_dice(int num);

void GameDisplay();
void Dice_roll(unsigned char key, int x, int y);
void leader_input(unsigned char key, int x, int y);
void side_board();
void board();
void Dice_display();
int block_file(int T);
string block_file_output();
void Red();
void Green();
void Purple();
void Yellow();

void first_turn_purple(int x);
void first_turn_green(int x);
void first_turn_yellow(int x);
void first_turn_input_red(int x);

int first_turn_red_return();
int first_turn_Green_return();
int first_turn_purple_return();
int first_turn_yellow_return();

void Red_1_pos_input(int x);
int Red_1_pos_return();
void Red_2_pos_input(int x);
int Red_2_pos_return();
void Red_3_pos_input(int x);
int Red_3_pos_return();
void Red_4_pos_input(int x);
int Red_4_pos_return();

void Green_1_pos_input(int x);
int Green_1_pos_return();
void Green_2_pos_input(int x);
int Green_2_pos_return();
void Green_3_pos_input(int x);
int Green_3_pos_return();
void Green_4_pos_input(int x);
int Green_4_pos_return();

void Purple_1_pos_input(int x);
int Purple_1_pos_return();
void Purple_2_pos_input(int x);
int Purple_2_pos_return();
void Purple_3_pos_input(int x);
int Purple_3_pos_return();
void Purple_4_pos_input(int x);
int Purple_4_pos_return();

void Yellow_1_pos_input(int x);
int Yellow_1_pos_return();
void Yellow_2_pos_input(int x);
int Yellow_2_pos_return();
void Yellow_3_pos_input(int x);
int Yellow_3_pos_return();
void Yellow_4_pos_input(int x);
int Yellow_4_pos_return();

double block_number_xpos(int x);
double block_number_ypos(int x);
void Red_1(int x);
void Red_2(int x);
void Red_3(int x);
void Red_4(int x);
void Green_1(int x);
void Green_2(int x);
void Green_3(int x);
void Green_4(int x);
void Purple_1(int x);
void Purple_2(int x);
void Purple_3(int x);
void Purple_4(int x);
void Yellow_1(int x);
void Yellow_2(int x);
void Yellow_3(int x);
void Yellow_4(int x);
void current_input(int x);
int current_return();

/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {

	// ? b = new Board(60, 60); // create a new board object to use in the Display Function ...
	int width = 1200, height = 705; // i have set my window size to be 800 x 600
	// ? b->InitalizeBoard(width, height);
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(-1, -1); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("Usman's Ludo game"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels..
	remove_all();
	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.
	// glutDisplayFunc(initial_display); //? tell library which function to call for drawing Canvas.
	glutDisplayFunc(initial_display);
	glutSpecialFunc(NonPrintableKeys); //? tell library which function to call for non-printable ASCII characters
	// glutKeyboardFunc(PrintableKeys); //? tell library which function to call for printable ASCII characters
	//? This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
/*
!==============================================================================================
!==============================================================================================
!                               NEW SECTION: leader board DISPLAY
!==============================================================================================
!==============================================================================================
*/
void leader_board(){

	glClearColor(0/* Red Component */, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); //*  Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //*Update the colors
	DrawRectangle(0,0,1200,705,colors[PERU]);
	DrawString(400,100,"Press N to continue: ",colors[WHITE]);

	string arr[10];
	string dummy;
	ifstream leader_board;
	leader_board.open("Leader_board.txt");
	for(int z = 0; z < 10; z++){
		getline(leader_board,arr[z], '\n');

	}


	for(int z = 1; z < 11; z++){
		DrawString(300, 705-(z*50), arr[z],colors[BLACK]);
	}

	


	glutKeyboardFunc(leader_input);
	glutSwapBuffers();
}
void leader_input(unsigned char key, int x, int y){

	if (key == 27/* Escape key ASCII*/){
		remove_all();
		exit(1); // exit the program when escape key is pressed.
	}


	if (key == 'n' || key == 'N') //Key for placing the bomb
	{
		glutDisplayFunc(names); //? tell library which function to call for drawing Canvas.
	}

	glutPostRedisplay();
}
/*
!==============================================================================================
!==============================================================================================
!                               NEW SECTION: INITIAL DISPLAY
!==============================================================================================
!==============================================================================================
*/
void initial_display(){
	
	glClearColor(0/* Red Component */, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); //*  Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //*Update the colors
	DrawRectangle(0, 0, 1200 , 705 , colors[PERU]);
	DrawRectangle(150, 100, 700 , 500 , colors[MEDIUM_AQUA_MARINE]);


	DrawString(200,550, "Welcome To The LUDO Game", colors[MISTY_ROSE]);
	DrawString(200,450, "Press S to START the game", colors[MISTY_ROSE]);	
	DrawString(200,350, "Press N to SEE LEADER BOARD the game", colors[MISTY_ROSE]);	
	DrawString(200,2500, "Press ESC to END the game", colors[MISTY_ROSE]);
	

	glutKeyboardFunc(start_input);
	
	glutSwapBuffers(); // do not modify this line..
}
//? Input for initial screen.
void start_input(unsigned char key, int x, int y){

	if (key == 27/* Escape key ASCII*/){
		remove_all();
		exit(1); // exit the program when escape key is pressed.
	}


	if (key == 'S' || key == 's') //Key for placing the bomb
	{
		glutDisplayFunc(names); //? tell library which function to call for drawing Canvas.
	}
	if (key == 'N' || key == 'n') //Key for placing the bomb
	{
		glutDisplayFunc(leader_board); //? tell library which function to call for drawing Canvas.
	}

	glutPostRedisplay();
}

/*
!==============================================================================================
!==============================================================================================
!                               NEW SECTION: Name input for color
!==============================================================================================
!==============================================================================================
*/
//? Display func
void names(){
	string name1,name2,name3,name4;
	int pos=pos_return();
	glClearColor(0/* Red Component */, 0,	/*148.0/255/*Green Component*/ 0.0/*Blue Component*/, 0 /*Alpha component*/); //*  Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //*Update the colors
	DrawRectangle(0, 0, 1200 , 705 , colors[PERU]);

	
	//? Print users selection
		DrawString(200,600, "Please select each players respective colors press enter to skip the color. The program automatically detects number of players.", colors[BLACK]);
		DrawString(300,450, "Red Player: ", colors[BLACK]);
		DrawString(300,400, "Green Player:", colors[BLACK]);
		DrawString(300,350, "Purple player:", colors[BLACK]);
		DrawString(300,300, "Yellow player:", colors[BLACK]);


	//? Take names input.
	if(pos==0){
		DrawString(255,450, "-->", colors[BLACK]);
		glutKeyboardFunc(Red_name_input);
	}
	else if(pos==50){
		DrawString(255,400, "-->", colors[BLACK]);
		glutKeyboardFunc(Green_name_input);
	}
	else if(pos==100){
		DrawString(255,350, "-->", colors[BLACK]);
		glutKeyboardFunc(Purple_name_input);
	}
	else if(pos==150){
		DrawString(255,300, "-->", colors[BLACK]);
		glutKeyboardFunc(Yellow_name_input);
	}	

	//? Draws the entered arrays:
	display_red_name();
	display_Green_name();
	display_purple_name();
	display_yellow_name();	

	glutSwapBuffers(); // do not modify this line..
}

//? Input func
void Red_name_input(unsigned char key, int x, int y) {

	char Red_name;
	int pos=pos_return();	
	if (key == 27/* Escape key ASCII*/){
		remove_all();
		exit(1); // exit the program when escape key is pressed.
	}
	if((key>=65&&key<=90)||(key>=97&&key<=122)){
		Red_name=key;
		ofstream player_1;
		player_1.open("Red_name.txt",ios::app);
		player_1<<Red_name;
		player_1.close();
	}
	if (key == 13){
		pos_input(50);
	}

	glutPostRedisplay();
}
//? Input func
void Green_name_input(unsigned char key, int x, int y) {
	char Green_name;
	int pos=pos_return();
	if (key == 27/* Escape key ASCII*/) {
	remove_all();
		exit(1); // exit the program when escape key is pressed.
	}
	
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}
	if((key>=65&&key<=90)||(key>=97&&key<=122)){
		Green_name=key;
		ofstream player_2;
		player_2.open("Green_name.txt",ios::app);
		player_2<<Green_name;
		player_2.close();
	}
	if (key == 13){
		pos_input(100);
	}
	glutPostRedisplay();
}
//? Input func
void Purple_name_input(unsigned char key, int x, int y) {
	char Purple_name;
	int pos=pos_return();
	if (key == 27/* Escape key ASCII*/) {
	remove_all();
		exit(1); // exit the program when escape key is pressed.
	}
	
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}
	if((key>=65&&key<=90)||(key>=97&&key<=122)){
		Purple_name=key;
		ofstream player_3;
		player_3.open("Purple_name.txt",ios::app);
		player_3<<Purple_name;
		player_3.close();
	}
	if (key == 13){
		pos_input(150);
	}

	glutPostRedisplay();
}
//? Input func
void Yellow_name_input(unsigned char key, int x, int y) {
	char Yellow_name;

	if (key == 27/* Escape key ASCII*/) {
		remove_all();
		exit(1); // exit the program when escape key is pressed.
	}

	if((key>=65&&key<=90)||(key>=97&&key<=122)){
		Yellow_name=key;
		ofstream player_4;
		player_4.open("Yellow_name.txt",ios::app);
		player_4<<Yellow_name;
		player_4.close();
	}
	if (key == 13){
		pos_input(0);
		glutDisplayFunc(First_turn);
	}
	
	glutPostRedisplay();
}
/*
!==============================================================================================
!==============================================================================================
!                               NEW SECTION: GAME DISPLAY
!==============================================================================================
!==============================================================================================
*/
void GameDisplay(){
	//? set the background color using function glClearColor.
	//? to change the background play with the red, green and blue values below.
	//? Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.
	glClearColor(0/* Red Component */, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); //*  Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //*Update the colors

	glutKeyboardFunc(Dice_roll);
	side_board();
	board();
	Dice_display();
	Red();
	Green();
	Purple();
	Yellow();
	Red_1(Red_1_pos_return());
	Red_2(Red_2_pos_return());
	Red_3(Red_3_pos_return());
	Red_4(Red_4_pos_return());

	Green_1(Green_1_pos_return());
	Green_2(Green_2_pos_return());
	Green_3(Green_3_pos_return());
	Green_4(Green_4_pos_return());

	Purple_1(Purple_1_pos_return());
	Purple_2(Purple_2_pos_return());
	Purple_3(Purple_3_pos_return());
	Purple_4(Purple_4_pos_return());

	Yellow_1(Yellow_1_pos_return());
	Yellow_2(Yellow_2_pos_return());	
	Yellow_3(Yellow_3_pos_return());
	Yellow_4(Yellow_4_pos_return());

	
	glutSwapBuffers(); // do not modify this line..
}

void Dice_roll(unsigned char key, int x, int y) {

	int Red=Red_name_length();
	int Green=Green_name_length();
	int Purple=Purple_name_length();
	int Yellow=Yellow_name_length();
	int turn=turn_return();
	int red_check=first_turn_red_return();
	int Green_check=first_turn_Green_return();
	int purple_check=first_turn_purple_return();
	int yellow_check=first_turn_yellow_return();

	if (key == 27/* Escape key ASCII*/){
		remove_all();
		exit(1); // exit the program when escape key is pressed.
	}

	if (key == 32/* Escape key ASCII*/) {
		dice_input(GetRandInRange(1,7));
		int num=dice_return();
		current_input(num);
		//! Turn 1
		if(turn==1){
			if(num==6){
				first_turn_input_red(num);
				red_check=first_turn_red_return();
			}
			if(Red!=0){
				block_file(turn);
				if(red_check==6){
				turn=turn_return();
				Red_dice(num);
				glutPostRedisplay();
				}
				else if(red_check!=6){
					turn_input(2);
				}
				return;
			}
			else{
				turn_input(2);
				turn=turn_return();
			}
		}
	
		//! Turn 2
		if(turn==2){
			if(num==6){
				first_turn_green(num);
				Green_check=first_turn_Green_return();
			}
			if(Green!=0){
				block_file(turn);
				if(Green_check==6){
				turn=turn_return();
				Green_dice(num);
				glutPostRedisplay();
				}
			else if(Green_check!=6){
				turn_input(3);
			}
				return;
			}
			else{
				turn_input(3);
				turn=turn_return();
			}
		}	

		//! Turn 3
		if(turn==3){
			if(num==6){
				first_turn_purple(num);
				purple_check=first_turn_purple_return();
			}
			if(Purple!=0){
				block_file(turn);
				if(purple_check==6){
				turn=turn_return();
				Purple_dice(num);
				glutPostRedisplay();
				}
				else if(purple_check!=6){
					turn_input(4);
				}
				return;
			}
			else{
				turn_input(4);
				turn=turn_return();
			}
		}	

		//! Turn 4
		if(turn==4){
			if(num==6){
				first_turn_yellow(num);
				yellow_check=first_turn_yellow_return();
			}
			if(Yellow!=0){
				block_file(turn);
				if(yellow_check==6){
				turn=turn_return();
				Yellow_dice(num);
				glutPostRedisplay();
				}
				else if(yellow_check!=6){
					turn_input(1);
				}
				return;
			}
			else{
				if(Red!=0){
					if(num==6){
					first_turn_input_red(num);
					red_check=first_turn_red_return();
					}
					block_file(1);
					if(red_check==6){
					turn=turn_return();
					Red_dice(num);
					glutPostRedisplay();
					}
					else if(red_check!=6){
						turn_input(2);
					}
					return;
				}
				else if(Green!=0){
					if(num==6){
					first_turn_green(num);
					Green_check=first_turn_Green_return();
					}
					block_file(2);
					if(Green_check==6){
					turn=turn_return();
					Green_dice(num);
					glutPostRedisplay();
					}
					else if(Green_check!=6){
						turn_input(3);
					}
					return;
				}
				else if(Purple!=0){
					if(num==6){
					first_turn_purple(num);
					purple_check=first_turn_purple_return();
					}
					block_file(3);
					if(purple_check==6){
					turn=turn_return();
					Purple_dice(num);
					glutPostRedisplay();
					}
					else if(purple_check!=6){
						turn_input(4);
					}
					return;
				}
				else{
					turn_input(1);
				}
			}
		}
	}


	glutPostRedisplay();
}

void side_board(){
	string name1,name2,name3,name4,test;
	test=block_file_output();
	
	//? Backgroud Rect
	DrawRectangle(705, 0, 495 , 705 , colors[PERU]);
	
	//? Title
	DrawString(880,680,"---LUDO---",colors[BLACK]);
	if(test=="1"){
			DrawSquare(707,600,15,colors[BLACK]);
	}
	if(test=="2"){
			DrawSquare(707,570,15,colors[BLACK]);
	}
	if(test=="3"){
			DrawSquare(707,540,15,colors[BLACK]);
	}
	if(test=="4"){
			DrawSquare(707,510,15,colors[BLACK]);
	}

	name1=display_red_name();
	name2=display_Green_name();
	name3=display_purple_name();
	name4=display_yellow_name();
	DrawString(750,600,name1,colors[FIREBRICK]);
	DrawString(750,570,name2,colors[MEDIUM_AQUA_MARINE]);
	DrawString(750,540,name3,colors[DARK_SLATE_BLUE]);
	DrawString(750,510,name4,colors[ORANGE_RED]);

	string F=Num2Str(Red_score());
	if(Red_score()!='0'){
	DrawString(900,600,F,colors[BLACK]);
	}


	string W=Num2Str(Green_score());
	if(Green_score()!=0){
	DrawString(900,570,W,colors[BLACK]);
	}
	


	string X=Num2Str(Purple_score());
	if(Purple_score()!=0){
	DrawString(900,540,X,colors[BLACK]);
	}
	

	string Z= Num2Str(Yellow_score());
	if(Yellow_score()!=0){
	DrawString(900,510,Z,colors[BLACK]);
	}

}

int block_file(int T){
	std::ofstream del;
	del.open("Block.txt", std::ofstream::out | std::ofstream::trunc);
	del.close();

	ofstream block;
	block.open("Block.txt",ios::app);
		block<<T;
	block.close();
}
string block_file_output(){
	string Q;
	ifstream Block; //opening user name file
		Block.open("Block.txt");
		while( (! Block.fail( )) && (! Block.eof( )) ){
			getline(Block,Q); //extracting name of user into variable
		}
    Block.close();
	return Q;
}

void board(){

	DrawLine(1200,705,1200,0,3,colors[SALMON]);
	DrawLine(705,705,705,0,2,colors[SALMON]);


	//! Bottom left square
	DrawSquare( 0 , 0 ,282,colors[FIREBRICK]);

	//? Square inside square
	DrawRoundRect(47, 47, 188 , 188 , colors[WHITE] ,10);

	//? small squares(Middle-bottom-left)
	DrawSquare( 282 , 0 , 47,colors[WHITE]);
	DrawSquare( 282 , 47 , 47,colors[FIREBRICK]);
	DrawSquare( 282 , 94 , 47,colors[WHITE]);
	DrawSquare( 282 , 141 , 47,colors[WHITE]);
	DrawSquare( 282 , 188 , 47,colors[WHITE]);
	DrawSquare( 282 , 235 , 47,colors[WHITE]);

	//? small squares(Middle-bottom-middle)
	DrawSquare( 329 , 0 , 47,colors[WHITE]);
	DrawSquare( 329 , 47 , 47,colors[FIREBRICK]);
	DrawSquare( 329 , 94 , 47,colors[FIREBRICK]);
	DrawSquare( 329 , 141 , 47,colors[FIREBRICK]);
	DrawSquare( 329 , 188 , 47,colors[FIREBRICK]);
	DrawSquare( 329 , 235 , 47,colors[FIREBRICK]);

	//? small squares(Middle-bottom-right)
	DrawSquare( 376 , 0 , 47,colors[WHITE]);
	DrawSquare( 376 , 47 , 47,colors[WHITE]);
	DrawSquare( 376 , 94 , 47,colors[BURLY_WOOD]);
	DrawSquare( 376 , 141 , 47,colors[WHITE]);
	DrawSquare( 376 , 188 , 47,colors[WHITE]);
	DrawSquare( 376 , 235 , 47,colors[WHITE]);

	//! top left square
	DrawSquare( 0 , 423 ,282,colors[MEDIUM_AQUA_MARINE]);

	//? Square inside square
	DrawRoundRect(47, 470, 188 , 188 , colors[WHITE] ,10);

	//? small squares(left-bottom)
	DrawSquare( 0 , 282 , 47,colors[WHITE]);
	DrawSquare( 47 , 282 , 47,colors[WHITE]);
	DrawSquare( 94 , 282 , 47,colors[BURLY_WOOD]);
	DrawSquare( 141 , 282 , 47,colors[WHITE]);
	DrawSquare( 188 , 282 , 47,colors[WHITE]);
	DrawSquare( 235 , 282 , 47,colors[WHITE]);

	//? small squares(left-middle)
	DrawSquare( 0 ,329 , 47,colors[WHITE]);
	DrawSquare( 47 , 329 , 47,colors[MEDIUM_AQUA_MARINE]);
	DrawSquare( 94 , 329, 47,colors[MEDIUM_AQUA_MARINE]);
	DrawSquare( 141 , 329 , 47,colors[MEDIUM_AQUA_MARINE]);
	DrawSquare( 188 , 329 , 47,colors[MEDIUM_AQUA_MARINE]);
	DrawSquare( 235 , 329 , 47,colors[MEDIUM_AQUA_MARINE]);

	//? small squares(left-top)
	DrawSquare( 0 , 376 , 47,colors[WHITE]);
	DrawSquare( 47 , 376 , 47,colors[MEDIUM_AQUA_MARINE]);
	DrawSquare( 94 , 376 , 47,colors[WHITE]);
	DrawSquare( 141 , 376 , 47,colors[WHITE]);
	DrawSquare( 188 , 376 , 47,colors[WHITE]);
	DrawSquare( 235 , 376 , 47,colors[WHITE]);

	//! top right square
	DrawSquare( 423 , 423 ,282,colors[DARK_SLATE_BLUE]);

	//? Square inside square
	DrawRoundRect(470, 470, 188 , 188 , colors[WHITE] ,10);

	//? small squares(Middle-top-left)
	DrawSquare( 282 , 705-47 , 47,colors[WHITE]);
	DrawSquare( 282 , 705-94 , 47,colors[WHITE]);
	DrawSquare( 282 , 705-141 , 47,colors[BURLY_WOOD]);
	DrawSquare( 282 , 705-188 , 47,colors[WHITE]);
	DrawSquare( 282 , 705-235 , 47,colors[WHITE]);
	DrawSquare( 282 , 705-282 , 47,colors[WHITE]);

	//? small squares(Middle-top-middle)
	DrawSquare( 329 , 705-47 , 47,colors[WHITE]);
	DrawSquare( 329 , 705-94 , 47,colors[DARK_SLATE_BLUE]);
	DrawSquare( 329 , 705-141 , 47,colors[DARK_SLATE_BLUE]);
	DrawSquare( 329 , 705-188 , 47,colors[DARK_SLATE_BLUE]);
	DrawSquare( 329 , 705-235 , 47,colors[DARK_SLATE_BLUE]);
	DrawSquare( 329 , 705-282 , 47,colors[DARK_SLATE_BLUE]);

	//? small squares(Middle-top-right)
	DrawSquare( 376 , 705-47 , 47,colors[WHITE]);
	DrawSquare( 376 , 705-94 , 47,colors[DARK_SLATE_BLUE]);
	DrawSquare( 376 , 705-141 , 47,colors[WHITE]);
	DrawSquare( 376 , 705-188 , 47,colors[WHITE]);
	DrawSquare( 376 , 705-235 , 47,colors[WHITE]);
	DrawSquare( 376 , 705-282 , 47,colors[WHITE]);


	//! bottom right square
	DrawSquare( 423 , 0 ,282,colors[ORANGE_RED]);
	
	//? Square inside square
	DrawRoundRect(470, 47, 188 , 188 , colors[WHITE] ,10);

	//? small squares(left-bottom)
	DrawSquare( 423 , 282 , 47,colors[WHITE]);
	DrawSquare( 470 , 282 , 47,colors[WHITE]);
	DrawSquare( 517 , 282 , 47,colors[WHITE]);
	DrawSquare( 564 , 282 , 47,colors[WHITE]);
	DrawSquare( 611 , 282 , 47,colors[ORANGE_RED]);
	DrawSquare( 658 , 282 , 47,colors[WHITE]);

	//? small squares(left-middle)
	DrawSquare( 423 ,329 , 47,colors[ORANGE_RED]);
	DrawSquare( 470 , 329 , 47,colors[ORANGE_RED]);
	DrawSquare( 517 , 329, 47,colors[ORANGE_RED]);
	DrawSquare( 564 , 329 , 47,colors[ORANGE_RED]);
	DrawSquare( 611 , 329 , 47,colors[ORANGE_RED]);
	DrawSquare( 658 , 329 , 47,colors[WHITE]);

	//? small squares(left-top)
	DrawSquare( 423 , 376 , 47,colors[WHITE]);
	DrawSquare( 470 , 376 , 47,colors[WHITE]);
	DrawSquare( 517 , 376 , 47,colors[WHITE]);
	DrawSquare( 564 , 376 , 47,colors[BURLY_WOOD]);
	DrawSquare( 611 , 376 , 47,colors[WHITE]);
	DrawSquare( 658 , 376 , 47,colors[WHITE]);

	

	DrawTriangle( 282, 282 , 423, 282 , 352.5 , 352.5, colors[FIREBRICK]); 

	DrawTriangle( 423, 282, 423, 423, 352.5 , 352.5, colors[ORANGE_RED]);

	DrawTriangle( 282, 423 , 423, 423, 352.5 , 352.5, colors[DARK_SLATE_BLUE]); 

	DrawTriangle( 282, 423 , 282, 282, 352.5 , 352.5, colors[MEDIUM_AQUA_MARINE]);


}

void Dice_display(){
	int dice=dice_return();
	if(dice==0){
		DrawRoundRect(900, 300, 100 , 100 , colors[OLD_LACE] ,10);
	}
	if(dice==1){
		DrawRoundRect(900, 300, 100 , 100 , colors[OLD_LACE] ,10);
		DrawCircle(950 , 350 ,10,colors[BLACK]);
	}
	if(dice==2){
		DrawRoundRect(900, 300, 100 , 100 , colors[OLD_LACE] ,10);
		DrawCircle(920 , 320 ,10,colors[BLACK]);
		DrawCircle(980 , 380 ,10,colors[BLACK]);
	}
	if(dice==3){
		DrawRoundRect(900, 300, 100 , 100 , colors[OLD_LACE] ,10);
		DrawCircle(920 , 320 ,10,colors[BLACK]);
		DrawCircle(980 , 380 ,10,colors[BLACK]);
		DrawCircle(950 , 350 ,10,colors[BLACK]);
	}
	if(dice==4){
		DrawRoundRect(900, 300, 100 , 100 , colors[OLD_LACE] ,10);
		DrawCircle(920 , 320 ,10,colors[BLACK]);
		DrawCircle(980 , 380 ,10,colors[BLACK]);
		DrawCircle(980 , 320 ,10,colors[BLACK]);
		DrawCircle(920 , 380 ,10,colors[BLACK]);

	}
	if(dice==5){
		DrawRoundRect(900, 300, 100 , 100 , colors[OLD_LACE] ,10);
		DrawCircle(920 , 320 ,10,colors[BLACK]);
		DrawCircle(980 , 380 ,10,colors[BLACK]);
		DrawCircle(980 , 320 ,10,colors[BLACK]);
		DrawCircle(920 , 380 ,10,colors[BLACK]);
		DrawCircle(950 , 350 ,10,colors[BLACK]);
	}
	if(dice==6 ){
		DrawRoundRect(900, 300, 100 , 100 , colors[OLD_LACE] ,10);
		DrawCircle(980 , 380 ,10,colors[BLACK]);
		DrawCircle(980 , 350 ,10,colors[BLACK]);
		DrawCircle(980 , 320 ,10,colors[BLACK]);

		DrawCircle(920 , 380 ,10,colors[BLACK]);
		DrawCircle(920 , 350 ,10,colors[BLACK]);
		DrawCircle(920 , 320 ,10,colors[BLACK]);
	}

}
/*
!==============================================================================================
!==============================================================================================
!                               NEW SECTION: Movig
!==============================================================================================
!==============================================================================================
*/

/*
!==============================================================================================
!==============================================================================================
!                               NEW SECTION: Find length of names
!==============================================================================================
!==============================================================================================
*/

int Red_name_length(){
	//? Checking to see if player exists.
	string length;
	ifstream Score_1; //opening user name file
		Score_1.open("Red_name.txt");
		while( (! Score_1.fail( )) && (! Score_1.eof( )) ){
			getline(Score_1,length); //extracting name of user into variable
		}
    Score_1.close();
	return length.size();
}
int Green_name_length(){
	//? Checking to see if player exists.
	string length;
	ifstream Score_1; //opening user name file
		Score_1.open("Green_name.txt");
		while( (! Score_1.fail( )) && (! Score_1.eof( )) ){
			getline(Score_1,length); //extracting name of user into variable
		}
    Score_1.close();
	return length.size();
}
int Purple_name_length(){
	//? Checking to see if player exists.
	string length;
	ifstream Score_1; //opening user name file
		Score_1.open("Purple_name.txt");
		while( (! Score_1.fail( )) && (! Score_1.eof( )) ){
			getline(Score_1,length); //extracting name of user into variable
		}
    Score_1.close();
	return length.size();
}
int Yellow_name_length(){
	//? Checking to see if player exists.
	string length;
	ifstream Score_1; //opening user name file
		Score_1.open("Yellow_name.txt");
		while( (! Score_1.fail( )) && (! Score_1.eof( )) ){
			getline(Score_1,length); //extracting name of user into variable
		}
    Score_1.close();
	return length.size();
}
/*
!==============================================================================================
!==============================================================================================
!                               NEW SECTION: Getting rid of global varaibles
!==============================================================================================
!==============================================================================================
*/

//? Dice val
void dice_input(int x){
	std::ofstream del;
	del.open("Dice.txt", std::ofstream::out | std::ofstream::trunc);
	del.close();
	ofstream Dice;
	Dice.open("Dice.txt",ios::app);
		for(int i=0;i<x;i++)
			Dice<<"1";
	Dice.close();
}
int dice_return(){
	string size;
	ifstream Dice; //opening user name file
		Dice.open("Dice.txt");
		while((! Dice.fail( ) ) && ( ! Dice.eof( ) ) ){
			getline(Dice,size); //extracting name of user into variable
		}
    Dice.close();
	int x= size.size();
	return x;
}

//? Turn val
void turn_input(int x){
	std::ofstream del;
	del.open("Turn.txt", std::ofstream::out | std::ofstream::trunc);
	del.close();

	ofstream Turn;
	Turn.open("Turn.txt",ios::app);
		for(int i=0;i<x;i++)
			Turn<<"1";
	Turn.close();
}
int turn_return(){
	string size;
	ifstream Turn; //opening user name file
		Turn.open("Turn.txt");
		while((! Turn.fail( ) ) && ( ! Turn.eof( ) ) ){
			getline(Turn,size); //extracting name of user into variable
		}
    Turn.close();
	int x= size.size();
	return x;
}

//?pos val
void pos_input(int x){
	std::ofstream del;
	del.open("Pos.txt", std::ofstream::out | std::ofstream::trunc);
	del.close();
	// cout<<x<<" :Pos input"<<endl;
	ofstream Pos;
	Pos.open("Pos.txt",ios::app);
		for(int i=0;i<x;i++)
			Pos<<"1";
	Pos.close();
}
int pos_return(){
	string size;
	ifstream Pos; //opening user name file
		Pos.open("Pos.txt");
		while((! Pos.fail( ) ) && ( ! Pos.eof( ) ) ){
			getline(Pos,size); //extracting name of user into variable
		}
    Pos.close();
	int x= size.size();
	// cout<<x<<" :Pos output"<<endl;
	return x;
}

//?first six val
void first_turn_input_red(int x){
	std::ofstream del;
	del.open("first_turn_red.txt", std::ofstream::out | std::ofstream::trunc);
	del.close();

	ofstream Pos;
	Pos.open("first_turn_red.txt",ios::app);
		for(int i=0;i<x;i++)
			Pos<<"1";
	Pos.close();
}
int first_turn_red_return(){ 
	string size;
	ifstream Pos; //opening user name file
		Pos.open("first_turn_red.txt");
		while((! Pos.fail( ) ) && ( ! Pos.eof( ) ) ){
			getline(Pos,size); //extracting name of user into variable
		}
    Pos.close();
	int x= size.size();
	// cout<<x<<" :Pos output"<<endl;
	return x;
}
//?Second six val
void first_turn_green(int x){
	std::ofstream del;
	del.open("first_turn_green.txt", std::ofstream::out | std::ofstream::trunc);
	del.close();

	ofstream Pos;
	Pos.open("first_turn_green.txt",ios::app);
		for(int i=0;i<x;i++)
			Pos<<"1";
	Pos.close();
}
int first_turn_Green_return(){ 
	string size;
	ifstream Pos; //opening user name file
		Pos.open("first_turn_green.txt");
		while((! Pos.fail( ) ) && ( ! Pos.eof( ) ) ){
			getline(Pos,size); //extracting name of user into variable
		}
    Pos.close();
	int x= size.size();
	// cout<<x<<" :Pos output"<<endl;
	return x;
}
//?first six val
void first_turn_purple(int x){
	std::ofstream del;
	del.open("first_turn_purple.txt", std::ofstream::out | std::ofstream::trunc);
	del.close();

	ofstream Pos;
	Pos.open("first_turn_purple.txt",ios::app);
		for(int i=0;i<x;i++)
			Pos<<"1";
	Pos.close();
}
int first_turn_purple_return(){ 
	string size;
	ifstream Pos; //opening user name file
		Pos.open("first_turn_purple.txt");
		while((! Pos.fail( ) ) && ( ! Pos.eof( ) ) ){
			getline(Pos,size); //extracting name of user into variable
		}
    Pos.close();
	int x= size.size();
	// cout<<x<<" :Pos output"<<endl;
	return x;
}
//?first six val
void first_turn_yellow(int x){
	std::ofstream del;
	del.open("first_turn_yellow.txt", std::ofstream::out | std::ofstream::trunc);
	del.close();

	ofstream Pos;
	Pos.open("first_turn_yellow.txt",ios::app);
		for(int i=0;i<x;i++)
			Pos<<"1";
	Pos.close();
}
int first_turn_yellow_return(){ 
	string size;
	ifstream Pos; //opening user name file
		Pos.open("first_turn_yellow.txt");
		while((! Pos.fail( ) ) && ( ! Pos.eof( ) ) ){
			getline(Pos,size); //extracting name of user into variable
		}
    Pos.close();
	int x= size.size();
	// cout<<x<<" :Pos output"<<endl;
	return x;
}
/*
!==============================================================================================
!==============================================================================================
!                            NEW SECTION: See who gets tp play first:
!==============================================================================================
!==============================================================================================
*/
void First_turn(){
	
	glClearColor(0/* Red Component */, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); //*  Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //*Update the colors
	DrawRectangle(0, 0, 1200 , 705 , colors[PERU]);
	int Red=Red_name_length();
	int Green=Green_name_length();
	int Purple=Purple_name_length();
	int Yellow=Yellow_name_length();

	DrawString(300,550, "Get ready to start!!!", colors[MISTY_ROSE]);
	DrawString(300,500, "Computer now is rolling the dice", colors[MISTY_ROSE]);
	DrawString(300,450, "Press enter to see who starts", colors[MISTY_ROSE]);
	int x=0;
	dice_input(GetRandInRange(1,7));
	Dice_display();
	glutTimerFunc(0,dice_time,0);
	while(1){
			int start=GetRandInRange(1,5);
			if(start==1&&Red!=0){
				DrawString(300,400, "Red player will start!", colors[MISTY_ROSE]);
				turn_input(1);
				break;
			}
			if(start==2&&Green!=0){
				DrawString(300,400, "Green player will start!", colors[MISTY_ROSE]);
				turn_input(2);
				break;
			}
			if(start==3&&Purple!=0){
				DrawString(300,400, "Purple player will start!", colors[MISTY_ROSE]);
				turn_input(3);
				break;
			}
			if(start==4&&Yellow!=0){
				DrawString(300,400, "Yellow player will start!", colors[MISTY_ROSE]);
				turn_input(4);
				break;
			}
		}
	glutKeyboardFunc(First_turn_input);
	glutSwapBuffers();
}
void dice_time(int){
	glutPostRedisplay();
	glutTimerFunc(0,dice_time,0);
}
void First_turn_input(unsigned char key, int x, int y){
	if(key==13){
		sleep(1.5);
		glutDisplayFunc(GameDisplay);
	}
}

/*
!==============================================================================================
!==============================================================================================
!                               NEW SECTION: Display names
!==============================================================================================
!==============================================================================================
*/
//? To display Red name.
string display_red_name(){
	string name1;
	ifstream player_1; //opening user name file
		player_1.open("Red_name.txt");
		while((! player_1.fail( ) ) && ( ! player_1.eof( ) ) ){
			getline(player_1,name1); //extracting name of user into variable
			DrawString(450,450,name1,colors[FIREBRICK]);
		}
    player_1.close();
	return name1;
}
//? To display Green name.
string display_Green_name(){
	string name2;
	ifstream player_2; //opening user name file
		player_2.open("Green_name.txt");
		while((! player_2.fail( ) ) && ( ! player_2.eof( ) ) ){
			getline(player_2,name2); //extracting name of user into variable
			DrawString(450,400,name2,colors[MEDIUM_AQUA_MARINE]);
		}
    player_2.close();
	return name2;
}
//? To display Purple name.
string display_purple_name(){
	string name3;
	ifstream player_3; //opening user name file
		player_3.open("Purple_name.txt");
		while((! player_3.fail( ) ) && ( ! player_3.eof( ) ) ){
			getline(player_3,name3); //extracting name of user into variable
			DrawString(450,350,name3,colors[DARK_SLATE_BLUE]);
		}
    player_3.close();	
	return name3;
}
//? To display Yellow name.
string display_yellow_name(){
	string name4;
	ifstream player_4; //opening user name file
		player_4.open("Yellow_name.txt");
		while((! player_4.fail( ) ) && ( ! player_4.eof( ) ) ){
			getline(player_4,name4); //extracting name of user into variable
			DrawString(450,300,name4,colors[ORANGE_RED]);
		}
    player_4.close();
	return name4;
}

/*
!==============================================================================================
!==============================================================================================
!                               NEW SECTION: Find score
!==============================================================================================
!==============================================================================================
*/
int Red_score(){
	//? Checking to see if player exists.
	string length;
	ifstream Score_1; //opening user name file
		Score_1.open("Score_Red.txt");
		while( (! Score_1.fail( )) && (! Score_1.eof( )) ){
			getline(Score_1,length); //extracting name of user into variable
		}
    Score_1.close();
	return length.size();
}
int Green_score(){
	//? Checking to see if player exists.
	string length;
	ifstream Score_1; //opening user name file
		Score_1.open("Score_Green.txt");
		while( (! Score_1.fail( )) && (! Score_1.eof( )) ){
			getline(Score_1,length); //extracting name of user into variable
		}
    Score_1.close();
	return length.size();
}
int Purple_score(){
	//? Checking to see if player exists.
	string length;
	ifstream Score_1; //opening user name file
		Score_1.open("Score_Purple.txt");
		while( (! Score_1.fail( )) && (! Score_1.eof( )) ){
			getline(Score_1,length); //extracting name of user into variable
		}
    Score_1.close();
	return length.size();
}
int Yellow_score(){
	//? Checking to see if player exists.
	string length;
	ifstream Score_1; //opening user name file
		Score_1.open("Score_Yellow.txt");
		while( (! Score_1.fail( )) && (! Score_1.eof( )) ){
			getline(Score_1,length); //extracting name of user into variable
		}
    Score_1.close();
	return length.size();
}

/*
!==============================================================================================
!==============================================================================================
!                               NEW SECTION: Store score
!==============================================================================================
!==============================================================================================
*/
//? To add score
void Red_dice(int num){
	int dice=dice_return();
	int turn=turn_return();
	int pos=pos_return();
	if(dice==6||pos==12||pos==6){
				turn_input(1);
				pos+=dice;
				pos_input(pos);
				num=0;
					if(pos>6&&pos<12){
						num=pos;
						turn_input(2);
						pos_input(0);
					}				
					if(pos>12&&pos<18){
						num=pos;
						turn_input(2);
						pos_input(0);
					}
					if(pos==18){
						turn_input(2);
						pos_input(0);
						num=0;
					}
			}
				ofstream Red;
				Red.open("Score_Red.txt",ios::app);
					for(int i=0;i<num;i++)
						Red<<"1";
				Red.close();
				if(num>0&&num<6){
					turn_input(2);
				}
}
//? To add score
void Green_dice(int num){
	int dice=dice_return();
	int turn=turn_return();
	int pos=pos_return();
	if(dice==6||pos==12||pos==6){
				turn_input(2);
				pos+=dice;
				pos_input(pos);
				num=0;
					if(pos>6&&pos<12){
						num=pos;
						turn_input(3);
						pos_input(0);
					}				
					if(pos>12&&pos<18){
						num=pos;
						turn_input(3);
						pos_input(0);
					}
					if(pos==18){
						turn_input(3);
						pos_input(0);
						num=0;
					}
			}
				ofstream Green;
				Green.open("Score_Green.txt",ios::app);
					for(int i=0;i<num;i++)
						Green<<"1";
				Green.close();
				if(num>0&&num<6){
					turn_input(3);
				}
}
//? To add score
void Purple_dice(int num){
	int dice=dice_return();
	int turn=turn_return();
	int pos=pos_return();
	if(dice==6||pos==12||pos==6){
				turn_input(3);
				pos+=dice;
				pos_input(pos);
				num=0;
					if(pos>6&&pos<12){
						num=pos;
						turn_input(4);
						pos_input(0);
					}				
					if(pos>12&&pos<18){
						num=pos;
						turn_input(4);
						pos_input(0);
					}
					if(pos==18){
						turn_input(4);
						pos_input(0);
						num=0;
					}
			}
				ofstream Purple;
				Purple.open("Score_Purple.txt",ios::app);
					for(int i=0;i<num;i++)
						Purple<<"1";
				Purple.close();
				if(num>0&&num<6){
					turn_input(4);
				}
}
//? To add score
void Yellow_dice(int num){
	int dice=dice_return();
	int turn=turn_return();
	int pos=pos_return();
	if(dice==6||pos==12||pos==6){
				turn_input(4);
				pos+=dice;
				pos_input(pos);
				num=0;
					if(pos>6&&pos<12){
						num=pos;
						turn_input(1);
						pos_input(0);
					}				
					if(pos>12&&pos<18){
						num=pos;
						turn_input(1);
						pos_input(0);
					}
					if(pos==18){
						turn_input(1);
						pos_input(0);
						num=0;
					}
			}
				ofstream Yellow;
				Yellow.open("Score_Yellow.txt",ios::app);
					for(int i=0;i<num;i++)
						Yellow<<"1";
				Yellow.close();
				if(num>0&&num<6){
					turn_input(1);
				}
}
/*
!==============================================================================================
!==============================================================================================
!                               NEW SECTION: For peices display
!==============================================================================================
!==============================================================================================
*/
void Red(){
	/*
	TODO: 1) Give each peice a position.
	TODO: 2) Be able to change position.
	TODO: 3) Be able to send back pieces if pos==18.
	*/
	//? Red circles
	DrawCircle(94 , 94 ,20,colors[FIREBRICK]); //? Bottom-left
	DrawCircle(188 , 94 ,20,colors[FIREBRICK]); //? Bottom-right
	DrawCircle(94 , 188 ,20,colors[FIREBRICK]); //? Top-left
	DrawCircle(188 , 188 ,20,colors[FIREBRICK]); //? Top-right
}
void Purple(){
	//? purple circles
	DrawCircle(517 , 517 ,20,colors[DARK_SLATE_BLUE]); //? Bottom-left
	DrawCircle(611 , 517 ,20,colors[DARK_SLATE_BLUE]); //? Bottom-right
	DrawCircle(517 , 610.5 ,20,colors[DARK_SLATE_BLUE]); //? Top-left
	DrawCircle(611 , 610.5 ,20,colors[DARK_SLATE_BLUE]); //? Top-right
}
void Green(){
	//? Green circles
	DrawCircle(94 , 517 ,20,colors[MEDIUM_AQUA_MARINE]); //? Bottom-left
	DrawCircle(188 , 517 ,20,colors[MEDIUM_AQUA_MARINE]); //? Bottom-right
	DrawCircle(94 , 610.5 ,20,colors[MEDIUM_AQUA_MARINE]); //? Top-left
	DrawCircle(188 , 610.5 ,20,colors[MEDIUM_AQUA_MARINE]); //? Top-right
}
void Yellow(){
	//? yellow circles
	DrawCircle(517 , 94 ,20,colors[ORANGE_RED]); //? Bottom-left
	DrawCircle(611 , 94 ,20,colors[ORANGE_RED]); //? Bottom-right
	DrawCircle(517 , 188 ,20,colors[ORANGE_RED]); //? Top-left
	DrawCircle(611 , 188 ,20,colors[ORANGE_RED]); //? Top-right
}
/*
!==============================================================================================
!==============================================================================================
!      NEW SECTION: To give each block a number and coordinate and return its coordinates
!==============================================================================================
!==============================================================================================
*/
double block_number_xpos(int x){
	//?For values greater than 
	if(x<200){
	if(x>52){
		x=x-52;
	}

	//? Bottom-left
	if(x>=1&&x<=6){
		return 305.5;
	}

	//? left-bottom
	if(x==7){
		return 258.5;
	}
	if(x==8){
		return 211.5;
	}
	if(x==9){
		return 164.5;
	}
	if(x==10){
		return 117.5;
	}
	if(x==11){
		return 70.5;
	}
	if(x==12){
		return 23.5;
	}

	//?left middle
	if(x==13){
		return 23.5;
	}

	//?left-top
	if(x==14){
		return 23.5;
	}
	if(x==15){
		return 70.5;
	}
	if(x==16){
		return 117.5;
	}
	if(x==17){
		return 164.5;
	}
	if(x==18){
		return 211.5;
	}
	if(x==19){
		return 258.5;
	}

	//?Top-left
	if(x>=20&&x<=25){
		return 305.5;
	}

	//?Top-middle
	if(x==26){
		return 352.5;
	}

	//?Top-right
	if(x>=27&&x<=32){
		return 399.5;
	}

	//?Right-top
	if(x==33){
		return 446.5;
	}
	if(x==34){
		return 493.5;
	}
	if(x==35){
		return 540.5;
	}
	if(x==36){
		return 587.5;
	}
	if(x==37){
		return 634.5;
	}
	if(x==38){
		return 681.5;
	}

	//?Right-middle
	if(x==39){
		return 681.5;
	}
	//?right bottom
	if(x==40){
		return 681.5;
	}
	if(x==41){
		return 634.5;
	}
	if(x==42){
		return 587.5;
	}
	if(x==43){
		return 540.5;
	}
	if(x==44){
		return 493.5;
	}
	if(x==45){
		return 446.5;
	}

	//?bottom-right
	if(x>=46&&x<=51){
		return 399.5;
	}

	//?bottom-middle
	if(x==52){
		return 352.5;
	}
	}
	else if(x>200&&x<300){
		if(x>=252&&x<=258){
			return 352.5;
		}
	}
	else if(x>300&&x<400){
		if(x==366){
			return 70.5;
		}
		if(x==367){
			return 117.5;
		}
		if(x==368){
			return 164.5;
		}
		if(x==369){
			return 211.5;
		}
		if(x==370){
			return 258.5;
		}
		if(x==371){
			return 305.5;
		}
	}
	else if(x>400&&x<500){
		if(x>=478&&x<=483){
			return 352.5;
		}
	}
	else if(x>591&&x<=597){
		if(x==592){
			return 634.5;
		}
		if(x==593){
			return 587.5;
		}
		if(x==594){
			return 540.5;
		}
		if(x==595){
			return 493.5;
		}
		if(x==596){
			return 446.5;
		}
	}
}


double block_number_ypos(int x){
	//?For values greater than 
	if(x<200){
	if(x>52){
		x=x-52;
	}

	//?Bottom-middle
	if(x==1){
		return 23.5;
	}
	if(x==2){
		return 70.5;
	}
	if(x==3){
		return 117.5;
	}
	if(x==4){
		return 164.5;
	}
	if(x==5){
		return 211.5;
	}
	if(x==6){
		return 258.5;
	}

	//?Left-bottom
	if(x>=7&&x<=12){
		return 305.5;
	}

	//?Left-middle
	if(x==13){
		return 352.5;
	}

	//?Left-top
	if(x>=14&&x<=19){
		return 399.5;
	}

	//?Top-left
	if(x==20){
		return 446.5;
	}
	if(x==21){
		return 493.5;
	}
	if(x==22){
		return 540.5;
	}
	if(x==23){
		return 587.5;
	}
	if(x==24){
		return 634.5;
	}
	if(x==25){
		return 681.5;
	}

	//?top-middle
	if(x==26){
		return 681.5;
	}

	//?top-right
	if(x==27){
		return 681.5;
	}
	if(x==28){
		return 634.5;
	}
	if(x==29){
		return 587.5;
	}
	if(x==30){
		return 540.5;
	}
	if(x==31){
		return 493.5;
	}
	if(x==32){
		return 446.5;
	}

	//?right-top
	if(x>=33&&x<=38){
		return 399.5;
	}

	//?right-middle
	if(x==39){
		return 352.5;
	}

	//?right-bottom
	if(x>=40&&x<=45){
		return 305.5;
	}

	//?bottom-right
	if(x==51){
		return 23.5;
	}
	if(x==50){
		return 70.5;
	}
	if(x==49){
		return 117.5;
	}
	if(x==48){
		return 164.5;
	}
	if(x==47){
		return 211.5;
	}
	if(x==46){
		return 258.5;
	}

	//?bottom-middle
	if(x==52){
		return 23.5;
	}
	}
	else if(x>=253&&x<=258){
		if(x==253){
			return 70.5;
		}
		if(x==254){
			return 117.5;
		}
		if(x==255){
			return 164.5;
		}
		if(x==256){
			return 211.5;
		}
		if(x==257){
			return 258.5;
		}
		if(x==258){
			return 305.5;
		}
	}
	else if(x>300&&x<400){
		if (x>365&&x<372){
			return 352.5;
		}
		
	}
	else if(x>400&&x<500){
		if(x==478){
			return 681.5;
		}
		if(x==479){
			return 634.5;
		}
		if(x==480){
			return 587.5;
		}
		if(x==481){
			return 540.5;
		}
		if(x==482){
			return 493.5;
		}
		if(x==483){
			return 446.5;
		}
	}
	else if(x>591&&x<=597){
		return 352.5;
	}
}
/*
!==============================================================================================
!==============================================================================================
!                               NEW SECTION: For peices movement
!==============================================================================================
!==============================================================================================
*/
//DrawCircle(94 , 94 ,20,colors[FIREBRICK]); //? Bottom-left
//DrawCircle(188 , 94 ,20,colors[FIREBRICK]); //? Bottom-right
//DrawCircle(94 , 188 ,20,colors[FIREBRICK]); //? Top-left
//DrawCircle(188 , 188 ,20,colors[FIREBRICK]); //? Top-right
void MouseClicked(int button, int state, int x, int y){

	int Red=Red_name_length();
	int Green=Green_name_length();
	int Purple=Purple_name_length();
	int Yellow=Yellow_name_length();
	int turn=turn_return();
	int red_check=first_turn_red_return();
	int Green_check=first_turn_Green_return();
	int purple_check=first_turn_purple_return();
	int yellow_check=first_turn_yellow_return();
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) // dealing only with left button
	{	
		int red1=Red_1_pos_return();
		int red1_xpos=block_number_xpos(red1);
		int red1_ypos=block_number_ypos(red1);

		int red2=Red_2_pos_return();
		int red2_xpos=block_number_xpos(red2);
		int red2_ypos=block_number_ypos(red2);

		int red3=Red_3_pos_return();
		int red3_xpos=block_number_xpos(red3);
		int red3_ypos=block_number_ypos(red3);

		int red4=Red_4_pos_return();
		int red4_xpos=block_number_xpos(red4);
		int red4_ypos=block_number_ypos(red4);

		int green1=Green_1_pos_return();
		int green1_xpos=block_number_xpos(green1);
		int green1_ypos=block_number_ypos(green1);

		int green2=Green_2_pos_return();
		int green2_xpos=block_number_xpos(green2);
		int green2_ypos=block_number_ypos(green2);

		int green3=Green_3_pos_return();
		int green3_xpos=block_number_xpos(green3);
		int green3_ypos=block_number_ypos(green3);

		int green4=Green_4_pos_return();
		int green4_xpos=block_number_xpos(green4);
		int green4_ypos=block_number_ypos(green4);
		
		int purple1=Purple_1_pos_return();
		int purple1_xpos=block_number_xpos(purple1);
		int purple1_ypos=block_number_ypos(purple1);
		
		int purple2=Purple_2_pos_return();
		int purple2_xpos=block_number_xpos(purple2);
		int purple2_ypos=block_number_ypos(purple2);
		
		int purple3=Purple_3_pos_return();
		int purple3_xpos=block_number_xpos(purple3);
		int purple3_ypos=block_number_ypos(purple3);
		
		int purple4=Purple_4_pos_return();
		int purple4_xpos=block_number_xpos(purple4);
		int purple4_ypos=block_number_ypos(purple4);
		
		int yellow1=Yellow_1_pos_return();
		int yellow1_xpos=block_number_xpos(yellow1);
		int yellow1_ypos=block_number_ypos(yellow1);

		int yellow2=Yellow_2_pos_return();
		int yellow2_xpos=block_number_xpos(yellow2);
		int yellow2_ypos=block_number_ypos(yellow2);

		int yellow3=Yellow_3_pos_return();
		int yellow3_xpos=block_number_xpos(yellow3);
		int yellow3_ypos=block_number_ypos(yellow3);
		
		int yellow4=Yellow_4_pos_return();
		int yellow4_xpos=block_number_xpos(yellow4);
		int yellow4_ypos=block_number_ypos(yellow4);

		int dice=current_return();
		cout<<x<<" "<<y<<endl;
		if((x>50&&x<=164)&&(y<=658&&y>=540)&&dice==6&&red_check==6&&red1==0&&Red!=0){
			Red_1_pos_input(2);
		}
		else if((x>=red1_xpos-23.5&&x<=red1_xpos+23.5)&&(y>=658-red1_ypos&&y<=752-red1_ypos)){
			red1+=dice;
			if(red1>52&&red1<252){
				red1+=200;
			}
			Red_1_pos_input(red1);
		}
		else if((x>50&&x<=164)&&(y<=611&&y>=493)&&dice==6&&red_check==6&&red2==0&&Red!=0){
			Red_2_pos_input(2);
		}
		else if((x>=red2_xpos-23.5&&x<=red2_xpos+23.5)&&(y>=658-red2_ypos&&y<=752-red2_ypos)){
			red2+=dice;
			if(red2>52&&red2<252){
				red2+=200;
			}
			Red_2_pos_input(red2);
		}
		else if((x>97&&x<=211)&&(y<=611&&y>=493)&&dice==6&&red_check==6&&red3==0&&Red!=0){
			Red_3_pos_input(2);
		}
		else if((x>=red3_xpos-23.5&&x<=red3_xpos+23.5)&&(y>=658-red3_ypos&&y<=752-red3_ypos)){
			red3+=dice;
			if(red3>52&&red3<252){
				red3+=200;
			}
			Red_3_pos_input(red3);
		}
		else if((x>97&&x<=211)&&(y<=658&&y>=540)&&dice==6&&red_check==6&&red4==0&&Red!=0){
			Red_4_pos_input(2);
		}
		else if((x>=red4_xpos-23.5&&x<=red4_xpos+23.5)&&(y>=658-red4_ypos&&y<=752-red4_ypos)){
			red4+=dice;
			if(red4>52&&red4<252){
				red4+=200;
			}
			Red_4_pos_input(red4);
		}

		if((x>70.5&&x<=117.5)&&(y<=211.5&&y>=164)&&dice==6&&Green_check==6&&green1==0&&Green!=0){
			Green_1_pos_input(15);
		}
		else if((x>=green1_xpos-23.5&&x<=green1_xpos+23.5)&&(y>=658-green1_ypos&&y<=752-green1_ypos)){
			green1+=dice;
			if(green1>65&&green1<252){
				green1+=300;
			}
			Green_1_pos_input(green1);
		}
		else if((x>70.5&&x<=117.5)&&(y<=117&&y>=75)&&dice==6&&Green_check==6&&green2==0&&Green!=0){
			Green_2_pos_input(15);
		}
		else if((x>=green2_xpos-23.5&&x<=green2_xpos+23.5)&&(y>=658-green2_ypos&&y<=752-green2_ypos)){
			green2+=dice;
			if(green2>65&&green2<252){
				green2+=300;
			}
			Green_2_pos_input(green2);
		}
		else if((x>164.5&&x<=211)&&(y<=211&&y>=164)&&dice==6&&Green_check==6&&green4==0&&Green!=0){
			Green_4_pos_input(15);
		}
		else if((x>=green4_xpos-23.5&&x<=green4_xpos+23.5)&&(y>=658-green4_ypos&&y<=752-green4_ypos)){
			green4+=dice;
			if(green4>65&&green4<252){
				green4+=300;
			}
			Green_4_pos_input(green4);
		}
		else if((x>164&&x<=211)&&(y<=117&&y>=75)&&dice==6&&Green_check==6&&green3==0&&Green!=0){
			Green_3_pos_input(15);
		}
		else if((x>=green3_xpos-23.5&&x<=green3_xpos+23.5)&&(y>=658-green3_ypos&&y<=752-green3_ypos)){
			green3+=dice;
			if(green3>65&&green3<252){
				green3+=300;
			}
			Green_3_pos_input(green3);
		}


		if((x>493.5&&x<=540.5)&&(y<=211.5&&y>=164)&&dice==6&&purple_check==6&&purple1==0&&Purple!=0){
			Purple_1_pos_input(28);
		}
		else if((x>=purple1_xpos-23.5&&x<=purple1_xpos+23.5)&&(y>=658-purple1_ypos&&y<=752-purple1_ypos)){
			purple1+=dice;
			if(purple1>78&&purple1<252){
				purple1+=400;
			}
			Purple_1_pos_input(purple1);
		}
		else if((x>493.5&&x<=540.5)&&(y<=117.5&&y>=70.5)&&dice==6&&purple_check==6&&purple2==0&&Purple!=0){
			Purple_2_pos_input(28);
		}
		else if((x>=purple2_xpos-23.5&&x<=purple2_xpos+23.5)&&(y>=658-purple2_ypos&&y<=752-purple2_ypos)){
			purple2+=dice;
			if(purple2>78&&purple2<252){
				purple2+=400;
			}
			Purple_2_pos_input(purple2);
		}
		else if((x>587.5&&x<=634.5)&&(y<=117.5&&y>=70.5)&&dice==6&&purple_check==6&&purple3==0&&Purple!=0){
			Purple_3_pos_input(28);
		}
		else if((x>=purple3_xpos-23.5&&x<=purple3_xpos+23.5)&&(y>=658-purple3_ypos&&y<=752-purple3_ypos)){
			purple3+=dice;
			if(purple3>78&&purple3<252){
				purple3+=400;
			}
			Purple_3_pos_input(purple3);
		}
		else if((x>587.5&&x<=634.5)&&(y<=211.5&&y>=164)&&dice==6&&purple_check==6&&purple4==0&&Purple!=0){
			Purple_4_pos_input(28);
		}
		else if((x>=purple4_xpos-23.5&&x<=purple4_xpos+23.5)&&(y>=658-purple4_ypos&&y<=752-purple4_ypos)){
			purple4+=dice;
			if(purple4>78&&purple4<252){
				purple4+=400;
			}
			Purple_4_pos_input(purple4);
		}


		if((x>593.5&&x<=540.5)&&(y<=658&&y>=540)&&dice==6&&yellow_check==6&&yellow1==0&&Yellow!=0){
			Yellow_1_pos_input(41);
		}
		else if((x>=yellow1_xpos-23.5&&x<=yellow1_xpos+23.5)&&(y>=658-yellow1_ypos&&y<=752-yellow1_ypos)){
			yellow1+=dice;
			if(yellow1>91&&yellow1<591){
				yellow1+=500;
			}
			Yellow_1_pos_input(yellow1);
		}
		else if((x>493.5&&x<=540.5)&&(y<=611&&y>=493)&&dice==6&&yellow_check==6&&yellow2==0&&Yellow!=0){
			Yellow_2_pos_input(41);
		}
		else if((x>=yellow2_xpos-23.5&&x<=yellow2_xpos+23.5)&&(y>=658-yellow2_ypos&&y<=752-yellow2_ypos)){
			yellow2+=dice;
			if(yellow2>91&&yellow2<591){
				yellow2+=500;
			}
			Yellow_2_pos_input(yellow2);
		}
		else if((x>587.5&&x<=634.5)&&(y<=611&&y>=493)&&dice==6&&yellow_check==6&&yellow3==0&&Yellow!=0){
			Yellow_3_pos_input(41);
		}
		else if((x>=yellow3_xpos-23.5&&x<=yellow3_xpos+23.5)&&(y>=658-yellow3_ypos&&y<=752-yellow3_ypos)){
			yellow3+=dice;
			if(yellow3>91&&yellow3<591){
				yellow3+=500;
			}
			Yellow_3_pos_input(yellow3);
		}
		else if((x>587.5&&x<=634.5)&&(y<=658&&y>=540)&&dice==6&&yellow_check==6&&yellow4==0&&Yellow!=0){
			Yellow_4_pos_input(41);
		}
		else if((x>=yellow4_xpos-23.5&&x<=yellow4_xpos+23.5)&&(y>=658-yellow4_ypos&&y<=752-yellow4_ypos)){
			yellow4+=dice;
			if(yellow4>91&&yellow4<591){
				yellow4+=500;
			}
			Yellow_4_pos_input(yellow4);
		}
		
	}


	glutPostRedisplay();
}
/*
!==============================================================================================
!==============================================================================================
!                  NEW SECTION: For drawing of peices at respective positions.
!==============================================================================================
!==============================================================================================
*/
void Red_1(int x){
	int xpos=block_number_xpos(x);
	int ypos=block_number_ypos(x);
	if(x==2)
	DrawCircle(xpos,ypos,20,colors[WHITE]);
	if(x!=0)
	DrawCircle(94 , 94 ,20,colors[WHITE]);
	if(x>2&&x<=52&&x!=2)
	DrawCircle(xpos,ypos,20,colors[FIREBRICK]);
	if(x>=252&&x<=257)
	DrawCircle(xpos,ypos,20,colors[WHITE]);
}
void Red_2(int x){
	int xpos=block_number_xpos(x);
	int ypos=block_number_ypos(x);
	if(x==2)
	DrawCircle(xpos,ypos,20,colors[WHITE]);
	if(x!=0)
	DrawCircle(94 , 188  ,20,colors[WHITE]);
	if(x>=2&&x<=52&&x!=2)
	DrawCircle(xpos,ypos,20,colors[FIREBRICK]);
	if(x>=252&&x<=257)
	DrawCircle(xpos,ypos,20,colors[WHITE]);
}
void Red_3(int x){
	int xpos=block_number_xpos(x);
	int ypos=block_number_ypos(x);
	if(x==2)
	DrawCircle(xpos,ypos,20,colors[WHITE]);
	if(x!=0)
	DrawCircle(188 , 188  ,20,colors[WHITE]);
	if(x>=2&&x<=52&&x!=2)
	DrawCircle(xpos,ypos,20,colors[FIREBRICK]);
	if(x>=252&&x<=257)
	DrawCircle(xpos,ypos,20,colors[WHITE]);
}
void Red_4(int x){
	int xpos=block_number_xpos(x);
	int ypos=block_number_ypos(x);
	if(x==2)
	DrawCircle(xpos,ypos,20,colors[WHITE]);
	if(x!=0)
	DrawCircle(188 , 94  ,20,colors[WHITE]);
	if(x>0&&x<=52&&x!=2)
	DrawCircle(xpos,ypos,20,colors[FIREBRICK]);
	if(x>=352&&x<=357)
	DrawCircle(xpos,ypos,20,colors[WHITE]);
}

void Green_1(int x){
	int xpos=block_number_xpos(x);
	int ypos=block_number_ypos(x);
	if(x==15)
	DrawCircle(xpos,ypos,20,colors[WHITE]);
	if(x!=0)
	DrawCircle(94,517,23,colors[WHITE]);
	if(x>0&&x<=65&&x!=15)
	DrawCircle(xpos,ypos,20,colors[MEDIUM_AQUA_MARINE]);
	if(x>=365&&x<=371)
	DrawCircle(xpos,ypos,20,colors[WHITE]);
}
void Green_2(int x){
	int xpos=block_number_xpos(x);
	int ypos=block_number_ypos(x);
	if(x==15)
	DrawCircle(xpos,ypos,20,colors[WHITE]);
	if(x!=0)
	DrawCircle(94 ,611,23,colors[WHITE]);
	if(x>0&&x<=65&&x!=15)
	DrawCircle(xpos,ypos,20,colors[MEDIUM_AQUA_MARINE]);
	if(x>=366&&x<=371)
	DrawCircle(xpos,ypos,20,colors[WHITE]);
}
void Green_3(int x){
	int xpos=block_number_xpos(x);
	int ypos=block_number_ypos(x);
	if(x==15)
	DrawCircle(xpos,ypos,20,colors[WHITE]);
	if(x!=0)
	DrawCircle(188 ,611,23,colors[WHITE]);
	if(x>0&&x<=65&&x!=15)
	DrawCircle(xpos,ypos,20,colors[MEDIUM_AQUA_MARINE]);
	if(x>=366&&x<=371)
	DrawCircle(xpos,ypos,20,colors[WHITE]);
}
void Green_4(int x){
	int xpos=block_number_xpos(x);
	int ypos=block_number_ypos(x);
	if(x==15)
	DrawCircle(xpos,ypos,20,colors[WHITE]);
	if(x!=0)
	DrawCircle(188 ,517,23,colors[WHITE]);
	if(x>0&&x<=65&&x!=15)
	DrawCircle(xpos,ypos,20,colors[MEDIUM_AQUA_MARINE]);
	if(x>=366&&x<=371)
	DrawCircle(xpos,ypos,20,colors[WHITE]);
}


void Purple_1(int x){
	int xpos=block_number_xpos(x);
	int ypos=block_number_ypos(x);
	if(x==28)
	DrawCircle(xpos,ypos,20,colors[WHITE]);
	if(x!=0)
	DrawCircle(517,517,23,colors[WHITE]);
	if(x>0&&x<=78&&x!=28)
	DrawCircle(xpos,ypos,20,colors[DARK_SLATE_BLUE]);
	if(x>=478&&x<=484)
	DrawCircle(xpos,ypos,20,colors[WHITE]);
}
void Purple_2(int x){
	int xpos=block_number_xpos(x);
	int ypos=block_number_ypos(x);
	if(x==28)
	DrawCircle(xpos,ypos,20,colors[WHITE]);
	if(x!=0)
	DrawCircle(517,611,23,colors[WHITE]);
	if(x>0&&x<=78&&x!=28)
	DrawCircle(xpos,ypos,20,colors[DARK_SLATE_BLUE]);
	if(x>=478&&x<=484)
	DrawCircle(xpos,ypos,20,colors[WHITE]);
}
void Purple_3(int x){
	int xpos=block_number_xpos(x);
	int ypos=block_number_ypos(x);
	if(x==28)
	DrawCircle(xpos,ypos,20,colors[WHITE]);
	if(x!=0)
	DrawCircle(611,611,23,colors[WHITE]);
	if(x>0&&x<=78&&x!=28)
	DrawCircle(xpos,ypos,20,colors[DARK_SLATE_BLUE]);
	if(x>=478&&x<=484)
	DrawCircle(xpos,ypos,20,colors[WHITE]);
}
void Purple_4(int x){
	int xpos=block_number_xpos(x);
	int ypos=block_number_ypos(x);
	if(x==28)
	DrawCircle(xpos,ypos,20,colors[WHITE]);
	if(x!=0)
	DrawCircle(611,517,23,colors[WHITE]);
	if(x>0&&x<=78&&x!=28)
	DrawCircle(xpos,ypos,20,colors[DARK_SLATE_BLUE]);
	if(x>=478&&x<=484)
	DrawCircle(xpos,ypos,20,colors[WHITE]);
}
void Yellow_1(int x){
	int xpos=block_number_xpos(x);
	int ypos=block_number_ypos(x);
	if(x==41)
	DrawCircle(xpos,ypos,20,colors[WHITE]);
	if(x!=0)
	DrawCircle(517 , 94 ,20,colors[WHITE]);
	if(x>0&&x<=91&&x!=41)
	DrawCircle(xpos,ypos,20,colors[ORANGE_RED]);
	if(x>=500&&x<=696)
	DrawCircle(xpos,ypos,20,colors[WHITE]);
}
void Yellow_2(int x){
	int xpos=block_number_xpos(x);
	int ypos=block_number_ypos(x);
	if(x==41)
	DrawCircle(xpos,ypos,20,colors[WHITE]);
	if(x!=0)
	DrawCircle(517 , 188 ,20,colors[WHITE]);
	if(x>0&&x<=91&&x!=41)
	DrawCircle(xpos,ypos,20,colors[ORANGE_RED]);
	if(x>=500&&x<=696)
	DrawCircle(xpos,ypos,20,colors[WHITE]);
}
void Yellow_3(int x){
	int xpos=block_number_xpos(x);
	int ypos=block_number_ypos(x);
	if(x==41)
	DrawCircle(xpos,ypos,20,colors[WHITE]);
	if(x!=0)
	DrawCircle(611 , 188 ,20,colors[WHITE]);
	if(x>0&&x<=91&&x!=41)
	DrawCircle(xpos,ypos,20,colors[ORANGE_RED]);
	if(x>=500&&x<=696)
	DrawCircle(xpos,ypos,20,colors[WHITE]);
}
void Yellow_4(int x){
	int xpos=block_number_xpos(x);
	int ypos=block_number_ypos(x);
	if(x==41)
	DrawCircle(xpos,ypos,20,colors[WHITE]);
	if(x!=0)
	DrawCircle(611 , 94 ,20,colors[WHITE]);
	if(x>0&&x<=91&&x!=41)
	DrawCircle(xpos,ypos,20,colors[ORANGE_RED]);
	if(x>=500&&x<=696)
	DrawCircle(xpos,ypos,20,colors[WHITE]);
}

/*
!==============================================================================================
!==============================================================================================
!                               NEW SECTION: For peices pos storing
!==============================================================================================
!==============================================================================================
*/
void Red_1_pos_input(int x){
	std::ofstream del;
	del.open("Red_1_pos.txt", std::ofstream::out | std::ofstream::trunc);
	del.close();
	ofstream pos;
	pos.open("Red_1_pos.txt",ios::app);
		for(int i=0;i<x;i++)
			pos<<"1";
	pos.close();
}
int Red_1_pos_return(){
	string size;
	ifstream pos; //opening user name file
		pos.open("Red_1_pos.txt");
		while((! pos.fail( ) ) && ( ! pos.eof( ) ) ){
			getline(pos,size); //extracting name of user into variable
		}
    pos.close();
	int x= size.size();
	return x;
}
void Red_2_pos_input(int x){
	std::ofstream del;
	del.open("Red_2_pos.txt", std::ofstream::out | std::ofstream::trunc);
	del.close();
	ofstream pos;
	pos.open("Red_2_pos.txt",ios::app);
		for(int i=0;i<x;i++)
			pos<<"1";
	pos.close();
}
int Red_2_pos_return(){
	string size;
	ifstream pos; //opening user name file
		pos.open("Red_2_pos.txt");
		while((! pos.fail( ) ) && ( ! pos.eof( ) ) ){
			getline(pos,size); //extracting name of user into variable
		}
    pos.close();
	int x= size.size();
	return x;
}
void Red_3_pos_input(int x){
	std::ofstream del;
	del.open("Red_3_pos.txt", std::ofstream::out | std::ofstream::trunc);
	del.close();
	ofstream pos;
	pos.open("Red_3_pos.txt",ios::app);
		for(int i=0;i<x;i++)
			pos<<"1";
	pos.close();
}
int Red_3_pos_return(){
	string size;
	ifstream pos; //opening user name file
		pos.open("Red_3_pos.txt");
		while((! pos.fail( ) ) && ( ! pos.eof( ) ) ){
			getline(pos,size); //extracting name of user into variable
		}
    pos.close();
	int x= size.size();
	return x;
}
void Red_4_pos_input(int x){
	std::ofstream del;
	del.open("Red_4_pos.txt", std::ofstream::out | std::ofstream::trunc);
	del.close();
	ofstream pos;
	pos.open("Red_4_pos.txt",ios::app);
		for(int i=0;i<x;i++)
			pos<<"1";
	pos.close();
}
int Red_4_pos_return(){
	string size;
	ifstream pos; //opening user name file
		pos.open("Red_4_pos.txt");
		while((! pos.fail( ) ) && ( ! pos.eof( ) ) ){
			getline(pos,size); //extracting name of user into variable
		}
    pos.close();
	int x= size.size();
	return x;
}

void Green_1_pos_input(int x){
	std::ofstream del;
	del.open("Green_1_pos.txt", std::ofstream::out | std::ofstream::trunc);
	del.close();
	ofstream pos;
	pos.open("Green_1_pos.txt",ios::app);
		for(int i=0;i<x;i++)
			pos<<"1";
	pos.close();
}
int Green_1_pos_return(){
	string size;
	ifstream pos; //opening user name file
		pos.open("Green_1_pos.txt");
		while((! pos.fail( ) ) && ( ! pos.eof( ) ) ){
			getline(pos,size); //extracting name of user into variable
		}
    pos.close();
	int x= size.size();
	return x;
}
void Green_2_pos_input(int x){
	std::ofstream del;
	del.open("Green_2_pos.txt", std::ofstream::out | std::ofstream::trunc);
	del.close();
	ofstream pos;
	pos.open("Green_2_pos.txt",ios::app);
		for(int i=0;i<x;i++)
			pos<<"1";
	pos.close();
}
int Green_2_pos_return(){
	string size;
	ifstream pos; //opening user name file
		pos.open("Green_2_pos.txt");
		while((! pos.fail( ) ) && ( ! pos.eof( ) ) ){
			getline(pos,size); //extracting name of user into variable
		}
    pos.close();
	int x= size.size();
	return x;
}
void Green_3_pos_input(int x){
	std::ofstream del;
	del.open("Green_3_pos.txt", std::ofstream::out | std::ofstream::trunc);
	del.close();
	ofstream pos;
	pos.open("Green_3_pos.txt",ios::app);
		for(int i=0;i<x;i++)
			pos<<"1";
	pos.close();
}
int Green_3_pos_return(){
	string size;
	ifstream pos; //opening user name file
		pos.open("Green_3_pos.txt");
		while((! pos.fail( ) ) && ( ! pos.eof( ) ) ){
			getline(pos,size); //extracting name of user into variable
		}
    pos.close();
	int x= size.size();
	return x;
}
void Green_4_pos_input(int x){
	std::ofstream del;
	del.open("Green_4_pos.txt", std::ofstream::out | std::ofstream::trunc);
	del.close();
	ofstream pos;
	pos.open("Green_4_pos.txt",ios::app);
		for(int i=0;i<x;i++)
			pos<<"1";
	pos.close();
}
int Green_4_pos_return(){
	string size;
	ifstream pos; //opening user name file
		pos.open("Green_4_pos.txt");
		while((! pos.fail( ) ) && ( ! pos.eof( ) ) ){
			getline(pos,size); //extracting name of user into variable
		}
    pos.close();
	int x= size.size();
	return x;
}


void Purple_1_pos_input(int x){
	std::ofstream del;
	del.open("Purple_1_pos.txt", std::ofstream::out | std::ofstream::trunc);
	del.close();
	ofstream pos;
	pos.open("Purple_1_pos.txt",ios::app);
		for(int i=0;i<x;i++)
			pos<<"1";
	pos.close();
}
int Purple_1_pos_return(){
	string size;
	ifstream pos; //opening user name file
		pos.open("Purple_1_pos.txt");
		while((! pos.fail( ) ) && ( ! pos.eof( ) ) ){
			getline(pos,size); //extracting name of user into variable
		}
    pos.close();
	int x= size.size();
	return x;
}
void Purple_2_pos_input(int x){
	std::ofstream del;
	del.open("Purple_2_pos.txt", std::ofstream::out | std::ofstream::trunc);
	del.close();
	ofstream pos;
	pos.open("Purple_2_pos.txt",ios::app);
		for(int i=0;i<x;i++)
			pos<<"1";
	pos.close();
}
int Purple_2_pos_return(){
	string size;
	ifstream pos; //opening user name file
		pos.open("Purple_2_pos.txt");
		while((! pos.fail( ) ) && ( ! pos.eof( ) ) ){
			getline(pos,size); //extracting name of user into variable
		}
    pos.close();
	int x= size.size();
	return x;
}
void Purple_3_pos_input(int x){
	std::ofstream del;
	del.open("Purple_3_pos.txt", std::ofstream::out | std::ofstream::trunc);
	del.close();
	ofstream pos;
	pos.open("Purple_3_pos.txt",ios::app);
		for(int i=0;i<x;i++)
			pos<<"1";
	pos.close();
}
int Purple_3_pos_return(){
	string size;
	ifstream pos; //opening user name file
		pos.open("Purple_3_pos.txt");
		while((! pos.fail( ) ) && ( ! pos.eof( ) ) ){
			getline(pos,size); //extracting name of user into variable
		}
    pos.close();
	int x= size.size();
	return x;
}
void Purple_4_pos_input(int x){
	std::ofstream del;
	del.open("Purple_4_pos.txt", std::ofstream::out | std::ofstream::trunc);
	del.close();
	ofstream pos;
	pos.open("Purple_4_pos.txt",ios::app);
		for(int i=0;i<x;i++)
			pos<<"1";
	pos.close();
}
int Purple_4_pos_return(){
	string size;
	ifstream pos; //opening user name file
		pos.open("Purple_4_pos.txt");
		while((! pos.fail( ) ) && ( ! pos.eof( ) ) ){
			getline(pos,size); //extracting name of user into variable
		}
    pos.close();
	int x= size.size();
	return x;
}

void Yellow_1_pos_input(int x){
	std::ofstream del;
	del.open("Yellow_1_pos.txt", std::ofstream::out | std::ofstream::trunc);
	del.close();
	ofstream pos;
	pos.open("Yellow_1_pos.txt",ios::app);
		for(int i=0;i<x;i++)
			pos<<"1";
	pos.close();
}
int Yellow_1_pos_return(){
	string size;
	ifstream pos; //opening user name file
		pos.open("Yellow_1_pos.txt");
		while((! pos.fail( ) ) && ( ! pos.eof( ) ) ){
			getline(pos,size); //extracting name of user into variable
		}
    pos.close();
	int x= size.size();
	return x;
}
void Yellow_2_pos_input(int x){
	std::ofstream del;
	del.open("Yellow_2_pos.txt", std::ofstream::out | std::ofstream::trunc);
	del.close();
	ofstream pos;
	pos.open("Yellow_2_pos.txt",ios::app);
		for(int i=0;i<x;i++)
			pos<<"1";
	pos.close();
}
int Yellow_2_pos_return(){
	string size;
	ifstream pos; //opening user name file
		pos.open("Yellow_2_pos.txt");
		while((! pos.fail( ) ) && ( ! pos.eof( ) ) ){
			getline(pos,size); //extracting name of user into variable
		}
    pos.close();
	int x= size.size();
	return x;
}
void Yellow_3_pos_input(int x){
	std::ofstream del;
	del.open("Yellow_3_pos.txt", std::ofstream::out | std::ofstream::trunc);
	del.close();
	ofstream pos;
	pos.open("Yellow_3_pos.txt",ios::app);
		for(int i=0;i<x;i++)
			pos<<"1";
	pos.close();
}
int Yellow_3_pos_return(){
	string size;
	ifstream pos; //opening user name file
		pos.open("Yellow_3_pos.txt");
		while((! pos.fail( ) ) && ( ! pos.eof( ) ) ){
			getline(pos,size); //extracting name of user into variable
		}
    pos.close();
	int x= size.size();
	return x;
}
void Yellow_4_pos_input(int x){
	std::ofstream del;
	del.open("Yellow_4_pos.txt", std::ofstream::out | std::ofstream::trunc);
	del.close();
	ofstream pos;
	pos.open("Yellow_4_pos.txt",ios::app);
		for(int i=0;i<x;i++)
			pos<<"1";
	pos.close();
}
int Yellow_4_pos_return(){
	string size;
	ifstream pos; //opening user name file
		pos.open("Yellow_4_pos.txt");
		while((! pos.fail( ) ) && ( ! pos.eof( ) ) ){
			getline(pos,size); //extracting name of user into variable
		}
    pos.close();
	int x= size.size();
	return x;
}

void current_input(int x){
	std::ofstream del;
	del.open("current_input.txt", std::ofstream::out | std::ofstream::trunc);
	del.close();
	ofstream current_input;
	current_input.open("current_input.txt",ios::app);
		for(int i=0;i<x;i++)
			current_input<<"1";
	current_input.close();
}
int current_return(){
	string size;
	ifstream current_input; //opening user name file
		current_input.open("current_input.txt");
		while((! current_input.fail( ) ) && ( ! current_input.eof( ) ) ){
			getline(current_input,size); //extracting name of user into variable
		}
    current_input.close();
	int x= size.size();
	return x;
}
/*
?==============================================================================================
?==============================================================================================
?                               NEW SECTION: Random functions
?==============================================================================================
?==============================================================================================
*/
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); //* set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}

void Timer(int m) {

	// implement your functionality here

	//! once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(1000.0, Timer, 0);
}

void MousePressedAndMoved(int x, int y) {
	cout << x << " " << y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {

	glutPostRedisplay();
}
void NonPrintableKeys(int key, int x, int y) {
	if (key
			== GLUT_KEY_LEFT /* GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...

	} else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {

	} else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {

	}

	else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {

	}

	/*
	! This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	! this function
	*/

	glutPostRedisplay();

}
void remove_all(){
		remove("Green_name.txt");
		remove("Purple_name.txt");
		remove("Yellow_name.txt");
		remove("Red_name.txt");
		remove("Score_Red.txt");
		remove("Score_Green.txt");
		remove("Score_Purple.txt");
		remove("Score_Yellow.txt");	
		remove("Turn.txt");	
		remove("Dice.txt");
		remove("Block.txt");
		remove("Pos.txt");
		remove("first_turn_green.txt");
		remove("first_turn_red.txt");
		remove("first_turn_purple.txt");
		remove("first_turn_yellow.txt");
		remove("Red_1_pos.txt");
		remove("Red_2_pos.txt");
		remove("Red_3_pos.txt");
		remove("Red_4_pos.txt");
		remove("current_input.txt");
		remove("Green_1_pos.txt");
		remove("Green_2_pos.txt");
		remove("Green_3_pos.txt");
		remove("Green_4_pos.txt");
		remove("Purple_1_pos.txt");
		remove("Purple_2_pos.txt");
		remove("Purple_3_pos.txt");
		remove("Purple_4_pos.txt");
		remove("Yellow_1_pos.txt");
		remove("Yellow_2_pos.txt");
		remove("Yellow_3_pos.txt");
		remove("Yellow_4_pos.txt");
}
#endif /* AsteroidS_CPP_ */