# Set the minimum required CMake version
cmake_minimum_required(VERSION 3.12)

# Set the project name
project(In_Memory_Homomorphic_Computation)

# Set the compiler to dpu-upmem-dpurte-clang
set(CMAKE_C_COMPILER "dpu-upmem-dpurte-clang")

# Set the dpu library name
set(DPU_PKG_NAME "dpu")

# OpenFHE 
set(CMAKE_CXX_STANDARD 17)
option( BUILD_STATIC "Set to ON to include static versions of the library" OFF)

find_package(OpenFHE CONFIG REQUIRED)
if (OpenFHE_FOUND)
    message(STATUS "FOUND PACKAGE OpenFHE")
    message(STATUS "OpenFHE Version: ${BASE_OPENFHE_VERSION}")
    message(STATUS "OpenFHE installed as shared libraries: ${OpenFHE_SHARED}")
    message(STATUS "OpenFHE include files location: ${OpenFHE_INCLUDE}")
    message(STATUS "OpenFHE lib files location: ${OpenFHE_LIBDIR}")
    message(STATUS "OpenFHE Native Backend size: ${OpenFHE_NATIVE_SIZE}")
else()
    message(FATAL_ERROR "PACKAGE OpenFHE NOT FOUND")
endif ()

set( CMAKE_CXX_FLAGS ${OpenFHE_CXX_FLAGS} )

include_directories( ${OPENMP_INCLUDES} )
include_directories( ${OpenFHE_INCLUDE} )
include_directories( ${OpenFHE_INCLUDE}/third-party/include )
include_directories( ${OpenFHE_INCLUDE}/core )
include_directories( ${OpenFHE_INCLUDE}/pke )
include_directories( ${OpenFHE_INCLUDE}/binfhe )
### add directories for other OpenFHE modules as needed for your project


# Use dpu-pkg-config for compiler and linker flags
execute_process(COMMAND dpu-pkg-config --cflags ${DPU_PKG_NAME} OUTPUT_VARIABLE DPU_CFLAGS OUTPUT_STRIP_TRAILING_WHITESPACE)
execute_process(COMMAND dpu-pkg-config --libs ${DPU_PKG_NAME} OUTPUT_VARIABLE DPU_LIBS OUTPUT_STRIP_TRAILING_WHITESPACE)

# Add the executable targets for .c and _host.cpp files
file(GLOB SOURCE_FILES *_dpu.c *_host.cpp)
foreach(source_file ${SOURCE_FILES})
    get_filename_component(target_name ${source_file} NAME_WE)

    # Check the file extension and set the language accordingly
    if(source_file MATCHES ".*_dpu\\.c$")
        add_executable(${target_name} ${source_file})
    elseif(source_file MATCHES ".*_host\\.cpp$")

        link_directories( ${OpenFHE_LIBDIR} )
        link_directories( ${OPENMP_LIBRARIES} )
        if(BUILD_STATIC)
            set( CMAKE_EXE_LINKER_FLAGS "${OpenFHE_EXE_LINKER_FLAGS} -static")
            link_libraries( ${OpenFHE_STATIC_LIBRARIES} )
        else()
            set( CMAKE_EXE_LINKER_FLAGS ${OpenFHE_EXE_LINKER_FLAGS} )
            link_libraries( ${OpenFHE_SHARED_LIBRARIES} )
        endif()

        add_executable(${target_name} ${source_file})

        # Set compiler flags
        target_compile_options(${target_name} PRIVATE ${DPU_CFLAGS})

        # Link libraries
        target_link_libraries(${target_name} PRIVATE ${DPU_LIBS})
        
        target_compile_options(${target_name} PRIVATE -g)


 


    endif()
endforeach()
