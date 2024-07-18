cmake_minimum_required(VERSION 3.19)

set_property (GLOBAL PROPERTY USE_FOLDERS ON)
set (CMAKE_CONFIGURATION_TYPES Debug;Release;RelWithDebInfo;MinSizeRel)
add_definitions (-DUNICODE -D_UNICODE -DGLAD -DNOMINMAX)



add_subdirectory(external/glfw)
target_compile_options(glfw PRIVATE "/MTd")
project(ThreeCPP)
set(CMAKE_CXX_STANDARD 17)

set(ThreeCPPExternalInclude include)
set(ThreeCPPSourcesFolder src)

file(GLOB ThreeCPPSourceFiles CONFIGURE_DEPENDS
	src/three/*.h*
	src/three/*.c*
)
file(GLOB
	CamerasSourceFiles CONFIGURE_DEPENDS
	src/three/cameras/*.h*
	src/three/cameras/*.c*
)

file(GLOB
	ControlsSourceFiles CONFIGURE_DEPENDS
	src/three/controls/*.h*
	src/three/controls/*.c*
)
file(GLOB
	CoreSourceFiles CONFIGURE_DEPENDS
	src/three/core/*.h*
	src/three/core/*.c*
)

file(GLOB
	ExtrasSourceFiles CONFIGURE_DEPENDS
	src/three/extras/*.h*
	src/three/extras/*.c*
)

file(GLOB
	GeometriesSourceFiles CONFIGURE_DEPENDS
	src/three/geometries/*.h*
	src/three/geometries/*.c*
)

file(GLOB
	HelpersSourceFiles CONFIGURE_DEPENDS
	src/three/helpers/*.h*
	src/three/helpers/*.c*
)

file(GLOB
	LightsSourceFiles CONFIGURE_DEPENDS
	src/three/lights/*.h*
	src/three/lights/*.c*
)

file(GLOB
	LoadersSourceFiles CONFIGURE_DEPENDS
	src/three/loaders/*.h*
	src/three/loaders/*.c*
)

file(GLOB
	MaterialsSourceFiles CONFIGURE_DEPENDS
	src/three/materials/*.h*
	src/three/materials/*.c*
)
file(GLOB
	MathSourceFiles CONFIGURE_DEPENDS
	src/three/math/*.h*
	src/three/math/*.c*
)
file(GLOB
	ObjectsSourceFiles CONFIGURE_DEPENDS
	src/three/objects/*.h*
	src/three/objects/*.c*
)
file(GLOB
	RenderersSourceFiles CONFIGURE_DEPENDS
	src/three/renderers/*.h*
	src/three/renderers/*.c*
)
file(GLOB
	RenderersGLSourceFiles CONFIGURE_DEPENDS
	src/three/renderers/gl/*.h*
	src/three/renderers/gl/*.c*
)
file(GLOB
	RenderesShadersSourceFiles CONFIGURE_DEPENDS
	src/three/renderers/shaders/*.h*
	src/three/renderers/shaders/*.c*
)
file(GLOB
	ScenesSourceFiles CONFIGURE_DEPENDS
	src/three/scenes/*.h*
	src/three/scenes/*.c*
)
file(GLOB
	TexturesSourceFiles CONFIGURE_DEPENDS
	src/three/textures/*.h*
	src/three/textures/*.c*
)
file(GLOB
	UtilsSourceFiles CONFIGURE_DEPENDS
	src/three/utils/*.h*
	src/three/utils/*.c*
)
source_group("" FILES ${ThreeCPPSourceFiles})
source_group("cameras" FILES ${CamerasSourceFiles})
source_group("controls" FILES ${ControlsSourceFiles})
source_group("core" FILES ${CoreSourceFiles})
source_group("extras" FILES ${ExtrasSourceFiles})
source_group("geometries" FILES ${GeometriesSourceFiles})
source_group("helpers" FILES ${HelpersSourceFiles})
source_group("lights" FILES ${LightsSourceFiles})
source_group("loaders" FILES ${LoadersSourceFiles})
source_group("materials" FILES ${MaterialsSourceFiles})
source_group("math" FILES ${MathSourceFiles})
source_group("objects" FILES ${ObjectsSourceFiles})
source_group("renderes" FILES ${RenderersSourceFiles})
source_group("renderes/gl" FILES ${RenderersGLSourceFiles})
source_group("renderes/shaders" FILES ${RenderesShadersSourceFiles})
source_group("scenes" FILES ${ScenesSourceFiles})
source_group("textures" FILES ${TexturesSourceFiles})
source_group("utils" FILES ${UtilsSourceFiles})

set(GLADFolder external/GLAD)
file(GLOB GLADSourceFiles CONFIGURE_DEPENDS
	${GLADFolder}/*.c*
)

add_library(ThreeCPP 
	${ThreeCPPSourceFiles} 
	${CamerasSourceFiles} 
	${ControlsSourceFiles} 
	${CoreSourceFiles} 
	${ExtrasSourceFiles}	
	${GeometriesSourceFiles} 
	${HelpersSourceFiles} 
	${LightsSourceFiles}
	${LoadersSourceFiles}
	${MaterialsSourceFiles}
	${MathSourceFiles}
	${ObjectsSourceFiles}
	${RenderersSourceFiles}
	${RenderersGLSourceFiles}
	${RenderesShadersSourceFiles}
	${ScenesSourceFiles}
	${TexturesSourceFiles}
	${UtilsSourceFiles}
	${GLADSourceFiles}
)
	
target_include_directories(ThreeCPP PRIVATE ${ThreeCPPSourcesFolder} ${ThreeCPPExternalInclude})
set_target_properties(ThreeCPP PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}")	
target_compile_options(ThreeCPP PRIVATE "/MTd")

set(ThreeExampleFolder examples/ThreeExample)
file(GLOB 
	ThreeExampleSourceFiles CONFIGURE_DEPENDS
	${ThreeExampleFolder}/*.h*
	${ThreeExampleFolder}/*.c*
)
file(GLOB 
	ImGuiSourceFiles CONFIGURE_DEPENDS
	${ThreeExampleFolder}/imgui/*.h*
	${ThreeExampleFolder}/imgui/*.c*
)

file(GLOB 
	LearningjsCh1 CONFIGURE_DEPENDS
	${ThreeExampleFolder}/learningjs/ch1/*.h*
	${ThreeExampleFolder}/learningjs/ch1/*.c*
)
file(GLOB 
	LearningjsCh2 CONFIGURE_DEPENDS
	${ThreeExampleFolder}/learningjs/ch2/*.h*
	${ThreeExampleFolder}/learningjs/ch2/*.c*
)
file(GLOB 
	LearningjsCh3 CONFIGURE_DEPENDS
	${ThreeExampleFolder}/learningjs/ch3/*.h*
	${ThreeExampleFolder}/learningjs/ch3/*.c*
)
file(GLOB 
	LearningjsCh4 CONFIGURE_DEPENDS
	${ThreeExampleFolder}/learningjs/ch4/*.h*
	${ThreeExampleFolder}/learningjs/ch4/*.c*
)
source_group("" FILES ${ThreeExampleSourceFiles})
source_group("learningjs/ch1" FILES ${LearningjsCh1})
source_group("learningjs/ch2" FILES ${LearningjsCh2})
source_group("learningjs/ch3" FILES ${LearningjsCh3})
source_group("learningjs/ch4" FILES ${LearningjsCh4})
source_group("imgui" FILES ${ImGuiSourceFiles})

add_library(ThreeExample 
	${ThreeExampleSourceFiles}
	${ImGuiSourceFiles}
	${LearningjsCh1}
	${LearningjsCh2}
	${LearningjsCh3}
	${LearningjsCh4}
)
set_target_properties(ThreeExample PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}")	
target_compile_options(ThreeExample PRIVATE "/MTd")
target_include_directories(ThreeExample PUBLIC ${ThreeCPPSourcesFolder} ${ThreeCPPExternalInclude} ${ThreeExampleFolder} )
target_link_libraries (ThreeExample PRIVATE ThreeCPP glfw)

set(GLFWDemoFolder examples/GLFWdemo)
file(GLOB GLFWDemoSource CONFIGURE_DEPENDS
	${GLFWDemoFolder}/*.h*
	${GLFWDemoFolder}/*.c*
)

source_group("Sources" FILES ${GLFWDemoSource})
add_executable(GLFWDemo ${GLFWDemoSource})
target_compile_options(GLFWDemo PRIVATE "/MTd")
target_include_directories(GLFWDemo PRIVATE ${ThreeCPPSourcesFolder} ${ThreeCPPExternalInclude} ${ThreeExampleFolder})
target_link_libraries(GLFWDemo PRIVATE ThreeCPP ThreeExample glfw)
set_target_properties(GLFWDemo PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}")	
set_property(TARGET GLFWDemo PROPERTY VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR})



set(MFCDemoFolder examples/MFCDemo)
file(GLOB MFCDemoSource CONFIGURE_DEPENDS
	${MFCDemoFolder}/*.h*
	${MFCDemoFolder}/*.c*
)	

file(GLOB ResourceFiles CONFIGURE_DEPENDS
	${MFCDemoFolder}/*.rc
	${MFCDemoFolder}/res/*.rc2
	${MFCDemoFolder}/res/*.ico
	${MFCDemoFolder}/res/*.bmp	
)

source_group("" FILES ${MFCDemoSource} )
source_group("Resources" FILES ${ResourceFiles})
add_executable(MFCDemo WIN32 ${MFCDemoSource} ${ResourceFile} ${ResourceFiles})
set(CMAKE_MFC_FLAG 1)
target_compile_options(MFCDemo PRIVATE "/MTd")
target_include_directories(MFCDemo PUBLIC ${ThreeCPPSourcesFolder} ${ThreeCPPExternalInclude} ${ThreeExampleFolder} )
target_link_libraries (MFCDemo PRIVATE ThreeCPP ThreeExample)
set_target_properties(MFCDemo PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}")
set_property(TARGET MFCDemo PROPERTY VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR})
file(COPY "${CMAKE_CURRENT_LIST_DIR}/external/glew/Debug" DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY "${CMAKE_CURRENT_LIST_DIR}/external/glew/Release" DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

