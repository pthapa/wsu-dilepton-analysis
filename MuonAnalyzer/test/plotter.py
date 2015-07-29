# imports ROOT as a 
import ROOT as r 
# imports TH1F and TH2F from ROOT
from ROOT import TH1F,TH2F

#create a TCanvas object to draw a histogram into
 
width = 600
height = 600
#python does not care types
c = r.TCanvas("canvas1", "Cosmic Muon Analysis", width, height)
# opens up ".root" file and only allows to read
f = r.TFile.Open("CosmicMuonAnalysis_Run2015B_struct_gooddNoOfEvents.root", "read")
# ???
t = f.Get("analysisMuons/MuonTree")
#print t
#print t.GetEntries()
#print t.GetListOfLeaves().Print()
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
h_resol = TH1F("h_resol", "Resolution of CMS detector", 100, -10, 10)
h_n_pix = TH1F("h_n_pix", "Number of pixel hit", 10, -0.5, 9.5)
h_n_trk = TH1F("h_n_trk", "Number of tracker hit", 10, -0.5, 9.5)
h_n_Mstation = TH1F("h_n_Mstation", "Number of muon station hit", 10, -0.5, 9.5)
pt_U_vs_pt_L = TH2F("pt_U_vs_pt_L", "pt uper vs pt lower", 100, 0., 1000.,100, 0., 1000.)
dxy_U_vs_dz_U = TH2F("dxy_U_vs_dz_U","dxy upper versus dz upper ", 200,-1000., 1000, 200,-1000., 1000.)

dxy_L_vs_dz_L = TH2F("dxy_L_vs_dz_L","dxy lower versus dz lower", 200,-1000., 1000, 200,-1000., 1000.)
dxy_U_vs_dxy_L = TH2F("dxy_U_vs_dxy_L","dxy upper versus dxy lower", 200,-1000., 1000, 200,-1000., 1000.)
dz_U_vs_dz_L = TH2F("dz_U_vs_dz_L","dz upper versus dz lower", 200,-1000., 1000, 200,-1000., 1000.)

# Draw histograms for Stand Alone Muons:


 #int muon_upper_charge, muon_lower_charge;
 # int muon_upper_number_of_pixel_hit, muon_upper_number_of_tracker_hit, muon_upper_number_of_muon_station_hit, muon_upper_hit;
 # int muon_lower_number_of_pixel_hit, muon_lower_number_of_tracker_hit, muon_lower_number_of_muon_station_hit, muon_lower_hit;
 # double muon_upper_pt, muon_upper_eta, muon_upper_phi, muon_upper_theta, muon_upper_dxy, muon_upper_dz;
  #double muon_lower_pt, muon_lower_eta, muon_lower_phi, muon_lower_theta, muon_lower_dxy, muon_lower_dz;
 # double muon_upper_chi_square_over_n_d_o_f, muon_upper_inner_Y_position, muon_upper_outer_Y_position;
 # double muon_lower_chi_square_over_n_d_o_f, muon_lower_inner_Y_position, muon_lower_outer_Y_position;





#standAloneMuon is name of branch in our TTree.We do have nothing to do with structure vatiables
#muon_upper_pt is one the variable inside the standAloneMuon, that's why we use the dot operator to acess that particular
#variable located inside the branch

#define outside the loop:
#histograms, canvas
#file
##create a list with the names of the tree branches corresponding to the different types of track
muonList = ['standAloneMuon', 'combined','tracker']
#muonList = ['standAloneMuon']


##define a loop over the list
#for entry in list:
#    do something
for threeItems in muonList:

#syntax for string manipulations
#myname = "asldfj %d %s %x"%(someInt, someString, someHexInt)
#in the loop you rename/retitle the canvas
    c.SetTitle("%s "%threeItems)


#set up the cuts depending on the particular branch
# fill the histograms 
# draw them on the canvas
# save the canvas
#repeat!

    cut = "%s.muon_upper_pt>0&&%s.muon_lower_pt>0"%(threeItems, threeItems)

    curvature1 = "(%s.muon_upper_charge)/(%s.muon_upper_pt)"%(threeItems, threeItems)
    curvature2 = "(%s.muon_lower_charge)/(%s.muon_lower_pt)"%(threeItems, threeItems)
    resolution = "(%s-%s)/(sqrt(2)*%s)"%(curvature1,curvature2,curvature1)# make resolution a string variable
#print resolution
#exit(1)
# what does >> means ? However it connects the variable defined in a header file
#to the histogram object defined in this file
# use dot operator to specify the varibales related to stanAloneMuon branch
# if you are working only on varibles remove dot operator and branch name stanAloneMuon
#Draw histogram for each of the variables 
    t.Draw(threeItems + ".muon_upper_number_of_pixel_hit>>h_n_pix",cut, "ep0")
    t.Draw(threeItems + ".muon_upper_number_of_tracker_hit>>h_n_trk",cut, "ep0")
    t.Draw(threeItems + ".muon_upper_number_of_muon_station_hit>>h_n_Mstation",cut, "ep0")

  #  print cut
   # t.Draw(threeItems + ".muon_upper_number_of_muon_station_hit","", "ep0")
  #  c.Update()
  #  raw_input("Press enter to continue")
   # t.Draw(threeItems + ".muon_upper_number_of_muon_station_hit",cut, "ep0")
  #  c.Update()
  #  raw_input("Press enter to continue")
  #  print threeItems + ".muon_upper_number_of_muon_station_hit>>h_n_Mstation"
   # print h_n_Mstation , h_n_Mstation.GetEntries()
    t.Draw(resolution+">>h_resol", cut, "ep0")# add strings together


# Use colon when you draw 2D histogram
    t.Draw("%s.muon_upper_pt:%s.muon_lower_pt>>pt_U_vs_pt_L"%(threeItems, threeItems),cut, "colz")
    t.Draw("%s.muon_upper_dxy:%s.muon_upper_dz>>dxy_U_vs_dz_U"%(threeItems, threeItems),cut, "colz")

    t.Draw("%s.muon_lower_dxy:%s.muon_lower_dz>>dxy_L_vs_dz_L"%(threeItems, threeItems),cut, "colz")
    t.Draw("%s.muon_upper_dxy:%s.muon_lower_dxy>>dxy_U_vs_dxy_L"%(threeItems, threeItems),cut, "colz")
    t.Draw("%s.muon_upper_dz:%s.muon_lower_dz>>dz_U_vs_dz_L"%(threeItems, threeItems),cut, "colz")
   # print "%s.muon_upper_dz:%s.muon_lower_dz>>dz_U_vs_dz_L"%(threeItems, threeItems)
   # print dz_U_vs_dz_L, dz_U_vs_dz_L.GetEntries()

   # exit(1)

    c.Clear()
# divides canavas into different numbers according to the arguments given inside Divide
# the following arguments divides the canvas into 3*3 = 9 pads
#Every single division on a canavas is called a pad
#if you do not divide canavas, whole canavas is a pad
    c.Divide(3,3)
#updates canavas
    c.Update()
#Activates number 1 pad and counted  horizontally from left top to right top
    c.cd(1)
#Draws a histogram  h_n_pix on number 1 pad
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

    c.cd(9)
    h_resol.Draw("colz")




#save the output histogram as a pdf and png
    c.SaveAs("%s.png"%threeItems)

    raw_input("Press enter to Quit")

