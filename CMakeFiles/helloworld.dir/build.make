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
include CMakeFiles/helloworld.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/helloworld.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/helloworld.dir/flags.make

CMakeFiles/helloworld.dir/src/PlayerShip.cpp.o: CMakeFiles/helloworld.dir/flags.make
CMakeFiles/helloworld.dir/src/PlayerShip.cpp.o: src/PlayerShip.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/f85/msnelsen/CS420/StarWars/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/helloworld.dir/src/PlayerShip.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/helloworld.dir/src/PlayerShip.cpp.o -c /home/f85/msnelsen/CS420/StarWars/src/PlayerShip.cpp

CMakeFiles/helloworld.dir/src/PlayerShip.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/helloworld.dir/src/PlayerShip.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/f85/msnelsen/CS420/StarWars/src/PlayerShip.cpp > CMakeFiles/helloworld.dir/src/PlayerShip.cpp.i

CMakeFiles/helloworld.dir/src/PlayerShip.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/helloworld.dir/src/PlayerShip.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/f85/msnelsen/CS420/StarWars/src/PlayerShip.cpp -o CMakeFiles/helloworld.dir/src/PlayerShip.cpp.s

CMakeFiles/helloworld.dir/src/PlayerShip.cpp.o.requires:

.PHONY : CMakeFiles/helloworld.dir/src/PlayerShip.cpp.o.requires

CMakeFiles/helloworld.dir/src/PlayerShip.cpp.o.provides: CMakeFiles/helloworld.dir/src/PlayerShip.cpp.o.requires
	$(MAKE) -f CMakeFiles/helloworld.dir/build.make CMakeFiles/helloworld.dir/src/PlayerShip.cpp.o.provides.build
.PHONY : CMakeFiles/helloworld.dir/src/PlayerShip.cpp.o.provides

CMakeFiles/helloworld.dir/src/PlayerShip.cpp.o.provides.build: CMakeFiles/helloworld.dir/src/PlayerShip.cpp.o


CMakeFiles/helloworld.dir/src/Body.cpp.o: CMakeFiles/helloworld.dir/flags.make
CMakeFiles/helloworld.dir/src/Body.cpp.o: src/Body.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/f85/msnelsen/CS420/StarWars/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/helloworld.dir/src/Body.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/helloworld.dir/src/Body.cpp.o -c /home/f85/msnelsen/CS420/StarWars/src/Body.cpp

CMakeFiles/helloworld.dir/src/Body.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/helloworld.dir/src/Body.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/f85/msnelsen/CS420/StarWars/src/Body.cpp > CMakeFiles/helloworld.dir/src/Body.cpp.i

CMakeFiles/helloworld.dir/src/Body.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/helloworld.dir/src/Body.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/f85/msnelsen/CS420/StarWars/src/Body.cpp -o CMakeFiles/helloworld.dir/src/Body.cpp.s

CMakeFiles/helloworld.dir/src/Body.cpp.o.requires:

.PHONY : CMakeFiles/helloworld.dir/src/Body.cpp.o.requires

CMakeFiles/helloworld.dir/src/Body.cpp.o.provides: CMakeFiles/helloworld.dir/src/Body.cpp.o.requires
	$(MAKE) -f CMakeFiles/helloworld.dir/build.make CMakeFiles/helloworld.dir/src/Body.cpp.o.provides.build
.PHONY : CMakeFiles/helloworld.dir/src/Body.cpp.o.provides

CMakeFiles/helloworld.dir/src/Body.cpp.o.provides.build: CMakeFiles/helloworld.dir/src/Body.cpp.o


CMakeFiles/helloworld.dir/src/Flipper.cpp.o: CMakeFiles/helloworld.dir/flags.make
CMakeFiles/helloworld.dir/src/Flipper.cpp.o: src/Flipper.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/f85/msnelsen/CS420/StarWars/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/helloworld.dir/src/Flipper.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/helloworld.dir/src/Flipper.cpp.o -c /home/f85/msnelsen/CS420/StarWars/src/Flipper.cpp

CMakeFiles/helloworld.dir/src/Flipper.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/helloworld.dir/src/Flipper.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/f85/msnelsen/CS420/StarWars/src/Flipper.cpp > CMakeFiles/helloworld.dir/src/Flipper.cpp.i

CMakeFiles/helloworld.dir/src/Flipper.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/helloworld.dir/src/Flipper.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/f85/msnelsen/CS420/StarWars/src/Flipper.cpp -o CMakeFiles/helloworld.dir/src/Flipper.cpp.s

CMakeFiles/helloworld.dir/src/Flipper.cpp.o.requires:

.PHONY : CMakeFiles/helloworld.dir/src/Flipper.cpp.o.requires

CMakeFiles/helloworld.dir/src/Flipper.cpp.o.provides: CMakeFiles/helloworld.dir/src/Flipper.cpp.o.requires
	$(MAKE) -f CMakeFiles/helloworld.dir/build.make CMakeFiles/helloworld.dir/src/Flipper.cpp.o.provides.build
.PHONY : CMakeFiles/helloworld.dir/src/Flipper.cpp.o.provides

CMakeFiles/helloworld.dir/src/Flipper.cpp.o.provides.build: CMakeFiles/helloworld.dir/src/Flipper.cpp.o


CMakeFiles/helloworld.dir/src/Menu.cpp.o: CMakeFiles/helloworld.dir/flags.make
CMakeFiles/helloworld.dir/src/Menu.cpp.o: src/Menu.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/f85/msnelsen/CS420/StarWars/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/helloworld.dir/src/Menu.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/helloworld.dir/src/Menu.cpp.o -c /home/f85/msnelsen/CS420/StarWars/src/Menu.cpp

CMakeFiles/helloworld.dir/src/Menu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/helloworld.dir/src/Menu.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/f85/msnelsen/CS420/StarWars/src/Menu.cpp > CMakeFiles/helloworld.dir/src/Menu.cpp.i

CMakeFiles/helloworld.dir/src/Menu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/helloworld.dir/src/Menu.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/f85/msnelsen/CS420/StarWars/src/Menu.cpp -o CMakeFiles/helloworld.dir/src/Menu.cpp.s

CMakeFiles/helloworld.dir/src/Menu.cpp.o.requires:

.PHONY : CMakeFiles/helloworld.dir/src/Menu.cpp.o.requires

CMakeFiles/helloworld.dir/src/Menu.cpp.o.provides: CMakeFiles/helloworld.dir/src/Menu.cpp.o.requires
	$(MAKE) -f CMakeFiles/helloworld.dir/build.make CMakeFiles/helloworld.dir/src/Menu.cpp.o.provides.build
.PHONY : CMakeFiles/helloworld.dir/src/Menu.cpp.o.provides

CMakeFiles/helloworld.dir/src/Menu.cpp.o.provides.build: CMakeFiles/helloworld.dir/src/Menu.cpp.o


CMakeFiles/helloworld.dir/src/Nose.cpp.o: CMakeFiles/helloworld.dir/flags.make
CMakeFiles/helloworld.dir/src/Nose.cpp.o: src/Nose.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/f85/msnelsen/CS420/StarWars/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/helloworld.dir/src/Nose.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/helloworld.dir/src/Nose.cpp.o -c /home/f85/msnelsen/CS420/StarWars/src/Nose.cpp

CMakeFiles/helloworld.dir/src/Nose.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/helloworld.dir/src/Nose.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/f85/msnelsen/CS420/StarWars/src/Nose.cpp > CMakeFiles/helloworld.dir/src/Nose.cpp.i

CMakeFiles/helloworld.dir/src/Nose.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/helloworld.dir/src/Nose.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/f85/msnelsen/CS420/StarWars/src/Nose.cpp -o CMakeFiles/helloworld.dir/src/Nose.cpp.s

CMakeFiles/helloworld.dir/src/Nose.cpp.o.requires:

.PHONY : CMakeFiles/helloworld.dir/src/Nose.cpp.o.requires

CMakeFiles/helloworld.dir/src/Nose.cpp.o.provides: CMakeFiles/helloworld.dir/src/Nose.cpp.o.requires
	$(MAKE) -f CMakeFiles/helloworld.dir/build.make CMakeFiles/helloworld.dir/src/Nose.cpp.o.provides.build
.PHONY : CMakeFiles/helloworld.dir/src/Nose.cpp.o.provides

CMakeFiles/helloworld.dir/src/Nose.cpp.o.provides.build: CMakeFiles/helloworld.dir/src/Nose.cpp.o


CMakeFiles/helloworld.dir/src/Tail.cpp.o: CMakeFiles/helloworld.dir/flags.make
CMakeFiles/helloworld.dir/src/Tail.cpp.o: src/Tail.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/f85/msnelsen/CS420/StarWars/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/helloworld.dir/src/Tail.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/helloworld.dir/src/Tail.cpp.o -c /home/f85/msnelsen/CS420/StarWars/src/Tail.cpp

CMakeFiles/helloworld.dir/src/Tail.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/helloworld.dir/src/Tail.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/f85/msnelsen/CS420/StarWars/src/Tail.cpp > CMakeFiles/helloworld.dir/src/Tail.cpp.i

CMakeFiles/helloworld.dir/src/Tail.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/helloworld.dir/src/Tail.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/f85/msnelsen/CS420/StarWars/src/Tail.cpp -o CMakeFiles/helloworld.dir/src/Tail.cpp.s

CMakeFiles/helloworld.dir/src/Tail.cpp.o.requires:

.PHONY : CMakeFiles/helloworld.dir/src/Tail.cpp.o.requires

CMakeFiles/helloworld.dir/src/Tail.cpp.o.provides: CMakeFiles/helloworld.dir/src/Tail.cpp.o.requires
	$(MAKE) -f CMakeFiles/helloworld.dir/build.make CMakeFiles/helloworld.dir/src/Tail.cpp.o.provides.build
.PHONY : CMakeFiles/helloworld.dir/src/Tail.cpp.o.provides

CMakeFiles/helloworld.dir/src/Tail.cpp.o.provides.build: CMakeFiles/helloworld.dir/src/Tail.cpp.o


CMakeFiles/helloworld.dir/bin/helloworld.cpp.o: CMakeFiles/helloworld.dir/flags.make
CMakeFiles/helloworld.dir/bin/helloworld.cpp.o: bin/helloworld.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/f85/msnelsen/CS420/StarWars/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/helloworld.dir/bin/helloworld.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/helloworld.dir/bin/helloworld.cpp.o -c /home/f85/msnelsen/CS420/StarWars/bin/helloworld.cpp

CMakeFiles/helloworld.dir/bin/helloworld.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/helloworld.dir/bin/helloworld.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/f85/msnelsen/CS420/StarWars/bin/helloworld.cpp > CMakeFiles/helloworld.dir/bin/helloworld.cpp.i

CMakeFiles/helloworld.dir/bin/helloworld.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/helloworld.dir/bin/helloworld.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/f85/msnelsen/CS420/StarWars/bin/helloworld.cpp -o CMakeFiles/helloworld.dir/bin/helloworld.cpp.s

CMakeFiles/helloworld.dir/bin/helloworld.cpp.o.requires:

.PHONY : CMakeFiles/helloworld.dir/bin/helloworld.cpp.o.requires

CMakeFiles/helloworld.dir/bin/helloworld.cpp.o.provides: CMakeFiles/helloworld.dir/bin/helloworld.cpp.o.requires
	$(MAKE) -f CMakeFiles/helloworld.dir/build.make CMakeFiles/helloworld.dir/bin/helloworld.cpp.o.provides.build
.PHONY : CMakeFiles/helloworld.dir/bin/helloworld.cpp.o.provides

CMakeFiles/helloworld.dir/bin/helloworld.cpp.o.provides.build: CMakeFiles/helloworld.dir/bin/helloworld.cpp.o


# Object files for target helloworld
helloworld_OBJECTS = \
"CMakeFiles/helloworld.dir/src/PlayerShip.cpp.o" \
"CMakeFiles/helloworld.dir/src/Body.cpp.o" \
"CMakeFiles/helloworld.dir/src/Flipper.cpp.o" \
"CMakeFiles/helloworld.dir/src/Menu.cpp.o" \
"CMakeFiles/helloworld.dir/src/Nose.cpp.o" \
"CMakeFiles/helloworld.dir/src/Tail.cpp.o" \
"CMakeFiles/helloworld.dir/bin/helloworld.cpp.o"

# External object files for target helloworld
helloworld_EXTERNAL_OBJECTS =

helloworld: CMakeFiles/helloworld.dir/src/PlayerShip.cpp.o
helloworld: CMakeFiles/helloworld.dir/src/Body.cpp.o
helloworld: CMakeFiles/helloworld.dir/src/Flipper.cpp.o
helloworld: CMakeFiles/helloworld.dir/src/Menu.cpp.o
helloworld: CMakeFiles/helloworld.dir/src/Nose.cpp.o
helloworld: CMakeFiles/helloworld.dir/src/Tail.cpp.o
helloworld: CMakeFiles/helloworld.dir/bin/helloworld.cpp.o
helloworld: CMakeFiles/helloworld.dir/build.make
helloworld: /home/f85/msnelsen/SFML/lib/libsfml-graphics.so
helloworld: /home/f85/msnelsen/SFML/lib/libsfml-window.so
helloworld: /home/f85/msnelsen/SFML/lib/libsfml-system.so
helloworld: /home/f85/msnelsen/SFML/lib/libsfml-audio.so
helloworld: /home/f85/msnelsen/SFML/lib/libsfml-network.so
helloworld: CMakeFiles/helloworld.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/f85/msnelsen/CS420/StarWars/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable helloworld"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/helloworld.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/helloworld.dir/build: helloworld

.PHONY : CMakeFiles/helloworld.dir/build

CMakeFiles/helloworld.dir/requires: CMakeFiles/helloworld.dir/src/PlayerShip.cpp.o.requires
CMakeFiles/helloworld.dir/requires: CMakeFiles/helloworld.dir/src/Body.cpp.o.requires
CMakeFiles/helloworld.dir/requires: CMakeFiles/helloworld.dir/src/Flipper.cpp.o.requires
CMakeFiles/helloworld.dir/requires: CMakeFiles/helloworld.dir/src/Menu.cpp.o.requires
CMakeFiles/helloworld.dir/requires: CMakeFiles/helloworld.dir/src/Nose.cpp.o.requires
CMakeFiles/helloworld.dir/requires: CMakeFiles/helloworld.dir/src/Tail.cpp.o.requires
CMakeFiles/helloworld.dir/requires: CMakeFiles/helloworld.dir/bin/helloworld.cpp.o.requires

.PHONY : CMakeFiles/helloworld.dir/requires

CMakeFiles/helloworld.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/helloworld.dir/cmake_clean.cmake
.PHONY : CMakeFiles/helloworld.dir/clean

CMakeFiles/helloworld.dir/depend:
	cd /home/f85/msnelsen/CS420/StarWars && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/f85/msnelsen/CS420/StarWars /home/f85/msnelsen/CS420/StarWars /home/f85/msnelsen/CS420/StarWars /home/f85/msnelsen/CS420/StarWars /home/f85/msnelsen/CS420/StarWars/CMakeFiles/helloworld.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/helloworld.dir/depend

