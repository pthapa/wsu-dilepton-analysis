#include "WSUDiLeptons/MuonAnalyzer/interface/MuonAnalyzer.h"
// -*- C++ -*-
//
// Package:    CosmicStudies/MuonAnalyzer
// Class:      MuonAnalyzer
// 
/**\class MuonAnalyzer MuonAnalyzer.cc CosmicStudies/MuonAnalyzer/plugins/MuonAnalyzer.cc

   Description: [one line class summary]

   Implementation:
   [Notes on implementation]

*/
//
// Original Author:  Jared Sturdy
//  Created:  Wed, 25 Feb 2015 12:55:49 GMT
//




void MuonAnalyzer:: initialize(MuonAnalyzer::cosmicMuon &theCosmicObject)
{
 
  theCosmicObject.standAlone.muon_upper_charge = -99;
  theCosmicObject.standAlone.muon_lower_charge = -99;
  theCosmicObject.standAlone.muon_upper_pt = -1.;
  theCosmicObject.standAlone.muon_lower_pt = -1.;
  theCosmicObject.standAlone.muon_upper_eta = -10.;
  theCosmicObject.standAlone.muon_lower_eta = -10.;
  theCosmicObject.standAlone.muon_upper_phi = -10.;
  theCosmicObject.standAlone.muon_lower_phi = -10.;
  theCosmicObject.standAlone.muon_upper_theta = -10.;
  theCosmicObject.standAlone.muon_lower_theta = -10.;
  theCosmicObject.standAlone.muon_upper_dxy = 0.;
  theCosmicObject.standAlone.muon_lower_dxy = 0.;
  theCosmicObject.standAlone.muon_upper_dz = 0.;
  theCosmicObject.standAlone.muon_lower_dz = 0.;
  theCosmicObject.standAlone.muon_upper_number_of_muon_station_hit = -1;
  theCosmicObject.standAlone.muon_upper_number_of_pixel_hit = -1;
  theCosmicObject.standAlone.muon_upper_number_of_tracker_hit = -1;
  theCosmicObject.standAlone.muon_upper_hit = -1;
  theCosmicObject.standAlone.muon_lower_number_of_muon_station_hit = -1;
  theCosmicObject.standAlone.muon_lower_number_of_pixel_hit = -1;
  theCosmicObject.standAlone.muon_lower_number_of_tracker_hit = -1,
    theCosmicObject.standAlone.muon_lower_hit = -1;
  theCosmicObject.standAlone.muon_upper_chi_square_over_n_d_o_f = -1.;
  theCosmicObject.standAlone.muon_upper_inner_Y_position = 0.;
  theCosmicObject.standAlone.muon_upper_outer_Y_position = 0.;
  theCosmicObject.standAlone.muon_lower_chi_square_over_n_d_o_f = -1.;
  theCosmicObject.standAlone.muon_lower_inner_Y_position = 0.;
  theCosmicObject.standAlone.muon_lower_outer_Y_position = 0.;
  
  theCosmicObject.standAlone.muon_upper_stand_alone=0;
  theCosmicObject.standAlone.muon_upper_combined=0;
  theCosmicObject.standAlone.muon_upper_tracker=0;
  theCosmicObject.standAlone.muon_lower_stand_alone=0;
  theCosmicObject.standAlone.muon_lower_combined =0; 
  theCosmicObject.standAlone.muon_lower_tracker=0;

  theCosmicObject.combined =  theCosmicObject.standAlone;

  theCosmicObject.tracker =  theCosmicObject.standAlone;



}// closes the initialize function



//void MuonAnalyzer:: getTracRef(reco::TrackRef ref, MuonAnalyzer:: cosmicVariables &theCosmicVariables, bool debug=false)
void MuonAnalyzer:: getTracRef(reco::TrackRef ref, MuonAnalyzer:: cosmicVariables &theCosmicVariables)


{

  // std::cout << " upperRef is processed !!!"<< std::endl;

  if (ref->innerPosition().Y() > 0) {


    // std::cout << " upperRef is processed !!!"<< std::endl;
    // std::cout << ref.innerOk()<< std::endl;

    //fill these out
    //	theCosmicVariables.muon_upper_stand_alone = muon_is_stand_alone;// assign muon_is_stand_alont to muon_upper_stand_alone 
    // if it passes the the condition inside the if statemt
    //	theCosmicVariables.muon_upper_combined = muon_is_combined;
    //	theCosmicVariables.muon_upper_tracker =  muon_is_traker;
    theCosmicVariables.muon_upper_charge= ref->charge();
    theCosmicVariables.muon_upper_pt= ref->pt();
    theCosmicVariables.muon_upper_eta = ref->eta();
    theCosmicVariables.muon_upper_phi =ref->phi();
    theCosmicVariables.muon_upper_theta=ref->theta();
    theCosmicVariables. muon_upper_dxy= ref->dxy();
    theCosmicVariables.muon_upper_dz = ref->dz();
    // std::cout << " upperRef is processed !!!"<< std::endl;


    theCosmicVariables.muon_upper_number_of_pixel_hit= ref->hitPattern().numberOfValidPixelHits();
    theCosmicVariables.muon_upper_number_of_tracker_hit= ref->hitPattern().numberOfValidTrackerHits();
    theCosmicVariables.muon_upper_number_of_muon_station_hit = ref->hitPattern().muonStationsWithValidHits();
    theCosmicVariables.muon_upper_hit=ref->hitPattern().numberOfValidMuonHits();

    // std::cout << " upper hitpattern is processed !!!"<< std::endl;
    // std::cout << ref->hitPattern().numberOfValidPixelHits() << std::endl;
    // std::cout <<  ref->hitPattern().numberOfValidTrackerHits()<< std::endl;
    // std::cout << ref->hitPattern().muonStationsWithValidHits() << std::endl;
    // std::cout << ref->hitPattern().numberOfValidMuonHits() << std::endl;


    //	 muon_upper_chi_square_over_n_d_o_f=  (double)( ref->chi2()/ref->ndof())  ;// Variable or functions ??
    theCosmicVariables.muon_upper_inner_Y_position= ref->innerPosition().Y();
    theCosmicVariables.muon_upper_outer_Y_position= ref->outerPosition().Y(); 
 
    // std::cout << " upper  Y position  is processed !!!"<< std::endl;

	
  }
  else if (ref->innerPosition().Y() < 0) {

    //	theCosmicVariables.muon_lower_stand_alone = muon_is_stand_alone;
    //	theCosmicVariables.muon_lower_combined = muon_is_combined;
    //	theCosmicVariables.muon_lower_tracker =  muon_is_traker;

    theCosmicVariables.muon_lower_charge= ref->charge();
    theCosmicVariables.muon_lower_pt=  ref->pt();
    theCosmicVariables.muon_lower_eta = ref->eta();
    theCosmicVariables.muon_lower_phi = ref->phi();
    theCosmicVariables.muon_lower_theta= ref->theta();

    theCosmicVariables.muon_lower_dxy= ref->dxy();
    theCosmicVariables.muon_lower_dz = ref->dz();

    //std::cout << " lowerRef is processed !!!"<< std::endl;
    // std::cout <<  ref->dz()<< std::endl;



    theCosmicVariables.muon_lower_number_of_pixel_hit= ref->hitPattern().numberOfValidPixelHits();
    theCosmicVariables.muon_lower_number_of_tracker_hit= ref->hitPattern().numberOfValidTrackerHits();
    theCosmicVariables.muon_lower_number_of_muon_station_hit = ref->hitPattern().muonStationsWithValidHits();
    theCosmicVariables.muon_lower_hit=ref->hitPattern().numberOfValidMuonHits();
   
    // std::cout << " lower hitpattern is processed !!!"<< std::endl;
    // std::cout << ref->hitPattern().numberOfValidPixelHits() << std::endl;
    // std::cout <<  ref->hitPattern().numberOfValidTrackerHits()<< std::endl;
    // std::cout << ref->hitPattern().muonStationsWithValidHits() << std::endl;
    // std::cout << ref->hitPattern().numberOfValidMuonHits() << std::endl;


 


    //	muon_lower_ chi_square_over_n_d_o_f= (double)( ref->chi2()/ref->ndof()) ;// Variable or functions ??
    theCosmicVariables.muon_lower_inner_Y_position= ref->innerPosition().Y();
    theCosmicVariables.muon_lower_outer_Y_position= ref->outerPosition().Y();
    // std::cout << "  lower Y is processed !!!"<< std::endl;


  }//coles Y<0;
}//closes the function getTracRef




MuonAnalyzer::MuonAnalyzer(const edm::ParameterSet& pset)
{
  muonSrc_ = pset.getParameter<edm::InputTag>("muonSrc");


  //now do what ever initialization is needed
  h_pt  = fs->make<TH1F>( "pt"  , "p_{t}", 500,  0., 2500. );
  h_eta = fs->make<TH1F>( "eta" , "#eta" , 100, -5., 5.    );
  h_phi = fs->make<TH1F>( "phi" , "#phi" , 100,  0., 6.3   );
  h_theta = fs->make<TH1F>("theta" ,"#theta",500, 0.,3.15);
  h_dxy = fs->make<TH1F>("dxy", "d_{xy}", 500,-100., 100.);
  h_dz = fs->make<TH1F>("dz",  "d_{z}", 500, -50., 50.);
  h_number_of_pixel_hit = fs->make<TH1F>("number_of_pixel_hit", "N_{hit}^{pixel}", 25,0, 25);
  h_number_of_tracker_hit = fs->make<TH1F>("number_of_tracker_hit", "N_{hit}^{tracker}", 50, 0, 50);


  // h2_pt1_vs_pt2   = fs->make<0., 2500.);
  h2_eta1_vs_eta2 = fs->make<TH2F>( "eta1_vs_eta2" , "#eta_{1} vs. #eta_{2}" , 100, -5., 5.   , 100, -5., 5.   );
  h2_phi1_vs_phi2 = fs->make<TH2F>( "phi1_vs_phi2" , "#phi_{1} vs. #phi_{2}" , 100,  0., 6.3  , 100,  0., 6.3  );

}


MuonAnalyzer::~MuonAnalyzer()
{
 
  // do anything here that needs to be done at desctruction time
  // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  ------------
//The method analyze receives a pointer ev to the object edm::Event which contains all event data
// Event Setup selects the valid event
void MuonAnalyzer::analyze(const edm::Event& ev, const edm::EventSetup& es)
{

  // initialization with unconvetional values
 
  initialize(cosmicObject);

 
  //edm::Handle<edm::View<reco::Muon> > muonColl;

  //These declarations create handles called "muonColl" to the types of records "reco::MuonCollection" that you want
  // to retrieve from event "ev".
  edm::Handle<reco::MuonCollection > muonColl;
  //Pass the handle "muonColl" to the method "getByLabel", which is used to 
  // retrieve one and only one instance of the type in question with
  // the label specified out of event "ev"
  ev.getByLabel(muonSrc_, muonColl);
  if( muonColl->size()!= 2)
    return;// returns void
  //std::cout<<"muonColl->size(): "<< muonColl->size( )<< std::endl;
 
  //  int muIdx = 0;
  for (reco::MuonCollection::const_iterator muon=muonColl->begin();// muonCollEnd=muonColl->end();
       muon!=muonColl->end();
       ++muon)
    {
      reco::TrackRef ref;
      // define temporary boolean for future use
      // bool muon_is_stand_alone=false;
      // bool muon_is_combined=false;
      // bool muon_is_traker=false;
     
      //logic to select which track ref goes here
      // Every single muon is tested by if else statements
      // if one staement is true, then skips the rest of other statements


      if (muon->standAloneMuon().isNonnull())
	{
	  //  std::cout<< "standAlone Muone is processed !" << std::endl;
	  
	  //  muon_is_stand_alone =true;// if theres is stand alone muon set muon_is_alone  variable as a true
	  ref = muon->standAloneMuon();// assign stand alone muon to ref of type reco::TrackRef
	  getTracRef(ref,cosmicObject.standAlone);
	  
      	}
      if (muon->combinedMuon().isNonnull())
	{
	  std::cout << "combinedMuon is processed !!"<< std::endl;
 
	  // muon_is_combined=true;
	  ref = muon->combinedMuon();
	  getTracRef(ref,cosmicObject.combined);

	}
	
      // Impement these functions
      /*
	ProductID id() const {return product_.id();}
	
	/// Accessor for product getter.
	EDProductGetter const* productGetter() const {return product_.productGetter();}
	
	/// Accessor for product key.
	key_type key() const {return index_;}
	
	// This one just for backward compatibility.  Will be removed soon.
	key_type index() const {return index_;}
	
	/// Returns true if container referenced by the Ref has been cached
	bool hasProductCache() const {return product_.productPtr() != 0;}
	
	/// Checks if collection is in memory or available
	/// in the Event. No type checking is done.
	bool isAvailable() const;
	
	/// Checks if this ref is transient (i.e. not persistable).
	bool isTransient() const {return product_.isTransient();}
	
	
      */
      if(muon->track().isNonnull()){
	//	muon_is_traker=true;
	//	std::cout << "TrackMuon is processed !!!"<< std::endl;
	//	std::cout <<"tracking id"  << muon->track().id()<< std::endl;
	//	std::cout << "product cache" << muon->track().hasProductCache()<< std::endl;
	//	std::cout << "is Available"  << muon->track().isAvailable()<< std::endl;
	//	std::cout << "is Transient"  <<muon->track().isTransient()<< std::endl;
	
	
	ref = muon->track();
	//	std::cout << "TrackMuon is processed !!!"<< std::endl;
	//	std::cout <<"tracking id"  << ref.id()<< std::endl;
	
	
	
	getTracRef(ref,cosmicObject.tracker);
	//	std::cout << "TrackMuon is processed !!!"<< std::endl;
	//	std::cout <<"tracking id"  << ref.id()<< std::endl;
	
	
      }
      cosmicTree->Fill();
    }// close the for loop  
}//closes the analyze function


// ------------ method called once each job just before starting event loop  ------------
void MuonAnalyzer::beginJob()
{
  edm::Service< TFileService > fs;
  
  cosmicTree = fs->make<TTree>( "MuonTree", "TTree variables" );

  cosmicTree->Branch("standAloneMuon",    &(cosmicObject.standAlone), cosmicVariables::contents().c_str());
  cosmicTree->Branch("combined",            &(cosmicObject.combined), cosmicVariables::contents().c_str());
  cosmicTree->Branch("tracker",              &(cosmicObject.tracker), cosmicVariables::contents().c_str());
 
}// closes the beginjob function
    
  
// ------------ method called once each job just after ending the event loop  ------------
void MuonAnalyzer::endJob() 
{
}

// ------------ method called when starting to processes a run  ------------
/*
  void MuonAnalyzer::beginRun(edm::Run const&, edm::EventSetup const&)
  {
  }
*/

// ------------ method called when ending the processing of a run  ------------
/*
  void MuonAnalyzer::endRun(edm::Run const&, edm::EventSetup const&)
  {
  }
*/

// ------------ method called when starting to processes a luminosity block  ------------
/*
  void MuonAnalyzer::beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
  {
  }
*/

// ------------ method called when ending the processing of a luminosity block  ------------
/*
  void MuonAnalyzer::endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
  {
  }

*/

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void MuonAnalyzer::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(MuonAnalyzer);

