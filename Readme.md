# Car Rental Management System in C++

A simple console-based Car Rental Management System built using C++. This project helps manage car inventory, customer records, and rental transactions efficiently using object-oriented programming and file handling.

---

## Features

-  Add new cars to inventory
-  View all available cars
-  Register new customers
-  View all registered customers
-  Rent a car to a customer
-  Return a rented car
-  View all rental history
-  Data is saved and loaded from `.txt` files

---

## Technologies Used

- C++
- File I/O (`fstream`)
- Object-Oriented Programming
- Standard Template Library (`vector`, `string`)

---

## Project Structure

CarRentalSystem/
│
├── main.cpp # Main source code
├── cars.txt # Car records
├── customers.txt # Customer records
├── rentals.txt # Rental records
└── README.md # You're reading this!

---

## Getting Started

### Compile and Run

Make sure you have a C++ compiler installed (e.g., g++ or Code::Blocks on Windows).

To compile:
```bash
g++ main.cpp -o CarRental

To run:
./CarRental

---

## Data Persistence

Car, customer, and rental data are stored in text files:

cars.txt
customers.txt
rentals.txt

Data automatically loads at program startup and saves on exit.

---

