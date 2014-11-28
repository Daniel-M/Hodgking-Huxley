// MathGL Headers
#ifndef MATHGL_H
    #include<mgl2/mgl.h>
    #define MATHGL_H
#endif

#include <string>
/* ==========================================================================   
/ ==========================================================================
/ ==========================================================================
/   MathGL Graphics generation (on a PNG file)
/ ========================================================================== 
/ ==========================================================================
/ ==========================================================================*/
//\file mglGraphicsZB.hpp
/*! 
 * \brief MathGL implementation to generate PNG graphics
 * 
 * \param parametros stores numerical values of the used parameters on the HH-model
 * \param POINT is the number of points used to generate the plots. Used only to put information on the key
 * \param sFile stores the sFile to name the PNG output
 * 
 * MathGL implementation to crete PNG file of the HH Action Potential on the given time 
 * 
 */

int mglDrawFunction(std::vector<double> parametros, int POINTS, std::string sFile)
{


    char parametroCm[20];
    char parametroI[20];    
    char parametrogNa[20];
    char parametrovNa[20];
    char parametrogK[20];
    char parametrovK[20];
    char parametrogL[20];
    char parametrovL[20];

    char parametroP[30];

    sprintf(parametroCm,"\\C_{m} = %.3lf \\mF",parametros[0]);
    sprintf(parametroI,"\\I_{injected} = %.3lf \\mA",parametros[1]);
    sprintf(parametrogNa,"\\g_{Na} = %.3lf \\dMho",parametros[2]);
    sprintf(parametrovNa,"\\E_{Na} = %.3lf \\mV",parametros[3]);
    sprintf(parametrogK,"\\g_{K} = %.3lf \\dMho",parametros[4]);
    sprintf(parametrovK,"\\E_{K} = %.3lf \\mV",parametros[5]);
    sprintf(parametrogL,"\\g_{L} = %.3lf \\dMho",parametros[6]);
    sprintf(parametrovL,"\\E_{L} = %.3lf \\mV",parametros[7]);
    sprintf(parametroP,"Points = %i",POINTS);
 

	mglGraph plot;
	mglData points(sFile.c_str());
	
	plot.SetSize(1200,900);          ///gr->SetSize(1200,900) Set image size in pixels
    plot.SetMarkSize(0.0005);    /// gr->SetMarkSize(0.0005) Set size of the marker, i.e. the dot size on plot
	
	plot.SetRanges(points.SubData(0),points.SubData(1));

	plot.Alpha(true); plot.Light(true); //plot.Transparent(false);
	
	plot.Title("Hodgking and Huxley's\nAction Potential","iC",8);
    
	plot.SetFontSize(4);  /// gr->SetFontSize(4) Sets the global font size for the plot ticks and related
	
	plot.SetRotatedText(true);
	plot.Label('x',"Time(ms)",0,0);
	plot.Label('y',"Voltage (mV)",0,0);
	plot.SetRotatedText(false);
	//plot.AdjustTicks("xy");      /// gr->AdjustTicks("xy") The numbers on ticks will be rotated along the x axis.
	plot.Axis();

	plot.SetFontSize(4);  /// gr->SetFontSize(4) Sets the global font size for the plot ticks and related
    plot.SetFontDef("iC"); /// gr->SetFontDef("iC") Sets the font i-italic and Centered
    plot.SetRotatedText(true);  /// gr->SetRotatedText(true) Allow text rotating, for instance, the y-axis label will bi rotated
    plot.AddLegend("HH Model Parameters","");
	plot.AddLegend(parametroI," ");
    plot.AddLegend(parametroCm," "); 
    plot.AddLegend(parametrovL," ");
    plot.AddLegend(parametrogL," ");
    plot.AddLegend(parametrovK," ");
    plot.AddLegend(parametrogK," ");
    plot.AddLegend(parametrovNa," ");
    plot.AddLegend(parametrogNa," ");
	plot.AddLegend(parametroP," "); ///  gr->AddLegend(parametroP," ") Adding legend tags, the order of appareance is inverse, so the last line on the legend will be given by parametroP
          
    plot.Legend(/*1,1,"iL",2.7*/); ///gr->Legend() put the legend in 0,0, with font size 2.3
	
	plot.Box();
  
	std::string out_datafile(sFile + "_mgl.png");
	
	plot.Plot(points.SubData(0),points.SubData(1),"r-");
    
	plot.WritePNG(out_datafile.c_str(),"",false); ///gr->WritePNG(out_datafile.c_str(),"",false) put the plot on a PNG file
    
	//delete &plot;  /// delete gr Destroy the plot on memory

}

