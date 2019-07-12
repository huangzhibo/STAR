#ifndef H_SoloReadBarcode
#define H_SoloReadBarcode
#include <set>
#include "IncludeDefine.h"
#include "Parameters.h"

class SoloReadBarcode {
public:
    uint32 homoPolymer[4];//homopolymer constants
    string cbSeq, umiSeq, cbQual, umiQual;
    uint32 umiB;
    //int64  cbI;
    int32  cbMatch;//-1: no match, 0: exact, 1: 1 match with 1MM, >1: # of matches with 1MM
    string cbMatchString;//CB matches and qualities
    vector<uint64> cbMatchInd;//matches
    uint32 *cbReadCountExact;

    struct {
        enum {                 nNinBarcode,  nUMIhomopolymer,  nTooMany,  nNoMatch,  nStats};
        uint64 V[nStats];
        vector<string> names={"nNinBarcode","nUMIhomopolymer","nTooMany","nNoMatch"};
    } stats;

    SoloReadBarcode(Parameters &Pin);
    void getCBandUMI(string &readNameExtra);
    void addCounts(const SoloReadBarcode &rfIn);
    void addStats(const SoloReadBarcode &rfIn);
    void statsOut(ofstream &streamOut);
    void matchCBtoWL(string &cbSeq1, string &cbQual1, vector<uint64> &cbWL, int32 &cbMatch1, vector<uint64> &cbMatchInd1, string &cbMatchString1);
    bool convertCheckUMI();

private:
    Parameters &P;
    ParametersSolo &pSolo;
};

#endif
