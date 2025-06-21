/**
 * @file UIManager.h
 * @brief UI rendering and management
 *
 * Handles rendering of UI elements and screens like menu, game over screen, etc.
 */

#pragma once

#include "GameTypes.h"
#include "raylib.h"

 /**
  * @class UIManager
  * @brief Manages and renders the user interface elements
  */
class UIManager {
public:
    /**
     * @brief Constructor
     */
    UIManager();

    /**
     * @brief Draw the UI based on current game state
     * @param state Current game state
     * @param timer Current game timer (for display)
     */
    void draw(GameState state, float timer);

    /**
     * @brief Draw the in-game UI during gameplay
     * @param timer Current game timer
     */
    void drawGameUI(float timer);

    /**
     * @brief Draw the main menu
     */
    void drawMenu();

    /**
     * @brief Draw the game over screen
     * @param timer Final game timer
     */
    void drawGameOver(float timer);
};
