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
    void selectedBlock();
	void unselectedBlock(); 
//    void printBackground();
    void printInterface(); 
    void printInterfaceHard();
	 
	void moveRight();
	void moveLeft();
	void moveUp();
	void moveDown(); 
   

	string playerName;
    int playerID;
    string playerClass;
    int _mode;
    int score;

private:
   
	int _x, _y;
	bool isPlaying;
	int _lockedBlock;
	int _remainBlocks;
	

};

#endif
