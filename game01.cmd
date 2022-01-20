@echo off
echo Running... Untitled Goose
cd "C:\Games\Untitled Goose Game"
tasklist /nh /fi "imagename eq Untitled.exe" | find /i "Untitled.exe" > nul || (start /wait Untitled.exe)
