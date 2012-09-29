/*
    FILE NAME: HH_Model_ODES.hpp
  DESCRIPTION: Part of Hodgking-Huxley model, used in HH-model.cpp

       AUTHOR: Daniel Mejia Raigosa
       E-MAIL: danielmejia55@gmail.com
       GITHUB: http://github.com/Daniel-M/Hodgking-Huxley
         DATE: 13 Sept 2012
      VERSION: 1.0
    
    LICENSE
    
    This file is part of "Hodgking-Huxley".

    "HH_Model_ODES.hpp" is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    "HH_Model_ODES.hpp" is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with "HH_Model_ODES.hpp".  If not, see <http://www.gnu.org/licenses/>.
    
    
*/

// ==========================================================================
//     Defining the ODE system for the Hodgking Huxley Model
// ==========================================================================


int HH_Model (double t, const double y[], double f[], void *params){
  
 
   double *k=(double*)params;
 
  
    f[0]=(1/k[0])*(k[1]-k[2]*pow(y[1],3)*y[2]*(y[0]-k[3])-k[4]*pow(y[3],4)*(y[0]-k[5])-k[6]*(y[0]-k[7]));
    f[1]=alpha_m(y[0])*(1-y[1])-beta_m(y[0])*y[1];
    f[2]=alpha_h(y[0])*(1-y[2])-beta_h(y[0])*y[2];
    f[3]=alpha_n(y[0])*(1-y[3])-beta_n(y[0])*y[3];

  return GSL_SUCCESS;
  
  /* ALWAYS Must Return GSL_SUCCESS ! */
}

