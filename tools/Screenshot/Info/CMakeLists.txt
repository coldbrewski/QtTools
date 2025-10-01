# Configure information files for appearance
set(INFO_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/howto.txt
    ${CMAKE_CURRENT_SOURCE_DIR}/overview.txt
)

add_custom_target(InfoFiles ALL SOURCES ${INFO_FILES})
