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

	//Double_t cE, cTheta, cPhi, cMass, dE, dTheta, dPhi, dMass, eE, eTheta, ePhi, eMass;
	DetectedParticle4 ej = {ejectileE, ejectileTheta, ejectilePhi, this->ejectile.mass};
	DetectedParticle4 det1 = {detected1E, detected1Theta, detected1Phi, 0.};//mass set to 0 here but updated in case definitions below!!!!!
	DetectedParticle4 det2 = {detected2E, detected2Theta, detected2Phi, 0.};//mass set to 0 here but updated in case definitions below!!!!!
	DetectedParticle4 det3 = {detected3E, detected3Theta, detected3Phi, 0.};//mass set to 0 here but updated in case definitions below!!!!!

	std::vector<std::tuple<DetectedParticle4, DetectedParticle4, DetectedParticle4>> permutations = {


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
		//case1:
		{ {det1.E, det1.Theta, det1.Phi, this->breakup1.mass},
		  {det2.E, det2.Theta, det2.Phi, this->breakup2.mass},
		  {det3.E, det3.Theta, det3.Phi, this->breakup3.mass}
		},


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
		//case2:
		{ {det1.E, det1.Theta, det1.Phi, this->breakup1.mass},
		  {det3.E, det3.Theta, det3.Phi, this->breakup2.mass},
		  {det2.E, det2.Theta, det2.Phi, this->breakup3.mass}
		},


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
		//case3:
		{ {det2.E, det2.Theta, det2.Phi, this->breakup1.mass},
		  {det1.E, det1.Theta, det1.Phi, this->breakup2.mass},
		  {det3.E, det3.Theta, det3.Phi, this->breakup3.mass}
		},


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
		//case4:
		{ {det2.E, det2.Theta, det2.Phi, this->breakup1.mass},
		  {det3.E, det3.Theta, det3.Phi, this->breakup2.mass},
		  {det1.E, det1.Theta, det1.Phi, this->breakup3.mass}
		},


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
		//case5:
		{ {det3.E, det3.Theta, det3.Phi, this->breakup1.mass},
		  {det1.E, det1.Theta, det1.Phi, this->breakup2.mass},
		  {det2.E, det2.Theta, det2.Phi, this->breakup3.mass}
		},


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
		//case6:
		{ {det3.E, det3.Theta, det3.Phi, this->breakup1.mass},
		  {det2.E, det2.Theta, det2.Phi, this->breakup2.mass},
		  {det1.E, det1.Theta, det1.Phi, this->breakup3.mass}
		}
	};

	
	//loop through permutations and try every case!
	// int i=0;
	// for(const auto& [bu1, bu2, bu3] : permutations){ 
	// 	results[i++] = CalculateCaseIMM(ej, bu1, bu2, bu3);
	// }

	for(size_t i=0; i<permutations.size(); i++){
		results[i] = CalculateCaseIMM(ej, get<0>(permutations[i]), get<1>(permutations[i]), get<2>(permutations[i]));
	}

	// for(const auto& [bu1, bu2, bu3] : permutations){
	// 	std::cout << "permutation: [" << bu1, << ", " << bu2 << ", " << bu3 << "]\n";
	// 	}

	//finished computing all 6 cases, now return!
	return results;
}

std::array<CaseResult4, 6> IMMMA_Tool_4::AnalyzeMMMEvent(Double_t ejectileE, Double_t ejectileTheta, Double_t ejectilePhi,
														 Double_t detected1E, Double_t detected1Theta, Double_t detected1Phi,
														 Double_t detected2E, Double_t detected2Theta, Double_t detected2Phi)
{

	
	TLorentzVector beam_4vect, target_4vect, ejectile_4vect, recoil_4vect, daughter1_4vect, observed1_4vect, observed2_4vect, missing_4vect;
	CaseResult4 case1, case2;

	/*******************************************************
	 *					  CASE I BELOW:				 	   *
	 *******************************************************/
	//assume the missing mass is    --->   break up 1
	//assume the detected1 mass is  --->   break up 2
	//assume the detected2 mass is  --->   break up 3

	Double_t mass_missing = this->breakup1.mass;

	Double_t mass_observed1 = this->breakup2.mass;
	Double_t Elab_observed1 = detected1E;
	Double_t Thetalab_observed1 = detected1Theta;
	Double_t Philab_observed1 = detected1Phi;
	Double_t plab_observed1 = sqrt(2*Elab_observed1*mass_observed1);


	Double_t mass_observed2 = this->breakup3.mass;
	Double_t Elab_observed2 = detected2E;
	Double_t Thetalab_observed2 = detected2Theta;
	Double_t Philab_observed2 = detected2Phi;
	Double_t plab_observed2 = sqrt(2*Elab_observed2*mass_observed2);

	Double_t plab_ej = sqrt(2*ejectileE*this->ejectile.mass);
	Double_t plab_beam = sqrt(2*this->beam_energy*this->beam.mass);
	Double_t plab_target = 0.;

	beam_4vect.SetPxPyPzE(0., 0., plab_beam, this->beam.mass+this->beam_energy);
	target_4vect.SetPxPyPzE(0., 0., 0., this->target.mass);
	ejectile_4vect.SetPxPyPzE(plab_ej*sin(degToRad*ejectileTheta)*cos(degToRad*ejectilePhi), plab_ej*sin(degToRad*ejectileTheta)*sin(degToRad*ejectilePhi), plab_ej*cos(degToRad*ejectileTheta), this->ejectile.mass+ejectileE);
	observed1_4vect.SetPxPyPzE(plab_observed1*sin(degToRad*Thetalab_observed1)*cos(degToRad*Philab_observed1), plab_observed1*sin(degToRad*Thetalab_observed1)*sin(degToRad*Philab_observed1), plab_observed1*cos(degToRad*Thetalab_observed1), mass_observed1+Elab_observed1);
	observed2_4vect.SetPxPyPzE(plab_observed2*sin(degToRad*Thetalab_observed2)*cos(degToRad*Philab_observed2), plab_observed2*sin(degToRad*Thetalab_observed2)*sin(degToRad*Philab_observed2), plab_observed2*cos(degToRad*Thetalab_observed2), mass_observed2+Elab_observed2);

	recoil_4vect = beam_4vect + target_4vect - ejectile_4vect;
	missing_4vect = recoil_4vect - observed1_4vect - observed2_4vect;
	daughter1_4vect = observed1_4vect + observed2_4vect;

	Double_t missing_4vect_thetalab = radToDeg*acos(missing_4vect.Vect().Z()/missing_4vect.Vect().Mag());
	Double_t missing_4vect_philab = radToDeg*atan2(missing_4vect.Vect().Y(), missing_4vect.Vect().X());

	TVector3 boostvector1 = (-1/recoil_4vect.Energy())*recoil_4vect.Vect();
	TVector3 boostvector2 = (-1/daughter1_4vect.Energy())*daughter1_4vect.Vect();

	//Double_t recoil_ExcessEnergy = recoil_4vect.M() - this->recoil.mass;
	Double_t recoil_ExcessEnergy = recoil_4vect.M() - this->recoil.mass;

	//calculate breakup angle in lab:
	Double_t breakupAngleLab = radToDeg*acos(observed2_4vect.Vect().Dot(observed1_4vect.Vect())/(observed2_4vect.Vect().Mag()*observed1_4vect.Vect().Mag()));

	Double_t thetalab2 = radToDeg*acos(observed2_4vect.Vect().Z()/observed2_4vect.Vect().Mag());
	Double_t philab2 = radToDeg*atan2(observed2_4vect.Vect().Y(), observed2_4vect.Vect().X());

	Double_t breakup1_LabAngleWRTVCM = radToDeg*observed1_4vect.Vect().Angle(-boostvector1);
	Double_t breakup2_LabAngleWRTVCM = radToDeg*observed2_4vect.Vect().Angle(-boostvector2);
	Double_t breakup3_LabAngleWRTVCM = radToDeg*missing_4vect.Vect().Angle(-boostvector2);

	//boost!
	observed1_4vect.Boost(boostvector1);
	observed2_4vect.Boost(boostvector2);
	missing_4vect.Boost(boostvector2);

	//calculate angle between breakup particles in CM frame
	Double_t breakup1_CMAngleWRTVCM = radToDeg*missing_4vect.Vect().Angle(-boostvector1);
	Double_t breakup2_CMAngleWRTVCM = radToDeg*observed1_4vect.Vect().Angle(-boostvector2);
	Double_t breakup3_CMAngleWRTVCM = radToDeg*observed2_4vect.Vect().Angle(-boostvector2);

	Double_t vcmrec = ((1/recoil_4vect.Energy())*recoil_4vect.Vect()).Mag();
	Double_t vcm1 = ((1/missing_4vect.Energy())*missing_4vect.Vect()).Mag();
	Double_t vcm2 = ((1/observed1_4vect.Energy())*observed1_4vect.Vect()).Mag();
	Double_t vcm3 = ((1/observed2_4vect.Energy())*observed2_4vect.Vect()).Mag();

	Double_t kecmrec = 0.5*this->recoil.mass*vcmrec*vcmrec;
	Double_t kecm1 = 0.5*breakup1.mass*vcm1*vcm1;
	Double_t kecm2 = 0.5*breakup2.mass*vcm2*vcm2;
	Double_t kecm3 = 0.5*breakup3.mass*vcm3*vcm3;

	Double_t ecm1 = kecm1 + kecmrec;
	Double_t ecm2 = kecm2 + kecm3;

	Double_t theta1 = radToDeg*acos(missing_4vect.Vect().Z()/missing_4vect.Vect().Mag());
	Double_t phi1 = radToDeg*atan2(missing_4vect.Vect().Y(), missing_4vect.Vect().X());
	if(phi1<0) phi1 += 360.;

	Double_t theta2 = radToDeg*acos(observed1_4vect.Vect().Z()/observed1_4vect.Vect().Mag());
	Double_t phi2 = radToDeg*atan2(observed1_4vect.Vect().Y(), observed1_4vect.Vect().X());
	if(phi2<0) phi2 += 360.;

	Double_t theta3 = radToDeg*acos(observed2_4vect.Vect().Z()/observed2_4vect.Vect().Mag());
	Double_t phi3 = radToDeg*atan2(observed2_4vect.Vect().Y(), observed2_4vect.Vect().X());
	if(phi3<0) phi3 += 360.;

	CaseResult4 result1;
	result1.boostvector1 = boostvector1;
	result1.boostvector2 = boostvector2;

	result1.Vcm1 = vcm1;
	result1.KEcm1 = kecm1;
	result1.ThetaCM1 = theta1;
	result1.PhiCM1 = phi1;
	result1.ELab1 = missing_4vect.Energy();
	result1.ThetaLab1 = missing_4vect_thetalab;
	result1.PhiLab1 = missing_4vect_philab;
	result1.breakup1_LabAngleWRTVCM = breakup1_LabAngleWRTVCM;
	result1.breakup1_CMAngleWRTVCM = breakup1_CMAngleWRTVCM;

	result1.Vcm2 = vcm2;
	result1.KEcm2 = kecm2;
	result1.ThetaCM2 = theta2;
	result1.PhiCM2 = phi2;
	result1.ELab2 = detected1E;
	result1.ThetaLab2 = detected1Theta;
	result1.PhiLab2 = detected1Phi;
	result1.breakup2_LabAngleWRTVCM = breakup2_LabAngleWRTVCM;
	result1.breakup2_CMAngleWRTVCM = breakup2_CMAngleWRTVCM;

	result1.Vcm3 = vcm3;
	result1.KEcm3 = kecm3;
	result1.ThetaCM3 = theta3;
	result1.PhiCM3 = phi3;
	result1.ELab3 = detected2E;
	result1.ThetaLab3 = detected2Theta;
	result1.PhiLab3 = detected2Phi;
	result1.breakup3_LabAngleWRTVCM = breakup3_LabAngleWRTVCM;
	result1.breakup3_CMAngleWRTVCM = breakup3_CMAngleWRTVCM;

	result1.Ecm1 = ecm1;
	result1.Ecm2 = ecm2;

	result1.recoilExE = recoil_ExcessEnergy;

	result1.recInvMass = recoil_4vect.M();
	result1.ejInvMass =  ejectile_4vect.M();
	result1.daughterInvMass = daughter1_4vect.M();
	result1.bu1InvMass = missing_4vect.M();
	result1.bu2InvMass = observed1_4vect.M();
	result1.bu3InvMass = observed2_4vect.M();




	/*******************************************************
	 *					  CASE II BELOW:				   *
	 *******************************************************/
	//assume the missing mass is    --->   break up 1
	//assume the detected1 mass is  --->   break up 3
	//assume the detected2 mass is  --->   break up 2

	mass_missing = this->breakup1.mass;

	mass_observed1 = this->breakup3.mass;
	Elab_observed1 = detected1E;
	Thetalab_observed1 = detected1Theta;
	Philab_observed1 = detected1Phi;
	plab_observed1 = sqrt(2*Elab_observed1*mass_observed1);

	mass_observed2 = this->breakup2.mass;
	Elab_observed2 = detected2E;
	Thetalab_observed2 = detected2Theta;
	Philab_observed2 = detected2Phi;
	plab_observed2 = sqrt(2*Elab_observed2*mass_observed2);

	plab_ej = sqrt(2*ejectileE*this->ejectile.mass);
	plab_beam = sqrt(2*this->beam_energy*this->beam.mass);
	plab_target = 0.;

	beam_4vect.SetPxPyPzE(0., 0., plab_beam, this->beam.mass+this->beam_energy);
	target_4vect.SetPxPyPzE(0., 0., 0., this->target.mass);
	ejectile_4vect.SetPxPyPzE(plab_ej*sin(degToRad*ejectileTheta)*cos(degToRad*ejectilePhi), plab_ej*sin(degToRad*ejectileTheta)*sin(degToRad*ejectilePhi), plab_ej*cos(degToRad*ejectileTheta), this->ejectile.mass+ejectileE);
	observed1_4vect.SetPxPyPzE(plab_observed1*sin(degToRad*Thetalab_observed1)*cos(degToRad*Philab_observed1), plab_observed1*sin(degToRad*Thetalab_observed1)*sin(degToRad*Philab_observed1), plab_observed1*cos(degToRad*Thetalab_observed1), mass_observed1+Elab_observed1);
	observed2_4vect.SetPxPyPzE(plab_observed2*sin(degToRad*Thetalab_observed2)*cos(degToRad*Philab_observed2), plab_observed2*sin(degToRad*Thetalab_observed2)*sin(degToRad*Philab_observed2), plab_observed2*cos(degToRad*Thetalab_observed2), mass_observed2+Elab_observed2);

	recoil_4vect = beam_4vect + target_4vect - ejectile_4vect;
	missing_4vect = recoil_4vect - observed1_4vect - observed2_4vect;
	daughter1_4vect = observed1_4vect + observed2_4vect;

	missing_4vect_thetalab = radToDeg*acos(missing_4vect.Vect().Z()/missing_4vect.Vect().Mag());
	missing_4vect_philab = radToDeg*atan2(missing_4vect.Vect().Y(), missing_4vect.Vect().X());


	boostvector1 = (-1/recoil_4vect.Energy())*recoil_4vect.Vect();
	boostvector2 = (-1/daughter1_4vect.Energy())*daughter1_4vect.Vect();

	//recoil_ExcessEnergy = recoil_4vect.M() - this->recoil.mass;
	recoil_ExcessEnergy = recoil_4vect.M() - this->recoil.mass;

	//calculate breakup angle in lab:
	breakupAngleLab = radToDeg*acos(observed2_4vect.Vect().Dot(observed1_4vect.Vect())/(observed2_4vect.Vect().Mag()*observed1_4vect.Vect().Mag()));

	thetalab2 = radToDeg*acos(observed2_4vect.Vect().Z()/observed2_4vect.Vect().Mag());
	philab2 = radToDeg*atan2(observed2_4vect.Vect().Y(), observed2_4vect.Vect().X());

	breakup1_LabAngleWRTVCM = radToDeg*observed1_4vect.Vect().Angle(-boostvector1);
	breakup2_LabAngleWRTVCM = radToDeg*observed2_4vect.Vect().Angle(-boostvector2);
	breakup3_LabAngleWRTVCM = radToDeg*missing_4vect.Vect().Angle(-boostvector2);


	//boost!
	observed1_4vect.Boost(boostvector1);
	observed2_4vect.Boost(boostvector2);
	missing_4vect.Boost(boostvector2);

	//calculate angle between breakup particles in CM frame
	breakup1_CMAngleWRTVCM = radToDeg*missing_4vect.Vect().Angle(-boostvector1);
	breakup2_CMAngleWRTVCM = radToDeg*observed1_4vect.Vect().Angle(-boostvector2);
	breakup3_CMAngleWRTVCM = radToDeg*observed2_4vect.Vect().Angle(-boostvector2);

	vcmrec = ((1/recoil_4vect.Energy())*recoil_4vect.Vect()).Mag();
	vcm1 = ((1/missing_4vect.Energy())*missing_4vect.Vect()).Mag();
	vcm2 = ((1/observed1_4vect.Energy())*observed1_4vect.Vect()).Mag();
	vcm3 = ((1/observed2_4vect.Energy())*observed2_4vect.Vect()).Mag();

	kecmrec = 0.5*this->recoil.mass*vcmrec*vcmrec;
	kecm1 = 0.5*breakup1.mass*vcm1*vcm1;
	kecm2 = 0.5*breakup2.mass*vcm2*vcm2;
	kecm3 = 0.5*breakup3.mass*vcm3*vcm3;

	ecm1 = kecm1 + kecmrec;
	ecm2 = kecm2 + kecm3;

	theta1 = radToDeg*acos(missing_4vect.Vect().Z()/missing_4vect.Vect().Mag());
	phi1 = radToDeg*atan2(missing_4vect.Vect().Y(), missing_4vect.Vect().X());
	if(phi1<0) phi1 += 360.;

	theta2 = radToDeg*acos(observed1_4vect.Vect().Z()/observed1_4vect.Vect().Mag());
	phi2 = radToDeg*atan2(observed1_4vect.Vect().Y(), observed1_4vect.Vect().X());
	if(phi2<0) phi2 += 360.;

	theta3 = radToDeg*acos(observed2_4vect.Vect().Z()/observed2_4vect.Vect().Mag());
	phi3 = radToDeg*atan2(observed2_4vect.Vect().Y(), observed2_4vect.Vect().X());
	if(phi3<0) phi3 += 360.;

	CaseResult4 result2;

	result2.boostvector1 = boostvector1;
	result2.boostvector2 = boostvector2;

	result2.Vcm1 = vcm1;
	result2.KEcm1 = kecm1;
	result2.ThetaCM1 = theta1;
	result2.PhiCM1 = phi1;
	result2.ELab1 = missing_4vect.Energy();;
	result2.ThetaLab1 = missing_4vect_thetalab;
	result2.PhiLab1 = missing_4vect_philab;
	result2.breakup1_LabAngleWRTVCM = breakup1_LabAngleWRTVCM;
	result2.breakup1_CMAngleWRTVCM = breakup1_CMAngleWRTVCM;

	result2.Vcm2 = vcm2;
	result2.KEcm2 = kecm2;
	result2.ThetaCM2 = theta2;
	result2.PhiCM2 = phi2;
	result2.ELab2 = detected2E;
	result2.ThetaLab2 = detected2Theta;
	result2.PhiLab2 = detected2Phi;
	result2.breakup2_LabAngleWRTVCM = breakup2_LabAngleWRTVCM;
	result2.breakup2_CMAngleWRTVCM = breakup2_CMAngleWRTVCM;

	result2.Vcm3 = vcm3;
	result2.KEcm3 = kecm3;
	result2.ThetaCM3 = theta3;
	result2.PhiCM3 = phi3;
	result2.ELab3 = detected1E;
	result2.ThetaLab3 = detected1Theta;
	result2.PhiLab3 = detected1Phi;
	result2.breakup3_LabAngleWRTVCM = breakup3_LabAngleWRTVCM;
	result2.breakup3_CMAngleWRTVCM = breakup3_CMAngleWRTVCM;

	result2.Ecm1 = ecm1;
	result2.Ecm2 = ecm2;

	result2.recoilExE = recoil_ExcessEnergy;

	result2.recInvMass = recoil_4vect.M();
	result2.ejInvMass =  ejectile_4vect.M();
	result2.daughterInvMass = daughter1_4vect.M();
	result2.bu1InvMass = missing_4vect.M();
	result2.bu2InvMass = observed1_4vect.M();
	result2.bu3InvMass = observed2_4vect.M();



	/*******************************************************
	 *					  CASE III BELOW:				   *
	 *******************************************************/
	//assume the missing mass is    --->   break up 2
	//assume the detected1 mass is  --->   break up 1
	//assume the detected2 mass is  --->   break up 3


	mass_missing = this->breakup2.mass;

	mass_observed1 = this->breakup1.mass;
	Elab_observed1 = detected1E;
	Thetalab_observed1 = detected1Theta;
	Philab_observed1 = detected1Phi;
	plab_observed1 = sqrt(2*Elab_observed1*mass_observed1);


	mass_observed2 = this->breakup3.mass;
	Elab_observed2 = detected2E;
	Thetalab_observed2 = detected2Theta;
	Philab_observed2 = detected2Phi;
	plab_observed2 = sqrt(2*Elab_observed2*mass_observed2);

	plab_ej = sqrt(2*ejectileE*this->ejectile.mass);
	plab_beam = sqrt(2*this->beam_energy*this->beam.mass);
	plab_target = 0.;

	beam_4vect.SetPxPyPzE(0., 0., plab_beam, this->beam.mass+this->beam_energy);
	target_4vect.SetPxPyPzE(0., 0., 0., this->target.mass);
	ejectile_4vect.SetPxPyPzE(plab_ej*sin(degToRad*ejectileTheta)*cos(degToRad*ejectilePhi), plab_ej*sin(degToRad*ejectileTheta)*sin(degToRad*ejectilePhi), plab_ej*cos(degToRad*ejectileTheta), this->ejectile.mass+ejectileE);
	observed1_4vect.SetPxPyPzE(plab_observed1*sin(degToRad*Thetalab_observed1)*cos(degToRad*Philab_observed1), plab_observed1*sin(degToRad*Thetalab_observed1)*sin(degToRad*Philab_observed1), plab_observed1*cos(degToRad*Thetalab_observed1), mass_observed1+Elab_observed1);
	observed2_4vect.SetPxPyPzE(plab_observed2*sin(degToRad*Thetalab_observed2)*cos(degToRad*Philab_observed2), plab_observed2*sin(degToRad*Thetalab_observed2)*sin(degToRad*Philab_observed2), plab_observed2*cos(degToRad*Thetalab_observed2), mass_observed2+Elab_observed2);

	recoil_4vect = beam_4vect + target_4vect - ejectile_4vect;
	missing_4vect = recoil_4vect - observed1_4vect - observed2_4vect;
	daughter1_4vect = recoil_4vect - observed1_4vect;

	missing_4vect_thetalab = radToDeg*acos(missing_4vect.Vect().Z()/missing_4vect.Vect().Mag());
	missing_4vect_philab = radToDeg*atan2(missing_4vect.Vect().Y(), missing_4vect.Vect().X());

	boostvector1 = (-1/recoil_4vect.Energy())*recoil_4vect.Vect();
	boostvector2 = (-1/daughter1_4vect.Energy())*daughter1_4vect.Vect();
	
	//recoil_ExcessEnergy = recoil_4vect.M() - this->recoil.mass;
	recoil_ExcessEnergy = recoil_4vect.M() - this->recoil.mass;

	//calculate breakup angle in lab:
	breakupAngleLab = radToDeg*acos(observed2_4vect.Vect().Dot(observed1_4vect.Vect())/(observed2_4vect.Vect().Mag()*observed1_4vect.Vect().Mag()));

	thetalab2 = radToDeg*acos(observed2_4vect.Vect().Z()/observed2_4vect.Vect().Mag());
	philab2 = radToDeg*atan2(observed2_4vect.Vect().Y(), observed2_4vect.Vect().X());

	breakup1_LabAngleWRTVCM = radToDeg*observed1_4vect.Vect().Angle(-boostvector1);
	breakup2_LabAngleWRTVCM = radToDeg*observed2_4vect.Vect().Angle(-boostvector2);
	breakup3_LabAngleWRTVCM = radToDeg*missing_4vect.Vect().Angle(-boostvector2);


	//boost!
	observed1_4vect.Boost(boostvector1);
	observed2_4vect.Boost(boostvector2);
	missing_4vect.Boost(boostvector2);

	//calculate angle between breakup particles in CM frame
	breakup1_CMAngleWRTVCM = radToDeg*missing_4vect.Vect().Angle(-boostvector1);
	breakup2_CMAngleWRTVCM = radToDeg*observed1_4vect.Vect().Angle(-boostvector2);
	breakup3_CMAngleWRTVCM = radToDeg*observed2_4vect.Vect().Angle(-boostvector2);

	vcmrec = ((1/recoil_4vect.Energy())*recoil_4vect.Vect()).Mag();
	vcm1 = ((1/missing_4vect.Energy())*missing_4vect.Vect()).Mag();
	vcm2 = ((1/observed1_4vect.Energy())*observed1_4vect.Vect()).Mag();
	vcm3 = ((1/observed2_4vect.Energy())*observed2_4vect.Vect()).Mag();

	kecmrec = 0.5*this->recoil.mass*vcmrec*vcmrec;
	kecm1 = 0.5*breakup1.mass*vcm1*vcm1;
	kecm2 = 0.5*breakup2.mass*vcm2*vcm2;
	kecm3 = 0.5*breakup3.mass*vcm3*vcm3;

	ecm1 = kecm1 + kecmrec;
	ecm2 = kecm2 + kecm3;
	theta1 = radToDeg*acos(missing_4vect.Vect().Z()/missing_4vect.Vect().Mag());
	phi1 = radToDeg*atan2(missing_4vect.Vect().Y(), missing_4vect.Vect().X());
	if(phi1<0) phi1 += 360.;

	theta2 = radToDeg*acos(observed1_4vect.Vect().Z()/observed1_4vect.Vect().Mag());
	phi2 = radToDeg*atan2(observed1_4vect.Vect().Y(), observed1_4vect.Vect().X());
	if(phi2<0) phi2 += 360.;

	theta3 = radToDeg*acos(observed2_4vect.Vect().Z()/observed2_4vect.Vect().Mag());
	phi3 = radToDeg*atan2(observed2_4vect.Vect().Y(), observed2_4vect.Vect().X());
	if(phi3<0) phi3 += 360.;

	CaseResult4 result3;
	result3.boostvector1 = boostvector1;
	result3.boostvector2 = boostvector2;
	result3.Vcm1 = vcm1;
	result3.KEcm1 = kecm1;
	result3.ThetaCM1 = theta1;
	result3.PhiCM1 = phi1;
	result3.ELab1 = detected1E;
	result3.ThetaLab1 = detected1Theta;
	result3.PhiLab1 = detected1Phi;
	result3.breakup1_LabAngleWRTVCM = breakup1_LabAngleWRTVCM;
	result3.breakup1_CMAngleWRTVCM = breakup1_CMAngleWRTVCM;

	result3.Vcm2 = vcm2;
	result3.KEcm2 = kecm2;
	result3.ThetaCM2 = theta2;
	result3.PhiCM2 = phi2;
	result3.ELab2 = missing_4vect.Energy();
	result3.ThetaLab2 = missing_4vect_thetalab;
	result3.PhiLab2 = missing_4vect_philab;
	result3.breakup2_LabAngleWRTVCM = breakup2_LabAngleWRTVCM;
	result3.breakup2_CMAngleWRTVCM = breakup2_CMAngleWRTVCM;

	result3.Vcm3 = vcm3;
	result3.KEcm3 = kecm3;
	result3.ThetaCM3 = theta3;
	result3.PhiCM3 = phi3;
	result3.ELab3 = detected2E;
	result3.ThetaLab3 = detected2Theta;
	result3.PhiLab3 = detected2Phi;
	result3.breakup3_LabAngleWRTVCM = breakup3_LabAngleWRTVCM;
	result3.breakup3_CMAngleWRTVCM = breakup3_CMAngleWRTVCM;

	result3.Ecm1 = ecm1;
	result3.Ecm2 = ecm2;

	result3.recoilExE = recoil_ExcessEnergy;

	result3.recInvMass = recoil_4vect.M();
	result3.ejInvMass =  ejectile_4vect.M();
	result3.daughterInvMass = daughter1_4vect.M();
	result3.bu1InvMass = missing_4vect.M();
	result3.bu2InvMass = observed1_4vect.M();
	result3.bu3InvMass = observed2_4vect.M();




	/*******************************************************
	 *					  CASE IV BELOW:				   *
	 *******************************************************/
	//assume the missing mass is    --->   break up 2
	//assume the detected1 mass is  --->   break up 3
	//assume the detected2 mass is  --->   break up 1


	mass_missing = this->breakup2.mass;

	mass_observed1 = this->breakup3.mass;
	Elab_observed1 = detected1E;
	Thetalab_observed1 = detected1Theta;
	Philab_observed1 = detected1Phi;
	plab_observed1 = sqrt(2*Elab_observed1*mass_observed1);


	mass_observed2 = this->breakup1.mass;
	Elab_observed2 = detected2E;
	Thetalab_observed2 = detected2Theta;
	Philab_observed2 = detected2Phi;
	plab_observed2 = sqrt(2*Elab_observed2*mass_observed2);

	plab_ej = sqrt(2*ejectileE*this->ejectile.mass);
	plab_beam = sqrt(2*this->beam_energy*this->beam.mass);
	plab_target = 0.;

	beam_4vect.SetPxPyPzE(0., 0., plab_beam, this->beam.mass+this->beam_energy);
	target_4vect.SetPxPyPzE(0., 0., 0., this->target.mass);
	ejectile_4vect.SetPxPyPzE(plab_ej*sin(degToRad*ejectileTheta)*cos(degToRad*ejectilePhi), plab_ej*sin(degToRad*ejectileTheta)*sin(degToRad*ejectilePhi), plab_ej*cos(degToRad*ejectileTheta), this->ejectile.mass+ejectileE);
	observed1_4vect.SetPxPyPzE(plab_observed1*sin(degToRad*Thetalab_observed1)*cos(degToRad*Philab_observed1), plab_observed1*sin(degToRad*Thetalab_observed1)*sin(degToRad*Philab_observed1), plab_observed1*cos(degToRad*Thetalab_observed1), mass_observed1+Elab_observed1);
	observed2_4vect.SetPxPyPzE(plab_observed2*sin(degToRad*Thetalab_observed2)*cos(degToRad*Philab_observed2), plab_observed2*sin(degToRad*Thetalab_observed2)*sin(degToRad*Philab_observed2), plab_observed2*cos(degToRad*Thetalab_observed2), mass_observed2+Elab_observed2);

	recoil_4vect = beam_4vect + target_4vect - ejectile_4vect;
	missing_4vect = recoil_4vect - observed1_4vect - observed2_4vect;
	daughter1_4vect = recoil_4vect - observed2_4vect;

	missing_4vect_thetalab = radToDeg*acos(missing_4vect.Vect().Z()/missing_4vect.Vect().Mag());
	missing_4vect_philab = radToDeg*atan2(missing_4vect.Vect().Y(), missing_4vect.Vect().X());

	boostvector1 = (-1/recoil_4vect.Energy())*recoil_4vect.Vect();
	boostvector2 = (-1/daughter1_4vect.Energy())*daughter1_4vect.Vect();

	//recoil_ExcessEnergy = recoil_4vect.M() - this->recoil.mass;
	recoil_ExcessEnergy = recoil_4vect.M() - this->recoil.mass;

	//calculate breakup angle in lab:
	breakupAngleLab = radToDeg*acos(observed2_4vect.Vect().Dot(observed1_4vect.Vect())/(observed2_4vect.Vect().Mag()*observed1_4vect.Vect().Mag()));

	thetalab2 = radToDeg*acos(observed2_4vect.Vect().Z()/observed2_4vect.Vect().Mag());
	philab2 = radToDeg*atan2(observed2_4vect.Vect().Y(), observed2_4vect.Vect().X());

	breakup1_LabAngleWRTVCM = radToDeg*observed1_4vect.Vect().Angle(-boostvector1);
	breakup2_LabAngleWRTVCM = radToDeg*observed2_4vect.Vect().Angle(-boostvector2);
	breakup3_LabAngleWRTVCM = radToDeg*missing_4vect.Vect().Angle(-boostvector2);


	//boost!
	observed1_4vect.Boost(boostvector1);
	observed2_4vect.Boost(boostvector2);
	missing_4vect.Boost(boostvector2);

	//calculate angle between breakup particles in CM frame
	breakup1_CMAngleWRTVCM = radToDeg*missing_4vect.Vect().Angle(-boostvector1);
	breakup2_CMAngleWRTVCM = radToDeg*observed1_4vect.Vect().Angle(-boostvector2);
	breakup3_CMAngleWRTVCM = radToDeg*observed2_4vect.Vect().Angle(-boostvector2);

	vcmrec = ((1/recoil_4vect.Energy())*recoil_4vect.Vect()).Mag();
	vcm1 = ((1/missing_4vect.Energy())*missing_4vect.Vect()).Mag();
	vcm2 = ((1/observed1_4vect.Energy())*observed1_4vect.Vect()).Mag();
	vcm3 = ((1/observed2_4vect.Energy())*observed2_4vect.Vect()).Mag();

	kecmrec = 0.5*this->recoil.mass*vcmrec*vcmrec;
	kecm1 = 0.5*breakup1.mass*vcm1*vcm1;
	kecm2 = 0.5*breakup2.mass*vcm2*vcm2;
	kecm3 = 0.5*breakup3.mass*vcm3*vcm3;

	ecm1 = kecm1 + kecmrec;
	ecm2 = kecm2 + kecm3;

	theta1 = radToDeg*acos(missing_4vect.Vect().Z()/missing_4vect.Vect().Mag());
	phi1 = radToDeg*atan2(missing_4vect.Vect().Y(), missing_4vect.Vect().X());
	if(phi1<0) phi1 += 360.;

	theta2 = radToDeg*acos(observed1_4vect.Vect().Z()/observed1_4vect.Vect().Mag());
	phi2 = radToDeg*atan2(observed1_4vect.Vect().Y(), observed1_4vect.Vect().X());
	if(phi2<0) phi2 += 360.;

	theta3 = radToDeg*acos(observed2_4vect.Vect().Z()/observed2_4vect.Vect().Mag());
	phi3 = radToDeg*atan2(observed2_4vect.Vect().Y(), observed2_4vect.Vect().X());
	if(phi3<0) phi3 += 360.;

	CaseResult4 result4;
	result4.boostvector1 = boostvector1;
	result4.boostvector2 = boostvector2;
	result4.Vcm1 = vcm1;
	result4.KEcm1 = kecm1;
	result4.ThetaCM1 = theta1;
	result4.PhiCM1 = phi1;
	result4.ELab1 = detected2E;
	result4.ThetaLab1 = detected2Theta;
	result4.PhiLab1 = detected2Phi;
	result4.breakup1_LabAngleWRTVCM = breakup1_LabAngleWRTVCM;
	result4.breakup1_CMAngleWRTVCM = breakup1_CMAngleWRTVCM;

	result4.Vcm2 = vcm2;
	result4.KEcm2 = kecm2;
	result4.ThetaCM2 = theta2;
	result4.PhiCM2 = phi2;
	result4.ELab2 = missing_4vect.Energy();
	result4.ThetaLab2 = missing_4vect_thetalab;
	result4.PhiLab2 = missing_4vect_philab;
	result4.breakup2_LabAngleWRTVCM = breakup2_LabAngleWRTVCM;
	result4.breakup2_CMAngleWRTVCM = breakup2_CMAngleWRTVCM;

	result4.Vcm3 = vcm3;
	result4.KEcm3 = kecm3;
	result4.ThetaCM3 = theta3;
	result4.PhiCM3 = phi3;
	result4.ELab3 = detected1E;
	result4.ThetaLab3 = detected1Theta;
	result4.PhiLab3 = detected1Phi;
	result4.breakup3_LabAngleWRTVCM = breakup3_LabAngleWRTVCM;
	result4.breakup3_CMAngleWRTVCM = breakup3_CMAngleWRTVCM;

	result4.Ecm1 = ecm1;
	result4.Ecm2 = ecm2;

	result4.recoilExE = recoil_ExcessEnergy;

	result4.recInvMass = recoil_4vect.M();
	result4.ejInvMass =  ejectile_4vect.M();
	result4.daughterInvMass = daughter1_4vect.M();
	result4.bu1InvMass = missing_4vect.M();
	result4.bu2InvMass = observed1_4vect.M();
	result4.bu3InvMass = observed2_4vect.M();


	/*******************************************************
	 *					  CASE V BELOW:				   	   *
	 *******************************************************/
	//assume the missing mass is    --->   break up 3
	//assume the detected1 mass is  --->   break up 1
	//assume the detected2 mass is  --->   break up 2


	mass_missing = this->breakup3.mass;

	mass_observed1 = this->breakup1.mass;
	Elab_observed1 = detected1E;
	Thetalab_observed1 = detected1Theta;
	Philab_observed1 = detected1Phi;
	plab_observed1 = sqrt(2*Elab_observed1*mass_observed1);


	mass_observed2 = this->breakup2.mass;
	Elab_observed2 = detected2E;
	Thetalab_observed2 = detected2Theta;
	Philab_observed2 = detected2Phi;
	plab_observed2 = sqrt(2*Elab_observed2*mass_observed2);

	plab_ej = sqrt(2*ejectileE*this->ejectile.mass);
	plab_beam = sqrt(2*this->beam_energy*this->beam.mass);
	plab_target = 0.;

	beam_4vect.SetPxPyPzE(0., 0., plab_beam, this->beam.mass+this->beam_energy);
	target_4vect.SetPxPyPzE(0., 0., 0., this->target.mass);
	ejectile_4vect.SetPxPyPzE(plab_ej*sin(degToRad*ejectileTheta)*cos(degToRad*ejectilePhi), plab_ej*sin(degToRad*ejectileTheta)*sin(degToRad*ejectilePhi), plab_ej*cos(degToRad*ejectileTheta), this->ejectile.mass+ejectileE);
	observed1_4vect.SetPxPyPzE(plab_observed1*sin(degToRad*Thetalab_observed1)*cos(degToRad*Philab_observed1), plab_observed1*sin(degToRad*Thetalab_observed1)*sin(degToRad*Philab_observed1), plab_observed1*cos(degToRad*Thetalab_observed1), mass_observed1+Elab_observed1);
	observed2_4vect.SetPxPyPzE(plab_observed2*sin(degToRad*Thetalab_observed2)*cos(degToRad*Philab_observed2), plab_observed2*sin(degToRad*Thetalab_observed2)*sin(degToRad*Philab_observed2), plab_observed2*cos(degToRad*Thetalab_observed2), mass_observed2+Elab_observed2);

	recoil_4vect = beam_4vect + target_4vect - ejectile_4vect;
	missing_4vect = recoil_4vect - observed1_4vect - observed2_4vect;
	daughter1_4vect = recoil_4vect - observed1_4vect;

	missing_4vect_thetalab = radToDeg*acos(missing_4vect.Vect().Z()/missing_4vect.Vect().Mag());
	missing_4vect_philab = radToDeg*atan2(missing_4vect.Vect().Y(), missing_4vect.Vect().X());

	boostvector1 = (-1/recoil_4vect.Energy())*recoil_4vect.Vect();
	boostvector2 = (-1/daughter1_4vect.Energy())*daughter1_4vect.Vect();

	//recoil_ExcessEnergy = recoil_4vect.M() - this->recoil.mass;
	recoil_ExcessEnergy = recoil_4vect.M() - this->recoil.mass;

	//calculate breakup angle in lab:
	breakupAngleLab = radToDeg*acos(observed2_4vect.Vect().Dot(observed1_4vect.Vect())/(observed2_4vect.Vect().Mag()*observed1_4vect.Vect().Mag()));

	thetalab2 = radToDeg*acos(observed2_4vect.Vect().Z()/observed2_4vect.Vect().Mag());
	philab2 = radToDeg*atan2(observed2_4vect.Vect().Y(), observed2_4vect.Vect().X());

	breakup1_LabAngleWRTVCM = radToDeg*observed1_4vect.Vect().Angle(-boostvector1);
	breakup2_LabAngleWRTVCM = radToDeg*observed2_4vect.Vect().Angle(-boostvector2);
	breakup3_LabAngleWRTVCM = radToDeg*missing_4vect.Vect().Angle(-boostvector2);


	//boost!
	observed1_4vect.Boost(boostvector1);
	observed2_4vect.Boost(boostvector2);
	missing_4vect.Boost(boostvector2);

	//calculate angle between breakup particles in CM frame
	breakup1_CMAngleWRTVCM = radToDeg*missing_4vect.Vect().Angle(-boostvector1);
	breakup2_CMAngleWRTVCM = radToDeg*observed1_4vect.Vect().Angle(-boostvector2);
	breakup3_CMAngleWRTVCM = radToDeg*observed2_4vect.Vect().Angle(-boostvector2);

	vcmrec = ((1/recoil_4vect.Energy())*recoil_4vect.Vect()).Mag();
	vcm1 = ((1/missing_4vect.Energy())*missing_4vect.Vect()).Mag();
	vcm2 = ((1/observed1_4vect.Energy())*observed1_4vect.Vect()).Mag();
	vcm3 = ((1/observed2_4vect.Energy())*observed2_4vect.Vect()).Mag();

	kecmrec = 0.5*this->recoil.mass*vcmrec*vcmrec;
	kecm1 = 0.5*breakup1.mass*vcm1*vcm1;
	kecm2 = 0.5*breakup2.mass*vcm2*vcm2;
	kecm3 = 0.5*breakup3.mass*vcm3*vcm3;

	ecm1 = kecm1 + kecmrec;
	ecm2 = kecm2 + kecm3;

	theta1 = radToDeg*acos(missing_4vect.Vect().Z()/missing_4vect.Vect().Mag());
	phi1 = radToDeg*atan2(missing_4vect.Vect().Y(), missing_4vect.Vect().X());
	if(phi1<0) phi1 += 360.;

	theta2 = radToDeg*acos(observed1_4vect.Vect().Z()/observed1_4vect.Vect().Mag());
	phi2 = radToDeg*atan2(observed1_4vect.Vect().Y(), observed1_4vect.Vect().X());
	if(phi2<0) phi2 += 360.;

	theta3 = radToDeg*acos(observed2_4vect.Vect().Z()/observed2_4vect.Vect().Mag());
	phi3 = radToDeg*atan2(observed2_4vect.Vect().Y(), observed2_4vect.Vect().X());
	if(phi3<0) phi3 += 360.;

	CaseResult4 result5;
	result5.boostvector1 = boostvector1;
	result5.boostvector2 = boostvector2;
	result5.Vcm1 = vcm1;
	result5.KEcm1 = kecm1;
	result5.ThetaCM1 = theta1;
	result5.PhiCM1 = phi1;
	result5.ELab1 = detected1E;
	result5.ThetaLab1 = detected1Theta;
	result5.PhiLab1 = detected1Phi;
	result5.breakup1_LabAngleWRTVCM = breakup1_LabAngleWRTVCM;
	result5.breakup1_CMAngleWRTVCM = breakup1_CMAngleWRTVCM;

	result5.Vcm2 = vcm2;
	result5.KEcm2 = kecm2;
	result5.ThetaCM2 = theta2;
	result5.PhiCM2 = phi2;
	result5.ELab2 = detected2E;
	result5.ThetaLab2 = detected2Theta;
	result5.PhiLab2 = detected2Phi;
	result5.breakup2_LabAngleWRTVCM = breakup2_LabAngleWRTVCM;
	result5.breakup2_CMAngleWRTVCM = breakup2_CMAngleWRTVCM;

	result5.Vcm3 = vcm3;
	result5.KEcm3 = kecm3;
	result5.ThetaCM3 = theta3;
	result5.PhiCM3 = phi3;
	result5.ELab3 = missing_4vect.Energy();
	result5.ThetaLab3 = missing_4vect_thetalab;
	result5.PhiLab3 = missing_4vect_philab;
	result5.breakup3_LabAngleWRTVCM = breakup3_LabAngleWRTVCM;
	result5.breakup3_CMAngleWRTVCM = breakup3_CMAngleWRTVCM;

	result5.Ecm1 = ecm1;
	result5.Ecm2 = ecm2;

	result5.recoilExE = recoil_ExcessEnergy;

	result5.recInvMass = recoil_4vect.M();
	result5.ejInvMass =  ejectile_4vect.M();
	result5.daughterInvMass = daughter1_4vect.M();
	result5.bu1InvMass = missing_4vect.M();
	result5.bu2InvMass = observed1_4vect.M();
	result5.bu3InvMass = observed2_4vect.M();



	/*******************************************************
	 *					  CASE VI BELOW:				   *
	 *******************************************************/
	//assume the missing mass is    --->   break up 3
	//assume the detected1 mass is  --->   break up 2
	//assume the detected2 mass is  --->   break up 1


	mass_missing = this->breakup3.mass;

	mass_observed1 = this->breakup1.mass;
	Elab_observed1 = detected1E;
	Thetalab_observed1 = detected1Theta;
	Philab_observed1 = detected1Phi;
	plab_observed1 = sqrt(2*Elab_observed1*mass_observed1);


	mass_observed2 = this->breakup2.mass;
	Elab_observed2 = detected2E;
	Thetalab_observed2 = detected2Theta;
	Philab_observed2 = detected2Phi;
	plab_observed2 = sqrt(2*Elab_observed2*mass_observed2);

	plab_ej = sqrt(2*ejectileE*this->ejectile.mass);
	plab_beam = sqrt(2*this->beam_energy*this->beam.mass);
	plab_target = 0.;

	beam_4vect.SetPxPyPzE(0., 0., plab_beam, this->beam.mass+this->beam_energy);
	target_4vect.SetPxPyPzE(0., 0., 0., this->target.mass);
	ejectile_4vect.SetPxPyPzE(plab_ej*sin(degToRad*ejectileTheta)*cos(degToRad*ejectilePhi), plab_ej*sin(degToRad*ejectileTheta)*sin(degToRad*ejectilePhi), plab_ej*cos(degToRad*ejectileTheta), this->ejectile.mass+ejectileE);
	observed1_4vect.SetPxPyPzE(plab_observed1*sin(degToRad*Thetalab_observed1)*cos(degToRad*Philab_observed1), plab_observed1*sin(degToRad*Thetalab_observed1)*sin(degToRad*Philab_observed1), plab_observed1*cos(degToRad*Thetalab_observed1), mass_observed1+Elab_observed1);
	observed2_4vect.SetPxPyPzE(plab_observed2*sin(degToRad*Thetalab_observed2)*cos(degToRad*Philab_observed2), plab_observed2*sin(degToRad*Thetalab_observed2)*sin(degToRad*Philab_observed2), plab_observed2*cos(degToRad*Thetalab_observed2), mass_observed2+Elab_observed2);

	recoil_4vect = beam_4vect + target_4vect - ejectile_4vect;
	missing_4vect = recoil_4vect - observed1_4vect - observed2_4vect;
	daughter1_4vect = recoil_4vect - observed2_4vect;

	missing_4vect_thetalab = radToDeg*acos(missing_4vect.Vect().Z()/missing_4vect.Vect().Mag());
	missing_4vect_philab = radToDeg*atan2(missing_4vect.Vect().Y(), missing_4vect.Vect().X());

	boostvector1 = (-1/recoil_4vect.Energy())*recoil_4vect.Vect();
	boostvector2 = (-1/daughter1_4vect.Energy())*daughter1_4vect.Vect();

	//recoil_ExcessEnergy = recoil_4vect.M() - this->recoil.mass;
	recoil_ExcessEnergy = recoil_4vect.M() - this->recoil.mass;

	//calculate breakup angle in lab:
	breakupAngleLab = radToDeg*acos(observed2_4vect.Vect().Dot(observed1_4vect.Vect())/(observed2_4vect.Vect().Mag()*observed1_4vect.Vect().Mag()));

	thetalab2 = radToDeg*acos(observed2_4vect.Vect().Z()/observed2_4vect.Vect().Mag());
	philab2 = radToDeg*atan2(observed2_4vect.Vect().Y(), observed2_4vect.Vect().X());

	breakup1_LabAngleWRTVCM = radToDeg*observed1_4vect.Vect().Angle(-boostvector1);
	breakup2_LabAngleWRTVCM = radToDeg*observed2_4vect.Vect().Angle(-boostvector2);
	breakup3_LabAngleWRTVCM = radToDeg*missing_4vect.Vect().Angle(-boostvector2);


	//boost!
	observed1_4vect.Boost(boostvector1);
	observed2_4vect.Boost(boostvector2);
	missing_4vect.Boost(boostvector2);

	//calculate angle between breakup particles in CM frame
	breakup1_CMAngleWRTVCM = radToDeg*missing_4vect.Vect().Angle(-boostvector1);
	breakup2_CMAngleWRTVCM = radToDeg*observed1_4vect.Vect().Angle(-boostvector2);
	breakup3_CMAngleWRTVCM = radToDeg*observed2_4vect.Vect().Angle(-boostvector2);

	vcmrec = ((1/recoil_4vect.Energy())*recoil_4vect.Vect()).Mag();
	vcm1 = ((1/missing_4vect.Energy())*missing_4vect.Vect()).Mag();
	vcm2 = ((1/observed1_4vect.Energy())*observed1_4vect.Vect()).Mag();
	vcm3 = ((1/observed2_4vect.Energy())*observed2_4vect.Vect()).Mag();

	kecmrec = 0.5*this->recoil.mass*vcmrec*vcmrec;
	kecm1 = 0.5*breakup1.mass*vcm1*vcm1;
	kecm2 = 0.5*breakup2.mass*vcm2*vcm2;
	kecm3 = 0.5*breakup3.mass*vcm3*vcm3;

	ecm1 = kecm1 + kecmrec;
	ecm2 = kecm2 + kecm3;

	theta1 = radToDeg*acos(missing_4vect.Vect().Z()/missing_4vect.Vect().Mag());
	phi1 = radToDeg*atan2(missing_4vect.Vect().Y(), missing_4vect.Vect().X());
	if(phi1<0) phi1 += 360.;

	theta2 = radToDeg*acos(observed1_4vect.Vect().Z()/observed1_4vect.Vect().Mag());
	phi2 = radToDeg*atan2(observed1_4vect.Vect().Y(), observed1_4vect.Vect().X());
	if(phi2<0) phi2 += 360.;

	theta3 = radToDeg*acos(observed2_4vect.Vect().Z()/observed2_4vect.Vect().Mag());
	phi3 = radToDeg*atan2(observed2_4vect.Vect().Y(), observed2_4vect.Vect().X());
	if(phi3<0) phi3 += 360.;

	CaseResult4 result6;
	result6.boostvector1 = boostvector1;
	result6.boostvector2 = boostvector2;
	result6.Vcm1 = vcm1;
	result6.KEcm1 = kecm1;
	result6.ThetaCM1 = theta1;
	result6.PhiCM1 = phi1;
	result6.ELab1 = detected2E;
	result6.ThetaLab1 = detected2Theta;
	result6.PhiLab1 = detected2Phi;
	result6.breakup1_LabAngleWRTVCM = breakup1_LabAngleWRTVCM;
	result6.breakup1_CMAngleWRTVCM = breakup1_CMAngleWRTVCM;

	result6.Vcm2 = vcm2;
	result6.KEcm2 = kecm2;
	result6.ThetaCM2 = theta2;
	result6.PhiCM2 = phi2;
	result6.ELab2 = detected1E;
	result6.ThetaLab2 = detected1Theta;
	result6.PhiLab2 = detected1Phi;
	result6.breakup2_LabAngleWRTVCM = breakup2_LabAngleWRTVCM;
	result6.breakup2_CMAngleWRTVCM = breakup2_CMAngleWRTVCM;

	result6.Vcm3 = vcm3;
	result6.KEcm3 = kecm3;
	result6.ThetaCM3 = theta3;
	result6.PhiCM3 = phi3;
	result6.ELab3 = missing_4vect.Energy();
	result6.ThetaLab3 = missing_4vect_thetalab;
	result6.PhiLab3 = missing_4vect_philab;
	result6.breakup3_LabAngleWRTVCM = breakup3_LabAngleWRTVCM;
	result6.breakup3_CMAngleWRTVCM = breakup3_CMAngleWRTVCM;

	result6.Ecm1 = ecm1;
	result6.Ecm2 = ecm2;

	result6.recoilExE = recoil_ExcessEnergy;

	result6.recInvMass = recoil_4vect.M();
	result6.ejInvMass =  ejectile_4vect.M();
	result6.daughterInvMass = daughter1_4vect.M();
	result6.bu1InvMass = missing_4vect.M();
	result6.bu2InvMass = observed1_4vect.M();
	result6.bu3InvMass = observed2_4vect.M();



	//return!

	return {result1, result2, result3, result4, result5, result6};

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



CaseResult4 IMMMA_Tool_4::CalculateCaseIMM(const DetectedParticle4& ej, const DetectedParticle4& bu1, const DetectedParticle4& bu2, const DetectedParticle4& bu3)
{

	//CalculateCaseIMM always assumes ej = ejectile, bu1 = breakup1, bu2 = breakup2, bu3 = breakup3
	//The arguments should be cycled and called individually as done in AnalyzeEventIMM


	//result to get returned:
	CaseResult4 result;

	//TLorentzVectors for reaction particles:
	TLorentzVector beam_4vect, target_4vect, ejectile_4vect, recoil_4vect, breakup1_4vect, daughter1_4vect, breakup2_4vect, breakup3_4vect;


	//calculate momenta from assumed masses
	double plab_detected1 = sqrt(2*bu1.E*bu1.Mass);
	double plab_detected2 = sqrt(2*bu2.E*bu2.Mass);
	double plab_detected3 = sqrt(2*bu3.E*bu3.Mass);

	//and momenta w/ known masses:
	double plab_ej = sqrt(2*ej.E*ej.Mass);
	double plab_beam = sqrt(2*beam_energy*beam.mass);
	double plab_target = 0.;

	//initialize 4vectors w/ above momenta:
	beam_4vect.SetPxPyPzE(0., 0., plab_beam, beam.mass + beam_energy);
	target_4vect.SetPxPyPzE(0., 0., 0., target.mass);

	ejectile_4vect.SetPxPyPzE(plab_ej*sin(degToRad*ej.Theta)*cos(degToRad*ej.Phi),
							  plab_ej*sin(degToRad*ej.Theta)*sin(degToRad*ej.Phi),
							  plab_ej*cos(degToRad*ej.Theta),
							  ej.Mass + ej.E);

	breakup1_4vect.SetPxPyPzE(plab_detected1*sin(degToRad*bu1.Theta)*cos(degToRad*bu1.Phi),
							  plab_detected1*sin(degToRad*bu1.Theta)*sin(degToRad*bu1.Phi),
							  plab_detected1*cos(degToRad*bu1.Theta),
							  bu1.Mass + bu1.E);

	breakup2_4vect.SetPxPyPzE(plab_detected2*sin(degToRad*bu2.Theta)*cos(degToRad*bu2.Phi),
							  plab_detected2*sin(degToRad*bu2.Theta)*sin(degToRad*bu2.Phi),
							  plab_detected2*cos(degToRad*bu2.Theta),
							  bu2.Mass + bu2.E);

	breakup3_4vect.SetPxPyPzE(plab_detected3*sin(degToRad*bu3.Theta)*cos(degToRad*bu3.Phi),
							  plab_detected3*sin(degToRad*bu3.Theta)*sin(degToRad*bu3.Phi),
							  plab_detected3*cos(degToRad*bu3.Theta),
							  bu3.Mass + bu3.E);

	//reconstruct the resonance from breakup2+breakup3 (daughter1)
	daughter1_4vect = breakup2_4vect + breakup3_4vect;

	//reconstruct recoil
	recoil_4vect = daughter1_4vect + breakup1_4vect;


	//calculate excitation energy of the recoil:
	//Double_t recoil_ExcessEnergy = recoil_4vect.M() - recoil.mass;
	Double_t recoil_ExcessEnergy = recoil_4vect.M() - this->recoil.mass;

	
	//calculate breakup angle in lab:
	//(between 3, 4, so final break up particles)
	Double_t breakupAngleLab = radToDeg*acos(breakup2_4vect.Vect().Dot(breakup3_4vect.Vect())/(breakup2_4vect.Vect().Mag()*breakup3_4vect.Vect().Mag()));

	Double_t thetalab2 = radToDeg*acos(breakup2_4vect.Vect().Z()/breakup2_4vect.Vect().Mag());
	Double_t philab2 = radToDeg*atan2(breakup2_4vect.Vect().Y(), breakup2_4vect.Vect().X());

	//obtain the boost vector to boost into the breakup CM frame:
	TVector3 boostvector1 = (-1/recoil_4vect.Energy())*recoil_4vect.Vect();
	TVector3 boostvector2 = (-1/daughter1_4vect.Energy())*daughter1_4vect.Vect();

	//calculate angle between break up particles in the lab and the CM velocity vector (-boost vector)
	Double_t breakup1_LabAngleWRTVCM = radToDeg*breakup1_4vect.Vect().Angle(-boostvector1); // due to recoil
	Double_t breakup2_LabAngleWRTVCM = radToDeg*breakup2_4vect.Vect().Angle(-boostvector2); // daughter1
	Double_t breakup3_LabAngleWRTVCM = radToDeg*breakup3_4vect.Vect().Angle(-boostvector2); // daughter1
	
	//boost!
	breakup1_4vect.Boost(boostvector1);//boost to CM of first break up (recoil rest frame)
	breakup2_4vect.Boost(boostvector2);//boost to CM of second break up (daughter1 rest frame)
	breakup3_4vect.Boost(boostvector2);//boost to CM of second break up (daughter1 rest frame)

	//calculate angle between break up particles in the CM frame and the CM velocity vector:
	Double_t breakup1_CMAngleWRTVCM = radToDeg*breakup1_4vect.Vect().Angle(-boostvector1);
	Double_t breakup2_CMAngleWRTVCM = radToDeg*breakup2_4vect.Vect().Angle(-boostvector2);
	Double_t breakup3_CMAngleWRTVCM = radToDeg*breakup3_4vect.Vect().Angle(-boostvector2);

	//calculate CM variables from the boosted vectors
	Double_t vcmrec = ((1/recoil_4vect.Energy())*recoil_4vect.Vect()).Mag();
	Double_t vcm1 = ((1/breakup1_4vect.Energy())*breakup1_4vect.Vect()).Mag();
	Double_t vcm2 = ((1/breakup2_4vect.Energy())*breakup2_4vect.Vect()).Mag();
	Double_t vcm3 = ((1/breakup3_4vect.Energy())*breakup3_4vect.Vect()).Mag();

	Double_t kecmrec = 0.5*this->recoil.mass*vcmrec*vcmrec;
	Double_t kecm1 = 0.5*bu1.Mass*vcm1*vcm1;
	Double_t kecm2 = 0.5*bu2.Mass*vcm2*vcm2;
	Double_t kecm3 = 0.5*bu3.Mass*vcm3*vcm3;

	//Double_t ecm = kecm1 + kecm2 + kecm3;
	Double_t ecm1 = kecm1 + kecmrec;
	Double_t ecm2 = kecm2 + kecm3;

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
	result.boostvector1 = boostvector1;
	result.boostvector2 = boostvector2;

	result.Vcm1 = vcm1;
	result.KEcm1 = kecm1;
	result.ThetaCM1 = theta1;
	result.PhiCM1 = phi1;
	result.ELab1 = bu1.E;
	result.ThetaLab1 = bu1.Theta;
	result.PhiLab1 = bu1.Phi;
	result.breakup1_LabAngleWRTVCM = breakup1_LabAngleWRTVCM;
	result.breakup1_CMAngleWRTVCM = breakup1_CMAngleWRTVCM;

	result.Vcm2 = vcm2;
	result.KEcm2 = kecm2;
	result.ThetaCM2 = theta2;
	result.PhiCM2 = phi2;
	result.ELab2 = bu2.E;
	result.ThetaLab2 = bu2.Theta;
	result.PhiLab2 = bu2.Phi;
	result.breakup2_LabAngleWRTVCM = breakup2_LabAngleWRTVCM;
	result.breakup2_CMAngleWRTVCM = breakup2_CMAngleWRTVCM;

	result.Vcm3 = vcm3;
	result.KEcm3 = kecm3;
	result.ThetaCM3 = theta3;
	result.PhiCM3 = phi3;
	result.ELab3 = bu3.E;
	result.ThetaLab3 = bu3.Theta;
	result.PhiLab3 = bu3.Phi;
	result.breakup3_LabAngleWRTVCM = breakup3_LabAngleWRTVCM;
	result.breakup3_CMAngleWRTVCM = breakup3_CMAngleWRTVCM;

	result.Ecm1 = ecm1;
	result.Ecm2 = ecm2;

	result.recoilExE = recoil_ExcessEnergy;

	result.recInvMass = recoil_4vect.M();
	result.ejInvMass = ejectile_4vect.M();
	result.bu1InvMass = breakup1_4vect.M();
	result.daughterInvMass = daughter1_4vect.M();
	//result.daughterInvMass = daughter1_4vect.Vect().Mag2()/(2*daughter1.mass);
	result.bu2InvMass = breakup2_4vect.M();
	result.bu3InvMass = breakup3_4vect.M();

	return result;	


}