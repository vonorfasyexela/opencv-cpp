cmake_minimum_required( VERSION 2.6 )
##############################################################################
project( hello-world )
set( SOURCE_FILES hello-world.cpp )
# set( LINKER_FLAGS    "-lcsfml-network -lcsfml-system -lwiringPi -lpthread" )

# if you need libraries that pkg-config can find set ON instead OFF
option( USE_GSTREAMER         "Want GStreamer?"         OFF )
option( USE_GSTREAMER_VIDEO   "Want GStreamer Video?"   OFF )
option( USE_GSTREAMER_AUDIO   "Want GStreamer Audio?"   OFF )
option( USE_GSTREAMER_PBUTILS "Want GStreamer pbutils?" OFF )
option( USE_GTK2              "Want GTK2?"              OFF )
option( USE_GTK3              "Want GTK3?"              OFF )
option( USE_OPENCV            "Want OpenCV?"            ON  )

add_compile_options( -g )
add_compile_options( -Wall )
# add_compile_options( -std=c11 )

# if you want to provide definitions to the compiler
# add_definitions( -DEXERCISE )

if ( APPLE )
# add_compile_options( -ObjC )
endif ( APPLE )    

message( "Platform: " ${CMAKE_CXX_PLATFORM_ID} )

##############################################################################

add_executable( ${PROJECT_NAME} ${SOURCE_FILES} )
set( CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${LINKER_FLAGS}" )

if ( USE_GSTREAMER )
    find_package( PkgConfig REQUIRED )
    pkg_search_module( GSTREAMER REQUIRED gstreamer-1.0 )    
    include_directories( ${GSTREAMER_INCLUDE_DIRS} )
    link_directories( ${GSTREAMER_LIBRARY_DIRS} )    
    target_compile_options( ${PROJECT_NAME} PRIVATE ${GSTREAMER_CFLAGS} )
    target_link_libraries( ${PROJECT_NAME} ${GSTREAMER_LIBRARIES} )
endif ( USE_GSTREAMER )

if ( USE_GSTREAMER_VIDEO )
    find_package( PkgConfig REQUIRED )
    pkg_search_module( GSTREAMER_VIDEO REQUIRED gstreamer-video-1.0 )    
    include_directories( ${GSTREAMER_VIDEO_INCLUDE_DIRS} )
    link_directories( ${GSTREAMER_VIDEO_LIBRARY_DIRS} )   
    target_compile_options( ${PROJECT_NAME} PRIVATE ${GSTREAMER_VIDEO_CFLAGS} )
    target_link_libraries( ${PROJECT_NAME} ${GSTREAMER_VIDEO_LIBRARIES} ) 
endif ( USE_GSTREAMER_VIDEO )

if ( USE_GSTREAMER_AUDIO )
    find_package( PkgConfig REQUIRED )
    pkg_search_module( GSTREAMER_AUDIO REQUIRED gstreamer-audio-1.0 )    
    include_directories( ${GSTREAMER_AUDIO_INCLUDE_DIRS} )
    link_directories( ${GSTREAMER_AUDIO_LIBRARY_DIRS} )   
    target_compile_options( ${PROJECT_NAME} PRIVATE ${GSTREAMER_AUDIO_CFLAGS} )
    target_link_libraries( ${PROJECT_NAME} ${GSTREAMER_AUDIO_LIBRARIES} ) 
endif ( USE_GSTREAMER_AUDIO )

if ( USE_GSTREAMER_PBUTILS )
    find_package( PkgConfig REQUIRED )
    pkg_search_module( GSTREAMER_PBUTILS REQUIRED gstreamer-pbutils-1.0 )    
    include_directories( ${GSTREAMER_PBUTILS_INCLUDE_DIRS} )
    link_directories( ${GSTREAMER_PBUTILS_LIBRARY_DIRS} )   
    target_compile_options( ${PROJECT_NAME} PRIVATE ${GSTREAMER_PBUTILS_CFLAGS} )
    target_link_libraries( ${PROJECT_NAME} ${GSTREAMER_PBUTILS_LIBRARIES} ) 
endif ( USE_GSTREAMER_PBUTILS )

if ( USE_GTK2 )
    find_package( PkgConfig REQUIRED )
    pkg_search_module( GTK2 REQUIRED gtk+-2.0 )
    include_directories( ${GTK2_INCLUDE_DIRS} )
    link_directories( ${GTK2_LIBRARY_DIRS} )    
    target_compile_options( ${PROJECT_NAME} PRIVATE ${GTK2_CFLAGS} )
    target_link_libraries( ${PROJECT_NAME} ${GTK2_LIBRARIES} )
endif ( USE_GTK2 )

if ( USE_GTK3 )
    find_package( PkgConfig REQUIRED )
    pkg_search_module( GTK3 REQUIRED gtk+-3.0 )
    include_directories( ${GTK3_INCLUDE_DIRS} )
    link_directories( ${GTK3_LIBRARY_DIRS} ) 
    target_compile_options( ${PROJECT_NAME} PRIVATE ${GTK3_CFLAGS} )
    target_link_libraries( ${PROJECT_NAME} ${GTK3_LIBRARIES} )   
endif ( USE_GTK3 )

if ( USE_OPENCV )
    find_package( PkgConfig REQUIRED )
    pkg_search_module( OPENCV REQUIRED opencv )
    include_directories( ${OPENCV_INCLUDE_DIRS} )
    link_directories( ${OPENCV_LIBRARY_DIRS} ) 
    target_compile_options( ${PROJECT_NAME} PRIVATE ${OPENCV_CFLAGS} )
    target_link_libraries( ${PROJECT_NAME} ${OPENCV_LIBRARIES} )   
endif ( USE_OPENCV )

