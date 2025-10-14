#include "IMMMA_Tool_4.h"
#include "TLorentzVector.h"

std::array<CaseResult4, 6> IMMMA_Tool_4::AnalyzeIMMEvent(Double_t ejectileE, Double_t ejectileTheta, Double_t ejectilePhi,
								   Double_t detected1E, Double_t detected1Theta, Double_t detected1Phi,
								   Double_t detected2E, Double_t detected2Theta, Double_t detected2Phi,
								   Double_t detected3E, Double_t detected3Theta, Double_t detected3Phi)
{

	std::array<CaseResult4, 6> results;

	Double_t cE, cTheta, cPhi, dE, dTheta, dPhi, eE, eTheta, ePhi;

	TLorentzVector beam_4vect, target_4vect, ejectile_4vect, recoil_4vect, breakup1_4vect, breakup2_4vect, breakup3_4vect;
	
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
	Double_t philab2 = radToDeg*atan2(breakup2_4vect.Vect.Y(), breakup2_4vect.Vect().X());

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