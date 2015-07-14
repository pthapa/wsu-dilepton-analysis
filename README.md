# wsu-dilepton-analysis
Code for WSU dilepton analysis
```
verbatim
```
How to connect to the lxplus Machine:
```
ssh -XtY username@lxplus.cern.ch

```
Note: username is username of lxplus
Passowrd:Type Nice password
Passphrase: Type password for passPhrase
go to Work directory
go to CMSSW release (example CMSSW_7_4_1)

IMPORTANT::
 If you are using relase first  time follow this step othewise skip this step
steps to run when checking out a new release

search through available CMSSW releases that match the pattern W_7_4

```
scram l CMSSW|grep W_7_4  

```
check out the desired release
```
cmsrel CMSSW_7_4_1

```
steps to run every time you log in and want to work on a given release
show the current scram architecture

```
scram arch 

```
set the scram architecture to the desired value
```
export SCRAM_ARCH=slc6_amd64_gcc491

```
```
cd CMSSW_7_4_1/src/

```
set up the CMS environment based on the release area you're in

```
cmsenv 

```
 



go to src
create cms environmet typing 
```
cmsenv

```
go to WSUDilepton/Muonanalyzer

We build our code before or at the MuonAnalyzer directory using scram b:
I generally build using 
```
scram b -j3

```
-j3 menas I am building three files at a time. To save time we can build number of files as much as we want at a time. Jared suggested me to run 8 files at a time.

MuonAnalyzer contains folloing file and directories:
CosmicMuonAnalysis_2012D.root, interface, output.log, plugings, python, and test.

interface dierctory contains header file such as MuonAnalyzer.h where we define our variables, functions, structures inside MuonAnalysis class
test directory contains configuration and plotter files.
After building a program we run configuration file using cmsRun configuration file.
Example:
```
cmsRun wsuMuonAnalyzer_cfg.py

```
cmsRun outputs the root file inside the test directory. The name of the root file is given in configuration file. 
Example:
```
fileName = cms.string('CosmicMuonAnalysis_2012_struct.root')

```
cmsRun outputs on the screen !!!!
Alternative way for cmsRun:
Creates a log file as a output:
To be checked !!!!!

```
cmsRun wsuMuonAnalyzer_cfg > logfile& 
 
```
creates a logfile on the same directory and writes output on the logfile and can not be seen on  the screen
```
jobs

```
```

cmsRun wsuMuonAnalyzer_cfg > &logfile&
 
 ```
 ```
 
tail -f logfile

```
```
ll -lshtar 

```



plotter file is used to plot a Histogram from TTree!
	 



