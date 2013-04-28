#pragma once

class ISwitchable {
public:
    virtual void enable() = 0;
    virtual int getSwitchId() = 0;
};