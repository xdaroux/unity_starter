file(GLOB SOURCES ./*.c ../src/*.c)

add_subdirectory(unity)
add_executable(test ${SOURCES})
target_link_libraries(test unity)
