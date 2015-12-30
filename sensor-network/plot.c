/******************************/
/*************BONUS************/
/******************************/

// Base code taken from http://www.physics.csbsju.edu/~jcrumley/222/examples/plplot_example.C

// Credits:
// example of a simple program using the PLPlot library to plot results.
//  by Jim Crumley  20090120
//  updated 20110125 for latest version of PLPlot
//  updates 20120122 for latest version of PLPlot
//  updated 20130123 for compile line for newest version of Fedora

//Comments from owner:
// old line - ignore: g++ plplot_example.C -o plplot_example `pkg-config --cflags --libs plplotd-c++`
// compile with:
//   g++ plplot_example.C -o plplot_example -I/usr/include/plplot  -lplplotcxxd  -lplplotd
//using namespace std;

// Includes for plplot
#include <plstream.h>                                                                  //bonus was implemented using PLplot 
#include <iostream>
#include <stdio.h>
#include <string.h>

int main (int argc, char ** argv) {
    char input[20] = {}, output[20] = {}, data[1024] = {}, graphname[20] = {};
    char c;
    int i = 0, j = 0;

    PLFLT xmin = 0, ymin = 0, xmax = 0, ymax = 0;                                       //initialize elements of graph
    PLFLT x[200] = {0}, y[200] = {0};


    if (argc != 2) {                                                                    //handling of invalid program arguments
        puts("Invalid arguments.");
        puts("Usage: ./plot sensornum");
        return 0;
    }

    sprintf(input, "sensor-0%s.log", *(argv + 1));
    sprintf(output, "sensor-0%s.svg", *(argv + 1));
    sprintf(graphname, "Data from Sensor %s", *(argv + 1));

    FILE *fp = fopen(input, "r");                                                       //read from appropriate log file

    if (!fp) {
        perror(NULL);
        exit(-1);
    }

    //puts(input);

    c = fgetc(fp);
    while (c != EOF) {
        fseek(fp, -1, SEEK_CUR);
        fgets(data, 10, fp);
        data[strlen(data) - 1] = 0;
        //puts(data);

        x[i] = (float) i;                                                               //x-values will always be index (each element represents one second)
        y[i] = atof(data);

        xmax = x[i] + 1;                                                                //max x-value
                                                                                        //min x-value is always 0

        if (!i) {                                                                       //initialize ymin and ymax for first iteration
            ymin = y[i] - 1;
            ymax = ymin + 1;
        } else {
            if (y[i] < (ymin + 1)) {                                                    //set of conditional statements which set ymin and ymax appropriately
                ymin = y[i] - 1;
            } else if (y[i] > (ymax - 1)) {
                ymax = y[i] + 1;
            }
        }

        i++;

        c = fgetc(fp);
    }


    PLINT just = 0, axis = 0;
    plstream *pls;

    pls = new plstream();                                                                   //declare plplot object

    plsdev("svg");                                                                          //set output to be svg file
    plsfnam(output);                                                                        //set name of the output file


    pls->init();                                                                            //start plplot object
    pls->env(xmin, xmax, ymin, ymax, just, axis );
    
    //Comments from owner:
    //Setup window size
    // - just=0 sets axis so they scale indepedently
    // - axis=0 draw axis box, ticks, and numeric labels
    //   see "man plenv" for details


    pls->lab( "Time (seconds)", "Temperature (°C)", graphname);                             //set x-axis label, y-axis label, and graph name 

    plcol0(3);                                                                              //set front color to green

    //Comments from owner:
    // Plot the data points - (num_points, x, y, plot_symbol)
    //  - plot_symbol=9 sets a circle with a dot in the
    // middle for the plot symbol - see "man plpoin"

    pls->poin( i + 1, x, y, 32);                                                            //plot points

    for (j = 0; j < i; j++) {                                                               //join points
        if (j) {
            pljoin(x[j - 1], y[j - 1], x[j], y[j]);
        } else {
            pljoin(x[j], y[j], x[j + 1], y[j + 1]);
        }
    }

    delete pls;                                                                             //close plot

    return 0;
}
