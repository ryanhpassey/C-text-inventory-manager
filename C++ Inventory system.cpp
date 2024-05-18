// Online C++ compiler to run C++ program online
using namespace std;
#include <iostream>
#include <list>
#include <string>


// Base class for all collectables
class Collectable {
    protected:
        string _name;
        double _cost;
        double _rating; 
    
    // Public setter methods
    public:
        void SetName(){
            cout << "Name it: ";
            cin.ignore(1000,'\n');
            getline(cin, _name);
        }
        
        void SetCost(){
            cout << "How much was it? $";
            cin >> _cost;
        }
        
        void SetRating(){
            cout << "What would you rate it? (/10)";
            cin >> _rating;
            cin.ignore(1000,'\n');
        }
        
        virtual void SetInfo() {
            SetName();
            SetCost();
            SetRating();
        }
        
        // Formats and prints the info
        virtual void PrintInfo() {
            cout << _name << endl;
            cout << "$" << _cost << endl;
            cout << _rating << "/10" << endl;
        }
};


class Vinyl : public Collectable {
    private:
        int _hours;
        int _minutes;
        string _artist;
    
        // Public setter methods
        void SetLength(){
            cout << "How many hours long?: ";
            cin >> _hours;
            cout << "How many minutes long? ";
            cin >> _minutes;
        }
    
        void SetArtist(){
            cout << "Who's the artist? ";
            cin.ignore(1000,'\n');
            getline(cin, _artist);
        }
        
    public:
        void SetInfo(){
            SetName();
            SetCost();
            SetLength();
            SetArtist();
            SetRating();
        }
        
        // Formats and prints the info
        void PrintInfo(){
            cout << _name << endl;
            cout << "By: " << _artist << endl;
            cout << "$" << _cost << endl;
            cout << "Length: " << _hours << ":" << _minutes << endl;
        }
};


class Videogame : public Collectable {
    private: 
        string _system;
        string _series;
    
    public:
        // Public setter methods
        void SetSystem(){
            cout << "What system did you buy it for? ";
            cin.ignore(1000,'\n');
            getline(cin, _system);
        }
        
        void SetSeries(){
            cout << "What's the game series? ";
            getline(cin, _series);
        }
        
        void SetInfo(){
            SetName();
            SetCost();
            SetSystem();
            SetSeries();
            SetRating();
        }
        
        // Formats and prints the info
        void PrintInfo(){
            cout << _name << endl;
            cout << _series << endl;
            cout << "$" << _cost << "for" << _system << endl;
            cout << _rating << "/10" << endl;
        }
};

class Figurine : public Collectable {
    private:
        string _series;
        string _brand;
    
    public:
        // Public setter methods
        void SetInfo(){
            SetName();
            SetCost();
            SetBrand();
            SetSeries();
            SetRating();
        }
    
        void SetSeries(){
            cout << "What's the origin series? ";
            cin.ignore(1000,'\n');
            getline(cin, _series);
        }
        void SetBrand(){
            cout << "What brand of figurine? ";
            cin.ignore(1000,'\n');
            getline(cin, _brand);
        }
        
        // Formats and prints the info
        void PrintInfo() {
            cout << _name << endl;
            cout << _series << "series" << endl;
            cout << "$" << _cost << endl;
            cout << _rating << "/10" << endl;
        }
};

list<Vinyl> Vinyls;
list<Figurine> Figures;
list<Videogame> Videogames;

// 3 for loops for each list to call their print methods
// Originally intended to be one loop
void PrintAll(){
    cout << "\n\nVinyls: \n";
    for (Vinyl collectable : Vinyls){
        cout << endl;
        collectable.PrintInfo();
    }
    cout << "\n\nVideogames: \n";
    for (Videogame collectable : Videogames){
        cout << endl;
        collectable.PrintInfo();
    }
    cout << "\n\nFigurines: \n";
    for (Figurine collectable : Figures){
        cout << endl;
        collectable.PrintInfo();
    }
}

// Creates an object of the given class
// uses an int parameter from the user
void CreateNewCollectable(int selection){
    switch(selection){
        case 1:
        {
            Vinyl newVinyl;
            newVinyl.SetInfo();
            Vinyls.push_front(newVinyl);
            return ;
        }
        case 2:
        {
            Videogame newVideogame;
            newVideogame.SetInfo();
            Videogames.push_front(newVideogame);
            return;
        }
        case 3:
        {
            Figurine newFigure;
            newFigure.SetInfo();
            Figures.push_front(newFigure);
            return;
        }
        default:
            return;
    }
}

// Ensures that user input is in range. Bool
bool ValidateInput(int selection, int max){
    if (selection < 1 || selection > max){
        cout << "\nInvalid entry\n\n";
        return false;
    }
    else{
        return true;
    }
}

// Create a collectable text menu
int promptCreateCollectable(){
    int selection;
    do{
        cout << "What kind of collectable?\n";
        cout << "1. Vinyl\n2. Videogame\n3. Figurine\n4. Quit\n";
        cin >> selection;
    }
    while (!ValidateInput(selection, 4));
    
    return selection;
}

// Text main menu
int PromptMainMenu(){
    int selection;
    do{
        cout << "\nWhat are we doing today? Type the number:\n";
        cout << "1. Add new collectable\n2. View List\n3. Quit\n";
        cin >> selection;
    }
    while (!ValidateInput(selection, 3));
    
    return selection;
}

// Calls the necesary methods in the proper order to run the main menu
void RunMainMenu(){
    bool quit = false;
    
    while (true){
        int selection = PromptMainMenu();
        switch (selection){
            case 1: // Add a collectable
                selection = promptCreateCollectable();
                if (selection == 4){
                    break;
                }
                else{
                    CreateNewCollectable(selection);
                    break;
                }
            case 2: // View list of collectables
                PrintAll();
                break;
            case 3: // Quit
                return;
            case 4: // Save list
                break;
            case 5: // Load collectable list
                break;
        }
    }
}


// main
int main() {
    RunMainMenu();

    return 0;
}