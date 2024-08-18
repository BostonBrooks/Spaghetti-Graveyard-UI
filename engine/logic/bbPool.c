#include "engine/logic/bbPool.h"
#include "engine/logic/bbTerminal.h"
#include "engine/logic/bbIntTypes.h"

static const U32 numCheckingBits = 2;
static const U32 checkingBitMask = 0xC0000000;
static const U32 numIndexBits = 30;
static const U32 indexBitMask = 0x3fffffff;



bbHandle_unpacked bbHandle_Unpack (bbHandle handle){

    bbHandle_unpacked handleUnpacked;
    handleUnpacked.checking = handle >> numIndexBits;
    handleUnpacked.index = handle & indexBitMask;

    return handleUnpacked;
}

bbHandle bbHandle_Pack (bbHandle_unpacked handleUnpacked){

    U32 sanitisedIndex = handleUnpacked.index & indexBitMask;
    U32 checkingBits = handleUnpacked.checking << numIndexBits;
    return sanitisedIndex | checkingBits;

}

bool bbHandle_isNULL(bbHandle handle){
    U32 collision = handle >> numIndexBits;
    return collision == 0 ? true : false;
}

