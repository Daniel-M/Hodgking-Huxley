/*
	FILE NAME: HH-model.cpp
	DESCRIPTION: This code uses GSL to calculate the solution to the Hodgking Huxley Model

	[!] The system must be normalized to get the feeling of the biophysical behavior
	[!] See the txt files to more info about the model
	AUTHOR: Daniel Mejia Raigosa
	E-MAIL: danielmejia55@gmail.com
	GITHUB: http://github.com/Daniel-M/
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
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with "HH-model.cpp". If not, see <http://www.gnu.org/licenses/>.
*/
//\file getInfoFromFile.hpp
/*! 
 *  \brief Reads datafile and stores the data into _double_ array
 */

/*! \param filename The name of the file to be readed
 *  \param buffer[] The target array where the data will be stored
 * 
 */

void getInfoFromFile(std::string filename, double buffer[])
{
    std::ifstream data;
    char sBuffer[20];
    int i=0;
    

    data.open (filename.c_str(), std::ifstream::in);
  
    while(data.eof()!=true)
    {
data.getline(sBuffer,20);
buffer[i]=atof(sBuffer);
i++;
    }
   
       data.close();
}

