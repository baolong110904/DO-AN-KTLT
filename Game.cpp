#include <iostream>
#include "Game.h"

#include <windows.h>
#include <conio.h>
#include <fstream>
#include<stdio.h>
#include<Windows.h>
#include <string>
#include <chrono>

#define _EASY 4
#define _MEDIUM 6
#define _HARD 8
using namespace std;


HANDLE consoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
COORD cursorpos; // used to set the position of the cursor

int mapMaxWidth = 18, mapMaxHeight = 10;
int cellWidth = 5, cellHeight = 3;
int** map;

int mapWidth = 6, mapHeight = 6;
int xCur = 1, yCur = 1;


const int size = _EASY;
char pokemons[size*4][size*8];
void printInterface();
//void selectedBlock();
//void unselectedBlock();

void ShowCursor(bool show)
{
	CONSOLE_CURSOR_INFO info = { 1, show };
	SetConsoleCursorInfo(consoleOutput, &info);
}
void gotoxy(int x, int y){
	COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

enum Consolecolor {
    Black = 0,
    Blue = 1,
    Green = 2,
    Cyan = 3,
    Red = 4,
    Magenta = 5,
    Yellow = 6,
    White = 7,
    Gray = 8,
    DarkBlue = 9,
    DarkGreen = 10,
    Teal = 11,
    DarkRed = 12,
    Purple = 13,
    Orange = 14,
    LightGray = 15,
    DarkOrange = 16,
    LightBlue = 17,
    LightGreen = 18,
    LightYellow = 19,
    LightCyan = 20,
    Pink = 21,
    Lavender = 22
    
};

void setcolor(Consolecolor color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (WORD)color);
}

void L(string fileName, int x, int y) {
    ifstream file("L.txt");

    if (file.is_open()) {
        char c;
        int posX = 5, posY = 1;
        while (file.get(c)) {
            if (c == '|' || c == '.' || c == '_' || c == '\\' || c == '-' || c == '\'' || c == '/') {
                
                gotoxy(posX, posY);
                setcolor(Yellow);
                cout << c;
                posX++;
            }
            
            else if (c == '\n') {
                posY++;
                posX = x;
            }
            else {
                
                gotoxy(posX, posY);
                setcolor(Gray);
                cout << c;
                posX++;
            }
        }
        file.close();
    }
}
void O(string fileName, int x, int y) {
    ifstream file("O.txt");

    if (file.is_open()) {
        char c;
        int posX = 25, posY = 1;
        while (file.get(c)) {
            if (c == '|' || c == '.' || c == '_' || c == '\\' || c == '-' || c == '\'' || c == '/' || c == '`') {
                
                gotoxy(posX, posY);
                setcolor(Magenta);
                cout << c;
                posX++;
            }
            
            else if (c == '\n') {
                posY++;
                posX = x;
            }
            else {
                
                gotoxy(posX, posY);
                setcolor(Gray);
                cout << c;
                posX++;
            }
        }
        file.close();
    }
}
void G(string fileName, int x, int y) {
    ifstream file("G.txt");

    if (file.is_open()) {
        char c;
        int posX = 44, posY = 1;
        while (file.get(c)) {
            if (c == '|' || c == '.' || c == '_' || c == '\\' || c == '-' || c == '\'' || c == '/') {
                
                gotoxy(posX, posY);
                setcolor(Cyan);
                cout << c;
                posX++;
            }
            
            else if (c == '\n') {
                posY++;
                posX = x;
            }
            else {
                
                gotoxy(posX, posY);
                setcolor(Gray);
                cout << c;
                posX++;
            }
        }
        file.close();
    }
}
void I(string fileName, int x, int y) {
    ifstream file("I.txt");

    if (file.is_open()) {
        char c;
        int posX = 63, posY = 1;
        while (file.get(c)) {
            if (c == '|' || c == '.' || c == '_' || c == '\\' || c == '-' || c == '\'' || c == '/') {
                
                gotoxy(posX, posY);
                setcolor(Teal);
                cout << c;
                posX++;
            }
            
            else if (c == '\n') {
                posY++;
                posX = x;
            }
            else {
                
                gotoxy(posX, posY);
                setcolor(Gray);
                cout << c;
                posX++;
            }
        }
        file.close();
    }
}
void N(string fileName, int x, int y) {
    ifstream file("N.txt");

    if (file.is_open()) {
        char c;
        int posX = 83, posY = 1;
        while (file.get(c)) {
            if (c == '|' || c == '.' || c == '_' || c == '\\' || c == '-' || c == '\'' || c == '/') {
                
                gotoxy(posX, posY);
                setcolor(Blue);
                cout << c;
                posX++;
            }
            
            else if (c == '\n') {
                posY++;
                posX = x;
            }
            else {
                
                gotoxy(posX, posY);
                setcolor(Gray);
                cout << c;
                posX++;
            }
        }
        file.close();
    }
}


void printrectangle(int left, int top, int width, int height){
	gotoxy(left, top);
	putchar(218);
	for (int i = 0; i < width; i++)
		putchar(196);
	putchar(191);

	int i = 0;
	for (; i < height; i++)
	{
		gotoxy(left, top + i + 1);
		putchar(179);
		gotoxy(left + width + 1, top + i + 1);
		putchar(179);
	}

	gotoxy(left, top + i);
	putchar(192);
	for (i = 0; i < width; i++)
		putchar(196);
	putchar(217);
}
void setConsolecolor(int textColor, int bgColor) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (textColor + (bgColor * 16)));
}

void Game::setupGame() {
	system("cls");
	// Print rectangle to cover the screen
	L("L.txt", 5, 1);
	O("0.txt", 25, 1);
	G("G.txt", 44, 1);
	I("I.txt", 63, 1);
	N("N.txt", 83, 1);
	
	ShowCursor(true);
// code for the "Back" button
	printrectangle(50, 27, 8, 2);
	gotoxy(47, 28);
	putchar(175);
	gotoxy(53, 28);
	setcolor(Cyan);
	cout << "Back";
	gotoxy(60, 28);
	putchar(174);
	
	// wait for user input
    while (true) {
        char c = getch();
        if (c == 13) { // user pressed Enter key
            break;
        }
        else if (c == 'b' || c == 'B') { // user pressed "B" key
//            displayStartMenu(); // call the function from menu.h
            return; // exit current function
        }
    }
	// Print input fields and get player information

	setcolor(Orange);
	printrectangle(15, 13, 80, 12);
	gotoxy(30, 15);
	cout << "Please enter your name, ID, class shortly!";
		gotoxy(35, 18);
		cout << "Enter your Name:  ";
		getline(cin, playerName);
		while (playerName.empty()) {
			gotoxy(0, 27);
			cout << "Please enter a valid name! ";
			gotoxy(53, 18);
			getline(cin, playerName);
		}
		
		gotoxy(35, 20);
		cout << "Enter your ID:  ";
		
		// Restrict user to input data only within the specified coordinates
		int x = 51, y = 20;
		while (true) {
			char c = getch();
			if (c == 13) break; // exit loop when user presses Enter key
			else if (c == 8 && x > 51) { // handle backspace key
				gotoxy(--x, y);
				putchar(' ');
				gotoxy(x, y);
			}
			else if (isdigit(c) && x < 57) { // handle numeric input
				putchar(c);
				playerID = playerID * 10 + (c - '0');
				gotoxy(++x, y);
			}
		}
		
		// Check if user entered any input for player ID
		if (playerID == 0) {
			gotoxy(0, 27);
			cout << "Please enter a valid integer for your ID! ";
			gotoxy(51, 20);
		}
		
		gotoxy(35, 22);
		cout << "Enter your class's name:  ";
		getline(cin, playerClass);
	
		// Check for empty input
		while (playerClass.empty()) {
			gotoxy(0, 27);
			cout << "Please enter a valid class name! ";
			gotoxy(61, 22);
			getline(cin, playerClass);
		}
	
	
	system("cls");
	saveData();
//// Set mode based on difficulty level
//	if (_mode == 4)
//		strcpy_s(mode, "EASY");
//	else 
//		strcpy_s(mode, "MEDIUM");
}

void Game::saveData() {
    std::ofstream outfile("player_info.dat", std::ios::binary|ios::out|ios::app);
    if (!outfile) {
        std::cerr << "Failed to open file for writing.\n";
        return;
    }

    // Write data to binary file
    outfile.write((char*)&playerName, sizeof(playerName));
    outfile.write((char*)&playerID, sizeof(playerID)); 
    outfile.write((char*)&playerClass, sizeof(playerClass));
    
	
    outfile.close();
   
    system("cls");
}

//void Game::printBackground() {
//    // Define file paths for background images
//    string easyFilePath = "images\\easy.txt";
//    string mediumFilePath = "images\\medium.txt";
//    string filePath;
//
//    // Choose background image based on difficulty level
//    if(_mode == 4) {
//        filePath = easyFilePath;
//    } else if(_mode == 6) {
//        filePath = mediumFilePath;
//    } else {
//        // Default to easy background if difficulty level is not recognized
//        filePath = easyFilePath;
//    }
//
//    // Read background image from file
//    ifstream infile(filePath); // Open file for reading
//    string line;
//    while (getline(infile, line)) { // Read each line of the file
//        // Replace difficulty level markers with the appropriate number of spaces
//        if(_mode == 4) {
//            line.replace(line.find("_EASY"), 5, string(_EASY, ' '));
//        } else if(_mode == 6) {
//            line.replace(line.find("_MEDIUM"), 7, string(_MEDIUM, ' '));
//        }
//        cout << line << endl; // Print the line to the console
//    }
//    infile.close(); // Close the file
//}
int getConsoleinput(){
	int c = _getch();
	// Arrow key
	if (c == 0 || c == 224)
	{
		switch (_getch())
		{
		case KEY_UP:				//lên
			return 2;
		case KEY_LEFT:				//trái
			return 3;
		case KEY_RIGHT:				//phải
			return 4;
		case KEY_DOWN:				//xuống
			return 5;
		default:				//nút khác
			return 0;
		}
	}
	else
	{
		if (c == KEY_ESC)                  //esc
			return 1;
		else if (c == 87 || c == 119) //W, w
			return 2;
		else if (c == 65 || c == 97)  //A, a
			return 3;
		else if (c == 68 || c == 100) //D, d
			return 4;
		else if (c == 83 || c == 115) //S, s
			return 5;
		else if (c == 13)             //Enter
			return 6;
		else if (c == 72 || c == 104) //H, h
			return 7;
		else if (c == 77 || c == 109) // M, m
			return 8;
		else
			return 0;                 //nút khác
	}
}

void exitscreen(){
	system("cls");
	ShowCursor(false);
	
	
	
	printrectangle(34, 13, 35, 8);
	printrectangle(37, 18, 7, 2);
	printrectangle(60, 18, 6, 2);
	
	gotoxy(0, 0);
	
	gotoxy(42, 16);
	cout << "Do you want to exit?";
	string str[2] = { "Yes", "No" };
	int left[] = { 35,40,47,58,63,69 }, word[] = { 32,32,175,174 }, color[] = { BLACK, RED }, top = 19;
	bool choice = 0;
	bool loop = 1;
	bool exitProgram = false; // new variable
	auto print1 = [&]()
	{
		int i = 0;
		while (i < 2)
		{
			PlaySound("click.wav", NULL, SND_ASYNC);
			
			gotoxy(left[choice * 3], top);        putchar(word[i * 2]);
			gotoxy(left[choice * 3 + 1], top);    cout << str[choice];
			gotoxy(left[choice * 3 + 2], top);    putchar(word[i * 2 + 1]);
			if (!i++)
				choice = !choice;
		}
		exitProgram = (choice == 0); // update exitProgram variable
	};
	print1();
	while (loop)
	{
		int key = getConsoleinput();
		if ((key == 3 && choice == 1) || (key == 4 && choice == 0))
		{	
			print1();
		}
		else if (key == 6)
        {
            if (!choice)
            {   
                
                system("cls");
                exitProgram = true;
                break;
            }
            
            else // add this else block to change color back to default
            {
                setConsolecolor(LIGHT_YELLOW, BLACK); 
                return;
            }
        }
	}
	if (exitProgram) // check if user wants to exit
		exit(0);

//		else
//		{
//			Controller::playSound(ERROR_SOUND);
//		}
	
}
void instructionscreen(){
	ShowCursor(false);
	
	system("cls");
	int left = 5, top = 2, width = 85, height = 23;
	int line1 = 6, line2 = 19, line3 = 20, line4 = 15;
	printrectangle(left, top, width, height);
	gotoxy(left + 1, line1);
	for (int i = 0; i < width; i++)
	{
		putchar(196);
	}
	gotoxy(left + 1, line2);
	for (int i = 0; i < width; i++)
	{
		putchar(196);
	}
	gotoxy(left + 1, line4);
	for (int i = 0; i < width; i++)
	{
		putchar(196);
	}
	for (int i = 1; i < height; i++)
	{
		gotoxy(line3, top + i);
		putchar(179);
	}
	gotoxy(line3, line1);
	putchar(197);
	gotoxy(line3, line2);
	putchar(197);

	gotoxy(left + 3, top + 2);
	setcolor(White);
	
	cout << "Moves:";
	gotoxy(left + 20, top + 1);
	setcolor(Cyan);
	
	putchar(249); cout << "Up:    W, up arrow";
	gotoxy(left + 52, top + 1);
	setcolor(Cyan);
	putchar(249); cout << "Down:  S, down arrow";
	gotoxy(left + 20, top + 3);
	setcolor(Cyan);
	putchar(249); cout << "Left:  A, left arrow";
	gotoxy(left + 52, top + 3);
	setcolor(Cyan);
	putchar(249); cout << "Right: D, right arrow";
	
	
	gotoxy(left + 3, top + 8);
	setcolor(White);
	cout << "Rules:";
	gotoxy(left + 17, top + 5);
	int left1 = left + 17;
	
	setcolor(Orange);
	putchar(249); cout << " The Matching Game (commonly known as the Pikachu Puzzle Game)";
	gotoxy(left1, top + 6);
	cout << " includes a board of multiple cells, each of which presents a figure.";
	gotoxy(left1, top + 8);
	setcolor(Orange);
	putchar(249); cout << " The player finds and matches a pair of cells that contain the same";
	gotoxy(left1, top + 9);
	cout << " figure and connect each other in some particular pattern.";
	gotoxy(left1, top + 11);
	setcolor(Orange);
	putchar(249); cout << " A legal match will make the two cells disappear. The game ends when";
	gotoxy(left1, top + 12);
	cout << " all matching pairs are found.";
	setcolor(Orange);
	gotoxy(left + 3, top + 15);
	setcolor(White);
	cout << "Scoring:";
	

	gotoxy(left1 + 10, top + 14);
	putchar(249); cout << " I Matching: +1 points";
	
	gotoxy(left1 + 40, top + 14);
	putchar(249); cout << " L Matching: +2 points";
	setcolor(Yellow);
	gotoxy(left1 + 10, top + 15);
	putchar(249); cout << " Z Matching: +3 points";
	setcolor(Green);
	gotoxy(left1 + 40, top + 15);
	putchar(249); cout << " U Matching: +4 points";
	
	setcolor(Red);
	gotoxy(left1 + 10, top + 16);
	putchar(249); cout << " Not Matched: -2 points";
	
	setcolor(Red);
	gotoxy(left1 + 40, top + 16);
	putchar(249); cout << " Move suggestion: -2 points";
	
	
	gotoxy(left + 3, top + 20);
	setcolor(White);
	cout << "Developers:";
	gotoxy(left + 31, top + 19);
	setcolor(Teal);
	cout << "Dev 1: Nguyen Bao Long (22127243))";
	gotoxy(left + 31, top + 21);
	setcolor(Teal);
	cout << "Dev 2: Bui Minh Quan (22127342)";


	// code for the "Back" button
	printrectangle(45, 27, 8, 2);
	gotoxy(43, 28);
	putchar(175);
	gotoxy(48, 28);
	setcolor(Red);
	cout << "Back";
	gotoxy(56, 28);
	putchar(174);
	// wait for user input
	while (true) {
   		if (_kbhit()) {
        	char c = _getch();
        if (c == 'B' || c == 'b' || c == '\r') {  // check if the user pressed "B" or "b"
            system("cls");
            setConsolecolor(LIGHT_YELLOW, BLACK); 
            break;
        }
    }
}
//	while (getConsoleInput() != 6)
//	{
//		Controller::playSound(ERROR_SOUND);
//	}
}

	 
void showBoardEasy(){
    system("cls");
	ShowCursor(false);
	int left = 2, top = 2, size = 4; 
	
    gotoxy(left + 1, top);
    putchar(201);
    for (int i = 1; i < size * 8; i++)
    {
        Sleep(5);
        if (i % 8 == 0)
            putchar(205);
        else
            putchar(205);
    }
    putchar(187);

    // Draw right line
    for (int i = 1; i < size * 4; i++)
    {
        Sleep(10);
        gotoxy(size * 8 + left + 1, i + top);
        if (i % 4 != 0)
            putchar(186);
        else
            putchar(186);
    }
    gotoxy(size * 8 + left + 1, size * 4 + top);
    putchar(188);

    // Draw bottom line
    for (int i = 1; i < size * 8; i++)
    {
        gotoxy(size * 8 + left - i + 1, size * 4 + top);
        Sleep(5);
        if (i % 8 == 0)
            putchar(205);
        else
            putchar(205);
    }
    gotoxy(left + 1, size * 4 + top);
    putchar(200);

    // Draw left line
    for (int i = 1; i < size * 4; i++)
    {
        Sleep(10);
        gotoxy(left + 1, size * 4 + top - i);
        if (i % 4 != 0)
            putchar(186);
        else
            putchar(186);
    }

    // Draw vertical lines
    for (int i = 1; i < size * 4; i++)
    {
        for (int j = 8; j < size * 8; j += 8)
        {
            if (i % 4 != 0)
            {
                gotoxy(j + left + 1, i + top);
                putchar(179);
            }
        }
        Sleep(10);
    }

    // Draw horizontal lines
    for (int i = 1; i < size * 8; i++)
    {
        for (int j = 4; j < size * 4; j += 4)
        {
            gotoxy(i + left + 1, j + top);
            if (i % 8 == 0)
                //putchar(197);
                putchar(32);
            else
                putchar(196);
        }
        Sleep(5);
    }
    // Fill cells with random letters A to D
	srand(time(NULL)); // Seed the random number generator with current time
	
	for (int i = 1; i <= size * 4; i+=4)
	{
		for (int j = 8; j <= size * 8; j+=8)
	    {
	        char pokemon = 'A' + rand() % 4; // Generate random letter from A to D
	        gotoxy(left + j - 3, top + i + 1); // Position cursor at center of cell
	        putchar(pokemon); // Print the random letter
	        
	                                  
	        // Store the pokemons in the matrix
        	pokemons[i-1][(j-8)/8] = pokemon;
		}
	}
	// Initialize player position
    
    // Select starting block
    //selectedBlock();

}
void showBoardMedium(){

    system("cls");
	ShowCursor(false);
	int left = 2, top = 2, size = 6; 
    gotoxy(left + 1, top);
    putchar(201);
    for (int i = 1; i < size * 8; i++)
    {
        Sleep(5);
        if (i % 8 == 0)
            putchar(205);
        else
            putchar(205);
    }
    putchar(187);

    // Draw right line
    for (int i = 1; i < size * 4; i++)
    {
        Sleep(10);
        gotoxy(size * 8 + left + 1, i + top);
        if (i % 4 != 0)
            putchar(186);
        else
            putchar(186);
    }
    gotoxy(size * 8 + left + 1, size * 4 + top);
    putchar(188);

    // Draw bottom line
    for (int i = 1; i < size * 8; i++)
    {
        gotoxy(size * 8 + left - i + 1, size * 4 + top);
        Sleep(5);
        if (i % 8 == 0)
            putchar(205);
        else
            putchar(205);
    }
    gotoxy(left + 1, size * 4 + top);
    putchar(200);

    // Draw left line
    for (int i = 1; i < size * 4; i++)
    {
        Sleep(10);
        gotoxy(left + 1, size * 4 + top - i);
        if (i % 4 != 0)
            putchar(186);
        else
            putchar(186);
    }

    // Draw vertical lines
    for (int i = 1; i < size * 4; i++)
    {
        for (int j = 8; j < size * 8; j += 8)
        {
            if (i % 4 != 0)
            {
                gotoxy(j + left + 1, i + top);
                putchar(179);
            }
        }
        Sleep(10);
    }

    // Draw horizontal lines
    for (int i = 1; i < size * 8; i++)
    {
        for (int j = 4; j < size * 4; j += 4)
        {
            gotoxy(i + left + 1, j + top);
            if (i % 8 == 0)
                //putchar(197);
                putchar(32);
            else
                putchar(196);
        }
        Sleep(5);
    }
    // Fill cells with random letters A to D
	srand(time(NULL)); // Seed the random number generator with current time
	
	for (int i = 1; i <= size * 4; i+=4)
	{
		for (int j = 8; j <= size * 8; j+=8)
	    {
	        char pokemon = 'H' + rand() % 8; // Generate random letter from A to D
	        gotoxy(left + j - 3, top + i + 1); // Position cursor at center of cell
	        putchar(pokemon); // Print the random letter
	        
	                                  
	        // Store the polemons in the matrix
        	pokemons[i-1][(j-8)/8] = pokemon;
		}
	}
}
void showBoardHard(){

    system("cls");
	ShowCursor(false);
	int left = 2, top = 2, size = 8; 
    gotoxy(left + 1, top);
    putchar(201);
    for (int i = 1; i < size * 8; i++)
    {
        Sleep(5);
        if (i % 8 == 0)
            putchar(205);
        else
            putchar(205);
    }
    putchar(187);

    // Draw right line
    for (int i = 1; i < size * 4; i++)
    {
        Sleep(10);
        gotoxy(size * 8 + left + 1, i + top);
        if (i % 4 != 0)
            putchar(186);
        else
            putchar(186);
    }
    gotoxy(size * 8 + left + 1, size * 4 + top);
    putchar(188);

    // Draw bottom line
    for (int i = 1; i < size * 8; i++)
    {
        gotoxy(size * 8 + left - i + 1, size * 4 + top);
        Sleep(5);
        if (i % 8 == 0)
            putchar(205);
        else
            putchar(205);
    }
    gotoxy(left + 1, size * 4 + top);
    putchar(200);

    // Draw left line
    for (int i = 1; i < size * 4; i++)
    {
        Sleep(10);
        gotoxy(left + 1, size * 4 + top - i);
        if (i % 4 != 0)
            putchar(186);
        else
            putchar(186);
    }

    // Draw vertical lines
    for (int i = 1; i < size * 4; i++)
    {
        for (int j = 8; j < size * 8; j += 8)
        {
            if (i % 4 != 0)
            {
                gotoxy(j + left + 1, i + top);
                putchar(179);
            }
        }
        Sleep(10);
    }

    // Draw horizontal lines
    for (int i = 1; i < size * 8; i++)
    {
        for (int j = 4; j < size * 4; j += 4)
        {
            gotoxy(i + left + 1, j + top);
            if (i % 8 == 0)
                //putchar(197);
                putchar(32);
            else
                putchar(196);
        }
        Sleep(5);
    }
    // Fill cells with random letters A to D
	srand(time(NULL)); // Seed the random number generator with current time
	
	for (int i = 1; i <= size * 4; i+=4)
	{
		for (int j = 8; j <= size * 8; j+=8)
	    {
	        char pokemon = 'H' + rand() % 8; // Generate random letter from A to D
	        gotoxy(left + j - 3, top + i + 1); // Position cursor at center of cell
	        putchar(pokemon); // Print the random letter
	        
	                                  
	        // Store the polemons in the matrix
        	pokemons[i-1][(j-8)/8] = pokemon;
		}
	}
}
//// Move player right and select block
//void Game::moveRight()
//{
//    if (_x < (size-1)*8)
//    {
//        Controller::playSound(MOVE_SOUND);
//        unselectedBlock();
//
//        // Move player position right
//        _x += 8;
//
//        // Select block at new position
//        selectedBlock();
//    }
//    else
//    {
//        Controller::playSound(ERROR_SOUND);
//    }
//}
//
//// Move player left and select block
//void Game::moveLeft()
//{
//    if (_x > 0)
//    {
//        Controller::playSound(MOVE_SOUND);
//        unselectedBlock();
//
//        // Move player position left
//        _x -= 8;
//
//        // Select block at new position
//        selectedBlock();
//    }
//    else
//    {
//        Controller::playSound(ERROR_SOUND);
//    }
//}
//
//// Move player down and select block
//void Game::moveDown()
//{
//    if (_y < (size-1)*4)
//    {
//        Controller::playSound(MOVE_SOUND);
//        unselectedBlock();
//
//        // Move player position down
//        _y += 4;
//
//        // Select block at new position
//        selectedBlock();
//    }
//    else
//    {
//        Controller::playSound(ERROR_SOUND);
//    }
//}
//
//// Move player up and select block
//void Game::moveUp()
//{
//    if (_y > 0)
//    {
//        Controller::playSound(MOVE_SOUND);
//        unselectedBlock();
//
//        // Move player position up
//        _y -= 4;
//
//        // Select block at new position
//        selectedBlock();
//    }
//    else
//    {
//        Controller::playSound(ERROR_SOUND);
//    }
//}
//
//// Select block at player position and display pokemon letter
//void Game::selectedBlock()
//{
//    if (board->getCheck(_x, _y) != _LOCK) {
//        board->selectedBlock(_x, _y, GREEN);
//    }
//
//    char pokemon = pokemons[_y/4][_x/8];
//    gotoxy(_x+2, _y+2);
//    putchar(pokemon);
//}
//
//// Deselect block at player position and clear display
//void Game::unselectedBlock()
//{
//    if (board->getCheck(_x, _y) != _LOCK) {
//        board->unselectedBlock(_x, _y);
//    }
//
//    gotoxy(_x+2, _y+2);
//    putchar(' ');
//}




void Game::printInterface(){
	

	system("cls");
	
//	board->renderBoard();
//	board->buildBoardData();
	if(_mode == _EASY){
        showBoardEasy();
    }
    else if(_mode == _MEDIUM){
        showBoardMedium();
    }
	bool Loop = 1;
	ShowCursor(false);
	while(Loop){ 
		
//		
//		
	    printrectangle(59, 1, 33, 10);
		printrectangle(59, 12, 33, 10);
		
		printrectangle(60, 2, 31, 2);
	   
		gotoxy(67, 3);
		cout << "PLAYER'S INFORMATION";
		
		gotoxy(65, 5);
		if(playerName.empty()) {
		    playerName = "unknown";
		    cout << "Player's name: " << playerName;
		} else {
		    cout << "Player's name: " << playerName;
		}
		gotoxy(65, 7);
		if(playerID == 0) {
		    playerID = -1;
		    cout << "Student's ID: unknown";
		} else {
		    cout << "Student's ID: " << playerID;
		}
		gotoxy(65, 9);
		if(playerClass.empty()) {
		    playerClass = "unknown";
		    cout << "Class: " << playerClass;
		} else {
		    cout << "Class: " << playerClass;
		}
		
		
		printrectangle(60, 13, 31, 2);
		
		gotoxy(69, 14);
		cout << "GAME INFORMATION";
		
		gotoxy(65, 16);
		cout << "Moves:";
		gotoxy(65, 17);
		cout << "Current score:";
		gotoxy(80, 17);
		cout << score;
		
		printrectangle(59, 24, 33, 2);
		printrectangle(59, 27, 14, 2);
		printrectangle(78, 27, 14, 2);
		
		gotoxy(67, 25);
		cout << "M : Move suggestion";
		
		gotoxy(63, 28);
		cout << "H : Help";
		gotoxy(81, 28);
		cout << "Esc : Exit";
		ShowCursor(false);
		
		// Check for keyboard input
    if (_kbhit()) {
        char key = _getch();

        // Implement Move suggestion
//        if (key == 'm' || key == 'M') {
//            board->showPossibleMoves();
//        }
		// Ignore up-arrow key
	    if (key == 72) {
	        continue;
	    }
        // Implement Help
        if (key == 'h' || key == 'H') {
            instructionscreen();
            break;
        }

        // Implement Exit
        if (key == 27) {
            exitscreen();
            break;
        }
        
	    
        
	}
			
}
}
void Game::printInterfaceHard(){
	

	system("cls");
	
//	board->renderBoard();
//	board->buildBoardData();
	showBoardHard();
	bool Loop = 1;
	ShowCursor(false);
	while(Loop){ 
		
//		
//		
	    printrectangle(72, 3, 33, 10);
		printrectangle(72, 14, 33, 10);
		
		printrectangle(73, 4, 31, 2);
	   
		gotoxy(80, 5);
		cout << "PLAYER'S INFORMATION";
		
		gotoxy(78, 7);
		if(playerName.empty()) {
		    playerName = "unknown";
		    cout << "Player's name: " << playerName;
		} else {
		    cout << "Player's name: " << playerName;
		}
		gotoxy(77, 9);
		if(playerID == 0) {
		    playerID = -1;
		    cout << "Student's ID: unknown";
		} else {
		    cout << "Student's ID: " << playerID;
		}
		gotoxy(78, 11);
		if(playerClass.empty()) {
		    playerClass = "unknown";
		    cout << "Class: " << playerClass;
		} else {
		    cout << "Class: " << playerClass;
		}
		
		
		printrectangle(73, 15, 31, 2);
		
		gotoxy(82, 16);
		cout << "GAME INFORMATION";
		
		gotoxy(78, 18);
		cout << "Moves:";
		gotoxy(78, 19);
		cout << "Current score:";
		gotoxy(93, 19);
		cout << score;
		
		printrectangle(72, 26, 33, 2);
		printrectangle(72, 29, 14, 2);
		printrectangle(90, 29, 14, 2);
		
		gotoxy(80, 27);
		cout << "M : Move suggestion";
		
		gotoxy(76, 30);
		cout << "H : Help";
		gotoxy(94, 30);
		cout << "Esc : Exit";
		ShowCursor(false);
		
		// Check for keyboard input
    if (_kbhit()) {
        char key = _getch();

        // Implement Move suggestion
//        if (key == 'm' || key == 'M') {
//            board->showPossibleMoves();
//        }
		// Ignore up-arrow key
	    if (key == 72) {
	        continue;
	    }
        // Implement Help
        if (key == 'h' || key == 'H') {
            instructionscreen();
            break;
        }

        // Implement Exit
        if (key == 27) {
            exitscreen();
            break;
        }
        
	    
        
	}
			
}
}
void Game::startGame() 
{
	system("cls");
	int mapWidth = 6, mapHeight = 6;
	int xCur = 1, yCur = 1;
	
	
	while(isPlaying = true){
		printInterface();
    }
	
	saveData();
}
void Game::startGameHard() 
{
	system("cls");
	int mapWidth = 8, mapHeight = 8;
	int xCur = 1, yCur = 1;
	
	
	while(isPlaying = true){
		printInterfaceHard();
    }
	
	saveData();
}

