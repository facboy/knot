#ifdef _UCRT

#include "libdnssec/string.h"
/* #include <math.h> */

// strndup() is not available on Windows
char *strndup( const char *s1, size_t n)
{
    char *copy= (char*)malloc( n+1 );
    memcpy( copy, s1, n );
    copy[n] = 0;
    return copy;
};
#endif
