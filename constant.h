#ifndef CONSTANT_H_
#define CONSTANT_H_

// configuration
const int SPRITESIZE = 64;
const int WINDOW_WIDTH = 1024;
const int WINDOW_HEIGHT = 768;
const int LEVEL_NUM = 20;
const float MAP_SCALE = 0.7f;

// block
const int GROUND = 0;
const int WALL = 1;
const int BOX = 2;
const int TARGET = 3;
const int TARGET_FILLED = 4;
const int PLAYER = 5;

enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

#endif