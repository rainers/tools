#include <windows.h>

#define _CRTALLOC(x) __declspec(allocate(x))

ULONG _tls_index = 0;

#pragma section(".tls")
#pragma section(".tls$AAA")
#pragma section(".tls$ZZZ")
#pragma section(".CRT$XLA")
#pragma section(".CRT$XLZ")
#pragma section(".CRT$XIA")
#pragma section(".CRT$XIZ")
#pragma section(".CRT$XCA")
#pragma section(".CRT$XCZ")
#pragma section(".CRT$XPA")
#pragma section(".CRT$XPZ")
#pragma section(".CRT$XTA")
#pragma section(".CRT$XTZ")

/* TLS raw template data start and end. */
_CRTALLOC(".tls$AAA") char _tls_start = 0;
_CRTALLOC(".tls$ZZZ") char _tls_end = 0;

// TLS init/exit callbacks
_CRTALLOC(".CRT$XLA") PIMAGE_TLS_CALLBACK __xl_a = 0;
_CRTALLOC(".CRT$XLZ") PIMAGE_TLS_CALLBACK __xl_z = 0;

// #pragma section(".tls")
_CRTALLOC(".tls") const IMAGE_TLS_DIRECTORY _tls_used =
{
  (SIZE_T) &_tls_start,
  (SIZE_T) &_tls_end,
  (SIZE_T) &_tls_index,
  (SIZE_T) (&__xl_a+1),
  (ULONG) 0, // SizeOfZeroFill
  (ULONG) 0 // Characteristics
};

typedef void(*_PVFV)();

// C init
_CRTALLOC(".CRT$XIA") _PVFV __xi_a[] = { NULL };
_CRTALLOC(".CRT$XIZ") _PVFV __xi_z[] = { NULL };
// C++ init
_CRTALLOC(".CRT$XCA") _PVFV __xc_a[] = { NULL };
_CRTALLOC(".CRT$XCZ") _PVFV __xc_z[] = { NULL };
// C pre-terminators
_CRTALLOC(".CRT$XPA") _PVFV __xp_a[] = { NULL };
_CRTALLOC(".CRT$XPZ") _PVFV __xp_z[] = { NULL };
// C terminators
_CRTALLOC(".CRT$XTA") _PVFV __xt_a[] = { NULL };
_CRTALLOC(".CRT$XTZ") _PVFV __xt_z[] = { NULL };

char _fltused;

int    _argc = 0;
char **_argv = NULL;
