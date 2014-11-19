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
/*!
 * \brief Defines the ODE system proposed by Hodgking and Huxley as a class
 */
  
/*!
 * \param t Time instant
 * \param y[] This array stores the solution of the previous iterarion
 * \param f[] This array stores the result of the actual iteration (the derivatives)
 * \param *params The array that stores the ODE constants, that is, the model parameters
 * 
 * \return Must always return GSL_SUCCESS 
 * 
 */

class hh_model
{
	private:
	
		std::vector<double> parameters;

	public:

		hh_model( std::vector<double> params ) : parameters(params) { }

		void operator()( const std::vector<double> &y , std::vector<double> &f , const double /* t */ )
		{
			f[0]=(1/parameters[0])*(parameters[1]-parameters[2]*pow(y[1],3)*y[2]*(y[0]-parameters[3])-parameters[4]*pow(y[3],4)*(y[0]-parameters[5])-parameters[6]*(y[0]-parameters[7]));
		    f[1]=alpha_m(y[0])*(1-y[1])-beta_m(y[0])*y[1];
		    f[2]=alpha_h(y[0])*(1-y[2])-beta_h(y[0])*y[2];
		    f[3]=alpha_n(y[0])*(1-y[3])-beta_n(y[0])*y[3];
		}
};


//[ integrate_observer

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
//]
