cl /nologo /O2 /Fe:%1.exe %1.c
%1.exe
fc %1.out %1.out_r
