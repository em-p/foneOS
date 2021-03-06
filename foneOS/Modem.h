#pragma once
class Modem
{
public:
    virtual ~Modem() { }

    // Initializes the modem.
    virtual void Init() = 0;

    // Checks if the modem is working.
    virtual bool GetEnabled() = 0;

    // Gets the operator the modem is connected to.
    virtual FoneOSString GetOperator() = 0;

    // Gets the RSSI of the modem's connection.
    virtual int GetRSSI() = 0;

    // Gets the firmware revision of the modem.
    virtual FoneOSString GetFWRev() = 0;

    // Gets the IMEI of the modem.
    virtual FoneOSString GetIMEI() = 0;

	// Gets the CCID of the modem SIM card.
	virtual FoneOSString GetCCID() = 0;

	// Calls
	// Calls the specified phone number.
	virtual void Call(FoneOSString number) = 0;

    // Frees memory associated with the modem.
    virtual void Cleanup() = 0;
};

class Modem_Fake : public Modem
{
public:
    virtual void Init();
    virtual bool GetEnabled();
    virtual FoneOSString GetOperator();
    virtual int GetRSSI();
    virtual FoneOSString GetFWRev();
    virtual FoneOSString GetIMEI();
    virtual FoneOSString GetCCID();
	virtual void Call(FoneOSString number);
    virtual void Cleanup();
};

#ifdef PRODUCTION_BUILD
class Modem_SIM800 : public Modem
{
public:
    virtual void Init();
    virtual bool GetEnabled();
    virtual FoneOSString GetOperator();
    virtual int GetRSSI();
    virtual FoneOSString GetFWRev();
    virtual FoneOSString GetIMEI();
    virtual FoneOSString GetCCID();
	virtual void Call(FoneOSString number);
    virtual void Cleanup();
private:
    mraa_uart_context _serial;

    char replybuffer[512];

    std::string Read();
    void WriteLine(std::string line);
    bool CheckReply(std::string line, std::string reply);
};
#endif
