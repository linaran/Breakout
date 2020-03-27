rmdir /s /q build
mkdir build
cd build
cmake .. -DSDL2_PATH="C:\Documents\Projects\CMake Breakout\SDL2\SDL2-2.0.10" -DSDL2_IMAGE_PATH="C:\Documents\Projects\CMake Breakout\SDL2\SDL2_Image-2.0.5"
cmake --build . 
cd ..