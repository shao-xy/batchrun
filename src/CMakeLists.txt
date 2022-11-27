add_subdirectory(common)
add_subdirectory(test)

add_executable(batchrun batchrun.c)
target_link_libraries(batchrun common)
