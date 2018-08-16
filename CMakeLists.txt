cmake_minimum_required(VERSION 3.4)
project(testSDL)

#
#   Project Sources
#---------------------------------------------------------------
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")
set(SOURCE_FILES
        src/main.cpp)

#
#   Library Include Dirs
#---------------------------------------------------------------
if(MINGW)
    set(Boost_INCLUDE_DIR C:/MinGW/include)
    set(Boost_LIBRARY_DIR C:/MinGW/lib)

    set(SDL_INCLUDE_DIR C:/MinGW/include)
    set(SDL_LIBRARY C:/MinGW/lib)
else()
    set(Boost_INCLUDE_DIR /usr/local/include/)
    set(Boost_LIBRARY_DIR /usr/local/lib/)

    set(SDL_INCLUDE_DIR /usr/local/include/)
    set(SDL_LIBRARY /usr/local/lib/)
endif()

#
#   Find Packages
#---------------------------------------------------------------
find_package(SDL REQUIRED)
find_package(Boost COMPONENTS
        system
        timer
        thread
        REQUIRED)

#
#  Includes
#--------------------------------------------------------------
include_directories(
        ./include
        ${Boost_INCLUDE_DIRS}
        ${SDL_INCLUDE_DIR}
)

#
#   Executable
#--------------------------------------------------------------
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

#
#   Linking
#-------------------------------------------------------------
if(WIN32)
    target_link_libraries( ${PROJECT_NAME}
            #
            # LIBS REQUIRED FOR SDL IN THIS ORDER!!
            #------------------------------------------------------------
            mingw32                         # Required for SDL
            SDL2main
            SDL2
            SDL2_image
            m dinput8 dxguid dxerr8 user32 gdi32 winmm # Windows libs?
            imm32 ole32 oleaut32 shell32 version uuid  # Windows libs? Thank Sourceforge

            wsock32                         # Required for Boost::asio
            ws2_32                          # Required for Boost::asio
            ${Boost_LIBRARIES})

else()
    target_link_libraries( ${PROJECT_NAME}
            ${Boost_LIBRARIES}
            ${SDL2_LIBRARIES})
endif()
