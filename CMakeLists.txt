cmake_minimum_required(VERSION 3.13)

set(PACKAGE_NAME "chimera-agent")
set(PACKAGE_VERSION "0.0.1")
set(CMAKE_BUILD_TYPE Release)

if(NOT CMAKE_TOOLCHAIN_FILE)
    set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/musl.cmake)
endif()
project(${PACKAGE_NAME} LANGUAGES C CXX)
if(NOT EXTERNAL_DIR)
    set(EXTERNAL_DIR ${PROJECT_BINARY_DIR}/external)
endif()
# include(ExternalProject)
include(${CMAKE_TOOLCHAIN_FILE})

set(INSTALL_DIR ${PROJECT_BINARY_DIR}/dep-install)
set(CMAKE_INSTALL_PREFIX PATH=${INSTALL_DIR})
### FLATBUFFER START ###
set(FLATBUFFERS "Flatbuffers")
set(FLATBUFFERS_URL "https://github.com/google/flatbuffers/archive/refs/tags/v24.3.25.tar.gz")
set(FLATBUFFERS_PREFIX ${EXTERNAL_DIR}/${FLATBUFFERS})
set(FLATBUFFERS_BUILD_TESTS OFF)
set(FLATBUFFERS_BUILD_FLATC OFF)
set(FLATBUFFERS_CXX_FLAGS "-Os -fno-exceptions -DNDEBUG -fno-rtti -ffunction-sections -fdata-sections -Wl,--gc-sections -fno-ident -fmerge-all-constants -fvisibility=hidden -Wl,--hash-style=sysv -Wl,--no-eh-frame-hdr -Wl,--build-id=none -Wl,--no-export-dynamic")
include(FetchContent)

FetchContent_Declare(
    ${FLATBUFFERS}
    URL ${FLATBUFFERS_URL}
    DOWNLOAD_EXTRACT_TIMESTAMP true
    PREFIX ${FLATBUFFERS_PREFIX}
)

### FLATBUFFER END ###

FetchContent_MakeAvailable(${FLATBUFFERS})
# add_subdirectory(${FLATBUFFERS_SRC} ${FLATBUFFERS_BIN} EXCLUDE_FROM_ALL)
# ExternalProject_Add(
#     ${FLATBUFFERS}
#     URL ${FLATBUFFER_URL}
#     PREFIX ${EXTERNAL_DIR}/${FLATBUFFERS}
#     DOWNLOAD_EXTRACT_TIMESTAMP true
#     CMAKE_ARGS 
#         -DCMAKE_INSTALL_PREFIX:PATH=${INSTALL_DIR}
#         -DCMAKE_TOOLCHAIN_FILE=${CMAKE_TOOLCHAIN_FILE}
#         -DEXTERNAL_DIR=${EXTERNAL_DIR}
#         -DFLATBUFFERS_BUILD_TESTS=OFF
#         -DFLATBUFFERS_BUILD_FLATC=OFF
# )


file(GLOB CHIMERA_SRC ${CMAKE_SOURCE_DIR}/src/*.cc)

add_executable(${PACKAGE_NAME} ${CHIMERA_SRC})
target_include_directories(
    ${PACKAGE_NAME} 
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
    PUBLIC ${TOOLCHAIN_DIR}/${ARCH}/include
    PUBLIC ${INSTALL_DIR}/include
    )
target_link_directories(
    ${PACKAGE_NAME} 
    PUBLIC 
    ${INSTALL_DIR}/lib
)
target_link_libraries(${PACKAGE_NAME} PUBLIC
    flatbuffers
    )
# add_dependencies(${PACKAGE_NAME} ${FLATBUFFERS})

target_link_options(${PACKAGE_NAME} PUBLIC "LINKER:--hash-style=sysv")
target_link_options(${PACKAGE_NAME} PUBLIC "LINKER:--no-eh-frame-hdr")
target_link_options(${PACKAGE_NAME} PUBLIC "LINKER:--gc-sections")
target_link_options(${PACKAGE_NAME} PUBLIC "LINKER:--build-id=none")
target_link_options(${PACKAGE_NAME} PUBLIC "LINKER:--no-export-dynamic")
target_link_options(${PACKAGE_NAME} PUBLIC "LINKER:-x")
target_link_options(${PACKAGE_NAME} PUBLIC "LINKER:-X")

# target_compile_options(${PACKAGE_NAME })

set(CMAKE_C_FLAGS "-W -Wall -Werror")
set(CMAKE_C_FLAGS_DEBUG "-Og -g")
set(CMAKE_C_FLAGS_RELEASE "-Os -fPIE -fno-exceptions -fvtable-gc -fno-rtti -ffunction-sections -fdata-sections -Wl,--gc-sections -fno-ident -fmerge-all-constants")
set(CMAKE_C_STANDARD 99)

set(CMAKE_CXX_FLAGS "-W -Wall -Werror")
set(CMAKE_CXX_FLAGS_DEBUG "-Og -g")
set(CMAKE_CXX_FLAGS_RELEASE "-Os -no-pie -fno-exceptions -fno-rtti -ffunction-sections -fdata-sections -fno-ident -fmerge-all-constants -fvisibility=hidden")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -DNDEBUG")
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_EXE_LINKER_FLAGS "-static -s")
