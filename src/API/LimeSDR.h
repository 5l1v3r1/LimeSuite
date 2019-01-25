/*
 * File:   LimeSDR.h
 * Author: Ignas J
 *
 * Created on September 18, 2017
 */

#ifndef LIMESDR_H
#define	LIMESDR_H
#include "LmsGeneric.h"

namespace lime
{

class LMS7_LimeSDR : public LMS7_Generic
{
public:
    LMS7_LimeSDR(lime::IConnection* conn, LMS7_Device *obj = nullptr);
    int SetRate(double f_Hz, int oversample) override;
    std::vector<std::string> GetProgramModes() const override;
    int Program(const std::string& mode, const char* data, size_t len, lime::IConnection::ProgrammingCallback callback) const override;
private:
};

class LMS7_CoreSDR : public LMS7_LimeSDR
{
public:
    LMS7_CoreSDR(lime::IConnection* conn, LMS7_Device *obj = nullptr);
    std::vector<std::string> GetProgramModes() const override;
    int SetPath(bool tx, unsigned chan, unsigned path) override;
private:
    int SetRFSwitch(bool isTx, unsigned path, int chan);
};

class LMS7_LimeSDR_PCIE : public LMS7_Generic
{
public:
    LMS7_LimeSDR_PCIE(lime::IConnection* conn, LMS7_Device *obj = nullptr);
    std::vector<std::string> GetProgramModes() const override;
    int SetRate(double f_Hz, int oversample) override;
private:
};

}

#endif	/* LIMESDR_H */

