#include "keyboard-event.h"
#include "playboard.h"

#include <iostream>
#include <vector>
#include <cstdlib>
#include <deque>
#include <chrono>
#include <random>


std::default_random_engine re;

// nombre de lignes et de colonne du board
const int rows = 10;
const int columns = 16;
int apple = 2;

int MS = 600; // milli-secondes (200 pour aller plus vite)

// vecteur représentant le board
std::vector<char> board = std::vector<char>(rows * columns, '.');
//Position de la pomme
//int apple = std::uniform_int_distribution<int> distrib{0, 10 * 16};

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


void add_apple_to_board()
{
  if (board.at(apple) == '.')
  {
    board.at(apple) = '@';
  }
  else
  {
    apple = rand()%(rows * columns);
    add_apple_to_board();
  }

};

void speed(Snake snake)
{
  for(auto k :snake.snake)
  {
    MS = 700;
    if (MS >= 100)
    {
      MS = MS*0.90;
    }
  }
}