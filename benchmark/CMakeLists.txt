add_executable(benchmark bechmark.cpp)
target_link_libraries(benchmark PRIVATE project_paths project_warnings ${PROJECT_NAME})
add_executable(generate ../dataset/generate.cpp)
target_link_libraries(generate PRIVATE project_paths project_warnings ${PROJECT_NAME})
