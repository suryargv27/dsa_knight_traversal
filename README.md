# Knight's Shortest Path Solver

## Overview
This project implements a solution to the Knight's shortest path problem on an `n x n` chessboard using **Breadth-First Search (BFS)**. The program determines the minimum number of moves required for a knight to travel from a given start position to a specified end position. It also visually simulates the movement of the knight on the board.

## Features
- Accepts user input for board size, start position, and destination position.
- Implements a queue-based BFS algorithm to find the shortest path.
- Visually displays the knight's movement on the board in real-time.
- Outputs the shortest path and the number of moves taken.

## Technologies Used
- **C Programming Language**
- **Breadth-First Search (BFS)** for pathfinding
- **Dynamic Memory Allocation** for queue management
- **System Calls (`system("cls")`)** for board visualization (Windows only)
- **Clock-based delay** for simulation pacing

## How It Works
1. The board size (`n`) is taken as input.
2. The user specifies the starting and ending coordinates of the knight.
3. The BFS algorithm is used to explore all possible moves and find the shortest path.
4. The knight's movement is displayed on the console, with a delay for visualization.
5. The program prints the shortest path and the number of moves required.

## Code Structure
### Data Structures
1. **Node Structure (`struct Node`)**
   - Stores the knight's `(x, y)` position, distance from the start, and a pointer to the previous node (to reconstruct the path).
   
2. **Queue Structure (`struct Queue`)**
   - Implements a queue using a doubly linked list to facilitate BFS traversal.

### Functions
- `node *new(int x, int y, int distance, node *prev)`: Creates a new node.
- `queue *create()`: Initializes an empty queue.
- `void enqueue(queue **q, int x, int y, int distance, node *prev)`: Adds a new position to the queue.
- `void dequeue(queue **q)`: Removes the front node from the queue.
- `int in_board(int x, int y, int n)`: Checks if a position is within the board.
- `node *knight_travel(int start[], int end[], int n)`: Implements BFS to find the shortest path.
- `void reverse_path(node **temp)`: Reverses the path for proper output.
- `void delay(int seconds)`: Creates a delay for visualization.

### Main Function (`main()`)
- Takes input for board size and knight's positions.
- Checks for invalid inputs.
- Calls `knight_travel()` to compute the shortest path.
- Reverses the path and prints the movement on the board.
- Displays the shortest path and distance.

## Usage
### Compilation
```sh
gcc knight_traversal.c -o knight_traversal
```

### Execution
```sh
./knight_traversal
```

### Example Input/Output
```
Enter the size of the board : 8
Enter the start_x position : 1
Enter the start_y position : 1
Enter the end_x position : 8
Enter the end_y position : 8

Shortest distance from (1,1) to (8,8) : 6
Shortest Path : (1,1) -> (2,3) -> (3,5) -> (4,7) -> (5,5) -> (6,7) -> (8,8)
```

## Limitations
- Uses `system("cls")`, which only works on Windows. Replace it with `system("clear")` for Linux/Mac compatibility.
- Uses `delay()`, which could be improved with `usleep()` for finer control.
- Does not handle memory cleanup (`free()`) properly; might lead to memory leaks in large board sizes.

## Future Improvements
- Implementing multi-threading for better performance.
- Adding GUI support for a visual representation.
- Optimizing BFS with bi-directional search to speed up computations.

## License
This project is licensed under the MIT License


