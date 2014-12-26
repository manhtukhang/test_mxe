
if (CMAKE_VERSION VERSION_LESS 2.8.3)
    message(FATAL_ERROR "Qt 5 requires at least CMake version 2.8.3")
endif()

get_filename_component(_qt5Sensors_install_prefix "${CMAKE_CURRENT_LIST_DIR}/../../../" ABSOLUTE)

# For backwards compatibility only. Use Qt5Sensors_VERSION instead.
set(Qt5Sensors_VERSION_STRING 5.1.0)

set(Qt5Sensors_LIBRARIES Qt5::Sensors)

macro(_qt5_Sensors_check_file_exists file)
    if(NOT EXISTS "${file}" )
        message(FATAL_ERROR "The imported target \"Qt5::Sensors\" references the file
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


macro(_populate_Sensors_target_properties Configuration LIB_LOCATION IMPLIB_LOCATION)
    set_property(TARGET Qt5::Sensors APPEND PROPERTY IMPORTED_CONFIGURATIONS ${Configuration})

    set(imported_location "${_qt5Sensors_install_prefix}/lib/${LIB_LOCATION}")
    _qt5_Sensors_check_file_exists(${imported_location})
    set_target_properties(Qt5::Sensors PROPERTIES
        "IMPORTED_LINK_INTERFACE_LIBRARIES_${Configuration}" "${_Qt5Sensors_LIB_DEPENDENCIES}"
        "IMPORTED_LOCATION_${Configuration}" ${imported_location}
    )

    set(imported_implib "${_qt5Sensors_install_prefix}/lib/${IMPLIB_LOCATION}")
    _qt5_Sensors_check_file_exists(${imported_implib})
    if(NOT "${IMPLIB_LOCATION}" STREQUAL "")
        set_target_properties(Qt5::Sensors PROPERTIES
        "IMPORTED_IMPLIB_${Configuration}" ${imported_implib}
        )
    endif()
endmacro()

if (NOT TARGET Qt5::Sensors)

    set(_Qt5Sensors_OWN_INCLUDE_DIRS "${_qt5Sensors_install_prefix}/include/" "${_qt5Sensors_install_prefix}/include/QtSensors")
    set(Qt5Sensors_PRIVATE_INCLUDE_DIRS
        "${_qt5Sensors_install_prefix}/include/QtSensors/${Qt5Sensors_VERSION_STRING}"
        "${_qt5Sensors_install_prefix}/include/QtSensors/${Qt5Sensors_VERSION_STRING}/QtSensors"
    )

    foreach(_dir ${_Qt5Sensors_OWN_INCLUDE_DIRS}
                 ${Qt5Sensors_PRIVATE_INCLUDE_DIRS}
                 )
        _qt5_Sensors_check_file_exists(${_dir})
    endforeach()

    set(Qt5Sensors_INCLUDE_DIRS ${_Qt5Sensors_OWN_INCLUDE_DIRS})

    set(Qt5Sensors_DEFINITIONS -DQT_SENSORS_LIB)
    set(Qt5Sensors_COMPILE_DEFINITIONS QT_SENSORS_LIB)

    set(_Qt5Sensors_MODULE_DEPENDENCIES "Core")

    set(_Qt5Sensors_FIND_DEPENDENCIES_REQUIRED)
    if (Qt5Sensors_FIND_REQUIRED)
        set(_Qt5Sensors_FIND_DEPENDENCIES_REQUIRED REQUIRED)
    endif()
    set(_Qt5Sensors_FIND_DEPENDENCIES_QUIET)
    if (Qt5Sensors_FIND_QUIETLY)
        set(_Qt5Sensors_DEPENDENCIES_FIND_QUIET QUIET)
    endif()
    set(_Qt5Sensors_FIND_VERSION_EXACT)
    if (Qt5Sensors_FIND_VERSION_EXACT)
        set(_Qt5Sensors_FIND_VERSION_EXACT EXACT)
    endif()

    foreach(_module_dep ${_Qt5Sensors_MODULE_DEPENDENCIES})
        if (NOT Qt5${_module_dep}_FOUND)
            find_package(Qt5${_module_dep}
                ${Qt5Sensors_VERSION_STRING} ${_Qt5Sensors_FIND_VERSION_EXACT}
                ${_Qt5Sensors_DEPENDENCIES_FIND_QUIET}
                ${_Qt5Sensors_FIND_DEPENDENCIES_REQUIRED}
                PATHS "${CMAKE_CURRENT_LIST_DIR}/.." NO_DEFAULT_PATH
            )
        endif()

        if (NOT Qt5${_module_dep}_FOUND)
            set(Qt5Sensors_FOUND False)
            return()
        endif()

        list(APPEND Qt5Sensors_INCLUDE_DIRS "${Qt5${_module_dep}_INCLUDE_DIRS}")
        list(APPEND Qt5Sensors_PRIVATE_INCLUDE_DIRS "${Qt5${_module_dep}_PRIVATE_INCLUDE_DIRS}")
        list(APPEND Qt5Sensors_DEFINITIONS ${Qt5${_module_dep}_DEFINITIONS})
        list(APPEND Qt5Sensors_COMPILE_DEFINITIONS ${Qt5${_module_dep}_COMPILE_DEFINITIONS})
        list(APPEND Qt5Sensors_EXECUTABLE_COMPILE_FLAGS ${Qt5${_module_dep}_EXECUTABLE_COMPILE_FLAGS})
    endforeach()
    list(REMOVE_DUPLICATES Qt5Sensors_INCLUDE_DIRS)
    list(REMOVE_DUPLICATES Qt5Sensors_PRIVATE_INCLUDE_DIRS)
    list(REMOVE_DUPLICATES Qt5Sensors_DEFINITIONS)
    list(REMOVE_DUPLICATES Qt5Sensors_COMPILE_DEFINITIONS)
    if (Qt5Sensors_EXECUTABLE_COMPILE_FLAGS)
        list(REMOVE_DUPLICATES Qt5Sensors_EXECUTABLE_COMPILE_FLAGS)
    endif()

    set(_Qt5Sensors_LIB_DEPENDENCIES "Qt5::Core")

    add_library(Qt5::Sensors STATIC IMPORTED)
    set_property(TARGET Qt5::Sensors PROPERTY IMPORTED_LINK_INTERFACE_LANGUAGES CXX)

    set_property(TARGET Qt5::Sensors PROPERTY
      INTERFACE_INCLUDE_DIRECTORIES ${_Qt5Sensors_OWN_INCLUDE_DIRS})
    set_property(TARGET Qt5::Sensors PROPERTY
      INTERFACE_COMPILE_DEFINITIONS QT_SENSORS_LIB)

    _populate_Sensors_target_properties(RELEASE "libQt5Sensors.a" "" )

    if (EXISTS "${_qt5Sensors_install_prefix}/lib/libQt5Sensorsd.a" )
        _populate_Sensors_target_properties(DEBUG "libQt5Sensorsd.a" "" )
    endif()





_qt5_Sensors_check_file_exists("${CMAKE_CURRENT_LIST_DIR}/Qt5SensorsConfigVersion.cmake")

endif()
