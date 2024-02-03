#ifndef _DYNAMIC_H_
#define _DYNAMIC_H_

// Макрос ARR_EXPORTS необходимо определить только при сборке DLL
#ifdef ARR_EXPORTS
#define ARR_DLL __declspec(dllexport)
#else
#define ARR_DLL __declspec(dllimport)
#endif

// Соглашение о вызовах
#define ARR_DECL __cdecl

#endif