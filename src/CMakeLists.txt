set(header_path "${${PROJECT_NAME}_SOURCE_DIR}/include")
set(header1 ${header_path}/task1.h)
set(src1 task1.cpp)
set(header2 ${header_path}/task2.h)
set(src2 task2.cpp)
set(header3 ${header_path}/task3.h)
set(src3 task3.cpp)

set(header ${header_path}/task1.h ${header_path}/task2.h ${header_path}/task3.h)

add_library(${PROJECT_NAME}_1 SHARED
  ${header1}
  ${src1})
target_include_directories(${PROJECT_NAME}_1
  PUBLIC ${CMAKE_CURRENT_BINARY_DIR}
         ${${PROJECT_NAME}_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME}_1
  pthread)

add_library(${PROJECT_NAME}_2 SHARED
  ${header2}
  ${src2})
target_include_directories(${PROJECT_NAME}_2
  PUBLIC ${CMAKE_CURRENT_BINARY_DIR}
         ${${PROJECT_NAME}_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME}_2
  pthread)

add_library(${PROJECT_NAME}_3 SHARED
  ${header3}
  ${src3})
target_include_directories(${PROJECT_NAME}_3
  PUBLIC ${CMAKE_CURRENT_BINARY_DIR}
         ${${PROJECT_NAME}_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME}_3
  pthread)
  
add_executable(${PROJECT_NAME}_1.info main1.cpp)
target_include_directories(${PROJECT_NAME}_1.info
  PUBLIC ${CMAKE_CURRENT_BINARY_DIR}
         ${${PROJECT_NAME}_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME}_1.info
  ${PROJECT_NAME}_1)

add_executable(${PROJECT_NAME}_2.info main2.cpp)
target_include_directories(${PROJECT_NAME}_2.info
  PUBLIC ${CMAKE_CURRENT_BINARY_DIR}
         ${${PROJECT_NAME}_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME}_2.info
  ${PROJECT_NAME}_2)

add_executable(${PROJECT_NAME}_3.info main3.cpp)
target_include_directories(${PROJECT_NAME}_3.info
  PUBLIC ${CMAKE_CURRENT_BINARY_DIR}
         ${${PROJECT_NAME}_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME}_3.info
  ${PROJECT_NAME}_3)


install(TARGETS ${PROJECT_NAME}_1
		LIBRARY DESTINATION "${lib_dest}"
    ARCHIVE DESTINATION "${lib_dest}"
    COMPONENT library)
install(TARGETS ${PROJECT_NAME}_1.info
		RUNTIME DESTINATION "${tool_dest}"
    COMPONENT library)

install(TARGETS ${PROJECT_NAME}_2
    LIBRARY DESTINATION "${lib_dest}"
    ARCHIVE DESTINATION "${lib_dest}"
    COMPONENT library)
install(TARGETS ${PROJECT_NAME}_2.info
    RUNTIME DESTINATION "${tool_dest}"
    COMPONENT library)

install(TARGETS ${PROJECT_NAME}_3
    LIBRARY DESTINATION "${lib_dest}"
    ARCHIVE DESTINATION "${lib_dest}"
    COMPONENT library)
install(TARGETS ${PROJECT_NAME}_3.info
    RUNTIME DESTINATION "${tool_dest}"
    COMPONENT library)
install(FILES ${header} DESTINATION "${include_dest}")
