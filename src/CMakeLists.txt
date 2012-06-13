# Add the library to the output target
add_library(nui 	nui.c
					memory.c
					utils/log.c
					${NATIVE_DIR}/native.c)