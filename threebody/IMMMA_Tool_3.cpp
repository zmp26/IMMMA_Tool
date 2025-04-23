using namespace std;

#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "TLorentzVector.h"
#include "IMMMA_Tool_3.h"

IMMMA_Tool_3::IMMMA_Tool_3(){
	//default constructor
	ThetaCMSum.expected = 180.;
	ThetaCMSum.lower = 179.;
	ThetaCMSum.upper = 181.;

	PhiCMSep.expected = 180.;
	PhiCMSep.lower = 179.;
	PhiCMSep.upper = 181.;
}

//setters
void IMMMA_Tool_3::SetBeamNucleus(Int_t A, TString sym, Double_t mass){
	this->beam.A = A;
	this->beam.sym = sym;
	this->beam.mass = mass;
}

void IMMMA_Tool_3::SetTargetNucleus(Int_t A, TString sym, Double_t mass){
	this->target.A = A;
	this->target.sym = sym;
	this->target.mass = mass;
}

void IMMMA_Tool_3::SetEjectileNucleus(Int_t A, TString sym, Double_t mass){
	this->ejectile.A = A;
	this->ejectile.sym = sym;
	this->ejectile.mass = mass;
}

void IMMMA_Tool_3::SetRecoilNucleus(Int_t A, TString sym, Double_t mass){
	this->recoil.A = A;
	this->recoil.sym = sym;
	this->recoil.mass = mass;
}

void IMMMA_Tool_3::SetBreakup1Nucleus(Int_t A, TString sym, Double_t mass){
	this->breakup1.A = A;
	this->breakup1.sym = sym;
	this->breakup1.mass = mass;
}

void IMMMA_Tool_3::SetBreakup2Nucleus(Int_t A, TString sym, Double_t mass){
	this->breakup2.A = A;
	this->breakup2.sym = sym;
	this->breakup2.mass = mass;
}

void IMMMA_Tool_3::SetBeamEnergy(Double_t energy){
	this->beam_energy = energy;
}

void IMMMA_Tool_3::SetRecoilExE(Double_t energy){
	this->recoil_exE = energy;
}

void IMMMA_Tool_3::SetVcm_bu1_bounds(Double_t lower, Double_t upper){
	this->Vcm_bu1.lower = lower;
	this->Vcm_bu1.upper = upper;
}

void IMMMA_Tool_3::SetVcm_bu1_bounds(Double_t sigma){
	this->Vcm_bu1.lower = this->Vcm_bu1.mean - 2*sigma;
	this->Vcm_bu1.upper = this->Vcm_bu1.mean + 2*sigma;
}

void IMMMA_Tool_3::SetVcm_bu2_bounds(Double_t lower, Double_t upper){
	this->Vcm_bu2.lower = lower;
	this->Vcm_bu2.upper = upper;
}

void IMMMA_Tool_3::SetVcm_bu2_bounds(Double_t sigma){
	this->Vcm_bu2.lower = this->Vcm_bu2.mean - 2*sigma;
	this->Vcm_bu2.upper = this->Vcm_bu2.mean + 2*sigma;
}

void IMMMA_Tool_3::SetKEcm_bu1_bounds(Double_t lower, Double_t upper){
	this->KEcm_bu1.lower = lower;
	this->KEcm_bu1.upper = upper;
}

void IMMMA_Tool_3::SetKEcm_bu1_bounds(Double_t sigma){
	this->KEcm_bu1.lower = this->KEcm_bu1.mean - 2*sigma;
	this->KEcm_bu1.upper = this->KEcm_bu1.mean + 2*sigma;
}

void IMMMA_Tool_3::SetKEcm_bu2_bounds(Double_t lower, Double_t upper){
	this->KEcm_bu2.lower = lower;
	this->KEcm_bu2.upper = upper;
}

void IMMMA_Tool_3::SetKEcm_bu2_bounds(Double_t sigma){
	this->KEcm_bu2.lower = this->KEcm_bu2.mean - 2*sigma;
	this->KEcm_bu2.upper = this->KEcm_bu2.mean + 2*sigma;
}

void IMMMA_Tool_3::SetEcm_bounds(Double_t lower, Double_t upper){
	this->Ecm.lower = lower;
	this->Ecm.upper = upper;
}

void IMMMA_Tool_3::SetEcm_bounds(Double_t sigma){
	this->Ecm.lower = this->Ecm.mean - 2*sigma;
	this->Ecm.upper = this->Ecm.mean + 2*sigma;
}

void IMMMA_Tool_3::SetMean_Vcm_bu1(Double_t mean){
	this->Vcm_bu1.mean = mean;
}

void IMMMA_Tool_3::SetMean_Vcm_bu2(Double_t mean){
	this->Vcm_bu2.mean = mean;
}

void IMMMA_Tool_3::SetMean_KEcm_bu1(Double_t mean){
	this->KEcm_bu1.mean = mean;
}

void IMMMA_Tool_3::SetMean_KEcm_bu2(Double_t mean){
	this->KEcm_bu2.mean = mean;
}

void IMMMA_Tool_3::SetMean_Ecm(Double_t mean){
	this->Ecm.mean = mean;
}

//getters

Nucleus IMMMA_Tool_3::GetBeamNucleus(){
	return this->beam;
}

Nucleus IMMMA_Tool_3::GetTargetNucleus(){
	return this->target;
}

Nucleus IMMMA_Tool_3::GetEjectileNucleus(){
	return this->ejectile;
}

Nucleus IMMMA_Tool_3::GetRecoilNucleus(){
	return this->recoil;
}

Nucleus IMMMA_Tool_3::GetBreakup1Nucleus(){
	return this->breakup1;
}

Nucleus IMMMA_Tool_3::GetBreakup2Nucleus(){
	return this->breakup2;
}

Double_t IMMMA_Tool_3::GetBeamMass(){
	return this->beam.mass;
}

Double_t IMMMA_Tool_3::GetTargetMass(){
	return this->target.mass;
}

Double_t IMMMA_Tool_3::GetEjectileMass(){
	return this->ejectile.mass;
}

Double_t IMMMA_Tool_3::GetRecoilMass(){
	return this->recoil.mass;
}

Double_t IMMMA_Tool_3::GetBreakup1Mass(){
	return this->breakup1.mass;
}

Double_t IMMMA_Tool_3::GetBreakup2Mass(){
	return this->breakup2.mass;
}

Double_t IMMMA_Tool_3::GetBeamEnergy(){
	return this->beam_energy;
}

Double_t IMMMA_Tool_3::GetRecoilExE(){
	return this->recoil_exE;
}

CMConstant IMMMA_Tool_3::GetVcm_bu1(){
	return this->Vcm_bu1;
}

CMConstant IMMMA_Tool_3::GetVcm_bu2(){
	return this->Vcm_bu2;
}

CMConstant IMMMA_Tool_3::GetKEcm_bu1(){
	return this->KEcm_bu1;
}

CMConstant IMMMA_Tool_3::GetKEcm_bu2(){
	return this->KEcm_bu2;
}

CMConstant IMMMA_Tool_3::GetEcm(){
	return this->Ecm;
}

TString IMMMA_Tool_3::GetReactionString(){
	return this->reaction;
}

TString IMMMA_Tool_3::GetBreakupString(){
	return this->breakup;
}

//checkers
bool IMMMA_Tool_3::CheckInBounds_Vcm_bu1(Double_t test){
	return (this->Vcm_bu1.lower <= test && this->Vcm_bu1.upper >= test);
}

bool IMMMA_Tool_3::CheckInBounds_Vcm_bu2(Double_t test){
	return (this->Vcm_bu2.lower <= test && this->Vcm_bu2.upper >= test);
}

bool IMMMA_Tool_3::CheckInBounds_KEcm_bu1(Double_t test){
	return (this->KEcm_bu1.lower <= test && this->KEcm_bu1.upper >= test);
}

bool IMMMA_Tool_3::CheckInBounds_KEcm_bu2(Double_t test){
	return (this->KEcm_bu2.lower <= test && this->KEcm_bu2.upper >= test);
}

bool IMMMA_Tool_3::CheckInBounds_Ecm(Double_t test){
	return (this->Ecm.lower <= test && this->Ecm.upper >= test);
}

bool IMMMA_Tool_3::CheckInBounds_ThetaCMSum(Double_t test){
	return (this->ThetaCMSum.lower <= test && this->ThetaCMSum.upper >= test);
}

bool IMMMA_Tool_3::CheckInBounds_PhiCMSep(Double_t test){
	return (this->PhiCMSep.lower <= test && this->PhiCMSep.upper >= test);
}

//init reaction function
void IMMMA_Tool_3::CalculateCMConstants(){
	if(this->recoil.Filled() && this->breakup1.Filled() && this->breakup2.Filled()){
		this->Ecm.expected = this->recoil.mass + this->recoil_exE - this->breakup1.mass - this->breakup2.mass;
		this->Vcm_bu1.expected = sqrt(2*this->breakup2.mass*this->Ecm.expected/(this->breakup1.mass*(this->breakup1.mass + this->breakup2.mass)));
		this->Vcm_bu2.expected = sqrt(2*this->breakup1.mass*this->Ecm.expected/(this->breakup2.mass*(this->breakup1.mass + this->breakup2.mass)));
		this->KEcm_bu1.expected = 0.5*this->breakup1.mass*this->Vcm_bu1.expected*this->Vcm_bu1.expected;
		this->KEcm_bu2.expected = 0.5*this->breakup2.mass*this->Vcm_bu2.expected*this->Vcm_bu2.expected;

		this->reaction = Form("%d%s(%d%s,%d%s)%d%s",this->target.A,this->target.sym.Data(),this->beam.A,this->beam.sym.Data(),this->ejectile.A,this->ejectile.sym.Data(),this->recoil.A,this->recoil.sym.Data());
		this->breakup = Form("%d%s ---> %d%s + %d%s",this->recoil.A,this->recoil.sym.Data(),this->breakup1.A,this->breakup1.sym.Data(),this->breakup2.A,this->breakup2.sym.Data());

		//set means to expected -> these can be updated by the user in their macro by calling IMMMA_Tool_3::SetMean_Vcm_bu1(), etc...
		this->Ecm.mean = this->Ecm.expected;
		this->Vcm_bu1.mean = this->Vcm_bu1.expected;
		this->Vcm_bu2.mean = this->Vcm_bu2.expected;
		this->KEcm_bu1.mean = this->KEcm_bu1.expected;
		this->KEcm_bu2.mean = this->KEcm_bu2.expected;
	} else {
		this->Ecm.expected = -666;
		this->Vcm_bu1.expected = -666;
		this->Vcm_bu2.expected = -666;
		this->KEcm_bu1.expected = -666;
		this->KEcm_bu2.expected = -666;

		this->reaction = "null";
		this->breakup = "null";

		//set means to expected -> these can be updated by the user in their macro by calling IMMMA_Tool_3::SetMean_Vcm_bu1(), etc...
		this->Ecm.mean = this->Ecm.expected;
		this->Vcm_bu1.mean = this->Vcm_bu1.expected;
		this->Vcm_bu2.mean = this->Vcm_bu2.expected;
		this->KEcm_bu1.mean = this->KEcm_bu1.expected;
		this->KEcm_bu2.mean = this->KEcm_bu2.expected;
	}
}

//IMM Event Analysis Function:
std::pair<CaseResult,CaseResult> IMMMA_Tool_3::AnalyzeEventIMM(Double_t ejectileE, Double_t ejectileTheta, Double_t ejectilePhi, Double_t detected1E, Double_t detected1Theta, Double_t detected1Phi, Double_t detected2E, Double_t detected2Theta, Double_t detected2Phi){
	TLorentzVector beam_4vect, target_4vect, ejectile_4vect, recoil_4vect, breakup1_4vect, breakup2_4vect;
	CaseResult case1, case2;

	/*******************************************************
	 *					  CASE I BELOW:				 	   *
	 *******************************************************/
	//in this case we detect the ejectile and two particles we assume to be the break up particles.
	//Case 1 is the case in which detected1 uses mass information from breakup1
	//			              and detected2 uses mass information from breakup2

	Double_t plab_detected1 = sqrt(2*detected1E*this->breakup1.mass);
	Double_t plab_detected2 = sqrt(2*detected2E*this->breakup2.mass);

	Double_t plab_ej = sqrt(2*ejectileE*this->ejectile.mass);
	Double_t plab_beam = sqrt(2*this->beam_energy*this->beam.mass);
	Double_t plab_target = 0.;

	//initialize the 4vectors from this information:
	beam_4vect.SetPxPyPzE(0.,0.,plab_beam,this->beam.mass+this->beam_energy);
	target_4vect.SetPxPyPzE(0.,0.,0.,this->target.mass);
	ejectile_4vect.SetPxPyPzE(plab_ej*sin(degToRad*ejectileTheta)*cos(degToRad*ejectilePhi), plab_ej*sin(degToRad*ejectileTheta)*sin(degToRad*ejectilePhi), plab_ej*cos(degToRad*ejectileTheta), this->ejectile.mass+ejectileE);
	breakup1_4vect.SetPxPyPzE(plab_detected1*sin(degToRad*detected1Theta)*cos(degToRad*detected1Phi), plab_detected1*sin(degToRad*detected1Theta)*sin(degToRad*detected1Phi), plab_detected1*cos(degToRad*detected1Theta), this->breakup1.mass+detected1E);
	breakup2_4vect.SetPxPyPzE(plab_detected2*sin(degToRad*detected2Theta)*cos(degToRad*detected2Phi), plab_detected2*sin(degToRad*detected2Theta)*sin(degToRad*detected2Phi), plab_detected2*cos(degToRad*detected2Theta), this->breakup2.mass+detected2E);

	//reconstruct recoil_4vect from beam, target, and ejectile information:
	recoil_4vect = beam_4vect + target_4vect - ejectile_4vect;

	//calculate the excitation energy of the recoil:
	Double_t recoil_ExcessEnergy = recoil_4vect.M() - this->recoil.mass;//this excess energy is entirely due to excitation!

	//calculate breakup angle in the lab:
	Double_t breakupAngleLab = radToDeg*acos(breakup1_4vect.Vect().Dot(breakup2_4vect.Vect())/(breakup1_4vect.Vect().Mag()*breakup2_4vect.Vect().Mag()));

	//obtain the boost vector to boost into the breakup CM frame:
	TVector3 boostvector = (-1/recoil_4vect.Energy())*recoil_4vect.Vect();

	//boost breakup1_4vect and breakup2_4vect into the CM frame:
	breakup1_4vect.Boost(boostvector);
	breakup2_4vect.Boost(boostvector);

	//calculate CM variables from the boosted momenta:
	Double_t vcm1 = ((1/breakup1_4vect.Energy())*breakup1_4vect.Vect()).Mag();
	Double_t vcm2 = ((1/breakup2_4vect.Energy())*breakup2_4vect.Vect()).Mag();

	Double_t kecm1 = 0.5*this->breakup1.mass*vcm1*vcm1;
	Double_t kecm2 = 0.5*this->breakup2.mass*vcm2*vcm2;

	Double_t ecm = kecm1 + kecm2;

	Double_t theta1 = radToDeg*acos(breakup1_4vect.Vect().Z()/breakup1_4vect.Vect().Mag());
	Double_t phi1 = radToDeg*atan2(breakup1_4vect.Vect().Y(),breakup1_4vect.Vect().X());

	Double_t theta2 = radToDeg*acos(breakup2_4vect.Vect().Z()/breakup2_4vect.Vect().Mag());
	Double_t phi2 = radToDeg*atan2(breakup2_4vect.Vect().Y(), breakup2_4vect.Vect().X());

	//perform checks and update case1:
	// case1.Vcm1_check = (vcm1 >= Vcm_bu1_bounds[0] && vcm1 <= Vcm_bu1_bounds[1]);
	// case1.Vcm2_check = (vcm2 >= Vcm_bu2_bounds[0] && vcm2 <= Vcm_bu2_bounds[1]);
	// case1.KEcm1_check = (kecm1 >= KEcm_bu1_bounds[0] && kecm1 <= KEcm_bu1_bounds[1]);
	// case1.KEcm2_check = (kecm2 >= KEcm_bu2_bounds[0] && kecm2 <= KEcm_bu2_bounds[1]);
	// case1.Ecm_check = (ecm >= Ecm_bounds[0] && ecm <= Ecm_bounds[1]);
	// case1.ThetaCMSum_check = (theta1+theta2 >= ThetaCMSum_bounds[0] && theta1+theta2 <= ThetaCMSum_bounds[1]);
	// case1.PhiCMSep_check = (abs(phi1-phi2) >= PhiCMSep_bounds[0] && abs(phi1-phi2) <= PhiCMSep_bounds[1]);

	case1.Vcm1 = vcm1;
	case1.KEcm1 = kecm1;
	case1.ThetaCM1 = theta1;
	case1.PhiCM1 = phi1;

	case1.Vcm2 = vcm2;
	case1.KEcm2 = kecm2;
	case1.ThetaCM2 = theta2;
	case1.PhiCM2 = phi2;

	case1.Ecm = ecm;

	//now we can move on to case 2
	/*******************************************************
	 *					  CASE II BELOW:				   *
	 *******************************************************/
	//in this case we detect the ejectile and two particles we assume to be the break up particles.
	//Case 2 is the case in which detected1 uses mass information from breakup2
	//			              and detected2 uses mass information from breakup1

	plab_detected1 = sqrt(2*detected1E*this->breakup2.mass);
	plab_detected2 = sqrt(2*detected2E*this->breakup1.mass);

	plab_ej = sqrt(2*ejectileE*this->ejectile.mass);
	plab_beam = sqrt(2*this->beam_energy*this->beam.mass);
	plab_target = 0.;

	//update 4vectors for this case:
	beam_4vect.SetPxPyPzE(0.,0.,plab_beam,this->beam.mass+this->beam_energy);
	target_4vect.SetPxPyPzE(0.,0.,0.,this->target.mass);
	ejectile_4vect.SetPxPyPzE(plab_ej*sin(degToRad*ejectileTheta)*cos(degToRad*ejectilePhi), plab_ej*sin(degToRad*ejectileTheta)*sin(degToRad*ejectilePhi), plab_ej*cos(degToRad*ejectileTheta), this->ejectile.mass+ejectileE);
	breakup1_4vect.SetPxPyPzE(plab_detected1*sin(degToRad*detected1Theta)*cos(degToRad*detected1Phi), plab_detected1*sin(degToRad*detected1Theta)*sin(degToRad*detected1Phi), plab_detected1*cos(degToRad*detected1Theta), this->breakup2.mass+detected1E);
	breakup2_4vect.SetPxPyPzE(plab_detected2*sin(degToRad*detected2Theta)*cos(degToRad*detected2Phi), plab_detected2*sin(degToRad*detected2Theta)*sin(degToRad*detected2Phi), plab_detected2*cos(degToRad*detected2Theta), this->breakup1.mass+detected2E);

	//reconstruct recoil_4vect from beam, target, and ejectile information:
	recoil_4vect = beam_4vect + target_4vect - ejectile_4vect;

	//calculate the excitation energy of the recoil:
	recoil_ExcessEnergy = recoil_4vect.M() - this->recoil.mass;

	//calculate breakup angle in the lab:
	breakupAngleLab = radToDeg*acos(breakup1_4vect.Vect().Dot(breakup2_4vect.Vect())/(breakup1_4vect.Vect().Mag()*breakup2_4vect.Vect().Mag()));

	//obtain the boost vector to boost into the breakup CM frame:
	boostvector = (-1/recoil_4vect.Energy())*recoil_4vect.Vect();

	//boost breakup1_4vect and breakup2_4vect into CM frame:
	breakup1_4vect.Boost(boostvector);
	breakup2_4vect.Boost(boostvector);

	//calculate CM variables from boosted momenta:
	vcm1 = ((1/breakup1_4vect.Energy())*breakup1_4vect.Vect()).Mag();
	vcm2 = ((1/breakup2_4vect.Energy())*breakup2_4vect.Vect()).Mag();

	kecm1 = 0.5*this->breakup2.mass*vcm1*vcm1;
	kecm2 = 0.5*this->breakup1.mass*vcm2*vcm2;

	ecm = kecm1 + kecm2;

	theta1 = radToDeg*acos(breakup1_4vect.Vect().Z()/breakup1_4vect.Vect().Mag());
	phi1 = radToDeg*atan2(breakup1_4vect.Vect().Y(),breakup1_4vect.Vect().X());

	theta2 = radToDeg*acos(breakup2_4vect.Vect().Z()/breakup2_4vect.Vect().Mag());
	phi2 = radToDeg*atan2(breakup2_4vect.Vect().Y(),breakup2_4vect.Vect().X());

	//perform checks and update case2:
	// case2.Vcm1_check = (vcm1 >= Vcm_bu1_bounds[0] && vcm1 <= Vcm_bu1_bounds[1]);
	// case2.Vcm2_check = (vcm2 >= Vcm_bu2_bounds[0] && vcm2 <= Vcm_bu2_bounds[1]);
	// case2.KEcm1_check = (kecm1 >= KEcm_bu1_bounds[0] && kecm1 <= KEcm_bu1_bounds[1]);
	// case2.KEcm2_check = (kecm2 >= KEcm_bu2_bounds[0] && kecm2 <= KEcm_bu2_bounds[1]);
	// case2.Ecm_check = (ecm >= Ecm_bounds[0] && ecm <= Ecm_bounds[1]);
	// case2.ThetaCMSum_check = (theta1+theta2 >= ThetaCMSum_bounds[0] && theta1+theta2 <= ThetaCMSum_bounds[1]);
	// case2.PhiCMSep_check = (abs(phi1-phi2) >= PhiCMSep_bounds[0] && abs(phi1-phi2) <= PhiCMSep_bounds[1]);

	case2.Vcm1 = vcm1;
	case2.KEcm1 = kecm1;
	case2.ThetaCM1 = theta1;
	case2.PhiCM1 = phi1;

	case2.Vcm2 = vcm2;
	case2.KEcm2 = kecm2;
	case2.ThetaCM2 = theta2;
	case2.PhiCM2 = phi2;

	case2.Ecm = ecm;


	//return a std::pair<CaseResult,CaseResult>
	std::pair<CaseResult,CaseResult> retval = std::make_pair(case1,case2);
	return retval;
}

std::pair<CaseResult,CaseResult> IMMMA_Tool_3::AnalyzeEventMMM(Double_t ejectileE, Double_t ejectileTheta, Double_t ejectilePhi, Double_t detectedE, Double_t detectedTheta, Double_t detectedPhi){
	TLorentzVector beam_4vect, target_4vect, ejectile_4vect, recoil_4vect, observed_4vect, missing_4vect;
	CaseResult case1, case2;

	/*******************************************************
	 *					  CASE I BELOW:				 	   *
	 *******************************************************/
	//assume the mass is breakup1.mass

	Double_t mass_observed = this->breakup1.mass;
	Double_t Elab_observed = detectedE;
	Double_t Thetalab_observed = detectedTheta;
	Double_t Philab_observed = detectedPhi;

	Double_t mass_missing = this->breakup2.mass;


	Double_t plab_observed = sqrt(2*Elab_observed*mass_observed);
	Double_t plab_ej = sqrt(2*ejectileE*this->ejectile.mass);
	Double_t plab_beam = sqrt(2*this->beam_energy*this->beam.mass);
	Double_t plab_target = 0.;

	beam_4vect.SetPxPyPzE(0.,0.,plab_beam,this->beam.mass+this->beam_energy);
	target_4vect.SetPxPyPzE(0.,0.,0.,this->target.mass);
	ejectile_4vect.SetPxPyPzE(plab_ej*sin(degToRad*ejectileTheta)*cos(degToRad*ejectilePhi), plab_ej*sin(degToRad*ejectileTheta)*sin(degToRad*ejectilePhi), plab_ej*cos(degToRad*ejectileTheta), this->ejectile.mass+ejectileE);
	observed_4vect.SetPxPyPzE(plab_observed*sin(degToRad*Thetalab_observed)*cos(degToRad*Philab_observed), plab_observed*sin(degToRad*Thetalab_observed)*sin(degToRad*Philab_observed), plab_observed*cos(degToRad*Thetalab_observed), mass_observed+Elab_observed);

	recoil_4vect = beam_4vect + target_4vect - ejectile_4vect;
	missing_4vect = recoil_4vect - observed_4vect;
	TVector3 boostvector = (-1/recoil_4vect.Energy())*recoil_4vect.Vect();

	Double_t recoil_ExcessEnergy = recoil_4vect.M() - this->recoil.mass;

	Double_t breakupAngleLab = radToDeg*acos(observed_4vect.Vect().Dot(missing_4vect.Vect())/(observed_4vect.Vect().Mag()*missing_4vect.Vect().Mag()));

	//boost into CM frame
	missing_4vect.Boost(boostvector);
	observed_4vect.Boost(boostvector);

	Double_t vcm1 = ((1/observed_4vect.Energy())*observed_4vect.Vect()).Mag();
	Double_t vcm2 = ((1/missing_4vect.Energy())*missing_4vect.Vect()).Mag();

	Double_t kecm1 = 0.5*mass_observed*vcm1*vcm1;
	Double_t kecm2 = 0.5*mass_missing*vcm2*vcm2;

	Double_t ecm = kecm1+kecm2;

	Double_t theta1 = radToDeg*acos(observed_4vect.Vect().Z()/observed_4vect.Vect().Mag());
	Double_t theta2 = radToDeg*acos(missing_4vect.Vect().Z()/missing_4vect.Vect().Mag());

	Double_t phi1 = radToDeg*atan2(observed_4vect.Vect().Y(),observed_4vect.Vect().X());
	Double_t phi2 = radToDeg*atan2(missing_4vect.Vect().Y(),missing_4vect.Vect().X());

	//perform checks and update case1:
	// case1.Vcm1_check = (vcm1 >= Vcm_bu1_bounds[0] && vcm1 <= Vcm_bu1_bounds[1]);
	// case1.Vcm2_check = (vcm2 >= Vcm_bu2_bounds[1] && vcm2 <= Vcm_bu2_bounds[1]);
	// case1.KEcm1_check = (kecm1 >= KEcm_bu1_bounds[0] && kecm1 <= KEcm_bu1_bounds[1]);
	// case1.KEcm2_check = (kecm2 >= KEcm_bu2_bounds[0] && kecm2 <= KEcm_bu2_bounds[1]);
	// case1.Ecm_check = (ecm >= Ecm_bounds[0] && ecm <= Ecm_bounds[1]);
	// case1.ThetaCMSum_check = (theta1+theta2 >= ThetaCMSum_bounds[0] && theta1+theta2 <= ThetaCMSum_bounds[1]);
	// case1.PhiCMSep_check = (abs(phi1-phi2) >= PhiCMSep_bounds[0] && abs(phi1-phi2) <= PhiCMSep_bounds[1]);

	case1.Vcm1 = vcm1;
	case1.KEcm1 = kecm1;
	case1.ThetaCM1 = theta1;
	case1.PhiCM1 = phi1;

	case1.Vcm2 = vcm2;
	case1.KEcm2 = kecm2;
	case1.ThetaCM2 = theta2;
	case1.PhiCM2 = phi2;

	case1.Ecm = ecm;

	/*******************************************************
	 *					  CASE II BELOW:				   *
	 *******************************************************/
	//assume the mass is breakup2.mass
	mass_observed = this->breakup2.mass;
	Elab_observed = detectedE;
	Thetalab_observed = detectedTheta;
	Philab_observed = detectedPhi;

	mass_missing = this->breakup1.mass;


	plab_observed = sqrt(2*Elab_observed*mass_observed);
	plab_ej = sqrt(2*ejectileE*this->ejectile.mass);
	plab_beam = sqrt(2*this->beam_energy*this->beam.mass);
	plab_target = 0.;

	beam_4vect.SetPxPyPzE(0.,0.,plab_beam,this->beam.mass+this->beam_energy);
	target_4vect.SetPxPyPzE(0.,0.,0.,this->target.mass);
	ejectile_4vect.SetPxPyPzE(plab_ej*sin(degToRad*ejectileTheta)*cos(degToRad*ejectilePhi), plab_ej*sin(degToRad*ejectileTheta)*sin(degToRad*ejectilePhi), plab_ej*cos(degToRad*ejectileTheta), this->ejectile.mass+ejectileE);
	observed_4vect.SetPxPyPzE(plab_observed*sin(degToRad*Thetalab_observed)*cos(degToRad*Philab_observed), plab_observed*sin(degToRad*Thetalab_observed)*sin(degToRad*Philab_observed), plab_observed*cos(degToRad*Thetalab_observed), mass_observed+Elab_observed);

	recoil_4vect = beam_4vect + target_4vect - ejectile_4vect;
	missing_4vect = recoil_4vect - observed_4vect;
	boostvector = (-1/recoil_4vect.Energy())*recoil_4vect.Vect();

	recoil_ExcessEnergy = recoil_4vect.M() - this->recoil.mass;

	breakupAngleLab = radToDeg*acos(observed_4vect.Vect().Dot(missing_4vect.Vect())/(observed_4vect.Vect().Mag()*missing_4vect.Vect().Mag()));

	//boost into CM frame
	missing_4vect.Boost(boostvector);
	observed_4vect.Boost(boostvector);

	vcm1 = ((1/observed_4vect.Energy())*observed_4vect.Vect()).Mag();
	vcm2 = ((1/missing_4vect.Energy())*missing_4vect.Vect()).Mag();

	kecm1 = 0.5*mass_observed*vcm1*vcm1;
	kecm2 = 0.5*mass_missing*vcm2*vcm2;

	ecm = kecm1+kecm2;

	theta1 = radToDeg*acos(observed_4vect.Vect().Z()/observed_4vect.Vect().Mag());
	theta2 = radToDeg*acos(missing_4vect.Vect().Z()/missing_4vect.Vect().Mag());

	phi1 = radToDeg*atan2(observed_4vect.Vect().Y(),observed_4vect.Vect().X());
	phi2 = radToDeg*atan2(missing_4vect.Vect().Y(),missing_4vect.Vect().X());

	//perform checks and update case1:
	// case2.Vcm1_check = (vcm1 >= Vcm_bu1_bounds[0] && vcm1 <= Vcm_bu1_bounds[1]);
	// case2.Vcm2_check = (vcm2 >= Vcm_bu2_bounds[0] && vcm2 <= Vcm_bu2_bounds[1]);
	// case2.KEcm1_check = (kecm1 >= KEcm_bu1_bounds[0] && kecm1 <= KEcm_bu1_bounds[1]);
	// case2.KEcm2_check = (kecm2 >= KEcm_bu2_bounds[0] && kecm2 <= KEcm_bu2_bounds[1]);
	// case2.Ecm_check = (ecm >= Ecm_bounds[0] && ecm <= Ecm_bounds[1]);
	// case2.ThetaCMSum_check = (theta1+theta2 >= ThetaCMSum_bounds[0] && theta1+theta2 <= ThetaCMSum_bounds[1]);
	// case2.PhiCMSep_check = (abs(phi1-phi2) >= PhiCMSep_bounds[0] && abs(phi1-phi2) <= PhiCMSep_bounds[1]);

	case2.Vcm1 = vcm1;
	case2.KEcm1 = kecm1;
	case2.ThetaCM1 = theta1;
	case2.PhiCM1 = phi1;

	case2.Vcm2 = vcm2;
	case2.KEcm2 = kecm2;
	case2.ThetaCM2 = theta2;
	case2.PhiCM2 = phi2;

	case2.Ecm = ecm;

	
	std::pair<CaseResult,CaseResult> retval = std::make_pair(case1,case2);
	return retval;
}

Double_t IMMMA_Tool_3::AnalyzeEventCalculateRecoilExE(Double_t ejectileE, Double_t ejectileTheta, Double_t ejectilePhi){
	TLorentzVector beam, target, ejectile, recoil;
	beam.SetPxPyPzE(0.,0.,sqrt(2*this->beam_energy*this->beam.mass),this->beam_energy+this->beam.mass);
	target.SetPxPyPzE(0.,0.,0.,this->target.mass);
	Double_t pej = sqrt(2*ejectileE*this->ejectile.mass);
	ejectile.SetPxPyPzE(pej*sin(degToRad*ejectileTheta)*cos(degToRad*ejectilePhi), pej*sin(degToRad*ejectileTheta)*sin(degToRad*ejectilePhi), pej*cos(degToRad*ejectileTheta), this->ejectile.mass+ejectileE);

	recoil = beam + target - ejectile;

	return (recoil.M() - this->recoil.mass);
}