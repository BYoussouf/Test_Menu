#ifndef HOME_H
#define HOME_H

#include<iostream>
#include<cstdlib>
#include<string>
#include<limits>
#include<termios.h>
#include<unistd.h>
#include<csignal>
#include<cctype>

using namespace std;

extern termios originalTerm;


constexpr const char* RESET = "\033[0m";
constexpr const char* BLACK = "\033[30m";      /* Black */
constexpr const char* RED   =  "\033[31m";      /* Red */
constexpr const char* GREEN = "\033[32m";    /* Green */
constexpr const char* YELLOW = "\033[33m";      /* Yellow */
constexpr const char* BLUE   = "\033[34m";      /* Blue */
constexpr const char* MAGENTA = "\033[35m";      /* Magenta */
constexpr const char* CYAN  =  "\033[36m";      /* Cyan */
constexpr const char* WHITE  = "\033[37m";      /* White */
constexpr const char* BOLDBLACK =  "\033[1m\033[30m";      /* Bold Black */
constexpr const char* BOLDRED   =  "\033[1m\033[31m";      /* Bold Red */
constexpr const char* BOLDGREEN  = "\033[1m\033[32m";      /* Bold Green */
constexpr const char* BOLDYELLOW = "\033[1m\033[33m";      /* Bold Yellow */
constexpr const char* BOLDBLUE   = "\033[1m\033[34m";      /* Bold Blue */
constexpr const char* BOLDMAGENTA = "\033[1m\033[35m";      /* Bold Magenta */
constexpr const char* BOLDCYAN    = "\033[1m\033[36m";      /* Bold Cyan */
constexpr const char* BOLDWHITE   = "\033[1m\033[37m";      /* Bold White */

// Afficher les informations de système (Linux).
void InfoSys(); 

// Afficher la date et l'heure de l'ordinateur.
void DateHeure(); 

// Afficher les fichiers du répertoire actuel.
void Fichiers(); 

// Afficher le répertoire actuel.
void Repertoire(); 

// Affiche le célèbre écran coulissant vert de Matrix.
void MatrixMode(); 

// Vérifie que la saisie de l'utilisateur est valide et bloque les caractères spéciaux.
bool IsValid(const string& s); 

// Permet d'afficher une entité et le message de l'utilisateur.
void CustomCowsay(); 

// Permet de quitter le programme.
void Quitter(); 

// Attend que l'utilisateur appuie sur la touche Entrée.
void WaitForEnter(); 

// Active le mode Raw.
void EnableRawMode(); 

// Permet l'utilisation des touches directionnelles.
char ReadKey(); 

// Désactive le mode Raw.
void DisableRawMode(); 

// Affiche les titres des menus et permet permet de naviguer avec les touches directionnelles.
int Menu(const string& title, const string option[], int count); 

// Restaure le terminal puis quitte le programme. 
void SignalHandler(int signal); 

// Efface le continu de l'écran.
void ClearScreen(); 

#endif // HOME_H


