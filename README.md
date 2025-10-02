# Hyderabad Metro Management System

This is a C++ project that simulates a basic management system for the Hyderabad Metro network. It is designed to demonstrate the application of Object-Oriented Programming (OOPS) principles to a real-world problem. The system calculates the shortest distance between any two stations and estimates the corresponding ticket fare.

## Features

  - **Shortest Distance Calculation**: Utilizes the Floyd-Warshall algorithm to pre-compute the shortest path between all pairs of stations in the network.
  - **Ticket Fare Estimation**: Calculates a dynamic ticket price based on the shortest travel distance, with a minimum base fare.
  - **Station Management**: Allows for adding stations and connections to build the metro map.
  - **User-Friendly CLI**: A simple command-line interface to input source and destination stations.
  - **Input Validation**: Ensures that the user enters valid station names.
  - **Clear Separation of Roles**: Differentiates between a `Manager` (who builds the map) and a `user` (who queries the map).

## Core Concepts Demonstrated (The 4 Pillars of OOPS)

This project is built upon the four main pillars of Object-Oriented Programming:

1.  **Abstraction**: The `MetroMap` base class provides an abstract interface for a metro system. It defines what a metro map should do (e.g., `add_node`, `add_edge`) without specifying *how* it should be done. This hides the complex implementation details from the user.

2.  **Encapsulation**: The data members (`node` map, `distance` matrix, etc.) are declared as `protected` within the `MetroMap` class. This bundles the data with the methods that operate on it and restricts direct access from outside the class hierarchy, ensuring data integrity.

3.  **Inheritance**: The `Manager` and `user` classes inherit from the `MetroMap` base class. They extend its functionality and provide specific implementations for the virtual functions. This promotes code reusability.

4.  **Polymorphism**: Achieved through virtual functions in the `MetroMap` class. The `add_node`, `add_edge`, and `flloyd_warshall` functions are overridden in the `Manager` class to provide a specific implementation, demonstrating runtime polymorphism.

## Algorithm Used: Floyd-Warshall

The core of the shortest distance calculation is the **Floyd-Warshall algorithm**.

  - It is an **all-pairs shortest path** algorithm, meaning it finds the shortest distances between every pair of vertices (stations) in the graph.
  - In this project, the `flloyd_warshall()` method is called once after the graph is constructed. This pre-computes all shortest paths.
  - The advantage is that any subsequent query for the shortest distance between two stations is extremely fast (effectively an O(1) lookup in the distance matrix), making the system responsive for the end-user.

## Code Structure

  - `metro_mgmt.cpp`: This header file defines the core class structures:
      - `MetroMap` (Abstract Base Class): Defines the blueprint for the metro system.
      - `Manager` (Derived Class): Responsible for building the station graph, adding edges, and running the Floyd-Warshall algorithm.
      - `user` (Derived Class): Responsible for querying the pre-computed data to find distances and calculate fares.
  - `main.cpp`: This is the driver file. It:
      - Creates a `Manager` object to build the Hyderabad metro map with hardcoded station data.
      - Creates a `user` object to interact with the map.
      - Handles all user input and output.

## How to Compile and Run

You will need a C++ compiler (like g++).

1.  **Save the Files**: Make sure `main.cpp` and `metro_mgmt.cpp` are in the same directory.

2.  **Compile**: Open a terminal or command prompt in that directory and run the following command:

    ```sh
    g++ main.cpp -o metro_system
    ```

3.  **Execute**: Run the compiled program:

    ```sh
    ./metro_system
    ```

## Example Usage

Upon running, the program will first list all the stations and then prompt you for input.

```
List of all stations in the metro network:

1. Nagole
2. NGRI
3. Mettuguda
... (and so on) ...
23. JNTU college

Total number of stations in the metro network:
23
Enter source station:
JNTU college
Enter destination station:
LB Nagar
Shortest distance between JNTU college and LB Nagar is: 18 km
Price of ticket is: 180 Rs
```
