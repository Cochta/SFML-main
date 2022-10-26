# CMakeList.txt : fichier projet CMake de niveau supérieur, effectuez une configuration globale
# et incluez les sous-projets ici.
#
cmake_minimum_required (VERSION 3.8)

# Solution
project ("SAE921-GRP4100-SFML")

# Each sub-project
set(EXECUTABLE_CUSTOM_NAME "00-Starter")
add_subdirectory ("00-Starter")

set(EXECUTABLE_CUSTOM_NAME "01-Test")
add_subdirectory ("01-Test")

set(EXECUTABLE_CUSTOM_NAME "02-Zelda")
add_subdirectory ("02-Zelda")

set(EXECUTABLE_CUSTOM_NAME "03-PaintingDrawer")
add_subdirectory ("03-PaintingDrawer")

set(EXECUTABLE_CUSTOM_NAME "04-Cuphead")
add_subdirectory ("04-Cuphead")

set(EXECUTABLE_CUSTOM_NAME "05-Arkanoid")
add_subdirectory ("05-Arkanoid")