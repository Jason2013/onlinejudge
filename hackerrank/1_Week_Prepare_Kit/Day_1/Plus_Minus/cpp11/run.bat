rem cl /nologo /O2 /Fe:%1.exe %1.cpp
rem %1.exe
rem fc %1.out %1.out_r
cmake -S . -B build
cmake --build build
build\Debug\main.exe < main.in > main.out
