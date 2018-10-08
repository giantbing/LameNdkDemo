//
// Created by giant on 2018/9/25.
//

#ifndef MYNDKDEMO_LAMEHELPER_H
#define MYNDKDEMO_LAMEHELPER_H


#include "lame.h"

class LameHelper {
private:
    FILE* pcmFile;
    FILE* mp3File;
    lame_t lameClient;

public:
    LameHelper();
    ~LameHelper();
    int Init(const char* pcmFilePath, const char *mp3FilePath, int
    sampleRate, int channels, int bitRate);
    void Encode();
    void Destory();

};


#endif //MYNDKDEMO_LAMEHELPER_H
