/* Tracy-3

   J. Bengtsson, BNL 2007

   NO   1   link to the linear TPSA (nv_tps = 1)
       >1   link to Berz' TPSA

*/

#ifndef TRACY_LIB_H
#define TRACY_LIB_H

#define _GLIBCXX_DEBUG          1
#define _GLIBCXX_DEBUG_PEDANTIC 1

// C standard library.
#include <stdio.h>
#include <stddef.h>
#include <setjmp.h>
#include <time.h>
#include <memory.h>

// C++ standard library.
#include <cstdlib>
#include <cfloat>
#include <cctype>
#include <cmath>
#include <complex>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <fstream>
#if 0
  #include <string>
#else
  #include <debug/string>
#endif
#include <algorithm>

#include <gsl/gsl_linalg.h>
// Must be defined before armadillo.
// #include <carma>
#include <armadillo>
#include <vector>

using namespace std;


#define STR(x)  #x
#define XSTR(x) STR(x)

// Tracy-3
#include "thor_config.h"
// #include "field.h"

#ifndef NO_TPSA
  // Abort.
  #include <"thor_lib.h: NO_TPSA undefined!!!">
#elif NO_TPSA == 1
  // linear TPSA
  #pragma message("tracy_lib.h: NO_TPSA = " XSTR(NO_TPSA))
  #include "tpsa_lin.h"
  #include "tpsa_lin_pm.h"
#else
  // interface to M. Berz' TPSA
  #pragma message("tracy_lib.h: NO_TPSA = " XSTR(NO_TPSA))
  #include "tpsa_for.h"
  #include "tpsa_for_pm.h"
#endif

#include "ety.h"
#include "eigenv.h"

#include "thor.h"

#include "t2elem.h"
#include "t2cell.h"
#include "t2ring.h"
// #include "sigma_track.h"

#include "rdmfile.h"
#include "prtmfile.h"

#include "set_errors.h"
#include "lsoc.h"

// #include "orb_corr.h"
// #include "param.h"
// #include "dynap.h"

// #include "physlib.h"
// #include "fft.h"

#include "radia2tracy.h"
// #include "modnaff.h"
// #include "naffutils.h"
// #include "complexeheader_naff.h"
// #include "soleillib.h"

// #include "nsls-ii_lib.h"


extern LatticeType lat;

#endif