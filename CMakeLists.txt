cmake_minimum_required(VERSION 3.27)
set(CMAKE_VERBOSE_MAKEFILE ON)
project(ecal_shm_layer)
set(CMAKE_CXX_STANDARD 20)

set(ecal_io_mtx_src
        src/io/mtx/ecal_named_mutex.cpp
        src/io/mtx/ecal_named_mutex.h
        src/io/mtx/ecal_named_mutex_base.h
)


if(UNIX)
    set(ecal_io_mtx_linux_src
            src/io/mtx/linux/ecal_named_mutex_impl.cpp
            $<$<OR:$<BOOL:${ECAL_HAS_CLOCKLOCK_MUTEX}>,$<BOOL:${ECAL_HAS_ROBUST_MUTEX}>>:src/io/mtx/linux/ecal_named_mutex_robust_clocklock_impl.cpp>
            src/io/mtx/linux/ecal_named_mutex_impl.h
            $<$<OR:$<BOOL:${ECAL_HAS_CLOCKLOCK_MUTEX}>,$<BOOL:${ECAL_HAS_ROBUST_MUTEX}>>:src/io/mtx/linux/ecal_named_mutex_robust_clocklock_impl.h>
    )
endif()

# io/mtx/win32
if(WIN32)
    set(ecal_io_mtx_win_src
            src/io/mtx/win32/ecal_named_mutex_impl.cpp
            src/io/mtx/win32/ecal_named_mutex_impl.h
    )
endif()

set(ecal_cmn_src
        src/ecal_global_accessors.cpp
        src/ecal_def.h
        src/ecal_global_accessors.h
        src/ecal_globals.h
        src/ecal_globals.cpp

)

set(ecal_header_cmn
        include/ecal/ecal_event.h
)

set(ecal_io_shm_src
        src/io/shm/ecal_memfile.cpp
        src/io/shm/ecal_memfile_broadcast.cpp
        src/io/shm/ecal_memfile_broadcast_reader.cpp
        src/io/shm/ecal_memfile_broadcast_writer.cpp
        src/io/shm/ecal_memfile_db.cpp
        src/io/shm/ecal_memfile_naming.cpp
        src/io/shm/ecal_memfile_sync.cpp
        src/io/shm/ecal_memfile.h
        src/io/shm/ecal_memfile_broadcast.h
        src/io/shm/ecal_memfile_broadcast_reader.h
        src/io/shm/ecal_memfile_broadcast_writer.h
        src/io/shm/ecal_memfile_db.h
        src/io/shm/ecal_memfile_header.h
        src/io/shm/ecal_memfile_info.h
        src/io/shm/ecal_memfile_naming.h
        src/io/shm/ecal_memfile_os.h
        src/io/shm/ecal_memfile_sync.h
        src/io/shm/relocatable_circular_queue.h
)

if(UNIX)
    set(ecal_io_shm_linux_src
            src/io/shm/linux/ecal_memfile_os.cpp
    )
endif()

if(WIN32)
    set(ecal_io_shm_win_src
            src/io/shm/win32/ecal_memfile_os.cpp
    )
endif()

set(ecal_readwrite_src
        src/readwrite/ecal_buffer_payload_writer.h
        src/readwrite/ecal_reader.cpp
        src/readwrite/ecal_reader.h
        src/readwrite/ecal_writer.cpp
        src/readwrite/ecal_writer.h
        src/readwrite/ecal_writer_data.h
)

if     (IS_GIT_TREE OR NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/include/ecal/ecal_defs.h")
    configure_file(src/ecal_defs.h.in "${CMAKE_CURRENT_BINARY_DIR}/include/ecal/ecal_defs.h" @ONLY)
endif  (IS_GIT_TREE OR NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/include/ecal/ecal_defs.h")

function(ecal_add_ecal_shared_library TARGET_NAME)
    add_library(${TARGET_NAME} SHARED ${ARGN})
    set_target_properties(${TARGET_NAME} PROPERTIES
            VERSION ${eCAL_VERSION_STRING}
            SOVERSION ${eCAL_VERSION_MAJOR}
            OUTPUT_NAME ecal_${TARGET_NAME})
endfunction()



ecal_add_ecal_shared_library(${PROJECT_NAME}
        ${ecal_cmn_src}
        ${ecal_io_mtx_src}
        ${ecal_io_mtx_linux_src}
        ${ecal_io_mtx_win_src}
        ${ecal_io_shm_src}
        ${ecal_io_shm_linux_src}
        ${ecal_io_shm_win_src}
        ${ecal_readwrite_src}
        ${ecal_header_cmn}
        ${CMAKE_CURRENT_BINARY_DIR}/include/ecal/ecal_defs.h
)



file(COPY
        "C:/Program Files (x86)/Microsoft Visual Studio/2019/Community/VC/Tools/MSVC/14.29.30133/include"
        DESTINATION
        ${PROJECT_BINARY_DIR}/include/std
)

target_include_directories(${PROJECT_NAME}
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include/>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include/std
        $<INSTALL_INTERFACE:include>
        PRIVATE
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/mtx>
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/src>)

