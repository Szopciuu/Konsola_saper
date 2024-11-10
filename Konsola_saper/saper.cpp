#include "saper.h"

// konstruktor planszy
Board::Board(int r, int c, int mines) : rows(r), cols(c), totalMines(mines),
totalFreeCells((r* c) - mines), discoveredFreeCells(0),
cells(r, std::vector<Cell>(c)) {
    std::srand(std::time(0));
    // losowanie min
    for (int i = 0; i < mines; ++i) {
        int mineRow = std::rand() % rows;
        int mineCol = std::rand() % cols;
        if (!cells[mineRow][mineCol].isMine) {
            cells[mineRow][mineCol].isMine = true;
        }
        else {
            --i; // próbuj ponownie, jeśli miny się pokryły
        }
    }
}

// odkrycie komórki
void Board::revealCell(int row, int col) {
    if (row < 0 || row >= rows || col < 0 || col >= cols) return;
    if (cells[row][col].isRevealed) return;

    cells[row][col].isRevealed = true;

    // zwiększanie licznika odkrytych wolnych komórek, jeśli komórka nie jest miną
    if (!cells[row][col].isMine) {
        discoveredFreeCells++;
    }
}

// wypisz plansze
void Board::printBoard(bool revealAll) {
    // numeracja kolumn
    std::cout << "   ";
    for (int j = 0; j < cols; ++j) {
        std::cout << j << " ";
    }
    std::cout << std::endl;

    // numerowanie wierszy i wypisanie planszy
    for (int i = 0; i < rows; ++i) {
        std::cout << i << " | "; // numeracja wierszy
        for (int j = 0; j < cols; ++j) {
            if (revealAll || cells[i][j].isRevealed) {
                if (cells[i][j].isMine) {
                    std::cout << "* "; // wyświetlenie miny
                }
                else {
                    std::cout << " 0 "; // pusta komórka
                }
            }
            else {
                std::cout << "# "; // ukryta komórka
            }
        }
        std::cout << std::endl;
    }
}

// sprawdzenie, czy gra się skończyła
bool Board::isGameOver(int row, int col) {
    return cells[row][col].isMine;
}

// sprawdzenie, czy gracz wygrał
bool Board::hasWon() const {
    return discoveredFreeCells == totalFreeCells; // Jeśli wszystkie wolne komórki zostały odkryte
}
