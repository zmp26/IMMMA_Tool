#ifndef IMMMA_TOOL_4_H
#define IMMMA_TOOL_4_H

#include "TString.h"
#include "TLorentzVector.h"
#include <cmath>

#endif//IMMMA_TOOL_4_H

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

struct CaseResult4{
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
	Double_t breakup1_LabAngleWRTVCM;
	Double_t breakup1_CMAngleWRTVCM;

	Double_t Vcm2;
	Double_t KEcm2;
	Double_t ThetaCM2;
	Double_t PhiCM2;
	Double_t ELab2;
	Double_t ThetaLab2;
	Double_t PhiLab2;
	Double_t breakup2_LabAngleWRTVCM;
	Double_t breakup2_CMAngleWRTVCM;

	Double_t Vcm3;
	Double_t KEcm3;
	Double_t ThetaCM3;
	Double_t PhiCM3;
	Double_t ELab3;
	Double_t ThetaLab3;
	Double_t PhiLab3;
	Double_t breakup3_LabAngleWRTVCM;
	Double_t breakup3_CMAngleWRTVCM;

	Double_t recInvMass;
	Double_t ejInvMass;
	Double_t bu1InvMass;
	Double_t bu2InvMass;
	Double_t bu3InvMass;

	Double_t Ecm;

	Double_t recoilExE;

	//note that CM1 == observedCM1 for MMM
	// and that CM2 == observedCM2 for MMM
	// and that CM3 == missingCM for MMM

	TString ToString(){
		return Form("\n\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf",Vcm1,KEcm1,ThetaCM1,PhiCM1,Vcm2,KEcm2,ThetaCM2,PhiCM2,Vcm3,KEcm3,ThetaCM3,PhiCM3,Ecm);
	}
};

struct CMConstant{
	Double_t expected;
	Double_t mean;
	Double_t lower;
	Double_t upper;
};


class IMMMA_Tool_4{
public:
	IMMMA_Tool_4();
	~IMMMA_Tool_4();

	TString reaction;//ex: 10B(3He,4He)9B		A(a,b)B
	TString breakup1;//ex: 9B->8Be+p 			B-> D + c (D = daughter, c = decay)
	TString breakup2;//ex: 8Be->4He+4He			D->d+e (D = daughter from above, d/e = decays)

	//setters
	void SetBeamNucleus(Int_t A, TString sym, Double_t mass);
	void SetTargetNucleus(Int_t A, TString sym, Double_t mass);
	void SetEjectileNucleus(Int_t A, TString sym, Double_t mass);
	void SetRecoilNucleus(Int_t A, TString sym, Double_t mass);
	void SetBreakup1Nucleus(Int_t A, TString sym, Double_t mass);//first decay step 			(c decay)
	void SetBreakup2Nucleus(Int_t A, TString sym, Double_t mass);//second decay step, bu1 		(d decay)
	void SetBreakup3Nucleus(Int_t A, TString sym, Double_t mass);//second decay step, bu2 		(e decay)

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
	TString GetBreakup1String();
	TString GetBreakup2String();

	void CalculateCMConstants();

	//IMM Event Analysis:
	std::array<CaseResult4, 6> AnalyzeIMMEvent(Double_t ejectileE, Double_t ejectileTheta, Double_t ejectilePhi,
								   Double_t detected1E, Double_t detected1Theta, Double_t detected1Phi,
								   Double_t detected2E, Double_t detected2Theta, Double_t detected2Phi,
								   Double_t detected3E, Double_t detected3Theta, Double_t detected3Phi);



private:
	const Double_t degToRad = M_PI/180.;
	const Double_t radToDeg = 180./M_PI;

	//IMM Event Analysis helper function:
	CaseResult4 CalculateCase(Double_t ejectileE, Double_t ejectileTheta, Double_t ejectilePhi,
							  Double_t detected1E, Double_t detected1Theta, Double_t detected1Phi,
							  Double_t detected2E, Double_t detected2Theta, Double_t detected2Phi,
							  Double_t detected3E, Double_t detected3Theta, Double_t detected3Phi);

	//helper function to calculate recoil excitation energy:
	Double_t AnalyzeEventCalculateRecoilExE(Double_t ejectileE, Double_t ejectileTheta, Double_t ejectilePhi);

};