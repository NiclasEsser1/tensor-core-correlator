#if !defined UNIT_TEST_H
#define UNIT_TEST_H

#include <cu.hpp>

#include "test/Common/Record.h"

#if defined MEASURE_POWER
#include <powersensor/NVMLPowerSensor.h>
#endif


class UnitTest
{
  public:
    UnitTest(unsigned deviceNumber);
    ~UnitTest();

  protected:
    void report(const char *name, const Record &startRecord, const Record &stopRecord, uint64_t FLOPS = 0, uint64_t bytes = 0);

    cu::Device  device;
    cu::Context context;
    cu::Stream  stream;

#if defined MEASURE_POWER
    powersensor::PowerSensor *powerSensor;
#endif
};

#endif
