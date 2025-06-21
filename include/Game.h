/**
 * @file Game.h
 * @brief Main game management class
 *
 * Handles the initialization, main game loop, and cleanup for the Sudoku game.
 */

#pragma once

#include "GameTypes.h"
#include "SudokuBoard.h"
#include "raylib.h"

 /**
  * @class Game
  * @brief Main game class that orchestrates the game loop and components
  */
class Game {
public:
    /**
     * @brief Constructor
     * Initializes the game window and components
     */
    Game();

    /**
     * @brief Destructor
     * Cleans up resources
     */
    ~Game();

    /**
     * @brief Run the main game loop
     * Handles the game loop including input, update, and render
     */
    void run();

private:
    /**
     * @brief Process user input
     * @param deltaTime Time elapsed since last frame
     */
    void processInput(float deltaTime);

    /**
     * @brief Update game state
     * @param deltaTime Time elapsed since last frame
     */
    void update(float deltaTime);

    /**
     * @brief Render the game
     */
    void render();

    // Game state and components
    SudokuBoard board;  // The Sudoku board
    bool isRunning;     // Flag to control the game loop
};
