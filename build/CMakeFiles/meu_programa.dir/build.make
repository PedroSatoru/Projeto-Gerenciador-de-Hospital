# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /workspaces/Projeto-Gerenciador-de-Hospital

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /workspaces/Projeto-Gerenciador-de-Hospital/build

# Include any dependencies generated for this target.
include CMakeFiles/meu_programa.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/meu_programa.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/meu_programa.dir/flags.make

CMakeFiles/meu_programa.dir/src/main.c.o: CMakeFiles/meu_programa.dir/flags.make
CMakeFiles/meu_programa.dir/src/main.c.o: ../src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/Projeto-Gerenciador-de-Hospital/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/meu_programa.dir/src/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/meu_programa.dir/src/main.c.o   -c /workspaces/Projeto-Gerenciador-de-Hospital/src/main.c

CMakeFiles/meu_programa.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/meu_programa.dir/src/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /workspaces/Projeto-Gerenciador-de-Hospital/src/main.c > CMakeFiles/meu_programa.dir/src/main.c.i

CMakeFiles/meu_programa.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/meu_programa.dir/src/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /workspaces/Projeto-Gerenciador-de-Hospital/src/main.c -o CMakeFiles/meu_programa.dir/src/main.c.s

# Object files for target meu_programa
meu_programa_OBJECTS = \
"CMakeFiles/meu_programa.dir/src/main.c.o"

# External object files for target meu_programa
meu_programa_EXTERNAL_OBJECTS =

meu_programa: CMakeFiles/meu_programa.dir/src/main.c.o
meu_programa: CMakeFiles/meu_programa.dir/build.make
meu_programa: libbibliotecas.a
meu_programa: CMakeFiles/meu_programa.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/workspaces/Projeto-Gerenciador-de-Hospital/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable meu_programa"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/meu_programa.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/meu_programa.dir/build: meu_programa

.PHONY : CMakeFiles/meu_programa.dir/build

CMakeFiles/meu_programa.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/meu_programa.dir/cmake_clean.cmake
.PHONY : CMakeFiles/meu_programa.dir/clean

CMakeFiles/meu_programa.dir/depend:
	cd /workspaces/Projeto-Gerenciador-de-Hospital/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /workspaces/Projeto-Gerenciador-de-Hospital /workspaces/Projeto-Gerenciador-de-Hospital /workspaces/Projeto-Gerenciador-de-Hospital/build /workspaces/Projeto-Gerenciador-de-Hospital/build /workspaces/Projeto-Gerenciador-de-Hospital/build/CMakeFiles/meu_programa.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/meu_programa.dir/depend
