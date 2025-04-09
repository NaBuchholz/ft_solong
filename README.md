<p align="left"><h1 align="left">So Long - A 2D Game</h1></p>
<p align="left">
	<img src="https://img.shields.io/github/license/NaBuchholz/so_long?style=default&logo=opensourceinitiative&logoColor=white&color=0b96a2" alt="license">
	<img src="https://img.shields.io/github/last-commit/NaBuchholz/so_long?style=default&logo=git&logoColor=white&color=0b96a2" alt="last-commit">
	<img src="https://img.shields.io/github/languages/top/NaBuchholz/so_long?style=default&color=0b96a2" alt="repo-top-language">
	<img src="https://img.shields.io/github/languages/count/NaBuchholz/so_long?style=default&color=0b96a2" alt="repo-language-count">
	<img src="https://github.com/NaBuchholz/so_long/workflows/norminette/badge.svg" alt="repo-norminette">
</p>
<p align="left"><!-- default option, no dependency badges. -->
</p>
<p align="left">
	<!-- default option, no dependency badges. -->
</p>
<br>

## 🔗 Table of Contents

- [📍 Overview](#-overview)
- [📁 Project Structure](#-project-structure)
- [🚀 Getting Started](#-getting-started)
  - [☑️ Prerequisites](#-prerequisites)
  - [⚙️ Installation](#-installation)
  - [🤖 Usage](#🤖-usage)
  - [🧪 Testing](#🧪-testing)
- [🎗 License](#-license)
- [🙌 Acknowledgments](#-acknowledgments)

## 📍 Overview

So Long is a simple 2D game created using the MiniLibX library, where a player (originally a dolphin) must collect items and escape through an exit. The game includes basic features such as:

- Map rendering from a .ber file
- Keyboard controls for player movement
- Collectible items that must be gathered
- Exit that becomes accessible once all collectibles are gathered
- Movement counter displayed in the terminal
- Wall collision detection

This project demonstrates skills in window management, event handling, textures, and sprites while providing an engaging gaming experience.

## 📁 Project Structure

```sh
so_long/
├── assets/             # Game sprites and textures
│   ├── bg.xpm
│   ├── collectible.xpm
│   ├── exit.xpm
│   ├── player_left.xpm
│   ├── player_right.xpm
│   ├── player_still.xpm
│   ├── player_up.xpm
│   └── wall.xpm
├── includes/           # Header files
│   └── so_long.h       # Main header file
├── libft/              # Custom C library (submodule)
├── maps/               # Game map files in .ber format
│   ├── control.ber
│   ├── game_1.ber
│   ├── game_2.ber
│   └── one_collectable.ber
│   └── ...
├── minilibx/           # MiniLibX graphics library (submodule)
├── src/                # Source code
│   ├── error_handling.c
│   ├── free_map.c
│   ├── game_utils.c
│   ├── get_copy.c
│   ├── get_map.c
│   ├── get_next_line/  # File reading utilities
│   ├── player.c
│   ├── so_long.c       # Main program file
│   ├── update_map.c
│   ├── utils_validation_map.c
│   └── validate_map.c
├── .github/            # GitHub actions for norminette
├── .gitignore
├── .gitmodules         # Submodule configuration
├── LICENSE             # MIT License
├── Makefile            # Build configuration
└── README.md           # This file
```

## 🚀 Getting Started

### ☑️ Prerequisites

Before getting started with So Long, ensure your runtime environment meets the following requirements:

- **Operating System:** Linux (Preferably Ubuntu/Debian-based) or macOS
- **Programming Language:** C
- **Compiler:** GCC or Clang with C99 support
- **Libraries:** X11 and XShm development libraries
- **Other Tools:** Make

For Debian/Ubuntu systems, you can install the necessary dependencies with:
```sh
sudo apt-get update && sudo apt-get install gcc make xorg libxext-dev libbsd-dev
```

### ⚙️ Installation

Install So Long using the following method:

**Build from source:**

1. Clone the So Long repository:
```sh
❯ git clone https://github.com/NaBuchholz/so_long.git
```

2. Navigate to the project directory:
```sh
❯ cd so_long
```

3. Initialize and update the submodules:
```sh
❯ git submodule init
❯ git submodule update
```

4. Compile the project:
```sh
❯ make
```

### 🤖 Usage

Run So Long with a map file:
```sh
❯ ./solong maps/game_1.ber
```

**Controls:**
- Move Up: W or Up Arrow
- Move Down: S or Down Arrow
- Move Left: A or Left Arrow
- Move Right: D or Right Arrow
- Exit Game: ESC key or click the window close button

The player's goal is to collect all collectibles and then reach the exit. The movement count is displayed in the terminal.

### 🧪 Testing

The project includes several test maps in the `maps/` directory that can be used to verify different game behaviors and edge cases:

```sh
❯ ./solong maps/control.ber      # Basic test map
❯ ./solong maps/game_1.ber       # Larger game map
❯ ./solong maps/game_2.ber       # Small maze-like map
```

For debugging memory issues, you can use the debug target:
```sh
❯ make debug
```

## 🎗 License

This project is protected under the [MIT License](https://choosealicense.com/licenses/mit/). For more details, refer to the [LICENSE](LICENSE) file.

---

## 🙌 Acknowledgments

- The MiniLibX team for providing the graphics library
- 42 School for the project specifications and educational framework
- The open-source community for sprite resources and technical guidance
- Douglas Adams for the "So Long and Thanks for All the Fish" reference

---
