find_package(SDL2 REQUIRED)

add_library(scotty-ui
	app.c
	screen.c
)

target_include_directories(scotty-ui PRIVATE
	.
)

include_directories(scotty ${SDL2_INCLUDE_DIRS})

target_link_libraries(scotty-ui PUBLIC
	${SDL2_LIBRARIES}
)
