#ifndef IMMMA_TOOL_3_H
#define IMMMA_TOOL_3_H

#include "TString.h"
#include "TLorentzVector.h"
#include <cmath>

struct Nucleus{
	Int_t A = -666;
	TString sym = "";
	Float_t mass = -666;//MeV/c^2

	bool Filled(){
		return (A!=-666 && sym!="" && mass!=-666);
	}

	TString ToString(){
		return Form("%d%s",A,sym.Data());
	}

};

struct CaseResult{
	//CM constants results
	Float_t Vcm1;
	Float_t KEcm1;
	Float_t ThetaCM1;
	Float_t PhiCM1;

	Float_t Vcm2;
	Float_t KEcm2;
	Float_t ThetaCM2;
	Float_t PhiCM2;

	Float_t Ecm;

	//note that CM1 == observedCM  for MMM
	// and that CM2 == missingCM   for MMM

	TString ToString(){
		return Form("\n\t%f\n\t%f\n\t%f\n\t%f\n\t%f\n\t%f\n\t%f\n\t%f\n\t%f",Vcm1,KEcm1,ThetaCM1,PhiCM1,Vcm2,KEcm2,ThetaCM2,PhiCM2,Ecm);
	}
};

struct CMConstant{
	Float_t expected;
	Float_t lower;
	Float_t upper;
};


class IMMMA_Tool_3{
	public:
		//constructor:
		IMMMA_Tool_3();

		TString reaction;//string to hold reaction in A(a,b)B format
		TString breakup;//string to hold breakup in B -> c + d format

		//setters
		void SetBeamNucleus(Int_t A, TString sym, Float_t mass);
		void SetTargetNucleus(Int_t A, TString sym, Float_t mass);
		void SetEjectileNucleus(Int_t A, TString sym, Float_t mass);
		void SetRecoilNucleus(Int_t A, TString sym, Float_t mass);
		void SetBreakup1Nucleus(Int_t A, TString sym, Float_t mass);
		void SetBreakup2Nucleus(Int_t A, TString sym, Float_t mass);

		void SetBeamEnergy(Float_t energy);
		void SetRecoilExE(Float_t energy);

		void SetVcm_bu1_bounds(Float_t upper, Float_t lower);
		void SetVcm_bu2_bounds(Float_t upper, Float_t lower);
		void SetKEcm_bu1_bounds(Float_t upper, Float_t lower);
		void SetKEcm_bu2_bounds(Float_t upper, Float_t lower);
		void SetEcm_bounds(Float_t upper, Float_t lower);

		void SetVcm_bu1_bounds(Float_t sigma);
		void SetVcm_bu2_bounds(Float_t sigma);
		void SetKEcm_bu1_bounds(Float_t sigma);
		void SetKEcm_bu2_bounds(Float_t sigma);
		void SetEcm_bounds(Float_t sigma);

		//getters
		Nucleus GetBeamNucleus();
		Nucleus GetTargetNucleus();
		Nucleus GetEjectileNucleus();
		Nucleus GetRecoilNucleus();
		Nucleus GetBreakup1Nucleus();
		Nucleus GetBreakup2Nucleus();

		Float_t GetBeamMass();
		Float_t GetTargetMass();
		Float_t GetEjectileMass();
		Float_t GetRecoilMass();
		Float_t GetBreakup1Mass();
		Float_t GetBreakup2Mass();

		Float_t GetBeamEnergy();
		Float_t GetRecoilExE();

		Float_t GetVcm_bu1();
		Float_t GetVcm_bu2();
		Float_t GetKEcm_bu1();
		Float_t GetKEcm_bu2();
		Float_t GetEcm();

		TString GetReactionString();
		TString GetBreakupString();

		//init reaction function
		void CalculateCMConstants();

		//IMM Event analysis function:
		std::pair<CaseResult,CaseResult> AnalyzeEventIMM(Float_t ejectileE, Float_t ejectileTheta, Float_t ejectilePhi, Float_t detected1E, Float_t detected1Theta, Float_t detected1Phi, Float_t detected2E, Float_t detected2Theta, Float_t detected2Phi);

		//MMM Event analysis function:
		std::pair<CaseResult,CaseResult> AnalyzeEventMMM(Float_t ejectileE, Float_t ejectileTheta, Float_t ejectilePhi, Float_t detectedE, Float_t detectedTheta, Float_t detectedPhi);

		//calculate Excitation energy of recoil from ejectile, beam, target information:
		Float_t AnalyzeEventCalculateRecoilExE(Float_t ejectileE, Float_t ejectileTheta, Float_t ejectilePhi);

		//parsing
		// std::vector<Nucleus> parseReactionString(const TString& reactionStr);

		//checkers
		bool CheckInBounds_Vcm_bu1(Float_t test);
		bool CheckInBounds_Vcm_bu2(Float_t test);
		bool CheckInBounds_KEcm_bu1(Float_t test);
		bool CheckInBounds_KEcm_bu2(Float_t test);
		bool CheckInBounds_Ecm(Float_t test);

	private:
		//nuclear data
		Nucleus beam;
		Nucleus target;
		Nucleus ejectile;
		Nucleus recoil;
		Nucleus breakup1;
		Nucleus breakup2;

		//relevant reaction data
		Float_t beam_energy;//from experiment
		Float_t recoil_exE;//expected/from literature

		//Breakup CM Constants:
		// Float_t Vcm_bu1;		//constant from reaction
		// Float_t Vcm_bu2;		//constant from reaction
		// Float_t KEcm_bu1;		//constant from reaction
		// Float_t KEcm_bu2;		//constant from reaction
		// Float_t Ecm;			//constant from reaction

		CMConstant Vcm_bu1;
		CMConstant Vcm_bu2;
		CMConstant KEcm_bu1;
		CMConstant KEcm_bu2;
		CMConstant Ecm;

		Float_t ThetaCMSum;// = 180.;		//constant from reaction
		Float_t PhiCMSep;// = 180.;		//constant from reaction

		//Breakup CM Constant Bounds: (bounds for checking if a value passes the check)
		// Float_t Vcm_bu1_bounds[2] = {0.,0.};//{min,max}
		// Float_t Vcm_bu2_bounds[2] = {0.,0.};//{min,max}
		// Float_t KEcm_bu1_bounds[2] = {0.,0.};//{min,max}
		// Float_t KEcm_bu2_bounds[2] = {0.,0.};//{min,max}
		// Float_t Ecm_bounds[2] = {0.,0.};//{min,max}
		// Float_t ThetaCMSum_bounds[2] = {0.,0.};//{min,max}
		// Float_t PhiCMSep_bounds[2] = {0.,0.};//{min,max}

		const Float_t degToRad = M_PI/180.;
		const Float_t radToDeg = 180./M_PI;

		//parsing
		// Nucleus parseNucleus(const TString& nucleusStr);

};

#endif