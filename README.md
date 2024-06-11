# C-SDL1.2 Project Environment

**A simple template for starting a complex C-SDL1.2 project.**

## Overview

This template provides a basic structure for starting a complex C-SDL1.2 project. It includes essential directories and files to help you organize your code and easily get started with development using the **CMake** to generate a build system including the **Makefile/build.ninja**.

## Project Structure

```plaintext
.C-SDL1.2 Project Environment
├── bin
│   ├── build
│   │   └── build
│   ├── debug
│   │   └── debug
│   ├── release
│   │   └── release
│   └── test
│       └── test
├── C-SDL1.2 Project Environment.code-workspace
├── doc
│   ├── pdf
│   │   └── NONE.pdf
│   └── TODO.md
├── download
│   └── download
├── LICENSE
├── pkg
│   ├── C-Cpp_pkg.cmd
│   ├── C-Cpp_pkg.sh
│   └── CMakeLists.txt
├── project
│   ├── doc
│   │   └── doc
│   ├── inc
│   │   └── inc.h
│   ├── res
│   │   └── res
│   └── src
│       ├── lib.c
│       └── main.c
├── README.md
└── run.sh

15 directories, 19 files
```

## How to Use

To lunch the project on your Linux system, follow these steps:

1. **Clone the Repository**:

    ```sh
    git clone https://github.com/ZouariOmar/Run_C_Project.git
    ```

2. **Navigate to the Directory**:

    ```sh
    cd 'C-SDL1.2 Project Environment'
    ```

3. **Make the script executable**:

    ```sh
    chmod +x run.sh
    ```

4. **Build & Run the Application**:

    ```sh
    ./run.sh <COMMAND>
    ```

- **COMMAND: make/ninja**

- **Note: if you are using VSC, you can't run your program using the "Code Runner" extension**

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Contact

If you have any questions or suggestions, please feel free to reach out to us at [zouariomar20@gmail.com](mailto:zouariomar20@gmail.com)
