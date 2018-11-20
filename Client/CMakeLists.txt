cmake_minimum_required(VERSION 3.12)
project(Client)


set(CMAKE_CXX_STANDARD 14)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
find_package(Boost COMPONENTS system)
include_directories(include )

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(Client src/main.cpp src/Client.cpp include/Client.h src/info_game.cpp include/info_game.h src/Case.cpp include/Case.h src/Game.cpp include/Game.h GUI/ConnexionPage.cpp include/ConnexionPage.h GUI/MainMenu.cpp include/MainMenu.h GUI/CreateGame.cpp include/CreateGame.h)
    target_link_libraries(Client ${Boost_LIBRARIES} tgui -lsfml-graphics -lsfml-window -lsfml-system)
endif()


