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
include CMakeFiles/shipBuilder.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/shipBuilder.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/shipBuilder.dir/flags.make

CMakeFiles/shipBuilder.dir/src/Body.cpp.o: CMakeFiles/shipBuilder.dir/flags.make
CMakeFiles/shipBuilder.dir/src/Body.cpp.o: src/Body.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/f85/msnelsen/CS420/StarWars/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/shipBuilder.dir/src/Body.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/shipBuilder.dir/src/Body.cpp.o -c /home/f85/msnelsen/CS420/StarWars/src/Body.cpp

CMakeFiles/shipBuilder.dir/src/Body.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/shipBuilder.dir/src/Body.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/f85/msnelsen/CS420/StarWars/src/Body.cpp > CMakeFiles/shipBuilder.dir/src/Body.cpp.i

CMakeFiles/shipBuilder.dir/src/Body.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/shipBuilder.dir/src/Body.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/f85/msnelsen/CS420/StarWars/src/Body.cpp -o CMakeFiles/shipBuilder.dir/src/Body.cpp.s

CMakeFiles/shipBuilder.dir/src/Body.cpp.o.requires:

.PHONY : CMakeFiles/shipBuilder.dir/src/Body.cpp.o.requires

CMakeFiles/shipBuilder.dir/src/Body.cpp.o.provides: CMakeFiles/shipBuilder.dir/src/Body.cpp.o.requires
	$(MAKE) -f CMakeFiles/shipBuilder.dir/build.make CMakeFiles/shipBuilder.dir/src/Body.cpp.o.provides.build
.PHONY : CMakeFiles/shipBuilder.dir/src/Body.cpp.o.provides

CMakeFiles/shipBuilder.dir/src/Body.cpp.o.provides.build: CMakeFiles/shipBuilder.dir/src/Body.cpp.o


CMakeFiles/shipBuilder.dir/src/Flipper.cpp.o: CMakeFiles/shipBuilder.dir/flags.make
CMakeFiles/shipBuilder.dir/src/Flipper.cpp.o: src/Flipper.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/f85/msnelsen/CS420/StarWars/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/shipBuilder.dir/src/Flipper.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/shipBuilder.dir/src/Flipper.cpp.o -c /home/f85/msnelsen/CS420/StarWars/src/Flipper.cpp

CMakeFiles/shipBuilder.dir/src/Flipper.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/shipBuilder.dir/src/Flipper.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/f85/msnelsen/CS420/StarWars/src/Flipper.cpp > CMakeFiles/shipBuilder.dir/src/Flipper.cpp.i

CMakeFiles/shipBuilder.dir/src/Flipper.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/shipBuilder.dir/src/Flipper.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/f85/msnelsen/CS420/StarWars/src/Flipper.cpp -o CMakeFiles/shipBuilder.dir/src/Flipper.cpp.s

CMakeFiles/shipBuilder.dir/src/Flipper.cpp.o.requires:

.PHONY : CMakeFiles/shipBuilder.dir/src/Flipper.cpp.o.requires

CMakeFiles/shipBuilder.dir/src/Flipper.cpp.o.provides: CMakeFiles/shipBuilder.dir/src/Flipper.cpp.o.requires
	$(MAKE) -f CMakeFiles/shipBuilder.dir/build.make CMakeFiles/shipBuilder.dir/src/Flipper.cpp.o.provides.build
.PHONY : CMakeFiles/shipBuilder.dir/src/Flipper.cpp.o.provides

CMakeFiles/shipBuilder.dir/src/Flipper.cpp.o.provides.build: CMakeFiles/shipBuilder.dir/src/Flipper.cpp.o


CMakeFiles/shipBuilder.dir/src/Menu.cpp.o: CMakeFiles/shipBuilder.dir/flags.make
CMakeFiles/shipBuilder.dir/src/Menu.cpp.o: src/Menu.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/f85/msnelsen/CS420/StarWars/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/shipBuilder.dir/src/Menu.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/shipBuilder.dir/src/Menu.cpp.o -c /home/f85/msnelsen/CS420/StarWars/src/Menu.cpp

CMakeFiles/shipBuilder.dir/src/Menu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/shipBuilder.dir/src/Menu.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/f85/msnelsen/CS420/StarWars/src/Menu.cpp > CMakeFiles/shipBuilder.dir/src/Menu.cpp.i

CMakeFiles/shipBuilder.dir/src/Menu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/shipBuilder.dir/src/Menu.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/f85/msnelsen/CS420/StarWars/src/Menu.cpp -o CMakeFiles/shipBuilder.dir/src/Menu.cpp.s

CMakeFiles/shipBuilder.dir/src/Menu.cpp.o.requires:

.PHONY : CMakeFiles/shipBuilder.dir/src/Menu.cpp.o.requires

CMakeFiles/shipBuilder.dir/src/Menu.cpp.o.provides: CMakeFiles/shipBuilder.dir/src/Menu.cpp.o.requires
	$(MAKE) -f CMakeFiles/shipBuilder.dir/build.make CMakeFiles/shipBuilder.dir/src/Menu.cpp.o.provides.build
.PHONY : CMakeFiles/shipBuilder.dir/src/Menu.cpp.o.provides

CMakeFiles/shipBuilder.dir/src/Menu.cpp.o.provides.build: CMakeFiles/shipBuilder.dir/src/Menu.cpp.o


CMakeFiles/shipBuilder.dir/src/Nose.cpp.o: CMakeFiles/shipBuilder.dir/flags.make
CMakeFiles/shipBuilder.dir/src/Nose.cpp.o: src/Nose.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/f85/msnelsen/CS420/StarWars/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/shipBuilder.dir/src/Nose.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/shipBuilder.dir/src/Nose.cpp.o -c /home/f85/msnelsen/CS420/StarWars/src/Nose.cpp

CMakeFiles/shipBuilder.dir/src/Nose.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/shipBuilder.dir/src/Nose.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/f85/msnelsen/CS420/StarWars/src/Nose.cpp > CMakeFiles/shipBuilder.dir/src/Nose.cpp.i

CMakeFiles/shipBuilder.dir/src/Nose.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/shipBuilder.dir/src/Nose.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/f85/msnelsen/CS420/StarWars/src/Nose.cpp -o CMakeFiles/shipBuilder.dir/src/Nose.cpp.s

CMakeFiles/shipBuilder.dir/src/Nose.cpp.o.requires:

.PHONY : CMakeFiles/shipBuilder.dir/src/Nose.cpp.o.requires

CMakeFiles/shipBuilder.dir/src/Nose.cpp.o.provides: CMakeFiles/shipBuilder.dir/src/Nose.cpp.o.requires
	$(MAKE) -f CMakeFiles/shipBuilder.dir/build.make CMakeFiles/shipBuilder.dir/src/Nose.cpp.o.provides.build
.PHONY : CMakeFiles/shipBuilder.dir/src/Nose.cpp.o.provides

CMakeFiles/shipBuilder.dir/src/Nose.cpp.o.provides.build: CMakeFiles/shipBuilder.dir/src/Nose.cpp.o


CMakeFiles/shipBuilder.dir/src/PlayerShip.cpp.o: CMakeFiles/shipBuilder.dir/flags.make
CMakeFiles/shipBuilder.dir/src/PlayerShip.cpp.o: src/PlayerShip.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/f85/msnelsen/CS420/StarWars/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/shipBuilder.dir/src/PlayerShip.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/shipBuilder.dir/src/PlayerShip.cpp.o -c /home/f85/msnelsen/CS420/StarWars/src/PlayerShip.cpp

CMakeFiles/shipBuilder.dir/src/PlayerShip.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/shipBuilder.dir/src/PlayerShip.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/f85/msnelsen/CS420/StarWars/src/PlayerShip.cpp > CMakeFiles/shipBuilder.dir/src/PlayerShip.cpp.i

CMakeFiles/shipBuilder.dir/src/PlayerShip.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/shipBuilder.dir/src/PlayerShip.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/f85/msnelsen/CS420/StarWars/src/PlayerShip.cpp -o CMakeFiles/shipBuilder.dir/src/PlayerShip.cpp.s

CMakeFiles/shipBuilder.dir/src/PlayerShip.cpp.o.requires:

.PHONY : CMakeFiles/shipBuilder.dir/src/PlayerShip.cpp.o.requires

CMakeFiles/shipBuilder.dir/src/PlayerShip.cpp.o.provides: CMakeFiles/shipBuilder.dir/src/PlayerShip.cpp.o.requires
	$(MAKE) -f CMakeFiles/shipBuilder.dir/build.make CMakeFiles/shipBuilder.dir/src/PlayerShip.cpp.o.provides.build
.PHONY : CMakeFiles/shipBuilder.dir/src/PlayerShip.cpp.o.provides

CMakeFiles/shipBuilder.dir/src/PlayerShip.cpp.o.provides.build: CMakeFiles/shipBuilder.dir/src/PlayerShip.cpp.o


CMakeFiles/shipBuilder.dir/src/Tail.cpp.o: CMakeFiles/shipBuilder.dir/flags.make
CMakeFiles/shipBuilder.dir/src/Tail.cpp.o: src/Tail.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/f85/msnelsen/CS420/StarWars/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/shipBuilder.dir/src/Tail.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/shipBuilder.dir/src/Tail.cpp.o -c /home/f85/msnelsen/CS420/StarWars/src/Tail.cpp

CMakeFiles/shipBuilder.dir/src/Tail.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/shipBuilder.dir/src/Tail.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/f85/msnelsen/CS420/StarWars/src/Tail.cpp > CMakeFiles/shipBuilder.dir/src/Tail.cpp.i

CMakeFiles/shipBuilder.dir/src/Tail.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/shipBuilder.dir/src/Tail.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/f85/msnelsen/CS420/StarWars/src/Tail.cpp -o CMakeFiles/shipBuilder.dir/src/Tail.cpp.s

CMakeFiles/shipBuilder.dir/src/Tail.cpp.o.requires:

.PHONY : CMakeFiles/shipBuilder.dir/src/Tail.cpp.o.requires

CMakeFiles/shipBuilder.dir/src/Tail.cpp.o.provides: CMakeFiles/shipBuilder.dir/src/Tail.cpp.o.requires
	$(MAKE) -f CMakeFiles/shipBuilder.dir/build.make CMakeFiles/shipBuilder.dir/src/Tail.cpp.o.provides.build
.PHONY : CMakeFiles/shipBuilder.dir/src/Tail.cpp.o.provides

CMakeFiles/shipBuilder.dir/src/Tail.cpp.o.provides.build: CMakeFiles/shipBuilder.dir/src/Tail.cpp.o


CMakeFiles/shipBuilder.dir/bin/shipBuilder.cpp.o: CMakeFiles/shipBuilder.dir/flags.make
CMakeFiles/shipBuilder.dir/bin/shipBuilder.cpp.o: bin/shipBuilder.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/f85/msnelsen/CS420/StarWars/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/shipBuilder.dir/bin/shipBuilder.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/shipBuilder.dir/bin/shipBuilder.cpp.o -c /home/f85/msnelsen/CS420/StarWars/bin/shipBuilder.cpp

CMakeFiles/shipBuilder.dir/bin/shipBuilder.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/shipBuilder.dir/bin/shipBuilder.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/f85/msnelsen/CS420/StarWars/bin/shipBuilder.cpp > CMakeFiles/shipBuilder.dir/bin/shipBuilder.cpp.i

CMakeFiles/shipBuilder.dir/bin/shipBuilder.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/shipBuilder.dir/bin/shipBuilder.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/f85/msnelsen/CS420/StarWars/bin/shipBuilder.cpp -o CMakeFiles/shipBuilder.dir/bin/shipBuilder.cpp.s

CMakeFiles/shipBuilder.dir/bin/shipBuilder.cpp.o.requires:

.PHONY : CMakeFiles/shipBuilder.dir/bin/shipBuilder.cpp.o.requires

CMakeFiles/shipBuilder.dir/bin/shipBuilder.cpp.o.provides: CMakeFiles/shipBuilder.dir/bin/shipBuilder.cpp.o.requires
	$(MAKE) -f CMakeFiles/shipBuilder.dir/build.make CMakeFiles/shipBuilder.dir/bin/shipBuilder.cpp.o.provides.build
.PHONY : CMakeFiles/shipBuilder.dir/bin/shipBuilder.cpp.o.provides

CMakeFiles/shipBuilder.dir/bin/shipBuilder.cpp.o.provides.build: CMakeFiles/shipBuilder.dir/bin/shipBuilder.cpp.o


# Object files for target shipBuilder
shipBuilder_OBJECTS = \
"CMakeFiles/shipBuilder.dir/src/Body.cpp.o" \
"CMakeFiles/shipBuilder.dir/src/Flipper.cpp.o" \
"CMakeFiles/shipBuilder.dir/src/Menu.cpp.o" \
"CMakeFiles/shipBuilder.dir/src/Nose.cpp.o" \
"CMakeFiles/shipBuilder.dir/src/PlayerShip.cpp.o" \
"CMakeFiles/shipBuilder.dir/src/Tail.cpp.o" \
"CMakeFiles/shipBuilder.dir/bin/shipBuilder.cpp.o"

# External object files for target shipBuilder
shipBuilder_EXTERNAL_OBJECTS =

shipBuilder: CMakeFiles/shipBuilder.dir/src/Body.cpp.o
shipBuilder: CMakeFiles/shipBuilder.dir/src/Flipper.cpp.o
shipBuilder: CMakeFiles/shipBuilder.dir/src/Menu.cpp.o
shipBuilder: CMakeFiles/shipBuilder.dir/src/Nose.cpp.o
shipBuilder: CMakeFiles/shipBuilder.dir/src/PlayerShip.cpp.o
shipBuilder: CMakeFiles/shipBuilder.dir/src/Tail.cpp.o
shipBuilder: CMakeFiles/shipBuilder.dir/bin/shipBuilder.cpp.o
shipBuilder: CMakeFiles/shipBuilder.dir/build.make
shipBuilder: /home/f85/msnelsen/SFML/lib/libsfml-graphics.so
shipBuilder: /home/f85/msnelsen/SFML/lib/libsfml-window.so
shipBuilder: /home/f85/msnelsen/SFML/lib/libsfml-system.so
shipBuilder: /home/f85/msnelsen/SFML/lib/libsfml-audio.so
shipBuilder: /home/f85/msnelsen/SFML/lib/libsfml-network.so
shipBuilder: CMakeFiles/shipBuilder.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/f85/msnelsen/CS420/StarWars/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable shipBuilder"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/shipBuilder.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/shipBuilder.dir/build: shipBuilder

.PHONY : CMakeFiles/shipBuilder.dir/build

CMakeFiles/shipBuilder.dir/requires: CMakeFiles/shipBuilder.dir/src/Body.cpp.o.requires
CMakeFiles/shipBuilder.dir/requires: CMakeFiles/shipBuilder.dir/src/Flipper.cpp.o.requires
CMakeFiles/shipBuilder.dir/requires: CMakeFiles/shipBuilder.dir/src/Menu.cpp.o.requires
CMakeFiles/shipBuilder.dir/requires: CMakeFiles/shipBuilder.dir/src/Nose.cpp.o.requires
CMakeFiles/shipBuilder.dir/requires: CMakeFiles/shipBuilder.dir/src/PlayerShip.cpp.o.requires
CMakeFiles/shipBuilder.dir/requires: CMakeFiles/shipBuilder.dir/src/Tail.cpp.o.requires
CMakeFiles/shipBuilder.dir/requires: CMakeFiles/shipBuilder.dir/bin/shipBuilder.cpp.o.requires

.PHONY : CMakeFiles/shipBuilder.dir/requires

CMakeFiles/shipBuilder.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/shipBuilder.dir/cmake_clean.cmake
.PHONY : CMakeFiles/shipBuilder.dir/clean

CMakeFiles/shipBuilder.dir/depend:
	cd /home/f85/msnelsen/CS420/StarWars && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/f85/msnelsen/CS420/StarWars /home/f85/msnelsen/CS420/StarWars /home/f85/msnelsen/CS420/StarWars /home/f85/msnelsen/CS420/StarWars /home/f85/msnelsen/CS420/StarWars/CMakeFiles/shipBuilder.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/shipBuilder.dir/depend
