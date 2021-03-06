#ifndef ANALYZERPARAMETERS
#define ANALYZERPARAMETERS

#include <QVector>
#include <qcustomplot.h>

//#define SETTINGS_PATH "AntScope2.ini"


#pragma warning (disable : 4068 )

//#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-variable"
//#pragma GCC diagnostic ignored "-Wtype-limits"
//#pragma GCC diagnostic pop

static int MAX_SWR = 11;

static int ABSOLUTE_MIN_FQ = 0;
static int ABSOLUTE_MAX_FQ = 1400000;

enum {
    AANONE = 0,
    AA30ZERO,
    AA30,
    AA35ZOOM,
    AA54,
    AA55ZOOM,
    AA170,
    AA200,
    AA230,
    AA230PRO,
    AA230ZOOM,
    AA500,
    AA520,
    AA600,
    AA700ZOOM,
    AA1000,
    AA1400,
    SARK110,    //@SARK110
    QUANTITY
};
static QString names[QUANTITY]={
    "NONE",
    "AA-30",
    "AA-30 ZERO",
    "AA-35 ZOOM",
    "AA-54",
    "AA-55 ZOOM",
    "AA-170",
    "AA-200",
    "AA-230",
    "AA-230PRO",
    "AA-230 ZOOM",
    "AA-500",
    "AA-520",
    "AA-600",
    "AA-700 ZOOM",
    "AA-1000",
    "AA-1400",
    "SARK-110"  //@SARK110
};
static QString minFq[QUANTITY]={//in kHz
    "NONE",
    "100",  //AA-30
    "60",  //AA-30 ZERO
    "60",   //AA-35ZOOM
    "100",  //AA-54
    "60",   //AA-55ZOOM
    "100",  //AA-170
    "100",  //AA-200
    "100",  //AA-230
    "100",  //AA-230PRO
    "100",  //AA-230ZOOM
    "100",  //AA-500
    "100",  //AA-520
    "100",  //AA-600
    "100",  //AA-700ZOOM
    "100",  //AA-1000
    "100",  //AA-1400
    "100"   //@SARK110
};
static QString maxFq[QUANTITY]={//in kHz
    "NONE",
    "30000",    //AA-30
    "30000",    //AA-30 ZERO
    "35000",    //AA-35ZOOM
    "54000",    //AA-54
    "55000",    //AA-55ZOOM
    "170000",   //AA-170
    "200000",   //AA-200
    "230000",   //AA-230
    "230000",   //AA-230PRO
    "230000",   //AA-230ZOOM
    "500000",   //AA-500
    "520000",   //AA-520
    "600000",   //AA-600
    "700000",   //AA-700ZOOM
    "1000000",  //AA-1000
    "1400000",   //AA-1400
    "230000",   //@SARK110
};

static int lcdHeight[QUANTITY]={//in kHz
    0,
    64,    //AA-30
    0,  //AA-30 ZERO
    240,    //AA-35ZOOM
    64,    //AA-54
    240,    //AA-55ZOOM
    64,   //AA-170
    0,   //AA-200
    0,   //AA-230
    0,   //AA-230PRO
    220,   //AA-230ZOOM
    0,   //AA-500
    0,   //AA-520
    240,   //AA-600
    0,   //AA-700ZOOM
    240,  //AA-1000
    240,   //AA-1400
    240     //@SARK110
};

static int lcdWidth[QUANTITY]={//in kHz
    0,
    133,    //AA-30
    0,  //AA-30 ZERO
    320,    //AA-35ZOOM
    133,    //AA-54
    320,    //AA-55ZOOM
    133,   //AA-170
    0,   //AA-200
    0,   //AA-230
    0,   //AA-230PRO
    290,   //AA-230ZOOM
    0,   //AA-500
    0,   //AA-520
    320,   //AA-600
    0,   //AA-700ZOOM
    320,  //AA-1000
    320,   //AA-1400
    400    //@SARK110
};

enum parse{
    VER = 1,
    WAIT_DATA,
    WAIT_ANALYZER_DATA,
    WAIT_SCREENSHOT_DATA,
    WAIT_ANALYZER_UPDATE
};

struct rawData{
    double fq;
    double r;
    double x;
    void read (const QJsonObject &json)
    {
        fq = json["fq"].toDouble();
        r = json["r"].toDouble();
        x = json["x"].toDouble();
    }
    void write (QJsonObject &json) const
    {
        json["fq"] = fq;
        json["r"] = r;
        json["x"] = x;
    }
};

struct measurement{

    QVector <rawData> dataRX;
//---------------------------------
    QCPDataMap swrGraph;
    QCPDataMap phaseGraph;
    QCPDataMap rhoGraph;
    QCPDataMap rsrGraph;
    QCPDataMap rsxGraph;
    QCPDataMap rszGraph;
    QCPDataMap rprGraph;
    QCPDataMap rpxGraph;
    QCPDataMap rpzGraph;
    QCPDataMap rlGraph;
    QCPDataMap tdrImpGraph;
    QCPDataMap tdrStepGraph;
    QCPDataMap tdrImpGraphFeet;
    QCPDataMap tdrStepGraphFeet;

    QCPCurve *smithCurve;
    QCPCurveDataMap smithGraph;
    QCPCurveDataMap smithGraphView;
//---------------------------------
//---------------------------------
//---------------------------------
    QVector <rawData> dataRXCalib;
    QCPDataMap swrGraphCalib;
    QCPDataMap phaseGraphCalib;
    QCPDataMap rhoGraphCalib;
    QCPDataMap rsrGraphCalib;
    QCPDataMap rsxGraphCalib;
    QCPDataMap rszGraphCalib;
    QCPDataMap rprGraphCalib;
    QCPDataMap rpxGraphCalib;
    QCPDataMap rpzGraphCalib;
    QCPDataMap rlGraphCalib;
    QCPCurveDataMap smithGraphCalib;
};

#endif // ANALYZERPARAMETERS
