#include <iostream>
#include <vector>
#include "keyboard-event.h"
#include <deque>

// nombre de lignes et de colonne du board
extern const int rows;
extern const int columns;
extern int apple;
extern int MS; // milli-secondes

// vecteur représentant le board
extern std::vector<char> board;

// ré-initialise le board
void reset_board();

// dessine le board
void draw_board();


class Snake
{
  public:
    std::deque<int> snake;
    Snake(std::deque<int>& initiator): snake(initiator){
        srand(time(NULL));
    };
    void moving(char e)
    
    {
        if (e == 'l')
        {
            snake.pop_back();
            snake.push_front(snake.front() + 1);
        }
        else if (e == 'j')
        {
            snake.pop_back();
            snake.push_front(snake.front() - 1);
        }
        else if (e == 'i')
        {
            snake.pop_back();
            snake.push_front(snake.front()-columns);
        }
        else if (e == 'k')
        {
            snake.pop_back();
            snake.push_front(snake.front() + columns);
        }
    };
    
    
    void eating_apple(char e)
    {
        srand(time(NULL));
        
        if (e == 'l')
        {
            snake.push_front(snake.front() + 1);
        }
        else if (e == 'j')
        {
            snake.push_front(snake.front() - 1);
        }
        else if (e == 'i')
        {
            snake.push_front(snake.front()-columns);
        }
        else if (e == 'k')
        {
            snake.push_front(snake.front() + columns);
        }
        apple = rand()%(rows*columns);
        while (board.at(apple) == '.')
        {
            apple = rand()%(rows*columns);
        }
    };
    int front()
    {
        return snake.front();
    }
};

void add_apple_to_board();


// dessine le serpent sur le board
void add_snake_to_board(Snake snake);

void speed(Snake snake);