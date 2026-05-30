#include <iostream>
#include <string>

void clearScreen() {
    std::cout << "\033[2J\033[H" << std::flush;
}

void pressEnterToContinue() {
    std::cout << "\n[Press ENTER to continue...]\n";
    
    // 1. Clear any leftover characters or newlines in the buffer 
    // from the last time the player typed a number.
    std::cin.ignore(); 
    
    // 2. Wait for the player to press Enter
    std::cin.get(); 
}

enum class Location{
    HOME,
    WILD,
    LABORATORY,
    POKEMON_CENTER
};

class Character{
    public:
        std::string name;
        Location currentLocation = Location::HOME;
};
    

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
                std::cout << main_character.name << ": ";
                std::cin >> choice;
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
                std::cout << main_character.name << ": ";
                std::cin >> choice;
                clearScreen();

                if (choice == 1){
                    std::cout << "Professor Oak: I'm waiting for you, " << main_character.name << "\n";
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
                std::cout << main_character.name << ": ";
                std::cin >> choice;
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
                std::cout << main_character.name << ": ";
                std::cin >> choice;
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
                else{
                    std::cout << "Invalid Option, try again!" << "\n";
                }
                break;
        }
    }

    return 0;
}

