# CMakeList.txt: проект CMake для VirusWar; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (VirusWar "VirusWar.cpp" "VirusWar.h" "Controller.h" "Controller.cpp" "Model.h" "Model.cpp" "View.h" "View.cpp")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
