#include "home.hpp"

termios originalTerm;

// Efface le continu de l'écran en utilisant une commande ANSI.
void ClearScreen()
{
    cout << "\033[2J\033[H"; 
}

// Afficher les informations de système (Linux).
void InfoSys()
{
    system("fastfetch");
}

// Afficher la date et l'heure de l'ordinateur.
void DateHeure()
{
    system("date");
}

// Afficher les fichiers du répertoire actuel.
void Fichiers()
{
    system("ls -lah");
}

// Afficher le répertoire actuel.
void Repertoire()
{
    system("pwd");
}

// Affiche l'écran coulissant vert de Matrix.
void MatrixMode()
{
    system("cmatrix");
}

// Vérifie que la saisie de l'utilisateur est valide et bloque les caractères spéciaux.
bool IsValid(const string& s)
{
    if (s.empty())
        return false;

    for (char c : s)
    {
        if(!isalnum(static_cast<unsigned char>(c)) && 
            c != '_' && 
            c != '-')
        {
            return false;
        }
    }
        return true;
}

// Permet d'afficher une entité et le message de l'utilisateur.
void CustomCowsay()
{
    string animal;
    string message;

    system("cowsay -l | tr '\\n' ' '");

    cout << endl << endl << "Veuillez entrer le nom de l'entité de votre choix :";
    cin >> animal;

    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

    cout << endl << "Veuillez entrer le message que vous voulez afficher :";
    getline(cin, message);

    if (!IsValid(animal))
    {
        cout << "Nom d'entité invalide !" << endl;
        return;
    }
    
    if (message.size() > 200 )
    {
        cout << "Message trop long !" << endl;
        return;
    }

    for (char &c : message)
    {
        if (c == '"')
            c = '\'';
    }

    string command = "cowsay -f " + animal + " \"" + message + "\"";

    int result = system(command.c_str());

    if (result != 0)
    {
        cout << "Erreur lors de l'éxéction de cowsay." << endl;
    }

}

// Permet de quitter le programme.
void Quitter()
{
    cout << endl << "Goodbye!"<<endl;
}

// Attend que l'utilisateur appuie sur la touche Entrée.
void WaitForEnter()
{
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << endl <<"Appuyez sur Entrée pour continuer...";
    cin.get();
}

// Active le mode Raw.
void EnableRawMode()
{
    tcgetattr(STDIN_FILENO, &originalTerm);

    termios raw = originalTerm;
    raw.c_lflag &= ~(ICANON | ECHO); 

    tcsetattr(STDIN_FILENO, TCSANOW, &raw);
}

// Permet l'utilisation des touches directionnelles.
char ReadKey()
{
    char c;
    if (read(STDIN_FILENO, &c, 1) != 1)
    {
        return '\0';
    }

    if (c == 27) //ESC
    {
        char seq[2];
        read(STDIN_FILENO, &seq[0], 1);
        read(STDIN_FILENO, &seq[1], 1);

        if (seq[0] == '[')
        {
            if (seq[1] == 'A') return 'U'; // UP
            if (seq[1] == 'B') return 'D'; // Down
        }
    }

    return c;
}

// Désactive le mode Raw.
void DisableRawMode()
{
    tcsetattr(STDIN_FILENO, TCSANOW, &originalTerm);
}

// Affiche les titres des menus et permet permet de naviguer avec les touches directionnelles.
int Menu(const string& title, const string option[], int count)
{
    int selected = 0;

    EnableRawMode();

    while (true)
    {
        ClearScreen();
        cout << "======" << BOLDRED << title << RESET << "=======" << endl << endl;
        
        for (int i = 0; i < count; i++)
        {
            if (i == selected)
            
                cout << BOLDGREEN << "> " << option[i] << RESET << endl;
            else
                cout << " " << option[i] << endl;  
        }

        char key = ReadKey();

        switch (key)
        {
        case 'U':  //fléche haut
            if (selected > 0)
                selected--; 
            break;
        case 'D': //fléche bas
            if (selected < count - 1)
                selected++;
            break;

        case '\n': //Entrée
        case '\r':
            DisableRawMode();
            return selected; 
        }
    }
}

// Restaure le terminal puis quitte le programme. 
void SignalHandler(int)
{
    DisableRawMode();
    exit(0);
}


