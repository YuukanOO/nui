# Add the executable
add_executable(basic ${NUI_EXE_FLAGS} main.c)

# Link the sample
target_link_libraries(basic ${NUI_EXE_LIBS} nui)