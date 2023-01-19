#include "game.h"
#include "playboard.h"

void play_game()
{
    // le jeu est une boucle sans fin
    // qu'on temporise d'un 'delay' de ms entre deux mouvements du serpent
    // (on règle comme cela la vitesse du serpent)

    // la clé qui sera entrée au clavier
    char key = 'l';
    std::deque<int> initiator {87, 86, 85};
    Snake snake(initiator);

    while (true)
    {
        // on efface tout
        backgroundClear();
        reset_board();

        // on écrit le serpent dans le board
        add_snake_to_board(snake);
        // on dessine le board
        // qui contient donc le serpent
        draw_board();

        // on temporise un tour
        sleepOneLap(MS);

        // si un caractère a été entré
        // on le lit sinon ça continue
        
        
        if (keyEvent())
        {
            std::cin >> key;
        }

        // on traite les clés

        


        if (key == 'l')
        {
            if (board.at(snake.snake.front() + 1) == '.')
            {
                snake.moving('l');
            }
            else if (board.at(snake.snake.front() + 1) == '@')
            {
                snake.eating_apple('l');
            }
            else if (board.at(snake.snake.front() + 1) == 'o')
            {
                backgroundClear();
                std::cout<<"GAME OVER"<<std::endl;
                std::cout<<"Score :"<<snake.snake.size()<<std::endl;
            }
            // avec cette clé, on veut déplacer le serpent
            // d'un coup vers la droite
        }
        else if (key == 'i')
        {
            if (board.at(snake.snake.front() - rows) == '.')
            {
                snake.moving('i');
            }
            else if (board.at(snake.snake.front() - rows) == '@')
            {
                snake.eating_apple('i');
            }
            else if (board.at(snake.snake.front() - rows) == 'o')
            {
                backgroundClear();
                std::cout<<"GAME OVER"<<std::endl;
                std::cout<<"Score :"<<snake.snake.size()<<std::endl;
            }
        }
        else if (key == 'j')
        {
            if (board.at(snake.snake.front() - 1) == '.')
            {
                snake.moving('j');
            }
            else if (board.at(snake.snake.front() - 1) == '@')
            {
                snake.eating_apple('j');
            }
            else if (board.at(snake.snake.front() - 1) == 'o')
            {
                backgroundClear();
                std::cout<<"GAME OVER"<<std::endl;
                std::cout<<"Score :"<<snake.snake.size()<<std::endl;
            }
        }

        else if (key == 'k')
        {
            if (board.at(snake.snake.front() + rows) == '.')
            {
                snake.moving('k');
            }
            else if (board.at(snake.snake.front() + rows) == '@')
            {
                snake.eating_apple('k');
            }
            else if (board.at(snake.snake.front() + rows) == 'o')
            {
                backgroundClear();
                std::cout<<"GAME OVER"<<std::endl;
                std::cout<<"Score :"<<snake.snake.size()<<std::endl;
            }
        }
        else if (key == 'q') // on veut quitter la partie
        {
            backgroundClear();
            std::cout << "see you soon little snake !" << std::endl;
            exit(1);
        }
        
    }
}