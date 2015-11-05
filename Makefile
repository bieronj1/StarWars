# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.3

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/ccmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/f85/msnelsen/CS420/StarWars/CMakeFiles /home/f85/msnelsen/CS420/StarWars/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/f85/msnelsen/CS420/StarWars/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named astroloot

# Build rule for target.
astroloot: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 astroloot
.PHONY : astroloot

# fast build rule for target.
astroloot/fast:
	$(MAKE) -f CMakeFiles/astroloot.dir/build.make CMakeFiles/astroloot.dir/build
.PHONY : astroloot/fast

#=============================================================================
# Target rules for targets named sandbox

# Build rule for target.
sandbox: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 sandbox
.PHONY : sandbox

# fast build rule for target.
sandbox/fast:
	$(MAKE) -f CMakeFiles/sandbox.dir/build.make CMakeFiles/sandbox.dir/build
.PHONY : sandbox/fast

#=============================================================================
# Target rules for targets named shipBuilder

# Build rule for target.
shipBuilder: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 shipBuilder
.PHONY : shipBuilder

# fast build rule for target.
shipBuilder/fast:
	$(MAKE) -f CMakeFiles/shipBuilder.dir/build.make CMakeFiles/shipBuilder.dir/build
.PHONY : shipBuilder/fast

bin/astroloot.o: bin/astroloot.cpp.o

.PHONY : bin/astroloot.o

# target to build an object file
bin/astroloot.cpp.o:
	$(MAKE) -f CMakeFiles/astroloot.dir/build.make CMakeFiles/astroloot.dir/bin/astroloot.cpp.o
.PHONY : bin/astroloot.cpp.o

bin/astroloot.i: bin/astroloot.cpp.i

.PHONY : bin/astroloot.i

# target to preprocess a source file
bin/astroloot.cpp.i:
	$(MAKE) -f CMakeFiles/astroloot.dir/build.make CMakeFiles/astroloot.dir/bin/astroloot.cpp.i
.PHONY : bin/astroloot.cpp.i

bin/astroloot.s: bin/astroloot.cpp.s

.PHONY : bin/astroloot.s

# target to generate assembly for a file
bin/astroloot.cpp.s:
	$(MAKE) -f CMakeFiles/astroloot.dir/build.make CMakeFiles/astroloot.dir/bin/astroloot.cpp.s
.PHONY : bin/astroloot.cpp.s

bin/sandbox.o: bin/sandbox.cpp.o

.PHONY : bin/sandbox.o

# target to build an object file
bin/sandbox.cpp.o:
	$(MAKE) -f CMakeFiles/sandbox.dir/build.make CMakeFiles/sandbox.dir/bin/sandbox.cpp.o
.PHONY : bin/sandbox.cpp.o

bin/sandbox.i: bin/sandbox.cpp.i

.PHONY : bin/sandbox.i

# target to preprocess a source file
bin/sandbox.cpp.i:
	$(MAKE) -f CMakeFiles/sandbox.dir/build.make CMakeFiles/sandbox.dir/bin/sandbox.cpp.i
.PHONY : bin/sandbox.cpp.i

bin/sandbox.s: bin/sandbox.cpp.s

.PHONY : bin/sandbox.s

# target to generate assembly for a file
bin/sandbox.cpp.s:
	$(MAKE) -f CMakeFiles/sandbox.dir/build.make CMakeFiles/sandbox.dir/bin/sandbox.cpp.s
.PHONY : bin/sandbox.cpp.s

bin/shipBuilder.o: bin/shipBuilder.cpp.o

.PHONY : bin/shipBuilder.o

# target to build an object file
bin/shipBuilder.cpp.o:
	$(MAKE) -f CMakeFiles/shipBuilder.dir/build.make CMakeFiles/shipBuilder.dir/bin/shipBuilder.cpp.o
.PHONY : bin/shipBuilder.cpp.o

bin/shipBuilder.i: bin/shipBuilder.cpp.i

.PHONY : bin/shipBuilder.i

# target to preprocess a source file
bin/shipBuilder.cpp.i:
	$(MAKE) -f CMakeFiles/shipBuilder.dir/build.make CMakeFiles/shipBuilder.dir/bin/shipBuilder.cpp.i
.PHONY : bin/shipBuilder.cpp.i

bin/shipBuilder.s: bin/shipBuilder.cpp.s

.PHONY : bin/shipBuilder.s

# target to generate assembly for a file
bin/shipBuilder.cpp.s:
	$(MAKE) -f CMakeFiles/shipBuilder.dir/build.make CMakeFiles/shipBuilder.dir/bin/shipBuilder.cpp.s
.PHONY : bin/shipBuilder.cpp.s

src/Body.o: src/Body.cpp.o

.PHONY : src/Body.o

# target to build an object file
src/Body.cpp.o:
	$(MAKE) -f CMakeFiles/astroloot.dir/build.make CMakeFiles/astroloot.dir/src/Body.cpp.o
	$(MAKE) -f CMakeFiles/sandbox.dir/build.make CMakeFiles/sandbox.dir/src/Body.cpp.o
	$(MAKE) -f CMakeFiles/shipBuilder.dir/build.make CMakeFiles/shipBuilder.dir/src/Body.cpp.o
.PHONY : src/Body.cpp.o

src/Body.i: src/Body.cpp.i

.PHONY : src/Body.i

# target to preprocess a source file
src/Body.cpp.i:
	$(MAKE) -f CMakeFiles/astroloot.dir/build.make CMakeFiles/astroloot.dir/src/Body.cpp.i
	$(MAKE) -f CMakeFiles/sandbox.dir/build.make CMakeFiles/sandbox.dir/src/Body.cpp.i
	$(MAKE) -f CMakeFiles/shipBuilder.dir/build.make CMakeFiles/shipBuilder.dir/src/Body.cpp.i
.PHONY : src/Body.cpp.i

src/Body.s: src/Body.cpp.s

.PHONY : src/Body.s

# target to generate assembly for a file
src/Body.cpp.s:
	$(MAKE) -f CMakeFiles/astroloot.dir/build.make CMakeFiles/astroloot.dir/src/Body.cpp.s
	$(MAKE) -f CMakeFiles/sandbox.dir/build.make CMakeFiles/sandbox.dir/src/Body.cpp.s
	$(MAKE) -f CMakeFiles/shipBuilder.dir/build.make CMakeFiles/shipBuilder.dir/src/Body.cpp.s
.PHONY : src/Body.cpp.s

src/Flipper.o: src/Flipper.cpp.o

.PHONY : src/Flipper.o

# target to build an object file
src/Flipper.cpp.o:
	$(MAKE) -f CMakeFiles/astroloot.dir/build.make CMakeFiles/astroloot.dir/src/Flipper.cpp.o
	$(MAKE) -f CMakeFiles/sandbox.dir/build.make CMakeFiles/sandbox.dir/src/Flipper.cpp.o
	$(MAKE) -f CMakeFiles/shipBuilder.dir/build.make CMakeFiles/shipBuilder.dir/src/Flipper.cpp.o
.PHONY : src/Flipper.cpp.o

src/Flipper.i: src/Flipper.cpp.i

.PHONY : src/Flipper.i

# target to preprocess a source file
src/Flipper.cpp.i:
	$(MAKE) -f CMakeFiles/astroloot.dir/build.make CMakeFiles/astroloot.dir/src/Flipper.cpp.i
	$(MAKE) -f CMakeFiles/sandbox.dir/build.make CMakeFiles/sandbox.dir/src/Flipper.cpp.i
	$(MAKE) -f CMakeFiles/shipBuilder.dir/build.make CMakeFiles/shipBuilder.dir/src/Flipper.cpp.i
.PHONY : src/Flipper.cpp.i

src/Flipper.s: src/Flipper.cpp.s

.PHONY : src/Flipper.s

# target to generate assembly for a file
src/Flipper.cpp.s:
	$(MAKE) -f CMakeFiles/astroloot.dir/build.make CMakeFiles/astroloot.dir/src/Flipper.cpp.s
	$(MAKE) -f CMakeFiles/sandbox.dir/build.make CMakeFiles/sandbox.dir/src/Flipper.cpp.s
	$(MAKE) -f CMakeFiles/shipBuilder.dir/build.make CMakeFiles/shipBuilder.dir/src/Flipper.cpp.s
.PHONY : src/Flipper.cpp.s

src/Menu.o: src/Menu.cpp.o

.PHONY : src/Menu.o

# target to build an object file
src/Menu.cpp.o:
	$(MAKE) -f CMakeFiles/astroloot.dir/build.make CMakeFiles/astroloot.dir/src/Menu.cpp.o
	$(MAKE) -f CMakeFiles/sandbox.dir/build.make CMakeFiles/sandbox.dir/src/Menu.cpp.o
	$(MAKE) -f CMakeFiles/shipBuilder.dir/build.make CMakeFiles/shipBuilder.dir/src/Menu.cpp.o
.PHONY : src/Menu.cpp.o

src/Menu.i: src/Menu.cpp.i

.PHONY : src/Menu.i

# target to preprocess a source file
src/Menu.cpp.i:
	$(MAKE) -f CMakeFiles/astroloot.dir/build.make CMakeFiles/astroloot.dir/src/Menu.cpp.i
	$(MAKE) -f CMakeFiles/sandbox.dir/build.make CMakeFiles/sandbox.dir/src/Menu.cpp.i
	$(MAKE) -f CMakeFiles/shipBuilder.dir/build.make CMakeFiles/shipBuilder.dir/src/Menu.cpp.i
.PHONY : src/Menu.cpp.i

src/Menu.s: src/Menu.cpp.s

.PHONY : src/Menu.s

# target to generate assembly for a file
src/Menu.cpp.s:
	$(MAKE) -f CMakeFiles/astroloot.dir/build.make CMakeFiles/astroloot.dir/src/Menu.cpp.s
	$(MAKE) -f CMakeFiles/sandbox.dir/build.make CMakeFiles/sandbox.dir/src/Menu.cpp.s
	$(MAKE) -f CMakeFiles/shipBuilder.dir/build.make CMakeFiles/shipBuilder.dir/src/Menu.cpp.s
.PHONY : src/Menu.cpp.s

src/Nose.o: src/Nose.cpp.o

.PHONY : src/Nose.o

# target to build an object file
src/Nose.cpp.o:
	$(MAKE) -f CMakeFiles/astroloot.dir/build.make CMakeFiles/astroloot.dir/src/Nose.cpp.o
	$(MAKE) -f CMakeFiles/sandbox.dir/build.make CMakeFiles/sandbox.dir/src/Nose.cpp.o
	$(MAKE) -f CMakeFiles/shipBuilder.dir/build.make CMakeFiles/shipBuilder.dir/src/Nose.cpp.o
.PHONY : src/Nose.cpp.o

src/Nose.i: src/Nose.cpp.i

.PHONY : src/Nose.i

# target to preprocess a source file
src/Nose.cpp.i:
	$(MAKE) -f CMakeFiles/astroloot.dir/build.make CMakeFiles/astroloot.dir/src/Nose.cpp.i
	$(MAKE) -f CMakeFiles/sandbox.dir/build.make CMakeFiles/sandbox.dir/src/Nose.cpp.i
	$(MAKE) -f CMakeFiles/shipBuilder.dir/build.make CMakeFiles/shipBuilder.dir/src/Nose.cpp.i
.PHONY : src/Nose.cpp.i

src/Nose.s: src/Nose.cpp.s

.PHONY : src/Nose.s

# target to generate assembly for a file
src/Nose.cpp.s:
	$(MAKE) -f CMakeFiles/astroloot.dir/build.make CMakeFiles/astroloot.dir/src/Nose.cpp.s
	$(MAKE) -f CMakeFiles/sandbox.dir/build.make CMakeFiles/sandbox.dir/src/Nose.cpp.s
	$(MAKE) -f CMakeFiles/shipBuilder.dir/build.make CMakeFiles/shipBuilder.dir/src/Nose.cpp.s
.PHONY : src/Nose.cpp.s

src/PlayerShip.o: src/PlayerShip.cpp.o

.PHONY : src/PlayerShip.o

# target to build an object file
src/PlayerShip.cpp.o:
	$(MAKE) -f CMakeFiles/astroloot.dir/build.make CMakeFiles/astroloot.dir/src/PlayerShip.cpp.o
	$(MAKE) -f CMakeFiles/sandbox.dir/build.make CMakeFiles/sandbox.dir/src/PlayerShip.cpp.o
	$(MAKE) -f CMakeFiles/shipBuilder.dir/build.make CMakeFiles/shipBuilder.dir/src/PlayerShip.cpp.o
.PHONY : src/PlayerShip.cpp.o

src/PlayerShip.i: src/PlayerShip.cpp.i

.PHONY : src/PlayerShip.i

# target to preprocess a source file
src/PlayerShip.cpp.i:
	$(MAKE) -f CMakeFiles/astroloot.dir/build.make CMakeFiles/astroloot.dir/src/PlayerShip.cpp.i
	$(MAKE) -f CMakeFiles/sandbox.dir/build.make CMakeFiles/sandbox.dir/src/PlayerShip.cpp.i
	$(MAKE) -f CMakeFiles/shipBuilder.dir/build.make CMakeFiles/shipBuilder.dir/src/PlayerShip.cpp.i
.PHONY : src/PlayerShip.cpp.i

src/PlayerShip.s: src/PlayerShip.cpp.s

.PHONY : src/PlayerShip.s

# target to generate assembly for a file
src/PlayerShip.cpp.s:
	$(MAKE) -f CMakeFiles/astroloot.dir/build.make CMakeFiles/astroloot.dir/src/PlayerShip.cpp.s
	$(MAKE) -f CMakeFiles/sandbox.dir/build.make CMakeFiles/sandbox.dir/src/PlayerShip.cpp.s
	$(MAKE) -f CMakeFiles/shipBuilder.dir/build.make CMakeFiles/shipBuilder.dir/src/PlayerShip.cpp.s
.PHONY : src/PlayerShip.cpp.s

src/Tail.o: src/Tail.cpp.o

.PHONY : src/Tail.o

# target to build an object file
src/Tail.cpp.o:
	$(MAKE) -f CMakeFiles/astroloot.dir/build.make CMakeFiles/astroloot.dir/src/Tail.cpp.o
	$(MAKE) -f CMakeFiles/sandbox.dir/build.make CMakeFiles/sandbox.dir/src/Tail.cpp.o
	$(MAKE) -f CMakeFiles/shipBuilder.dir/build.make CMakeFiles/shipBuilder.dir/src/Tail.cpp.o
.PHONY : src/Tail.cpp.o

src/Tail.i: src/Tail.cpp.i

.PHONY : src/Tail.i

# target to preprocess a source file
src/Tail.cpp.i:
	$(MAKE) -f CMakeFiles/astroloot.dir/build.make CMakeFiles/astroloot.dir/src/Tail.cpp.i
	$(MAKE) -f CMakeFiles/sandbox.dir/build.make CMakeFiles/sandbox.dir/src/Tail.cpp.i
	$(MAKE) -f CMakeFiles/shipBuilder.dir/build.make CMakeFiles/shipBuilder.dir/src/Tail.cpp.i
.PHONY : src/Tail.cpp.i

src/Tail.s: src/Tail.cpp.s

.PHONY : src/Tail.s

# target to generate assembly for a file
src/Tail.cpp.s:
	$(MAKE) -f CMakeFiles/astroloot.dir/build.make CMakeFiles/astroloot.dir/src/Tail.cpp.s
	$(MAKE) -f CMakeFiles/sandbox.dir/build.make CMakeFiles/sandbox.dir/src/Tail.cpp.s
	$(MAKE) -f CMakeFiles/shipBuilder.dir/build.make CMakeFiles/shipBuilder.dir/src/Tail.cpp.s
.PHONY : src/Tail.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... shipBuilder"
	@echo "... sandbox"
	@echo "... astroloot"
	@echo "... bin/astroloot.o"
	@echo "... bin/astroloot.i"
	@echo "... bin/astroloot.s"
	@echo "... bin/sandbox.o"
	@echo "... bin/sandbox.i"
	@echo "... bin/sandbox.s"
	@echo "... bin/shipBuilder.o"
	@echo "... bin/shipBuilder.i"
	@echo "... bin/shipBuilder.s"
	@echo "... src/Body.o"
	@echo "... src/Body.i"
	@echo "... src/Body.s"
	@echo "... src/Flipper.o"
	@echo "... src/Flipper.i"
	@echo "... src/Flipper.s"
	@echo "... src/Menu.o"
	@echo "... src/Menu.i"
	@echo "... src/Menu.s"
	@echo "... src/Nose.o"
	@echo "... src/Nose.i"
	@echo "... src/Nose.s"
	@echo "... src/PlayerShip.o"
	@echo "... src/PlayerShip.i"
	@echo "... src/PlayerShip.s"
	@echo "... src/Tail.o"
	@echo "... src/Tail.i"
	@echo "... src/Tail.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

