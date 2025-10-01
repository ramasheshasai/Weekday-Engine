# Day of Week Calculator

A multi-platform application that determines the day of the week for any given date using the Doomsday algorithm. The project includes implementations in Python (Flask web app), Java (Swing GUI), and C++ (console application).

## Overview

This application calculates the day of the week for any date between 1600 and 2099 using mathematical algorithms based on month codes, century codes, and modular arithmetic. It also validates dates, identifies leap years, and optionally displays detailed calculation breakdowns.

## Features

- Calculate day of the week for dates from 1600 to 2099
- Automatic leap year detection and validation
- Date validation to prevent invalid entries
- Optional detailed calculation breakdown showing:
  - Month codes
  - Century codes
  - Year remainders and quotients
  - Step-by-step mathematical operations
- Three platform implementations for maximum accessibility

## Technology Stack

### Web Application (Flask/Python)
- **Backend:** Python 3.x with Flask framework
- **Frontend:** HTML5, CSS3 with responsive design
- **Styling:** Custom gradient design with animations
- **Fonts:** Google Fonts (Poppins)
- **Icons:** Font Awesome 6.4.0

### Desktop Application (Java)
- **Framework:** Java Swing
- **GUI Components:** JFrame, JTextField, JTextArea, JButton
- **Event Handling:** ActionListener interface

### Console Application (C++)
- **Language:** C++ with OOP principles
- **Design Pattern:** Multi-level inheritance hierarchy
- **Features:** Friend functions, operator overloading, static members

## File Structure

```
project/
├── app.py                  # Flask web application
├── templates/
│   └── index.html         # Web interface with CSS styling
├── DayFinderApp.java      # Java Swing GUI application
├── Calender.cpp           # C++ console application
└── README.md              # This file
```

## Installation & Usage

### Web Application (Flask)

1. Install dependencies:
```bash
pip install flask
```

2. Run the application:
```bash
python app.py
```

3. Open browser and navigate to `http://127.0.0.1:5000/`

### Java Desktop Application

1. Compile:
```bash
javac DayFinderApp.java
```

2. Run:
```bash
java DayFinderApp
```

### C++ Console Application

1. Compile:
```bash
g++ Calender.cpp -o calendar
```

2. Run:
```bash
./calendar
```

## Algorithm Explanation

The application uses a mathematical formula based on the Doomsday algorithm:

```
Day of Week = (Date + Month Code + Year + Year/4 + Century Code) % 7
```

### Components:

1. **Month Codes:** Each month has a predefined code (Jan=0, Feb=3, Mar=3, etc.)
2. **Year:** Last two digits of the year
3. **Year/4:** Integer division of last two digits by 4
4. **Century Codes:**
   - 1600-1699: 6
   - 1700-1799: 4
   - 1800-1899: 2
   - 1900-1999: 0
   - 2000-2099: 6

5. **Result:** Remainder when divided by 7 gives day (0=Sunday, 1=Monday, etc.)

## Input Validation

- Date range: 1-31 (validated against month and leap year)
- Month range: 1-12
- Year range: 1600-2099
- Leap year calculation: Accounts for century rules (divisible by 400 or by 4 but not 100)

## Design Features (Web App)

- Responsive layout for mobile and desktop
- Animated gradient background
- Glassmorphism UI with backdrop blur
- Smooth transitions and hover effects
- Accessibility features (ARIA labels, keyboard navigation)
- Interactive checkbox for showing calculation details

## Performance Metrics

- Algorithm complexity: O(1) constant time
- Date validation: O(1) constant time
- Supports 500 years of dates (1600-2099)
- Web app response time: <100ms
- Zero external API dependencies for calculations

## Live Demo

Web application deployed at: https://rama082005.pythonanywhere.com/

## Future Enhancements

- Extend year range beyond 2099
- Add support for different calendar systems
- Implement date range calculations
- Add historical date events lookup
- Multi-language support
- REST API endpoints for programmatic access

## License

This project is available for educational and personal use.

## Author

Created as a demonstration of multi-platform development and algorithmic problem-solving.
