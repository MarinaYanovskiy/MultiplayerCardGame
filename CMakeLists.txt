cmake_minimum_required(VERSION 3.24)
project(ex4_main)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(WorkingInProgress
        Mtmchkin.cpp
        Mtmchkin.h
        Players/Player.cpp
        Players/Player.h
        test.cpp
        utilities.cpp
        utilities.h
        Players/HealthPoints.cpp
        Players/Warrior.h
        Players/Warrior.cpp
        Players/Ninja.cpp
        Players/Healer.cpp
        Players/Ninja.cpp
        Cards/Card.cpp
        Cards/BattleCard.cpp
        Cards/Dragon.cpp
        Cards/Gremlin.cpp
        Cards/Mana.cpp
        Cards/Merchant.cpp
        Cards/Treasure.cpp
        Cards/Well.cpp
        Cards/Witch.cpp
        Cards/Barfight.cpp
        tool/main.cpp)
