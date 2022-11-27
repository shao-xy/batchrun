add_library(common STATIC
	common.c
)
target_link_libraries(common ${CURSES_LIBRARIES})
