#include "home.hpp"

int main()
{
    signal(SIGINT, SignalHandler); 

    int choice;

    string options[] = 
    {
        "Informations système",
        "Heure est date",
        "Liste des fichiers",
        "Répertoire courant",
        "Fun Menu",
        "Quitter",
    };

    while (true)
    {
        choice = Menu("HOME TERMINAL", options, 6);

    switch (choice)
    {
        case 0:
            InfoSys();
            break;
        case 1:
            DateHeure();
            break;
        case 2:
            Fichiers();
            break;
        case 3:
            Repertoire();
            break;
        case 4:
            {
                bool inSubMenu = true;
                int subchoice;

                string funOptions[]
               {
                    "Matrix",
                    "Talking animal",
                    "Retour"
               };

               while (inSubMenu)
               {

                    subchoice = Menu("FUN MENU", funOptions, 3);
               
                switch (subchoice)
                {
                case 0:
                    MatrixMode();
                    break;
                case 1:
                    CustomCowsay();
                    WaitForEnter();
                    break;
                case 2:
                    inSubMenu = false; 
                        break;

                default:
                    cout << "Option invalide!" << endl;
                    
                }

                //cout << endl << "Appuyez sur la touche Entrée pour continuer...";
                //cin.ignore();
                //cin.get();
                }    
            }
            break;

        case 5:
            Quitter();
            return 0;

        default:
            cout << "Option invalide!"<<endl;
    }

    WaitForEnter();

    }

}