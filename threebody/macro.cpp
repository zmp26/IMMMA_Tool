#include "IMMMA_Tool_3.h"
#include "masstable.h"

void macro(){
	IMMMA_Tool_3 fTool_3;
	TMassTable fMassTable;


	fMassTable.Init("masstable.dat");

	//set up reaction information:
	fTool_3.SetBeamNucleus(3,"He",fMassTable.GetMassMeV("He",3));
	fTool_3.SetTargetNucleus(7,"Li",fMassTable.GetMassMeV("Li",7));
	fTool_3.SetEjectileNucleus(4,"He",fMassTable.GetMassMeV("He",4));
	fTool_3.SetRecoilNucleus(6,"Li",fMassTable.GetMassMeV("Li",6));
	fTool_3.SetBreakup1Nucleus(4,"He",fMassTable.GetMassMeV("He",4));
	fTool_3.SetBreakup2Nucleus(2,"H",fMassTable.GetMassMeV("H",2));

	fTool_3.SetBeamEnergy(7.5);
	fTool_3.SetRecoilExE(2.186);

	//calculate CM constants
	fTool_3.CalculateCMConstants();//this sets the "expected" value - that is what we expect that event-by-event distribution to be centered on
	//update CM constant bounds using "perfect" precision in energy angle (i.e. using kin3mc energy and angle output as is w/o any adjustments/smearing)
	//these were retrieved by fitting the "case1_IMM_correct/case1_Vcm1" and other "case1_" histograms from kin3mcPlotter w/ basic gaussian: /mnt/e/kinematics/kin3mc/kin3mcPlotter/
	fTool_3.SetVcm_bu1_bounds(1.32232e-04);//(sigma)
	fTool_3.SetVcm_bu2_bounds(2.61581e-04);//(sigma)
	fTool_3.SetKEcm_bu1_bounds(5.57896e-03);//(sigma)
	fTool_3.SetKEcm_bu2_bounds(1.10286e-02);//(sigma)
	fTool_3.SetEcm_bounds(1.66187e-02);//(sigma)

	//great, now fTool_3 is ready to do an event-by-event analysis of IMM data!
	TString infilepath = "kin3mc_100k_first100.out";//bu1 == 4He and bu2 == 2H in this input file!

	ifstream infile;
	infile.open(infilepath.Data());

	Float_t Elab_ej, Thetalab_ej, Philab_ej, Elab_rec, Thetalab_rec, Philab_rec, Elab_bu1, Thetalab_bu1, Philab_bu1, Elab_bu2, Thetalab_bu2, Philab_bu2;

	//prep output
	ofstream outfile1,outfile2,outfile3,outfile4;
	TString outfile1path = "macro1.txt", outfile2path = "macro2.txt", outfile3path = "macro3.txt", outfile4path = "macro4.txt";
	outfile1.open(outfile1path.Data());
	outfile2.open(outfile2path.Data());
	outfile3.open(outfile3path.Data());
	outfile4.open(outfile4path.Data());

	Float_t VCM1 = fTool_3.GetVcm_bu1();
	Float_t KECM1 = fTool_3.GetKEcm_bu1();
	Float_t VCM2 = fTool_3.GetVcm_bu2();
	Float_t KECM2 = fTool_3.GetKEcm_bu2();
	Float_t ECM = fTool_3.GetEcm();

	cout << endl;
	cout << VCM1 << endl;
	cout << KECM1 << endl << endl;
	cout << VCM2 << endl;
	cout << KECM2 << endl << endl;
	cout << ECM << endl << endl;

	cout << "M_target = " << fTool_3.GetTargetMass() << endl;
	cout << "M_beam = " << fTool_3.GetBeamMass() << endl;
	cout << "M_ej = " << fTool_3.GetEjectileMass() << endl;
	cout << "M_recoil = " << fTool_3.GetRecoilMass() << endl;
	cout << "M_bu1 = " << fTool_3.GetBreakup1Mass() << endl;
	cout << "M_bu2 = " << fTool_3.GetBreakup2Mass() << endl;
	cout << endl;

	TString header1 = "Elab_ej\tThetalab_ej\tPhilab_ej\tElab_rec\tThetalab_rec\tPhilab_rec\tElab_bu1\tThetalab_bu1\tPhilab_bu1\tElab_bu2\tThetalab_bu2\tPhilab_bu2\tThetaCM1\tPhiCM1\tVcm1\tKEcm1\tThetaCM1\tPhiCM2\tVcm2\tKEcm2\tThetaCMSum\tPhiCMSep\tEcm";
	TString header2 = "Elab_ej\tThetalab_ej\tPhilab_ej\tElab_rec\tThetalab_rec\tPhilab_rec\tElab_bu1\tThetalab_bu1\tPhilab_bu1\tElab_bu2\tThetalab_bu2\tPhilab_bu2\tobservedThetaCM\tobservedPhiCM\tobservedVcm\tobservedKEcm\tmissingThetaCM\tmissingPhiCM\tmissingVcm\tmissingKEcm\tThetaCMSum\tPhiCMSep\tEcm";

	outfile1 << header1 << endl;
	outfile2 << header1 << endl;
	outfile3 << header2 << endl;
	outfile4 << header2 << endl;


	Int_t count1 = 0, count2 = 0, count3 = 0, count4 = 0;
	Int_t count = 0;

	while(infile >> Elab_ej >> Thetalab_ej >> Philab_ej >> Elab_rec >> Thetalab_rec >> Philab_rec >> Elab_bu1 >> Thetalab_bu1 >> Philab_bu1 >> Elab_bu2 >> Thetalab_bu2 >> Philab_bu2){
		TString kinline = Form("%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f",Elab_ej,Thetalab_ej,Philab_ej,Elab_rec,Thetalab_rec,Philab_rec,Elab_bu1,Thetalab_bu1,Philab_bu1,Elab_bu2,Thetalab_bu2,Philab_bu2);


		//---------------------------------------------------------EVENT ANALYSIS-------------------------------------------------------------------------------------------------------------
		//perform the IMM calculation for both cases for the data
		//recall that case1 will be the bu1 assumption and case2 will be the bu2 assumption!
		std::pair<CaseResult,CaseResult> IMMresults = fTool_3.AnalyzeEventIMM(Elab_ej,Thetalab_ej,Philab_ej,Elab_bu1,Thetalab_bu1,Philab_bu1,Elab_bu2,Thetalab_bu2,Philab_bu2);
		CaseResult IMMcorrect = IMMresults.first;
		CaseResult IMMwrong = IMMresults.second;

		std::pair<CaseResult,CaseResult> MMMresults = fTool_3.AnalyzeEventMMM(Elab_ej,Thetalab_ej,Philab_ej,Elab_bu1,Thetalab_bu1,Philab_bu1);
		CaseResult MMMcorrect = MMMresults.first;
		CaseResult MMMwrong = MMMresults.second;

		//---------------------------------------------------------CASE DETERMINATION-------------------------------------------------------------------------------------------------------------
		//perform the CMConstant checks to determine whether case0 (.first) or case1 (.second) is the proper case to treat this event

		//IMM checks
		Int_t IMMfirstcount = 0, IMMsecondcount = 0;
		if(fTool_3.CheckInBounds_Vcm_bu1(IMMresults.first.Vcm1)) IMMfirstcount += 1;
		if(fTool_3.CheckInBounds_Vcm_bu2(IMMresults.first.Vcm2)) IMMfirstcount += 1;
		if(fTool_3.CheckInBounds_KEcm_bu1(IMMresults.first.KEcm1)) IMMfirstcount += 1;
		if(fTool_3.CheckInBounds_KEcm_bu2(IMMresults.first.KEcm1)) IMMfirstcount += 1;
		if(fTool_3.CheckInBounds_Ecm(IMMresults.first.Ecm)) IMMfirstcount += 1;

		if(fTool_3.CheckInBounds_Vcm_bu1(IMMresults.second.Vcm1)) IMMsecondcount += 1;
		if(fTool_3.CheckInBounds_Vcm_bu2(IMMresults.second.Vcm2)) IMMsecondcount += 1;
		if(fTool_3.CheckInBounds_KEcm_bu1(IMMresults.second.KEcm1)) IMMsecondcount += 1;
		if(fTool_3.CheckInBounds_KEcm_bu2(IMMresults.second.KEcm1)) IMMsecondcount += 1;
		if(fTool_3.CheckInBounds_Ecm(IMMresults.second.Ecm)) IMMsecondcount += 1;

		TString IMM_casedet;
		if(IMMfirstcount > IMMsecondcount){
			//case1 determined to be more correct
			IMM_casedet = Form("det1 = %s\tdet2 = %s\t(first)\t%d/%d", (fTool_3.GetBreakup1Nucleus().ToString()).Data(), (fTool_3.GetBreakup2Nucleus().ToString()).Data(),IMMfirstcount, 5);
			count1 += 1;
		} else if(IMMfirstcount < IMMsecondcount){
			//case2 determined to be more correct
			IMM_casedet = Form("det1 = %s\tdet2 = %s\t(second)\t%d/%d", (fTool_3.GetBreakup2Nucleus().ToString()).Data(), (fTool_3.GetBreakup1Nucleus().ToString()).Data(), IMMsecondcount, 5);
			count2 += 1;
		} else {
			IMM_casedet = Form("cannot determine one case over the other\t%d/%d\t%d/%d",IMMfirstcount,5,IMMsecondcount,5);
		}

		//MMM checks
		Int_t MMMfirstcount = 0, MMMsecondcount = 0;
		if(fTool_3.CheckInBounds_Vcm_bu1(MMMresults.first.Vcm1)) MMMfirstcount += 1;
		if(fTool_3.CheckInBounds_Vcm_bu2(MMMresults.first.Vcm2)) MMMfirstcount += 1;
		if(fTool_3.CheckInBounds_KEcm_bu1(MMMresults.first.KEcm1)) MMMfirstcount += 1;
		if(fTool_3.CheckInBounds_KEcm_bu2(MMMresults.first.KEcm1)) MMMfirstcount += 1;
		if(fTool_3.CheckInBounds_Ecm(MMMresults.first.Ecm)) MMMfirstcount += 1;

		if(fTool_3.CheckInBounds_Vcm_bu1(MMMresults.second.Vcm1)) MMMsecondcount += 1;
		if(fTool_3.CheckInBounds_Vcm_bu2(MMMresults.second.Vcm2)) MMMsecondcount += 1;
		if(fTool_3.CheckInBounds_KEcm_bu1(MMMresults.second.KEcm1)) MMMsecondcount += 1;
		if(fTool_3.CheckInBounds_KEcm_bu2(MMMresults.second.KEcm1)) MMMsecondcount += 1;
		if(fTool_3.CheckInBounds_Ecm(MMMresults.second.Ecm)) MMMsecondcount += 1;

		TString MMM_casedet;
		if(MMMfirstcount > MMMsecondcount){
			//case1 determined to be more correct
			MMM_casedet = Form("det = %s\tmiss = %s\t(first)\t%d/%d", fTool_3.GetBreakup1Nucleus().ToString().Data(), fTool_3.GetBreakup2Nucleus().ToString().Data(), MMMfirstcount, 5);
			count3 += 1;
		} else if(MMMfirstcount < MMMsecondcount){
			//case2 determined to be more correct
			MMM_casedet = Form("det = %s\tmiss = %s\t(second)\t%d/%d", fTool_3.GetBreakup2Nucleus().ToString().Data(), fTool_3.GetBreakup1Nucleus().ToString().Data(), MMMsecondcount, 5);
			count4 += 1;
		} else {
			MMM_casedet = Form("cannot determine once case over the other\t%d/%d\t%d/%d",MMMfirstcount,5,MMMsecondcount,5);
		}

		cout << "event " << count << endl;
		cout << "\tIMM case determination: " << IMM_casedet << endl;
		cout << "\tMMM case determination: " << MMM_casedet << endl;
		cout << endl;


		//---------------------------------------------------------FILE OUTPUT-------------------------------------------------------------------------------------------------------------
		//ThetaCM1 PhiCM1 VCM1 KECM1 ThetaCM2 PhiCM2 VCM2 KECM2 ThetaSUM PhiSep Ecm
		TString outline1 = Form("%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f",IMMcorrect.ThetaCM1,IMMcorrect.PhiCM1,IMMcorrect.Vcm1,IMMcorrect.KEcm1,IMMcorrect.ThetaCM2,IMMcorrect.PhiCM2,IMMcorrect.Vcm2,IMMcorrect.KEcm2,IMMcorrect.ThetaCM1+IMMcorrect.ThetaCM2,abs(IMMcorrect.PhiCM1-IMMcorrect.PhiCM2),IMMcorrect.Ecm);
		TString outline2 = Form("%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f",IMMwrong.ThetaCM1,IMMwrong.PhiCM1,IMMwrong.Vcm1,IMMwrong.KEcm1,IMMwrong.ThetaCM2,IMMwrong.PhiCM2,IMMwrong.Vcm2,IMMwrong.KEcm2,IMMwrong.ThetaCM1+IMMwrong.ThetaCM2,abs(IMMwrong.PhiCM1-IMMwrong.PhiCM2),IMMwrong.Ecm);
		TString outline3 = Form("%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f",MMMcorrect.ThetaCM1,MMMcorrect.PhiCM1,MMMcorrect.Vcm1,MMMcorrect.KEcm1,MMMcorrect.ThetaCM2,MMMcorrect.PhiCM2,MMMcorrect.Vcm2,MMMcorrect.KEcm2,MMMcorrect.ThetaCM1+MMMcorrect.ThetaCM2,abs(MMMcorrect.PhiCM1-MMMcorrect.PhiCM2),MMMcorrect.Ecm);
		TString outline4 = Form("%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f",MMMwrong.ThetaCM1,MMMwrong.PhiCM1,MMMwrong.Vcm1,MMMwrong.KEcm1,MMMwrong.ThetaCM2,MMMwrong.PhiCM2,MMMwrong.Vcm2,MMMwrong.KEcm2,MMMwrong.ThetaCM1+MMMwrong.ThetaCM2,abs(MMMwrong.PhiCM1-MMMwrong.PhiCM2),MMMwrong.Ecm);

		outfile1 << kinline << "\t" << outline1 << endl;
		outfile2 << kinline << "\t" << outline2 << endl;
		outfile3 << kinline << "\t" << outline3 << endl;
		outfile4 << kinline << "\t" << outline4 << endl;

		count += 1;
	}



	infile.close();
	outfile1.close();
	outfile2.close();
	outfile3.close();
	outfile4.close();

	cout << endl;
	cout << "Sucess!" << endl;
	cout << "IMM Correct mass assumption results found in: " << outfile1path << endl;
	cout << "IMM Wrong mass assumption results found in: " << outfile2path << endl;
	cout << "MMM Correct mass assumption results found in: " << outfile3path << endl;
	cout << "MMM Wrong mass assumption results found in: " << outfile4path << endl;
	cout << endl;
	cout << endl;
	cout << "efficiencies:" << endl;
	cout << "IMM correct:\t" << count1 << "/" << count << " = " << float(count1)/float(count) << endl;
	cout << "IMM wrong:\t" << count2 << "/" << count << " = " << float(count2)/float(count) << endl;
	cout << "MMMcorrect:\t" << count3 << "/" << count << " = " << float(count3)/float(count) << endl;
	cout << "MMMwrong:\t" << count4 << "/" << count << " = " << float(count4)/float(count) << endl;
	cout << endl;

}