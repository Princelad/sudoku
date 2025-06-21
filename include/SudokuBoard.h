/**
 * @file SudokuBoard.h
 * @brief Declaration of the SudokuBoard class
 *
 * Defines the SudokuBoard class which handles the game board logic,
 * including generation, validation, and gameplay mechanics.
 */

#pragma once

#include "GameTypes.h"
#include "raylib.h"
#include <array>
#include <utility>
#include <vector>

 /**
  * @class SudokuBoard
  * @brief Represents the Sudoku game board and its logic
  */
class SudokuBoard {
public:
    /**
     * @brief Constructor
     * Initializes a new Sudoku board with default values
     */
    SudokuBoard();

    /**
     * @brief Start a new game with the specified difficulty
     * @param newDifficulty The difficulty level for the new game
     */
    void newGame(Difficulty newDifficulty = Difficulty::MEDIUM);

    /**
     * @brief Update the game board state
     * @param deltaTime Time elapsed since last frame
     */
    void update(float deltaTime);

    /**
     * @brief Draw the Sudoku board
     */
    void draw();

    /**
     * @brief Get the current game state
     * @return The current game state (MENU, PLAYING, GAME_OVER)
     */
    GameState getState() const;

    /**
     * @brief Set the game state
     * @param newState The new game state
     */
    void setState(GameState newState);

private:
    /**
     * @brief Initialize the board to empty state
     */
    void initializeBoard();

    /**
     * @brief Set up a test board for development
     */
    void setupTestBoard();

    /**
     * @brief Check if the game is completed
     */
    void checkGameCompletion();

    /**
     * @brief Generate a new Sudoku puzzle
     */
    void generatePuzzle();

    // Game board data
    std::array<std::array<int, BOARD_SIZE>, BOARD_SIZE> board;      // Current game board
    std::array<std::array<int, BOARD_SIZE>, BOARD_SIZE> solution;   // Solution to the puzzle
    std::array<std::array<bool, BOARD_SIZE>, BOARD_SIZE> mask;      // Mask of initially visible cells

    // Game state
    GameState state;         // Current game state
    Difficulty difficulty;   // Current difficulty level
    int selectedRow;         // Currently selected row (-1 if none)
    int selectedCol;         // Currently selected column (-1 if none)
    float timer;             // Game timer (in seconds)
};
