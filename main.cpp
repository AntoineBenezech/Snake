#include "game.h"

// Vous devez réaliser un jeu où un serpent se déplace sur un board.
// On change sa direction avec des touches
// (par exemple: 'i' pour haut, 'k' pour bas, 'j' pour gauche et 'l' pour droite)

// Si le serpent sort du board: le jeu fait game-over.
// Si le serpent se marche dessus: le jeu fait game-over.

// Sur le board apparaissent des pommes que le serpent mange
// (quand il se déplace sur la case où est le fruit)
// Quand le serpent mange un fruit, il grandit d'un anneau.

// Vous avez déjà un début de jeu.
// Améliorez-le en faisant des classes et continuez-le.

// Testez dès que vous ajouter une ligne (j'exagère à peine...).

// N'oubliez pas de vous mettre en gestion de version sous git.
// Committez vos fichiers dès que vous avancez.
// Pour revenir facilement à la version qui marchait...

int main()
{
  play_game();
  return 0;
}
