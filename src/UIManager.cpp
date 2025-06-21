/**
 * @file UIManager.cpp
 * @brief Implementation of the UIManager class
 */

#include "UIManager.h"
#include <string>
#include <cstdio>

UIManager::UIManager() {
    // No initialization needed for now
}

void UIManager::draw(GameState state, float timer) {
    switch (state) {
    case GameState::MENU:
        drawMenu();
        break;
    case GameState::PLAYING:
        drawGameUI(timer);
        break;
    case GameState::GAME_OVER:
        drawGameOver(timer);
        break;
    }
}

void UIManager::drawGameUI(float timer) {
    // Draw timer
    char timerText[20];
    sprintf(timerText, "Time: %.1f", timer);
    DrawText(timerText, 10, 10, 20, DARKGRAY);

    // Draw help text
    DrawText("Click on a cell and press 1-9 to enter a number", 10, SCREEN_HEIGHT - 30, 20, DARKGRAY);
    DrawText("Press 0 to clear a cell", 10, SCREEN_HEIGHT - 60, 20, DARKGRAY);
}

void UIManager::drawMenu() {
    // Draw menu
    DrawText("SUDOKU", SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 3, 50, DARKBLUE);
    DrawText("Press ENTER to start a new game", SCREEN_WIDTH / 2 - 200, SCREEN_HEIGHT / 2, 25, DARKGRAY);
}

void UIManager::drawGameOver(float timer) {
    // Draw game over screen
    DrawText("PUZZLE SOLVED!", SCREEN_WIDTH / 2 - 150, SCREEN_HEIGHT / 3, 40, GREEN);
    char timerText[50];
    sprintf(timerText, "Completion Time: %.1f seconds", timer);
    DrawText(timerText, SCREEN_WIDTH / 2 - 180, SCREEN_HEIGHT / 2, 25, DARKGRAY);
    DrawText("Press ENTER to return to menu", SCREEN_WIDTH / 2 - 200, SCREEN_HEIGHT / 2 + 50, 25, DARKGRAY);
}
