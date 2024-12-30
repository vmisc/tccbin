@rem ------------------------------------------------------
@rem batch file to build tcc using msvc
@rem build.bat, will compile mob branch
@rem or build.bat COMMIT=12345, will compile commit=12345
@rem ------------------------------------------------------

@echo off
@setlocal
@set TCC_FOLDER=build
@set TCC_COMMIT=mob
@if (%1)==(COMMIT) set TCC_COMMIT=%2

@echo TCC_COMMIT: %TCC_COMMIT%
@echo ===============================================================
@pushd .

@git clone git://repo.or.cz/tinycc.git

@cd tinycc
@git pull

git checkout -f %TCC_COMMIT%
for /f %%b in ('git.exe rev-parse HEAD') do set TCC_COMMIT_FULL_HASH=%%b

echo Apply patch build-tcc.bat.patch
@git apply ..\scripts\build-tcc.bat.patch

echo Building tcc with MSVC ...
cd win32
call build-tcc.bat -c cl -i %TCC_FOLDER%>nul

@popd
@echo off

REM Copy only binaries
@copy /Y tinycc\win32\%TCC_FOLDER%\libtcc.dll .>nul
@copy /Y tinycc\win32\%TCC_FOLDER%\tcc.exe .>nul
@copy /Y tinycc\win32\%TCC_FOLDER%\lib\*.o lib\>nul
@copy /Y tinycc\win32\%TCC_FOLDER%\lib\*.a lib\>nul
@copy /Y tinycc\win32\%TCC_FOLDER%\libtcc\* libtcc\>nul

@for /f %%b in ('date /T') do set CURRENT_DATE=%%b
@for /f %%b in ('time /T') do set CURRENT_TIME=%%b
@echo>build_on_date.txt %CURRENT_DATE% %CURRENT_TIME%
@echo>build_source_hash.txt %TCC_COMMIT_FULL_HASH%                          
@for /f "tokens=*" %%b in ('tcc.exe --version') do set CURRENT_TCC_VERSION=%%b
@echo>build_version.txt %CURRENT_TCC_VERSION%

REM show the builtin search paths for sanity checking:
tcc.exe -v -v

@echo tcc commit: %TCC_COMMIT% , full hash: %TCC_COMMIT_FULL_HASH% .
@echo The tcc executable is ready in tcc.exe

@echo Build libgc with tcc.exe ...
@rmdir /S /Q libgc>nul
@mkdir libgc
@xcopy /E /H /K /Y /I ..\libgc libgc>nul
@echo Apply patch gc.c.patch
@git apply .\scripts\gc.c.patch
@tcc.exe libgc\gc.c -DGC_NOT_DLL -DGC_WIN32_THREADS -DGC_THREADS -DGC_BUILTIN_ATOMIC -Ilibgc\include -c -o gc.o
@tcc.exe -ar lib\libgc.a gc.o
del gc.o
