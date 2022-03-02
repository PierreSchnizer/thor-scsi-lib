#ifndef _THOR_SCSI_CORE_ELEMENTS_BASIS_H_
#define _THOR_SCSI_CORE_ELEMENTS_BASIS_H_ 1

/**
   Definitions common for all elements

 */
#include <vector>
#include <string>
#include <tps/ss_vect.h>
#include <tps/tps_type.h>
#include <thor_scsi/core/cells.h>
// #include <thor_scsi/core/elements_enums.h>
#include <thor_scsi/core/config.h>

namespace thor_scsi {
	namespace core {
		//< Element virtual base class.
		class ElemType : public CellType {
		public:
#if 0
			/* already defined in cell_void */
			std::string
			Name;                      ///< Element name.
#endif
			bool
			Reverse;                   ///< reverse elements: rearange the elements in reveresed order
			double
			PL;                        ///< Length[m].
#if 0
			// should not be required any more
			PartsKind
			Pkind;                     ///<  Enumeration for magnet types.
#endif
			/**
			 * @ brief basic element type
			 *
			 * "length" is option, and is 0.0 if omitted.
			 * delegate type to
			 */
			ElemType(const Config & config) : CellType(config),
							  PL(config.get<double>("L", 0.0))
				{};
			virtual inline double getLength(void) final { return this->PL;};


			/**
			 * Todo: implement taking stream or as ostream operator ....
			 */
			virtual inline void show(std::ostream& strm, int level) const override {
				strm << "Name: '"<<this->name<<"'";
				if(level >= 1){
					strm << "L= '"<<this->PL<<"'";
				}
			}

			// C++ templates not supported for virtual functions.

			/**
			 * Propagater  step for phase space.
			 *
			 * Args:
			 *    ps : phase space
			 *
			 * Todo:
			 *      make config constant (after config has been reworked)
			 */
			virtual void pass(thor_scsi::core::ConfigType &conf, ss_vect<double> &ps) = 0;
			// virtual void pass(thor_scsi::core::ConfigType &conf, ss_vect<tps> &ps) = 0;

			template<typename T>
			void pass(thor_scsi::core::ConfigType &conf, ss_vect<T> &ps);


#if 0
			///< Candidate to be moved towards aperture
			template<typename T>
			bool CheckAmpl(thor_scsi::core::ConfigType &conf, const ss_vect<T> &x);

			virtual void show(std::ostream&, int level) const;
#if 0
			std::string repr_elem(void);     ///< auxilliary function providing a string of common information
			                                 ///< required for the different elements
			virtual std::string repr(void) = 0;  ///< representation similar to prt_elem but a bit more pythonic
			                                 ///< used by python interface to generate the information for
			                                 ///< :meth:`__repr__`
#endif
			/**
			 * Todo:
			 *    Check if that is still missing an overloaded method?
			 *
			 * If understood coorectly one should review if a element factory is requireed.
			 */
			virtual ElemType* Elem_Init(const thor_scsi::core::ConfigType &conf, const bool reverse)
				{ return NULL; };
			void prt_elem(const std::string &);
			virtual void print(const std::string &) {};

			virtual void SetdS(void) {}; ///< Eucledian Group: dx, dy
			virtual void SetdT(void) {}; ///< Eucledian Group: Roll angle
			virtual void SetPB(const int n) {}; ///< Multipoles (total numbers)
			virtual double GetdT(void) { return 0e0; };
			virtual double GetPB(const int n) { return 0e0; };

#endif
		};

#if 0
		///< Index for lattice families & elements.
		class ElemFamType {
		public:
			ElemType 		*ElemF;
			int
			nKid,                      ///< No of kids.
				NoDBN;
			std::vector<int> KidList;   ///< Todo: position number in lattice ??
			std::vector<std::string>    DBNlist; ///< For control system. Todo: but what ?
		};
#endif
	}
}
#endif /*  _THOR_SCSI_CORE_ELEMENTS_BASIS_H_  */
/*
 * Local Variables:
 * mode: c++
 * c-file-style: "python"
 * End:
 */