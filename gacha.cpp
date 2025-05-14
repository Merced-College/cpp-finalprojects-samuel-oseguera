// Samuel Oseguera
// 5/13/2025
// Final Project

#include "gacha.h"
#include <random>
#include <iostream>


Pokemon gachaPull(const std::vector<Pokemon>& pokemons) {
    // Set up random number generation to simulate gacha roll (0 to 100)
    // ChatGPT was used to help understand how to implement std::random_device and std::uniform_real_distribution
    // Citation: OpenAI. (2025). ChatGPT [Large language model]. https://chat.openai.com
    std::random_device rd; 
    std::mt19937 gen(rd()); 
    std::uniform_real_distribution<> dis(0.0, 100.0); 

    double roll = dis(gen); // Rolls from (0-100)
    int rarity = 3; // Sets default roll to 3-star Pokemon

    //Assigns rarity based on typical gacha chances
    
    if (roll <= 2.0) {
        rarity = 5;
    } else if (roll <= 12.0) {
        rarity = 4;
    }

    // Filter Pokémon by the selected rarity
    std::vector<Pokemon> filtered;
    for (const auto& p : pokemons) {
        if (p.rarity == rarity) {
            filtered.push_back(p);
        }
    }

    // Randomly select one Pokémon from the filtered list
    std::uniform_int_distribution<> pick(0, filtered.size() - 1);
    return filtered[pick(gen)];
}
