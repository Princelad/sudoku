/**
 * @file GameTypes.h
 * @brief Common game types, enums, and constants
 *
 * Defines common types, enumerations, and constants used throughout the game.
 */

#pragma once

#include <array>

 // Screen dimensions
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

// Board dimensions
const int BOARD_SIZE = 9;
const int CELL_SIZE = 50;

// Board layout
const int BOARD_OFFSET_X = (SCREEN_WIDTH - (BOARD_SIZE * CELL_SIZE)) / 2;
const int BOARD_OFFSET_Y = (SCREEN_HEIGHT - (BOARD_SIZE * CELL_SIZE)) / 2;

/**
 * @enum GameState
 * @brief Represents the current state of the game
 */
enum class GameState {
    MENU,       // Main menu
    PLAYING,    // Actively playing the game
    GAME_OVER   // Game completed
};

/**
 * @enum Difficulty
 * @brief Represents the difficulty level of the game
 */
enum class Difficulty {
    EASY,       // Easy difficulty (more visible cells)
    MEDIUM,     // Medium difficulty
    HARD        // Hard difficulty (fewer visible cells)
};
