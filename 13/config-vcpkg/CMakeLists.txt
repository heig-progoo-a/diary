cmake_minimum_required(VERSION 3.10...3.22)
project(BoidsProject LANGUAGES CXX VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# if(NOT MSVC)
#     find_path(VCPKG_ROOT NAMES vcpkg PATHS "$ENV{VCPKG_ROOT}" NO_DEFAULT_PATH)
#     if(NOT VCPKG_ROOT)
#         message(FATAL_ERROR "VCPKG_ROOT not found in environment variables.")
#     else()
#         message(STATUS "VCPKG_ROOT found at ${VCPKG_ROOT}")
#         include(${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake)
#         set(CMAKE_PREFIX_PATH "${CMAKE_PREFIX_PATH};${VCPKG_ROOT}/installed/x64-linux")
#     endif()
# endif()

if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4 /Zi")
    set(FREETYPE "")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
    set(FREETYPE "freetype")
endif()

find_package(Boost 1.83.0 REQUIRED COMPONENTS program_options)
find_package(SFML 2.6.1 REQUIRED COMPONENTS graphics window system)
find_package(imgui CONFIG REQUIRED)
find_package(ImGui-SFML CONFIG REQUIRED)
find_package(GLEW CONFIG REQUIRED)
find_package(Freetype REQUIRED)

file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB ASSETS "assets/*")
file(COPY ${ASSETS} DESTINATION ${CMAKE_BINARY_DIR}/assets)

foreach(ASSET ${ASSETS})
  get_filename_component(ASSET_NAME ${ASSET} NAME)
  add_custom_command(
    OUTPUT "${CMAKE_BINARY_DIR}/assets/${ASSET_NAME}"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different "${ASSET}" "${CMAKE_BINARY_DIR}/assets/${ASSET_NAME}"
    DEPENDS "${ASSET}"
  )
endforeach()

add_executable(boids ${SOURCES} ${ASSETS})
source_group("Assets" FILES ${ASSETS})

target_include_directories(boids PRIVATE src)
target_link_libraries(boids ${Boost_LIBRARIES} GLEW::GLEW  ImGui-SFML::ImGui-SFML imgui::imgui sfml-graphics sfml-window sfml-system ${FREETYPE})

if(CMAKE_BUILD_TYPE STREQUAL "Release")
    if(MSVC)
    target_compile_options(boids PRIVATE /O2)
    else()
    target_compile_options(boids PRIVATE -O3)
    endif()
else() # Release
    if(MSVC)
        target_compile_options(boids PRIVATE /Zi)
        target_link_options(boids PRIVATE /DEBUG)
    else()
        target_compile_options(boids PRIVATE -O3 -g -pg)
    endif()
endif()

if(MSVC)
    set_target_properties(
        boids PROPERTIES
        LINK_FLAGS "/STACK:10000000"
        VS_DEBUGGER_COMMAND_ARGUMENTS "-s -f"
    )
endif()
