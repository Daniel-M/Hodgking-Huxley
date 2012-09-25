/*
    FILE NAME: getInfoFromFile.hpp
  DESCRIPTION: Part of Hodgking-Huxley model, used in HH-model.cpp

       AUTHOR: Daniel Mejia Raigosa
       E-MAIL: danielmejia55@gmail.com
       GITHUB: http://github.com/Daniel-M/Hodgking-Huxley
         DATE: 13 Sept 2012
      VERSION: 1.0
    
    LICENSE
    
    This file is part of "Hodgking-Huxley".

    "getInfoFromFile.hpp" is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    "getInfoFromFile.hpp" is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with "getInfoFromFile.hpp".  If not, see <http://www.gnu.org/licenses/>.
    
    
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

      if(sBuffer[0]!='#')
      {
        buffer[i]=atof(sBuffer);
        i++;
      }
      
    }

       data.close();
}