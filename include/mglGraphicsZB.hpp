// MathGL Headers
#ifndef MATHGL_H
    #include<mgl/mgl.h>
    #include <mgl/mgl_zb.h>
    #include <mgl/mgl_eps.h>
    #include <mgl/mgl_data.h>
#include <string>
    #define MATHGL_H
#endif

// ==========================================================================   
// ==========================================================================
// ==========================================================================
//   MathGL Graphics generation (on a PNG file)
// ========================================================================== 
// ==========================================================================
// ==========================================================================

void mglGeneratePNG(void *k, int POINTS,std::string sYAxis, std::string basefile,std::string ext)
{
        double *parametros=(double*)k;
        
        std::string out_datafile = basefile + "." + ext;

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
 
 
 mglGraph *gr = new mglGraphZB;


    mglData y_mgl(out_datafile.c_str());    // Load data from created file
    mglData xdat=y_mgl.SubData(0), ydat=y_mgl.SubData(1);   // Split data into x and y point coordinates
    
    gr->SetSize(1200,900);          //Set image size in pixels
//  gr->SetSize(620,480);
    gr->Transparent=false;          // Set transparency off
    gr->XRange(xdat);   gr->YRange(ydat); // for v.1.*
      //gr->SetRanges(xdat,ydat); // for v.2.*

    
    gr->Alpha(false);       // Set alpha off
    gr->Light(true);        // Set light on
    gr->SetMarkSize(0.0005);    // Set size of the marker, i.e. the dot size on plot
    
//  Set the title for the graph;
//  The font parameters are described by string.
//  This string may contain several characters of font type (‘rbiwou’) 
//  and/or align (‘LRC’) specification. Also it may contain the text color 
//  ‘wkrgbcymhRGBCYMHW’ (see section Line styles) after symbol ‘:’. 
//  The font types are: ‘r’ – roman font, ‘i’ – italic style, 
//  ‘b’ – bold style, ‘w’ – wired style, ‘o’ – over-lined text, 
//  ‘u’ – underlined text. By default roman font is used. 
//  The align types are: ‘L’ – align left (default), ‘C’ – align center, ‘R’ – align right.
//  For example, string ‘iC:b’ correspond to italic font style for centered text 
//  which printed by blue color. 
    
    gr->Title("Hodgking-Huxley's action potential","iC",8); 

//  gr->SubPlot(1,1,0,"^"); // Reserve aditional space only on the upper side  Default value is "<>_^" 
    
    gr->SetFontSize(4); // Sets the global font size for the plot ticks and related
    gr->SetFontDef("iC"); // Sets the font i-italic and Centered
    gr->SetRotatedText(true);  // Allow text rotating, for instance, the y-axis label will bi rotated
    
//  Addig legend tags, the order of appareance is inverse, so the last line on the legend will be given by parametroP
    gr->AddLegend(parametroP," ");
    gr->AddLegend(parametrovL," ");
    gr->AddLegend(parametrogL," ");
    gr->AddLegend(parametrovK," ");
    gr->AddLegend(parametrogK," ");
    gr->AddLegend(parametrovNa," ");
    gr->AddLegend(parametrogNa," ");
    gr->AddLegend(parametroI," ");
    gr->AddLegend(parametroCm," "); 
    
            
    gr->AddLegend("HH Model Parameters","");
    
    gr->Legend(/*1,1,"iL",2.7*/); //put the legend in 0,0, wiht font size 2.3
    
//  gr->SubPlot(1,1,0,"^"); // Reserve aditional space only on the upper side  Default value is "<>_^" 
    
    

//  Sets values of Min.x and Max.x as minimal and maximal values of data a.
//  Parameter add specify to add or not the new range to current one. 
//  Parameter fact add additional range increase on value (Max-Min)*fact.
//  See also Axis(). 

    gr->XRange(xdat,false,0);   // Set the data ranges
    gr->YRange(ydat,false,0.1);
    
//  Setup axes labels and ticks the syntax is Label (char dir, const char *text, float pos=0, float size=-1.4, float shift=0)
//  Prints the label text for axis dir=‘x’,‘y’,‘z’,‘t’ (here ‘t’ is “ternary” axis t=1-x-y). The position of label is determined
//  by pos parameter. If pos=0 then label is printed at the center of axis. If pos>0 then label is printed at the maximum of axis.
//  If pos<0 then label is printed at the minimum of axis. Parameter size determines the font size for the label. By default the 
//  font size is 1.4 times larger than the one for ticks FontSize (see section Font settings). See section Text printing. 
    
    gr->Label('x',"Time(ms)",0,5);
    gr->Label('y',sYAxis.c_str(),0,5.5);  // This will be rotated along the y-axis, see line 450
    
    gr->SetRotatedText(false); // Now the text will not rotate, for tick number on y-axis
    
    gr->AdjustTicks("xy");      // The numbers on ticks will be rotated along the x axis.
    gr->Axis();         
        
    
    gr->Box(); // The bounding box. Note that putting this on a line before SubPlot will give an unbounded graph (box undersized)
    
    gr->Plot(xdat,ydat,"r-"); // Make the plot, the r- are the options, r-red, and - for solid line
    
//  gr->Plot(xdat,ydat,"r#o "); // Make the plot, the r#o are the options, red, and #o for "special" dots see documentation
    
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    out_datafile = basefile + "_mgl.png";
    gr->WritePNG(out_datafile.c_str(),"",false); // put the plot on a PNG file
    delete gr;  // Destroy the plot on memory

}

