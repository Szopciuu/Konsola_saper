#include <iostream>
#include "saper.h"

int main() {
    int rows, cols, mines;

    //  wprowadzenie wymiarów planszy i liczby min
    std::cout << "Podaj liczbe wierszy: ";
    std::cin >> rows;
    std::cout << "Podaj liczbe kolumn: ";
    std::cin >> cols;
    std::cout << "Podaj liczbe min: ";
    std::cin >> mines;

    // tworzenie planszy
    Board board(rows, cols, mines);
    bool gameOver = false;

    while (!gameOver) {
        board.printBoard();
        int row, col;
        std::cout << "Podaj wspolrzedne (wiersz - spacja - kolumna): ";
        std::cin >> row >> col;

        // sprawdzenie, czy podane wspó³rzêdne s¹ w odpowiednich granicach
        if (row < 0 || row >= rows || col < 0 || col >= cols) {
            std::cout << "Nieprawidlowe wspolrzedne! Sprobuj ponownie." << std::endl;
            continue;
        }

        board.revealCell(row, col);

        // informacja o tym, co odkryto
        if (board.isGameOver(row, col)) {
            std::cout << "Przegrales! Odkryles mine!" << std::endl;
            gameOver = true;
        }
        else {
            std::cout << "Odkryles bezpieczna komorke." << std::endl;

            // sprawdzenie, czy gracz wygra³
            if (board.hasWon()) {
                std::cout << "Gratulacje! Wygrales gre!" << std::endl;
                gameOver = true;
            }
        }
    }

    std::cout << "Plansza po zakonczeniu gry:" << std::endl;
    board.printBoard(true);
    return 0;
}
