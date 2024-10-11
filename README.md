# OpenVPP Software

This repository contains Python software for the Open Architecture Vat Photopolymerization (VPP) Bottom-Up 3D printing system. The OpenVPP system is designed to offer customizable and modular control over the 3D printing process, including slicing, projector control, and motor management.

## Overview

The OpenVPP software provides tools for handling the entire 3D printing process, from slicing 3D models to controlling the projector and motors. This open-source project is intended for researchers and developers who need a flexible framework to work with vat photopolymerization systems.

## Features

- **3D Slicing**: Efficient slicing of 3D models with adjustable layer settings.
- **Projector Control**: Interface for controlling various projectors used in photopolymerization.
- **Motor Management**: Precision control of motors for Z-axis movement during printing.
- **Modular Design**: Easily extend or modify components to suit specific needs.

## System Requirements

- **Python 3.x**
- **Anaconda** (for environment management)
- **C++ Compiler** (recommended: Visual Studio 2019 for external libraries)
- **Supported OS**: Windows 64-bit

## Installation

### Step 1: Clone the Repository

1. Install [Git](https://git-scm.com/downloads).
2. Open **Git Bash** and navigate to your desired directory:
   ```bash
   cd Documents

3. Clone the repository
   ```bash
   git clone https://github.com/DTUOpenAM/OpenVPP_Software.git

### Step 2: Set Up the Environment

1. Install [Anaconda 64-bit](https://www.anaconda.com/products/individual).
2. Open **Anaconda Prompt** in the installation directory.
3. Create the environment:
   ```bash
   conda env create -f environment.yaml
   
### Step 3: Update the Environment

1. Activate the environment:
   ```bash
   conda activate 3DOpenSource
2. Update the environment
   ```bash
   conda env update --file environment.yaml

## Usage

1. Open **Anaconda Prompt** in the software installation directory.
2. Activate the environment:
   
   ```bash
   conda activate 3DOpenSource
   
3. Run the main GUI:

   ```bash
   python mainGUI.py

### Main Control GUI

This tab contains the GUI for the main control of the printer. Here, you can access a variety of printer and projector options, as well as configure layer parameters:

- **Printer Options**
  
  - **Establish connection with Arduino for stage control**: Connect to the Arduino to manage the Z-axis and other stage operations.
  - **Move building plate**: Manually move the building plate to the desired position.
  - **Set building plate origin**: Manually adjust and set the building plate origin for accurate positioning.
  - **Home building plate**: Automatically return the building plate to its home position.

- **Projector Options**
  
  - **Establish connection with projector**: Connect to the projector to control exposure and image projection.
  - **Project pattern to check focusing**: Project a pattern to ensure proper focusing and alignment of the projector.
  - **Set projector amplitude**: Adjust the projector amplitude (currently limited to a maximum of 255 for Wintech projectors).

- **Support Layer Parameters and Features Layer Parameters**
  
  - **Process parameters for different layers**: Configure the process parameters specific to support layers and feature layers, optimizing exposure and curing settings based on the material and layer characteristics.


   
## Key Components

- **dlpSlicer.py**: Handles the slicing of 3D models and preparation for layer-by-layer printing.
- **dlpProjectorController.py**: Manages the interface with the projector for light exposure control.
- **dlpMotorController.py**: Controls the motor responsible for Z-axis movement during printing.
- **mainGUI.py**: Launches the main graphical interface for controlling the printing process.

## How to add new projectors

*A new projector should implement the following interface:*

- **init_projector()** -> *initialize and turn on the projector, return True if succeeds, False otherwise*
- **stop_projector()** -> *shut down projector*
- **set_amplitude(a)** -> *set the projector amplitude to the value of the parameter a*

## How to add different motors for Z stage

*A new motor should implement the following interface:*

- **get_step_length_microns()** -> *return the length of a single motor step in microns*
- **connect_motor(serial_port)** -> *connect and activate motor, return True or False. serial_port parameter could be ignored if different connection is used*
- **disconnect_motor()** -> *disconnect motor, return True or False*
- **reset_motor()** -> *reset motor status, this function could be left empty, return True or False*
- **home_motor()** -> *send building plate to home position, return True or False*
- **move_motor(distance, feed_rate, relative_move)** -> *move building plate, relative_move is a boolean indicating if the movement is relative to the current position or absolute*
- **move_projector(distance_mm, feed_rate_mm_min, is_relative)** -> *move projector, is_relative is a boolean indicating if the movement is relative to the current position or absolute*

## Contributing

Contributions are welcome! Please fork the repository, make your changes, and submit a pull request. Ensure that you thoroughly test your changes and document any new features.

