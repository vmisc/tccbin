/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_SHELLAPI
#define _INC_SHELLAPI

#ifndef SHSTDAPI
#ifndef _SHELL32_
#ifdef __cplusplus
#define SHSTDAPI EXTERN_C DECLSPEC_IMPORT HRESULT STDAPICALLTYPE
#define SHSTDAPI_(type) EXTERN_C DECLSPEC_IMPORT type STDAPICALLTYPE
#else
#define SHSTDAPI DECLSPEC_IMPORT HRESULT STDAPICALLTYPE
#define SHSTDAPI_(type) DECLSPEC_IMPORT type STDAPICALLTYPE
#endif
#else
#define SHSTDAPI STDAPI
#define SHSTDAPI_(type) STDAPI_(type)
#endif
#endif

DECLARE_HANDLE (HDROP);
#define DragQueryFile __MINGW_NAME_AW(DragQueryFile)
#define ShellExecute __MINGW_NAME_AW(ShellExecute)
#define FindExecutable __MINGW_NAME_AW(FindExecutable)
#define ShellAbout __MINGW_NAME_AW(ShellAbout)
#define ExtractAssociatedIcon __MINGW_NAME_AW(ExtractAssociatedIcon)
#define ExtractAssociatedIconEx __MINGW_NAME_AW(ExtractAssociatedIconEx)
#define ExtractIcon __MINGW_NAME_AW(ExtractIcon)

  SHSTDAPI_(UINT) DragQueryFileA (HDROP hDrop, UINT iFile, LPSTR lpszFile, UINT cch);
  SHSTDAPI_(UINT) DragQueryFileW (HDROP hDrop, UINT iFile, LPWSTR lpszFile, UINT cch);
  SHSTDAPI_(WINBOOL) DragQueryPoint (HDROP hDrop, POINT *ppt);
  SHSTDAPI_(void) DragFinish (HDROP hDrop);
  SHSTDAPI_(void) DragAcceptFiles (HWND hWnd, WINBOOL fAccept);
  SHSTDAPI_(HINSTANCE) ShellExecuteA (HWND hwnd, LPCSTR lpOperation, LPCSTR lpFile, LPCSTR lpParameters, LPCSTR lpDirectory, INT nShowCmd);
  SHSTDAPI_(HINSTANCE) ShellExecuteW (HWND hwnd, LPCWSTR lpOperation, LPCWSTR lpFile, LPCWSTR lpParameters, LPCWSTR lpDirectory, INT nShowCmd);
  SHSTDAPI_(HINSTANCE) FindExecutableA (LPCSTR lpFile, LPCSTR lpDirectory, LPSTR lpResult);
  SHSTDAPI_(HINSTANCE) FindExecutableW (LPCWSTR lpFile, LPCWSTR lpDirectory, LPWSTR lpResult);
  SHSTDAPI_(INT) ShellAboutA (HWND hWnd, LPCSTR szApp, LPCSTR szOtherStuff, HICON hIcon);
  SHSTDAPI_(INT) ShellAboutW (HWND hWnd, LPCWSTR szApp, LPCWSTR szOtherStuff, HICON hIcon);
  SHSTDAPI_(HICON) DuplicateIcon (HINSTANCE hInst, HICON hIcon);
  SHSTDAPI_(HICON) ExtractAssociatedIconA (HINSTANCE hInst, LPSTR pszIconPath, WORD *piIcon);
  SHSTDAPI_(HICON) ExtractAssociatedIconW (HINSTANCE hInst, LPWSTR pszIconPath, WORD *piIcon);
  SHSTDAPI_(HICON) ExtractAssociatedIconExA (HINSTANCE hInst, LPSTR pszIconPath, WORD *piIconIndex, WORD *piIconId);
  SHSTDAPI_(HICON) ExtractAssociatedIconExW (HINSTANCE hInst, LPWSTR pszIconPath, WORD *piIconIndex, WORD *piIconId);
  SHSTDAPI_(HICON) ExtractIconA (HINSTANCE hInst, LPCSTR pszExeFileName, UINT nIconIndex);
  SHSTDAPI_(HICON) ExtractIconW (HINSTANCE hInst, LPCWSTR pszExeFileName, UINT nIconIndex);

#ifndef WINSHELLAPI
#if !defined(_SHELL32_)
#define WINSHELLAPI DECLSPEC_IMPORT
#else
#define WINSHELLAPI
#endif
#endif

#ifndef SHSTDAPI
#if !defined(_SHELL32_)
#define SHSTDAPI EXTERN_C DECLSPEC_IMPORT HRESULT WINAPI
#define SHSTDAPI_(type) EXTERN_C DECLSPEC_IMPORT type WINAPI
#else
#define SHSTDAPI STDAPI
#define SHSTDAPI_(type) STDAPI_(type)
#endif
#endif

/* SHDOCAPI[_] definitions not required in this TinyCC minimal header */

#if !defined(_WIN64)
#include <pshpack1.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifdef UNICODE
#define ShellExecute ShellExecuteW
#define FindExecutable FindExecutableW
#else
#define ShellExecute ShellExecuteA
#define FindExecutable FindExecutableA
#endif

  /* minimal subset distributed with TinyCC. nShowCmd is at winuser.h */
  SHSTDAPI_(HINSTANCE) ShellExecuteA(HWND hwnd,LPCSTR lpOperation,LPCSTR lpFile,LPCSTR lpParameters,LPCSTR lpDirectory,INT nShowCmd);
  SHSTDAPI_(HINSTANCE) ShellExecuteW(HWND hwnd,LPCWSTR lpOperation,LPCWSTR lpFile,LPCWSTR lpParameters,LPCWSTR lpDirectory,INT nShowCmd);
  SHSTDAPI_(HINSTANCE) FindExecutableA(LPCSTR lpFile,LPCSTR lpDirectory,LPSTR lpResult);
  SHSTDAPI_(HINSTANCE) FindExecutableW(LPCWSTR lpFile,LPCWSTR lpDirectory,LPWSTR lpResult);
  SHSTDAPI_(LPWSTR *) CommandLineToArgvW(LPCWSTR lpCmdLine,int*pNumArgs);

#ifdef __cplusplus
}
#endif

#if !defined(_WIN64)
#include <poppack.h>
#endif
#endif
