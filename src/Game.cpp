/**
 * @file Game.cpp
 * @brief Implementation of the Game class
 */

#include "Game.h"
#include "GameTypes.h"
#include "raylib.h"

Game::Game() : isRunning(true) {
    // Initialize the game window
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Sudoku Game");
    SetTargetFPS(60);

    // Initialize the board (it will start in MENU state)
    board = SudokuBoard();
}

Game::~Game() {
    // Clean up resources
    CloseWindow();
}

void Game::run() {
    // Main game loop
    while (!WindowShouldClose() && isRunning) {
        float deltaTime = GetFrameTime();

        // Process input, update game state, and render
        processInput(deltaTime);
        update(deltaTime);
        render();
    }
}

void Game::processInput(float deltaTime) {
    // Get current game state to handle input accordingly
    GameState state = board.getState();

    if (state == GameState::MENU) {
        // In menu, pressing ENTER starts a new game
        if (IsKeyPressed(KEY_ENTER)) {
            board.newGame();
        }
    }
    else if (state == GameState::GAME_OVER) {
        // In game over, pressing ENTER returns to menu
        if (IsKeyPressed(KEY_ENTER)) {
            board.setState(GameState::MENU);
        }
    }

    // Let the board handle its own input for gameplay
    board.update(deltaTime);
}

void Game::update(float deltaTime) {
    // No additional updates needed at this level
    // Board update is already called in processInput
}

void Game::render() {
    BeginDrawing();

    // Clear the background
    ClearBackground(RAYWHITE);

    // Draw the board
    board.draw();

    EndDrawing();
}
