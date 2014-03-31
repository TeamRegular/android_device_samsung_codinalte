/*
 * Copyright (C) ST-Ericsson SA 2010. All rights reserved.
 * This code is ST-Ericsson proprietary and confidential.
 * Any use of the code for whatever purpose is subject to
 * specific written permission of ST-Ericsson SA.
 */

/** @file scf_events.h
    @brief This file defines all functional events
    used by the state machines of the camera system
*/

//rename_file as scf_event.h

#ifndef scf_event_h
#define scf_event_h

#include "OMX_Component.h"
#include "IFM_Types.h"
#include "nmf_eventhandler.h"
#include "ENS_Nmf.h"
#include "ENS_Component_Fsm.h"
#include "hsmsig.h" // rename_me  with scf_signals.h

struct s_scf_event {

	e_scf_signal sig;                       // signal of the event instance

   union {
   	   int other;
	   struct s_NMF_ispctlInfoEvent ispctlInfo;
	   struct s_NMF_ispctlInfoEvent ispctlListInfo;
	   struct s_NMF_ispctlErrorEvent ispctlError;
	   struct s_NMF_ispctlDebugEvent ispctlDebug;
	   struct s_NMF_tuningLoaderEvent tuningLoaderEvent;
	   struct s_NMF_grabInfoEvent grabInfo;
	   struct s_NMF_grabErrorEvent grabError;
	   struct s_NMF_grabDebugEvent grabDebug;

	   struct OMX_STE_CONFIG_SENSORTESTTYPE testModeStruct;
	   struct OMX_CONFIG_WHITEBALCONTROLTYPE wbStruct;
	   struct OMX_CONFIG_BRIGHTNESSTYPE brightStruct;
	   struct OMX_CONFIG_LIGHTNESSTYPE lightStruct;
	   struct OMX_CONFIG_EXPOSUREVALUETYPE exposureValueStruct;
	   struct OMX_CONFIG_EXPOSURECONTROLTYPE exposureControlStruct;
	   struct OMX_CONFIG_CONTRASTTYPE contrastStruct;
	   struct OMX_CONFIG_SATURATIONTYPE saturationStruct;
	   struct OMX_CONFIG_GAMMATYPE gammaStruct;
	   struct OMX_CONFIG_IMAGEFILTERTYPE imgFilterStruct;
	   struct OMX_IMAGE_CONFIG_FOCUSCONTROLTYPE focusControlStruct;
	   //struct OMX_SYMBIAN_CONFIG_ZOOMFACTORTYPE zoomFactorStruct;
	   //struct OMX_SYMBIAN_CONFIG_POINTTYPE zoomCenterStruct;
	   struct OMX_SYMBIAN_CONFIG_BOOLEANTYPE capturingStruct;
	   struct OMX_SYMBIAN_CONFIG_EXTCAPTUREMODETYPE extCapturingStruct;
	   struct IFM_CONFIG_WRITEPETYPE writeStruct;
	   struct IFM_CONFIG_READPETYPE readStruct;
	  

   } type;
   union {
	   OMX_BUFFERHEADERTYPE * omxbufferhdr;
	   OMX_INDEXTYPE 		  omxsetConfigIndex;
	  struct {
	         OMX_COMMANDTYPE Cmd;
	         OMX_U32 nParam;
             OMX_BOOL nSendCallback;
	   }sendCommand;
   }args;
};

extern s_scf_event const pkgStdEvt[];

#endif // scf_event_h