// Samuel Oseguera
// 4/29/2025
// Final Project: Start your project assingment

#include <iostream>
#include <vector>
#include <random>

// Struct the represents the Pokemon rarities (3-Star, 4-Star, 5-star)
struct Pokemon {
    std::string name;
    int rarity;
};

// This function here simulates the gacha pull simulator
Pokemon gachaPull(const std::vector<Pokemon>& pokemons) {
    std::random_device rd; // This the the random seed generator
    std::mt19937 gen(rd()); // This is the random number generator
    std::uniform_real_distribution<> dis(0.0, 100.0); // This is the distrubtion for the rarity chances (aka percentages)

    double roll = dis(gen); // Rolls from (0-100)
    int rarity = 3; // Sets default roll to 3-star Pokemon

    /* Lines from 26-44 are based on help I recieved from ChatGPT
     Reasoning for using ChatGPT here was to obtain the average percentage
     distrubution among different gacha games
    */

    //Assigns rarity based on typical gacha chances
    if (roll <= 2.0) {
        rarity = 5; // 2% chance for 5-star
    } else if (roll <= 12.0) {
        rarity = 4; // 10% chance for 4-star
    } // Otherwise, 3-star (88% chance)

    // Filter Pokémon by the selected rarity
    std::vector<Pokemon> filtered;
    for (const auto& p : pokemons) {
        if (p.rarity == rarity) {
            filtered.push_back(p);
        }
    }

    /* Lines from 26-44 are based on help I recieved from ChatGPT
     Reasoning for using ChatGPT here was to obtain the average percentage
     distrubution among different gacha games
    */

    // Randomly select one Pokémon from the filtered list
    std::uniform_int_distribution<> pick(0, filtered.size() - 1);
    return filtered[pick(gen)];
}

int main() {
    // List of Pokemon with their assigned rarities
    std::vector<Pokemon> pokemons = {
        // 5-star Pokémon
        {"Charmander", 5}, {"Squirtle", 5}, {"Bulbasaur", 5},
        // 4-star Pokémon
        {"Arcanine", 4}, {"Lapras", 4}, {"Ghastly", 4}, 
        {"Snorlax", 4}, {"Gyarados", 4},
        // 3-star Pokémon
        {"Rattata", 3}, {"Pidgey", 3}, {"Spearow", 3},
        {"Ekans", 3}, {"Sandshrew", 3}
    };

    std::cout << "Welcome to the Pokemon Gacha Pull Simulator!\n";
    std::cout << "-------------------------------------------- \n";
    char choice;
    do {
        // This performs the pull sim part of the program
        Pokemon pulled = gachaPull(pokemons);
        std::cout << "You pulled a " << pulled.rarity << "-star Pokemon: " << pulled.name << "\n";
        std::cout << "-------------------------------------------- \n";

        // Asks the user if they want to pull again
        std::cout << "Pull again? (y/n): ";
        std::cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    std::cout << "Thanks for playing!\n";
    return 0;
}
