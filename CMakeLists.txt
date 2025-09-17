cmake_minimum_required(VERSION 3.15)
project(traderadar LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- nlohmann (header-only) ---
#add_subdirectory(lib/nlohmann)

# --- IXWebSocket ---
set(IXWEBSOCKET_INSTALL OFF CACHE BOOL "" FORCE) # unngå install targets
set(USE_TLS ON CACHE BOOL "" FORCE)              # aktiver TLS
add_subdirectory(lib/IXWebSocket)

# --- Dine kilder ---
file(GLOB_RECURSE PROJECT_SOURCES src/*.cpp)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

# Link mot IXWebSocket og evt. nlohmann_json (avhengig av behov)
target_link_libraries(${PROJECT_NAME}
    PRIVATE
        ixwebsocket
        ftxui::screen
        ftxui::dom
        ftxui::component
)

# Inkluder src for egne headers
target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_SOURCE_DIR}/src ${CMAKE_SOURCE_DIR}/lib/nlohmann
)