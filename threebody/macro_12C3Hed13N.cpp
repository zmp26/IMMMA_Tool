#include "IMMMA_Tool_3.h"
#include "masstable.h"

void macro2(){
	IMMMA_Tool_3 tool;
	TMassTable fMassTable;
	fMassTable.Init("masstable.dat");

	tool.SetBeamNucleus(3,"He",fMassTable.GetMassMeV("He",3));
	tool.SetTargetNucleus(12,"C",fMassTable.GetMassMeV("C",12));
	tool.SetEjectileNucleus(2,"H",fMassTable.GetMassMeV("H",2));
	tool.SetRecoilNucleus(13,"N",fMassTable.GetMassMeV("N",13));
	tool.SetBreakup1Nucleus(1,"H",fMassTable.GetMassMeV("H",1));
	tool.SetBreakup2Nucleus(12,"C",fMassTable.GetMassMeV("C",12));

	tool.SetBeamEnergy(7.5);
	tool.SetRecoilExE(2.367);

	tool.CalculateCMConstants();

	tool.SetMean_Vcm_bu1(2.88315e-02);
	tool.SetMean_Vcm_bu2(2.42266e-03);
	tool.SetMean_KEcm_bu1(3.90217e-01);
	tool.SetMean_KEcm_bu2(3.27854e-02);
	tool.SetMean_Ecm(4.22857e-01);

	tool.SetVcm_bu1_bounds(7.18612e-04);
	tool.SetVcm_bu2_bounds(6.01524e-05);
	tool.SetKEcm_bu1_bounds(1.95527e-02);
	tool.SetKEcm_bu2_bounds(1.66366e-03);
	tool.SetEcm_bounds(2.13208e-02);

	TString infiledatapath = "macro_12C3Hed13N_10000_randData.out";
	TString infilekeyspath = "macro_12C3Hed13N_10000_randKeys.out";

	ifstream infiledata, infilekeys;
	infiledata.open(infiledatapath);
	infilekeys.open(infilekeyspath);

	Float_t Elab_ej, Thetalab_ej, Philab_ej, Elab_rec, Thetalab_rec, Philab_rec, Elab_bu1, Thetalab_bu1, Philab_bu1, Elab_bu2, Thetalab_bu2, Philab_bu2;
	TString decayparticle;

	ofstream outfile;
	TString outfilepath = "12Cmacro2output.txt";
	outfile.open(outfilepath);

	outfile << "actual\tguess\tright?\tconf" << endl;

	CMConstant VCM1, KECM1, VCM2, KECM2, ECM;

	VCM1 = tool.GetVcm_bu1();
	KECM1 = tool.GetKEcm_bu1();
	VCM2 = tool.GetVcm_bu2();
	KECM2 = tool.GetKEcm_bu2();
	ECM = tool.GetEcm();

	cout << endl;
	cout << "VCM1\t=\t" << VCM1.expected << Form("\t\trange: (%.17g, %.17g)",VCM1.lower,VCM1.upper) << endl;
	cout << "KECM1\t=\t" << KECM1.expected << Form("\t\trange: (%.17g, %.17g)",KECM1.lower,KECM1.upper) << endl;
	cout << "VCM2\t=\t" << VCM2.expected << Form("\t\trange: (%.17g, %.17g)",VCM2.lower,VCM2.upper) << endl;
	cout << "KECM2\t=\t" << KECM2.expected << Form("\t\trange: (%.17g, %.17g)",KECM2.lower,KECM2.upper) << endl;
	cout << "ECM\t=\t" << ECM.expected << Form("\t\trange: (%.17g, %.17g)",ECM.lower,ECM.upper) << endl;
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
		std::pair<CaseResult,CaseResult> IMMresults = tool.AnalyzeEventIMM(Elab_ej, Thetalab_ej, Philab_ej, Elab_bu1, Thetalab_bu1, Philab_bu1, Elab_bu2, Thetalab_bu2, Philab_bu2);
		CaseResult IMMcase1 = IMMresults.first;
		CaseResult IMMcase2 = IMMresults.second;

		//---------------------------------------------------------CASE DETERMINATION-------------------------------------------------------------------------------------------------------------
		Int_t IMMfirstcount = 0, IMMsecondcount = 0;
		if(tool.CheckInBounds_Vcm_bu1(IMMresults.first.Vcm1)) {IMMfirstcount += 1;}// cout << "pass\t";} else { cout << Form("%.17g\t",IMMresults.first.Vcm1);}
		if(tool.CheckInBounds_Vcm_bu2(IMMresults.first.Vcm2)) {IMMfirstcount += 1;}// cout << "pass\t";} else { cout << Form("%.17g\t",IMMresults.first.Vcm2);}
		if(tool.CheckInBounds_KEcm_bu1(IMMresults.first.KEcm1)) {IMMfirstcount += 1;}// cout << "pass\t";} else { cout << Form("%.17g\t",IMMresults.first.KEcm1);}
		if(tool.CheckInBounds_KEcm_bu2(IMMresults.first.KEcm2)) {IMMfirstcount += 1;}// cout << "pass\t";} else { cout << Form("%.17g\t",IMMresults.first.KEcm2);}
		if(tool.CheckInBounds_Ecm(IMMresults.first.Ecm)) {IMMfirstcount += 1;}// cout << "pass\t";} else { cout << Form("%.17g\t",IMMresults.first.Ecm);}
		if(tool.CheckInBounds_ThetaCMSum(IMMresults.first.ThetaCM1+IMMresults.first.ThetaCM2)) {IMMfirstcount += 1;}// cout << "pass\t";} else {cout << Form("%.17g\t",IMMresults.first.ThetaCM1+IMMresults.first.ThetaCM2);}
		if(tool.CheckInBounds_PhiCMSep(abs(IMMresults.first.PhiCM1 - IMMresults.first.PhiCM2))) {IMMfirstcount += 1;}// cout << "pass\t";} else {cout << Form("%.17g\t",abs(IMMresults.first.PhiCM1 - IMMresults.first.PhiCM2))}

		if(tool.CheckInBounds_Vcm_bu1(IMMresults.second.Vcm1)) {IMMsecondcount += 1;}// cout << "pass\t";} else { cout << Form("%.17g\t",IMMresults.first.Vcm1);}
		if(tool.CheckInBounds_Vcm_bu2(IMMresults.second.Vcm2)) {IMMsecondcount += 1;}// cout << "pass\t";} else { cout << Form("%.17g\t",IMMresults.first.Vcm2);}
		if(tool.CheckInBounds_KEcm_bu1(IMMresults.second.KEcm1)) {IMMsecondcount += 1;}// cout << "pass\t";} else { cout << Form("%.17g\t",IMMresults.first.KEcm1);}
		if(tool.CheckInBounds_KEcm_bu2(IMMresults.second.KEcm2)) {IMMsecondcount += 1;}// cout << "pass\t";} else { cout << Form("%.17g\t",IMMresults.first.KEcm2);}
		if(tool.CheckInBounds_Ecm(IMMresults.second.Ecm)) {IMMsecondcount += 1;}// cout << "pass\t";} else { cout << Form("%.17g\t",IMMresults.first.Ecm);}
		if(tool.CheckInBounds_ThetaCMSum(IMMresults.second.ThetaCM1+IMMresults.second.ThetaCM2)) {IMMsecondcount += 1;}// cout << "pass\t";} else {cout << Form("%.17g\t",IMMresults.first.ThetaCM1+IMMresults.first.ThetaCM2);}
		if(tool.CheckInBounds_PhiCMSep(abs(IMMresults.second.PhiCM1 - IMMresults.second.PhiCM2))) {IMMsecondcount += 1;}// cout << "pass\t";} else {cout << Form("%.17g\t",abs(IMMresults.first.PhiCM1 - IMMresults.first.PhiCM2))}

		TString temp;
		if(IMMfirstcount > IMMsecondcount){
			if(decayparticle.EqualTo(tool.GetBreakup1Nucleus().ToString())){temp = "YES"; count1_c += 1;} else {temp = "NO";}
			outfile << decayparticle << "\t" << tool.GetBreakup1Nucleus().ToString() << "\t" << temp << "\t" << float(IMMfirstcount)/7. << endl;
			count1 += 1;
		} else if(IMMfirstcount < IMMsecondcount){
			if(decayparticle.EqualTo(tool.GetBreakup2Nucleus().ToString())){temp = "YES"; count2_c += 1;} else {temp = "NO";}
			outfile << decayparticle << "\t" << tool.GetBreakup2Nucleus().ToString() << "\t" << temp << "\t" << float(IMMsecondcount)/7. << endl;
			count2 += 1;
		} else {
			temp = "TIE";
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
	IMMMA_Tool_3 tool;
	TMassTable fMassTable;

	fMassTable.Init("masstable.dat");

	tool.SetBeamNucleus(3,"He",fMassTable.GetMassMeV("He",3));
	tool.SetTargetNucleus(12,"C",fMassTable.GetMassMeV("C",12));
	tool.SetEjectileNucleus(2,"H",fMassTable.GetMassMeV("H",2));
	tool.SetRecoilNucleus(13,"N",fMassTable.GetMassMeV("N",13));
	tool.SetBreakup1Nucleus(1,"H",fMassTable.GetMassMeV("H",1));
	tool.SetBreakup2Nucleus(12,"C",fMassTable.GetMassMeV("C",12));

	tool.SetBeamEnergy(7.5);
	tool.SetRecoilExE(2.367);

	tool.CalculateCMConstants();

	tool.SetMean_Vcm_bu1(2.88315e-02);
	tool.SetMean_Vcm_bu2(2.42266e-03);
	tool.SetMean_KEcm_bu1(3.90217e-01);
	tool.SetMean_KEcm_bu2(3.27854e-02);
	tool.SetMean_Ecm(4.22857e-01);

	tool.SetVcm_bu1_bounds(7.18612e-04);
	tool.SetVcm_bu2_bounds(6.01524e-05);
	tool.SetKEcm_bu1_bounds(1.95527e-02);
	tool.SetKEcm_bu2_bounds(1.66366e-03);
	tool.SetEcm_bounds(2.13208e-02);

	TString infiledatapath = "macro_12C3Hed13N_10000_randData.out";
	TString infilekeyspath = "macro_12C3Hed13N_10000_randKeys.out";

	ifstream infiledata, infilekeys;
	infiledata.open(infiledatapath);
	infilekeys.open(infilekeyspath);

	Float_t Elab_ej, Thetalab_ej, Philab_ej, Elab_rec, Thetalab_rec, Philab_rec, Elab_bu1, Thetalab_bu1, Philab_bu1, Elab_bu2, Thetalab_bu2, Philab_bu2;
	TString decayparticle;

	ofstream outfile;
	TString outfilepath = "12Cmacro3output.txt";
	outfile.open(outfilepath);

	outfile << "actual\tguess\tright?\tconf" << endl;

	CMConstant VCM1, KECM1, VCM2, KECM2, ECM;

	VCM1 = tool.GetVcm_bu1();
	KECM1 = tool.GetKEcm_bu1();
	VCM2 = tool.GetVcm_bu2();
	KECM2 = tool.GetKEcm_bu2();
	ECM = tool.GetEcm();

	cout << endl;
	cout << "VCM1\t=\t" << VCM1.expected << Form("\t\trange: (%.17g, %.17g)",VCM1.lower,VCM1.upper) << endl;
	cout << "KECM1\t=\t" << KECM1.expected << Form("\t\trange: (%.17g, %.17g)",KECM1.lower,KECM1.upper) << endl;
	cout << "VCM2\t=\t" << VCM2.expected << Form("\t\trange: (%.17g, %.17g)",VCM2.lower,VCM2.upper) << endl;
	cout << "KECM2\t=\t" << KECM2.expected << Form("\t\trange: (%.17g, %.17g)",KECM2.lower,KECM2.upper) << endl;
	cout << "ECM\t=\t" << ECM.expected << Form("\t\trange: (%.17g, %.17g)",ECM.lower,ECM.upper) << endl;
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
		std::pair<CaseResult,CaseResult> MMMresults = tool.AnalyzeEventMMM(Elab_ej,Thetalab_ej,Philab_ej,Elab_bu1,Thetalab_bu1,Philab_bu1);
		CaseResult MMMcase1 = MMMresults.first;
		CaseResult MMMcase2 = MMMresults.second;

		//---------------------------------------------------------CASE DETERMINATION-------------------------------------------------------------------------------------------------------------
		Int_t MMMfirstcount = 0, MMMsecondcount = 0;
		//cout << endl << count << endl;
		if(tool.CheckInBounds_Vcm_bu1(MMMresults.first.Vcm1)) {MMMfirstcount += 1;}// cout << "pass\t";} else { cout << Form("%.17g\t",MMMresults.first.Vcm1);}
		if(tool.CheckInBounds_Vcm_bu2(MMMresults.first.Vcm2)) {MMMfirstcount += 1;}// cout << "pass\t";} else { cout << Form("%.17g\t",MMMresults.first.Vcm2);}
		if(tool.CheckInBounds_KEcm_bu1(MMMresults.first.KEcm1)) {MMMfirstcount += 1;}// cout << "pass\t";} else { cout << Form("%.17g\t",MMMresults.first.KEcm1);}
		if(tool.CheckInBounds_KEcm_bu2(MMMresults.first.KEcm2)) {MMMfirstcount += 1;}// cout << "pass\t";} else { cout << Form("%.17g\t",MMMresults.first.KEcm2);}
		if(tool.CheckInBounds_Ecm(MMMresults.first.Ecm)) {MMMfirstcount += 1;}// cout << "pass\t";} else { cout << Form("%.17g\t",MMMresults.first.Ecm);}
		//cout << endl;
		if(tool.CheckInBounds_Vcm_bu1(MMMresults.second.Vcm1)) {MMMsecondcount += 1;}// cout << "pass\t";} else { cout << Form("%.17g\t",MMMresults.second.Vcm1);}
		if(tool.CheckInBounds_Vcm_bu2(MMMresults.second.Vcm2)) {MMMsecondcount += 1;}// cout << "pass\t";} else { cout << Form("%.17g\t",MMMresults.second.Vcm2);}
		if(tool.CheckInBounds_KEcm_bu1(MMMresults.second.KEcm1)) {MMMsecondcount += 1;}// cout << "pass\t";} else { cout << Form("%.17g\t",MMMresults.second.KEcm1);}
		if(tool.CheckInBounds_KEcm_bu2(MMMresults.second.KEcm2)) {MMMsecondcount += 1;}// cout << "pass\t";} else { cout << Form("%.17g\t",MMMresults.second.KEcm2);}
		if(tool.CheckInBounds_Ecm(MMMresults.second.Ecm)) {MMMsecondcount += 1;}// cout << "pass\t";} else { cout << Form("%.17g\t",MMMresults.second.Ecm);}
		//cout << endl;

		TString temp;
		if(MMMfirstcount > MMMsecondcount){
			if(decayparticle.EqualTo(tool.GetBreakup1Nucleus().ToString())){temp="YES";count1_c += 1;}else{temp="NO";}
			outfile << decayparticle << "\t" << tool.GetBreakup1Nucleus().ToString() << "\t" << temp << "\t" << float(MMMfirstcount)/5. << endl;
			count1 += 1;
		} else if(MMMfirstcount < MMMsecondcount){
			if(decayparticle.EqualTo(tool.GetBreakup2Nucleus().ToString())){temp="YES";count2_c += 1;}else{temp="NO";}
			outfile << decayparticle << "\t" << tool.GetBreakup2Nucleus().ToString() << "\t" << temp << "\t" << float(MMMsecondcount)/5. << endl;
			count2 += 1;
		} else {
			temp = "TIE";
			outfile << decayparticle << "\t" << "tie" << "\t" << temp << "\t" << float(MMMfirstcount)/5. << endl;
			count_tie += 1;
		}
		count += 1;
	}

	cout << "Success! Output file: " << outfilepath << endl << endl;
	cout << "Number of events determined to be case 1: " << count1 << "/5000 = " << float(count1)/5000. << endl;
	cout << "Number of events determined to be case 2: " << count2 << "/5000 = " << float(count2)/5000. << endl;
	cout << "Number of events undeterminable: " << count_tie << "/10000 = " << float(count_tie)/10000. << endl;
	cout << endl;
	cout << "Number of events correctly identifed to be case 1: " << count1_c << "/5000 = " << float(count1_c)/5000. << endl;
	cout << "Number of events correctly identified to be case2: " << count2_c << "/5000 = " << float(count2_c)/5000. << endl;
	cout << "Total correct events identified: " << count1_c + count2_c << "/10000 = " << float(count1_c + count2_c)/10000. << endl;
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