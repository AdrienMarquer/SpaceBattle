# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /home/adrien/Downloads/clion-2018.2.5/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/adrien/Downloads/clion-2018.2.5/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/adrien/Documents/SpaceBattle/server

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/adrien/Documents/SpaceBattle/server/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/server.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/server.dir/flags.make

CMakeFiles/server.dir/sources/BattleSpaceServer.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/sources/BattleSpaceServer.cpp.o: ../sources/BattleSpaceServer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adrien/Documents/SpaceBattle/server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/server.dir/sources/BattleSpaceServer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/sources/BattleSpaceServer.cpp.o -c /home/adrien/Documents/SpaceBattle/server/sources/BattleSpaceServer.cpp

CMakeFiles/server.dir/sources/BattleSpaceServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/sources/BattleSpaceServer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adrien/Documents/SpaceBattle/server/sources/BattleSpaceServer.cpp > CMakeFiles/server.dir/sources/BattleSpaceServer.cpp.i

CMakeFiles/server.dir/sources/BattleSpaceServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/sources/BattleSpaceServer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adrien/Documents/SpaceBattle/server/sources/BattleSpaceServer.cpp -o CMakeFiles/server.dir/sources/BattleSpaceServer.cpp.s

CMakeFiles/server.dir/sources/Client.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/sources/Client.cpp.o: ../sources/Client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adrien/Documents/SpaceBattle/server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/server.dir/sources/Client.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/sources/Client.cpp.o -c /home/adrien/Documents/SpaceBattle/server/sources/Client.cpp

CMakeFiles/server.dir/sources/Client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/sources/Client.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adrien/Documents/SpaceBattle/server/sources/Client.cpp > CMakeFiles/server.dir/sources/Client.cpp.i

CMakeFiles/server.dir/sources/Client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/sources/Client.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adrien/Documents/SpaceBattle/server/sources/Client.cpp -o CMakeFiles/server.dir/sources/Client.cpp.s

CMakeFiles/server.dir/sources/main.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/sources/main.cpp.o: ../sources/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adrien/Documents/SpaceBattle/server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/server.dir/sources/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/sources/main.cpp.o -c /home/adrien/Documents/SpaceBattle/server/sources/main.cpp

CMakeFiles/server.dir/sources/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/sources/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adrien/Documents/SpaceBattle/server/sources/main.cpp > CMakeFiles/server.dir/sources/main.cpp.i

CMakeFiles/server.dir/sources/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/sources/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adrien/Documents/SpaceBattle/server/sources/main.cpp -o CMakeFiles/server.dir/sources/main.cpp.s

CMakeFiles/server.dir/sources/TcpClient.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/sources/TcpClient.cpp.o: ../sources/TcpClient.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adrien/Documents/SpaceBattle/server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/server.dir/sources/TcpClient.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/sources/TcpClient.cpp.o -c /home/adrien/Documents/SpaceBattle/server/sources/TcpClient.cpp

CMakeFiles/server.dir/sources/TcpClient.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/sources/TcpClient.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adrien/Documents/SpaceBattle/server/sources/TcpClient.cpp > CMakeFiles/server.dir/sources/TcpClient.cpp.i

CMakeFiles/server.dir/sources/TcpClient.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/sources/TcpClient.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adrien/Documents/SpaceBattle/server/sources/TcpClient.cpp -o CMakeFiles/server.dir/sources/TcpClient.cpp.s

CMakeFiles/server.dir/sources/TcpServer.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/sources/TcpServer.cpp.o: ../sources/TcpServer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adrien/Documents/SpaceBattle/server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/server.dir/sources/TcpServer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/sources/TcpServer.cpp.o -c /home/adrien/Documents/SpaceBattle/server/sources/TcpServer.cpp

CMakeFiles/server.dir/sources/TcpServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/sources/TcpServer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adrien/Documents/SpaceBattle/server/sources/TcpServer.cpp > CMakeFiles/server.dir/sources/TcpServer.cpp.i

CMakeFiles/server.dir/sources/TcpServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/sources/TcpServer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adrien/Documents/SpaceBattle/server/sources/TcpServer.cpp -o CMakeFiles/server.dir/sources/TcpServer.cpp.s

CMakeFiles/server.dir/sources/Command/New.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/sources/Command/New.cpp.o: ../sources/Command/New.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adrien/Documents/SpaceBattle/server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/server.dir/sources/Command/New.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/sources/Command/New.cpp.o -c /home/adrien/Documents/SpaceBattle/server/sources/Command/New.cpp

CMakeFiles/server.dir/sources/Command/New.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/sources/Command/New.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adrien/Documents/SpaceBattle/server/sources/Command/New.cpp > CMakeFiles/server.dir/sources/Command/New.cpp.i

CMakeFiles/server.dir/sources/Command/New.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/sources/Command/New.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adrien/Documents/SpaceBattle/server/sources/Command/New.cpp -o CMakeFiles/server.dir/sources/Command/New.cpp.s

CMakeFiles/server.dir/sources/Command/Join.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/sources/Command/Join.cpp.o: ../sources/Command/Join.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adrien/Documents/SpaceBattle/server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/server.dir/sources/Command/Join.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/sources/Command/Join.cpp.o -c /home/adrien/Documents/SpaceBattle/server/sources/Command/Join.cpp

CMakeFiles/server.dir/sources/Command/Join.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/sources/Command/Join.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adrien/Documents/SpaceBattle/server/sources/Command/Join.cpp > CMakeFiles/server.dir/sources/Command/Join.cpp.i

CMakeFiles/server.dir/sources/Command/Join.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/sources/Command/Join.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adrien/Documents/SpaceBattle/server/sources/Command/Join.cpp -o CMakeFiles/server.dir/sources/Command/Join.cpp.s

CMakeFiles/server.dir/sources/Command/Tir.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/sources/Command/Tir.cpp.o: ../sources/Command/Tir.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adrien/Documents/SpaceBattle/server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/server.dir/sources/Command/Tir.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/sources/Command/Tir.cpp.o -c /home/adrien/Documents/SpaceBattle/server/sources/Command/Tir.cpp

CMakeFiles/server.dir/sources/Command/Tir.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/sources/Command/Tir.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adrien/Documents/SpaceBattle/server/sources/Command/Tir.cpp > CMakeFiles/server.dir/sources/Command/Tir.cpp.i

CMakeFiles/server.dir/sources/Command/Tir.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/sources/Command/Tir.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adrien/Documents/SpaceBattle/server/sources/Command/Tir.cpp -o CMakeFiles/server.dir/sources/Command/Tir.cpp.s

CMakeFiles/server.dir/sources/Command/Msg.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/sources/Command/Msg.cpp.o: ../sources/Command/Msg.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adrien/Documents/SpaceBattle/server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/server.dir/sources/Command/Msg.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/sources/Command/Msg.cpp.o -c /home/adrien/Documents/SpaceBattle/server/sources/Command/Msg.cpp

CMakeFiles/server.dir/sources/Command/Msg.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/sources/Command/Msg.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adrien/Documents/SpaceBattle/server/sources/Command/Msg.cpp > CMakeFiles/server.dir/sources/Command/Msg.cpp.i

CMakeFiles/server.dir/sources/Command/Msg.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/sources/Command/Msg.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adrien/Documents/SpaceBattle/server/sources/Command/Msg.cpp -o CMakeFiles/server.dir/sources/Command/Msg.cpp.s

CMakeFiles/server.dir/sources/Command/Timer.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/sources/Command/Timer.cpp.o: ../sources/Command/Timer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adrien/Documents/SpaceBattle/server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/server.dir/sources/Command/Timer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/sources/Command/Timer.cpp.o -c /home/adrien/Documents/SpaceBattle/server/sources/Command/Timer.cpp

CMakeFiles/server.dir/sources/Command/Timer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/sources/Command/Timer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adrien/Documents/SpaceBattle/server/sources/Command/Timer.cpp > CMakeFiles/server.dir/sources/Command/Timer.cpp.i

CMakeFiles/server.dir/sources/Command/Timer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/sources/Command/Timer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adrien/Documents/SpaceBattle/server/sources/Command/Timer.cpp -o CMakeFiles/server.dir/sources/Command/Timer.cpp.s

CMakeFiles/server.dir/sources/Command/Pseudon.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/sources/Command/Pseudon.cpp.o: ../sources/Command/Pseudon.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adrien/Documents/SpaceBattle/server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/server.dir/sources/Command/Pseudon.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/sources/Command/Pseudon.cpp.o -c /home/adrien/Documents/SpaceBattle/server/sources/Command/Pseudon.cpp

CMakeFiles/server.dir/sources/Command/Pseudon.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/sources/Command/Pseudon.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adrien/Documents/SpaceBattle/server/sources/Command/Pseudon.cpp > CMakeFiles/server.dir/sources/Command/Pseudon.cpp.i

CMakeFiles/server.dir/sources/Command/Pseudon.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/sources/Command/Pseudon.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adrien/Documents/SpaceBattle/server/sources/Command/Pseudon.cpp -o CMakeFiles/server.dir/sources/Command/Pseudon.cpp.s

CMakeFiles/server.dir/sources/Game.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/sources/Game.cpp.o: ../sources/Game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adrien/Documents/SpaceBattle/server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/server.dir/sources/Game.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/sources/Game.cpp.o -c /home/adrien/Documents/SpaceBattle/server/sources/Game.cpp

CMakeFiles/server.dir/sources/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/sources/Game.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adrien/Documents/SpaceBattle/server/sources/Game.cpp > CMakeFiles/server.dir/sources/Game.cpp.i

CMakeFiles/server.dir/sources/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/sources/Game.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adrien/Documents/SpaceBattle/server/sources/Game.cpp -o CMakeFiles/server.dir/sources/Game.cpp.s

CMakeFiles/server.dir/sources/Command/Bateau.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/sources/Command/Bateau.cpp.o: ../sources/Command/Bateau.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adrien/Documents/SpaceBattle/server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/server.dir/sources/Command/Bateau.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/sources/Command/Bateau.cpp.o -c /home/adrien/Documents/SpaceBattle/server/sources/Command/Bateau.cpp

CMakeFiles/server.dir/sources/Command/Bateau.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/sources/Command/Bateau.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adrien/Documents/SpaceBattle/server/sources/Command/Bateau.cpp > CMakeFiles/server.dir/sources/Command/Bateau.cpp.i

CMakeFiles/server.dir/sources/Command/Bateau.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/sources/Command/Bateau.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adrien/Documents/SpaceBattle/server/sources/Command/Bateau.cpp -o CMakeFiles/server.dir/sources/Command/Bateau.cpp.s

# Object files for target server
server_OBJECTS = \
"CMakeFiles/server.dir/sources/BattleSpaceServer.cpp.o" \
"CMakeFiles/server.dir/sources/Client.cpp.o" \
"CMakeFiles/server.dir/sources/main.cpp.o" \
"CMakeFiles/server.dir/sources/TcpClient.cpp.o" \
"CMakeFiles/server.dir/sources/TcpServer.cpp.o" \
"CMakeFiles/server.dir/sources/Command/New.cpp.o" \
"CMakeFiles/server.dir/sources/Command/Join.cpp.o" \
"CMakeFiles/server.dir/sources/Command/Tir.cpp.o" \
"CMakeFiles/server.dir/sources/Command/Msg.cpp.o" \
"CMakeFiles/server.dir/sources/Command/Timer.cpp.o" \
"CMakeFiles/server.dir/sources/Command/Pseudon.cpp.o" \
"CMakeFiles/server.dir/sources/Game.cpp.o" \
"CMakeFiles/server.dir/sources/Command/Bateau.cpp.o"

# External object files for target server
server_EXTERNAL_OBJECTS =

server: CMakeFiles/server.dir/sources/BattleSpaceServer.cpp.o
server: CMakeFiles/server.dir/sources/Client.cpp.o
server: CMakeFiles/server.dir/sources/main.cpp.o
server: CMakeFiles/server.dir/sources/TcpClient.cpp.o
server: CMakeFiles/server.dir/sources/TcpServer.cpp.o
server: CMakeFiles/server.dir/sources/Command/New.cpp.o
server: CMakeFiles/server.dir/sources/Command/Join.cpp.o
server: CMakeFiles/server.dir/sources/Command/Tir.cpp.o
server: CMakeFiles/server.dir/sources/Command/Msg.cpp.o
server: CMakeFiles/server.dir/sources/Command/Timer.cpp.o
server: CMakeFiles/server.dir/sources/Command/Pseudon.cpp.o
server: CMakeFiles/server.dir/sources/Game.cpp.o
server: CMakeFiles/server.dir/sources/Command/Bateau.cpp.o
server: CMakeFiles/server.dir/build.make
server: /usr/local/lib/libboost_system.so
server: /usr/local/lib/libboost_filesystem.so
server: /usr/local/lib/libboost_serialization.so
server: /usr/local/lib/libboost_thread.so
server: /usr/local/lib/libboost_chrono.so
server: /usr/local/lib/libboost_date_time.so
server: /usr/local/lib/libboost_atomic.so
server: CMakeFiles/server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/adrien/Documents/SpaceBattle/server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Linking CXX executable server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/server.dir/build: server

.PHONY : CMakeFiles/server.dir/build

CMakeFiles/server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/server.dir/clean

CMakeFiles/server.dir/depend:
	cd /home/adrien/Documents/SpaceBattle/server/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/adrien/Documents/SpaceBattle/server /home/adrien/Documents/SpaceBattle/server /home/adrien/Documents/SpaceBattle/server/cmake-build-debug /home/adrien/Documents/SpaceBattle/server/cmake-build-debug /home/adrien/Documents/SpaceBattle/server/cmake-build-debug/CMakeFiles/server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/server.dir/depend

