#include <hiredis/hiredis.h>

#define major 0
#define minor 10
#define patch 1
#if (( HIREDIS_MAJOR > major ) || \
      (( HIREDIS_MAJOR == major ) && ( HIREDIS_MINOR > minor )) || \
      (( HIREDIS_MAJOR == major ) && ( HIREDIS_MINOR == minor ) && ( HIREDIS_PATCH >= patch ))) \
/* OK */
#else
# error Hiredis version must be >= major.minor.path
#endif

