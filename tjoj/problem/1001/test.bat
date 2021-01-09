cl /nologo main.cpp
main.exe < input%1.txt > output_r.txt
fc output%1.txt output_r.txt
