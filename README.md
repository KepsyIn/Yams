# Yams Game (Yahtzee)

A C++ console-based implementation of the classic Yams (Yahtzee) dice game. This project is using the Model-View-Controller (MVC) design pattern to separate game logic from the user interface.

## Architecture
The project is divided into three main layers:

- **Model** : Handles game rules, scoring logic, and state management (Players, Dice, Figures).

- **View** : Handles all console output (std::cout) and user input collection (std::cin).

- **Controller** : Orchestrates the flow of the game, connecting the Model and the View.

## Project Structure

```Plaintext
.
├── include/
│   ├── core/           # Base entities (figure, player, dice launcher)
│   ├── model/          # Game state and logic
│   ├── view/           # Console UI and input handling
│   └── controller/     # Game flow orchestration
├── src/                # Implementation files (.cpp)
├── bin/                # Compiled executable
├── Makefile            # Build system
└── README.md
```

## Getting Started

Prerequisites
A C++ compiler supporting C++17 (e.g., g++).

Make build tool.

Installation & Build
Open your terminal in the project root directory.

### Compile the project using the Makefile:

```Bash
make
```
### Run the game:

```Bash
./bin/yams
```
Cleaning Build Files
To remove object files and the binary:

```Bash
make clean
```

## 🎮 How to Play

1. Roll: At the start of your turn, the dice are rolled automatically.

2. Relance (Reroll): You have up to 2 rerolls per turn. Enter the indexes of the dice you wish to change (e.g., 0 2 4).

3. Choose Figure: Select a figure from the available list to score points.

4. Score: The game tracks scores for both "Minor" and "Major" phases.

5. Win: The player with the highest total score at the end of all rounds wins!