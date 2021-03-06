# - Try to find Allegro
# Configs for lookup
#  ALLEGRO_PATH_SUFFIX - suffix for include path, allegro or alllegro5
#
# Once done this will define
#
#  ALLEGRO_FOUND - system has Allegro
#  ALLEGRO_INCLUDE_DIRS - the Allegro include directory
#  ALLEGRO_LIBRARIES - Link these to use Allegro
#  ALLEGRO_DEFINITIONS - Compiler switches required for using Allegro
#
#  Copyright (c) 2008 Olof Naessen <olof.naessen@gmail.com>
#
#  Redistribution and use is allowed according to the terms of the New
#  BSD license.
#  For details see the accompanying COPYING-CMAKE-SCRIPTS file.
#
if (ALLEGRO_LIBRARIES AND ALLEGRO_INCLUDE_DIRS)
  # in cache already
  set(ALLEGRO_FOUND TRUE)
else (ALLEGRO_LIBRARIES AND ALLEGRO_INCLUDE_DIRS)
  if (NOT DEFINED ALLEGRO_PATH_SUFFIX)
    set(ALLEGRO_PATH_SUFFIX allegro)
  endif()

  find_path(ALLEGRO_INCLUDE_DIR
    NAMES
      allegro.h
      allegro_image.h
    PATHS
      /usr/include
      /usr/local/include
      /opt/local/include
      /sw/include
      /usr/include/allegro5
      /usr/local/include/allegro5
      /opt/local/include/allegro5
      /sw/include/allegro5
    PATH_SUFFIXES
      "${ALLEGRO_PATH_SUFFIX}"
  )

  find_library(ALLEGRO_LIBRARY
    NAMES
      allegro
    PATHS
      /usr/lib
      /usr/lib/x86_64-linux-gnu
      /usr/local/lib
      /opt/local/lib
      /sw/lib
  )

  find_library(ALLEGRO_AUDIO_LIBRARY
    NAMES
      allegro_audio
    PATHS
      /usr/lib
      /usr/lib/x86_64-linux-gnu
      /usr/local/lib
      /opt/local/lib
      /sw/lib
  )
 
  find_library(ALLEGRO_FONT_LIBRARY
    NAMES
      allegro_font
    PATHS
      /usr/lib
      /usr/lib/x86_64-linux-gnu
      /usr/local/lib
      /opt/local/lib
      /sw/lib
  )
 
  find_library(ALLEGRO_TTF_LIBRARY
    NAMES
      allegro_ttf
    PATHS
      /usr/lib
      /usr/lib/x86_64-linux-gnu
      /usr/local/lib
      /opt/local/lib
      /sw/lib
  )
 
  find_library(ALLEGRO_IMAGE_LIBRARY
    NAMES
      allegro_image
    PATHS
      /usr/lib
      /usr/lib/x86_64-linux-gnu
      /usr/local/lib
      /opt/local/lib
      /sw/lib
  )

  set(ALLEGRO_LIBRARIES ${ALLEGRO_LIBRARY} ${ALLEGRO_IMAGE_LIBRARY})
  set(ALLEGRO_INCLUDE_DIRS ${ALLEGRO_INCLUDE_DIR})

  if (ALLEGRO_INCLUDE_DIRS AND ALLEGRO_LIBRARIES)
     set(ALLEGRO_FOUND TRUE)
  endif (ALLEGRO_INCLUDE_DIRS AND ALLEGRO_LIBRARIES)

  if (NOT ALLEGRO_FOUND)
    if (Allegro_FIND_REQUIRED)
      message(FATAL_ERROR "Could not find Allegro")
    endif (Allegro_FIND_REQUIRED)
  endif (NOT ALLEGRO_FOUND)

  # show the ALLEGRO_INCLUDE_DIRS and ALLEGRO_LIBRARIES variables only in the advanced view
  mark_as_advanced(ALLEGRO_INCLUDE_DIRS ALLEGRO_LIBRARIES)

endif (ALLEGRO_LIBRARIES AND ALLEGRO_INCLUDE_DIRS)

