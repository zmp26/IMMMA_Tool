#include "IMMMA_Tool_4.h"
#include "TLorentzVector.h"

IMMMA_Tool_4::IMMMA_Tool_4(){
	//default constructor
	ThetaCMSum1.expected = 180.;
	ThetaCMSum1.lower = 179.;
	ThetaCMSum1.upper = 181.;

	PhiCMSep1.expected = 180.;
	PhiCMSep1.lower = 179.;
	PhiCMSep1.upper = 181.;

	ThetaCMSum2.expected = 180.;
	ThetaCMSum2.lower = 179.;
	ThetaCMSum2.upper = 181.;

	PhiCMSep2.expected = 180.;
	PhiCMSep2.lower = 179.;
	PhiCMSep2.upper = 181.;
}

//setters:
void IMMMA_Tool_4::SetBeamNucleus(Int_t A, TString sym, Double_t mass){
	this->beam.A = A;
	this->beam.sym = sym;
	this->beam.mass = mass;
}

void IMMMA_Tool_4::SetTargetNucleus(Int_t A, TString sym, Double_t mass){
	this->target.A = A;
	this->target.sym = sym;
	this->target.mass = mass;
}

void IMMMA_Tool_4::SetEjectileNucleus(Int_t A, TString sym, Double_t mass){
	this->ejectile.A = A;
	this->ejectile.sym = sym;
	this->ejectile.mass = mass;
}

void IMMMA_Tool_4::SetRecoilNucleus(Int_t A, TString sym, Double_t mass){
	this->recoil.A = A;
	this->recoil.sym = sym;
	this->recoil.mass = mass;
}

void IMMMA_Tool_4::SetBreakup1Nucleus(Int_t A, TString sym, Double_t mass){
	this->breakup1.A = A;
	this->breakup1.sym = sym;
	this->breakup1.mass = mass;
}

void IMMMA_Tool_4::SetDaughter1Nucleus(Int_t A, TString sym, Double_t mass){
	this->daughter1.A = A;
	this->daughter1.sym = sym;
	this->daughter1.mass = mass;
}

void IMMMA_Tool_4::SetBreakup2Nucleus(Int_t A, TString sym, Double_t mass){
	this->breakup2.A = A;
	this->breakup2.sym = sym;
	this->breakup2.mass = mass;
}

void IMMMA_Tool_4::SetBreakup3Nucleus(Int_t A, TString sym, Double_t mass){
	this->breakup3.A = A;
	this->breakup3.sym = sym;
	this->breakup3.mass = mass;
}

void IMMMA_Tool_4::SetBeamEnergy(Double_t energy){
	this->beam_energy = energy;
}

void IMMMA_Tool_4::SetRecoilExE(Double_t energy){
	this->recoil_exE = energy;
}

void IMMMA_Tool_4::SetVcm_bu1_bounds(Double_t lower, Double_t upper){
	this->Vcm_bu1.lower = lower;
	this->Vcm_bu1.upper = upper;
}

void IMMMA_Tool_4::SetVcm_bu1_bounds(Double_t sigma){
	this->Vcm_bu1.lower = this->Vcm_bu1.mean - 2*sigma;
	this->Vcm_bu1.upper = this->Vcm_bu1.mean + 2*sigma;
}

void IMMMA_Tool_4::SetVcm_bu1_boundsp(Double_t lowerp, Double_t upperp){
	this->Vcm_bu1.lower = this->Vcm_bu1.mean*lowerp;
	this->Vcm_bu1.upper = this->Vcm_bu1.mean*upperp;
}

void IMMMA_Tool_4::SetVcm_bu2_bounds(Double_t lower, Double_t upper){
	this->Vcm_bu2.lower = lower;
	this->Vcm_bu2.upper = upper;
}

void IMMMA_Tool_4::SetVcm_bu2_bounds(Double_t sigma){
	this->Vcm_bu2.lower = this->Vcm_bu2.mean - 2*sigma;
	this->Vcm_bu2.upper = this->Vcm_bu2.mean + 2*sigma;
}

void IMMMA_Tool_4::SetVcm_bu2_boundsp(Double_t lowerp, Double_t upperp){
	this->Vcm_bu2.lower = this->Vcm_bu2.mean*lowerp;
	this->Vcm_bu2.upper = this->Vcm_bu2.mean*upperp;
}

void IMMMA_Tool_4::SetVcm_bu3_bounds(Double_t lower, Double_t upper){
	this->Vcm_bu3.lower = lower;
	this->Vcm_bu3.upper = upper;
}

void IMMMA_Tool_4::SetVcm_bu3_bounds(Double_t sigma){
	this->Vcm_bu3.lower = this->Vcm_bu3.mean - 2*sigma;
	this->Vcm_bu3.upper = this->Vcm_bu3.mean + 2*sigma;
}

void IMMMA_Tool_4::SetVcm_bu3_boundsp(Double_t lowerp, Double_t upperp){
	this->Vcm_bu3.lower = this->Vcm_bu3.mean*lowerp;
	this->Vcm_bu3.upper = this->Vcm_bu3.mean*upperp;
}

void IMMMA_Tool_4::SetKEcm_bu1_bounds(Double_t lower, Double_t upper){
	this->KEcm_bu1.lower = lower;
	this->KEcm_bu1.upper = upper;
}

void IMMMA_Tool_4::SetKEcm_bu1_bounds(Double_t sigma){
	this->KEcm_bu1.lower = this->KEcm_bu1.mean - 2*sigma;
	this->KEcm_bu1.upper = this->KEcm_bu1.mean + 2*sigma;
}

void IMMMA_Tool_4::SetKEcm_bu1_boundsp(Double_t lowerp, Double_t upperp){
	this->KEcm_bu1.lower = this->KEcm_bu1.mean*lowerp;
	this->KEcm_bu1.upper = this->KEcm_bu1.mean*upperp;
}

void IMMMA_Tool_4::SetKEcm_bu2_bounds(Double_t lower, Double_t upper){
	this->KEcm_bu2.lower = lower;
	this->KEcm_bu2.upper = upper;
}

void IMMMA_Tool_4::SetKEcm_bu2_bounds(Double_t sigma){
	this->KEcm_bu2.lower = this->KEcm_bu2.mean - 2*sigma;
	this->KEcm_bu2.upper = this->KEcm_bu2.mean + 2*sigma;
}

void IMMMA_Tool_4::SetKEcm_bu2_boundsp(Double_t lowerp, Double_t upperp){
	this->KEcm_bu2.lower = this->KEcm_bu2.mean*lowerp;
	this->KEcm_bu2.upper = this->KEcm_bu2.mean*upperp;
}

void IMMMA_Tool_4::SetKEcm_bu3_bounds(Double_t lower, Double_t upper){
	this->KEcm_bu3.lower = lower;
	this->KEcm_bu3.upper = upper;
}

void IMMMA_Tool_4::SetKEcm_bu3_bounds(Double_t sigma){
	this->KEcm_bu3.lower = this->KEcm_bu3.mean - 2*sigma;
	this->KEcm_bu3.upper = this->KEcm_bu3.mean + 2*sigma;
}

void IMMMA_Tool_4::SetKEcm_bu3_boundsp(Double_t lowerp, Double_t upperp){
	this->KEcm_bu3.lower = this->KEcm_bu3.mean*lowerp;
	this->KEcm_bu3.upper = this->KEcm_bu3.mean*upperp;
}

void IMMMA_Tool_4::SetEcm1_bounds(Double_t lower, Double_t upper){
	this->Ecm1.lower = lower;
	this->Ecm1.upper = upper;
}

void IMMMA_Tool_4::SetEcm1_bounds(Double_t sigma){
	this->Ecm1.lower = this->Ecm1.mean - 2*sigma;
	this->Ecm1.upper = this->Ecm1.mean + 2*sigma;
}

void IMMMA_Tool_4::SetEcm1_boundsp(Double_t lowerp, Double_t upperp){
	this->Ecm1.lower = this->Ecm1.mean*lowerp;
	this->Ecm1.upper = this->Ecm1.mean*upperp;
}

void IMMMA_Tool_4::SetEcm2_bounds(Double_t lower, Double_t upper){
	this->Ecm1.lower = lower;
	this->Ecm1.upper = upper;
}

void IMMMA_Tool_4::SetEcm2_bounds(Double_t sigma){
	this->Ecm1.lower = this->Ecm1.mean - 2*sigma;
	this->Ecm1.upper = this->Ecm1.mean + 2*sigma;
}

void IMMMA_Tool_4::SetEcm2_boundsp(Double_t lowerp, Double_t upperp){
	this->Ecm1.lower = this->Ecm1.mean*lowerp;
	this->Ecm1.upper = this->Ecm1.mean*upperp;
}

void IMMMA_Tool_4::SetMean_Vcm_bu1(Double_t mean){
	this->Vcm_bu1.mean = mean;
}

void IMMMA_Tool_4::SetMean_Vcm_bu2(Double_t mean){
	this->Vcm_bu2.mean = mean;
}

void IMMMA_Tool_4::SetMean_Vcm_bu3(Double_t mean){
	this->Vcm_bu2.mean = mean;
}

void IMMMA_Tool_4::SetMean_KEcm_bu1(Double_t mean){
	this->KEcm_bu1.mean = mean;
}

void IMMMA_Tool_4::SetMean_KEcm_bu2(Double_t mean){
	this->KEcm_bu2.mean = mean;
}

void IMMMA_Tool_4::SetMean_KEcm_bu3(Double_t mean){
	this->KEcm_bu3.mean = mean;
}

void IMMMA_Tool_4::SetMean_Ecm1(Double_t mean){
	this->Ecm1.mean = mean;
}

void IMMMA_Tool_4::SetMean_Ecm2(Double_t mean){
	this->Ecm2.mean = mean;
}

void IMMMA_Tool_4::SetMeanToExpected_Vcm_bu1(){
	this->Vcm_bu1.mean = this->Vcm_bu1.expected;
}

void IMMMA_Tool_4::SetMeanToExpected_Vcm_bu2(){
	this->Vcm_bu2.mean = this->Vcm_bu2.expected;
}

void IMMMA_Tool_4::SetMeanToExpected_Vcm_bu3(){
	this->Vcm_bu3.mean = this->Vcm_bu3.expected;
}

void IMMMA_Tool_4::SetMeanToExpected_KEcm_bu1(){
	this->KEcm_bu1.mean = this->KEcm_bu1.expected;
}

void IMMMA_Tool_4::SetMeanToExpected_KEcm_bu2(){
	this->KEcm_bu2.mean = this->KEcm_bu2.expected;
}

void IMMMA_Tool_4::SetMeanToExpected_KEcm_bu3(){
	this->KEcm_bu3.mean = this->KEcm_bu3.expected;
}

void IMMMA_Tool_4::SetMeanToExpected_Ecm1(){
	this->Ecm1.mean = this->Ecm1.expected;
}

void IMMMA_Tool_4::SetMeanToExpected_Ecm2(){
	this->Ecm2.mean = this->Ecm2.expected;
}

void IMMMA_Tool_4::SetMeanToExpected_All(){
	this->SetMeanToExpected_Vcm_bu1();
	this->SetMeanToExpected_Vcm_bu2();
	this->SetMeanToExpected_Vcm_bu3();
	this->SetMeanToExpected_KEcm_bu1();
	this->SetMeanToExpected_KEcm_bu2();
	this->SetMeanToExpected_KEcm_bu3();
	this->SetMeanToExpected_Ecm1();
	this->SetMeanToExpected_Ecm2();
}

//getters
Nucleus4 IMMMA_Tool_4::GetBeamNucleus(){
	return this->beam;
}

Nucleus4 IMMMA_Tool_4::GetTargetNucleus(){
	return this->target;
}

Nucleus4 IMMMA_Tool_4::GetEjectileNucleus(){
	return this->ejectile;
}

Nucleus4 IMMMA_Tool_4::GetRecoilNucleus(){
	return this->recoil;
}

Nucleus4 IMMMA_Tool_4::GetBreakup1Nucleus(){
	return this->breakup1;
}

Nucleus4 IMMMA_Tool_4::GetDaughter1Nucleus(){
	return this->daughter1;
}

Nucleus4 IMMMA_Tool_4::GetBreakup2Nucleus(){
	return this->breakup2;
}

Nucleus4 IMMMA_Tool_4::GetBreakup3Nucleus(){
	return this->breakup3;
}

Double_t IMMMA_Tool_4::GetBeamMass(){
	return this->beam.mass;
}

Double_t IMMMA_Tool_4::GetTargetMass(){
	return this->target.mass;
}

Double_t IMMMA_Tool_4::GetEjectileMass(){
	return this->ejectile.mass;
}

Double_t IMMMA_Tool_4::GetRecoilMass(){
	return this->recoil.mass;
}

Double_t IMMMA_Tool_4::GetBreakup1Mass(){
	return this->breakup1.mass;
}

Double_t IMMMA_Tool_4::GetDaughter1Mass(){
	return this->daughter1.mass;
}

Double_t IMMMA_Tool_4::GetBreakup2Mass(){
	return this->breakup2.mass;
}

Double_t IMMMA_Tool_4::GetBreakup3Mass(){
	return this->breakup3.mass;
}

Double_t IMMMA_Tool_4::GetBeamEnergy(){
	return this->beam_energy;
}

Double_t IMMMA_Tool_4::GetRecoilExE(){
	return this->recoil_exE;
}

Double_t IMMMA_Tool_4::GetExpectedVcm_bu1(){
	return this->Vcm_bu1.expected;
}

Double_t IMMMA_Tool_4::GetExpectedVcm_bu2(){
	return this->Vcm_bu2.expected;
}

Double_t IMMMA_Tool_4::GetExpectedVcm_bu3(){
	return this->Vcm_bu3.expected;
}


Double_t IMMMA_Tool_4::GetExpectedKEcm_bu1(){
	return this->KEcm_bu1.expected;
}

Double_t IMMMA_Tool_4::GetExpectedKEcm_bu2(){
	return this->KEcm_bu2.expected;
}

Double_t IMMMA_Tool_4::GetExpectedKEcm_bu3(){
	return this->KEcm_bu3.expected;
}

Double_t IMMMA_Tool_4::GetExpectedEcm1(){
	return this->Ecm1.expected;
}

Double_t IMMMA_Tool_4::GetExpectedEcm2(){
	return this->Ecm2.expected;
}

CMConstant4 IMMMA_Tool_4::GetVcm_bu1(){
	return this->Vcm_bu1;
}

CMConstant4 IMMMA_Tool_4::GetVcm_bu2(){
	return this->Vcm_bu2;
}

CMConstant4 IMMMA_Tool_4::GetVcm_bu3(){
	return this->Vcm_bu3;
}

CMConstant4 IMMMA_Tool_4::GetKEcm_bu1(){
	return this->KEcm_bu1;
}

CMConstant4 IMMMA_Tool_4::GetKEcm_bu2(){
	return this->KEcm_bu2;
}

CMConstant4 IMMMA_Tool_4::GetKEcm_bu3(){
	return this->KEcm_bu3;
}

CMConstant4 IMMMA_Tool_4::GetEcm1(){
	return this->Ecm1;
}

CMConstant4 IMMMA_Tool_4::GetEcm2(){
	return this->Ecm2;
}

TString IMMMA_Tool_4::GetReactionString(){
	return this->reaction;
}

TString IMMMA_Tool_4::GetBreakup1String(){
	return this->breakup1str;
}

TString IMMMA_Tool_4::GetBreakup2String(){
	return this->breakup2str;
}


//checkers
bool IMMMA_Tool_4::CheckInBounds_Vcm_bu1(Double_t test){
	return (this->Vcm_bu1.lower <= test && this->Vcm_bu1.upper >= test);
}

bool IMMMA_Tool_4::CheckInBounds_Vcm_bu2(Double_t test){
	return (this->Vcm_bu2.lower <= test && this->Vcm_bu2.upper >= test);
}

bool IMMMA_Tool_4::CheckInBounds_Vcm_bu3(Double_t test){
	return (this->Vcm_bu3.lower <= test && this->Vcm_bu3.upper >= test);
}

bool IMMMA_Tool_4::CheckInBounds_KEcm_bu1(Double_t test){
	return (this->KEcm_bu1.lower <= test && this->KEcm_bu1.upper >= test);
}

bool IMMMA_Tool_4::CheckInBounds_KEcm_bu2(Double_t test){
	return (this->KEcm_bu2.lower <= test && this->KEcm_bu2.upper >= test);
}

bool IMMMA_Tool_4::CheckInBounds_KEcm_bu3(Double_t test){
	return (this->KEcm_bu3.lower <= test && this->KEcm_bu3.upper >= test);
}

bool IMMMA_Tool_4::CheckInBounds_Ecm1(Double_t test){
	return (this->Ecm1.lower <= test && this->Ecm1.upper >= test);
}

bool IMMMA_Tool_4::CheckInBounds_Ecm2(Double_t test){
	return (this->Ecm2.lower <= test && this->Ecm2.upper >= test);
}

bool IMMMA_Tool_4::CheckInBounds_ThetaCMSum1(Double_t test){
	return (this->ThetaCMSum1.lower <= test && this->ThetaCMSum1.upper >= test);
}

bool IMMMA_Tool_4::CheckInBounds_ThetaCMSum2(Double_t test){
	return (this->ThetaCMSum2.lower <= test && this->ThetaCMSum2.upper >= test);
}

bool IMMMA_Tool_4::CheckInBounds_PhiCMSep1(Double_t test){
	return (this->PhiCMSep1.lower <= test && this->PhiCMSep1.upper >= test);
}

bool IMMMA_Tool_4::CheckInBounds_PhiCMSep2(Double_t test){
	return (this->PhiCMSep2.lower <= test && this->PhiCMSep2.upper >= test);
}


//init reaction function
void IMMMA_Tool_4::CalculateCMConstants(){
	if(this->recoil.Filled() && this->breakup1.Filled() && this->breakup2.Filled()){
		this->Ecm1.expected = this->recoil.mass + this->recoil_exE - this->breakup1.mass - this->daughter1.mass;
		this->Ecm2.expected = this->daughter1.mass - this->breakup2.mass - this->breakup3.mass;
		this->Vcm_bu1.expected = sqrt(2*(this->recoil.mass+this->recoil_exE)*this->Ecm1.expected/(this->breakup1.mass*(this->breakup1.mass + this->recoil.mass + this->recoil_exE)));//in CM frame of first break up (so recoil and 1 back to back)
		this->Vcm_bu2.expected = sqrt(2*this->breakup3.mass*this->Ecm2.expected/(this->breakup2.mass*(this->breakup2.mass + this->breakup3.mass)));//in CM frame of last break up (so 2, 3 back to back)
		this->Vcm_bu3.expected = sqrt(2*this->breakup2.mass*this->Ecm2.expected/(this->breakup3.mass*(this->breakup2.mass + this->breakup3.mass)));//in CM frame of last break up (so 2, 3 back to back)
		this->KEcm_bu1.expected = 0.5*this->breakup1.mass*this->Vcm_bu1.expected*this->Vcm_bu1.expected;//in CM frame of first break up (so recoil and 1 back to back)
		this->KEcm_bu2.expected = 0.5*this->breakup2.mass*this->Vcm_bu2.expected*this->Vcm_bu2.expected;//in CM frame of last break up (so 2, 3 back to back)
		this->KEcm_bu3.expected = 0.5*this->breakup3.mass*this->Vcm_bu3.expected*this->Vcm_bu3.expected;//in CM frame of last break up (so 2, 3 back to back)

		this->reaction = Form("%d%s(%d%s,%d%s)%d%s",this->target.A,this->target.sym.Data(),this->beam.A,this->beam.sym.Data(),this->ejectile.A,this->ejectile.sym.Data(),this->recoil.A,this->recoil.sym.Data());
		this->breakup1str = Form("%d%s ---> %d%s + %d%s",this->recoil.A,this->recoil.sym.Data(), this->daughter1.A, this->daughter1.sym.Data(), this->breakup2.A, this->breakup2.sym.Data());
		this->breakup2str = Form("%d%s ---> %d%s + %d%s",this->daughter1.A, this->daughter1.sym.Data(), this->breakup2.A, this->breakup2.sym.Data(), this->breakup3.A, this->breakup3.sym.Data());

		//set means to expected -> these can be updated by the user in their macro by calling IMMMA_Tool_4::SetMean_Vcm_bu1(), etc...
		this->Ecm1.mean = this->Ecm1.expected;
		this->Ecm2.mean = this->Ecm2.expected;
		this->Vcm_bu1.mean = this->Vcm_bu1.expected;
		this->Vcm_bu2.mean = this->Vcm_bu2.expected;
		this->Vcm_bu3.mean = this->Vcm_bu3.expected;
		this->KEcm_bu1.mean = this->KEcm_bu1.expected;
		this->KEcm_bu2.mean = this->KEcm_bu2.expected;
		this->KEcm_bu3.mean = this->KEcm_bu3.expected;
	} else {
		this->Ecm1.expected = -666;
		this->Ecm2.expected = -666;
		this->Vcm_bu1.expected = -666;
		this->Vcm_bu2.expected = -666;
		this->Vcm_bu3.expected = -666;
		this->KEcm_bu1.expected = -666;
		this->KEcm_bu2.expected = -666;
		this->KEcm_bu3.expected = -666;

		this->reaction = "null";
		this->breakup1str = "null";
		this->breakup2str = "null";

		//set means to expected -> these can be updated by the user in their macro by calling IMMMA_Tool_4::SetMean_Vcm_bu1(), etc...
		this->Ecm1.mean = this->Ecm1.expected;
		this->Ecm2.mean = this->Ecm2.expected;
		this->Vcm_bu1.mean = this->Vcm_bu1.expected;
		this->Vcm_bu2.mean = this->Vcm_bu2.expected;
		this->Vcm_bu3.mean = this->Vcm_bu3.expected;
		this->KEcm_bu1.mean = this->KEcm_bu1.expected;
		this->KEcm_bu2.mean = this->KEcm_bu2.expected;
		this->KEcm_bu3.mean = this->KEcm_bu3.expected;
	}
}

std::array<CaseResult4, 6> IMMMA_Tool_4::AnalyzeIMMEvent(Double_t ejectileE, Double_t ejectileTheta, Double_t ejectilePhi,
								   Double_t detected1E, Double_t detected1Theta, Double_t detected1Phi,
								   Double_t detected2E, Double_t detected2Theta, Double_t detected2Phi,
								   Double_t detected3E, Double_t detected3Theta, Double_t detected3Phi)
{

	std::array<CaseResult4, 6> results;

	Double_t cE, cTheta, cPhi, dE, dTheta, dPhi, eE, eTheta, ePhi;
	
	CaseResult4 case1, case2, case3, case4, case5, case6;

	/*******************************************************
	 * 										  			   *
	 *					  CASE I BELOW:				 	   *
	 * 				  c = kin4mc particle 2 = det1		   *
	 * 				  d = kin4mc particle 3 = det2		   *
	 * 				  e = kin4mc particle 4 = det3		   *
	 * 										  			   *
	 *******************************************************/
	//in this case, we assume we detect the ejectile and three particles we assume to be the resonance decay particles
	//case 1 is the case in which detected1 uses mass information from breakup1
	//						  and detected2 uses mass information from breakup2
	//						  and detected3 uses mass information from breakup3

	cE = detected1E;
	cTheta = detected1Theta;
	cPhi = detected1Phi;

	dE = detected2E;
	dTheta = detected2Theta;
	dPhi = detected2Phi;

	eE = detected3E;
	eTheta = detected3Theta;
	ePhi = detected3Phi;

	case1 = CalculateCase(ejectileE, ejectileTheta, ejectilePhi,
						  cE, cTheta, cPhi,
						  dE, dTheta, dPhi,
						  eE, eTheta, ePhi);
	results[0] = case1;

	/*******************************************************
	 * 										  			   *
	 *					  CASE II BELOW:				   *
	 * 				  c = kin4mc particle 2 = det1 		   *
	 * 				  d = kin4mc particle 4 = det3 		   *
	 * 				  e = kin4mc particle 3 = det2 		   *
	 * 										  			   *
	 *******************************************************/
	//in this case, we assume we detect the ejectile and three particles we assume to be the resonance decay particles
	//case 2 is the case in which detected1 uses mass information from breakup1
	//						  and detected2 uses mass information from breakup3
	//						  and detected3 uses mass information from breakup2

	cE = detected1E;
	cTheta = detected1Theta;
	cPhi = detected1Phi;

	dE = detected3E;
	dTheta = detected3Theta;
	dPhi = detected3Phi;

	eE = detected2E;
	eTheta = detected2Theta;
	ePhi = detected2Phi;

	case2 = CalculateCase(ejectileE, ejectileTheta, ejectilePhi,
						  cE, cTheta, cPhi,
						  dE, dTheta, dPhi,
						  eE, eTheta, ePhi);
	results[1] = case2;

	/*******************************************************
	 * 										  			   *
	 *					 CASE III BELOW:			 	   *
	 * 				  c = kin4mc particle 3 = det2		   *
	 * 				  d = kin4mc particle 2 = det1 		   *
	 * 				  e = kin4mc particle 4 = det3 		   *
	 * 										  			   *
	 *******************************************************/
	//in this case, we assume we detect the ejectile and three particles we assume to be the resonance decay particles
	//case 3 is the case in which detected1 uses mass information from breakup2
	//						  and detected2 uses mass information from breakup1
	//						  and detected3 uses mass information from breakup3

	cE = detected2E;
	cTheta = detected2Theta;
	cPhi = detected2Phi;

	dE = detected1E;
	dTheta = detected1Theta;
	dPhi = detected1Phi;

	eE = detected3E;
	eTheta = detected3Theta;
	ePhi = detected3Phi;

	case3 = CalculateCase(ejectileE, ejectileTheta, ejectilePhi,
						  cE, cTheta, cPhi,
						  dE, dTheta, dPhi,
						  eE, eTheta, ePhi);
	results[2] = case3;

	/*******************************************************
	 * 										  			   *
	 *					  CASE IV BELOW:				   *
	 * 				  c = kin4mc particle 3 = det2		   *
	 * 				  d = kin4mc particle 4 = det3		   *
	 * 				  e = kin4mc particle 2 = det1		   *
	 * 										  			   *
	 *******************************************************/
	//case 4 is the case in which detected1 uses mass information from breakup2
	//						  and detected2 uses mass information from breakup3
	//						  and detected3 uses mass information from breakup1

	cE = detected2E;
	cTheta = detected2Theta;
	cPhi = detected2Phi;

	dE = detected3E;
	dTheta = detected3Theta;
	dPhi = detected3Phi;

	eE = detected1E;
	eTheta = detected1Theta;
	ePhi = detected1Phi;

	case4 = CalculateCase(ejectileE, ejectileTheta, ejectilePhi,
						  cE, cTheta, cPhi,
						  dE, dTheta, dPhi,
						  eE, eTheta, ePhi);
	results[3] = case4;

	/*******************************************************
	 * 										  			   *
	 *					  CASE V BELOW:				  	   *
	 * 				  c = kin4mc particle 4 = det3		   *
	 * 				  d = kin4mc particle 2 = det1		   *
	 * 				  e = kin4mc particle 3 = det2		   *
	 * 										  			   *
	 *******************************************************/
	//case 5 is the case in which detected1 uses mass information from breakup3
	//						  and detected2 uses mass information from breakup1
	//						  and detected3 uses mass information from breakup2

	cE = detected3E;
	cTheta = detected3Theta;
	cPhi = detected3Phi;

	dE = detected1E;
	dTheta = detected1Theta;
	dPhi = detected1Phi;

	eE = detected2E;
	eTheta = detected2Theta;
	ePhi = detected2Phi;

	case5 = CalculateCase(ejectileE, ejectileTheta, ejectilePhi,
						  cE, cTheta, cPhi,
						  dE, dTheta, dPhi,
						  eE, eTheta, ePhi);
	results[4] = case5;

	/*******************************************************
	 * 										  			   *
	 *					  CASE VI BELOW:				   *
	 * 				  c = kin4mc particle 4 = det3		   *
	 * 				  d = kin4mc particle 3 = det2		   *
	 * 				  e = kin4mc particle 2 = det1		   *
	 * 										  			   *
	 *******************************************************/
	//case 6 is the case in which detected1 uses mass information from breakup3
	//						  and detected2 uses mass information from breakup2
	//						  and detected3 uses mass information from breakup1

	cE = detected3E;
	cTheta = detected3Theta;
	cPhi = detected3Phi;

	dE = detected2E;
	dTheta = detected2Theta;
	dPhi = detected2Phi;

	eE = detected1E;
	eTheta = detected1Theta;
	ePhi = detected1Phi;

	case6 = CalculateCase(ejectileE, ejectileTheta, ejectilePhi,
						  cE, cTheta, cPhi,
						  dE, dTheta, dPhi,
						  eE, eTheta, ePhi);
	results[5] = case6;

	//*******************************************************

	//finished computing all 6 cases, now return!
	return results;
}


Double_t IMMMA_Tool_4::AnalyzeEventCalculateRecoilExE(Double_t ejectileE, Double_t ejectileTheta, Double_t ejectilePhi){
	
	TLorentzVector beam, target, ejectile, recoil;

	beam.SetPxPyPzE(0.,0.,sqrt(2*this->beam_energy*this->beam.mass),this->beam_energy+this->beam.mass);
	target.SetPxPyPzE(0.,0.,0.,this->target.mass);
	Double_t pej = sqrt(2*ejectileE*this->ejectile.mass);
	ejectile.SetPxPyPzE(pej*sin(degToRad*ejectileTheta)*cos(degToRad*ejectilePhi), pej*sin(degToRad*ejectileTheta)*sin(degToRad*ejectilePhi), pej*cos(degToRad*ejectileTheta), this->ejectile.mass+ejectileE);

	recoil = beam + target - ejectile;

	return (recoil.M() - this->recoil.mass);

}

//below function holds the main logic to be used in AnalyzeIMMEvent to avoid explicitly rewriting the same code for all 6 cases
CaseResult4 IMMMA_Tool_4::CalculateCase(Double_t ejectileE, Double_t ejectileTheta, Double_t ejectilePhi,
								   		Double_t detected1E, Double_t detected1Theta, Double_t detected1Phi,
								   		Double_t detected2E, Double_t detected2Theta, Double_t detected2Phi,
								   		Double_t detected3E, Double_t detected3Theta, Double_t detected3Phi)
{

	TLorentzVector beam_4vect, target_4vect, ejectile_4vect, recoil_4vect, breakup1_4vect, breakup2_4vect, breakup3_4vect;

	CaseResult4 result;

	//calculate momenta:
	Double_t plab_detected1 = sqrt(2*detected1E*this->breakup1.mass);
	Double_t plab_detected2 = sqrt(2*detected2E*this->breakup2.mass);
	Double_t plab_detected3 = sqrt(2*detected3E*this->breakup3.mass);

	Double_t plab_ej = sqrt(2*ejectileE*this->ejectile.mass);
	Double_t plab_beam = sqrt(2*this->beam_energy*this->beam.mass);
	Double_t plab_target = 0.;

	//initialize 4vectors from the above information:
	beam_4vect.SetPxPyPzE(0.,0.,plab_beam,this->beam.mass+this->beam_energy);
	target_4vect.SetPxPyPzE(0.,0.,0.,this->target.mass);

	ejectile_4vect.SetPxPyPzE(plab_ej*sin(degToRad*ejectileTheta)*cos(degToRad*ejectilePhi),
							  plab_ej*sin(degToRad*ejectileTheta)*sin(degToRad*ejectilePhi),
							  plab_ej*cos(degToRad*ejectileTheta),
							  this->ejectile.mass+ejectileE);

	breakup1_4vect.SetPxPyPzE(plab_detected1*sin(degToRad*detected1Theta)*cos(degToRad*detected1Phi),
							  plab_detected1*sin(degToRad*detected1Theta)*sin(degToRad*detected1Phi),
							  plab_detected1*cos(degToRad*detected1Theta),
							  this->breakup1.mass+detected1E);

	breakup2_4vect.SetPxPyPzE(plab_detected2*sin(degToRad*detected2Theta)*cos(degToRad*detected2Phi),
							  plab_detected2*sin(degToRad*detected2Theta)*sin(degToRad*detected2Phi),
							  plab_detected2*cos(degToRad*detected2Theta),
							  this->breakup2.mass+detected2E);

	breakup3_4vect.SetPxPyPzE(plab_detected3*sin(degToRad*detected3Theta)*cos(degToRad*detected3Phi),
							  plab_detected3*sin(degToRad*detected3Theta)*sin(degToRad*detected3Phi),
							  plab_detected3*cos(degToRad*detected3Theta),
							  this->breakup3.mass+detected3E);

	//reconstruct recoil_4vect using beam, target, and ejectile information:
	//recoil_4vect = beam_4vect + target_4vect - ejectile_4vect;
	//recontruct recoil_4vect using bu1, bu2, and bu3 information:
	recoil_4vect = breakup1_4vect + breakup2_4vect + breakup3_4vect;

	//calculate the excitation energy of the recoil:
	Double_t recoil_ExcessEnergy = recoil_4vect.M() - this->recoil.mass; // entirely due to excitation!

	//calculate breakup angle in lab:
	//(between 3, 4, so final break up particles)
	Double_t breakupAngleLab = radToDeg*acos(breakup2_4vect.Vect().Dot(breakup3_4vect.Vect())/(breakup2_4vect.Vect().Mag()*breakup3_4vect.Vect().Mag()));

	Double_t thetalab2 = radToDeg*acos(breakup2_4vect.Vect().Z()/breakup2_4vect.Vect().Mag());
	Double_t philab2 = radToDeg*atan2(breakup2_4vect.Vect().Y(), breakup2_4vect.Vect().X());

	//obtain the boost vector to boost into the breakup CM frame:
	TVector3 boostvector = (-1/recoil_4vect.Energy())*recoil_4vect.Vect();

	//calculate angle between break up particles in the lab and the CM velocity vector (-boost vector)
	Double_t breakup1_LabAngleWRTVCM = radToDeg*breakup1_4vect.Vect().Angle(-boostvector);
	Double_t breakup2_LabAngleWRTVCM = radToDeg*breakup2_4vect.Vect().Angle(-boostvector);
	Double_t breakup3_LabAngleWRTVCM = radToDeg*breakup3_4vect.Vect().Angle(-boostvector);
	
	//boost!
	breakup1_4vect.Boost(boostvector);
	breakup2_4vect.Boost(boostvector);
	breakup3_4vect.Boost(boostvector);

	//calculate angle between break up particles in the CM frame and the CM velocity vector:
	Double_t breakup1_CMAngleWRTVCM = radToDeg*breakup1_4vect.Vect().Angle(-boostvector);
	Double_t breakup2_CMAngleWRTVCM = radToDeg*breakup2_4vect.Vect().Angle(-boostvector);
	Double_t breakup3_CMAngleWRTVCM = radToDeg*breakup3_4vect.Vect().Angle(-boostvector);

	//calculate CM variables from the boosted vectors
	Double_t vcm1 = ((1/breakup1_4vect.Energy())*breakup1_4vect.Vect()).Mag();
	Double_t vcm2 = ((1/breakup2_4vect.Energy())*breakup2_4vect.Vect()).Mag();
	Double_t vcm3 = ((1/breakup3_4vect.Energy())*breakup3_4vect.Vect()).Mag();

	Double_t kecm1 = 0.5*this->breakup1.mass*vcm1*vcm1;
	Double_t kecm2 = 0.5*this->breakup2.mass*vcm2*vcm2;
	Double_t kecm3 = 0.5*this->breakup3.mass*vcm3*vcm3;

	Double_t ecm = kecm1 + kecm2 + kecm3;

	Double_t theta1 = radToDeg*acos(breakup1_4vect.Vect().Z()/breakup1_4vect.Vect().Mag());
	Double_t phi1 = radToDeg*atan2(breakup1_4vect.Vect().Y(),breakup1_4vect.Vect().X());
	if(phi1 < 0) phi1 += 360.;

	Double_t theta2 = radToDeg*acos(breakup2_4vect.Vect().Z()/breakup2_4vect.Vect().Mag());
	Double_t phi2 = radToDeg*atan2(breakup2_4vect.Vect().Y(),breakup2_4vect.Vect().X());
	if(phi2 < 0) phi2 += 360.; 

	Double_t theta3 = radToDeg*acos(breakup3_4vect.Vect().Z()/breakup3_4vect.Vect().Mag());
	Double_t phi3 = radToDeg*atan2(breakup3_4vect.Vect().Y(),breakup3_4vect.Vect().X());
	if(phi3 < 0) phi3 += 360.;

	//fill result:
	result.boostvector = boostvector;

	result.Vcm1 = vcm1;
	result.KEcm1 = kecm1;
	result.ThetaCM1 = theta1;
	result.PhiCM1 = phi1;
	result.ELab1 = detected1E;
	result.ThetaLab1 = detected1Theta;
	result.PhiLab1 = detected1Phi;
	result.breakup1_LabAngleWRTVCM = breakup1_LabAngleWRTVCM;
	result.breakup1_CMAngleWRTVCM = breakup1_CMAngleWRTVCM;

	result.Vcm2 = vcm2;
	result.KEcm2 = kecm2;
	result.ThetaCM2 = theta2;
	result.PhiCM2 = phi2;
	result.ELab2 = detected2E;
	result.ThetaLab2 = detected2Theta;
	result.PhiLab2 = detected2Phi;
	result.breakup2_LabAngleWRTVCM = breakup2_LabAngleWRTVCM;
	result.breakup2_CMAngleWRTVCM = breakup2_CMAngleWRTVCM;

	result.Vcm3 = vcm3;
	result.KEcm3 = kecm3;
	result.ThetaCM3 = theta3;
	result.PhiCM3 = phi3;
	result.ELab3 = detected3E;
	result.ThetaLab3 = detected3Theta;
	result.PhiLab3 = detected3Phi;
	result.breakup3_LabAngleWRTVCM = breakup3_LabAngleWRTVCM;
	result.breakup3_CMAngleWRTVCM = breakup3_CMAngleWRTVCM;

	result.Ecm = ecm;

	result.recoilExE = recoil_ExcessEnergy;

	result.recInvMass = recoil_4vect.M();
	result.ejInvMass = ejectile_4vect.M();
	result.bu1InvMass = breakup1_4vect.M();
	result.bu2InvMass = breakup2_4vect.M();
	result.bu3InvMass = breakup3_4vect.M();

	return result;
}