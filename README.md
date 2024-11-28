# muons-betatron-oscillations
This repository contains C++ and MATLAB files for simulating the horizontal and vertical betatron oscillations of muons in the g-2 storage ring at KEK, JAPRC. The simulations use the Runge-Kutta 4th Order (RK4) method to solve the equations of motion in a weak focusing storage ring.

---

## Project Structure

### Files Overview
- **Horizontal Betatron Oscillation**:
  - `Horizontal Betatron Oscillation.cpp`: A C++ program that simulates horizontal betatron oscillations using RK4 and saves position and velocity data to a text file.
  - `Horizontal_Betatron_Oscillation.m`: A MATLAB script to visualize the results (position and velocity vs. time).

- **Vertical Betatron Oscillation**:
  - `Vertical Betatron Oscillation.cpp`: A C++ program that simulates vertical betatron oscillations using RK4 and saves position and velocity data to a text file.
  - `Vertical_Betatron_Oscillation.m`: A MATLAB script to visualize the results (position and velocity vs. time).

### Output Files
- **horizontal_betatron_oscillation_cm.txt**: Contains time, position (x), and velocity (\(\dot{x}\)) data for the horizontal oscillation in centimeters and seconds.
- **muon_VBO_trajectory_cm.txt**: Contains time, position (z), and velocity (\(\dot{z}\)) data for the vertical oscillation in centimeters and seconds.

---

## Simulation Details

### Horizontal Betatron Oscillations
- **Equation of Motion**:  
  x'' + ω₀²(1 - n)x = 0  
  Where:  
  - ω₀: Theoretical angular frequency.  
  - n: Field index (weak focusing strength).

- **Initial Conditions**:  
  - x(0) = 1.0 cm  
  - x'(0) = 0.0 cm/s  

- **Time Step**: 1 ns  
- **Duration**: 120 ns  

---

### Vertical Betatron Oscillations
- **Equation of Motion**:  
  z'' + nω₀²z = 0  
  Where:  
  - ω₀: Theoretical angular frequency.  
  - n: Field index.

- **Initial Conditions**:  
  - z(0) = 5.0 cm  
  - z'(0) = 0.0 cm/s  

- **Time Step**: 1 ns  
- **Duration**: 10 μs  

---

## Visualization

### MATLAB Plots
The MATLAB scripts generate the following visualizations:
1. **Position vs. Time**:
   - Displays the oscillatory motion of muons in the weak focusing field.
2. **Velocity vs. Time**:
   - Illustrates the velocity variation corresponding to the oscillations.

Each MATLAB script uses `sgtitle` to group the plots under a single heading.

---

## How to Use

1. **C++ Programs**:
   - Compile the `.cpp` files using a C++ compiler (e.g., `g++`).
     ```bash
     g++ Horizontal\ Betatron\ Oscillation.cpp -o horizontal
     ./horizontal
     ```
   - The output data will be saved to a text file (e.g., `horizontal_betatron_oscillation_cm.txt`).

2. **MATLAB Scripts**:
   - Run the `.m` files in MATLAB after generating the respective output data from the C++ programs.
   - Example:
     ```matlab
     run('Horizontal_Betatron_Oscillation.m')
     ```

---

## Dependencies
- **C++**:
  - Any standard C++ compiler (e.g., GCC, Clang, MSVC).
- **MATLAB**:
  - MATLAB version with basic plotting capabilities.

---

## Applications
These simulations are part of the study of betatron oscillations, which are crucial for understanding:
- The dynamics of stored muons in weak focusing fields.
- The design and analysis of storage rings for high-energy particle experiments like the Muon g-2/EDM experiment at J-PARC.

---
