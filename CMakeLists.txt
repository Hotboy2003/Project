cmake_minimum_required(VERSION 3.15) # Проверка версии CMake.
									 # Если версия установленой программы
									 # старее указаной, произайдёт аварийный выход.

set(PROJECT_NAME sfml_sample)				 # имя проекта		 
project("${PROJECT_NAME}")


set(CMAKE_CXX_STANDARD 17)			 # устанавливаем 17 стандарт языка
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)


add_definitions(-DSFML_STATIC)		 # дефайны

include_directories("ext/SFML/include/")	# добавляем директории
include_directories("/")
link_directories("ext/SFML/lib/")	

add_executable("${PROJECT_NAME}" Project.cpp Source.hpp Source.cpp)
											
target_link_libraries("${PROJECT_NAME}" debug sfml-graphics-s-d
						  debug sfml-window-s-d
						  debug sfml-system-s-d
						  debug sfml-audio-s-d)

target_link_libraries("${PROJECT_NAME}" optimised sfml-graphics-s
						  optimised debug sfml-window-s
						  optimised debug sfml-system-s
						  optimised debug sfml-audio-s)


target_link_libraries("${PROJECT_NAME}" open123 freetype winmm gdi32 opena132 flac vorbisenc vorbisfile vorbise ogg)

file(COPY "img" DESTINATION "/")