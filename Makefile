# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/amin/Desktop/UT/term2/ap/project/phase2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/amin/Desktop/UT/term2/ap/project/phase2

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/amin/Desktop/UT/term2/ap/project/phase2/CMakeFiles /home/amin/Desktop/UT/term2/ap/project/phase2/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/amin/Desktop/UT/term2/ap/project/phase2/CMakeFiles 0
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
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named myChess

# Build rule for target.
myChess: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 myChess
.PHONY : myChess

# fast build rule for target.
myChess/fast:
	$(MAKE) -f CMakeFiles/myChess.dir/build.make CMakeFiles/myChess.dir/build
.PHONY : myChess/fast

src/Board.o: src/Board.cpp.o

.PHONY : src/Board.o

# target to build an object file
src/Board.cpp.o:
	$(MAKE) -f CMakeFiles/myChess.dir/build.make CMakeFiles/myChess.dir/src/Board.cpp.o
.PHONY : src/Board.cpp.o

src/Board.i: src/Board.cpp.i

.PHONY : src/Board.i

# target to preprocess a source file
src/Board.cpp.i:
	$(MAKE) -f CMakeFiles/myChess.dir/build.make CMakeFiles/myChess.dir/src/Board.cpp.i
.PHONY : src/Board.cpp.i

src/Board.s: src/Board.cpp.s

.PHONY : src/Board.s

# target to generate assembly for a file
src/Board.cpp.s:
	$(MAKE) -f CMakeFiles/myChess.dir/build.make CMakeFiles/myChess.dir/src/Board.cpp.s
.PHONY : src/Board.cpp.s

src/Helper.o: src/Helper.cpp.o

.PHONY : src/Helper.o

# target to build an object file
src/Helper.cpp.o:
	$(MAKE) -f CMakeFiles/myChess.dir/build.make CMakeFiles/myChess.dir/src/Helper.cpp.o
.PHONY : src/Helper.cpp.o

src/Helper.i: src/Helper.cpp.i

.PHONY : src/Helper.i

# target to preprocess a source file
src/Helper.cpp.i:
	$(MAKE) -f CMakeFiles/myChess.dir/build.make CMakeFiles/myChess.dir/src/Helper.cpp.i
.PHONY : src/Helper.cpp.i

src/Helper.s: src/Helper.cpp.s

.PHONY : src/Helper.s

# target to generate assembly for a file
src/Helper.cpp.s:
	$(MAKE) -f CMakeFiles/myChess.dir/build.make CMakeFiles/myChess.dir/src/Helper.cpp.s
.PHONY : src/Helper.cpp.s

src/ParentPiece.o: src/ParentPiece.cpp.o

.PHONY : src/ParentPiece.o

# target to build an object file
src/ParentPiece.cpp.o:
	$(MAKE) -f CMakeFiles/myChess.dir/build.make CMakeFiles/myChess.dir/src/ParentPiece.cpp.o
.PHONY : src/ParentPiece.cpp.o

src/ParentPiece.i: src/ParentPiece.cpp.i

.PHONY : src/ParentPiece.i

# target to preprocess a source file
src/ParentPiece.cpp.i:
	$(MAKE) -f CMakeFiles/myChess.dir/build.make CMakeFiles/myChess.dir/src/ParentPiece.cpp.i
.PHONY : src/ParentPiece.cpp.i

src/ParentPiece.s: src/ParentPiece.cpp.s

.PHONY : src/ParentPiece.s

# target to generate assembly for a file
src/ParentPiece.cpp.s:
	$(MAKE) -f CMakeFiles/myChess.dir/build.make CMakeFiles/myChess.dir/src/ParentPiece.cpp.s
.PHONY : src/ParentPiece.cpp.s

src/Pieces.o: src/Pieces.cpp.o

.PHONY : src/Pieces.o

# target to build an object file
src/Pieces.cpp.o:
	$(MAKE) -f CMakeFiles/myChess.dir/build.make CMakeFiles/myChess.dir/src/Pieces.cpp.o
.PHONY : src/Pieces.cpp.o

src/Pieces.i: src/Pieces.cpp.i

.PHONY : src/Pieces.i

# target to preprocess a source file
src/Pieces.cpp.i:
	$(MAKE) -f CMakeFiles/myChess.dir/build.make CMakeFiles/myChess.dir/src/Pieces.cpp.i
.PHONY : src/Pieces.cpp.i

src/Pieces.s: src/Pieces.cpp.s

.PHONY : src/Pieces.s

# target to generate assembly for a file
src/Pieces.cpp.s:
	$(MAKE) -f CMakeFiles/myChess.dir/build.make CMakeFiles/myChess.dir/src/Pieces.cpp.s
.PHONY : src/Pieces.cpp.s

src/main.o: src/main.cpp.o

.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) -f CMakeFiles/myChess.dir/build.make CMakeFiles/myChess.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i

.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) -f CMakeFiles/myChess.dir/build.make CMakeFiles/myChess.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s

.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) -f CMakeFiles/myChess.dir/build.make CMakeFiles/myChess.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... myChess"
	@echo "... src/Board.o"
	@echo "... src/Board.i"
	@echo "... src/Board.s"
	@echo "... src/Helper.o"
	@echo "... src/Helper.i"
	@echo "... src/Helper.s"
	@echo "... src/ParentPiece.o"
	@echo "... src/ParentPiece.i"
	@echo "... src/ParentPiece.s"
	@echo "... src/Pieces.o"
	@echo "... src/Pieces.i"
	@echo "... src/Pieces.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system
