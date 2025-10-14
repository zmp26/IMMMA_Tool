#include "IMMMA_Tool_3.h"
#include "masstable.h"

TH1F *IMMfirst_Vcm1, *IMMfirst_Vcm2, *IMMfirst_KEcm1, *IMMfirst_KEcm2, *IMMfirst_Ecm, *IMMsecond_Vcm1, *IMMsecond_Vcm2, *IMMsecond_KEcm1, *IMMsecond_KEcm2, *IMMsecond_Ecm;
TH1F *MMMfirst_Vcm1, *MMMfirst_Vcm2, *MMMfirst_KEcm1, *MMMfirst_KEcm2, *MMMfirst_Ecm, *MMMsecond_Vcm1, *MMMsecond_Vcm2, *MMMsecond_KEcm1, *MMMsecond_KEcm2, *MMMsecond_Ecm;

void initHistos(){
	IMMfirst_Vcm1 = new TH1F("IMMfirst_Vcm1", "Vcm1 (IMM first case)", 256, 0.010, 0.012);
	IMMfirst_Vcm2 = new TH1F("IMMfirst_Vcm2", "Vcm2 (IMM first case)", 256, 0.020, 0.024);
	IMMfirst_KEcm1 = new TH1F("IMMfirst_KEcm1", "KEcm1 (IMM first case)", 256, 0.218, 0.260);
	IMMfirst_KEcm2 = new TH1F("IMMfirst_KEcm2", "KEcm2 (IMM first case)", 256, 0.433, 0.514);
	IMMfirst_Ecm = new TH1F("IMMfirst_Ecm", "Ecm (IMM first case)", 256, 0.650, 0.773);

	IMMsecond_Vcm1 = new TH1F("IMMsecond_Vcm1", "Vcm1 (IMM second case)", 256, 0.010, 0.012);
	IMMsecond_Vcm2 = new TH1F("IMMsecond_Vcm2", "Vcm2 (IMM second case)", 256, 0.020, 0.024);
	IMMsecond_KEcm1 = new TH1F("IMMsecond_KEcm1", "KEcm1 (IMM second case)", 256, 0.218, 0.260);
	IMMsecond_KEcm2 = new TH1F("IMMsecond_KEcm2", "KEcm2 (IMM second case)", 256, 0.433, 0.514);
	IMMsecond_Ecm = new TH1F("IMMsecond_Ecm", "Ecm (IMM second case)", 256, 0.650, 0.773);

	MMMfirst_Vcm1 = new TH1F("MMMfirst_Vcm1", "Vcm1 (MMM first case)", 256, 0.010, 0.012);
	MMMfirst_Vcm2 = new TH1F("MMMfirst_Vcm2", "Vcm2 (MMM first case)", 256, 0.020, 0.024);
	MMMfirst_KEcm1 = new TH1F("MMMfirst_KEcm1", "KEcm1 (MMM first case)", 256, 0.218, 0.260);
	MMMfirst_KEcm2 = new TH1F("MMMfirst_KEcm2", "KEcm2 (MMM first case)", 256, 0.433, 0.514);
	MMMfirst_Ecm = new TH1F("MMMfirst_Ecm", "Ecm (MMM first case)", 256, 0.650, 0.773);

	MMMsecond_Vcm1 = new TH1F("MMMsecond_Vcm1", "Vcm1 (MMM second case)", 256, 0.010, 0.012);
	MMMsecond_Vcm2 = new TH1F("MMMsecond_Vcm2", "Vcm2 (MMM second case)", 256, 0.020, 0.024);
	MMMsecond_KEcm1 = new TH1F("MMMsecond_KEcm1", "KEcm1 (MMM second case)", 256, 0.218, 0.260);
	MMMsecond_KEcm2 = new TH1F("MMMsecond_KEcm2", "KEcm2 (MMM second case)", 256, 0.433, 0.514);
	MMMsecond_Ecm = new TH1F("MMMsecond_Ecm", "Ecm (MMM second case)", 256, 0.650, 0.773);
}

void macro(){
	initHistos();

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
	TString outfile1path = "macro1_1.txt", outfile2path = "macro1_2.txt", outfile3path = "macro1_3.txt", outfile4path = "macro1_4.txt";
	outfile1.open(outfile1path.Data());
	outfile2.open(outfile2path.Data());
	outfile3.open(outfile3path.Data());
	outfile4.open(outfile4path.Data());

	CMConstant VCM1, KECM1, VCM2, KECM2, ECM;

	VCM1 = fTool_3.GetVcm_bu1();
	VCM2 = fTool_3.GetVcm_bu2();
	KECM1 = fTool_3.GetKEcm_bu1();
	KECM2 = fTool_3.GetKEcm_bu2();
	ECM = fTool_3.GetEcm();

	cout << endl;
	cout << "VCM1\t=\t" << VCM1.expected << Form("\t\trange: (%f, %f)",VCM1.lower,VCM1.upper) << endl;
	cout << "KECM1\t=\t" << KECM1.expected << Form("\t\trange: (%f, %f)",KECM1.lower,KECM1.upper) << endl;
	cout << "VCM2\t=\t" << VCM2.expected << Form("\t\trange: (%f, %f)",VCM2.lower,VCM2.upper) << endl;
	cout << "KECM2\t=\t" << KECM2.expected << Form("\t\trange: (%f, %f)",KECM2.lower,KECM2.upper) << endl;
	cout << "ECM\t=\t" << ECM.expected << Form("\t\trange: (%f, %f)",ECM.lower,ECM.upper) << endl;
	cout << endl;

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
		//fill histograms:
		IMMfirst_Vcm1->Fill(IMMresults.first.Vcm1);
		IMMfirst_Vcm2->Fill(IMMresults.first.Vcm2);
		IMMfirst_KEcm1->Fill(IMMresults.first.KEcm1);
		IMMfirst_KEcm2->Fill(IMMresults.first.KEcm2);
		IMMfirst_Ecm->Fill(IMMresults.first.Ecm);
		IMMsecond_Vcm1->Fill(IMMresults.second.Vcm1);
		IMMsecond_Vcm2->Fill(IMMresults.second.Vcm2);
		IMMsecond_KEcm1->Fill(IMMresults.second.KEcm1);
		IMMsecond_KEcm2->Fill(IMMresults.second.KEcm2);
		IMMsecond_Ecm->Fill(IMMresults.second.Ecm);

		std::pair<CaseResult,CaseResult> MMMresults = fTool_3.AnalyzeEventMMM(Elab_ej,Thetalab_ej,Philab_ej,Elab_bu1,Thetalab_bu1,Philab_bu1);
		CaseResult MMMcorrect = MMMresults.first;
		CaseResult MMMwrong = MMMresults.second;
		MMMfirst_Vcm1->Fill(MMMresults.first.Vcm1);
		MMMfirst_Vcm2->Fill(MMMresults.first.Vcm2);
		MMMfirst_KEcm1->Fill(MMMresults.first.KEcm1);
		MMMfirst_KEcm2->Fill(MMMresults.first.KEcm2);
		MMMfirst_Ecm->Fill(MMMresults.first.Ecm);
		MMMsecond_Vcm1->Fill(MMMresults.second.Vcm1);
		MMMsecond_Vcm2->Fill(MMMresults.second.Vcm2);
		MMMsecond_KEcm1->Fill(MMMresults.second.KEcm1);
		MMMsecond_KEcm2->Fill(MMMresults.second.KEcm2);
		MMMsecond_Ecm->Fill(MMMresults.second.Ecm);

		//---------------------------------------------------------CASE DETERMINATION-------------------------------------------------------------------------------------------------------------
		//perform the CMConstant checks to determine whether case0 (.first) or case1 (.second) is the proper case to treat this event
		//cout << "event " << count << endl;
		//IMM checks
		Int_t IMMfirstcount = 0, IMMsecondcount = 0;
		cout << "IMMfirst\t";
		if(fTool_3.CheckInBounds_Vcm_bu1(IMMresults.first.Vcm1)) {IMMfirstcount += 1; cout << "pass\t";} else { cout << Form("%f\t",IMMresults.first.Vcm1);}
		if(fTool_3.CheckInBounds_Vcm_bu2(IMMresults.first.Vcm2)) {IMMfirstcount += 1; cout << "pass\t";} else { cout << Form("%f\t",IMMresults.first.Vcm2);}
		if(fTool_3.CheckInBounds_KEcm_bu1(IMMresults.first.KEcm1)) {IMMfirstcount += 1; cout << "pass\t";} else { cout << Form("%f\t",IMMresults.first.KEcm1);}
		if(fTool_3.CheckInBounds_KEcm_bu2(IMMresults.first.KEcm2)) {IMMfirstcount += 1; cout << "pass\t";} else { cout << Form("%f\t",IMMresults.first.KEcm2);}
		if(fTool_3.CheckInBounds_Ecm(IMMresults.first.Ecm)) {IMMfirstcount += 1; cout << "pass\t";} else { cout << Form("%f\t",IMMresults.first.Ecm);}
		cout << Form("%d/%d",IMMfirstcount,5) << endl;
		cout << "IMMsecond\t";
		if(fTool_3.CheckInBounds_Vcm_bu1(IMMresults.second.Vcm1)) {IMMsecondcount += 1; cout << "pass\t";} else { cout << Form("%f\t",IMMresults.second.Vcm1);}
		if(fTool_3.CheckInBounds_Vcm_bu2(IMMresults.second.Vcm2)) {IMMsecondcount += 1; cout << "pass\t";} else { cout << Form("%f\t",IMMresults.second.Vcm2);}
		if(fTool_3.CheckInBounds_KEcm_bu1(IMMresults.second.KEcm1)) {IMMsecondcount += 1; cout << "pass\t";} else { cout << Form("%f\t",IMMresults.second.KEcm1);}
		if(fTool_3.CheckInBounds_KEcm_bu2(IMMresults.second.KEcm1)) {IMMsecondcount += 1; cout << "pass\t";} else { cout << Form("%f\t",IMMresults.second.KEcm2);}
		if(fTool_3.CheckInBounds_Ecm(IMMresults.second.Ecm)) {IMMsecondcount += 1; cout << "pass\t";} else { cout << Form("%f\t",IMMresults.second.Ecm);}
		cout  << endl;
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
		cout << "MMMfirst\t";
		if(fTool_3.CheckInBounds_Vcm_bu1(MMMresults.first.Vcm1)) {MMMfirstcount += 1; cout << "pass\t";} else { cout << Form("%f\t",IMMresults.second.Vcm1);}
		if(fTool_3.CheckInBounds_Vcm_bu2(MMMresults.first.Vcm2)) {MMMfirstcount += 1; cout << "pass\t";} else { cout << Form("%f\t",IMMresults.second.Vcm2);}
		if(fTool_3.CheckInBounds_KEcm_bu1(MMMresults.first.KEcm1)) {MMMfirstcount += 1; cout << "pass\t";} else { cout << Form("%f\t",IMMresults.second.KEcm1);}
		if(fTool_3.CheckInBounds_KEcm_bu2(MMMresults.first.KEcm2)) {MMMfirstcount += 1; cout << "pass\t";} else { cout << Form("%f\t",IMMresults.second.KEcm2);}
		if(fTool_3.CheckInBounds_Ecm(MMMresults.first.Ecm)) {MMMfirstcount += 1; cout << "pass\t";} else { cout << Form("%f\t",IMMresults.second.Ecm);}
		cout << Form("%d/%d",MMMfirstcount,5) << endl;
		cout << "MMMsecond\t";
		if(fTool_3.CheckInBounds_Vcm_bu1(MMMresults.second.Vcm1)) {MMMsecondcount += 1; cout << "pass\t";} else { cout << Form("%f\t",IMMresults.second.Vcm1);}
		if(fTool_3.CheckInBounds_Vcm_bu2(MMMresults.second.Vcm2)) {MMMsecondcount += 1; cout << "pass\t";} else { cout << Form("%f\t",IMMresults.second.Vcm2);}
		if(fTool_3.CheckInBounds_KEcm_bu1(MMMresults.second.KEcm1)) {MMMsecondcount += 1; cout << "pass\t";} else { cout << Form("%f\t",IMMresults.second.KEcm1);}
		if(fTool_3.CheckInBounds_KEcm_bu2(MMMresults.second.KEcm2)) {MMMsecondcount += 1; cout << "pass\t";} else { cout << Form("%f\t",IMMresults.second.KEcm2);}
		if(fTool_3.CheckInBounds_Ecm(MMMresults.second.Ecm)) {MMMsecondcount += 1; cout << "pass\t";} else { cout << Form("%f\t",IMMresults.second.Ecm);}
		cout << Form("%d/%d",MMMsecondcount,5) << endl;
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

		// cout << "event " << count << endl;
		// cout << "\tIMM case determination: " << IMM_casedet << endl;
		// cout << "\tMMM case determination: " << MMM_casedet << endl;
		// cout << endl;
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
	cout << "MMM Wrong mass assumption rfesults found in: " << outfile4path << endl;
	cout << endl;
	cout << endl;
	cout << "efficiencies:" << endl;
	cout << "IMM correct:\t" << count1 << "/" << count << " = " << float(count1)/float(count) << endl;
	cout << "IMM wrong:\t" << count2 << "/" << count << " = " << float(count2)/float(count) << endl;
	cout << "MMMcorrect:\t" << count3 << "/" << count << " = " << float(count3)/float(count) << endl;
	cout << "MMMwrong:\t" << count4 << "/" << count << " = " << float(count4)/float(count) << endl;
	cout << endl;

}

void macro2(){
	//this function handles the randomized data where I don't know which particle is in the kin3mc output columns for decay+daughter
	
	initHistos();

	IMMMA_Tool_3 tool;
	TMassTable fMassTable;

	fMassTable.Init("masstable.dat");

	//set up reaction information:
	tool.SetBeamNucleus(3,"He",fMassTable.GetMassMeV("He",3));
	tool.SetTargetNucleus(7,"Li",fMassTable.GetMassMeV("Li",7));
	tool.SetEjectileNucleus(4,"He",fMassTable.GetMassMeV("He",4));
	tool.SetRecoilNucleus(6,"Li",fMassTable.GetMassMeV("Li",6));
	tool.SetBreakup1Nucleus(4,"He",fMassTable.GetMassMeV("He",4));//make the 4He the bu1 --> case1 will always be this mass assumption
	tool.SetBreakup2Nucleus(2,"H",fMassTable.GetMassMeV("H",2));//make the 2H the bu2 --> case2 will always be this mass assumption

	tool.SetBeamEnergy(7.5);
	tool.SetRecoilExE(2.186);

	//calculate CM constants and set bounds
	tool.CalculateCMConstants();

	tool.SetMean_Vcm_bu1(1.13129e-02);
	tool.SetMean_Vcm_bu2(2.24771e-02);
	tool.SetMean_KEcm_bu1(2.38566e-01);
	tool.SetMean_KEcm_bu2(4.73926e-01);
	tool.SetMean_Ecm(7.12325e-01);

	// tool.SetVcm_bu1_bounds(1.32232e-04);//(sigma)
	// tool.SetVcm_bu2_bounds(2.61581e-04);//(sigma)
	// tool.SetKEcm_bu1_bounds(5.57896e-03);//(sigma)
	// tool.SetKEcm_bu2_bounds(1.10286e-02);//(sigma)
	// tool.SetEcm_bounds(1.66187e-02);//(sigma)

	const Float_t pm = 0.01;
	Float_t UPPER = 1+pm;
	Float_t LOWER = 1-pm;

	tool.SetVcm_bu1_boundsp(UPPER,LOWER);
	tool.SetVcm_bu2_boundsp(UPPER,LOWER);
	tool.SetKEcm_bu1_boundsp(UPPER,LOWER);
	tool.SetKEcm_bu2_boundsp(UPPER,LOWER);
	tool.SetEcm_boundsp(UPPER,LOWER);


	TString infiledatapath = "kin3mc_5000_randDecayData.txt";//kin3mc data
	TString infilekeyspath = "kin3mc_5000_randDecayKeys.txt";//key to which decay particle was picked for each line

	ifstream infiledata, infilekeys;
	infiledata.open(infiledatapath.Data());
	infilekeys.open(infilekeyspath.Data());

	Float_t Elab_ej, Thetalab_ej, Philab_ej, Elab_rec, Thetalab_rec, Philab_rec, Elab_bu1, Thetalab_bu1, Philab_bu1, Elab_bu2, Thetalab_bu2, Philab_bu2;
	TString decayparticle;

	//prep output
	ofstream outfile;
	TString outfilepath = "macro2output.txt";
	outfile.open(outfilepath);

	outfile << "actual\tguess\tright?\tconf" << endl;

	CMConstant VCM1, KECM1, VCM2, KECM2, ECM;

	VCM1 = tool.GetVcm_bu1();
	VCM2 = tool.GetVcm_bu2();
	KECM1 = tool.GetKEcm_bu1();
	KECM2 = tool.GetKEcm_bu2();
	ECM = tool.GetEcm();

	cout << endl;
	cout << "VCM1\t=\t" << VCM1.expected << Form("\t\trange: (%f, %f)",VCM1.lower,VCM1.upper) << endl;
	cout << "KECM1\t=\t" << KECM1.expected << Form("\t\trange: (%f, %f)",KECM1.lower,KECM1.upper) << endl;
	cout << "VCM2\t=\t" << VCM2.expected << Form("\t\trange: (%f, %f)",VCM2.lower,VCM2.upper) << endl;
	cout << "KECM2\t=\t" << KECM2.expected << Form("\t\trange: (%f, %f)",KECM2.lower,KECM2.upper) << endl;
	cout << "ECM\t=\t" << ECM.expected << Form("\t\trange: (%f, %f)",ECM.lower,ECM.upper) << endl;
	cout << endl;

	cout << "M_target = " << tool.GetTargetMass() << endl;
	cout << "M_beam = " << tool.GetBeamMass() << endl;
	cout << "M_ej = " << tool.GetEjectileMass() << endl;
	cout << "M_recoil = " << tool.GetRecoilMass() << endl;
	cout << "M_bu1 = " << tool.GetBreakup1Mass() << endl;
	cout << "M_bu2 = " << tool.GetBreakup2Mass() << endl;
	cout << endl;

	Int_t count = 0, count1 = 0, count2 = 0, count_tie = 0;
	Int_t count1_c = 0, count2_c = 0;

	while(infiledata >> Elab_ej >> Thetalab_ej >> Philab_ej >> Elab_rec >> Thetalab_rec >> Philab_rec >> Elab_bu1 >> Thetalab_bu1 >> Philab_bu1 >> Elab_bu2 >> Thetalab_bu2 >> Philab_bu2 && infilekeys >> decayparticle){
		//---------------------------------------------------------EVENT ANALYSIS-------------------------------------------------------------------------------------------------------------
		//perform the IMM calculation for both cases for the data:
		//recall that case1 will be the tool.Breakup1.mass assumption for the kin3mc "bu1" and that case2 will be the tool.Breakup2.mass assumption for the kin3mc "bu1"
		std::pair<CaseResult,CaseResult> IMMresults = tool.AnalyzeEventIMM(Elab_ej,Thetalab_ej,Philab_ej,Elab_bu1,Thetalab_bu1,Philab_bu1,Elab_bu2,Thetalab_bu2,Philab_bu2);
		CaseResult IMMcase1 = IMMresults.first;
		CaseResult IMMcase2 = IMMresults.second;
		//fill histograms:
		IMMfirst_Vcm1->Fill(IMMresults.first.Vcm1);
		IMMfirst_Vcm2->Fill(IMMresults.first.Vcm2);
		IMMfirst_KEcm1->Fill(IMMresults.first.KEcm1);
		IMMfirst_KEcm2->Fill(IMMresults.first.KEcm2);
		IMMfirst_Ecm->Fill(IMMresults.first.Ecm);
		IMMsecond_Vcm1->Fill(IMMresults.second.Vcm1);
		IMMsecond_Vcm2->Fill(IMMresults.second.Vcm2);
		IMMsecond_KEcm1->Fill(IMMresults.second.KEcm1);
		IMMsecond_KEcm2->Fill(IMMresults.second.KEcm2);
		IMMsecond_Ecm->Fill(IMMresults.second.Ecm);

		std::pair<CaseResult,CaseResult> MMMresults = tool.AnalyzeEventMMM(Elab_ej,Thetalab_ej,Philab_ej,Elab_bu1,Thetalab_bu1,Philab_bu1);
		CaseResult MMMcase1 = MMMresults.first;
		CaseResult MMMcase2 = MMMresults.second;
		//fill histograms:
		MMMfirst_Vcm1->Fill(MMMresults.first.Vcm1);
		MMMfirst_Vcm2->Fill(MMMresults.first.Vcm2);
		MMMfirst_KEcm1->Fill(MMMresults.first.KEcm1);
		MMMfirst_KEcm2->Fill(MMMresults.first.KEcm2);
		MMMfirst_Ecm->Fill(MMMresults.first.Ecm);
		MMMsecond_Vcm1->Fill(MMMresults.second.Vcm1);
		MMMsecond_Vcm2->Fill(MMMresults.second.Vcm2);
		MMMsecond_KEcm1->Fill(MMMresults.second.KEcm1);
		MMMsecond_KEcm2->Fill(MMMresults.second.KEcm2);
		MMMsecond_Ecm->Fill(MMMresults.second.Ecm);

		//---------------------------------------------------------CASE DETERMINATION-------------------------------------------------------------------------------------------------------------
		Int_t IMMfirstcount = 0, IMMsecondcount = 0;
		if(tool.CheckInBounds_Vcm_bu1(IMMresults.first.Vcm1)) {IMMfirstcount += 1;}// cout << "pass\t";} else { cout << Form("%f\t",IMMresults.first.Vcm1);}
		if(tool.CheckInBounds_Vcm_bu2(IMMresults.first.Vcm2)) {IMMfirstcount += 1;}// cout << "pass\t";} else { cout << Form("%f\t",IMMresults.first.Vcm2);}
		if(tool.CheckInBounds_KEcm_bu1(IMMresults.first.KEcm1)) {IMMfirstcount += 1;}// cout << "pass\t";} else { cout << Form("%f\t",IMMresults.first.KEcm1);}
		if(tool.CheckInBounds_KEcm_bu2(IMMresults.first.KEcm2)) {IMMfirstcount += 1;}// cout << "pass\t";} else { cout << Form("%f\t",IMMresults.first.KEcm2);}
		if(tool.CheckInBounds_Ecm(IMMresults.first.Ecm)) {IMMfirstcount += 1;}// cout << "pass\t";} else { cout << Form("%f\t",IMMresults.first.Ecm);}
		if(tool.CheckInBounds_ThetaCMSum(IMMresults.first.ThetaCM1+IMMresults.first.ThetaCM2)) {IMMfirstcount += 1;}// cout << "pass\t";} else {cout << Form("%f\t",IMMresults.first.ThetaCM1+IMMresults.first.ThetaCM2);}
		if(tool.CheckInBounds_PhiCMSep(abs(IMMresults.first.PhiCM1 - IMMresults.first.PhiCM2))) {IMMfirstcount += 1;}// cout << "pass\t";} else {cout << Form("%f\t",abs(IMMresults.first.PhiCM1 - IMMresults.first.PhiCM2))}

		if(tool.CheckInBounds_Vcm_bu1(IMMresults.second.Vcm1)) {IMMsecondcount += 1;}// cout << "pass\t";} else { cout << Form("%f\t",IMMresults.second.Vcm1);}
		if(tool.CheckInBounds_Vcm_bu2(IMMresults.second.Vcm2)) {IMMsecondcount += 1;}// cout << "pass\t";} else { cout << Form("%f\t",IMMresults.second.Vcm2);}
		if(tool.CheckInBounds_KEcm_bu1(IMMresults.second.KEcm1)) {IMMsecondcount += 1;}// cout << "pass\t";} else { cout << Form("%f\t",IMMresults.second.KEcm1);}
		if(tool.CheckInBounds_KEcm_bu2(IMMresults.second.KEcm1)) {IMMsecondcount += 1;}// cout << "pass\t";} else { cout << Form("%f\t",IMMresults.second.KEcm2);}
		if(tool.CheckInBounds_Ecm(IMMresults.second.Ecm)) {IMMsecondcount += 1;}// cout << "pass\t";} else { cout << Form("%f\t",IMMresults.second.Ecm);}
		if(tool.CheckInBounds_ThetaCMSum(IMMresults.second.ThetaCM1+IMMresults.second.ThetaCM2)) {IMMsecondcount += 1;}// cout << "pass\t";} else {cout << Form("%f\t",IMMresults.second.ThetaCM1+IMMresults.second.ThetaCM2);}
		if(tool.CheckInBounds_PhiCMSep(abs(IMMresults.second.PhiCM1 - IMMresults.second.PhiCM2))) {IMMsecondcount += 1;}//cout << "pass\t";} else {cout << Form("%f\t",abs(IMMresults.second.PhiCM1 - IMMresults.second.PhiCM2))}

		if(IMMfirstcount > IMMsecondcount){
			//case1 is the winner!
			TString temp;
			if(decayparticle.EqualTo(tool.GetBreakup1Nucleus().ToString())){temp = "YES";count1_c += 1;} else {temp = "NO";}
			outfile << decayparticle << "\t" << tool.GetBreakup1Nucleus().ToString() << "\t" << temp << "\t" << float(IMMfirstcount)/7. << endl;
			count1 += 1;
		} else if(IMMfirstcount < IMMsecondcount){
			//case2 is the winner!
			TString temp;
			if(decayparticle.EqualTo(tool.GetBreakup2Nucleus().ToString())){temp = "YES";count2_c += 1;} else {temp = "NO";}
			outfile << decayparticle << "\t" << tool.GetBreakup2Nucleus().ToString() << "\t" << temp << "\t" << float(IMMsecondcount)/7. << endl;
			count2 += 1;
		} else {
			//a tie!
			TString temp = "TIE";
			outfile << decayparticle << "\t" << "tie" << "\t" << temp << "\t" << float(IMMfirstcount)/7. << endl;
			count_tie += 1;
		}

		count += 1;
	}


	cout << endl;
	cout << "Success! Output file: " << outfilepath << endl;
	cout << "Number of events determined to be case 1: " << count1 << "/5000 = " << float(count1)/5000. << endl;
	cout << "Number of events determined to be case 2: " << count2 << "/5000 = " << float(count2)/5000. << endl;
	cout << "Number of events undeterminable: " << count_tie << "/10000 = " << float(count_tie)/10000. << endl;
	cout << endl;
	cout << "Number of events correctly identifed to be case 1: " << count1_c << "/5000 = " << float(count1_c)/5000. << endl;
	cout << "Number of events correctly identifed to be case 2: " << count2_c << "/5000 = " << float(count2_c)/5000. << endl;
	cout << endl;

	outfile.close();
	infiledata.close();
	infilekeys.close();
}

void macro3(){
	//this function handles the randomized data where I don't know which particle is in the kin3mc output columns, but only using the information from one breakup and the ejctile
	initHistos();

	IMMMA_Tool_3 tool;
	TMassTable fMassTable;

	fMassTable.Init("masstable.dat");

	//set up reaction information:
	tool.SetBeamNucleus(3,"He",fMassTable.GetMassMeV("He",3));
	tool.SetTargetNucleus(7,"Li",fMassTable.GetMassMeV("Li",7));
	tool.SetEjectileNucleus(4,"He",fMassTable.GetMassMeV("He",4));
	tool.SetRecoilNucleus(6,"Li",fMassTable.GetMassMeV("Li",6));
	tool.SetBreakup1Nucleus(4,"He",fMassTable.GetMassMeV("He",4));//make the 4He the bu1 --> case1 will always be this mass assumption
	tool.SetBreakup2Nucleus(2,"H",fMassTable.GetMassMeV("H",2));//make the 2H the bu2 --> case2 will always be this mass assumption

	tool.SetBeamEnergy(7.5);
	tool.SetRecoilExE(2.186);

	//calculate CM constants and set bounds
	tool.CalculateCMConstants();

	tool.SetMean_Vcm_bu1(1.13129e-02);
	tool.SetMean_Vcm_bu2(2.24771e-02);
	tool.SetMean_KEcm_bu1(2.38566e-01);
	tool.SetMean_KEcm_bu2(4.73926e-01);
	tool.SetMean_Ecm(7.12325e-01);

	tool.SetVcm_bu1_bounds(1.32232e-04);//(sigma)
	tool.SetVcm_bu2_bounds(2.61581e-04);//(sigma)
	tool.SetKEcm_bu1_bounds(5.57896e-03);//(sigma)
	tool.SetKEcm_bu2_bounds(1.10286e-02);//(sigma)
	tool.SetEcm_bounds(1.66187e-02);//(sigma)

	// const Float_t pm = 0.5;
	// Float_t UPPER = 1+pm;
	// Float_t LOWER = 1-pm;

	// tool.SetVcm_bu1_boundsp(UPPER,LOWER);
	// tool.SetVcm_bu2_boundsp(UPPER,LOWER);
	// tool.SetKEcm_bu1_boundsp(UPPER,LOWER);
	// tool.SetKEcm_bu2_boundsp(UPPER,LOWER);
	// tool.SetEcm_boundsp(UPPER,LOWER);

	TString infiledatapath = "kin3mc_5000_randDecayData.txt";//kin3mc data
	TString infilekeyspath = "kin3mc_5000_randDecayKeys.txt";//key to which decay particle was picked for each line

	ifstream infiledata, infilekeys;
	infiledata.open(infiledatapath.Data());
	infilekeys.open(infilekeyspath.Data());

	Float_t Elab_ej, Thetalab_ej, Philab_ej, Elab_rec, Thetalab_rec, Philab_rec, Elab_bu1, Thetalab_bu1, Philab_bu1, Elab_bu2, Thetalab_bu2, Philab_bu2;
	TString decayparticle;

	//prep output
	ofstream outfile;
	TString outfilepath = "macro3output.txt";
	outfile.open(outfilepath);

	outfile << "actual\tguess\tright?\tconf" << endl;

	CMConstant VCM1, KECM1, VCM2, KECM2, ECM;

	VCM1 = tool.GetVcm_bu1();
	VCM2 = tool.GetVcm_bu2();
	KECM1 = tool.GetKEcm_bu1();
	KECM2 = tool.GetKEcm_bu2();
	ECM = tool.GetEcm();

	cout << endl;
	cout << "VCM1\t=\t" << VCM1.expected << Form("\t\trange: (%f, %f)",VCM1.lower,VCM1.upper) << endl;
	cout << "KECM1\t=\t" << KECM1.expected << Form("\t\trange: (%f, %f)",KECM1.lower,KECM1.upper) << endl;
	cout << "VCM2\t=\t" << VCM2.expected << Form("\t\trange: (%f, %f)",VCM2.lower,VCM2.upper) << endl;
	cout << "KECM2\t=\t" << KECM2.expected << Form("\t\trange: (%f, %f)",KECM2.lower,KECM2.upper) << endl;
	cout << "ECM\t=\t" << ECM.expected << Form("\t\trange: (%f, %f)",ECM.lower,ECM.upper) << endl;
	cout << endl;

	cout << "M_target = " << tool.GetTargetMass() << endl;
	cout << "M_beam = " << tool.GetBeamMass() << endl;
	cout << "M_ej = " << tool.GetEjectileMass() << endl;
	cout << "M_recoil = " << tool.GetRecoilMass() << endl;
	cout << "M_bu1 = " << tool.GetBreakup1Mass() << endl;
	cout << "M_bu2 = " << tool.GetBreakup2Mass() << endl;
	cout << endl;

	Int_t count = 0, count1 = 0, count2 = 0, count_tie = 0;
	Int_t count1_c = 0, count2_c = 0;
	while(infiledata >> Elab_ej >> Thetalab_ej >> Philab_ej >> Elab_rec >> Thetalab_rec >> Philab_rec >> Elab_bu1 >> Thetalab_bu1 >> Philab_bu1 >> Elab_bu2 >> Thetalab_bu2 >> Philab_bu2 && infilekeys >> decayparticle){
		//---------------------------------------------------------EVENT ANALYSIS-------------------------------------------------------------------------------------------------------------
		//perform IMM/MMM calculation for both cases for the data:
		std::pair<CaseResult,CaseResult> IMMresults = tool.AnalyzeEventIMM(Elab_ej,Thetalab_ej,Philab_ej,Elab_bu1,Thetalab_bu1,Philab_bu1,Elab_bu2,Thetalab_bu2,Philab_bu2);
		CaseResult IMMcase1 = IMMresults.first;
		CaseResult IMMcase2 = IMMresults.second;
		//fill histograms:
		IMMfirst_Vcm1->Fill(IMMresults.first.Vcm1);
		IMMfirst_Vcm2->Fill(IMMresults.first.Vcm2);
		IMMfirst_KEcm1->Fill(IMMresults.first.KEcm1);
		IMMfirst_KEcm2->Fill(IMMresults.first.KEcm2);
		IMMfirst_Ecm->Fill(IMMresults.first.Ecm);
		IMMsecond_Vcm1->Fill(IMMresults.second.Vcm1);
		IMMsecond_Vcm2->Fill(IMMresults.second.Vcm2);
		IMMsecond_KEcm1->Fill(IMMresults.second.KEcm1);
		IMMsecond_KEcm2->Fill(IMMresults.second.KEcm2);
		IMMsecond_Ecm->Fill(IMMresults.second.Ecm);

		std::pair<CaseResult,CaseResult> MMMresults = tool.AnalyzeEventMMM(Elab_ej,Thetalab_ej,Philab_ej,Elab_bu1,Thetalab_bu1,Philab_bu1);
		CaseResult MMMcase1 = MMMresults.first;
		CaseResult MMMcase2 = MMMresults.second;
		//fill histograms:
		MMMfirst_Vcm1->Fill(MMMresults.first.Vcm1);
		MMMfirst_Vcm2->Fill(MMMresults.first.Vcm2);
		MMMfirst_KEcm1->Fill(MMMresults.first.KEcm1);
		MMMfirst_KEcm2->Fill(MMMresults.first.KEcm2);
		MMMfirst_Ecm->Fill(MMMresults.first.Ecm);
		MMMsecond_Vcm1->Fill(MMMresults.second.Vcm1);
		MMMsecond_Vcm2->Fill(MMMresults.second.Vcm2);
		MMMsecond_KEcm1->Fill(MMMresults.second.KEcm1);
		MMMsecond_KEcm2->Fill(MMMresults.second.KEcm2);
		MMMsecond_Ecm->Fill(MMMresults.second.Ecm);

		//---------------------------------------------------------CASE DETERMINATION-------------------------------------------------------------------------------------------------------------
		Int_t MMMfirstcount = 0, MMMsecondcount = 0;
		if(tool.CheckInBounds_Vcm_bu1(MMMresults.first.Vcm1)) {MMMfirstcount += 1;}// cout << "pass\t";} else { cout << Form("%f\t",MMMresults.first.Vcm1);}
		if(tool.CheckInBounds_Vcm_bu2(MMMresults.first.Vcm2)) {MMMfirstcount += 1;}// cout << "pass\t";} else { cout << Form("%f\t",MMMresults.first.Vcm2);}
		if(tool.CheckInBounds_KEcm_bu1(MMMresults.first.KEcm1)) {MMMfirstcount += 1;}// cout << "pass\t";} else { cout << Form("%f\t",MMMresults.first.KEcm1);}
		if(tool.CheckInBounds_KEcm_bu2(MMMresults.first.KEcm2)) {MMMfirstcount += 1;}// cout << "pass\t";} else { cout << Form("%f\t",MMMresults.first.KEcm2);}
		if(tool.CheckInBounds_Ecm(MMMresults.first.Ecm)) {MMMfirstcount += 1;}//cout << "pass\t";} else { cout << Form("%f\t",MMMresults.first.Ecm);}

		if(tool.CheckInBounds_Vcm_bu1(MMMresults.second.Vcm1)) {MMMsecondcount += 1;}// cout << "pass\t";} else { cout << Form("%f\t",MMMresults.second.Vcm1);}
		if(tool.CheckInBounds_Vcm_bu2(MMMresults.second.Vcm2)) {MMMsecondcount += 1;}// cout << "pass\t";} else { cout << Form("%f\t",MMMresults.second.Vcm2);}
		if(tool.CheckInBounds_KEcm_bu1(MMMresults.second.KEcm1)) {MMMsecondcount += 1;}// cout << "pass\t";} else { cout << Form("%f\t",MMMresults.second.KEcm1);}
		if(tool.CheckInBounds_KEcm_bu2(MMMresults.second.KEcm2)) {MMMsecondcount += 1;}// cout << "pass\t";} else { cout << Form("%f\t",MMMresults.second.KEcm2);}
		if(tool.CheckInBounds_Ecm(MMMresults.second.Ecm)) {MMMsecondcount += 1;}//cout << "pass\t";} else { cout << Form("%f\t",MMMresults.second.Ecm);}

		TString temp;
		if(MMMfirstcount > MMMsecondcount){
			//case1 is the winner!
			if(decayparticle.EqualTo(tool.GetBreakup1Nucleus().ToString())){temp="YES"; count1_c += 1;}else{temp="NO";}
			outfile << decayparticle << "\t" << tool.GetBreakup1Nucleus().ToString() << "\t" << temp << "\t" << float(MMMfirstcount)/5. << endl;
			count1 += 1;
		} else if(MMMfirstcount < MMMsecondcount){
			//case2 is the winner!
			if(decayparticle.EqualTo(tool.GetBreakup2Nucleus().ToString())){temp="YES"; count2_c += 1;}else{temp="NO";}
			outfile << decayparticle << "\t" << tool.GetBreakup2Nucleus().ToString() << "\t" << temp << "\t" << float(MMMsecondcount)/5. << endl;
			count2 += 1;
		} else {
			// a tie!
			temp = "TIE";
			outfile << decayparticle << "\t" << "tie" << "\t" << temp << "\t" << float(MMMfirstcount)/5. << endl;
			count_tie += 1;
		}

		count += 1;
	}

	cout << endl;
	cout << "Success! Output file: " << outfilepath << endl;
	cout << "Number of events determined to be case 1: " << count1 << "/5000 = " << float(count1)/5000. << endl;
	cout << "Number of events determined to be case 2: " << count2 << "/5000 = " << float(count2)/5000. << endl;
	cout << "Number of events undeterminable: " << count_tie << "/10000 = " << float(count_tie)/10000. << endl;
	cout << endl;
	cout << "Number of events correctly identifed to be case 1: " << count1_c << "/5000 = " << float(count1_c)/5000. << endl;
	cout << "Number of events correctly identifed to be case 2: " << count2_c << "/5000 = " << float(count2_c)/5000. << endl;
	cout << endl;

}

void mixDecayFiles(const TString& file1Path, const TString& decay1, const TString& file2Path, const TString& decay2, const TString& outputDataPath, const TString& outputKeyPath){
	//file1path = path to file containing kin3mc output with decay particle decay1
	//decay1 = the decay particle chosen for the kin3mc decay particle in output located at file1Path
	//file2path = path to file containing kin3mc output with decay particle decay2
	//decay2 = the decay particle chosen for the kin3mc decay particle in output located at file2Path
	//outputDataPath = path to the file containing the randomized data values (actual data values)
	//outputKeyPath = path to the file containing the randomized key values (whether the line is due to file1Path or file2Path)
	vector<TString> dataLines;
	vector<TString> keyLines;

	ifstream file1(file1Path.Data());
	if(file1.is_open()){
		string line;
		while(getline(file1, line)){
			TString LINE(line);
			dataLines.push_back(LINE);
			keyLines.push_back(decay1);
		}
		file1.close();
	} else {
		cerr << "Error: Could not open file" << endl;
		return;
	}

	ifstream file2(file2Path.Data());
	if(file2.is_open()){
		string line;
		while(getline(file2, line)){
			TString LINE(line);
			dataLines.push_back(LINE);
			keyLines.push_back(decay2);
		}
	} else {
		cerr << "Error: Could not open file" << endl;
		return;
	}

	if(dataLines.empty()){
		cerr << "Warning: No data found in input files" << endl;
		return;
	}

	vector<size_t> indices(dataLines.size());
	for(size_t i=0; i<indices.size(); ++i){
		indices[i] = i;
	}

	random_device rd;
	mt19937 gen(rd());
	//shuffle(indices.begin(), indices.end(), [&rng](size_t n) { return static_cast<size_t>(rng.Integer(n));});
	shuffle(indices.begin(), indices.end(), gen);

	ofstream outfileData(outputDataPath.Data());
	ofstream outfileKey(outputKeyPath.Data());

	if(outfileData.is_open() && outfileKey.is_open()){
		for(size_t index : indices){
			outfileData << dataLines[index] << endl;
			outfileKey << keyLines[index] << endl;
		}
		outfileData.close();
		outfileKey.close();
		cout << "data:\t" << outputDataPath << endl;
		cout << "keys:\t" << outputKeyPath << endl;
	}
}