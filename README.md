<p align="center">
  <img src="https://img.shields.io/badge/42-so__long-blue?style=for-the-badge" alt="42 so_long"/>
</p>

<h1 align="center">so_long</h1>

<p align="center">
  <em>And thanks for all the fish!</em>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Language-C-00599C?style=flat-square&logo=c&logoColor=white" alt="C"/>
  <img src="https://img.shields.io/badge/Graphics-MiniLibX-purple?style=flat-square" alt="MiniLibX"/>
  <img src="https://img.shields.io/badge/Build-Makefile-orange?style=flat-square" alt="Makefile"/>
  <img src="https://img.shields.io/badge/Theme-Pac--Man-yellow?style=flat-square" alt="Pac-Man"/>
</p>

---

## About

**so_long** is a 2D tile-based game written in C using the MiniLibX graphics library, developed as part of the [42 School](https://42.fr/) curriculum. The game is a Pac-Man inspired top-down maze where the player must collect all coins and reach the exit while avoiding enemies. The project covers window management, event handling, sprite animation, map parsing, and pathfinding validation.

> *A small 2D game that teaches you about textures, sprites, and basic gameplay elements.*

## Features

### Mandatory
- **Tile-based rendering** — 32x32 pixel tiles with distinct textures for walls, floor, player, coins, and exit
- **Smart wall textures** — 16 different wall tiles that automatically adapt based on neighboring walls (corners, edges, crosses, borders)
- **Player movement** — WASD and arrow key support in four directions
- **Collectibles** — gather all coins before the exit unlocks
- **Move counter** — tracks and prints each movement to the terminal
- **Map validation** — robust `.ber` file parser with flood-fill path verification
- **Win/lose conditions** — win by reaching the exit after collecting everything; lose by touching an enemy

### Bonus
- **Animated player sprite** — 13-frame directional animation (idle + 3 frames per direction)
- **Animated coin sprites** — 6-frame spinning coin animation
- **Enemy ghosts** — 4 colored ghost types (red, green, sky, purple) with 3-frame animations each
- **Enemy AI** — ghosts move randomly around the map, killing the player on contact
- **On-screen move counter** — HUD displayed directly in the game window
- **Game loop rendering** — continuous frame updates via `mlx_loop_hook` for smooth animations

---

## Getting Started

### Prerequisites

- **GCC** or **CC** compiler
- **GNU Make**
- **MiniLibX** with X11 libraries
- **Linux** (X11-based rendering)

#### Install dependencies:

```bash
# Ubuntu / Debian
sudo apt-get install libx11-dev libxext-dev

# Fedora
sudo dnf install libX11-devel libXext-devel
```

### Build

```bash
# Clone the repository
git clone <repository-url>
cd so_long

# Compile mandatory version
make

# Compile bonus version (animations, enemies, HUD)
make bonus

# Run with a map
./so_long maps/1_lvl.ber

# Run bonus version
./so_long_bonus maps/map_bonus.ber
```

### Makefile Targets

| Target | Description |
|--------|-------------|
| `make` / `make all` | Build the mandatory version |
| `make bonus` | Build the bonus version (animations + enemies) |
| `make clean` | Remove object files |
| `make fclean` | Remove object files and binaries |
| `make re` | Full recompile (mandatory) |
| `make reb` | Full recompile (bonus) |

---

## Usage

### Controls

| Key | Action |
|-----|--------|
| `W` / Up arrow | Move up |
| `S` / Down arrow | Move down |
| `A` / Left arrow | Move left |
| `D` / Right arrow | Move right |
| `ESC` | Exit the game |

### Objective

1. Collect all coins (`C`) on the map
2. Reach the exit (`E`)
3. Avoid ghosts (`G`) — touching one means game over (bonus)

Each move is counted and printed to the terminal (and displayed on-screen in bonus).

### Map File Format (`.ber`)

```
1111111111111
1E001C00111C1
111011101G101
1C001C0011101
1110101110101
1C000000000P1
1111111111111
```

| Character | Description |
|-----------|-------------|
| `1` | Wall |
| `0` | Floor (empty space) |
| `P` | Player spawn (exactly 1) |
| `C` | Collectible / coin (at least 1) |
| `E` | Exit (exactly 1) |
| `G` | Ghost / enemy (bonus only) |

### Map Rules

- Must be rectangular
- Must be fully enclosed by walls (`1`)
- Exactly one player (`P`) and one exit (`E`)
- At least one collectible (`C`)
- A valid path must exist from the player to all coins and the exit
- File must have `.ber` extension

See `maps/` for example maps (both valid and invalid test cases).

---

## Key Concepts Learned

- **MiniLibX** — low-level graphics library for window management and image rendering
- **Tile-based game design** — grid maps, tile rendering, and sprite management
- **Sprite animation** — frame-based animation with directional sprites
- **Flood fill algorithm** — path validation to ensure map solvability
- **Event-driven programming** — keyboard hooks and window event handling
- **Smart tile selection** — neighbor-aware wall textures for seamless borders
- **Game loop architecture** — input handling, state update, and rendering cycle
- **File parsing** — reading and validating structured map files

---

## Limitations

- Linux only (X11 / MiniLibX dependency)
- Fixed tile size (32x32 pixels)
- Enemy movement is random (no pathfinding AI)
- No scoring system beyond move counter
- No multiple levels / level progression
- No sound effects

---

## License

This project was developed as part of the 42 School curriculum. Feel free to use it as a reference, but please respect the [42 School's academic integrity rules](https://www.42.fr/).

---

<p align="center">
  Made at <strong>42 Vienna</strong>
</p>
