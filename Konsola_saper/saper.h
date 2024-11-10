

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class Cell {
public:
    bool isMine;      // zmienna informuj¹ca, czy komórka jest min¹
    bool isRevealed;  // zmienna informuj¹ca, czy komórka zosta³a odkryta

    Cell() : isMine(false), isRevealed(false) {}
};

class Board {
private:
    int rows;
    int cols;
    int totalMines;
    int totalFreeCells;         // ca³kowita liczba wolnych komórek
    int discoveredFreeCells;    // liczba odkrytych wolnych komórek
    std::vector<std::vector<Cell>> cells;

public:
    Board(int r, int c, int mines);
    void revealCell(int row, int col);
    void printBoard(bool revealAll = false);
    bool isGameOver(int row, int col);
    bool hasWon() const; // sprawdzanie czy gracz wygra³
};


