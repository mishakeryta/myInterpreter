# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.11

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = F:\Studying\4_term\MPZ\Interpreter\myInterpreter\project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = F:\Studying\4_term\MPZ\Interpreter\myInterpreter\build-project-Qt_5_12_2_MinGW_64_bit-Default

# Include any dependencies generated for this target.
include src/grammar/CMakeFiles/LibGrammar.dir/depend.make

# Include the progress variables for this target.
include src/grammar/CMakeFiles/LibGrammar.dir/progress.make

# Include the compile flags for this target's objects.
include src/grammar/CMakeFiles/LibGrammar.dir/flags.make

src/grammar/CMakeFiles/LibGrammar.dir/ExpressionGrammar.cpp.obj: src/grammar/CMakeFiles/LibGrammar.dir/flags.make
src/grammar/CMakeFiles/LibGrammar.dir/ExpressionGrammar.cpp.obj: src/grammar/CMakeFiles/LibGrammar.dir/includes_CXX.rsp
src/grammar/CMakeFiles/LibGrammar.dir/ExpressionGrammar.cpp.obj: F:/Studying/4_term/MPZ/Interpreter/myInterpreter/project/src/grammar/ExpressionGrammar.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\Studying\4_term\MPZ\Interpreter\myInterpreter\build-project-Qt_5_12_2_MinGW_64_bit-Default\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/grammar/CMakeFiles/LibGrammar.dir/ExpressionGrammar.cpp.obj"
	cd /d F:\Studying\4_term\MPZ\Interpreter\myInterpreter\build-project-Qt_5_12_2_MinGW_64_bit-Default\src\grammar && D:\qt\Tools\mingw730_64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\LibGrammar.dir\ExpressionGrammar.cpp.obj -c F:\Studying\4_term\MPZ\Interpreter\myInterpreter\project\src\grammar\ExpressionGrammar.cpp

src/grammar/CMakeFiles/LibGrammar.dir/ExpressionGrammar.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LibGrammar.dir/ExpressionGrammar.cpp.i"
	cd /d F:\Studying\4_term\MPZ\Interpreter\myInterpreter\build-project-Qt_5_12_2_MinGW_64_bit-Default\src\grammar && D:\qt\Tools\mingw730_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\Studying\4_term\MPZ\Interpreter\myInterpreter\project\src\grammar\ExpressionGrammar.cpp > CMakeFiles\LibGrammar.dir\ExpressionGrammar.cpp.i

src/grammar/CMakeFiles/LibGrammar.dir/ExpressionGrammar.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LibGrammar.dir/ExpressionGrammar.cpp.s"
	cd /d F:\Studying\4_term\MPZ\Interpreter\myInterpreter\build-project-Qt_5_12_2_MinGW_64_bit-Default\src\grammar && D:\qt\Tools\mingw730_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\Studying\4_term\MPZ\Interpreter\myInterpreter\project\src\grammar\ExpressionGrammar.cpp -o CMakeFiles\LibGrammar.dir\ExpressionGrammar.cpp.s

src/grammar/CMakeFiles/LibGrammar.dir/LiteralGrammar.cpp.obj: src/grammar/CMakeFiles/LibGrammar.dir/flags.make
src/grammar/CMakeFiles/LibGrammar.dir/LiteralGrammar.cpp.obj: src/grammar/CMakeFiles/LibGrammar.dir/includes_CXX.rsp
src/grammar/CMakeFiles/LibGrammar.dir/LiteralGrammar.cpp.obj: F:/Studying/4_term/MPZ/Interpreter/myInterpreter/project/src/grammar/LiteralGrammar.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\Studying\4_term\MPZ\Interpreter\myInterpreter\build-project-Qt_5_12_2_MinGW_64_bit-Default\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/grammar/CMakeFiles/LibGrammar.dir/LiteralGrammar.cpp.obj"
	cd /d F:\Studying\4_term\MPZ\Interpreter\myInterpreter\build-project-Qt_5_12_2_MinGW_64_bit-Default\src\grammar && D:\qt\Tools\mingw730_64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\LibGrammar.dir\LiteralGrammar.cpp.obj -c F:\Studying\4_term\MPZ\Interpreter\myInterpreter\project\src\grammar\LiteralGrammar.cpp

src/grammar/CMakeFiles/LibGrammar.dir/LiteralGrammar.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LibGrammar.dir/LiteralGrammar.cpp.i"
	cd /d F:\Studying\4_term\MPZ\Interpreter\myInterpreter\build-project-Qt_5_12_2_MinGW_64_bit-Default\src\grammar && D:\qt\Tools\mingw730_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\Studying\4_term\MPZ\Interpreter\myInterpreter\project\src\grammar\LiteralGrammar.cpp > CMakeFiles\LibGrammar.dir\LiteralGrammar.cpp.i

src/grammar/CMakeFiles/LibGrammar.dir/LiteralGrammar.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LibGrammar.dir/LiteralGrammar.cpp.s"
	cd /d F:\Studying\4_term\MPZ\Interpreter\myInterpreter\build-project-Qt_5_12_2_MinGW_64_bit-Default\src\grammar && D:\qt\Tools\mingw730_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\Studying\4_term\MPZ\Interpreter\myInterpreter\project\src\grammar\LiteralGrammar.cpp -o CMakeFiles\LibGrammar.dir\LiteralGrammar.cpp.s

src/grammar/CMakeFiles/LibGrammar.dir/StatementGrammar.cpp.obj: src/grammar/CMakeFiles/LibGrammar.dir/flags.make
src/grammar/CMakeFiles/LibGrammar.dir/StatementGrammar.cpp.obj: src/grammar/CMakeFiles/LibGrammar.dir/includes_CXX.rsp
src/grammar/CMakeFiles/LibGrammar.dir/StatementGrammar.cpp.obj: F:/Studying/4_term/MPZ/Interpreter/myInterpreter/project/src/grammar/StatementGrammar.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\Studying\4_term\MPZ\Interpreter\myInterpreter\build-project-Qt_5_12_2_MinGW_64_bit-Default\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/grammar/CMakeFiles/LibGrammar.dir/StatementGrammar.cpp.obj"
	cd /d F:\Studying\4_term\MPZ\Interpreter\myInterpreter\build-project-Qt_5_12_2_MinGW_64_bit-Default\src\grammar && D:\qt\Tools\mingw730_64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\LibGrammar.dir\StatementGrammar.cpp.obj -c F:\Studying\4_term\MPZ\Interpreter\myInterpreter\project\src\grammar\StatementGrammar.cpp

src/grammar/CMakeFiles/LibGrammar.dir/StatementGrammar.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LibGrammar.dir/StatementGrammar.cpp.i"
	cd /d F:\Studying\4_term\MPZ\Interpreter\myInterpreter\build-project-Qt_5_12_2_MinGW_64_bit-Default\src\grammar && D:\qt\Tools\mingw730_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\Studying\4_term\MPZ\Interpreter\myInterpreter\project\src\grammar\StatementGrammar.cpp > CMakeFiles\LibGrammar.dir\StatementGrammar.cpp.i

src/grammar/CMakeFiles/LibGrammar.dir/StatementGrammar.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LibGrammar.dir/StatementGrammar.cpp.s"
	cd /d F:\Studying\4_term\MPZ\Interpreter\myInterpreter\build-project-Qt_5_12_2_MinGW_64_bit-Default\src\grammar && D:\qt\Tools\mingw730_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\Studying\4_term\MPZ\Interpreter\myInterpreter\project\src\grammar\StatementGrammar.cpp -o CMakeFiles\LibGrammar.dir\StatementGrammar.cpp.s

# Object files for target LibGrammar
LibGrammar_OBJECTS = \
"CMakeFiles/LibGrammar.dir/ExpressionGrammar.cpp.obj" \
"CMakeFiles/LibGrammar.dir/LiteralGrammar.cpp.obj" \
"CMakeFiles/LibGrammar.dir/StatementGrammar.cpp.obj"

# External object files for target LibGrammar
LibGrammar_EXTERNAL_OBJECTS =

src/grammar/libLibGrammar.a: src/grammar/CMakeFiles/LibGrammar.dir/ExpressionGrammar.cpp.obj
src/grammar/libLibGrammar.a: src/grammar/CMakeFiles/LibGrammar.dir/LiteralGrammar.cpp.obj
src/grammar/libLibGrammar.a: src/grammar/CMakeFiles/LibGrammar.dir/StatementGrammar.cpp.obj
src/grammar/libLibGrammar.a: src/grammar/CMakeFiles/LibGrammar.dir/build.make
src/grammar/libLibGrammar.a: src/grammar/CMakeFiles/LibGrammar.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=F:\Studying\4_term\MPZ\Interpreter\myInterpreter\build-project-Qt_5_12_2_MinGW_64_bit-Default\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library libLibGrammar.a"
	cd /d F:\Studying\4_term\MPZ\Interpreter\myInterpreter\build-project-Qt_5_12_2_MinGW_64_bit-Default\src\grammar && $(CMAKE_COMMAND) -P CMakeFiles\LibGrammar.dir\cmake_clean_target.cmake
	cd /d F:\Studying\4_term\MPZ\Interpreter\myInterpreter\build-project-Qt_5_12_2_MinGW_64_bit-Default\src\grammar && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\LibGrammar.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/grammar/CMakeFiles/LibGrammar.dir/build: src/grammar/libLibGrammar.a

.PHONY : src/grammar/CMakeFiles/LibGrammar.dir/build

src/grammar/CMakeFiles/LibGrammar.dir/clean:
	cd /d F:\Studying\4_term\MPZ\Interpreter\myInterpreter\build-project-Qt_5_12_2_MinGW_64_bit-Default\src\grammar && $(CMAKE_COMMAND) -P CMakeFiles\LibGrammar.dir\cmake_clean.cmake
.PHONY : src/grammar/CMakeFiles/LibGrammar.dir/clean

src/grammar/CMakeFiles/LibGrammar.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" F:\Studying\4_term\MPZ\Interpreter\myInterpreter\project F:\Studying\4_term\MPZ\Interpreter\myInterpreter\project\src\grammar F:\Studying\4_term\MPZ\Interpreter\myInterpreter\build-project-Qt_5_12_2_MinGW_64_bit-Default F:\Studying\4_term\MPZ\Interpreter\myInterpreter\build-project-Qt_5_12_2_MinGW_64_bit-Default\src\grammar F:\Studying\4_term\MPZ\Interpreter\myInterpreter\build-project-Qt_5_12_2_MinGW_64_bit-Default\src\grammar\CMakeFiles\LibGrammar.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : src/grammar/CMakeFiles/LibGrammar.dir/depend

