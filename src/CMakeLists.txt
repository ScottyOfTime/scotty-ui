find_package(SDL2 REQUIRED)
find_package(SDL2TTF REQUIRED)

add_library(scotty-ui
	app.c
	screen.c
	button.c
)

target_include_directories(scotty-ui PRIVATE
	.
)

target_include_directories(scotty-ui  PRIVATE
	${SDL2_INCLUDE_DIRS}
	${SDL2TTF_INCLUDE_DIR}
)

target_link_libraries(scotty-ui PRIVATE
	${SDL2_LIBRARIES}
	${SDL2TTF_LIBRARY}
)
