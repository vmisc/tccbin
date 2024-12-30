# thirdparty-windows-amd64 (tcc64, tccwin64)

This repository contains a prebuilt [tcc compiler](https://repo.or.cz/tinycc.git),
from the mob branch.

It is a ***minimalistic*** C compiler, that is just enough to be V's
backend. It is small and fast, although it does not produce optimised
executables. For that, use MSVC, GCC or CLANG instead.

## Target OS
The tcc build here produces ***64-bit executables***, compatiable with ***64-bit Windows***.

## Build from source
1. Make sure you have `MSVC` and `git` installed.
2. Run the `build.bat` from ***current directory***, 
   ```sh
	.\scripts\build.bat
   ```
3. If you want to build tcc with a special commit, run the `build.bat` with COMMIT=..., 
   ```sh
   .\scripts\build.bat COMMIT=68000c01ae5b90a4b9677f7725a286e9057e9767
   ```

## Note
1. tcc is enabled with `BACKTRACE` and `BCHECK` via patch `win32\build-tcc.bat` (see `scripts\build-tcc.bat.patch`);
2. `include\tcc` is removed, as we use a pre-compiled `lib\openlibm.o` (see https://github.com/JuliaMath/openlibm)


## What if V reports missing C header files?
In this case, please create a PR to help us improve it.
Please try finding the missing header files in
[this](http://download.savannah.gnu.org/releases/tinycc/winapi-full-for-0.9.27.zip)
official full version of the WINAPI headers for tcc,
or in the releases of [MinGW64](https://sourceforge.net/projects/mingw-w64/).

Most of the time, the ported headers should just work if you copy them inside the include/ folder,
however small modifications are sometimes needed to make them work with V.
