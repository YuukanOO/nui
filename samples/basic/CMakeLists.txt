# Set some flags if needed
set(EXE_FLAGS)
if(WIN32)
	set(EXE_FLAGS ${EXE_FLAGS} WIN32)
endif(WIN32)

# Add the executable
add_executable(basic ${EXE_FLAGS} main.c)

# Link the sample
target_link_libraries(basic nui)