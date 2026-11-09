# Neko

Neko is a small C utility for reading files.

## Build

Requirements:

- CMake
- A C compiler, such as GCC or Clang

Configure and build the project:

```sh
cmake -S . -B build
cmake --build build
```

The executable will be created at:

```text
build/neko
```

## Run

```sh
./build/neko
```

## Project structure

```text
inc/          Public headers
src/          Application source code
src/file/     File-reading implementation
build/        CMake build directory
```

## License

See [`LICENSE`](LICENSE).
