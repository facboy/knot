#pragma once

#ifdef _UCRT

// strndup() is not available on Windows
char *strndup( const char *s1, size_t n);

// realpath() is not available on Windows
#define realpath(N,R) _fullpath((R),(N),_MAX_PATH)

#endif
