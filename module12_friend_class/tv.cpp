//
// Created by fcsca on 2019-03-07/0007.
//

#include "tv.h"
#include <iostream>

using namespace std;

bool Tv::volup() {
    if (volume < MaxVal) {
        volume++;
        return true;
    } else
        return false;
}

bool Tv::voldown() {
    if (volume > MinVal) {
        volume--;
        return true;
    } else
        return false;
}

void Tv::chanup() {
    if (channel < maxchannel) {
        channel++;
    } else
        channel = 1;
}

void Tv::chandown() {
    if (channel > 1)
        channel--;
    else
        channel = maxchannel;
}

void Tv::setting() const {
    cout << "TV is " << (state == Off? "Off":"On") << endl;
    if (state == On) {
        cout << "Volume setting = " << volume << endl;
        cout << "Channel setting = " << channel << endl;
        cout << "Mode = " << (mode == Antenna ? "antenna" : "cable") << endl;
        cout << "Input = " << (input == TV ? "TV" : "VCR") << endl;
    }
}
