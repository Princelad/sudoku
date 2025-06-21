/**
 * @file main.cpp
 * @brief Entry point for the Sudoku game
 *
 * This file contains the main function which initializes and runs the game.
 */

#include "Game.h"
#include <iostream>

 /**
  * Main entry point for the Sudoku game
  */
int main(int argc, char** argv) {
    try {
        // Create game instance
        Game game;

        // Run the game
        game.run();

        return 0;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    catch (...) {
        std::cerr << "Unknown error occurred" << std::endl;
        return 1;
    }
}
