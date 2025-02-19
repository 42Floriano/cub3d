# 🏰 Cub3D - 42 Project

Cub3D is a 42 project inspired by the classic Wolfenstein 3D. It is a simple 3D game engine utilizing **raycasting** to render a first-person perspective inside a maze. The project is built using **MiniLibX** and written in C.

---

## 📌 Project Overview

- **Language**: C
- **Graphics Library**: MiniLibX
- **Compilation**: `gcc -Wall -Wextra -Werror`
- **Status**: Mandatory part completed (Bonus not implemented)

---

## 📁 Repository Structure

```
├── includes/          # Header files
├── map/               # Example map files (.cub format)
├── minilibx-linux/    # MiniLibX library (Linux)
├── srcs/              # Source code files
├── textures/          # Wall textures
├── Makefile           # Compilation rules
└── README.md          # Project documentation
```

---

## 🚀 Getting Started

### 🔧 Dependencies

Before running the project, ensure you have the required dependencies installed:

#### For Linux:
```sh
sudo apt-get install libxext-dev libxrandr-dev libx11-dev libbsd-dev
```

#### For MacOS:
```sh
brew install minilibx
```

---

## 🏗️ Installation

Clone the repository and compile the project using Make:

```sh
git clone https://github.com/42Floriano/cub3d.git
cd cub3d
make
```

This will generate the `cub3D` executable.

---

## 🎮 How to Play

Run the game with a `.cub` map file:

```sh
./cub3D maps/example.cub
```

### 🕹️ Controls
- `W/A/S/D` → Move player
- `←` `→` → Rotate view
- `ESC` → Exit game

---

## 📜 Map Format
A valid `.cub` file consists of:
- **Textures:** `NO`, `SO`, `WE`, `EA` (Paths to texture files)
- **Colors:** `F` (Floor color), `C` (Ceiling color)
- **Map Layout:**
  - `1` → Wall
  - `0` → Walkable area
  - `N/S/E/W` → Player spawn position & orientation

Example:
```
NO ./textures/wall_north.xpm
SO ./textures/wall_south.xpm
WE ./textures/wall_west.xpm
EA ./textures/wall_east.xpm
F 220,100,0
C 225,30,0

111111
100001
1010N1
100001
111111
```

---

## 🛠️ Features Implemented
✅ Raycasting rendering engine  
✅ Player movement and rotation  
✅ Wall textures based on direction  
✅ Floor and ceiling coloring  
✅ Basic error handling  
❌ **Bonus features not implemented** (Minimap, Doors, Mouse control, etc.)  

---

## 🛑 Known Issues
- Some edge cases in map parsing may cause unexpected behavior.
- No sound or advanced graphical features.

---

## 📌 Credits
- **42Floriano** ([@42Floriano](https://github.com/42Floriano))
- **Aavduli** ([@aavduli](https://github.com/aavduli))

---

## 🏆 Acknowledgments
This project is inspired by **Wolfenstein 3D** and aims to provide a foundational understanding of **raycasting** and **game development** using **MiniLibX**.

---

🔗 [GitHub Repository](https://github.com/42Floriano/cub3d)

