# Conway's Game of Life - Homework 3 (CS243)
This project is an implementation of Conway's Game of Life, a cellular automaton devised by mathematician John Conway. The project simulates a 20x20 grid of cells that evolve based on a set of simple rules over a fixed number of generations.

## Features
- Dynamic Grid Simulation: A grid of size 20x20 simulates the evolution of organisms.
- Random Initialization: Users specify the number of initial organisms, and they are placed randomly on the grid.
## Conway's Rules: The game follows the classic rules:
- A live cell with fewer than two neighbors dies (underpopulation).
- A live cell with two or three neighbors survives.
- A live cell with more than three neighbors dies (overpopulation).
- A dead cell with exactly three neighbors becomes alive (reproduction).
## Generation Tracking: 
The simulation runs for 100 generations, printing the state of the grid for each.
## How It Works
- The user is prompted to enter the initial number of organisms.
- The program initializes the grid, ensuring no duplicate placement of organisms.
- Each generation is computed using Conway's rules, and the state of the grid is printed to the console.
- The simulation halts after 100 generations.
## Files
main.c: Contains the core implementation, including functions for initializing the grid, applying Conway's rules, and simulating generations.
## How to Build and Run
Clone the repository:
```
git clone https://github.com/jvs1328/ConwayGameOfLife-C.git
Navigate to the project directory:

cd ConwayGameOfLife-HW3-CS243

Compile the program:
gcc main.c -o game_of_life

Run the program:
./game_of_life
```
## Known Issues
- Boundary Wrapping: The grid currently wraps around at edges, which may differ from other implementations.
- Code Style: The implementation includes areas for improvement in consistency and formatting.
- Documentation: Comments and inline documentation need enhancement.
## Future Improvements
- Refactor the code for better modularity and readability.
- Enhance input validation and allow dynamic grid resizing.
- Add visualization using a GUI or external libraries for better clarity.
