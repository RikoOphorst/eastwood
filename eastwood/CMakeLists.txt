file(GLOB_RECURSE EastwoodHeaderFiles   CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${EastwoodHeaderFiles})

file(GLOB_RECURSE EastwoodCodeFiles     CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${EastwoodCodeFiles})

file(GLOB_RECURSE EastwoodSlangFiles    CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/*.slang)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${EastwoodSlangFiles})

add_executable(eastwood ${EastwoodHeaderFiles} ${EastwoodCodeFiles} ${EastwoodSlangFiles})

target_include_directories(eastwood PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

### Vulkan SDK
find_package(Vulkan REQUIRED COMPONENTS SPIRV-Tools)
target_link_libraries(eastwood PUBLIC Vulkan::Vulkan)
target_link_libraries(eastwood PUBLIC Vulkan::Headers)
target_link_libraries(eastwood PUBLIC Vulkan::SPIRV-Tools)
target_compile_definitions(eastwood PUBLIC VK_USE_PLATFORM_WIN32_KHR)

target_compile_definitions(eastwood PUBLIC
    NOMINMAX
    VC_EXTRALEAN
    WIN32_LEAN_AND_MEAN
    _SILENCE_STDEXT_ARR_ITERS_DEPRECATION_WARNING
)

### vk-bootstrap
add_subdirectory("${CMAKE_SOURCE_DIR}/submodules/vk-bootstrap" "${CMAKE_BINARY_DIR}/submodules/vk-bootstrap")
target_link_libraries(eastwood PUBLIC vk-bootstrap::vk-bootstrap)

### glfw
set(GLFW_BUILD_DOCS OFF)
set(GLFW_INSTALL OFF)
add_subdirectory("${CMAKE_SOURCE_DIR}/submodules/glfw" "${CMAKE_BINARY_DIR}/submodules/glfw")
target_link_libraries(eastwood PUBLIC glfw)
target_include_directories(eastwood PUBLIC ${CMAKE_SOURCE_DIR}/submodules/glfw/include)
target_compile_definitions(eastwood PUBLIC GLFW_EXPOSE_NATIVE_WIN32)

### imgui
file(GLOB           BaseImguiFiles   CONFIGURE_DEPENDS 
    ${CMAKE_SOURCE_DIR}/submodules/imgui/*.cpp 
    ${CMAKE_SOURCE_DIR}/submodules/imgui/*.h)
    
file(GLOB           MiscImguiFiles   CONFIGURE_DEPENDS 
    ${CMAKE_SOURCE_DIR}/submodules/imgui/misc/cpp/*.cpp 
    ${CMAKE_SOURCE_DIR}/submodules/imgui/misc/cpp/*.h)

source_group(TREE ${CMAKE_SOURCE_DIR}/submodules FILES ${BaseImguiFiles} ${MiscImguiFiles})

target_sources(eastwood PUBLIC ${BaseImguiFiles} ${MiscImguiFiles})
target_include_directories(eastwood PUBLIC ${CMAKE_SOURCE_DIR}/submodules/imgui)