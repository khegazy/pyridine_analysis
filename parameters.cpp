#include "/reg/neh/home5/khegazy/baseTools/tools/parameters.h"

parameterClass::parameterClass(std::string runName) {

  // Molecule
  molecule = initialState;
  //molecule = finalState2;
  radicalNames.push_back("nitrobenzene");
  radicalNames.push_back("phenoxyRadical");
  radicalNames.push_back("phenylRadical");
  molName = radicalNames[molecule];


  // Image parameters
  Nlegendres = 1;
  NradLegBins = 50;
  NmaxRadBins = 750;
  //NradAzmBins = 445;
  NradAzmBins = 555;
  imgSize = 895;
  imgEdgeBuffer = 20;
  hasRef = false;
  refStagePos = -1;
  imgShutterTime = 20;
  imgNormRadMin = 0.045; //0.06; //0.045;
  imgNormRadMax = 0.721; //0.33; //0.721;


  // PV
  getPVs        = true;
  pvSampleTimes = 5;
  pressureSmear = 180;
  pvFolder      = "/reg/ued/ana/scratch/nitroBenzene/PV/";

  // Time Zero
  tZeroQranges.resize(3);
  tZeroQranges[0].push_back(3);     tZeroQranges[0].push_back(3.5);
  tZeroQranges[1].push_back(3.75);  tZeroQranges[1].push_back(5);
  tZeroQranges[2].push_back(2);     tZeroQranges[2].push_back(3);

  tZeroRatio.resize(2);
  tZeroRatio[0] = 1;
  tZeroRatio[1] = 0;

  // Merging scans
  normalizeImgs = false;
  Qnormalize = true;
  mergeSTDscale = 3; //2.6; FIX ME CHANGE compare to Thomas
  mergeImageSTDScale = 2.3;
  legImageNoiseCut = 12;
  azmImageNoiseCut = 105;

  timeWnHigh = 0.8;
  timeFiltOrder  = 5;
  timeFilterType = "lowpass";
  smearTimeBinWindow  = 100;
  timeSmearSTD        = 0.025;
  scanImgAzmSTDcut    = 4;
  scanImgAzmRefSTDcut = 4;


  // Analysis Parameters
  signalRranges.resize(5);
  signalRranges[0].push_back(1.1);  signalRranges[0].push_back(1.7);
  signalRranges[1].push_back(1.7);  signalRranges[1].push_back(2.0);
  signalRranges[2].push_back(2.0);  signalRranges[2].push_back(2.75);
  signalRranges[3].push_back(3.0);  signalRranges[3].push_back(4.0);
  signalRranges[4].push_back(4.0);  signalRranges[4].push_back(5.0);


  // Background removal
  XrayHighCut       = 1e4; //30000;
  XrayLowCut        = 4e3;
  XraySTDcut        = 3;
  XrayWindow        = 20;
  xRayHitDist       = false;

  hotPixel          = 1750;
  bkgSTDcut         = 15;
  shellWidth        = 1;
  Npoly             = 5;
  stdIncludeLeft    = 3; //1;
  distSTDratioLeft  = 0.5;
  stdCutLeft        = 3.5;
  meanBinSize       = 12;
  stdIncludeRight   = 1;
  distSTDratioRight = 0.75;
  stdChangeRatio    = 0.02;
  stdCutRight       = 7; //2.25; //2.75;
  outlierSTDcut     = 7.;
  outlierVerbose    = false;
  radPixDist        = false;
  indicesPath       = "/reg/neh/home/khegazy/analysis/radialFitIndices/";

  outlierMapSTDcut        = 1.5;//75;
  outlierCoreValThresh    = 5000; //90; //65; //5e5;
  outlierCoreRad          = 2; 
  outlierClusterRad       = 3; 
  outlierMinClusterSize   = 50;
  outlierMinPixelSize     = outlierMinClusterSize;
  outlierMinDensity       = 0.0;//0.2;
  outlierShapeVarCut      = 400.5;
  outlierShapeEdgeCut     = 2.75;
  outlierBorderValThresh  = 10; //75; //1e5;
  outlierBorderDistLimit  = 2;
  outlierBorderRad        = 3;
  outlierPadRad           = 7;
  outlierrMaxScale        = 1;
  outlierrMinScale        = 0;
  outliercMaxScale        = 4;
  outliercMinScale        = 0;
 

  readoutStart         = 0.7; //0.94; // Use ratio < 1. Converts to bins at the end
  readoutEnd           = 1; // Use ratio < 1. Converts to bins at the end
   
  // Centering
  centerFxnType     = 3;
  centerShellWidth  = 15; 
  centerSTDcut      = 3;

  meanInds.push_back(140); 
  meanInds.push_back(155); 
  meanInds.push_back(170); 
  meanInds.push_back(185); 
  meanInds.push_back(200); 
  meanInds.push_back(250); 

  // Filtering
  order  = 5;
  WnLow  = 0.005;
  WnHigh = 0.08;
  filterType = "lowpass";
  pltFilterVerbose = false;

  // Remove low order polynomial noise
  NlowOrderPoly         = 6;
  lowPolySubtractStudy  = false;

  // Pair correlation parameters
  NautCpadding      = 10000;
  holeRat           = 0.15;
  rMaxLegRat        = 0.75;
  rMaxAzmRat        = 0.07; //0.052;
  padDecayRat       = 0.5;
  //filterVar         = std::pow(NradAzmBins/3.25, 2);
  filterVar         = std::pow(NradAzmBins/4, 2);
  lowQfillSimScale  = 0.3;
  fillLowQfile      = "/reg/neh/home5/khegazy/analysis/nitrobenzene/UED/timeDepStudies/results/sim-phenoxyRadicalLowQfill[555].dat";
  fillLowQtheory    = true;


  subtractReference = true;

  // Simulation parameters
  compareSims     = false;
  simPairCorr     = true;
  getBonds        = true;
  simPltVerbose   = false;
  NradSimBins     = NradAzmBins;
  Iebeam          = 5;
  elEnergy        = 3.7e6;
  screenDist      = 4;
  xyzDir          = "/reg/neh/home/khegazy/analysis/nitrobenzene/simulation/XYZfiles/";
  simOutputDir    = "/reg/ued/ana/scratch/nitroBenzene/simulations/";
  fsFitOffset     = false;
  fsFilterSMS     = false; 
  fsFilterVar     = std::pow(NradAzmBins/4.5, 2); 
  fsQfitBegin     = 1;
  fsQfitEnd       = 4;
  fsRfitBegin     = 1.1;
  fsRfitEnd       = 8;
  finalStates.push_back("phenylRadical");
  finalStates.push_back("phenoxyRadical");

  preProcOutputDir = "/reg/ued/ana/scratch/nitroBenzene/rootFiles/";
  mergeScansOutputDir = "/reg/ued/ana/scratch/nitroBenzene/mergeScans/";
  scanSearchOutputDir = "/reg/ued/ana/scratch/nitroBenzene/scanSearch/";
  radialPixelDist = "/reg/ued/ana/scratch/nitroBenzene/radialPixelDist/";
  backgroundImage = "NULL";
  backgroundFolder = "/reg/ued/ana/scratch/nitroBenzene/background/";
  indexPath = "/reg/neh/home/khegazy/analysis/radialFitIndices/";
  pltCent = false;
  verbose = false; 
  pltVerbose = false;


  scaleStagePos = 1e4;

  if (runName.compare("20161102_LongScan1") == 0) {

    NradLegBins = 30;
    imgMatType = "uint32";

    QperPix = 0.0223;
    maxQleg = QperPix*imgSize/2;

    hasRef = true;
    refStagePos = 38.0;

    timeZero = 0.5;
    legStdCut = 1.5;

    /////  Center Finding Parameters  /////
    // Rough center finding
    sigma = 8;
    blockCentR = 560;
    blockCentC = 485;
    minRad = 90;
    maxRad = 340;
    meanInd = 335;
    COMstdScale = 0.025;

    // Fine centering
    centerFxnType = 2;
    centerShellWidth = 130; //70;
    holeR = 547;
    holeC = 492;
    holeRad = 60;
 
    cntrScale = 10;
    cntrMinScale = 1;
    cntrPowellTol = 0.2;
    cntrFracTol1d = 0.01;

    // Laser Background Removal Parameters
    hasLaserBkg = true;
    laserClusterRemoval = false;
    decayConst = -1.0/400.0;
    coreValThresh = 6.0e-3; //90; //65; //5e5;
    coreRad = 4; 
    clusterRad = 1; 
    minClusterSize = 550;
    minPixelSize = 300;
    minDensity = 0.2;//0.2;
    borderValThresh = 5.8e-3; //75; //1e5;
    borderRad = 3;
    padRad = 10;

    nanMap.clear();
    nanMap.resize(imgSize);
    for (int ir=0; ir<imgSize; ir++) {
      nanMap[ir].resize(imgSize, 0);
      if ((ir > 350) && (ir < 500)) {
        for (int ic=(int)imgSize*0.8; ic<imgSize; ic++) {
          nanMap[ir][ic] = NANVAL;
        }
      }
    }

    /*
    for (int ir=imgSize/2-40; ir<imgSize/2+40; ir++) {
      for (int ic=imgSize/2-120; ic<imgSize/2; ic++) {
        nanMap[ir][ic] = nanVal;
      }
    }
    for (int ir=imgSize/2-200; ir<imgSize/2+50; ir++) {
      for (int ic=imgSize-225; ic<imgSize-115; ic++) {
        nanMap[ir][ic] = nanVal;
      }
    }
    for (int ir=imgSize/2-60; ir<imgSize/2+35; ir++) {
      for (int ic=imgSize-75; ic<imgSize; ic++) {
        nanMap[ir][ic] = nanVal;
      }
    }
    */


  }
  else if ((runName.compare("20180701_0746") == 0)
            || (runName.compare("20180701_0738") == 0)
            || (runName.compare("20180701") == 0)) {

    // Image parameters
    QperPix = 0.0223;
    legStdCut = 3.0;
    NbinsSkip = 50; //27;

    // Filtering
    suppressBins = 75;
    padMaxHeight = 3;

    // Measurement parameters
    timeZero = 0.3;
    hasRef = true;
    refStagePos = 154.0;
    imgMatType = "uint16";

    // Bad scans
    /*
    for (int i=169; i<=175; i++) {
      badScans.push_back(i);
    }
    //for (int i=179; i<=181; i++) {
    //  badScans.push_back(i);
    //}
    badScans.push_back(131);
    badScans.push_back(165);
    badScans.push_back(203);
    badScans.push_back(103);
    badScans.push_back(53);
    badScans.push_back(57);
    badScans.push_back(90);
    badScans.push_back(91);
    badScans.push_back(98);
    for (int i=166; i<203; i++) {
      badScans.push_back(i);
    }
    */

    badScans.push_back(37);
    badScans.push_back(38);
    badScans.push_back(41);
    badScans.push_back(57);
    badScans.push_back(87);
    badScans.push_back(96);
    badScans.push_back(111);
    badScans.push_back(147);
    badScans.push_back(152);
    for (int i=166; i<203; i++) {
      badScans.push_back(i);
    }

    badImages[4].push_back(1542450);
    badImages[4].push_back(1542850);
    badImages[6].push_back(1542550);
    badImages[17].push_back(1542450);
    badImages[18].push_back(1543150);
    badImages[29].push_back(1543550);
    badImages[35].push_back(1530500);
    badImages[62].push_back(1543550);
    badImages[68].push_back(1542450);
    badImages[98].push_back(1543550);
    badImages[98].push_back(1544300);
    badImages[101].push_back(1542350);
    badImages[105].push_back(1530500);
    badImages[131].push_back(1543250);
    badImages[131].push_back(1543400);
    badImages[149].push_back(1542350);
    badImages[155].push_back(1543250);

    //badImages[187].push_back(1542550);
    //badImages[196].push_back(1550300);


    // Background
    backgroundImage = "backgroundImg-20180701_0738.dat";
    hasLaserBkg = true;
    laserClusterRemoval = false;

    int row, col;
    int rad = 57;
    int hRad = 45;
    nanMap.clear();
    nanMap.resize(1024);
    for (uint ir=0; ir<nanMap.size(); ir++) {
      nanMap[ir].resize(1024, 0);
    }
    for (int ir=510; ir<660; ir++) {
      for (int ic=443; ic<583; ic++) {
        row = ir - 570;
        col = ic - 535;
        if (rad > std::sqrt(row*row + col*col)) {
          nanMap[ir][ic] = NANVAL;
        }
        row = ir - 590;
        col = ic - 518;
        if (sqrt(row*row + col*col) < hRad) {
          nanMap[ir][ic] = NANVAL;
        }
      }
    }

    rad = 48;
    for (int ir=420; ir<660; ir++) {
      for (int ic=443; ic<583; ic++) {
        row = ir - 565;
        col = ic - 510;
        if (sqrt(row*row + col*col) < rad) {
          nanMap[ir][ic] = NANVAL;
        }
      }
    }

    rad = 40;
    for (int ir=540; ir<610; ir++) {
      for (int ic=560; ic<630; ic++) {
        row = ir - 575;
        col = ic - 575;
        if (sqrt(row*row + col*col) < rad) {
          nanMap[ir][ic] = NANVAL;
        }
      }
    }

    rad = 60;
    for (int ir=560; ir<680; ir++) {
      for (int ic=510; ic<630; ic++) {
        row = ir - 585;
        col = ic - 550;
        if (sqrt(row*row + col*col) < rad) {
          nanMap[ir][ic] = NANVAL;
        }
      }
    }


    /*
    outlierMapSTDcut        = 2.0;//75;
    outlierCoreValThresh    = 100000; //90; //65; //5e5;
    outlierCoreRad          = 2; 
    outlierClusterRad       = 3; 
    outlierMinClusterSize   = 50;
    outlierMinPixelSize     = outlierMinClusterSize;
    outlierMinDensity       = 0.0;//0.2;
    outlierShapeCut         = 4;
    outlierBorderValThresh  = 10; //75; //1e5;
    outlierBorderDistLimit  = 2;
    outlierBorderRad        = 3;
    outlierPadRad           = 7;
    outlierrMaxScale        = 1;
    outlierrMinScale        = 0;
    outliercMaxScale        = 4;
    outliercMinScale        = 0;
    */
   
    // Remove hole
    holeR = 587; //590;
    holeC = 512; //513;
    holeRad = 43; //50;

    /////  Center Finding Parameters  /////
    // Rough center finding
    sigma = 8;
    blockCentR = 560;
    blockCentC = 505;
    minRad = 70;
    maxRad = 325;
    meanInd = 350;
    COMstdScale = 0.075;

    cntrScale = 10;
    cntrMinScale = 0.5;
    cntrPowellTol = 0.5;
    cntrFracTol1d = 0.005;

    // PVs
    pvMap["pressure"]    = "pressureSampleChamber_07_01_2018_07_47_00-07_02_2018_08_41_10-17932.dat";
    pvMap["UVcounts"]    = "UVsampleChamberCam_07_01_2018_07_47_00-07_02_2018_08_41_10-17932.dat";
    pvMap["bunkerTemp"]  = "bunkerTemperature_07_01_2018_07_47_00-07_02_2018_08_41_10-17932.dat";
    pvMap["highBayTemp"] = "highBayTemperature_07_01_2018_07_47_00-07_02_2018_08_41_10-17932.dat"; 
 
  }
  else if ((runName.compare("20180630_1925") == 0)
            || (runName.compare("20180630_1917") == 0)
            || (runName.compare("20180630") == 0)) {

    // Image parameters
    QperPix = 0.0223;
    legStdCut = 3.0;
    NbinsSkip = 50; //31;

    // Measurement parameters
    timeZero = 0.3;
    hasRef = true;
    refStagePos = 154.0;
    imgMatType = "uint16";

    // Filtering
    suppressBins = 75;
    padMaxHeight = 4;

    // Bad scans
    /*
    badScans.push_back(20);
    badScans.push_back(86);
    badScans.push_back(97);
    */

    badScans.push_back(8);
    badScans.push_back(62);
    badScans.push_back(86);
    badScans.push_back(97);

    badImages[20].push_back(1543550);
    badImages[26].push_back(1543250);
    badImages[27].push_back(1542750);
    badImages[27].push_back(1545800);
    badImages[46].push_back(1542950);
    badImages[68].push_back(1542650);
    badImages[68].push_back(1543400);
    badImages[70].push_back(1542350);
    badImages[75].push_back(1544000);
    badImages[76].push_back(1542350);
    badImages[94].push_back(1543400);
    badImages[96].push_back(1543050);

    // Background
    backgroundImage = "backgroundImg-20180630_1917.dat";
    hasLaserBkg = true;
    laserClusterRemoval = false;

    int row, col;
    int rad = 58;
    int hRad = 50;
    nanMap.clear();
    nanMap.resize(1024);
    for (uint ir=0; ir<nanMap.size(); ir++) {
      nanMap[ir].resize(1024, 0);
    }
    for (int ir=510; ir<660; ir++) {
      for (int ic=443; ic<583; ic++) {
        row = ir - 570;
        col = ic - 535;
        if (rad > std::sqrt(row*row + col*col)) {
          nanMap[ir][ic] = NANVAL;
        }
        row = ir - 590;
        col = ic - 518;
        if (sqrt(row*row + col*col) < hRad) {
          nanMap[ir][ic] = NANVAL;
        }
      }
    }

    rad = 48;
    for (int ir=420; ir<660; ir++) {
      for (int ic=443; ic<583; ic++) {
        row = ir - 565;
        col = ic - 510;
        if (sqrt(row*row + col*col) < rad) {
          nanMap[ir][ic] = NANVAL;
        }
      }
    }

    rad = 40;
    for (int ir=540; ir<610; ir++) {
      for (int ic=560; ic<630; ic++) {
        row = ir - 575;
        col = ic - 575;
        if (sqrt(row*row + col*col) < rad) {
          nanMap[ir][ic] = NANVAL;
        }
      }
    }

    rad = 60;
    for (int ir=560; ir<680; ir++) {
      for (int ic=510; ic<630; ic++) {
        row = ir - 585;
        col = ic - 550;
        if (sqrt(row*row + col*col) < rad) {
          nanMap[ir][ic] = NANVAL;
        }
      }
    }


    // Remove hole
    holeR = 590;
    holeC = 513;
    holeRad = 50;

    /////  Center Finding Parameters  /////
    // Rough center finding
    sigma = 8;
    blockCentR = 574;
    blockCentC = 505;
    minRad = 70;
    maxRad = 325;
    meanInd = 350;
    COMstdScale = 0.075;

    cntrScale = 10;
    cntrMinScale = 1;
    cntrPowellTol = 1;
    cntrFracTol1d = 0.01;

    // PV
    pvMap["pressure"]    = "pressureSampleChamber_06_30_2018_19_25_55-07_01_2018_07_15_50-8521.dat";
    pvMap["UVcounts"]    = "UVsampleChamberCam_06_30_2018_19_25_55-07_01_2018_07_15_50-8521.dat";
    pvMap["bunkerTemp"]  = "bunkerTemperature_06_30_2018_19_25_55-07_01_2018_07_15_50-8521.dat";
    pvMap["highBayTemp"] = "highBayTemperature_06_30_2018_19_25_55-07_01_2018_07_15_50-8521.dat";
  }
  else if ((runName.compare("20180629_1630") == 0)
            || (runName.compare("20180629_1619") == 0)
            || (runName.compare("20180629") == 0)) {

    // Image parameters
    QperPix = 0.0223;
    legStdCut = 3.0;
    NbinsSkip = 50; //28;

    // Measurement parameters
    timeZero = 0.3;
    hasRef = true;
    refStagePos = 154.0;
    imgMatType = "uint16";

    // Filtering
    suppressBins = 75;
    padMaxHeight = 2;

    // Bad scans
    /*
    for (int i=163; i<177; i++) {
      badScans.push_back(i);
    }
    badScans.push_back(163);
    badScans.push_back(176);
    badScans.push_back(197);
    */

    badScans.push_back(89);
    badScans.push_back(197);
    for (int i=163; i<177; i++) {
      badScans.push_back(i);
    }
    badImages[19].push_back(1542450);
    badImages[26].push_back(1542750);
    badImages[26].push_back(1550300);
    badImages[84].push_back(1542550);
    badImages[87].push_back(1543050);
    badImages[108].push_back(1542750);
    badImages[110].push_back(1543050);
    badImages[121].push_back(1543400);
    badImages[135].push_back(1544000);
    badImages[136].push_back(1542950);
    badImages[140].push_back(1542650);
    badImages[163].push_back(1542750);
    badImages[163].push_back(1544000);
    badImages[184].push_back(1542550);
    badImages[198].push_back(1544150);

    // Background
    backgroundImage = "backgroundImg-20180629_1619.dat";
    hasLaserBkg = true;
    laserClusterRemoval = false;

    int row, col;
    int rad = 57;
    int hRad = 48;
    nanMap.clear();
    nanMap.resize(1024);
    for (uint ir=0; ir<nanMap.size(); ir++) {
      nanMap[ir].resize(1024, 0);
    }
    for (int ir=520; ir<660; ir++) {
      for (int ic=443; ic<583; ic++) {
        row = ir - 570;
        col = ic - 535;
        if (rad > std::sqrt(row*row + col*col)) {
          nanMap[ir][ic] = NANVAL;
        }
        row = ir - 590;
        col = ic - 518;
        if (sqrt(row*row + col*col) < hRad) {
          nanMap[ir][ic] = NANVAL;
        }
      }
    }

    rad = 45;
    for (int ir=420; ir<660; ir++) {
      for (int ic=443; ic<583; ic++) {
        row = ir - 565;
        col = ic - 510;
        if (sqrt(row*row + col*col) < rad) {
          nanMap[ir][ic] = NANVAL;
        }
      }
    }

    for (int ir=540; ir<610; ir++) {
      for (int ic=560; ic<630; ic++) {
        row = ir - 575;
        col = ic - 575;
        if (sqrt(row*row + col*col) < rad) {
          nanMap[ir][ic] = NANVAL;
        }
      }
    }

    rad = 58;
    for (int ir=560; ir<680; ir++) {
      for (int ic=510; ic<630; ic++) {
        row = ir - 585;
        col = ic - 550;
        if (sqrt(row*row + col*col) < rad) {
          nanMap[ir][ic] = NANVAL;
        }
      }
    }


   

    // Remove hole
    holeR = 590;
    holeC = 513;
    holeRad = 50;

    /////  Center Finding Parameters  /////
    // Rough center finding
    sigma = 8;
    blockCentR = 568;
    blockCentC = 495;
    minRad = 70;
    maxRad = 350;
    meanInd = 350;
    COMstdScale = 0.075;

    cntrScale = 10;
    cntrMinScale = 1;
    cntrPowellTol = 1;
    cntrFracTol1d = 0.01;

    // Pressure measurements
    pvMap["pressure"]    = "pressureSampleChamber_06_29_2018_16_30_40-06_30_2018_16_04_40-16970.dat";
    pvMap["UVcounts"]    = "UVsampleChamberCam_06_29_2018_16_30_40-06_30_2018_16_04_40-16970.dat";
    pvMap["bunkerTemp"]  = "bunkerTemperature_06_29_2018_16_30_40-06_30_2018_16_04_40-16970.dat";
    pvMap["highBayTemp"] = "highBayTemperature_06_29_2018_16_30_40-06_30_2018_16_04_40-16970.dat";
  }
  else if ((runName.compare("20180627_1551") == 0)
            || (runName.compare("20180627_1116") == 0)
            || (runName.compare("20180627") == 0)) {

    // Image parameters
    QperPix = 0.0223;
    legStdCut = 3.0;
    NbinsSkip = 50; //25;

    // Filtering
    suppressBins = 75;
    padMaxHeight = 6.5;

    // Measurement parameters
    timeZero      = 0.125;
    hasRef        = true;
    refStagePos   = 154.0;
    imgMatType    = "uint16";
    NfinalPoints  = 4;

    // Bad scans
    /*
    badScans.push_back(9);
    badScans.push_back(38);
    badScans.push_back(91);
    badScans.push_back(107);
    badScans.push_back(108);
    badScans.push_back(121);
    */
    for (int i=100; i<=121; i++) {
      badScans.push_back(i);
    }
    /*
    badImages[7].push_back(1530100);
    badImages[20].push_back(1543950);
    badImages[24].push_back(1544250);
    badImages[26].push_back(1544550);
    badImages[32].push_back(1530100);
    badImages[46].push_back(1543650);
    badImages[48].push_back(1565700);
    badImages[63].push_back(1544100);
    badImages[65].push_back(1544100);
    badImages[70].push_back(1543450);
    badImages[71].push_back(1542750);
    badImages[72].push_back(1542750);
    badImages[86].push_back(1544400);
    badImages[96].push_back(1544250);
    badImages[102].push_back(1543350);
    badImages[115].push_back(1530100);
    */

    /*
    for (int i=10; i<=18; i++) {
      badImages[i].push_back(1530000);
      badImages[i].push_back(1530100);
    }
    for (int i=49; i<=56; i++) {
      badImages[i].push_back(1530000);
      badImages[i].push_back(1530100);
    }
    for (int i=76; i<=79; i++) {
      badImages[i].push_back(1530000);
      badImages[i].push_back(1530100);
    }
    for (int i=85; i<=100; i++) {
      badScans.push_back(i);
    }
    */

    /*
    badScans.push_back(9);
    badScans.push_back(38);
    badScans.push_back(91);
    badScans.push_back(108);
    badScans.push_back(121);
    */

    /*
    for (int i=32; i<=34; i++) {
      badScans.push_back(i);  // Pressure inscrease
    }
    for (int i=51; i<=52; i++) {
      badScans.push_back(i);  // Pressure inscrease
    }
    for (int i=63; i<=71; i++) {
      badScans.push_back(i);  // Pressure inscrease
    }
    for (int i=90; i<=96; i++) {
      badScans.push_back(i);  // Pressure inscrease
    }
    */

    // Original
    /*
    badScans.push_back(108);
    badScans.push_back(121);
    badScans.push_back(24);
    badScans.push_back(38);
    badScans.push_back(48);
    badScans.push_back(91);
    badScans.push_back(9);
    */

    // Background
    backgroundImage = "backgroundImg-20180627_1116.dat";
    hasLaserBkg = true;
    laserClusterRemoval = false;

    int row, col;
    int rad = 52;
    int hRad = 55;
    nanMap.clear();
    nanMap.resize(1024);
    for (uint ir=0; ir<nanMap.size(); ir++) {
      nanMap[ir].resize(1024, 0);
    }
    if (false) {
      for (int ir=520; ir<660; ir++) {
        for (int ic=443; ic<583; ic++) {
          row = ir - 570;
          col = ic - 535;
          if (rad > std::sqrt(row*row + col*col)) {
            nanMap[ir][ic] = NANVAL;
          }
          row = ir - 590;
          col = ic - 518;
          if (sqrt(row*row + col*col) < hRad) {
            nanMap[ir][ic] = NANVAL;
          }
        }
      }

      rad = 50;
      for (int ir=420; ir<660; ir++) {
        for (int ic=443; ic<583; ic++) {
          row = ir - 565;
          col = ic - 510;
          if (sqrt(row*row + col*col) < rad) {
            nanMap[ir][ic] = NANVAL;
          }
        }
      }

      rad = 46;
      for (int ir=530; ir<700; ir++) {
        for (int ic=560; ic<630; ic++) {
          row = ir - 575;
          col = ic - 575;
          if (sqrt(row*row + col*col) < rad) {
            nanMap[ir][ic] = NANVAL;
          }
        }
      }

      for (int ir=600; ir<630; ir++) {
        for (int ic=550; ic<630; ic++) {
          nanMap[ir][ic] = NANVAL;
        }
      }

      rad = 15;
      for (int ir=572; ir<612; ir++) {
        for (int ic=640; ic<670; ic++) {
          row = ir - 587;
          col = ic - 652;
          if (sqrt(row*row + col*col) < rad) {
            nanMap[ir][ic] = NANVAL;
          }
        }
      }
      rad = 20;
      for (int ir=560; ir<610; ir++) {
        for (int ic=342; ic<392; ic++) {
          row = ir - 582;
          col = ic - 367;
          if (sqrt(row*row + col*col) < rad) {
            nanMap[ir][ic] = NANVAL;
          }
        }
      }
      rad = 15;
      for (int ir=700; ir<747; ir++) {
        for (int ic=57; ic<98; ic++) {
          row = ir - 722;
          col = ic - 78;
          if (sqrt(row*row + col*col) < rad) {
            nanMap[ir][ic] = NANVAL;
          }
        }
      }
    }

 
    // Remove hole
    holeR = 590; //587; //590;
    holeC = 513; //512; //513;
    holeRad = 45; //43; //45;

    /////  Center Finding Parameters  /////
    // Rough center finding
    sigma = 8;
    blockCentR = 573;
    blockCentC = 500;
    minRad = 70;
    maxRad = 325;
    meanInd = 350;
    COMstdScale = 0.075;

    cntrScale = 10;
    cntrMinScale = 1;
    cntrPowellTol = 1;
    cntrFracTol1d = 0.01;

    // PV files / variables
    pvMap["pressure"]    = "pressureSampleChamber_06_27_2018_15_51_20-06_28_2018_13_27_15-15553.dat";
    pvMap["UVcounts"]    = "UVsampleChamberCam_06_27_2018_15_51_20-06_28_2018_13_27_15-15553.dat";
    pvMap["bunkerTemp"]  = "bunkerTemperature_06_27_2018_15_51_20-06_28_2018_13_27_15-15553.dat";
    pvMap["highBayTemp"] = "highBayTemperature_06_27_2018_15_51_20-06_28_2018_13_27_15-15553.dat";

    throttle = 103; //uJ or 53 degrees

    // Variables for studies
    bkgStudyRanges.resize(4);
    bkgStudyRanges[0].push_back(5.5);   bkgStudyRanges[0].push_back(6);
    bkgStudyRanges[1].push_back(6);     bkgStudyRanges[1].push_back(6.8);
    bkgStudyRanges[1].push_back(5.5);   bkgStudyRanges[1].push_back(6.8);
    bkgStudyRanges[2].push_back(2);     bkgStudyRanges[2].push_back(3);
    bkgStudyRanges[3].push_back(4);     bkgStudyRanges[3].push_back(5.5);

  }
  else if (runName.compare("simulateReference") == 0) {
    
    QperPix = 0.0223;
    NbinsSkip = 50; //28;
    switch (molecule) {
      case initialState: {
        xyzFiles.push_back("17050202_Nitrobenzene_opt_B3LYP_6-31G.xyz");
        break;
      }

      case finalState1: {
        xyzFiles.push_back("18062101_phenyloxy_opt_B3LYP_6-31G.xyz");
        xyzFiles.push_back("18062102_NO_opt_B3LYP_6-31G.xyz");
        break;
      }

      case finalState2: {
        xyzFiles.push_back("phenyl.xyz");
        xyzFiles.push_back("nitrogenDioxide.xyz");
        break;
      }

      default: {
        std::cerr << "ERROR: do not recognize molecule enum!!!\n";
        exit(0);
      }
    }
  }
  else if (runName.compare("doRunLists") == 0) {
  }
  else if (runName.compare("other") == 0) {
  }
  else {
    std::cerr << "ERROR: Cannot set values for run " + runName + "!!!\n";
    exit(0);
  }

  readoutAzmBinStart = readoutStart*NradAzmBins; //400
  readoutAzmBinEnd   = readoutEnd*NradAzmBins; //450
  readoutLegBinStart = readoutStart*NradLegBins;
  readoutLegBinEnd   = readoutEnd*NradLegBins;


  refStagePos *= scaleStagePos;
  maxQleg   = QperPix*NradLegBins;
  maxQazm   = QperPix*NradAzmBins;
  maxRbins  = rMaxAzmRat*((NradAzmBins + NautCpadding)/2 + 1);
  maxR      = maxRbins*(2*PI/(QperPix*(NradAzmBins + NautCpadding)));
  std::cout<<"testing: "<<rMaxAzmRat<<"  "<<(NradAzmBins + NautCpadding)/2 + 1<<"  "<<QperPix<<"  "<<std::endl;

  R1Bin = 1/(2*PI/(QperPix*(NradAzmBins + NautCpadding)));
  R8Bin = 8/(2*PI/(QperPix*(NradAzmBins + NautCpadding)));
  std::cout<<"Rbins: "<<R1Bin<<"   "<<R8Bin<<"  "<<NradAzmBins + NautCpadding<<std::endl;

  std::cout<<"maxR: "<<maxR<<std::endl;
}


