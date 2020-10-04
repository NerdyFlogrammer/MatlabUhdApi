
%{
	Copyright 2020 University of Applied Sciences (h_da)
%}

function make()
    mex -g  -LC:\local\UHD3.15\lib\ -LC:\local\boost_1_65_1\lib64-msvc-14.1 -luhd -I'C:\local\boost_1_65_1'  -I'C:\local\UHD3.15\include' ..\src\uhdapi.cpp COMPFLAGS='$COMPFLAGS /bigobj';
end