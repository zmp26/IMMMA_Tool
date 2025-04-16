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
	this->ThetaCMSum = 180.;
	this->PhiCMSep = 180.;
}

//setters
void IMMMA_Tool_3::SetBeamNucleus(Int_t A, TString sym, Float_t mass){
	this->beam.A = A;
	this->beam.sym = sym;
	this->beam.mass = mass;
}

void IMMMA_Tool_3::SetTargetNucleus(Int_t A, TString sym, Float_t mass){
	this->target.A = A;
	this->target.sym = sym;
	this->target.mass = mass;
}

void IMMMA_Tool_3::SetEjectileNucleus(Int_t A, TString sym, Float_t mass){
	this->ejectile.A = A;
	this->ejectile.sym = sym;
	this->ejectile.mass = mass;
}

void IMMMA_Tool_3::SetRecoilNucleus(Int_t A, TString sym, Float_t mass){
	this->recoil.A = A;
	this->recoil.sym = sym;
	this->recoil.mass = mass;
}

void IMMMA_Tool_3::SetBreakup1Nucleus(Int_t A, TString sym, Float_t mass){
	this->breakup1.A = A;
	this->breakup1.sym = sym;
	this->breakup1.mass = mass;
}

void IMMMA_Tool_3::SetBreakup2Nucleus(Int_t A, TString sym, Float_t mass){
	this->breakup2.A = A;
	this->breakup2.sym = sym;
	this->breakup2.mass = mass;
}

void IMMMA_Tool_3::SetBeamEnergy(Float_t energy){
	this->beam_energy = energy;
}

void IMMMA_Tool_3::SetRecoilExE(Float_t energy){
	this->recoil_exE = energy;
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

Float_t IMMMA_Tool_3::GetBeamMass(){
	return this->beam.mass;
}

Float_t IMMMA_Tool_3::GetTargetMass(){
	return this->target.mass;
}

Float_t IMMMA_Tool_3::GetEjectileMass(){
	return this->ejectile.mass;
}

Float_t IMMMA_Tool_3::GetRecoilMass(){
	return this->recoil.mass;
}

Float_t IMMMA_Tool_3::GetBreakup1Mass(){
	return this->breakup1.mass;
}

Float_t IMMMA_Tool_3::GetBreakup2Mass(){
	return this->breakup2.mass;
}

Float_t IMMMA_Tool_3::GetBeamEnergy(){
	return this->beam_energy;
}

Float_t IMMMA_Tool_3::GetRecoilExE(){
	return this->recoil_exE;
}

TLorentzVector IMMMA_Tool_3::GetBeamLVect(){
	return this->beam_4vect;
}

TLorentzVector IMMMA_Tool_3::GetTargetLVect(){
	return this->target_4vect;
}

TLorentzVector IMMMA_Tool_3::GetEjectileLVect(){
	return this->ejectile_4vect;
}

TLorentzVector IMMMA_Tool_3::GetRecoilLVect(){
	return this->recoil_4vect;
}

TLorentzVector IMMMA_Tool_3::GetBreakup1LVect(){
	return this->breakup1_4vect;
}

TLorentzVector IMMMA_Tool_3::GetBreakup2LVect(){
	return this->breakup2_4vect;
}

Float_t IMMMA_Tool_3::GetVcm_bu1(){
	return this->Vcm_bu1;
}

Float_t IMMMA_Tool_3::GetVcm_bu2(){
	return this->Vcm_bu2;
}

Float_t IMMMA_Tool_3::GetKEcm_bu1(){
	return this->KEcm_bu1;
}

Float_t IMMMA_Tool_3::GetKEcm_bu2(){
	return this->KEcm_bu2;
}

Float_t IMMMA_Tool_3::GetEcm(){
	return this->Ecm;
}

TString IMMMA_Tool_3::GetReactionString(){
	return this->reaction;
}

TString IMMMA_Tool_3::GetBreakupString(){
	return this->breakup;
}

//init reaction function
void IMMMA_Tool_3::CalculateCMConstants(){
	if(this->recoil.Filled() && this->breakup1.Filled() && this->breakup2.Filled()){
		this->Ecm = this->recoil.mass + this->recoil_exE - this->breakup1.mass - this->breakup2.mass;
		this->Vcm_bu1 = sqrt(2*this->breakup2.mass*this->Ecm/(this->breakup1.mass*(this->breakup1.mass + this->breakup2.mass)));
		this->Vcm_bu2 = sqrt(2*this->breakup1.mass*this->Ecm/(this->breakup2.mass*(this->breakup1.mass + this->breakup2.mass)));
		this->KEcm_bu1 = 0.5*this->breakup1.mass*GetVcm_bu1()*GetVcm_bu1();
		this->KEcm_bu2 = 0.5*this->breakup2.mass*GetVcm_bu2()*GetVcm_bu2();
	} else {
		this->Ecm = -666;
		this->Vcm_bu1 = -666;
		this->Vcm_bu2 = -666;
		this->KEcm_bu1 = -666;
		this->KEcm_bu2 = -666;
	}
	//set bounds:
	this->Vcm_bu1_bounds[0] = 0.99*this->Vcm_bu1;
	this->Vcm_bu1_bounds[1] = 1.01*this->Vcm_bu1;

	this->Vcm_bu2_bounds[0] = 0.99*this->Vcm_bu2;
	this->Vcm_bu2_bounds[1] = 1.01*this->Vcm_bu2;

	this->KEcm_bu1_bounds[0] = 0.99*this->KEcm_bu1;
	this->KEcm_bu1_bounds[1] = 1.01*this->KEcm_bu1;

	this->KEcm_bu2_bounds[0] = 0.99*this->KEcm_bu2;
	this->KEcm_bu2_bounds[1] = 1.01*this->KEcm_bu2;

	this->Ecm_bounds[0] = 0.99*this->Ecm;
	this->Ecm_bounds[1] = 1.01*this->Ecm;

	this->ThetaCMSum_bounds[0] = this->ThetaCMSum-0.5;
	this->ThetaCMSum_bounds[1] = this->ThetaCMSum+0.5;

	this->PhiCMSep_bounds[0] = this->PhiCMSep-0.5;
	this->PhiCMSep_bounds[1] = this->PhiCMSep+0.5;
}

//IMM Event Analysis Function:
DoubleCaseCheckResult IMMMA_Tool_3::AnalyzeEventIMM(Float_t ejectileE, Float_t ejectileTheta, Float_t ejectilePhi, Float_t detected1E, Float_t detected1Theta, Float_t detected1Phi, Float_t detected2E, Float_t detected2Theta, Float_t detected2Phi){

	DoubleCaseCheckResult retval;

	/*******************************************************
	 *					  CASE I BELOW:				 	   *
	 *******************************************************/
	//in this case we detect the ejectile and two particles we assume to be the break up particles.
	//Case 1 is the case in which detected1 uses mass information from breakup1
	//			              and detected2 uses mass information from breakup2

	Float_t plab_detected1 = sqrt(2*detected1E*this->breakup1.mass);
	Float_t plab_detected2 = sqrt(2*detected2E*this->breakup2.mass);

	Float_t plab_ej = sqrt(2*ejectileE*this->ejectile.mass);
	Float_t plab_beam = sqrt(2*this->beam_energy*this->beam.mass);
	Float_t plab_target = 0.;

	//initialize the 4vectors from this information:
	this->beam_4vect.SetPxPyPzE(0.,0.,plab_beam,this->beam.mass+this->beam_energy);
	this->target_4vect.SetPxPyPzE(0.,0.,0.,this->target.mass);
	this->ejectile_4vect.SetPxPyPzE(plab_ej*sin(degToRad*ejectileTheta)*cos(degToRad*ejectilePhi), plab_ej*sin(degToRad*ejectileTheta)*sin(degToRad*ejectilePhi), plab_ej*cos(degToRad*ejectileTheta), this->ejectile.mass+ejectileE);
	this->breakup1_4vect.SetPxPyPzE(plab_detected1*sin(degToRad*detected1Theta)*cos(degToRad*detected1Phi), plab_detected1*sin(degToRad*detected1Theta)*sin(degToRad*detected1Phi), plab_detected1*cos(degToRad*detected1Theta), this->breakup1.mass+detected1E);
	this->breakup2_4vect.SetPxPyPzE(plab_detected2*sin(degToRad*detected2Theta)*cos(degToRad*detected2Phi), plab_detected2*sin(degToRad*detected2Theta)*sin(degToRad*detected2Phi), plab_detected2*cos(degToRad*detected2Theta), this->breakup2.mass+detected2E);

	//reconstruct recoil_4vect from beam, target, and ejectile information:
	this->recoil_4vect = this->beam_4vect + this->target_4vect - this->ejectile_4vect;

	//calculate the excitation energy of the recoil:
	Float_t recoil_ExcessEnergy = this->recoil_4vect.M() - this->recoil.mass;//this excess energy is entirely due to excitation!

	//calculate breakup angle in the lab:
	Float_t breakupAngleLab = radToDeg*acos(this->breakup1_4vect.Vect().Dot(this->breakup2_4vect.Vect())/(this->breakup1_4vect.Vect().Mag()*this->breakup2_4vect.Vect().Mag()));

	//obtain the boost vector to boost into the breakup CM frame:
	TVector3 boostvector = (-1/this->recoil_4vect.Energy())*this->recoil_4vect.Vect();

	//boost breakup1_4vect and breakup2_4vect into the CM frame:
	this->breakup1_4vect.Boost(boostvector);
	this->breakup2_4vect.Boost(boostvector);

	//calculate CM variables from the boosted momenta:
	Float_t vcm1 = ((1/this->breakup1_4vect.Energy())*this->breakup1_4vect.Vect()).Mag();
	Float_t vcm2 = ((1/this->breakup2_4vect.Energy())*this->breakup2_4vect.Vect()).Mag();

	Float_t kecm1 = 0.5*this->breakup1.mass*vcm1*vcm1;
	Float_t kecm2 = 0.5*this->breakup2.mass*vcm2*vcm2;

	Float_t ecm = kecm1 + kecm2;

	Float_t theta1 = radToDeg*acos(breakup1_4vect.Vect().Z()/breakup1_4vect.Vect().Mag());
	Float_t phi1 = radToDeg*atan2(breakup1_4vect.Vect().Y(),breakup1_4vect.Vect().X());

	Float_t theta2 = radToDeg*acos(breakup2_4vect.Vect().Z()/breakup2_4vect.Vect().Mag());
	Float_t phi2 = radToDeg*atan2(breakup2_4vect.Vect().Y(), breakup2_4vect.Vect().X());

	//perform checks and update retval.assignment1:
	retval.assignment1.Vcm1_check = (vcm1 >= Vcm_bu1_bounds[0] && vcm1 <= Vcm_bu1_bounds[1]);
	retval.assignment1.Vcm2_check = (vcm2 >= Vcm_bu2_bounds[1] && vcm2 <= Vcm_bu2_bounds[1]);
	retval.assignment1.KEcm1_check = (kecm1 >= KEcm_bu1_bounds[0] && kecm1 <= KEcm_bu1_bounds[1]);
	retval.assignment1.KEcm2_check = (kecm2 >= KEcm_bu2_bounds[0] && kecm2 <= KEcm_bu2_bounds[1]);
	retval.assignment1.Ecm_check = (ecm >= Ecm_bounds[0] && ecm <= Ecm_bounds[1]);
	retval.assignment1.ThetaCMSum_check = (theta1+theta2 >= ThetaCMSum_bounds[0] && theta1+theta2 <= ThetaCMSum_bounds[1]);
	retval.assignment1.PhiCMSep_check = (abs(phi1-phi2) >= PhiCMSep_bounds[0] && abs(phi1-phi2) <= PhiCMSep_bounds[1]);

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
	this->beam_4vect.SetPxPyPzE(0.,0.,plab_beam,this->beam.mass+this->beam_energy);
	this->target_4vect.SetPxPyPzE(0.,0.,0.,this->target.mass);
	this->ejectile_4vect.SetPxPyPzE(plab_ej*sin(degToRad*ejectileTheta)*cos(degToRad*ejectilePhi), plab_ej*sin(degToRad*ejectileTheta)*sin(degToRad*ejectilePhi), plab_ej*cos(degToRad*ejectileTheta), this->ejectile.mass+ejectileE);
	this->breakup1_4vect.SetPxPyPzE(plab_detected1*sin(degToRad*detected1Theta)*cos(degToRad*detected1Phi), plab_detected1*sin(degToRad*detected1Theta)*sin(degToRad*detected1Phi), plab_detected1*cos(degToRad*detected1Theta), this->breakup2.mass+detected1E);
	this->breakup2_4vect.SetPxPyPzE(plab_detected2*sin(degToRad*detected2Theta)*cos(degToRad*detected2Phi), plab_detected2*sin(degToRad*detected2Theta)*sin(degToRad*detected2Phi), plab_detected2*cos(degToRad*detected2Theta), this->breakup1.mass+detected2E);

	//reconstruct recoil_4vect from beam, target, and ejectile information:
	this->recoil_4vect = this->beam_4vect + this->target_4vect - this->ejectile_4vect;

	//calculate the excitation energy of the recoil:
	recoil_ExcessEnergy = this->recoil_4vect.M() - this->recoil.mass;

	//calculate breakup angle in the lab:
	breakupAngleLab = radToDeg*acos(this->breakup1_4vect.Vect().Dot(this->breakup2_4vect.Vect())/(this->breakup1_4vect.Vect().Mag()*this->breakup2_4vect.Vect().Mag()));

	//obtain the boost vector to boost into the breakup CM frame:
	boostvector = (-1/this->recoil_4vect.Energy())*this->recoil_4vect.Vect();

	//boost breakup1_4vect and breakup2_4vect into CM frame:
	this->breakup1_4vect.Boost(boostvector);
	this->breakup2_4vect.Boost(boostvector);

	//calculate CM variables from boosted momenta:
	vcm1 = ((1/this->breakup1_4vect.Energy())*this->breakup1_4vect.Vect()).Mag();
	vcm2 = ((1/this->breakup2_4vect.Energy())*this->breakup2_4vect.Vect()).Mag();

	kecm1 = 0.5*this->breakup2.mass*vcm1*vcm1;
	kecm2 = 0.5*this->breakup1.mass*vcm2*vcm2;

	ecm = kecm1 + kecm2;

	theta1 = radToDeg*acos(breakup1_4vect.Vect().Z()/breakup1_4vect.Vect().Mag());
	phi1 = radToDeg*atan2(breakup1_4vect.Vect().Y(),breakup1_4vect.Vect().X());

	theta2 = radToDeg*acos(breakup2_4vect.Vect().Z()/breakup2_4vect.Vect().Mag());
	phi2 = radToDeg*atan2(breakup2_4vect.Vect().Y(),breakup2_4vect.Vect().X());

	//perform checks and update retval.assignment2:
	retval.assignment2.Vcm1_check = (vcm1 >= Vcm_bu1_bounds[0] && vcm1 <= Vcm_bu1_bounds[1]);
	retval.assignment2.Vcm2_check = (vcm2 >= Vcm_bu2_bounds[1] && vcm1 <= Vcm_bu2_bounds[1]);
	retval.assignment2.KEcm1_check = (kecm1 >= KEcm_bu1_bounds[0] && kecm1 <= KEcm_bu1_bounds[1]);
	retval.assignment2.KEcm2_check = (kecm2 >= KEcm_bu2_bounds[0] && kecm2 <= KEcm_bu2_bounds[1]);
	retval.assignment2.Ecm_check = (ecm >= Ecm_bounds[0] && ecm <= Ecm_bounds[1]);
	retval.assignment2.ThetaCMSum_check = (theta1+theta2 >= ThetaCMSum_bounds[0] && theta1+theta2 <= ThetaCMSum_bounds[1]);
	retval.assignment2.PhiCMSep_check = (abs(phi1-phi2) >= PhiCMSep_bounds[0] && abs(phi1-phi2) <= PhiCMSep_bounds[1]);


	//return retval
	return retval;
}

DoubleCaseCheckResult IMMMA_Tool_3::AnalyzeEventMMM(Float_t ejectileE, Float_t ejectileTheta, Float_t ejectilePhi, Float_t detectedE, Float_t detectedTheta, Float_t detectedPhi){
	DoubleCaseCheckResult retval;
	retval.assignment1.Vcm1_check=false;
	retval.assignment1.Vcm2_check=false;
	retval.assignment1.KEcm1_check=false;
	retval.assignment1.KEcm2_check=false;
	retval.assignment1.Ecm_check=false;
	retval.assignment1.ThetaCMSum_check=false;
	retval.assignment1.PhiCMSep_check=false;
	retval.assignment2.Vcm1_check=false;
	retval.assignment2.Vcm2_check=false;
	retval.assignment2.KEcm1_check=false;
	retval.assignment2.KEcm2_check=false;
	retval.assignment2.Ecm_check=false;
	retval.assignment2.ThetaCMSum_check=false;
	retval.assignment2.PhiCMSep_check=false;
	return retval;
}

