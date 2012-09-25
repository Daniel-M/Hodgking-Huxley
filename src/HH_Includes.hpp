/*
    FILE NAME: HH_Includes.hpp
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

    "HH_Includes.hpp" is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    "HH_Includes.hpp" is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with "HH_Includes.hpp".  If not, see <http://www.gnu.org/licenses/>.
    
    
*/

// Program Headers

#ifndef IOSTREAM_H
    #include <iostream>
    #define IOSTREAM_H
#endif 

#ifndef  SSTRING_H
  #include <string>
  #define SSTRING_H
#endif

#ifndef IONMANIP_H
    #include <iomanip>
    #define IONMANIP_H
#endif

#ifndef FSTREAM_H
    #include<fstream>
    #define FSTREAM_H
#endif

#ifndef  SCMATH_H
  #include <cmath>
  #define SCMATH_H
#endif

// C old headers
// #include <stdio.h>
// #include <stdlib.h>
#ifndef UNISTD_H
    #include <unistd.h>
    #define UNISTD_H
#endif

// GSL Headers

#ifndef GSL_INCLUDES_H
    #include<gsl/gsl_odeiv2.h>
    #include<gsl/gsl_errno.h>
    #define GSL_INCLUDES_H
#endif


// MathGL Headers
#ifndef MATHGL_H
    #include<mgl/mgl.h>
    #include <mgl/mgl_zb.h>
    #include <mgl/mgl_eps.h>
    #include <mgl/mgl_data.h>
    #define MATHGL_H
#endif

#ifndef CUSTOM_INCLUDES_H
    #include "getInfoFromFile.hpp"
    #include "HH_GatingFunctions.hpp"
    #include "HH_Model_ODES.hpp"
    #define CUSTOM_INCLUDES_H
#endif