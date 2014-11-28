/*
    FILE NAME: HH_Model_class.hpp
  DESCRIPTION: Part of Hodgking-Huxley model, used in HH-model.cpp

       AUTHOR: Daniel Mejia Raigosa
       E-MAIL: danielmejia55@gmail.com
       GITHUB: http://github.com/Daniel-M/Hodgking-Huxley
         DATE: 17 November 2014
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

/* ==========================================================================
/     Defining the ODE system for the Hodgking Huxley Model
/ ==========================================================================*/
//\file HH_Model_ODES.hpp 

#include "HH_Includes.hpp"

using namespace boost::numeric::odeint;

/*! \brief Structure that estores each set of points during the integration step.
 *
 * This structre stores the time value and the variable set in one file, this is
 * the libboost odeint observer so the vectors x and t contain each time step value for time,
 * voltaje, and gating probabilities h, m, and n.
 *
 * */ 

struct push_back_state_and_time
{
    std::vector< std::vector<double> >& m_states;
    std::vector< double >& m_times;

    push_back_state_and_time( std::vector< std::vector<double> > &states , std::vector< double > &times )
	: m_states( states ) , m_times( times ) { }

    void operator()( const std::vector<double> &x , double t )
    {
    	m_states.push_back( x );
    	m_times.push_back( t );
    }
};

/*! \brief The ODE Solver for the HH Model
 *
 * This function performs the numerical solition of the hh_model object taking the values stored on y 
 * and placing them on the file out_datafile
 * \param POINTS Number of points desired to make the numerical integral.
 * \param tf	Final time (in ms) of the integration.
 * \param hhmodel	hh_model object that contains the ODES and gating functions.
 * \param y			a vector that stores the solution (and initial conditions)
 * \param out_datafile	The filename where the solution is going to be placed

void hhSolver(int POINTS, double tf, hh_model hhmodel,std::vector<double> y,std::string out_datafile)
{
	std::vector<std::vector<double>> y_vec;
	std::vector<double> times;

	std::ofstream hh_action_potential(out_datafile.c_str());
	std::ofstream hh_data((out_datafile+"-all").c_str());

	//hh_model hhmodel(parametros);

	double h_step=tf/POINTS;

	size_t steps = integrate(hhmodel,y,0.0,tf,h_step,push_back_state_and_time( y_vec , times ));
  
	/* output */
	for( size_t i=0; i<=steps; i++ )
	{
		//std::cout << times[i] << '\t' << y_vec[i][0] << std::endl; 
		hh_action_potential << times[i] << '\t' << y_vec[i][0]  << std::endl;
		
		hh_data << times[i] << "\t";
		
		for(int j=0;j<4;j++)
		{
			hh_data	<< y_vec[i][j] << "\t";
		}
	
		hh_data << std::endl;
	}
}
