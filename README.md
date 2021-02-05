# C, Cmake and SDL2 Boilerplate

This is a C project template with the following features:

 - CMake build scripts for building libraries, applications, and tests.
 - Integrated with [Unity unit test framework](https://github.com/ThrowTheSwitch/Unity).
 - Integrated with [SDL2](https://www.libsdl.org/).
 - Integrated with [SDL2 Image](https://www.libsdl.org/projects/SDL_image/).
 - Resource folder to include assets
 - Updated and simplified version of [C-project-template](https://github.com/peterdn/C-project-template)

## Usage

### Build
```bash
# Debug build
make 
# Release build
make release
```

### Run Tests
This will build and run unity tests
```bash
make test
```

### Clean
This will delete generated files for debug and release
```bash
make clean
```

### Run Binary
This will open an SDL black window with the unlicense logo on it for 3 seconds.
```bash
# Debug bin
./build/debug/bin/example_app
# Release bin
./build/release/bin/example_app
```

## Directory Structure
```
 - app/ -- Application source code.
 - src/ -- Library source code and headers.
 - resources/ -- Application resources assets folder.
 - test/ -- Test source code.
   - unity/ -- Unity test framework source.

 - build/cmake -- Cmake Finders for external compiled libs

 - build/debug -- Application debug build
   - bin/ -- Application binaries.
   - resources/ -- Application resources assets symbolic link.
     - test/ -- Test binaries.
   - lib/ -- Libraries.

 - build/release -- Application release build
   - bin/ -- Application binaries.
   - resources/ -- Application resources assets symbolic link.
   - lib/ -- Libraries.
```

## Dependencies
 - [Clang](https://clang.llvm.org/)
 - [Make](https://www.gnu.org/software/make/)
 - [CMake](https://cmake.org/)
 - [SDL2](https://www.libsdl.org/)
 - [SDL2 Image](https://www.libsdl.org/projects/SDL_image/)

### Installing Dependencies

#### Arch Linux
```bash
pacman -Sy clang cmake sdl2 sdl2_image
```

#### Ubuntu
```bash
sudo add-apt-repository -y "deb http://archive.ubuntu.com/ubuntu `lsb_release -sc` main universe restricted multiverse"
sudo apt-get update -y -qq
sudo apt-get install clang cmake libsdl2-dev libsdl2-image-dev
```

## License
This is free and unencumbered software released into the public domain.  
For more information, please refer to <http://unlicense.org/>
