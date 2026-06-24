# PakWheels-CLI: Advanced Vehicle Marketplace System (Version 2.0)

A robust, highly refined C++ command-line application designed to simulate a vehicle buying and selling ecosystem, inspired by platforms like PakWheels. Building upon the core fundamentals of Assignment 1, this **advanced version** introduces a production-ready architectural design, migrating from a single-file codebase to a clean, decoupled multi-file layout with distinct compilation modules.

This project serves as a comprehensive implementation of advanced **Object-Oriented Programming (OOP)** principles to seamlessly manage complex user-listing interactions and lifecycle management.

---

### 🚀 Key Features

* **User Account Management:** Separate modules for Buyers and Sellers with secure attribute handling, backed by an abstract profile layer.
* **Dynamic Ad Listings:** Support for various polymorphic vehicle types with detailed attribute configurations (Model, Year, Price, Mileage).
* **Search & Filter Engine:** High-performance capability to browse and screen available listings based on precise vehicle criteria.
* **Admin Dashboard & Auditing:** High-level executive oversight for managing user accounts, checking credentials, and moderating active marketplace advertisements.

---

### 💻 Technical Architecture

While the previous iteration focused purely on basic structural configurations, this refined version elevates the ecosystem using deep runtime mechanics and structural decoupling:

* **File Separation (`/include` & `/src`):** Modularized codebase splitting class interfaces (`.h` header guards) from their execution mechanics (`.cpp` files) for faster compilation tracking and enterprise organization.
* **Inheritance & Polymorphism:** Abstract base structures utilize virtual frameworks (such as pure virtual functions and dynamic class safety) to define generalized blueprints for user types and vehicles.
* **Composition:** Used to securely build entity models from crucial static subsystems (e.g., tying localized `Account` modules directly to active `User` sessions).
* **Association & Aggregation:** The global `Marketplace` core acts as a persistent container layer, managing structural associations between interacting `Sellers`, `Buyers`, and dynamic listing entities without strictly controlling individual lifecycle bounds.
* **Encapsulation & Safety:** Enforced access specifiers (`private`/`protected`), constant members, static trackers, and friend classes safeguard critical data components against unauthorized scope leaks.

---

### 🛠️ Built With

* **Language:** C++ (Advanced OOP Architecture)
* **Directory Layout:** Modular `/include` and `/src` file structures
* **Concepts:** Polymorphism, Abstract Base Classes, Composition, Friend Functions, Operator Overloading
* **Environment:** VS Code / Dev C++
* **Version Control:** Git & GitHub
