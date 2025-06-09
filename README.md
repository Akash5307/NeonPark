# Advanced Multithreaded Parking Lot Management System (C++ with PostgreSQL & Docker)

## Overview

This project is a comprehensive, production-ready Parking Lot Management System designed in modern C++17. It features a modular, object-oriented architecture with multithreading support, real-time PostgreSQL integration via Neon DB, and full Dockerization for easy deployment.

---

## Key Features

- **Modular Design:**  
  Encapsulates core components like `Vehicle`, `Ticket`, `ParkingLot`, `PaymentSystem`, and `Logger` following SOLID principles for maintainability and extensibility.

- **Multithreading & Concurrency:**  
  Uses `std::mutex` to synchronize access to shared resources, enabling safe simultaneous vehicle parking requests. Handles edge cases such as simultaneous arrivals when parking space is limited.

- **Database Persistence:**  
  Implements persistent ticket and transaction storage using PostgreSQL through the `libpqxx` C++ library, leveraging Neon DB for cloud-hosted, secure access.

- **Docker & Docker Compose:**  
  Fully containerized for platform-independent deployment. Includes a `Dockerfile` and `docker-compose.yml` with environment variable configuration for easy setup.

- **Logging & Monitoring:**  
  Real-time logging tracks system events, facilitating debugging and auditing.

- **Unit Testing:**  
  Integrated GoogleTest framework with automated CMake builds ensures reliability and supports test-driven development.

---

## Tech Stack

- **Language:** C++17  
- **Database:** PostgreSQL (Neon DB)  
- **Database Library:** libpqxx  
- **Build System:** CMake  
- **Testing Framework:** GoogleTest  
- **Containerization:** Docker, Docker Compose  
- **Concurrency:** std::thread, std::mutex  

---

## Getting Started

### Prerequisites

- Docker & Docker Compose installed
- Internet connection for Neon DB access

### Build & Run

```bash
git clone <repo-url>
cd <repo-folder>
docker-compose --build
docker-compose up
```
### Run locally
```bash
sudo apt-get install libpqxx-dev libpq-dev

g++ -std=c++17 main.cpp PostgresDB.cpp ParkingLot.cpp -lpqxx -lpq -pthread -o parking_lot
./parking_lot

```

#### Run Tests

```bash
g++ -std=c++17 ./tests/main_test.cpp -o unit_tests -lpqxx -lpq -lgtest -lgtest_main -pthread
./unit_tests
```