# imports ROOT as a 
import ROOT as r 
# imports TH1F and TH2F from ROOT
from ROOT import TH1F,TH2F

#create a TCanvas object to draw a histogram into
 
width = 600
height = 600
#python does not care types
c = r.TCanvas("canvas", "Cosmic Muon Analysis", width, height)
# opens up ".root" file and only allows to read
f = r.TFile.Open("CosmicMuonAnalysis_2012D.root", "read")
# ???
t = f.Get("analysisMuons/MuonTree")
print t
#for event in t
#print t.branch





#you will need a TFile object
#you will need the TTree object

#you should split the canvas into a 2 by 2 grid
#draw four histograms:
#  pt upper vs pt lower   (2D)
#  dxy vs dz              (2D)
#  number of tracker hits (1D)
#  number of pixel hits   (1D)
h_n_Mstation = TH1F("h_n_Mstation", "Number of muon station hit", 50, -0.5, 49.5)

h_n_pix = TH1F("h_n_pix", "Number of pixel hit", 50, -0.5, 49.5)
h_n_trk = TH1F("h_n_trk", "Number of tracker hit", 50, -0.5, 49.5)
pt_U_vs_pt_L = TH2F("pt_U_vs_pt_L", "pt uper vs pt lower", 100, 0., 1000.,100, 0., 1000.)
dxy_U_vs_dz_U = TH2F("dxy_U_VS_dz_U","dxy versus dz", 200,-1000., 1000, 200,-1000., 1000.)

dxy_L_vs_dz_L = TH2F("dxy_L_VS_dz_L","dxy lower versus dz lower", 200,-1000., 1000, 200,-1000., 1000.)
dxy_U_vs_dxy_L = TH2F("dxy_U_VS_dxy_L","dxy upper versus dxy lower", 200,-1000., 1000, 200,-1000., 1000.)
dz_U_vs_dz_L = TH2F("dz_U_VS_dz_L","dz upper versus dz lower", 200,-1000., 1000, 200,-1000., 1000.)

# Draw histograms for Stand Alone Muons:



cut = "muon_upper_pt>0&&muon_lower_pt>0"
# what does >> means ? However it connects the variable defined in a header file
#to the histogram object defined in this file
t.Draw("muon_upper_number_of_pixel_hit>>h_n_pix",cut, "ep0")
t.Draw("muon_upper_number_of_tracker_hit>>h_n_trk",cut, "ep0")
t.Draw("muon_upper_number_of_muon_station_hit>>h_n_Mstation",cut, "ep0")

# Use colon when you are drawing 2D histogram
t.Draw("muon_upper_pt:muon_lower_pt>>pt_U_vs_pt_L",cut, "colz")
t.Draw("muon_upper_dxy:muon_upper_dz>>dxy_U_VS_dz_U",cut, "colz")

t.Draw("muon_lower_dxy:muon_lower_dz>>dxy_L_VS_dz_L",cut, "colz")
t.Draw("muon_upper_dxy:muon_lower_dxy>>dxy_U_VS_dxy_L",cut, "colz")
t.Draw("muon_upper_dz:muon_lower_dz>>dz_U_VS_dz_L",cut, "colz")




c.Clear()
# divides canavas into different numbers according to the arguments given inside Divide
c.Divide(3,3)
c.Update()
c.cd(1)
h_n_pix.Draw("ep0")

c.cd(2)
h_n_trk.Draw("ep0")

c.cd(3)
h_n_Mstation.Draw("ep0")

c.cd(4)
pt_U_vs_pt_L.Draw("colz")

c.cd(5)
dxy_U_vs_dz_U.Draw("colz")

c.cd(6)
dxy_L_vs_dz_L.Draw("colz")

c.cd(7)
dxy_U_vs_dxy_L.Draw("colz")

c.cd(8)
dz_U_vs_dz_L.Draw("colz")

#save the output histogram as a pdf and png
c.SaveAs("Upper_Muon.png")

raw_input("Press enter to Quit")
