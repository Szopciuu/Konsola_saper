

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class Cell {
public:
    bool isMine;      // zmienna informuj�ca, czy kom�rka jest min�
    bool isRevealed;  // zmienna informuj�ca, czy kom�rka zosta�a odkryta

    Cell() : isMine(false), isRevealed(false) {}
};

class Board {
private:
    int rows;
    int cols;
    int totalMines;
    int totalFreeCells;         // ca�kowita liczba wolnych kom�rek
    int discoveredFreeCells;    // liczba odkrytych wolnych kom�rek
    std::vector<std::vector<Cell>> cells;

public:
    Board(int r, int c, int mines);
    void revealCell(int row, int col);
    void printBoard(bool revealAll = false);
    bool isGameOver(int row, int col);
    bool hasWon() const; // sprawdzanie czy gracz wygra�
};


