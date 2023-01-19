#include "keyboard-event.h"
#include "playboard.h"

#include <iostream>
#include <vector>
#include <cstdlib>
#include <deque>

// nombre de lignes et de colonne du board
const int rows = 10;
const int columns = 16;

int MS = 600; // milli-secondes (200 pour aller plus vite)

// vecteur représentant le board
std::vector<char> board = std::vector<char>(rows * columns, '.');

// ré-initialise le board
// (ici on le remplit de '.')
void reset_board()
{
  for (int i = 0; i < board.size(); i++)
    board[i] = '.';
}

// dessine le board
void draw_board()
{
  for (int r = 0; r < rows; r++)
  {
    for (int c = 0; c < columns; c++)
      std::cout << board.at(r*columns+c);
    std::cout << std::endl;
  }
}

// dessine le serpent sur le board
void add_snake_to_board(Snake snake)
{
  for (const auto &e : snake.snake)
  {
    board.at(e) = 'o';
  }
  board.at(snake.snake.front()) = 'O';
}
