#include <stdio.h>
#include <stdbool.h>
#include "../src/constants.h"
#include "../src/macros.h"
// START FUNC DECL
int
count_nn_I8(
		   long long *in,
		   long long n,
		   char *cfld,
		   long long * restrict cnt,
		   int n_out,
		   bool safe_mode
		   )
// STOP FUNC DECL
{
  int status = 0;
  register char  *cptr = cfld;

  if ( safe_mode == true )  { 
    for ( long long i = 0; i < n; i++ ) {
      if ( *cptr++ == FALSE ) { continue; }
      long long idx = in[i];
      int idxI4 = (int)idx;
      if ( ( idx < 0 ) || ( idx >= n_out ) ) { status = -1; continue; }
      cnt[idxI4]++;
    }
  }
  else {
    for ( long long i = 0; i < n; i++ ) {
      if ( *cptr++ == FALSE ) { continue; }
      long long idx = in[i];
      int idxI4 = (int)idx;
      cnt[idxI4]++;
    }
  }
  return(status);
}
