#include <hiredis/hiredis.h>
#include <stdlib.h>

int main(void) {
        int major=0, minor=10, patch=1;

        if (( HIREDIS_MAJOR > major ) ||
           (( HIREDIS_MAJOR == major ) && ( HIREDIS_MINOR > minor )) ||
           (( HIREDIS_MAJOR == major ) && ( HIREDIS_MINOR == minor ) && ( HIREDIS_PATCH >= patch )))
        {
                exit(0);
        }
        else
        {
                exit(1);
        }
}
