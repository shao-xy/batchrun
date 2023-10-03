add_subdirectory(common)
add_subdirectory(test)

add_executable(batchrund batchrund.c)
target_link_libraries(batchrund common)
