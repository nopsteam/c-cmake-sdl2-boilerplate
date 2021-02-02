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
make build
```

### Run Tests
This will build and run unity tests

```bash
make test
```

### Run Binary
This will open an SDL black window with the unlicense logo on it for 3 seconds.
```bash
./build/bin/example_app
```

## Project directory structure

 - app/ -- Application source code.
 - src/ -- Library source code and headers.
 - test/ -- Test source code.
   - unity/ -- Unity test framework source.

## Build directory structure

 - bin/ -- Application binaries.
   - test/ -- Test binaries.
 - lib/ -- Libraries.

## License
This is free and unencumbered software released into the public domain
For more information, please refer to <http://unlicense.org/>
