#ifndef IMMMA_TOOL_3_H
#define IMMMA_TOOL_3_H

#include "TString.h"
#include "TLorentzVector.h"
#include <cmath>

struct Nucleus{
	Int_t A = -666;
	TString sym = "";
	Double_t mass = -666;//MeV/c^2

	bool Filled(){
		return (A!=-666 && sym!="" && mass!=-666);
	}

	TString ToString(){
		return Form("%d%s",A,sym.Data());
	}

};

struct CaseResult{
	//boost vector:
	TVector3 boostvector;

	//CM constants results
	Double_t Vcm1;
	Double_t KEcm1;
	Double_t ThetaCM1;
	Double_t PhiCM1;
	Double_t ELab1;
	Double_t ThetaLab1;
	Double_t PhiLab1;

	Double_t Vcm2;
	Double_t KEcm2;
	Double_t ThetaCM2;
	Double_t PhiCM2;
	Double_t ELab2;
	Double_t ThetaLab2;
	Double_t PhiLab2;


	//add recoil invariant mass calculation:
	Double_t recInvMass;
	Double_t ejInvMass;
	Double_t bu1InvMass;
	Double_t bu2InvMass;

	Double_t Ecm;

	Double_t recoilExE;

	//note that CM1 == observedCM  for MMM
	// and that CM2 == missingCM   for MMM

	TString ToString(){
		return Form("\n\t%lf\n\t%lf\n\t%lf\n\t%lf\n\t%lf\n\t%lf\n\t%lf\n\t%lf\n\t%lf",Vcm1,KEcm1,ThetaCM1,PhiCM1,Vcm2,KEcm2,ThetaCM2,PhiCM2,Ecm);
	}
};

struct CMConstant{
	Double_t expected;
	Double_t mean;
	Double_t lower;
	Double_t upper;
};


class IMMMA_Tool_3{
	public:
		//constructor:
		IMMMA_Tool_3();

		TString reaction;//string to hold reaction in A(a,b)B format
		TString breakup;//string to hold breakup in B -> c + d format

		//setters
		void SetBeamNucleus(Int_t A, TString sym, Double_t mass);
		void SetTargetNucleus(Int_t A, TString sym, Double_t mass);
		void SetEjectileNucleus(Int_t A, TString sym, Double_t mass);
		void SetRecoilNucleus(Int_t A, TString sym, Double_t mass);
		void SetBreakup1Nucleus(Int_t A, TString sym, Double_t mass);
		void SetBreakup2Nucleus(Int_t A, TString sym, Double_t mass);

		void SetBeamEnergy(Double_t energy);
		void SetRecoilExE(Double_t energy);

		void SetVcm_bu1_bounds(Double_t upper, Double_t lower);
		void SetVcm_bu2_bounds(Double_t upper, Double_t lower);
		void SetKEcm_bu1_bounds(Double_t upper, Double_t lower);
		void SetKEcm_bu2_bounds(Double_t upper, Double_t lower);
		void SetEcm_bounds(Double_t upper, Double_t lower);

		void SetVcm_bu1_boundsp(Double_t upperp, Double_t lowerp);
		void SetVcm_bu2_boundsp(Double_t upperp, Double_t lowerp);
		void SetKEcm_bu1_boundsp(Double_t upperp, Double_t lowerp);
		void SetKEcm_bu2_boundsp(Double_t upperp, Double_t lowerp);
		void SetEcm_boundsp(Double_t upperp, Double_t lowerp);

		void SetVcm_bu1_bounds(Double_t sigma);
		void SetVcm_bu2_bounds(Double_t sigma);
		void SetKEcm_bu1_bounds(Double_t sigma);
		void SetKEcm_bu2_bounds(Double_t sigma);
		void SetEcm_bounds(Double_t sigma);

		void SetMean_Vcm_bu1(Double_t mean);
		void SetMean_Vcm_bu2(Double_t mean);
		void SetMean_KEcm_bu1(Double_t mean);
		void SetMean_KEcm_bu2(Double_t mean);
		void SetMean_Ecm(Double_t mean);

		void SetMeanToExpected_Vcm_bu1();
		void SetMeanToExpected_Vcm_bu2();
		void SetMeanToExpected_KEcm_bu1();
		void SetMeanToExpected_KEcm_bu2();
		void SetMeanToExpected_Ecm();
		void SetMeanToExpected_All();

		//getters
		Nucleus GetBeamNucleus();
		Nucleus GetTargetNucleus();
		Nucleus GetEjectileNucleus();
		Nucleus GetRecoilNucleus();
		Nucleus GetBreakup1Nucleus();
		Nucleus GetBreakup2Nucleus();

		Double_t GetBeamMass();
		Double_t GetTargetMass();
		Double_t GetEjectileMass();
		Double_t GetRecoilMass();
		Double_t GetBreakup1Mass();
		Double_t GetBreakup2Mass();

		Double_t GetBeamEnergy();
		Double_t GetRecoilExE();

		Double_t GetExpectedVcm_bu1();
		Double_t GetExpectedVcm_bu2();
		Double_t GetExpectedKEcm_bu1();
		Double_t GetExpectedKEcm_bu2();
		Double_t GetExpectedEcm();

		CMConstant GetVcm_bu1();
		CMConstant GetVcm_bu2();
		CMConstant GetKEcm_bu1();
		CMConstant GetKEcm_bu2();
		CMConstant GetEcm();

		TString GetReactionString();
		TString GetBreakupString();

		//init reaction function
		void CalculateCMConstants();

		//IMM Event analysis function:
		std::pair<CaseResult,CaseResult> AnalyzeEventIMM(Double_t ejectileE, Double_t ejectileTheta, Double_t ejectilePhi, Double_t detected1E, Double_t detected1Theta, Double_t detected1Phi, Double_t detected2E, Double_t detected2Theta, Double_t detected2Phi);

		//MMM Event analysis function:
		std::pair<CaseResult,CaseResult> AnalyzeEventMMM(Double_t ejectileE, Double_t ejectileTheta, Double_t ejectilePhi, Double_t detectedE, Double_t detectedTheta, Double_t detectedPhi);

		//calculate Excitation energy of recoil from ejectile, beam, target information:
		Double_t AnalyzeEventCalculateRecoilExE(Double_t ejectileE, Double_t ejectileTheta, Double_t ejectilePhi);

		//parsing
		// std::vector<Nucleus> parseReactionString(const TString& reactionStr);

		//checkers
		bool CheckInBounds_Vcm_bu1(Double_t test);
		bool CheckInBounds_Vcm_bu2(Double_t test);
		bool CheckInBounds_KEcm_bu1(Double_t test);
		bool CheckInBounds_KEcm_bu2(Double_t test);
		bool CheckInBounds_Ecm(Double_t test);
		bool CheckInBounds_ThetaCMSum(Double_t test);
		bool CheckInBounds_PhiCMSep(Double_t test);

	private:
		//nuclear data
		Nucleus beam;
		Nucleus target;
		Nucleus ejectile;
		Nucleus recoil;
		Nucleus breakup1;
		Nucleus breakup2;

		//relevant reaction data
		Double_t beam_energy;//from experiment
		Double_t recoil_exE;//expected/from literature

		//Breakup CM Constants:
		// Double_t Vcm_bu1;		//constant from reaction
		// Double_t Vcm_bu2;		//constant from reaction
		// Double_t KEcm_bu1;		//constant from reaction
		// Double_t KEcm_bu2;		//constant from reaction
		// Double_t Ecm;			//constant from reaction

		CMConstant Vcm_bu1;
		CMConstant Vcm_bu2;
		CMConstant KEcm_bu1;
		CMConstant KEcm_bu2;
		CMConstant Ecm;
		CMConstant ThetaCMSum;
		CMConstant PhiCMSep;

		// Double_t ThetaCMSum;// = 180.;		//constant from reaction
		// Double_t PhiCMSep;// = 180.;		//constant from reaction

		//Breakup CM Constant Bounds: (bounds for checking if a value passes the check)
		// Double_t Vcm_bu1_bounds[2] = {0.,0.};//{min,max}
		// Double_t Vcm_bu2_bounds[2] = {0.,0.};//{min,max}
		// Double_t KEcm_bu1_bounds[2] = {0.,0.};//{min,max}
		// Double_t KEcm_bu2_bounds[2] = {0.,0.};//{min,max}
		// Double_t Ecm_bounds[2] = {0.,0.};//{min,max}
		// Double_t ThetaCMSum_bounds[2] = {0.,0.};//{min,max}
		// Double_t PhiCMSep_bounds[2] = {0.,0.};//{min,max}

		const Double_t degToRad = M_PI/180.;
		const Double_t radToDeg = 180./M_PI;

		//parsing
		// Nucleus parseNucleus(const TString& nucleusStr);

};

#endif