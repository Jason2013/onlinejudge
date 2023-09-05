cmake -S . -B build
cmake --build build

@echo off
setlocal EnableDelayedExpansion

for %%i in (main*.in) do (
    echo @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    echo --- input: %%i ---
    type %%i
    if exist %%~ni.out del /q %%~ni.out
    set OUTPUT_PATH=%%~ni.out
    build\Debug\main.exe < %%i
    echo +++ output: %%~ni.out +++
    type %%~ni.out
)

endlocal
