# FdF (Fil de Fer - Wireframe)

![Language](https://img.shields.io/badge/Language-C-blue.svg)
![Graphics](https://img.shields.io/badge/Graphics-MiniLibX-red)
![School](https://img.shields.io/badge/School-42%20Network-black.svg)

## 📖 About FdF

**FdF (Fil de Fer)** is a core graphics project at 42 that focuses on **3D visualization** and **projection**. The goal is to read a simple text file containing elevation data (a Z-axis value for every X/Y coordinate) and transform that data into a 3D wireframe model.

The project is implemented in C and uses the **MiniLibX** graphics library (a custom layer around X11 or Cocoa) to manage the window, handle graphics rendering, and capture user input (mouse and keyboard events).

### Core Concepts Demonstrated
* **Reading and Parsing:** Reading simple map data from a file into a grid structure.
* **Geometric Transformations:** Applying rotation matrices and projection calculations (Isometric and Parallel).
* **Graphics Programming:** Drawing lines and managing pixels using the Bresenham's line algorithm.
* **Event Management:** Handling keypresses for dynamic interaction (rotation, zoom, translation).

---

## 📸 Visualization Example


The program reads a simple grid of coordinates and draws the wireframe model based on the elevation values (Z).

<img width="1804" height="1078" alt="image" src="https://github.com/user-attachments/assets/79f69ef4-85ba-44f1-aea5-4a0ad4b03c8c" />


---

## 📌 Controls and Features

The application supports real-time manipulation of the 3D model via keyboard controls:

| Action | Key | Description |
| :--- | :--- | :--- |
| **Reset View** | `R` | Resets all rotations, zooms, and translations to the starting default. |
| **Move** |`W` / `A` / `S` / `D` / | Translates the model (moves the camera) up, down, left, or right. |
| **Zoom** | `+` / `-` | Zooms the model in or out. |
| **Flatten Z** | `Up Key` / `Down Key` | Increases or decreases the vertical scale (height multiplier). |
| **Rotate** | `1` / `2` / `3` / `4` / `5` / `6` | Rotates the model around the X, Y, and Z axes. |
| **Projection** | `TAB` | Toggles between **Isometric** and **Parallel** projections. |
| **Color** | `C` | Cycles through different color schemes. |
| **Exit** | `ESC` | Closes the window and exits the program. |

---

## 🛠️ Usage and Compilation

### Dependencies

This project requires the **MiniLibX** library to be installed on the system.

### Map File Format

The program accepts a map file (`.fdf`) where each number represents the Z-axis (height) value for that coordinate.

### Compilation

The project is compiled using the provided `Makefile`:

```bash

make
```
### Execution

Run the program by passing a valid map file as an argument:

```bash

./fdf maps/test_map.fdf
