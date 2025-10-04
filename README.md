**Console-Based Tetris Game**

**Overview**
This is a console-based Tetris game implemented in C++ for Windows. The game features classic Tetris gameplay, including various block shapes, rotation, movement, row deletion, scoring, and game save/load functionality. It uses the Windows console for rendering and user input handling.

**Features**
Block Types: Supports six Tetris block shapes (T, S-right, S-left, L, I, Box).
Movement: Move blocks left or right using arrow keys (left: ←, right: →).
Rotation: Rotate blocks using up or down arrow keys (↑ or ↓).
Scoring: Earn 100 points for each completed row.
Game Save/Load: Save the game state to a file (save.txt) and load it later.
Game Over: The game ends when blocks reach near the top of the board.
Console Rendering: Uses Windows-specific console functions for drawing the game board and blocks.

**Prerequisites**
Operating System: Windows (due to the use of windows.h and console functions).
Compiler: A C++ compiler supporting C++11 or later (e.g., MinGW, MSVC).
Libraries: Standard C++ libraries (iostream, fstream, ctime, etc.) and Windows-specific libraries (windows.h, conio.h).

**Installation**

Clone the Repository:
[git clone ](https://github.com/arfa-tayyabah/console_tetris_c-)
cd console-tetris
Compile the Code: Use a C++ compiler to build the project. For example, with g++:
g++ -o tetris main.cpp

Run the Game:
./tetris

**How to Play**
Start the Game:
Run the compiled executable.
At the prompt, press N for a new game or L to load a saved game.

**Controls:**
Left Arrow (←): Move block left.
Right Arrow (→): Move block right.
Up Arrow (↑) or Down Arrow (↓): Rotate block.


****Project Structure

console-tetris_c/
├── main.cpp          # Main game source code
├── save.txt         # File for saving/loading game state
├── README.md        # Project documentation
├── LICENSE          # License file
├── .gitignore       # Git ignore file
└── CONTRIBUTING.md   # Contribution guidelines

**Contributing**
Contributions are welcome! Please read the CONTRIBUTING.md file for guidelines on how to contribute to this project.

**License**
This project is licensed under the MIT License. See the LICENSE file for details.

Author https://github.com/arfa-tayyabah

