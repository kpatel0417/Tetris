#pragma once
#include "grid.h"
#include "blocks.cpp"
#include "block.h"

class Game {
    public:
        Game();
        void Draw();
        void HandleInput();
        void MoveBlockDown();
        bool gameOver;
        int score;

    private:
        Block GetRandomBlock();
        std::vector<Block> GetAllBlocks();
        bool IsBlockOutside();
        void MoveBlockLeft();
        void MoveBlockRight();
        void RotateBlock();
        void LockBlock();
        bool BlockFits();
        void Reset();
        void UpdateScore(int linesCleared, int moveDownPoints);
        std::vector<Block> blocks;
        Grid grid;
        Block currentBlock;
        Block nextBlock;

};