#ifndef _THOR_SCSI_CORE_LATTICE_H_
#define _THOR_SCSI_CORE_LATTICE_H_ 1

#include <thor_scsi/core/elements.h>
#include <armadillo>
#include <string>
#include <vector>

namespace thor_scsi {
	namespace core {
	  class LatticeType {
	  public:
	    std::vector<thor_scsi::elements::ElemFamType> elemf;
	    std::vector<thor_scsi::elements::ElemType*>   elems;
	    ConfigType               conf;

            /**
	     * Must be called after lattice has been read?
	     * Todo:
	     *    Check if lattice parser calls it
	     */
	    void Lat_Init(void);
	     /*
	      * Check what this is for ...
	      */
	    void SI_init();

	    void prt_fams(void);
	    void prt_elems(const std::string &str);

	    int GetnKid(const int Fnum);
	    long int ElemIndex(const std::string &name);
	    long int Elem_GetPos(const int Fnum, const int Knum);

	    void get_transp_mats(const double delta);

	    void SetdS(const int Fnum, const int Knum);
	    void SetdT(const int Fnum, const int Knum);
	    void SetPB(const int Fnum, const int Knum, const int Order);
	    double GetdT(const int Fnum, const int Knum);
	    double GetPB(const int Fnum, const int Knum, const int Order);

	    double Elem_GetKval(const int Fnum, const int Knum, const int Order);


	    void Mpole_DefPBpar(const int Fnum, const int Knum, const int Order,
				const double PBpar);
	    void Mpole_DefPBsys(const int Fnum, const int Knum, const int Order,
				const double PBsys);
	    void Mpole_DefdTpar(const int Fnum, const int Knum, const double PdTpar);
	    void Mpole_DefdTsys(const int Fnum, const int Knum, const double PdTsys);

	    void Lat_Read(const std::string &filename, bool verbose=true);
	    bool Lat_Read_py(const std::string &filnam);
	    void prtmfile(const std::string &mfile_dat);
	    void rdmfile(const std::string &mfile_dat);

	    // t2elem.

	    template<typename T>
	      friend T get_p_s(const ConfigType &conf, const ss_vect<T> &ps);
	    template<typename T>
	      friend void radiate(const ConfigType &conf, ss_vect<T> &ps, const double L,
				  const double h_ref, const T B[]);
	    template<typename T>
	      void radiate_ID(const ConfigType &conf, ss_vect<T> &ps, const double L,
			      const T &B2_perp);
	    friend void emittance(ConfigType &conf, const tps &B2_perp, const tps &ds,
				  const tps &p_s0, const ss_vect<tps> &A);

            /**
	     * Pass forward from element number i0 to i1
	     *
	     *
	     *  Args:
	     *       i0:      start position
	     *       i1:      end position
	     *       ps:      phase space coordiante in design coordinate system
	     *       lastpos: reports the location number of the element, where the
	     *                particle  got lost
	     */
	    // t2cell.
	    template<typename T>
	      void Cell_Pass(const long i0, const long i1, ss_vect<T> &ps, long &lastpos);
            /**
	       Todo: make function inline or use default values
	    */
	    // Python does not support function overloading; dynamically typed language.
	    void Cell_Pass1(const long i0, const long i1, ss_vect<double> &ps,
			    long &lastpos);
           /**
	      Todo: make function inline or use default values
	    */
	    void Cell_Pass2(const long i0, const long i1, ss_vect<tps> &ps,
			    long &lastpos);
            /**
	     * Polymorphism:  Moment tracking ....
	     *
	     * Note:
	     *      Code explored but needs to be exploited
	     *
	     * @f[
	     *     \Sigma_{k+1} = M_k Sigma_k M_k^T = \left(M_k (M_k Sigma_k)^T\right)^T
	     * @f]
	     */
	    void Cell_Pass(const long i0, const long i1, tps &sigma, long &lastpos);

             /**
	      * Get closed orbit distortion
	      *
	      * Note:
	      *     consider to rename it to compute ...
	      *
	      * Todo:
	      *   consider to make it private function
	      */
	    bool Cell_getCOD(long imax, double eps, double dp, long &lastpos);
            /**
	     * Get Closed Orbit Distortion
	     *
	     * Args:
	     *      imax: number of maximum iterations
	     *      eps:  tolerance for Newton search
	     *      dP:   momentum deviation from design \f$ \Delta \delta \f$
	     *
	     * Todo:
	     *     renamed to compute
	     */
	    bool GetCOD(long imax, double eps, double dp, long &lastpos);
	    bool getcod(double dp, long &lastpos);

	    // t2ring.
	    /**
	     * Get Closed Orbit Distortion
	     *
	     * Todo:
	     *     Review if removed ?
	     *     renamed to compute
	     */
	    void GDiag(int n_, double C, arma::mat &A, arma::mat &Ainv_, arma::mat &R,
		       arma::mat &M, double &Omega, double &alphac);

	    void Cell_Geteta(long i0, long i1, bool ring, double dp);

            /**
	     * Calculates Twiss parameters element by element
	     *
	     * Todo:
	     *    Legacy reduncdancy?
	     *
	     */
	    void Cell_Twiss(long i0, long i1, ss_vect<tps> &Ascr, bool chroma, bool ring,
			    double dp);
	    void Cell_Twiss(const long int i0, const long int i1);
	    void TraceABN(long i0, long i1, const std::vector<double> &alpha,
			  const std::vector<double> &beta, const std::vector<double> &eta,
			  const std::vector<double> &etap, const double dp);
	    void ttwiss(const std::vector<double> &alpha, const std::vector<double> &beta,
			const std::vector<double> &eta, const std::vector<double> &etap,
			const double dp);
	    void Ring_Twiss(bool chroma, double dp);
	    void Ring_GetTwiss(bool chroma, double dp);
	    void Ring_Getchrom(double dp);

	    void Ring_Fittune(std::vector<double> &nu, double eps, std::vector<int> &nq,
			      long qf[], long qd[], double dkL, long imax);
	    void Ring_Fitchrom(std::vector<double> &ksi, double eps, std::vector<int> &ns,
			       long sf[], long sd[], double dkpL, long imax);
	    void Ring_FitDisp(long pos, double eta, double eps, long nq, long q[],
			      double dkL, long imax);

	    /**
	     * Computes Synchrotron integrals
	     */
	    void get_I(std::vector<double> &I, const bool prt);
	    template<typename T>
	      void Elem_Pass_Lin(ss_vect<T> ps);

            /**
              *
              *  Note:
              *    @f[
	      *        M^T J M = J
	      *    @f]
	      *
	      *    @f[
	      *         A{-1} = -J A^T J,
	      *
	      *         J =
	      *             \left|\begin{array}{rr}
	      *              0 & I \\
	      *             -I & 0 \\
	      *            \end{array}\right|,
	      *
	      *        A A^T = \left|\begin{array}{rr}
	      *                   \beta & -\alpha \\
	      *                   -\alpha & gamma \\
	      *                \end{array}\right|
	      *    @f]
	      *
              *      -1       T           |  0  I |        T   | beta   -alpha |
              *     A   = -J A  J,    J = |       |,    A A  = |               |
              *                           | -I  0 |            | -alpha  gamma |
	      *
	      * Args:
	      *        eps_x :
	      *        sigma_delta:
	      *         J :
	      *         tau:
	      *         I:
	      *         prt:
	      *
              */
	    void get_eps_x(double &eps_x, double &sigma_delta, double &U_0,
			   std::vector<double> &J, std::vector<double> &tau,
			   std::vector<double> &I, const bool prt);

	    friend void get_dI_eta_5(const int k, thor_scsi::elements::ElemType *Elem[]);

	    void prt_lat1(const int loc1, const int loc2, const std::string &fname,
			  const bool all);
            /**
	     *
	     * Todo:
	     *   inline function or good choice of default variables
	     */
	    void prt_lat2(const std::string &fname, const bool all);
	    /**
	     * Todo:
	     *     Check if that prints out Twiss parameters?
	     */
	    void prt_lat3(const int loc1, const int loc2, const std::string &fname,
			  const bool all, const int n);
	    void prt_lat4(const std::string &fname, const bool all, const int n);
            /**
	     *
	     * Compute chromaticty and print it to file
	     */
	    void prt_chrom_lat(void);

            /**
	     * Print closed orbit
	     *
	     * Todo:
	     *    Fix version print
	     */
	    void prt_cod(const char *file_name, const bool all);

            /**
	     * Print beam position for each element
	     */
	    void prt_beampos(const char *file_name);
            /**
	     * Prints beam size from sigma Matrix
	     *
	     * Args: cnt
	     *    cnt: allows to enumerate the file
	     *
	     * Todo:
	     *    refactor interface: make it a stream operator
	     */
	    void prt_beamsizes(const int cnt);

	    void checkifstable_(struct LOC_Ring_FitDisp *LINK);
	    void checkifstable(struct LOC_Ring_Fittune *LINK);

	    // Lattice.
	    void shiftk(long Elnum, double dk, struct LOC_Ring_Fittune *LINK);
	    void shiftk_(long Elnum, double dk, struct LOC_Ring_FitDisp *LINK);
	    void shiftkp(long Elnum, double dkp);

            /**
	     *
	     * Warning:
	     *     Sets the maximum amplitude to max_ampl
	     *
	     * Todo:
	     *       Find out where max_ampl is defined
	     */
	    void ChamberOff(void);
            /**
	     * Print Chamber (internal geometry limit used
	     *
	     * prints to predefined file chamber.out
	     *
	     * Todo:
	     *   convert it flush to a stream
	     */
	    void PrintCh(void);

            /**
	     * Prints info on computation and on result
	     *
	     * Warning:
	     *           string argument is not used!
	     */
	    void print(const std::string &);

	    void GetEmittance(const int Fnum, const bool prt);
	  };

	}
}
#endif /* _THOR_SCSI_CORE_LATTICE_H_ */
/*
 * Local Variables:
 * mode: c++
 * c-file-style: "python"
 * End:
 */