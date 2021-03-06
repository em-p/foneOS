#pragma once

class HardwareManager
{
public:
	// Initializes the hardware manager and its associated hardware.
    static void Init();

    // Gets the current display.
    static Display * GetDisplay();

    // Gets the current modem.
    static Modem * GetModem();

    // Gets the current touch input device.
    static TouchInput * GetTouchInput();

	// Frees memory of the hardware manager and its associated hardware.
	static void Cleanup();
};
