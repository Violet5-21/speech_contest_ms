cmake_minimum_required(VERSION 3.29)
project(speech_contest_ms)

set(CMAKE_CXX_STANDARD 11)

add_executable(speech_contest_ms main.cpp
        Manager.cpp
        Manager.h
        Competitor.h)
