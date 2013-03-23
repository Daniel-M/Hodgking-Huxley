//#include "HH_Includes.hpp"


/* ===============================================================================
/ Defining some auxiliary "gating functions" for the Hodgking Huxley Model
/ These are taken from book "Nonlinear dynamics in physiology and medicine"
/ From Anne Beuter et al.
/ Chapter 4 - Excitable cells, pp 104
 ===============================================================================*/
// \file HH_GatingFunctions.hpp
/*! 
 *  \brief Gating functions for the model
 * 
 *  The Hodgking-Huxley model it's endowed with a set of auxiliary gating functions
 *  Those functions proposed on the original paper of the 1952 called
 *  _A quantitative description of membrane current and it's applications to conduction and excitation in nerve_
 *   published at J.physiol. (1952) 117, 500-544 it's free online
 * 
 * In other books like _Nonlinear dynamics in physiology and medicine_ from Anne Beuter et al.
 * or _Mathematical aspects of the Hodgking-Huxley Neural theory_ from Janne Cronin
 * are other formulations for the gating functions
 */

/*! \def alpha_n 
 * \brief The alpha gating function for the n gate
 * 
 */

double alpha_n(double V)
{
     return (0.01*(V+50.0))/(1.0-exp(-(V+50.0)/10.0));
}

/*! \def beta_n 
 * \brief The beta gating function for the n gate
 * 
 */
double beta_n(double V)
{
     return 0.125*exp(-(V+60.0)/80.0);
}

/*! \def alpha_m 
 * \brief The alpha gating function for the m gate
 * 
 */
double alpha_m(double V)
{
     return (0.1*(V+35.0))/(1-exp(-(V+35.0)/10.0));
}

/*! \def beta_m 
 * \brief The beta gating function for the m gate
 * 
 */
double beta_m(double V)
{
     return 4.0*exp(-(V+60.0)/18.0);
}

/*! \def alpha_h 
 * \brief The alpha gating function for the h gate
 * 
 */
double alpha_h(double V)
{
     return 0.07*exp(-(V+60.0)/20.0);
}

/*! \def beta_h 
 * \brief The beta gating function for the h gate
 * 
 */
double beta_h(double V)
{
     return 1.0/(1.0+exp(-(V+30.0)/10.0));
}


/* ===============================================================================
/ Defining some auxiliary "gating functions" for the Hodgking Huxley Model
/ These are taken from book "Mathematical aspects of the Hodgking-Huxley
/ Neural theory"
/ From Janne Cronin
/ Chapter 2.3 - The work of Hodgking-Huxley, pp 50-52
/ ===============================================================================*/

// double alpha_n(double V)
// {
// return (0.01*(V+10.0))/(exp((V+10.0)/10.0)-1.0);
// }
// 
// double beta_n(double V)
// {
// return 0.125*exp(V/80.0);
// }
// 
// 
// double alpha_m(double V)
// {
// return (0.1*(V+25.0))/(exp((V+25.0)/10.0)-1.0);
// }
// 
// double beta_m(double V)
// {
// return 4.0*exp(V/18.0);
// }
// 
// 
// double alpha_h(double V)
// {
// return 0.07*exp(V/20.0);
// }
// 
// double beta_h(double V)
// {
// return 1.0/(1.0+exp((V+30.0)/10.0));
// }


