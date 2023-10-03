add_library(common STATIC
	common.c
	logger.c
)
target_link_libraries(common ${CURSES_LIBRARIES} Threads::Threads)
