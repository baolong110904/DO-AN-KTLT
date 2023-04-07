#ifndef GAME_H
#define GAME_H

#include "BoardView.h"
#include "Controller.h"

#include <string>

class Game {
public:
	Board* board;
	Game(int mode) : _mode(mode) {}
    void setupGame();
    void saveData();
    void startGame();
    void startGameHard();
    
//    void printBackground();
    void printInterface(); 
    void printInterfaceHard();
	void displayStartMenu();
//	
//	void selectedBlock();
//	void unselectedBlock();
//	
//	void moveRight();
//	void moveLeft();
//	void moveUp();
//	void moveDown(); 
   

	char playerName[50];
	char playerClass[20];
    char playerID[20];
    int _mode;
    int score;

private:
   
	int _x, _y;
	bool isPlaying;
	int _lockedBlock;
	int _remainBlocks;
	

};

#endif
