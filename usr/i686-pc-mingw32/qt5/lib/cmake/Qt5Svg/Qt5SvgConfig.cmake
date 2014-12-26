
if (CMAKE_VERSION VERSION_LESS 2.8.3)
    message(FATAL_ERROR "Qt 5 requires at least CMake version 2.8.3")
endif()

get_filename_component(_qt5Svg_install_prefix "${CMAKE_CURRENT_LIST_DIR}/../../../" ABSOLUTE)

# For backwards compatibility only. Use Qt5Svg_VERSION instead.
set(Qt5Svg_VERSION_STRING 5.1.0)

set(Qt5Svg_LIBRARIES Qt5::Svg)

macro(_qt5_Svg_check_file_exists file)
    if(NOT EXISTS "${file}" )
        message(FATAL_ERROR "The imported target \"Qt5::Svg\" references the file
   \"${file}\"
but this file does not exist.  Possible reasons include:
* The file was deleted, renamed, or moved to another location.
* An install or uninstall procedure did not complete successfully.
* The installation package was faulty and contained
   \"${CMAKE_CURRENT_LIST_FILE}\"
but not all the files it references.
")
    endif()
endmacro()


macro(_populate_Svg_target_properties Configuration LIB_LOCATION IMPLIB_LOCATION)
    set_property(TARGET Qt5::Svg APPEND PROPERTY IMPORTED_CONFIGURATIONS ${Configuration})

    set(imported_location "${_qt5Svg_install_prefix}/lib/${LIB_LOCATION}")
    _qt5_Svg_check_file_exists(${imported_location})
    set_target_properties(Qt5::Svg PROPERTIES
        "IMPORTED_LINK_INTERFACE_LIBRARIES_${Configuration}" "${_Qt5Svg_LIB_DEPENDENCIES}"
        "IMPORTED_LOCATION_${Configuration}" ${imported_location}
    )

    set(imported_implib "${_qt5Svg_install_prefix}/lib/${IMPLIB_LOCATION}")
    _qt5_Svg_check_file_exists(${imported_implib})
    if(NOT "${IMPLIB_LOCATION}" STREQUAL "")
        set_target_properties(Qt5::Svg PROPERTIES
        "IMPORTED_IMPLIB_${Configuration}" ${imported_implib}
        )
    endif()
endmacro()

if (NOT TARGET Qt5::Svg)

    set(_Qt5Svg_OWN_INCLUDE_DIRS "${_qt5Svg_install_prefix}/include/" "${_qt5Svg_install_prefix}/include/QtSvg")
    set(Qt5Svg_PRIVATE_INCLUDE_DIRS
        "${_qt5Svg_install_prefix}/include/QtSvg/${Qt5Svg_VERSION_STRING}"
        "${_qt5Svg_install_prefix}/include/QtSvg/${Qt5Svg_VERSION_STRING}/QtSvg"
    )

    foreach(_dir ${_Qt5Svg_OWN_INCLUDE_DIRS}
                 ${Qt5Svg_PRIVATE_INCLUDE_DIRS}
                 )
        _qt5_Svg_check_file_exists(${_dir})
    endforeach()

    set(Qt5Svg_INCLUDE_DIRS ${_Qt5Svg_OWN_INCLUDE_DIRS})

    set(Qt5Svg_DEFINITIONS -DQT_SVG_LIB)
    set(Qt5Svg_COMPILE_DEFINITIONS QT_SVG_LIB)

    set(_Qt5Svg_MODULE_DEPENDENCIES "Widgets;Gui;Core")

    set(_Qt5Svg_FIND_DEPENDENCIES_REQUIRED)
    if (Qt5Svg_FIND_REQUIRED)
        set(_Qt5Svg_FIND_DEPENDENCIES_REQUIRED REQUIRED)
    endif()
    set(_Qt5Svg_FIND_DEPENDENCIES_QUIET)
    if (Qt5Svg_FIND_QUIETLY)
        set(_Qt5Svg_DEPENDENCIES_FIND_QUIET QUIET)
    endif()
    set(_Qt5Svg_FIND_VERSION_EXACT)
    if (Qt5Svg_FIND_VERSION_EXACT)
        set(_Qt5Svg_FIND_VERSION_EXACT EXACT)
    endif()

    foreach(_module_dep ${_Qt5Svg_MODULE_DEPENDENCIES})
        if (NOT Qt5${_module_dep}_FOUND)
            find_package(Qt5${_module_dep}
                ${Qt5Svg_VERSION_STRING} ${_Qt5Svg_FIND_VERSION_EXACT}
                ${_Qt5Svg_DEPENDENCIES_FIND_QUIET}
                ${_Qt5Svg_FIND_DEPENDENCIES_REQUIRED}
                PATHS "${CMAKE_CURRENT_LIST_DIR}/.." NO_DEFAULT_PATH
            )
        endif()

        if (NOT Qt5${_module_dep}_FOUND)
            set(Qt5Svg_FOUND False)
            return()
        endif()

        list(APPEND Qt5Svg_INCLUDE_DIRS "${Qt5${_module_dep}_INCLUDE_DIRS}")
        list(APPEND Qt5Svg_PRIVATE_INCLUDE_DIRS "${Qt5${_module_dep}_PRIVATE_INCLUDE_DIRS}")
        list(APPEND Qt5Svg_DEFINITIONS ${Qt5${_module_dep}_DEFINITIONS})
        list(APPEND Qt5Svg_COMPILE_DEFINITIONS ${Qt5${_module_dep}_COMPILE_DEFINITIONS})
        list(APPEND Qt5Svg_EXECUTABLE_COMPILE_FLAGS ${Qt5${_module_dep}_EXECUTABLE_COMPILE_FLAGS})
    endforeach()
    list(REMOVE_DUPLICATES Qt5Svg_INCLUDE_DIRS)
    list(REMOVE_DUPLICATES Qt5Svg_PRIVATE_INCLUDE_DIRS)
    list(REMOVE_DUPLICATES Qt5Svg_DEFINITIONS)
    list(REMOVE_DUPLICATES Qt5Svg_COMPILE_DEFINITIONS)
    if (Qt5Svg_EXECUTABLE_COMPILE_FLAGS)
        list(REMOVE_DUPLICATES Qt5Svg_EXECUTABLE_COMPILE_FLAGS)
    endif()

    set(_Qt5Svg_LIB_DEPENDENCIES "Qt5::Widgets;Qt5::Gui;Qt5::Core")

    add_library(Qt5::Svg STATIC IMPORTED)
    set_property(TARGET Qt5::Svg PROPERTY IMPORTED_LINK_INTERFACE_LANGUAGES CXX)

    set_property(TARGET Qt5::Svg PROPERTY
      INTERFACE_INCLUDE_DIRECTORIES ${_Qt5Svg_OWN_INCLUDE_DIRS})
    set_property(TARGET Qt5::Svg PROPERTY
      INTERFACE_COMPILE_DEFINITIONS QT_SVG_LIB)

    _populate_Svg_target_properties(RELEASE "libQt5Svg.a" "" )

    if (EXISTS "${_qt5Svg_install_prefix}/lib/libQt5Svgd.a" )
        _populate_Svg_target_properties(DEBUG "libQt5Svgd.a" "" )
    endif()





_qt5_Svg_check_file_exists("${CMAKE_CURRENT_LIST_DIR}/Qt5SvgConfigVersion.cmake")

endif()
