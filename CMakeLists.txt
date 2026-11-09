cmake_minimum_required(VERSION 3.10)
project(neko C)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
include_directories(inc)
find_package(Threads REQUIRED)

set(SOURCES
    src/main.c

    src/file/open_file.c
    src/file/read_file.c
)

add_executable(neko ${SOURCES})

target_compile_options(neko PRIVATE
    -Wall -Wextra -Wpedantic -Wshadow -Wconversion
    -fsanitize=address,undefined
)

target_link_libraries(neko PRIVATE
    Threads::Threads
    -fsanitize=address,undefined
)


install(TARGETS neko RUNTIME DESTINATION bin)
