/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2008. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/

#include "DriverStationLCD.h"
#include "NetworkCommunication/FRCComm.h"
#include "Synchronized.h"
#include <strLib.h>

DriverStationLCD* DriverStationLCD::m_instance = NULL;

/**
 * DriverStationLCD contructor.
 *
 * This is only called once the first time GetInstance() is called
 */
DriverStationLCD::DriverStationLCD()
    : m_textBuffer (NULL)
    , m_textBufferSemaphore (NULL)
{
    m_textBuffer = new char[USER_DS_LCD_DATA_SIZE];
    memset(m_textBuffer, ' ', USER_DS_LCD_DATA_SIZE);

    *((UINT16 *)m_textBuffer) = kFullDisplayTextCommand;

    m_textBufferSemaphore = semMCreate(SEM_DELETE_SAFE | SEM_INVERSION_SAFE);

    AddToSingletonList();
}

DriverStationLCD::~DriverStationLCD()
{
    semDelete(m_textBufferSemaphore);
    delete [] m_textBuffer;
    m_instance = NULL;
}

/**
 * Return a pointer to the singleton DriverStationLCD.
 */
DriverStationLCD* DriverStationLCD::GetInstance()
{
    if (m_instance == NULL)
    {
        m_instance = new DriverStationLCD();
    }
    return m_instance;
}

/**
 * Send the text data to the Driver Station.
 */
void DriverStationLCD::UpdateLCD()
{
    Synchronized sync(m_textBufferSemaphore);
    setUserDsLcdData(m_textBuffer, USER_DS_LCD_DATA_SIZE, kSyncTimeout_ms);
}

/**
 * Clear the text buffer.
 */
void DriverStationLCD::ClearBuffer()
{
    Synchronized sync(m_textBufferSemaphore);
    memset(m_textBuffer+2, ' ', USER_DS_LCD_DATA_SIZE-2);
}

/**
 * Print formatted text to the Driver Station LCD text bufer.
 *
 * Use UpdateLCD() periodically to actually send the test to the Driver Station.
 *
 * @param line The line on the LCD to print to.
 * @param startingColumn The column to start printing to (1-based number).
 * @param writeFmt The printf format string describing how to print.
 */
void DriverStationLCD::Printf(Line line, UINT32 startingColumn,
                              const char *writeFmt, ...)
{
    va_list args;
    UINT32 start = startingColumn - 1;
    INT32 maxLength = kLineLength - start;
    char lineBuffer[kLineLength + 1];

    if (startingColumn < 1 || startingColumn > startingColumn)
        return;

    if (line < kMain_Line6 || line > kUser_Line6)
        return;

    va_start (args, writeFmt);
    {
        Synchronized sync(m_textBufferSemaphore);
        /* snprintf appends NULL to its output.  Therefore we can't write
           directly to the buffer. */
        INT32 length = vsnprintf(lineBuffer, kLineLength + 1, writeFmt, args);
        memcpy(m_textBuffer + start + line * kLineLength + sizeof(UINT16),
               lineBuffer,
               std::min(maxLength,length));
    }

    va_end (args);
}

