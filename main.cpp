// Samuel Oseguera
// 5/13/2025
// Final Project - Pokémon Gacha Pull Simulator

#include <iostream>
#include <fstream>
#include <sstream>
#include "gacha.h"

int main() {
    std::vector<Pokemon> pokemons;

    // Open the CSV file that contains the Pokémon data
    std::ifstream file("gen1_pokemon.csv");

    if (!file) {
        std::cerr << "Error: Could not open the file.\n";
        return 1;
    }

    // Read the file line by line and assign rarity based on position
    std::string line;
    std::getline(file, line);

    int count = 0;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string number, name;
        std::getline(ss, number, ','); // Ignores the Pokémon's pokedex number
        std::getline(ss, name, ',');   // Grabs the Pokémon name instead

        // Assigns rarity for the Pokémon based on CSV list position
        int rarity;
        if (count < 10) {
            rarity = 5;
        } else if (count < 30) {
            rarity = 4;
        } else {
            rarity = 3;
        }

        pokemons.push_back({name, rarity});
        ++count;
    }

    file.close();

    std::cout << "Welcome to the Pokémon Gacha Pull Simulator!\n";
    std::cout << "--------------------------------------------\n";
    char choice;
    do {
        // Gives the user the choice to do a single pull or a 10x pull
        std::cout << "Choose pull type:\n";
        std::cout << "1. Single Pull\n"; // Enter 1 for a single pull
        std::cout << "2. 10x Pull\n"; // Enter 2 for a 10x pull
        int pullChoice;
        std::cin >> pullChoice;

        if (pullChoice == 1) {
            //Single pull output
            Pokemon pulled = gachaPull(pokemons);
            std::cout << "You pulled a " << pulled.rarity << "-star Pokémon: " << pulled.name << "\n";
        } else if (pullChoice == 2) {
            // 10x pull output
            std::cout << "Performing 10x pull...\n";
            for (int i = 0; i < 10; ++i) {
                Pokemon pulled = gachaPull(pokemons);
                std::cout << "Pull " << (i + 1) << ": " << pulled.rarity << "-star Pokémon: " << pulled.name << "\n";
            }
        }

        std::cout << "--------------------------------------------\n";

        // Asks if user want to pull again (if yes, gives same option as before)
        std::cout << "Pull again? (y/n): ";
        std::cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    std::cout << "Thanks for playing!\n";
    return 0;
}
