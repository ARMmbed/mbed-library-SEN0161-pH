#ifndef _SEN0161_H_
#define _SEN0161_H_

#include "mbed.h"

class SEN0161 {
    public:
        SEN0161 (PinName data_pin);

        /** Reads the pH
        * 
        * @returns pH
        */
        float get_pH();

    private:
        AnalogIn _datapin;

};

#endif