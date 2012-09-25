/*
    FILE NAME: HH_GatingFunctions.hpp
  DESCRIPTION: Part of Hodgking-Huxley model, used in HH-model.cpp

       AUTHOR: Daniel Mejia Raigosa
       E-MAIL: danielmejia55@gmail.com
       GITHUB: http://github.com/Daniel-M/Hodgking-Huxley
         DATE: 13 Sept 2012
      VERSION: 1.0
    
    LICENSE
    
    This file is part of "Hodgking-Huxley".

    "HH_GatingFunctions.hpp" is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    "HH_GatingFunctions.hpp" is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with "HH_GatingFunctions.hpp".  If not, see <http://www.gnu.org/licenses/>.
    
    
*/


// ===============================================================================
//  Defining some auxiliary "gating functions" for the Hodgking Huxley Model
//  These are taken from book "Nonlinear dynamics in physiology and medicine"
//  From Anne Beuter et al.
//  Chapter 4 - Excitable cells, pp 104
// ===============================================================================

double alpha_n(double V)
{
     return (0.01*(V+50.0))/(1.0-exp(-(V+50.0)/10.0));
}

double beta_n(double V)
{
     return 0.125*exp(-(V+60.0)/80.0);
}


double alpha_m(double V)
{
     return (0.1*(V+35.0))/(1-exp(-(V+35.0)/10.0));
}

double beta_m(double V)
{
     return 4.0*exp(-(V+60.0)/18.0);
}


double alpha_h(double V)
{
     return 0.07*exp(-(V+60.0)/20.0);
}

double beta_h(double V)
{
     return 1.0/(1.0+exp(-(V+30.0)/10.0));
}


// ===============================================================================
//  Defining some auxiliary "gating functions" for the Hodgking Huxley Model
//  These are taken from book "Mathematical aspects of the Hodgking-Huxley
//  Neural theory"
//  From Janne Cronin
//  Chapter 2.3 - The work of Hodgking-Huxley, pp 50-52
// ===============================================================================
/*
double alpha_n(double V)
{
     return (0.01*(V+10.0))/(exp((V+10.0)/10.0)-1.0);
}

double beta_n(double V)
{
     return 0.125*exp(V/80.0);
}


double alpha_m(double V)
{
     return (0.1*(V+25.0))/(exp((V+25.0)/10.0)-1.0);
}

double beta_m(double V)
{
     return 4.0*exp(V/18.0);
}


double alpha_h(double V)
{
     return 0.07*exp(V/20.0);
}

double beta_h(double V)
{
     return 1.0/(1.0+exp((V+30.0)/10.0));
}*/