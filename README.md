# 💰 FundFlow - Finance Manager

> A lightweight, command-line financial management system built with C++. Track your savings, loans, and interest calculations with ease.

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Language: C++](https://img.shields.io/badge/Language-C%2B%2B-blue.svg)](https://www.cplusplus.com/)
[![Status: Active](https://img.shields.io/badge/Status-Active-brightgreen.svg)]()
[![Build: G++](https://img.shields.io/badge/Build-G%2B%2B-orange.svg)]()

---

##  Table of Contents

- [Overview](#-overview)
- [Features](#-features)
- [Demo Commands](#-demo-commands)
- [Installation](#-installation)
- [Usage](#-usage)
- [Folder Structure](#-folder-structure)
- [Screenshots](#-screenshots)
- [Future Improvements](#-future-improvements)
- [Contributing](#-contributing)
- [License](#-license)
- [Contact & Support](#-contact--support)

---

##  Overview

**FundFlow** is a command-line finance manager designed to simplify personal financial management. Whether you're tracking savings, managing loans, or calculating compound interest, FundFlow provides a robust and intuitive interface for all your financial needs.

With secure user authentication, comprehensive logging, and powerful data persistence, FundFlow is built for reliability and ease of use.

---

##  Features

-  **User Authentication** - Secure login system with user credentials management
-  **Logging System** - Comprehensive action tracking and audit trails
-  **Member Management** - Add, update, delete, and find user records with ease
-  **Savings & Loan Management** - Track and manage savings accounts and loan portfolios
-  **Compound Interest Calculation** - Advanced interest computation with customizable rates and periods
-  **File Persistence** - Automatic save/load functionality with robust data storage
-  **Command-Based Interface** - Intuitive command syntax for seamless user interaction
-  **Summary Features** - Quick overview with total balance, total savings, and total loans

---

## Demo Commands

Experience FundFlow with these sample commands:

```bash
# Add a new member with initial balance
add Muthu 500

# Update member's balance
update Muthu 1000

# Find member details
find Muthu

# View total balance across all members
total

# View total savings
totalSaving

# View total loans
totalLoan

# Display all members
list

# Delete a member
delete Muthu

# Save all data to file
save

# Load data from file
load

# View action logs
logs

# Exit the application
exit
```

###  Example Workflow

```
FundFlow> add John 5000
✓ Member 'John' added with balance: $5000

FundFlow> add Sarah 3000
✓ Member 'Sarah' added with balance: $3000

FundFlow> update John 6500
✓ Member 'John' updated with new balance: $6500

FundFlow> total
Total Balance: $9500

FundFlow> find John
Name: John | Balance: $6500 | Savings: $5000 | Loans: $1500

FundFlow> exit
Thank you for using FundFlow. Goodbye!
```

---

##  Installation

### Prerequisites

- **G++ Compiler** (version 7.0 or higher)
- **C++11** or later standard
- Unix-like environment (Linux, macOS) or Windows with MinGW

### Step 1: Clone the Repository

```bash
git clone https://github.com/muthugopi/fundflow.git
cd fundflow
```

### Step 2: Compile the Project

Using the G++ compiler:

```bash
g++ -std=c++11 -o fundflow main.cpp data_manager.cpp intrest.cpp auth/*.cpp log_controller/*.cpp users_data/*.cpp
```

Or with optimizations:

```bash
g++ -std=c++11 -O2 -o fundflow main.cpp data_manager.cpp intrest.cpp auth/*.cpp log_controller/*.cpp users_data/*.cpp
```

### Step 3: Run the Application

```bash
./fundflow
```

### Alternative: Using a Makefile

Create a `Makefile` for easier compilation:

```makefile
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
TARGET = fundflow
SOURCES = main.cpp data_manager.cpp intrest.cpp auth/*.cpp log_controller/*.cpp users_data/*.cpp

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)
```

Then simply run:

```bash
make
make run
```

---

##  Usage

### Starting the Application

```bash
./fundflow
```

Upon startup, you'll see:

```
═══════════════════════════════════════
    Welcome to FundFlow Finance Manager
═══════════════════════════════════════

Available Commands:
  add <name> <amount>      - Add a new member
  update <name> <amount>   - Update member balance
  find <name>              - Find member details
  delete <name>            - Delete a member
  list                     - List all members
  total                    - Show total balance
  totalSaving              - Show total savings
  totalLoan                - Show total loans
  interest <amount> <rate> - Calculate compound interest
  save                     - Save data to file
  load                     - Load data from file
  logs                     - View action logs
  help                     - Display help menu
  exit                     - Exit application

FundFlow>
```

### Command Reference

#### Member Management

| Command | Syntax | Example | Description |
|---------|--------|---------|-------------|
| Add | `add <name> <amount>` | `add Muthu 500` | Add new member with initial balance |
| Update | `update <name> <amount>` | `update Muthu 1000` | Update existing member's balance |
| Find | `find <name>` | `find Muthu` | Display member's details |
| Delete | `delete <name>` | `delete Muthu` | Remove member from system |
| List | `list` | `list` | Display all members |

#### Financial Summary

| Command | Syntax | Example | Description |
|---------|--------|---------|-------------|
| Total | `total` | `total` | Show combined balance of all members |
| Total Saving | `totalSaving` | `totalSaving` | Sum of all savings |
| Total Loan | `totalLoan` | `totalLoan` | Sum of all loans |

#### Other Operations

| Command | Syntax | Example | Description |
|---------|--------|---------|-------------|
| Interest | `interest <amount> <rate>` | `interest 1000 5` | Calculate compound interest |
| Save | `save` | `save` | Persist all data to `data.txt` |
| Load | `load` | `load` | Restore data from `data.txt` |
| Logs | `logs` | `logs` | Display action history |
| Help | `help` | `help` | Show command reference |
| Exit | `exit` | `exit` | Close the application |

---

##  Folder Structure

```
fundflow/
├── auth/                          # Authentication System
│   ├── auth.cpp                   # Authentication implementation
│   ├── auth.h                     # Authentication header
│   └── credentials.txt            # User credentials (encrypted)
│
├── log_controller/                # Logging System
│   ├── log_controller.cpp         # Logger implementation
│   ├── log_controller.h           # Logger header
│   └── log.txt                    # Action logs (auto-generated)
│
├── users_data/                    # User Management
│   ├── user.cpp                   # User class implementation
│   ├── user.h                     # User class header
│   └── users.txt                  # User records
│
├── main.cpp                       # CLI Entry Point
│   └── Contains command parser and main loop
│
├── data_manager.cpp               # Core Data Management
│   └── Handles CRUD operations, file I/O
│
├── data_manager.h                 # Data Manager Header
│   └── Class definitions and interfaces
│
├── intrest.cpp                    # Interest Calculation Logic
│   └── Compound interest algorithms
│
├── intrest.h                      # Interest Calculation Header
│
├── data.txt                       # Database File (auto-generated)
│   └── Serialized member data
│
├── log.txt                        # Logs File (auto-generated)
│   └── Activity tracking
│
├── Makefile                       # Build configuration
├── README.md                      # This file
├── LICENSE                        # MIT License
└── .gitignore                     # Git ignore rules

```

### Directory Descriptions

| Directory | Purpose |
|-----------|---------|
| **auth/** | Handles user login, password verification, and session management |
| **log_controller/** | Manages action logging, timestamps, and audit trails |
| **users_data/** | Contains user class definitions and member information |
| **root/** | Core application logic including data management and interest calculations |

---

##  Screenshots

### Main Menu
```
═══════════════════════════════════════
    Welcome to FundFlow Finance Manager
═══════════════════════════════════════

FundFlow> _
```

### Add Member
```
FundFlow> add Muthu 5000
✓ Successfully added member: Muthu
  Initial Balance: $5000
```

### Member Details
```
FundFlow> find Muthu
╔════════════════════════════════╗
║      MEMBER DETAILS            ║
╠════════════════════════════════╣
║ Name:        Muthu             ║
║ Balance:     $5000             ║
║ Savings:     $3500             ║
║ Loans:       $1500             ║
║ Interest:    5.25%             ║
╚════════════════════════════════╝
```

### Total Summary
```
FundFlow> total
╔════════════════════════════════╗
║      FINANCIAL SUMMARY         ║
╠════════════════════════════════╣
║ Total Members:    5            ║
║ Total Balance:    $25,000      ║
║ Total Savings:    $18,500      ║
║ Total Loans:      $6,500       ║
╚════════════════════════════════╝
```

---

##  Future Improvements

- [ ] **Database Integration** - Migrate from file-based storage to SQLite/PostgreSQL
- [ ] **Web Interface** - Build a responsive web dashboard with REST API
- [ ] **Mobile App** - iOS/Android companion app for on-the-go access
- [ ] **Advanced Reporting** - PDF reports, charts, and data visualization
- [ ] **Multi-Currency Support** - Handle multiple currencies with real-time conversion
- [ ] **Budget Planning** - Built-in budget allocation and tracking tools
- [ ] **Investment Tracking** - Monitor stock portfolios and mutual funds
- [ ] **Data Encryption** - Enhanced security with encryption algorithms
- [ ] **Cloud Sync** - Synchronize data across multiple devices
- [ ] **Notifications** - Email/SMS alerts for loan due dates and savings milestones
- [ ] **Performance Metrics** - Dashboard showing savings growth and financial health
- [ ] **User Profiles** - Customizable user preferences and themes

---

##  Contributing

We welcome contributions from the community! Here's how you can help:

### Steps to Contribute

1. **Fork the Repository**
   ```bash
   git clone https://github.com/yourusername/fundflow.git
   ```

2. **Create a Feature Branch**
   ```bash
   git checkout -b feature/AmazingFeature
   ```

3. **Commit Your Changes**
   ```bash
   git commit -m 'Add some AmazingFeature'
   ```

4. **Push to the Branch**
   ```bash
   git push origin feature/AmazingFeature
   ```

5. **Open a Pull Request**
   - Provide a clear description of changes
   - Reference any related issues
   - Ensure code follows project conventions

### Code Style Guidelines

- Use meaningful variable names
- Add comments for complex logic
- Follow the existing code structure
- Test thoroughly before submitting
- Keep commits atomic and descriptive

### Reporting Issues

Found a bug? Have a suggestion?
- **Open an Issue** on GitHub with a clear title and description
- Include steps to reproduce (for bugs)
- Attach error logs if applicable
- Suggest improvements with use cases

---



##  Contact & Support

Have questions? Need help? Reach out!

- **Issues** - [GitHub Issues](https://github.com/muthugopi/fundflow/issues)
- **Email** - muthugopij@gmail.com

### Getting Help

1. Check the [FAQ](#faq) section below
2. Search existing [GitHub Issues](https://github.com/muthugopi/fundflow/issues)
3. Review [Documentation](./docs/)
4. Create a new issue with detailed information

---

##  FAQ

**Q: Can I run FundFlow on Windows?**
A: Yes! Use MinGW or Windows Subsystem for Linux (WSL) to compile and run.

**Q: Is my financial data encrypted?**
A: Currently, data is stored in plain text files. For production use, consider implementing encryption.

**Q: How do I backup my data?**
A: Simply copy the `data.txt` file to a safe location. Use the `save` command before backup.

**Q: Can I import data from other finance apps?**
A: Currently not supported, but it's on our roadmap for future versions.

**Q: What's the maximum number of members?**
A: No hard limit, but performance may vary with very large datasets (>10,000 members).

---

##  Project Stats

- **Language** - C++ (C++11 standard)
- **Total Lines of Code** - ~2,000+
- **Components** - 6 main modules
- **Build Time** - <2 seconds
- **Executable Size** - ~500 KB

---

##  Acknowledgments

- Built with ❤️ by the FundFlow team
- Inspired by the need for simple, reliable financial management
- Thanks to all contributors and users for support and feedback

---

##  Version Info

- **Current Version** - 1.0.0
- **Release Date** - 2026
- **Last Updated** - 2026
- **Status** - Stable & Maintained

---

<div align="center">

**[⬆ back to top](#-fundflow---finance-manager)**

Made with ❤️ | © 2024 FundFlow Project

[Star us on GitHub](https://github.com/yourusername/fundflow) ⭐

</div>