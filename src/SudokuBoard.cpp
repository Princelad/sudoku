/**
 * @file SudokuBoard.cpp
 * @brief Implementation of the SudokuBoard class
 */

#include "SudokuBoard.h"
#include "GameTypes.h"
#include "UIManager.h"
#include <algorithm>
#include <random>
#include <string>

SudokuBoard::SudokuBoard()
    : state(GameState::MENU), difficulty(Difficulty::MEDIUM),
    selectedRow(-1), selectedCol(-1), timer(0.0f) {
    initializeBoard();
}

void SudokuBoard::newGame(Difficulty newDifficulty) {
    // Set the difficulty
    difficulty = newDifficulty;

    // Reset the game state
    initializeBoard();

    // TODO: Generate a valid Sudoku puzzle based on difficulty
    // For now, use the test board
    setupTestBoard();

    state = GameState::PLAYING;
    timer = 0.0f;
}

void SudokuBoard::update(float deltaTime) {
    if (state == GameState::PLAYING) {
        // Update timer
        timer += deltaTime;

        // Handle input
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            Vector2 mousePos = GetMousePosition();
            int row = (mousePos.y - BOARD_OFFSET_Y) / CELL_SIZE;
            int col = (mousePos.x - BOARD_OFFSET_X) / CELL_SIZE;

            if (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE) {
                // Don't allow modifying cells that were given initially
                if (!mask[row][col]) {
                    selectedRow = row;
                    selectedCol = col;
                }
                else {
                    selectedRow = -1;
                    selectedCol = -1;
                }
            }
            else {
                selectedRow = -1;
                selectedCol = -1;
            }
        }

        // Handle number input
        if (selectedRow >= 0 && selectedCol >= 0) {
            for (int i = 0; i <= 9; i++) {
                if (IsKeyPressed(KEY_ZERO + i) || IsKeyPressed(KEY_KP_0 + i)) {
                    board[selectedRow][selectedCol] = i;

                    // Check if the puzzle is solved
                    checkGameCompletion();
                }
            }
        }
    }
}

void SudokuBoard::draw() {
    // Create UI manager for drawing UI elements
    static UIManager ui;

    if (state == GameState::PLAYING) {
        // Draw the grid
        for (int i = 0; i <= BOARD_SIZE; i++) {
            // Horizontal lines
            DrawLine(
                BOARD_OFFSET_X,
                BOARD_OFFSET_Y + i * CELL_SIZE,
                BOARD_OFFSET_X + BOARD_SIZE * CELL_SIZE,
                BOARD_OFFSET_Y + i * CELL_SIZE,
                i % 3 == 0 ? BLACK : GRAY
            );

            // Vertical lines
            DrawLine(
                BOARD_OFFSET_X + i * CELL_SIZE,
                BOARD_OFFSET_Y,
                BOARD_OFFSET_X + i * CELL_SIZE,
                BOARD_OFFSET_Y + BOARD_SIZE * CELL_SIZE,
                i % 3 == 0 ? BLACK : GRAY
            );
        }

        // Draw the numbers
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] != 0) {
                    // Draw filled number
                    DrawText(
                        std::to_string(board[i][j]).c_str(),
                        BOARD_OFFSET_X + j * CELL_SIZE + CELL_SIZE / 3,
                        BOARD_OFFSET_Y + i * CELL_SIZE + CELL_SIZE / 4,
                        CELL_SIZE / 2,
                        mask[i][j] ? DARKBLUE : BLACK
                    );
                }
            }
        }

        // Highlight the selected cell
        if (selectedRow >= 0 && selectedCol >= 0) {
            DrawRectangle(
                BOARD_OFFSET_X + selectedCol * CELL_SIZE,
                BOARD_OFFSET_Y + selectedRow * CELL_SIZE,
                CELL_SIZE,
                CELL_SIZE,
                ColorAlpha(SKYBLUE, 0.5f)
            );
        }
    }

    // Draw UI elements based on game state
    ui.draw(state, timer);
}

GameState SudokuBoard::getState() const {
    return state;
}

void SudokuBoard::setState(GameState newState) {
    state = newState;
}

void SudokuBoard::initializeBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;
            solution[i][j] = 0;
            mask[i][j] = false;
        }
    }
}

void SudokuBoard::setupTestBoard() {
    // A sample solution (would be generated in a full implementation)
    int sampleSolution[BOARD_SIZE][BOARD_SIZE] = {
        {5, 3, 4, 6, 7, 8, 9, 1, 2},
        {6, 7, 2, 1, 9, 5, 3, 4, 8},
        {1, 9, 8, 3, 4, 2, 5, 6, 7},
        {8, 5, 9, 7, 6, 1, 4, 2, 3},
        {4, 2, 6, 8, 5, 3, 7, 9, 1},
        {7, 1, 3, 9, 2, 4, 8, 5, 6},
        {9, 6, 1, 5, 3, 7, 2, 8, 4},
        {2, 8, 7, 4, 1, 9, 6, 3, 5},
        {3, 4, 5, 2, 8, 6, 1, 7, 9}
    };

    // Copy the solution
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            solution[i][j] = sampleSolution[i][j];
        }
    }

    // Create a mask based on difficulty (more hidden cells for higher difficulty)
    int visibleCells;
    switch (difficulty) {
    case Difficulty::EASY:
        visibleCells = 45; // Show about half the cells
        break;
    case Difficulty::MEDIUM:
        visibleCells = 35; // Show fewer cells
        break;
    case Difficulty::HARD:
        visibleCells = 25; // Show even fewer cells
        break;
    default:
        visibleCells = 35;
        break;
    }

    // Randomly select cells to be visible
    std::vector<std::pair<int, int>> positions;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            positions.push_back({ i, j });
        }
    }

    // Shuffle the positions
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(positions.begin(), positions.end(), g);

    // Select the first 'visibleCells' positions to be visible
    for (int i = 0; i < visibleCells && i < positions.size(); i++) {
        int row = positions[i].first;
        int col = positions[i].second;
        mask[row][col] = true;
        board[row][col] = solution[row][col];
    }
}

void SudokuBoard::checkGameCompletion() {
    bool completed = true;

    // Check if all cells match the solution
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] != solution[i][j]) {
                completed = false;
                break;
            }
        }
        if (!completed) break;
    }

    if (completed) {
        state = GameState::GAME_OVER;
    }
}

void SudokuBoard::generatePuzzle() {
    // TODO: Implement a proper Sudoku generator algorithm
    // This would replace the setupTestBoard method
    // For now, we use the test board implementation
}
