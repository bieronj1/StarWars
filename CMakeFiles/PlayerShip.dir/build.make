# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.3

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
CMAKE_SOURCE_DIR = /home/f85/msnelsen/CS420/StarWars

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/f85/msnelsen/CS420/StarWars

# Include any dependencies generated for this target.
include CMakeFiles/PlayerShip.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/PlayerShip.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PlayerShip.dir/flags.make

CMakeFiles/PlayerShip.dir/bin/PlayerShip.cpp.o: CMakeFiles/PlayerShip.dir/flags.make
CMakeFiles/PlayerShip.dir/bin/PlayerShip.cpp.o: bin/PlayerShip.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/f85/msnelsen/CS420/StarWars/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PlayerShip.dir/bin/PlayerShip.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/PlayerShip.dir/bin/PlayerShip.cpp.o -c /home/f85/msnelsen/CS420/StarWars/bin/PlayerShip.cpp

CMakeFiles/PlayerShip.dir/bin/PlayerShip.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PlayerShip.dir/bin/PlayerShip.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/f85/msnelsen/CS420/StarWars/bin/PlayerShip.cpp > CMakeFiles/PlayerShip.dir/bin/PlayerShip.cpp.i

CMakeFiles/PlayerShip.dir/bin/PlayerShip.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PlayerShip.dir/bin/PlayerShip.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/f85/msnelsen/CS420/StarWars/bin/PlayerShip.cpp -o CMakeFiles/PlayerShip.dir/bin/PlayerShip.cpp.s

CMakeFiles/PlayerShip.dir/bin/PlayerShip.cpp.o.requires:

.PHONY : CMakeFiles/PlayerShip.dir/bin/PlayerShip.cpp.o.requires

CMakeFiles/PlayerShip.dir/bin/PlayerShip.cpp.o.provides: CMakeFiles/PlayerShip.dir/bin/PlayerShip.cpp.o.requires
	$(MAKE) -f CMakeFiles/PlayerShip.dir/build.make CMakeFiles/PlayerShip.dir/bin/PlayerShip.cpp.o.provides.build
.PHONY : CMakeFiles/PlayerShip.dir/bin/PlayerShip.cpp.o.provides

CMakeFiles/PlayerShip.dir/bin/PlayerShip.cpp.o.provides.build: CMakeFiles/PlayerShip.dir/bin/PlayerShip.cpp.o


# Object files for target PlayerShip
PlayerShip_OBJECTS = \
"CMakeFiles/PlayerShip.dir/bin/PlayerShip.cpp.o"

# External object files for target PlayerShip
PlayerShip_EXTERNAL_OBJECTS =

PlayerShip: CMakeFiles/PlayerShip.dir/bin/PlayerShip.cpp.o
PlayerShip: CMakeFiles/PlayerShip.dir/build.make
PlayerShip: /home/f85/msnelsen/SFML/lib/libsfml-graphics.so
PlayerShip: /home/f85/msnelsen/SFML/lib/libsfml-window.so
PlayerShip: /home/f85/msnelsen/SFML/lib/libsfml-system.so
PlayerShip: /home/f85/msnelsen/SFML/lib/libsfml-audio.so
PlayerShip: /home/f85/msnelsen/SFML/lib/libsfml-network.so
PlayerShip: CMakeFiles/PlayerShip.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/f85/msnelsen/CS420/StarWars/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable PlayerShip"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PlayerShip.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PlayerShip.dir/build: PlayerShip

.PHONY : CMakeFiles/PlayerShip.dir/build

CMakeFiles/PlayerShip.dir/requires: CMakeFiles/PlayerShip.dir/bin/PlayerShip.cpp.o.requires

.PHONY : CMakeFiles/PlayerShip.dir/requires

CMakeFiles/PlayerShip.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PlayerShip.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PlayerShip.dir/clean

CMakeFiles/PlayerShip.dir/depend:
	cd /home/f85/msnelsen/CS420/StarWars && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/f85/msnelsen/CS420/StarWars /home/f85/msnelsen/CS420/StarWars /home/f85/msnelsen/CS420/StarWars /home/f85/msnelsen/CS420/StarWars /home/f85/msnelsen/CS420/StarWars/CMakeFiles/PlayerShip.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PlayerShip.dir/depend

