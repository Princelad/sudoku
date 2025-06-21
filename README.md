# Sudoku Game

A C++ implementation of the classic Sudoku puzzle game using the raylib graphics library.

## Overview

This Sudoku game provides a complete implementation with:
- Multiple difficulty levels (Easy, Medium, Hard)
- Clean, modular OOP design
- Visual game board with interactive cells
- Game timer to track solving speed
- Menu and game completion screens

## Project Structure

The project is organized as follows:

```
sudoku/
├── include/            # Header files
│   ├── Game.h          # Main game class
│   ├── GameTypes.h     # Common game types and constants
│   ├── SudokuBoard.h   # Sudoku board logic
│   └── UIManager.h     # UI rendering
├── src/                # Source files
│   ├── Game.cpp        # Game implementation
│   ├── SudokuBoard.cpp # Board implementation
│   └── UIManager.cpp   # UI implementation
├── main.cpp            # Entry point
└── CMakeLists.txt      # Build configuration
```

## Dependencies

- [raylib](https://www.raylib.com/) - A simple and easy-to-use library to learn videogames programming

## Building

This project uses CMake for building:

```bash
mkdir -p build
cd build
cmake ..
make
```

## Gameplay Instructions

1. Press ENTER on the menu screen to start a new game
2. Click on an empty cell to select it
3. Press a number key (1-9) to place a number in the selected cell
4. Press 0 to clear a cell
5. Complete the puzzle by filling all cells with the correct numbers

## Future Enhancements

- Sudoku puzzle generator (currently uses a test board)
- Difficulty selection in the menu
- Saving/loading game state
- Hint system
- Cell notes/candidates
- Undo/redo functionality

## License

[MIT License](LICENSE)
