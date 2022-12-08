cmake_minimum_required(VERSION 3.1)

# set project name and language
project(file-access-helper LANGUAGES CXX)

# Automoc and RCC ON. Needed in QT projects
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
# C++ 11 Flag
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set project Version
set(file-access-helper_VERSION_MAJOR "0")
set(file-access-helper_VERSION_MINOR "0")
set(file-access-helper_VERSION_PATCH "1")

set(PROJECT_VERSION "${file-access-helper_VERSION_MAJOR}.${file-access-helper_VERSION_MINOR}.${file-access-helper_VERSION_PATCH}")

# Adding cmake functions like feature_summary()
include(FeatureSummary)
include(GNUInstallDirs)

# Find dependecies
find_package(Qt5 REQUIRED COMPONENTS Core CONFIG)

set(SOURCES
    ${PROJECT_SOURCE_DIR}/src/fileaccesshelper.cpp
    )

set(HEADERS
    ${PROJECT_SOURCE_DIR}/src/fileaccesshelper.h
    )

# create library
add_library(file-access-helper-lib SHARED
    ${SOURCES}
    ${HEADERS}
)

# set target Version
set_target_properties(file-access-helper-lib PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(file-access-helper-lib PROPERTIES SOVERSION ${file-access-helper_VERSION_MAJOR})

# generate export header
include(GenerateExportHeader)
generate_export_header(file-access-helper-lib)

# install export header
install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/file-access-helper-lib_export.h
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/file-access-helper-lib
    )

# announce headers - target perspective
target_include_directories(file-access-helper-lib
    PUBLIC
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/file-access-helper-lib>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    )

# install library
install(TARGETS file-access-helper-lib
    EXPORT file-access-helper-libExport
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    )

# configure *ConfigVersion.cmake
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    file-access-helper-libConfigVersion.cmake
    VERSION ${PACKAGE_VERSION}
    COMPATIBILITY SameMajorVersion
    )

# configure *Config.cmake
configure_file(file-access-helper-libConfig.cmake.in file-access-helper-libConfig.cmake @ONLY)

# install *Config(Version).cmake
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/file-access-helper-libConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/file-access-helper-libConfigVersion.cmake"
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/file-access-helper-lib
    )

# install targets cmake-files
install(EXPORT file-access-helper-libExport
    FILE file-access-helper-libTargets.cmake
    NAMESPACE VeinMeta::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/file-access-helper-lib
    )

# install public headers
install(
    FILES ${HEADERS}
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/file-access-helper-lib
    )

# spawn out some info on configuration
feature_summary(WHAT ALL FATAL_ON_MISSING_REQUIRED_PACKAGES)


