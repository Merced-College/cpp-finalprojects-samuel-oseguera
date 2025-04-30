#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <map>
#include <algorithm>

struct Pokemon {
    std::string name;
    int rarity; // 3, 4, or 5
};

std::vector<Pokemon> loadKantoPokemon() {
    std::vector<Pokemon> pokemons = {
        // 5-star Pokémon (1.5% chance)
        {"Charizard", 5}, {"Blastoise", 5}, {"Venusaur", 5},
        {"Pikachu", 5}, {"Mewtwo", 5}, {"Mew", 5}, {"Dragonite", 5},
        {"Gengar", 5}, {"Alakazam", 5},

        // 4-star Pokémon (5.5% chance)
        {"Arcanine", 4}, {"Lapras", 4}, {"Machamp", 4}, {"Snorlax", 4},
        {"Gyarados", 4}, {"Scyther", 4}, {"Nidoking", 4}, {"Nidoqueen", 4},
        {"Jolteon", 4}, {"Flareon", 4}, {"Vaporeon", 4},

        // 3-star Pokémon (common, 93% chance)
        {"Rattata", 3}, {"Pidgey", 3}, {"Zubat", 3}, {"Ekans", 3},
        {"Sandshrew", 3}, {"Paras", 3}, {"Meowth", 3}, {"Ponyta", 3},
        {"Magnemite", 3}, {"Doduo", 3}, {"Seel", 3}, {"Shellder", 3},
        {"Drowzee", 3}, {"Voltorb", 3}, {"Krabby", 3}, {"Exeggcute", 3},
        {"Cubone", 3}, {"Koffing", 3}, {"Horsea", 3}, {"Goldeen", 3}
    };

    return pokemons;
}

Pokemon gachaPull(const std::vector<Pokemon>& pokemons) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 100.0);
    double roll = dis(gen);

    int rarity = 3;
    if (roll <= 1.5) rarity = 5;
    else if (roll <= 7.0) rarity = 4;

    // Filter Pokémon by rarity
    std::vector<Pokemon> filtered;
    std::copy_if(pokemons.begin(), pokemons.end(), std::back_inserter(filtered),
                 [rarity](const Pokemon& p) { return p.rarity == rarity; });

    std::uniform_int_distribution<> pick(0, filtered.size() - 1);
    return filtered[pick(gen)];
}

int main() {
    std::vector<Pokemon> pokemons = loadKantoPokemon();

    char choice;
    do {
        Pokemon pulled = gachaPull(pokemons);
        std::cout << "You pulled a " << pulled.rarity << "-star Pokemon: " << pulled.name << "!\n";
        std::cout << "Pull again? (y/n): ";
        std::cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    std::cout << "Thanks for playing the Kanto Gacha Simulator!\n";
    return 0;
}
