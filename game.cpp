#include "game.h"
#include "playboard.h"


void play_game()
{
    // le jeu est une boucle sans fin
    // qu'on temporise d'un 'delay' de ms entre deux mouvements du serpent
    // (on règle comme cela la vitesse du serpent)

    // la clé qui sera entrée au clavier
    char key = 'l';

    while (true)
    {
        // on efface tout
        backgroundClear();
        reset_board();

        // on écrit le serpent dans le board
        add_snake_to_board();

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
            // avec cette clé, on veut déplacer le serpent
            // d'un coup vers la droite
        }
        else if (key == 'i')
        {
            // les autres mouvements...
        }
        else if (key == 'q') // on veut quitter la partie
        {
            backgroundClear();
            std::cout << "see you soon little snake !" << std::endl;
            exit(1);
        }
        // et là on fait les actions...
        // déplacement du serpent...
        // le serpent mange la pomme
    }
}