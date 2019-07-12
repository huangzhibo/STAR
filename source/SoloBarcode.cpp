#include "SoloBarcode.h"
void SoloBarcode::sortWhiteList()
{
    totalSize=0;
    minLen=(uint32)-1;
    wlAdd.resize( wl.size() );
    for (uint32 ilen=1; ilen < wl.size(); ilen++) {//scan through different lengths for this CB
        wlAdd[ilen]=totalSize;
        if (wl[ilen].size()>0) {
            if (ilen<minLen)
                minLen=ilen;
            std::sort(wl[ilen].begin(),wl[ilen].end());//sort
            auto un1=std::unique(wl[ilen].begin(),wl[ilen].end());//collapse identical
            wl[ilen].resize(std::distance(wl[ilen].begin(),un1)); 
            totalSize += wl[ilen].size();            
        };
    };
};