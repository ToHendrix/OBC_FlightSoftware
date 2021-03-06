/*
 *  OBCVariableContainer.h
 *
 *  Created on: Jun 10, 2020
 *      Author: tom-h
 */

#ifndef OBCVARIABLECONTAINER_H_
#define OBCVARIABLECONTAINER_H_

#define OBC_VARIABLECONTAINER_SIZE  68

typedef enum Mode {ACTIVATIONMODE, DEPLOYMENTMODE, SAFEMODE, ADCSMODE, NOMINALMODE} Mode;

// States of Delfi-PQ in different mode
typedef enum ActivationState  {UNEXPIRED, EXPIRED} ActivationState;
typedef enum DeployState  {NORMAL, FORCED, DELAYING, DEPLOYED} DeployState;
typedef enum ADCSState {IDLE, DETUMBLE, DISABLED} ADCSState;

// Can be used in every mode for power line V2, V3 and V4
typedef enum PowerState {UNINITIALIZED, INITIALIZED, CYCLING, OFF} PowerState;

// Health check results of subsystems (TODO)
typedef enum ADBHealthResult {ADB_BAD, ADB_GOOD} ADBHealthResult;
typedef enum ADCSHealthResult {ADCS_BAD, ADCS_GOOD} ADCSHealthResult;
typedef enum COMMSHealthResult {COMMS_BAD, COMMS_GOOD} COMMSHealthResult;
typedef enum OBCHealthResult {OBC_BAD, OBC_GOOD} OBCHealthResult;
typedef enum EPSHealthResult {EPS_BAD, EPS_GOOD} EPSHealthResult;
typedef enum PROPHealthResult {PROP_BAD, PROP_GOOD} PROPHealthResult;

class OBCVariableContainer
{
protected:
    unsigned char data[OBC_VARIABLECONTAINER_SIZE];

public:
    int size();
    unsigned char * getArray();

    // Initialization functions
    void NormalInit();
    void FirstBootInit();

    // Variables which are used in every mode

    Mode getMode();
    void setMode(Mode currentMode);

    unsigned long getBootCount();
    void setBootCount(unsigned long count);

    unsigned long getUpTime(); // Uptime since the last boot
    void setUpTime(unsigned long uplong);

    unsigned long getTotalUpTime(); // Uptime since the first boot
    void setTotalUpTime(unsigned long uplong);

    unsigned short getBatteryVoltage();
    void setBatteryVoltage(unsigned short battvolt);

    unsigned char getADBResponse();
    void setADBResponse(unsigned char res);

    unsigned char getADCSResponse();
    void setADCSResponse(unsigned char res);

    unsigned char getCOMMSResponse();
    void setCOMMSResponse(unsigned char res);

    unsigned char getEPSResponse();
    void setEPSResponse(unsigned char res);

    unsigned char getPROPResponse();
    void setPROPResponse(unsigned char res);

    // Variables in the activation mode

    ActivationState getActivationState();
    void setActivationState(ActivationState state);

    unsigned long getEndOfActivation();
    void setEndOfActivation(unsigned long uplong);

    // Variables in the deployment mode

    DeployState getDeployState();
    void setDeployState(DeployState state);

    unsigned long getEndOfDeployState();
    void setEndOfDeployState(unsigned long uplong);

    unsigned short getDeployVoltage();
    void setDeployVoltage(unsigned short deployvolt);

    unsigned long getForcedDeployParameter();
    void setForcedDeployParameter(unsigned long uplong);

    unsigned long getDeployDelayParameter();
    void setDeployDelayParameter(unsigned long uplong);

    unsigned long getDeployDelayTime();
    void setDeployDelayTime(unsigned long uplong);
    // Variables in the safe mode

    unsigned short getSMVoltage();
    void setSMVoltage(unsigned short safevolt);

    // Variables in the ADCS mode

    ADCSState getADCSState();
    void setADCSState(ADCSState state);

    unsigned long getEndOfADCSState();
    void setEndOfADCSState(unsigned long uplong);

    unsigned short getRotateSpeed(); // TODO: signed or unsigned?
    void setRotateSpeed(unsigned short value);

    unsigned short getRotateSpeedLimit(); // TODO: signed or unsigned?
    void setRotateSpeedLimit(unsigned short value);

    unsigned long getDetumblingPeriod();
    void setDetumblingPeriod(unsigned long uplong);

    PowerState getADCSPowerState();
    void setADCSPowerState(PowerState state);

    unsigned long getEndOfADCSPowerState();
    void setEndOfADCSPowerState(unsigned long uplong);

    unsigned long getADCSPowerCyclePeriod();
    void setADCSPowerCyclePeriod(unsigned long uplong);
};

#endif /* OBCVARIABLECONTAINER_H_ */
