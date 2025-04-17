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
	fTool_3.CalculateCMConstants();

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

	while(infile >> Elab_ej >> Thetalab_ej >> Philab_ej >> Elab_rec >> Thetalab_rec >> Philab_rec >> Elab_bu1 >> Thetalab_bu1 >> Philab_bu1 >> Elab_bu2 >> Thetalab_bu2 >> Philab_bu2){
		TString kinline = Form("%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f",Elab_ej,Thetalab_ej,Philab_ej,Elab_rec,Thetalab_rec,Philab_rec,Elab_bu1,Thetalab_bu1,Philab_bu1,Elab_bu2,Thetalab_bu2,Philab_bu2);

		//perform the IMM calculation for both cases for the data
		//recall that case1 will be the bu1 assumption and case2 will be the bu2 assumption!
		std::pair<CaseResult,CaseResult> IMMresults = fTool_3.AnalyzeEventIMM(Elab_ej,Thetalab_ej,Philab_ej,Elab_bu1,Thetalab_bu1,Philab_bu1,Elab_bu2,Thetalab_bu2,Philab_bu2);
		CaseResult IMMcorrect = IMMresults.first;
		CaseResult IMMwrong = IMMresults.second;

		std::pair<CaseResult,CaseResult> MMMResults = fTool_3.AnalyzeEventMMM(Elab_ej,Thetalab_ej,Philab_ej,Elab_bu1,Thetalab_bu1,Philab_bu1);
		CaseResult MMMcorrect = MMMResults.first;
		CaseResult MMMwrong = MMMResults.second;

		//ThetaCM1 PhiCM1 VCM1 KECM1 ThetaCM2 PhiCM2 VCM2 KECM2 ThetaSUM PhiSep Ecm
		TString outline1 = Form("%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f",IMMcorrect.ThetaCM1,IMMcorrect.PhiCM1,IMMcorrect.Vcm1,IMMcorrect.KEcm1,IMMcorrect.ThetaCM2,IMMcorrect.PhiCM2,IMMcorrect.Vcm2,IMMcorrect.KEcm2,IMMcorrect.ThetaCM1+IMMcorrect.ThetaCM2,abs(IMMcorrect.PhiCM1-IMMcorrect.PhiCM2),IMMcorrect.Ecm);
		TString outline2 = Form("%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f",IMMwrong.ThetaCM1,IMMwrong.PhiCM1,IMMwrong.Vcm1,IMMwrong.KEcm1,IMMwrong.ThetaCM2,IMMwrong.PhiCM2,IMMwrong.Vcm2,IMMwrong.KEcm2,IMMwrong.ThetaCM1+IMMwrong.ThetaCM2,abs(IMMwrong.PhiCM1-IMMwrong.PhiCM2),IMMwrong.Ecm);
		TString outline3 = Form("%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f",MMMcorrect.ThetaCM1,MMMcorrect.PhiCM1,MMMcorrect.Vcm1,MMMcorrect.KEcm1,MMMcorrect.ThetaCM2,MMMcorrect.PhiCM2,MMMcorrect.Vcm2,MMMcorrect.KEcm2,MMMcorrect.ThetaCM1+MMMcorrect.ThetaCM2,abs(MMMcorrect.PhiCM1-MMMcorrect.PhiCM2),MMMcorrect.Ecm);
		TString outline4 = Form("%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f",MMMwrong.ThetaCM1,MMMwrong.PhiCM1,MMMwrong.Vcm1,MMMwrong.KEcm1,MMMwrong.ThetaCM2,MMMwrong.PhiCM2,MMMwrong.Vcm2,MMMwrong.KEcm2,MMMwrong.ThetaCM1+MMMwrong.ThetaCM2,abs(MMMwrong.PhiCM1-MMMwrong.PhiCM2),MMMwrong.Ecm);


		outfile1 << kinline << "\t" << outline1 << endl;
		outfile2 << kinline << "\t" << outline2 << endl;
		outfile3 << kinline << "\t" << outline3 << endl;
		outfile4 << kinline << "\t" << outline4 << endl;
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
}