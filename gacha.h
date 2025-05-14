// Samuel Oseguera
// 5/13/2025
// Final Project

// gacha.h
#ifndef GACHA_H
#define GACHA_H

#include <vector>
#include <string>

// Struct the represents the Pokemon rarities (3-Star, 4-Star, 5-star)
struct Pokemon {
    std::string name;
    int rarity;
};

// Function declaration for simulating a gacha pull
Pokemon gachaPull(const std::vector<Pokemon>& pokemons);

#endif