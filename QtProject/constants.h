/**
 * \file   constants.h
 */

#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>

class constants{
public:
    // Test settings
    static const int minFrequency = 20;
    static const int maxFrequency = 22000;
    static const int volumeMaxGain = 50;
    static constexpr float slope = float(maxFrequency-minFrequency)/float(volumeMaxGain);
    static const int volume = 20;

    // Frequencies
    static constexpr inline float sideFrequencies[4] = {697, 770, 852, 941};
    static constexpr inline float upperFrequencies[4] = {1209, 1336, 1477, 1633};

    // Digits
    inline static constexpr char digits[16] = {'1', '2', '3', 'A', '4', '5', '6', 'B', '7', '8', '9', 'C', '*', '0', '#', 'D'};

    // Sample limit for each tone
    static const int limit40 = 1763;

    // Button words
    inline static const std::string desc = "Descolgar";
    inline static const std::string col = "Colgar";

    // Number
    inline static const std::string number = "26557321";


    // Filter constants

    // General
    static const int movingAverageSamples = 500;
    static const int filterAmount = 8;
    static const int filterBuffers = 3;

    // Side frequencies
    // 697 Hz
    static constexpr float gain1_697 = 0.0014948343;
    static constexpr float gain2_697 = 0.0014948343;

    static const int sizeX1_697 = 3;
    static constexpr inline float coeffX1_697[3] = {1, 0, -1};
    static const int sizeY1_697 = 2;
    static constexpr inline float coeffY1_697[2] = {-1.988317610643, 0.998417227816};

    static const int sizeX2_697 = 3;
    static constexpr inline float coeffX2_697[3] = {1, 0, -1};
    static const int sizeY2_697 = 2;
    static constexpr inline float coeffY2_697[2] = {-1.98886276558, 0.998457206963};

    // 770 Hz
    static constexpr float gain1_770 = 0.003326779638;
    static constexpr float gain2_770 = 0.003326779638;

    static const int sizeX1_770 = 3;
    static constexpr inline float coeffX1_770[3] = {1, 0, -1};
    static const int sizeY1_770 = 2;
    static constexpr inline float coeffY1_770[2] = {-1.983281193331,  0.995984875273};

    static const int sizeX2_770 = 3;
    static constexpr inline float coeffX2_770[3] = {1, 0, -1};
    static const int sizeY2_770 = 2;
    static constexpr inline float coeffY2_770[2] = {-1.984899050628,  0.996210410153};

    // 852 Hz
    static constexpr float gain1_852 = 0.00332677963;
    static constexpr float gain2_852 = 0.00332677963;

    static const int sizeX1_852 = 3;
    static constexpr inline float coeffX1_852[3] = {1, 0, -1};
    static const int sizeY1_852 = 2;
    static constexpr inline float coeffY1_852[2] = {-1.9805297492016 ,  0.99599582446};

    static const int sizeX2_852 = 3;
    static constexpr inline float coeffX2_852[3] = {1, 0, -1};
    static const int sizeY2_852 = 2;
    static constexpr inline float coeffY2_852[2] = {-1.9822732712603,  0.9961994586010};

    // 941 Hz
    static constexpr float gain1_941 = 0.003326779638;
    static constexpr float gain2_941 = 0.003326779638;

    static const int sizeX1_941 = 3;
    static constexpr inline float coeffX1_941[3] = {1, 0, -1};
    static const int sizeY1_941 = 2;
    static constexpr inline float coeffY1_941[2] = {-1.9772353455719,  0.9960055572224};

    static const int sizeX2_941 = 3;
    static constexpr inline float coeffX2_941[3] = {1, 0, -1};
    static const int sizeY2_941 = 2;
    static constexpr inline float coeffY2_941[2] = {-1.979119326072,  0.996189723950605};

    // Upper frequencies
    // 1209 Hz
    static constexpr float gain1_1209 = 0.00332677963862064;
    static constexpr float gain2_1209 = 0.00332677963862064;

    static const int sizeX1_1209 = 3;
    static constexpr inline float coeffX1_1209[3] = {1, 0, -1};
    static const int sizeY1_1209 = 2;
    static constexpr inline float coeffY1_1209[2] = {-1.967711204258091, 0.9961690230785906};

    static const int sizeX2_1209 = 3;
    static constexpr inline float coeffX2_1209[3] = {1, 0, -1};
    static const int sizeY2_1209 = 2;
    static constexpr inline float coeffY2_1209[2] = {-1.96538879380776765337, 0.9960262546975657826};

    // 1336 Hz
    static constexpr float gain1_1336 = 0.003326779638621;
    static constexpr float gain2_1336 = 0.003326779638621;

    static const int sizeX1_1336 = 3;
    static constexpr inline float coeffX1_1336[3] = {1, 0, -1};
    static const int sizeY1_1336 = 2;
    static constexpr inline float coeffY1_1336[2] = {-1.958770234308357061081,  0.996033184567360119};

    static const int sizeX2_1336 = 3;
    static constexpr inline float coeffX2_1336[3] = {1, 0, -1};
    static const int sizeY2_1336 = 2;
    static constexpr inline float coeffY2_1336[2] = {-1.96130510192716167594, 0.99616209226370922014};


    // 1477 Hz
    static constexpr float gain1_1477 = 0.002994686472327;
    static constexpr float gain2_1477 = 0.002994686472327;

    static const int sizeX1_1477 = 3;
    static constexpr inline float coeffX1_1477[3] = {1, 0, -1};
    static const int sizeY1_1477 = 2;
    static constexpr inline float coeffY1_1477[2] = {-1.951345715501094701949,  0.9964399904583554068};

    static const int sizeX2_1477 = 3;
    static constexpr inline float coeffX2_1477[3] = {1, 0, -1};
    static const int sizeY2_1477 = 2;
    static constexpr inline float coeffY2_1477[2] = {-1.9538274781289741710565,  0.9965343784331675003};


    // 1633 Hz
    static constexpr float gain1_1633 = 0.003326779638621;
    static constexpr float gain2_1633 = 0.003326779638621;

    static const int sizeX1_1633 = 3;
    static constexpr inline float coeffX1_1633[3] = {1, 0, -1};
    static const int sizeY1_1633 = 2;
    static constexpr inline float coeffY1_1633[2] = {-1.9407886179805524662356,  0.9960452282621359287};

    static const int sizeX2_1633 = 3;
    static constexpr inline float coeffX2_1633[3] = {1, 0, -1};
    static const int sizeY2_1633 = 2;
    static constexpr inline float coeffY2_1633[2] = {-1.94382546374363984753,  0.9961500471558724090215};


    // Threshold and such
    static float constexpr threshold_697 = 0.3;//0
    static float constexpr threshold_770 = 0.3;//1
    static float constexpr threshold_852 = 0.3;//2
    static float constexpr threshold_941 = 0.3;//3
    static float constexpr threshold_1209 = 0.3;//4
    static float constexpr threshold_1336 = 0.3;//5
    static float constexpr threshold_1477 = 0.3;//6
    static float constexpr threshold_1633 = 0.3;//7

    static const int minimunHigh_697 = 1000;//1850;
    static const int minimunHigh_770 = 700;//1800;
    static const int minimunHigh_852 = 700;//1800;
    static const int minimunHigh_941 = 700;//1100;  
    static const int minimunHigh_1209 = 500;//1700;
    static const int minimunHigh_1336 = 700;//1750;
    static const int minimunHigh_1477 = 700;//1850;
    static const int minimunHigh_1633 = 700;//1700;

};

#endif // CONSTANTS_H
