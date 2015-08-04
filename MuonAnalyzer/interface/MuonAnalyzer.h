#ifndef WSUDILEPTONS_MUONANALYZER_H
#define WSUDILEPTONS_MUONANALYZER_H


// system include files
#include <memory>

// user include files
#include <FWCore/Framework/interface/Frameworkfwd.h>
#include <FWCore/Framework/interface/EDAnalyzer.h>

#include <FWCore/Framework/interface/Event.h>
#include <FWCore/Framework/interface/MakerMacros.h>

#include <FWCore/ParameterSet/interface/ParameterSet.h>
#include <DataFormats/PatCandidates/interface/Muon.h>
#include <DataFormats/Candidate/interface/Candidate.h>
#include <DataFormats/MuonReco/interface/MuonCocktails.h>
#include <DataFormats/MuonReco/interface/MuonFwd.h>

// TFile Service
#include <FWCore/ServiceRegistry/interface/Service.h>
#include <CommonTools/UtilAlgos/interface/TFileService.h>
#include <TTree.h>
#include <TH2.h>
#include <TH1.h>

//
// class declaration 


   class MuonAnalyzer : public edm::EDAnalyzer {

  public:
  struct cosmicVariables
  {
  int muon_upper_charge, muon_lower_charge;
  int muon_upper_number_of_pixel_hit, muon_upper_number_of_tracker_hit, muon_upper_number_of_muon_station_hit, muon_upper_hit;
  int muon_lower_number_of_pixel_hit, muon_lower_number_of_tracker_hit, muon_lower_number_of_muon_station_hit, muon_lower_hit;
  double muon_upper_pt, muon_upper_eta, muon_upper_phi, muon_upper_theta, muon_upper_dxy, muon_upper_dz;
  double muon_lower_pt, muon_lower_eta, muon_lower_phi, muon_lower_theta, muon_lower_dxy, muon_lower_dz;
  double muon_upper_chi_square_over_n_d_o_f, muon_upper_inner_Y_position, muon_upper_outer_Y_position;
  double muon_lower_chi_square_over_n_d_o_f, muon_lower_inner_Y_position, muon_lower_outer_Y_position;
 
  bool muon_upper_stand_alone, muon_upper_combined, muon_upper_tracker;
  bool muon_lower_stand_alone, muon_lower_combined, muon_lower_tracker;
  bool debug;
  

  static std::string contents()
  {
    return "muon_upper_charge/I:muon_lower_charge:muon_upper_number_of_pixel_hit:muon_upper_number_of_tracker_hit:muon_upper_number_of_muon_station_hit:muon_upper_hit:muon_lower_number_of_pixel_hit:muon_lower_number_of_tracker_hit:muon_lower_number_of_muon_station_hit:muon_lower_hit:muon_upper_pt/D:muon_upper_eta:muon_upper_phi:muon_upper_theta:muon_upper_dxy:muon_upper_dz:muon_lower_pt:muon_lower_eta:muon_lower_phi:muon_lower_theta, muon_lower_dxy:muon_lower_dz:muon_upper_chi_square_over_n_d_o_f:muon_upper_inner_Y_position:muon_upper_outer_Y_position:muon_lower_chi_square_over_n_d_o_f:muon_lower_inner_Y_position:muon_lower_outer_Y_position";
  } 
};
struct cosmicMuon
{

  cosmicVariables standAlone;
  cosmicVariables combined;
  cosmicVariables tracker;


};

  explicit MuonAnalyzer(const edm::ParameterSet&);
  ~MuonAnalyzer();
  
  static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);
  void initialize(cosmicMuon &theCosmicObject);
  void getTracRef(reco::TrackRef ref, cosmicVariables &theCosmicVariables);
  void selectMuon(cosmicVariables &theCosmicVariables);
 

  
private:
  virtual void beginJob() override;
  virtual void analyze(const edm::Event&, const edm::EventSetup&) override;
  virtual void endJob() override;
  
  //virtual void beginRun(edm::Run const&, edm::EventSetup const&) override;
  //virtual void endRun(edm::Run const&, edm::EventSetup const&) override;
  //virtual void beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&) override;
  //virtual void endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&) override;
  //virtual void fillDescriptions(edm::ConfigurationDescriptions& descriptions) {


  //  //The following says we do not know what parameters are allowed so do no validation
  //  // Please change this to state exactly what you do use, even if it is no parameters
  //  edm::ParameterSetDescription desc;
  //  desc.setUnknown();
  //  descriptions.addDefault(desc);
  //}
  
  // ----------member data ---------------------------
  edm::InputTag muonSrc_;
  edm::Service<TFileService> fs;
   TTree *cosmicTree;   
   TH1F * h_pt, * h_eta, * h_phi;
   TH1F *h_theta, *h_dxy, *h_dz, *h_number_of_pixel_hit, *h_number_of_tracker_hit;
   TH2F * h2_pt1_vs_pt2, * h2_eta1_vs_eta2, * h2_phi1_vs_phi2;

  

 
 
  //  double muon2_pt, muon2_eta, muon2_phi, muon2_theta, muon2_dxy, muon2_dz;
  // double delta_phi, delta_eta, delta_theta;
  // double theta;
  // double dxy, dz;
 
  //  double momentum_resolution;
 public:
 cosmicMuon cosmicObject;

};
#endif
