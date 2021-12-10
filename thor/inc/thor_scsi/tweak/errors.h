#ifndef _THOR_SCSI_TWEAK_ERRORS_
#define _THOR_SCSI_TWEAK_ERRORS_ 1

#include <thor_scsi/core/lattice.h>

namespace thor_scsi {
enum bn_types
  { bn_des   = 0,
    dbn_des  = 1,
    bnL_des  = 2,
    dbnL_des = 3,
    bnL_sys  = 4,
    bnL_rms  = 5,
    bnr_sys  = 6,
    bnr_rms  = 7 };

enum dx_types
  { dx_sys = 0,
    dx_rms = 1 };

void iniranf(const long i);

void newseed(void);

double ranf(void);

void setrancut(const double cut);

double normranf(void);

void CheckAlignTol(thor_scsi::core::LatticeType &lat, const char *OutputFile);

void misalign(thor_scsi::core::LatticeType &lat, const dx_types dx_type, const int Fnum,
	      const int Knum, const double dx_rms, const double dy_rms,
	      const double dr_rms, const bool new_rnd);

void misalign(thor_scsi::core::LatticeType &lat, const dx_types dx_type, const int Fnum,
	      const int Knum, const double dx_sys, const double dy_sys,
	      const double dr_sys);

void misalign(thor_scsi::core::LatticeType &lat, const thor_scsi::dx_types dx_type, const int Fnum,
	      const double dx, const double dy, const double dr,
	      const bool new_rnd);

void misalign_rms_type(thor_scsi::core::LatticeType &lat, const int type,
		       const double dx_rms, const double dy_rms,
		       const double dr_rms, const bool new_rnd);

void misalign_sys_type(thor_scsi::core::LatticeType &lat, const int type,
		       const double dx_sys, const double dy_sys,
		       const double dr_sys);

void misalign_rms_girders(thor_scsi::core::LatticeType &lat, const int gs, const int ge,
			  const double dx_rms, const double dy_rms,
			  const double dr_rms, const bool new_rnd);

void misalign_sys_girders(thor_scsi::core::LatticeType &lat, const int gs, const int ge,
			  const double dx_sys, const double dy_sys,
			  const double dr_sys);

void set_aper(thor_scsi::core::LatticeType &lat, const int Fnum, const int Knum,
	      const double Dxmin, const double Dxmax,
	      const double Dymin, const double Dymax);

void set_aper(thor_scsi::core::LatticeType &lat, const int Fnum,
	      const double Dxmin, const double Dxmax,
	      const double Dymin, const double Dymax);

void set_aper_type(thor_scsi::core::LatticeType &lat, const int type, const double Dxmin,
		   const double Dxmax, const double Dymin, const double Dymax);

double get_L(thor_scsi::core::LatticeType &lat, const int Fnum, const int Knum);

void set_L(thor_scsi::core::LatticeType &lat, const int Fnum, const int Knum, const double L);
void set_L(thor_scsi::core::LatticeType &lat, const int Fnum, const double L);
void set_dL(thor_scsi::core::LatticeType &lat, const int Fnum, const int Knum, const double dL);
void set_dL(thor_scsi::core::LatticeType &lat, const int Fnum, const double dL);

//------------------------------------------------------------------------------
void get_bn(thor_scsi::core::LatticeType &lat, const bn_types bn_type, const int Fnum,
	    const int Knum, const int n, double &bn, double &an);

void get_bn(thor_scsi::core::LatticeType &lat, const int Fnum, const int Knum,
	    const int n, double &bn, double &an);

void set_bn(thor_scsi::core::LatticeType &lat, const bn_types bn_type, const int Fnum,
	    const int Knum, const int n, const double bn, const double an,
	    const bool new_rnd);

void set_bn(thor_scsi::core::LatticeType &lat, const bn_types bn_type, const int Fnum,
	    const int n, const double bn, const double an, const bool new_rnd);

//------------------------------------------------------------------------------

void set_bnL_design_type(thor_scsi::core::LatticeType &lat, const int type, const int n,
			 const double bnL, const double anL);

void set_bnL_sys_type(thor_scsi::core::LatticeType &lat, const int type, const int n,
		      const double bnL, const double anL);
void set_bnr_sys_type(thor_scsi::core::LatticeType &lat, const int type, const int n,
		      const double bnr, const double anr);

void set_bnL_rms_type(thor_scsi::core::LatticeType &lat, const int type, const int n,
		      const double bnL, const double anL, const bool new_rnd);

void set_bnr_rms_type(thor_scsi::core::LatticeType &lat, const int type, const int n,
		      const double bnr, const double anr,
		      const bool new_rnd);
}
#endif /* _THOR_SCSI_TWEAK_ERRORS_ */
/*
 * Local Variables:
 * mode: c++
 * c-file-style: "python"
 * End:
 */