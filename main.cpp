/*
------------------------------------------------------------------------------
  Fichier     : main.cpp
  Auteur(s)   : Morgan Dussault
  Date        : 07.10.26

  But         : identifier tous les nombres premiers compris
                et une valeur choisie par l'utilisateur

  Remarque(s) : les erreurs de saisie ne sont pas vérifiées

  Compilateur : gcc
  ------------------------------------------------------------------------------
*/

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <limits>

int main() {

    const short n_col = 5; // nombre de colones lors de l'affichage des nombre premiers
    char restart;
    unsigned short spacing = 7;

    do {
        short limite;
        do {// 2. Saisie de la limite par l'utilisateur
            std::cout << "entrer une valeur [2-1000] : ";
            std::cin >> limite;
            // vide le buffer
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }while (!(2<limite && limite<1000));

        std::cout << std::endl << "Voici la liste des nombres premiers: " << std::endl;

        // 3. Calculs des nombres premiers et affichage
        short numberOuputed = 0; // nombre de nombre écris sur la ligne actuelle
        std::cout << std::setw(spacing) << '2'; ++numberOuputed;
        for (int i = 1; i <= limite; ++i) {
            if (i != 1) { // enleve 1 car pas un nombre premier
                int j;
                if (i%2 != 0) { // si l nombre est pas
                    for (j = 3; j < (i/2)+1; j+=2) { // fait le modulo avec tous les nombres impaire avant lui
                        if (i%j == 0) break; // si le nombre est pas premier, on quite la boucle
                    }
                    if (!(j<(i/2)+1)) { // si le nombre est premier
                        std::cout << std::setw(spacing) << i;
                        if (!(++numberOuputed % n_col)) std::cout << std::endl;
                    }
                }

            }
        }

        // 4. Demander à l'utilisateur si il veut recommencer
        do {
            std::cout << std::endl << std::endl << "Voulez-vous recommencer [O/N] : ";
            std::cin >> restart;
        }while (!(restart == 'O' || restart == 'N'));
        std::cout << std::endl;
    }while(restart == 'O');

    return EXIT_SUCCESS;
}
