# Synecta-test-assignment

A C++ application using the Qt library, which has the ability to load a measurement file (Touchstone) and visualize its data on graphs.

## Prerequisites

* **Operating System:** Windows 10
* **Qt:** Version 5.15.2 ([Qt download link](https://www.qt.io/download-open-source/)).
* **Compiler:**
    * MinGW 64-bit
* **Build System:** `qmake`

## Building the Application

1.  Open the command prompt or terminal.
2.  Navigate to the root directory of the project.
3.  Execute the command to generate the Makefile:
    ```bash
    qmake -project
    ```
4.  Execute the command to build the project:
    ```bash
    qmake
    ```
5.  Start the build process:
    * Release:
        ```bash
        mingw32-make release
        ```
        *OR, if `mingw32-make` does not work, try:*
        ```bash
        mingw64-make release
        ```
        The executable file will be located in the `release` directory.

## Running the Application

A deploy build needs to be created (you can use `windeployqt`).

After that, navigate to the `release` directory and run the executable file:

* `Synecta-test-assignment.exe`
