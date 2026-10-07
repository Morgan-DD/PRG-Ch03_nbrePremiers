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

int main() {

    const short n_col = 8; // nombre de colones lors de l'affichage des nombre premiers
    char restart;
    do {
        short limite;
        do {// 2. Saisie de la limite par l'utilisateur
            std::cout << "entrer une valeur [2-1000] : ";
            std::cin >> limite;
        }while (!(2<limite && limite<1000));

        std::cout << std::endl << "Voici la liste des nombres premiers: " << std::endl;

        // 3. Calculs des nombres premiers et affichage
        short numberOuputed = 0; // nombre de nombre écris sur la ligne actuelle
        for (int i = 1; i <= limite; ++i) {
            if (i != 1) { // enleve 1 car pas un nombre premier
                int j;
                for (j = 2; j < i; ++j) { // fait le modulo avec tous les nombres avant lui
                    if (i%j == 0) break;
                }
                if (!(j<i)) { // si le nombre est premier
                    std::cout << std::setw(7) << i;
                    if (!(++numberOuputed % n_col)) std::cout << std::endl;
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
