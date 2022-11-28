mkdir build & cd build 
conan install .. -s build_type=Debug --build=missing 
cmake .. 
cmake --build . --config Debug