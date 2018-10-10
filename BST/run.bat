echo off

SET mypath=%~dp0

g++ -o %mypath%/main %mypath%/Node.cpp %mypath%/TreeIterative.cpp %mypath%/Tree.cpp %mypath%/main.cpp
%mypath%/main