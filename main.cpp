#include <iostream>
#include <string>
#include <vector>




void clearScreen() {
    std::cout << "\033[2J\033[H" << std::flush;
}

void pressEnterToContinue(){
    std::cout << "\n[Press ENTER to continue...]\n";
    std::cin.get(); 
}

enum class Location{
    HOME,
    WILD,
    LABORATORY,
    POKEMON_CENTER
};

class Pokemon{
    public:
        std::string name;
        int hp;
        int maxHp;
        std::string type;
        Pokemon();
        Pokemon(std::string p_name, int p_hp, int p_maxHp, std::string p_type){
            name = p_name;
            hp = p_hp;
            maxHp = p_maxHp;
            type = p_type;
        }
};

class Character{
    public:
        std::string name;
        Location currentLocation = Location::HOME;
        std::vector<Pokemon> party;
};



//Method Signature
void checkParty(const std::vector<Pokemon>&);
void addPokemonToParty(Pokemon, Character &character);


Pokemon pikachu = Pokemon("Pikachu", 30, 30, "Electric");
Pokemon raychu = Pokemon("Raychu", 60, 60, "Electric");
Pokemon charmender = Pokemon("Charmender", 30, 30, "Fire");
Pokemon charmeleon = Pokemon("Charmeleon", 60, 60, "Fire");
Pokemon charizard = Pokemon("Charizard", 120, 120, "Fire");
Pokemon squirtle = Pokemon("Squirtle", 30, 30, "Water");
Pokemon wartortle = Pokemon("Wartortle", 60, 60, "Water");
Pokemon blastoise = Pokemon("Blastoise", 120, 120, "Water");
Pokemon pysduck = Pokemon("Psyduck", 30, 30, "Water");
Pokemon bellsprout = Pokemon("Bellsprout", 30, 30, "Grass");

int main(){
    std::cout << "Welcome to the Pokemon World!" << "\n";
    Character main_character;
    std::cout << "What is your name?: ";
    std::getline(std::cin, main_character.name);
    std::cout << "Welcome, " << main_character.name << " to the Pokemon World." << "\n";
    std::cout << "........................." << "\n";
    pressEnterToContinue();

    bool isRunning = true;
    std::cout << "The game is running now" << "\n";
    while(isRunning){
        int choice = 0;
        clearScreen();
        switch(main_character.currentLocation){
            case Location::HOME:
                std::cout << "You are at home now, what do you want to do now?" << "\n";
                std::cout << " 1. Talk with Mom" << "\n";
                std::cout << " 2. Go to lab" << "\n";
                std::cout << " 3. Go to Wild" << "\n";
                std::cout << " 4. Go to Pokemon Center" << "\n";
                std::cout << " 0. Quit Game" << "\n";
                std::cout << "Check Pokemon - p" << "\n";
                std::cout << main_character.name << ": ";
                std::cin >> choice;
                std::cin.ignore(256, '\n');
                clearScreen();

                if (choice == 1){
                    std::cout << "Mom: " << main_character.name << " ,Professor Oak is waiting you at the lab, you might want to meet him." << "\n";
                    pressEnterToContinue();
                } 
                else if (choice == 2){
                    main_character.currentLocation = Location::LABORATORY;
                }
                else if (choice == 3){
                    main_character.currentLocation = Location::WILD;
                }
                else if (choice == 4){
                    main_character.currentLocation = Location::POKEMON_CENTER;
                }
                else if (choice == 0){
                    isRunning = false;
                    std::cout << "Exiting Game Now......" << "\n";
                }
                else if (choice == 10){
                    checkParty(main_character.party);
                }
                else{
                    std::cout << "Invalid Option, try again!" << "\n";
                }
                break;
            
            case Location::LABORATORY:
                std::cout << "You are at Laboratory now, what do you want to do now?" << "\n";
                std::cout << " 1. Talk with Professor Oak" << "\n";
                std::cout << " 2. Go to Home" << "\n";
                std::cout << " 3. Go to Wild" << "\n";
                std::cout << " 4. Go to Pokemon Center" << "\n";
                std::cout << " 0. Quit Game"<< "\n";
                std::cout << "Check Pokemon - 10" << "\n";
                std::cout << main_character.name << ": ";
                std::cin >> choice;
                std::cin.ignore(256, '\n');
                clearScreen();

                if (choice == 1){
                    std::cout << "Professor Oak: I'm waiting for you, " << main_character.name << "\n";
                    if (main_character.party.empty() == 1){
                        std::cout << "Professor Oak: I see you don't have a Pokemon yet," << main_character.name << "\n";
                        std::cout << "Professor Oak: Take this Pikachu as your starter" << "\n";
                        addPokemonToParty(pikachu, main_character);
                        std::cout << "[Pikachu had been added into your party!]" << "\n";
                    }
                    pressEnterToContinue();
                }
                else if (choice == 2){
                    main_character.currentLocation = Location::HOME;
                }
                else if (choice == 3){
                    main_character.currentLocation = Location::WILD;
                }
                else if (choice == 4){
                    main_character.currentLocation = Location::POKEMON_CENTER;
                }
                else if (choice == 0){
                    isRunning = false;
                    std::cout << "Exiting Game Now......" << "\n";
                }
                else if (choice == 10){
                    checkParty(main_character.party);
                }
                else{
                    std::cout << "Invalid Option, try again!" << "\n";
                }
                break;

            case Location::WILD:
                std::cout << "You are at the wild now, what do you want to do?" << "\n";
                std::cout << " 1. Find Pokemon in bush" << "\n";
                std::cout << " 2. Go to Lab" << "\n";
                std::cout << " 3. Go to Home" << "\n";
                std::cout << " 4. Go to Pokemon Center" << "\n";
                std::cout << " 0. Quit Game"<< "\n";
                std::cout << "Check Pokemon - p" << "\n";
                std::cout << main_character.name << ": ";
                std::cin >> choice;
                std::cin.ignore(256, '\n');
                clearScreen();

                if (choice == 1){
                    std::cout << "You do not have a pokemon yet, it is not safe!" << "\n";
                    pressEnterToContinue();
                }   
                else if (choice == 2){
                    main_character.currentLocation = Location::LABORATORY;
                }
                else if (choice == 3){
                    main_character.currentLocation = Location::HOME;
                }
                else if (choice == 4){
                    main_character.currentLocation = Location::POKEMON_CENTER;
                }
                else if (choice == 0){
                    isRunning = false;
                    std::cout << "Exiting Game Now......" << "\n";
                }
                else if (choice == 10){
                    checkParty(main_character.party);
                }
                else{
                    std::cout << "Invalid Option, try again!" << "\n";
                }
                break;

            case Location::POKEMON_CENTER:
                std::cout << "You are at the Pokemon Center now, what do you want to do?" << "\n";
                std::cout << " 1. Heal my Pokemon" << "\n";
                std::cout << " 2. Go to Lab" << "\n";
                std::cout << " 3. Go to Home" << "\n";
                std::cout << " 4. Go to Wild" << "\n";
                std::cout << " 0. Quit Game"<< "\n";
                std::cout << "Check Pokemon - p" << "\n";
                std::cout << main_character.name << ": ";
                std::cin >> choice;
                std::cin.ignore(256, '\n');
                clearScreen();

                if (choice == 1){
                    std::cout << "You do not have a pokemon yet, no point doint this!" << "\n";
                    pressEnterToContinue();
                }   
                else if (choice == 2){
                    main_character.currentLocation = Location::LABORATORY;
                }
                else if (choice == 3){
                    main_character.currentLocation = Location::HOME;
                }
                else if (choice == 4){
                    main_character.currentLocation = Location::WILD;
                }
                else if (choice == 0){
                    isRunning = false;
                    std::cout << "Exiting Game Now......" << "\n";
                }
                else if (choice == 10){
                    checkParty(main_character.party);
                }
                else{
                    std::cout << "Invalid Option, try again!" << "\n";
                }
                break;
        }
    }

    return 0;
}

void addPokemonToParty(Pokemon p, Character &character){
    character.party.push_back(p);
}

void checkParty(const std::vector<Pokemon>& p){
    if(p.empty() == 1){
        std::cout << "You don't have any pokemon yet!" << "\n";
    }
    else{
        std::cout << "Pokemon Party's List" << "\n";
        for(Pokemon pokemon: p){
            std::cout << pokemon.name << "\t" << "HP:" << pokemon.hp << "/" << pokemon.maxHp << "\t" << pokemon.type << "\n";
        }
    }
    pressEnterToContinue();
}

