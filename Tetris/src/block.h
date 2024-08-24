#pragma once
#include <map>
#include <vector>
#include "position.h"
#include "colors.h"

class Block {
    public:
        Block();
        void Draw(int offsetX, int offsetY);
        void Move(int rows, int columns);
        void Rotate();
        void UndoRotation();
        std::vector<Position> GetCellPosition();
        int id;
        std::map<int, std::vector<Position>> cells;
    private:
        int cellSize;
        int rotationState;
        std::vector<Color> colors;
        int rowOffset;
        int colOffset;
};