/*
    FILE NAME: HH-model.cpp
  DESCRIPTION: This code uses GSL to calculate the solution to the Hodgking Huxley Model

		[!] The system must be normalized to get the feeling of the biophysical behavior
	   	[!] See the txt files to more info about the model
      
       AUTHOR: Daniel Mejia Raigosa
       E-MAIL: danielmejia55@gmail.com
       GITHUB: http://github.com/Daniel-M/Hodgking-Huxley
         DATE: 13 Sept 2012
      VERSION: 1.0
    
    LICENSE
    
    This file is part of "Hodgking-Huxley".

    "HH-model.cpp" is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    "HH-model.cpp" is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with "HH-model.cpp".  If not, see <http://www.gnu.org/licenses/>.
    
    
*/


// Program Headers
// #include <iostream>
// #include <string>
// #include <iomanip>
// #include<fstream>
// #include <cmath>
// 
// // C old headers
// // #include <stdio.h>
// // #include <stdlib.h>
// #include <unistd.h>
// 
// // GSL Headers
// #include<gsl/gsl_odeiv2.h>
// #include<gsl/gsl_errno.h>
// 
// 
// // MathGL Headers
// #include<mgl/mgl.h>
// #include <mgl/mgl_zb.h>
// #include <mgl/mgl_eps.h>
// #include <mgl/mgl_data.h>
// 
// #include "getInfoFromFile.hpp"
// #include "HH_GatingFunctions.hpp"
// #include "HH_Model_ODES.hpp"

#include "HH_Includes.hpp"


// ==========================================================================
// 			MAIN CODE
// ==========================================================================


int main(int argc, char **argv){

    int POINTS=250;
    char verbosity='n',gengraphs='g', automatic='y';
    
    std::string paramfile = "parameters.txt";
    std::string iniconfile = "init_cond.txt";
    std::string basefile = "results-HH-model";
    std::string ext = "txt";
    
    std::string out_datafile = basefile + "." + ext;
    
    
    std::ofstream hh_data(out_datafile.c_str());
    
    
//     out_datafile = basefile + "-Cm_current" + "." + ext;
//     std::ofstream CmCurrent_data(out_datafile.c_str());
           
    out_datafile = basefile + "-Na_current" + "." + ext;
    std::ofstream NaCurrent_data(out_datafile.c_str());
    
    out_datafile = basefile + "-K_current" + "." + ext;
    std::ofstream KCurrent_data(out_datafile.c_str());
    
    out_datafile = basefile + "-L_current" + "." + ext;
    std::ofstream LCurrent_data(out_datafile.c_str());
    
// ==========================================================================

    double y[4]; // Stores the solutions, y[0] will be Membrane mV y[1] will be m y[2] will be h and y[3] will be n
    double yerr[4]; // Stores the errors
    double h_step;  // This will be the h_step for integrate, will be redefined on line 333
    double parametros[8]; // Here one stores the ODES parameters for solvig, i.e membrane capacitance, conductances and so on
    
    double eps_abs = 1.e-8;	// absolute error requested 
    double eps_rel = 1.e-10;	// relative error requested 
    double t=0.0;       // Starting time, this variable is a "time buffer"
    double tf=25.0;	// 25 ms for time integration
 


// ==========================================================================
//   Console commands to run the programm
// ==========================================================================
    
      	int c;
	extern int optind;
	extern char *optarg;

	while ((c = getopt(argc, argv, "hvgAt:p:k:i:b:e:")) != -1)
	  switch (c)  {
	  case 'h':
	    std::cout << "\nUsage: \n" << argv[0] << " [options] \n" << std::endl;
//	    std::cout << "  [i]If no options are given, the -A flag is used by default\n" << std::endl;
	    std::cout <<"\t-h  : This help message"<< std::endl;
	    std::cout <<"\t-v  : Set verbosity level,(No verbosity by default)"<< std::endl;
	    std::cout <<"\t-g  : Don't generate PNG graphics,(Graphics by default)"<< std::endl;
            std::cout <<"\t-A  : Automatic parameters and initial conditions (using built-in defaults)"<< std::endl;
            std::cout <<"\t-t# : Integrate from zero to # (In milliseconds),(Default= " << tf << ")" << std::endl;
	    std::cout <<"\t-p# : Set number of points used (Default " << POINTS << ")" << std::endl;
	    std::cout <<"\t-i@ : Initial conditions file [-i filename.ext] (Default \"" << iniconfile << "\")" << std::endl;
	    std::cout <<"\t-k@ : Parameters file [-kfilename.ext] (Default \"" << paramfile << "\")" << std::endl;
	    std::cout <<"\t-b@ : Set basename for output files [-b basename] (Default \"" << basefile << "\")" << std::endl;
	    std::cout <<"\t-e@ : Set extension for basename output files [-e ext = basename.ext] (Default \"" << ext << "\")" << std::endl;

	    std::cout << "\nNOTE: If no options are given, the -A flag is used by default\n" << std::endl;

	    std::cout << std::endl;

	    exit(1);
	    break;

	  case 'v':  verbosity='v';
	    break;
	    
	  case 'g':  gengraphs='n';
	    break;
        
	  case 'A':  automatic='y'; // Automatic mode
        break;

	  case 't': tf=atof(optarg);
	    break;

	  case 'p': POINTS = atoi(optarg);
	    break;
	   
	  case 'i': iniconfile.assign(optarg);
		automatic='n'; //Disable automode 
	    break;
	    
	  case 'k': paramfile.assign(optarg);
		automatic='n'; //Disable automode 

	    break;
	    
	  case 'b': basefile.assign(optarg);
	    break;
	    
	  case 'e': ext.assign(optarg);
	    break;

	  case '?':
//          if (optopt == 'c')
// 	     {
//            std::cout <<  "Option " << optopt << "requires an argument." << std::endl;
// 	       exit(1);
// 	     }
//          else if (isprint (optopt))
// 	     {
//            std::cout <<  "Unknown option " << optarg << std::endl;
// 	       exit(1);
// 	     }
//          else
// 	     {
           std::cout << "Unknown option " << std::endl;
	       std::cout << "Aborting..." << std::endl;
// 	       exit(1);
// 	     }
             
         default:
            abort ();
	    
	  }
	  
	  
    
	if (automatic=='y')
    {
               
// ==========================================================================
// Initial conditions AUTOMATED
// ==========================================================================

    y[0]=-60;   // Initial transmembrane potential, assuming resting potential
    y[1]=0;     // Gating functions
    y[2]=0;  // Gating functions
    y[3]=0;  // Gating functions
    
    
// # Membrane capacitance in Farads
// Cm = 0.001; 
// 
// # Ion conductances in mMho
// gNa = 120;
// gK  = 36;
// gL  = 0.3;
// 
// # Ion equilibrium potentials in mVolts
// vNa = -115;
// vL  = 10.613;
// vK  = 12;
    
    parametros[0]=0.01;   // Membrane capacitance
    parametros[1]=0.1;    // induced current on axon, 0 means no external current
    parametros[2]=1.20;   // Na conductances
    parametros[3]=55.17;  // Na Nernst Potential
    parametros[4]=0.36;   // K Conductance
    parametros[5]=-72.14; // K Nernst Potential
    parametros[6]=0.003;  // Leakage conductance (Due to a Cl current)
    parametros[7]=-49.42; // Leakage Nernst potential (Due to a Cl current)
    
    
        
    }
    else
    {
// ==========================================================================
// Initial conditions FROM FILE
// ==========================================================================        
        
            getInfoFromFile(iniconfile,y);
            getInfoFromFile(paramfile,parametros);
    }
        
        

            std::cout << "Initial Conditions" << std::endl;
            
            std::cout << y[0] << std::endl;
            std::cout << y[1] << std::endl;
            std::cout << y[2] << std::endl;
            std::cout << y[3] << std::endl;
            
            std::cout << "Parameters" << std::endl;
            
            std::cout << parametros[0] << std::endl;
            std::cout << parametros[1] << std::endl;
            std::cout << parametros[2] << std::endl;
            std::cout << parametros[3] << std::endl;      
            std::cout << parametros[4] << std::endl;
            std::cout << parametros[5] << std::endl;
            std::cout << parametros[6] << std::endl;
            std::cout << parametros[7] << std::endl;
		    
		    

	    
// ==========================================================================  
// ==========================================================================
//  Now the iterative process of solution
// ==========================================================================
// ==========================================================================

  // define the type of routine for making steps: 
  
  const gsl_odeiv2_step_type *type_ptr = gsl_odeiv2_step_rk8pd;
  
  // some other possibilities (see GSL manual):          
  //   = gsl_odeiv2_step_rk2  - Runge Kutta (2,3) Method
  //   = gsl_odeiv2_step_rk4  - 4th Order Runge Kutta Method (The Classical)
  //   = gsl_odeiv2_step_rk45 - Runge-Kutta-Fehlberg (4,5) Method (General Purpose, GSL Recommended)
  //   = gsl_odeiv2_step_rkck - Runge- Kutta Cash-Karp (4,5) Method
  //   = gsl_odeiv2_step_rk8pd - Runge- Kutta Prince-Dormand (8,9) Method (defined here by default)
  //   = gsl_odeiv_step_rk4imp;
  //   = gsl_odeiv_step_bsimp;  
  //   = gsl_odeiv_step_gear1;
  //   = gsl_odeiv_step_gear2;

  // allocate/initialize the stepper, the control function, and the
  //  evolution function.
  
  gsl_odeiv2_step *step_ptr = gsl_odeiv2_step_alloc (type_ptr, 4);
  gsl_odeiv2_control *control_ptr = gsl_odeiv2_control_y_new (eps_abs, eps_rel);
  gsl_odeiv2_evolve *evolve_ptr = gsl_odeiv2_evolve_alloc (4);

  gsl_odeiv2_system HH_Model_odes;	// structure with the rhs function, etc. 
    
  HH_Model_odes.dimension=4;
  HH_Model_odes.function=&HH_Model;
  HH_Model_odes.jacobian=NULL;
  HH_Model_odes.params=&parametros;
  

  h_step=tf/POINTS;
  

  
     /* The function "gsl_odeiv2_step_apply(step_ptr,t,h_step,y,yerr,NULL,NULL,&HH_Model_odes)"
       applies the stepping function step_ptr to the system of equations deﬁned by HH_Model_odes,
       using the step-size h_step to advance the system from time t and state y to time t+h_step.
       The new state of the system is stored in y on output, with an estimate of the absolute 
       error in each component stored in yerr. If the argument dydt_in is not null it should
       point an array containing the derivatives for the system at time t on input. This is
       optional as the derivatives will be computed internally if they are not provided, but
       allows the reuse of existing derivative information. On output the new derivatives of
       the system at time t+h_step will be stored in dydt_out if it is not null.
       
       * Note that both dy/dt_in and dy/dt_out are defined as null below */ 
     


    // Print results on file
    

    
    int status=gsl_odeiv2_step_apply(step_ptr,t,h_step,y,yerr,NULL,NULL,&HH_Model_odes);
    t=t+h_step;
    
   // print results on screen and a file
   if(verbosity=='v')
   {
       while(t<tf && status==GSL_SUCCESS)
       {     

            int status=gsl_odeiv2_step_apply(step_ptr,t,h_step,y,yerr,NULL,NULL,&HH_Model_odes);
	    
            std::cout << t << "\t" << y[0] << "\t" << y[1] << "\t" << y[2] << "\t" << y[3] << std::endl;
	    
            hh_data << t << "\t" << y[0] << "\t" << y[1] << "\t" << y[2] << "\t" << y[3] << std::endl;
            // 	    Individual currents
            NaCurrent_data << t << "\t" << parametros[2]*pow(y[1],3)*y[2]*(y[0]-parametros[3]) << std::endl;
            KCurrent_data  << t << "\t" <<  parametros[4]*pow(y[3],4)*(y[0]-parametros[5]) << std::endl;
            LCurrent_data  << t << "\t" <<  parametros[6]*(y[0]-parametros[7]) << std::endl;
	    
//             t=t+h_step;
    
       }
    
   }
   else // print results to a file only
   {
       while(t<tf && status==GSL_SUCCESS)
       {     
     

            int status=gsl_odeiv2_step_apply(step_ptr,t,h_step,y,yerr,NULL,NULL,&HH_Model_odes);

            hh_data << t << "\t" << y[0] << "\t" << y[1] << "\t" << y[2] << "\t" << y[3] << std::endl;
	    
// 	        Individual currents
// 	        Cm_Current_data << t << "\t" <<  << std::endl;
            NaCurrent_data << t << "\t" << parametros[2]*pow(y[1],3)*y[2]*(y[0]-parametros[3]) << std::endl;
            KCurrent_data << t << "\t" <<  parametros[4]*pow(y[3],4)*(y[0]-parametros[5]) << std::endl;
            LCurrent_data << t << "\t" <<  parametros[6]*(y[0]-parametros[7]) << std::endl;

            t=t+h_step;

       }  
   }
   
   if(gengraphs!='n')
    {
        mglGeneratePNG(parametros, POINTS, basefile,ext);
        mglGeneratePNG(parametros, POINTS, basefile + "-Na_current",ext);
        mglGeneratePNG(parametros, POINTS, basefile + "-K_current",ext);
        mglGeneratePNG(parametros, POINTS, basefile + "-L_current",ext);
    }  

exit(0);
} //End of Main Code
