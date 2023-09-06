@echo off
setlocal EnableDelayedExpansion

for %%i in (..\cpp11\main*.in) do (
    @echo @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    rem echo %%i %%~ni.out
    @echo --- input: %%i ---
    type %%i
    if exist %%~ni.out del /q %%~ni.out
    python main.py < %%i > %%~ni.out
    @echo +++ output: %%~ni.out +++
    type %%~ni.out
)

endlocal
