set(INSTALL_NAME installer)
set(INSTALL_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(INSTALL_INC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/inc")

file(GLOB_RECURSE INSTALL_SRC CONFIGURE_DEPENDS 
  ${INSTALL_SRC_DIR}/*.c
  ${INSTALL_SRC_DIR}/*.cpp 
  ${INSTALL_SRC_DIR}/tasktracker.rc
)
file(GLOB_RECURSE INSTALL_INC CONFIGURE_DEPENDS
  ${INSTALL_INC_DIR}/*.h
  ${INSTALL_INC_DIR}/*.hpp
)

add_executable(${INSTALL_NAME} ${INSTALL_SRC} ${INSTALL_INC})

add_dependencies(${INSTALL_NAME} tasktracker)

target_include_directories(${INSTALL_NAME} PRIVATE ${INSTALL_INC_DIR})
target_link_libraries(${INSTALL_NAME} PRIVATE shared)

set_target_properties(${INSTALL_NAME} PROPERTIES 
  LINK_FLAGS "/MANIFESTUAC:\"level='requireAdministrator' uiAccess='false'\" /SUBSYSTEM:CONSOLE"
)
