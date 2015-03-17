/*
 * static_model.c
 *
 * automatically generated from gebrick.icd
 */
#include <stdlib.h>
#include "iec61850_model.h"

extern IedModel iedModel;
static void initializeValues();
extern LogicalDevice iedModel_LDInst;
extern LogicalNode   iedModel_LDInst_LLN0;
extern DataObject    iedModel_LDInst_LLN0_Mod;
extern DataAttribute iedModel_LDInst_LLN0_Mod_stVal;
extern DataAttribute iedModel_LDInst_LLN0_Mod_q;
extern DataAttribute iedModel_LDInst_LLN0_Mod_t;
extern DataAttribute iedModel_LDInst_LLN0_Mod_ctlModel;
extern DataObject    iedModel_LDInst_LLN0_Beh;
extern DataAttribute iedModel_LDInst_LLN0_Beh_stVal;
extern DataAttribute iedModel_LDInst_LLN0_Beh_q;
extern DataAttribute iedModel_LDInst_LLN0_Beh_t;
extern DataObject    iedModel_LDInst_LLN0_Health;
extern DataAttribute iedModel_LDInst_LLN0_Health_stVal;
extern DataAttribute iedModel_LDInst_LLN0_Health_q;
extern DataAttribute iedModel_LDInst_LLN0_Health_t;
extern DataObject    iedModel_LDInst_LLN0_NamPlt;
extern DataAttribute iedModel_LDInst_LLN0_NamPlt_vendor;
extern DataAttribute iedModel_LDInst_LLN0_NamPlt_swRev;
extern DataAttribute iedModel_LDInst_LLN0_NamPlt_d;
extern DataAttribute iedModel_LDInst_LLN0_NamPlt_configRev;
extern LogicalNode   iedModel_LDInst_LPHD1;
extern DataObject    iedModel_LDInst_LPHD1_PhyHealth;
extern DataAttribute iedModel_LDInst_LPHD1_PhyHealth_stVal;
extern DataAttribute iedModel_LDInst_LPHD1_PhyHealth_q;
extern DataAttribute iedModel_LDInst_LPHD1_PhyHealth_t;
extern DataObject    iedModel_LDInst_LPHD1_Proxy;
extern DataAttribute iedModel_LDInst_LPHD1_Proxy_stVal;
extern DataAttribute iedModel_LDInst_LPHD1_Proxy_q;
extern DataAttribute iedModel_LDInst_LPHD1_Proxy_t;
extern DataObject    iedModel_LDInst_LPHD1_PhyNam;
extern DataAttribute iedModel_LDInst_LPHD1_PhyNam_vendor;
extern DataAttribute iedModel_LDInst_LPHD1_PhyNam_swRev;
extern DataAttribute iedModel_LDInst_LPHD1_PhyNam_serNum;
extern DataAttribute iedModel_LDInst_LPHD1_PhyNam_model;
extern DataAttribute iedModel_LDInst_LPHD1_PhyNam_location;
extern LogicalNode   iedModel_LDInst_IBRK1;
extern DataObject    iedModel_LDInst_IBRK1_Mod;
extern DataAttribute iedModel_LDInst_IBRK1_Mod_stVal;
extern DataAttribute iedModel_LDInst_IBRK1_Mod_q;
extern DataAttribute iedModel_LDInst_IBRK1_Mod_t;
extern DataAttribute iedModel_LDInst_IBRK1_Mod_ctlModel;
extern DataObject    iedModel_LDInst_IBRK1_Beh;
extern DataAttribute iedModel_LDInst_IBRK1_Beh_stVal;
extern DataAttribute iedModel_LDInst_IBRK1_Beh_q;
extern DataAttribute iedModel_LDInst_IBRK1_Beh_t;
extern DataObject    iedModel_LDInst_IBRK1_Health;
extern DataAttribute iedModel_LDInst_IBRK1_Health_stVal;
extern DataAttribute iedModel_LDInst_IBRK1_Health_q;
extern DataAttribute iedModel_LDInst_IBRK1_Health_t;
extern DataObject    iedModel_LDInst_IBRK1_NamPlt;
extern DataAttribute iedModel_LDInst_IBRK1_NamPlt_vendor;
extern DataAttribute iedModel_LDInst_IBRK1_NamPlt_swRev;
extern DataAttribute iedModel_LDInst_IBRK1_NamPlt_d;
extern DataAttribute iedModel_LDInst_IBRK1_NamPlt_configRev;
extern DataObject    iedModel_LDInst_IBRK1_U;
extern DataAttribute iedModel_LDInst_IBRK1_U_smpNum;
extern DataAttribute iedModel_LDInst_IBRK1_U_model;
extern DataAttribute iedModel_LDInst_IBRK1_U_serNum;
extern DataAttribute iedModel_LDInst_IBRK1_U_outputs;
extern DataAttribute iedModel_LDInst_IBRK1_U_analogs;
extern DataAttribute iedModel_LDInst_IBRK1_U_analogs_ac1;
extern DataAttribute iedModel_LDInst_IBRK1_U_analogs_ac2;
extern DataAttribute iedModel_LDInst_IBRK1_U_analogs_ac3;
extern DataAttribute iedModel_LDInst_IBRK1_U_analogs_ac4;
extern DataAttribute iedModel_LDInst_IBRK1_U_analogs_ac5;
extern DataAttribute iedModel_LDInst_IBRK1_U_analogs_ac6;
extern DataAttribute iedModel_LDInst_IBRK1_U_analogs_ac7;
extern DataAttribute iedModel_LDInst_IBRK1_U_analogs_ac8;
extern DataAttribute iedModel_LDInst_IBRK1_U_analogs_dc1;
extern DataAttribute iedModel_LDInst_IBRK1_U_analogs_dc2;
extern DataAttribute iedModel_LDInst_IBRK1_U_analogs_dc3;
extern DataAttribute iedModel_LDInst_IBRK1_U_contactInputs;
extern DataAttribute iedModel_LDInst_IBRK1_U_sharedInputs;
extern DataAttribute iedModel_LDInst_IBRK1_U_outputMonitors;
extern DataAttribute iedModel_LDInst_IBRK1_U_diagnostics;
extern DataAttribute iedModel_LDInst_IBRK1_U_diagnostics_diagnosticFlags;
extern DataAttribute iedModel_LDInst_IBRK1_U_diagnostics_adcTemp;
extern DataAttribute iedModel_LDInst_IBRK1_U_diagnostics_transceiverTemp;
extern DataAttribute iedModel_LDInst_IBRK1_U_diagnostics_transceiverVolts;
extern DataAttribute iedModel_LDInst_IBRK1_U_diagnostics_transceiverCurrent;
extern DataAttribute iedModel_LDInst_IBRK1_U_diagnostics_transceiverTxPower;
extern DataAttribute iedModel_LDInst_IBRK1_U_diagnostics_transceiverRxPower;
extern DataAttribute iedModel_LDInst_IBRK1_U_lnNs;

extern DataSet ds_LDInst_LLN0_F;
extern DataSet ds_LDInst_LLN0_S;


extern DataSetEntry ds_LDInst_LLN0_F_fcda0;
extern DataSetEntry ds_LDInst_LLN0_F_fcda1;
extern DataSetEntry ds_LDInst_LLN0_F_fcda2;
extern DataSetEntry ds_LDInst_LLN0_F_fcda3;
extern DataSetEntry ds_LDInst_LLN0_F_fcda4;
extern DataSetEntry ds_LDInst_LLN0_F_fcda5;
extern DataSetEntry ds_LDInst_LLN0_F_fcda6;
extern DataSetEntry ds_LDInst_LLN0_F_fcda7;
extern DataSetEntry ds_LDInst_LLN0_F_fcda8;
extern DataSetEntry ds_LDInst_LLN0_F_fcda9;
extern DataSetEntry ds_LDInst_LLN0_F_fcda10;
extern DataSetEntry ds_LDInst_LLN0_F_fcda11;
extern DataSetEntry ds_LDInst_LLN0_F_fcda12;
extern DataSetEntry ds_LDInst_LLN0_F_fcda13;

DataSetEntry ds_LDInst_LLN0_F_fcda0 = {
  "LDInst",
  false,
  "IBRK1$MX$U$analogs$ac1",
  -1,
  NULL,
  NULL,
  &ds_LDInst_LLN0_F_fcda1
};

DataSetEntry ds_LDInst_LLN0_F_fcda1 = {
  "LDInst",
  false,
  "IBRK1$MX$U$analogs$ac2",
  -1,
  NULL,
  NULL,
  &ds_LDInst_LLN0_F_fcda2
};

DataSetEntry ds_LDInst_LLN0_F_fcda2 = {
  "LDInst",
  false,
  "IBRK1$MX$U$analogs$ac3",
  -1,
  NULL,
  NULL,
  &ds_LDInst_LLN0_F_fcda3
};

DataSetEntry ds_LDInst_LLN0_F_fcda3 = {
  "LDInst",
  false,
  "IBRK1$MX$U$analogs$ac4",
  -1,
  NULL,
  NULL,
  &ds_LDInst_LLN0_F_fcda4
};

DataSetEntry ds_LDInst_LLN0_F_fcda4 = {
  "LDInst",
  false,
  "IBRK1$MX$U$analogs$ac5",
  -1,
  NULL,
  NULL,
  &ds_LDInst_LLN0_F_fcda5
};

DataSetEntry ds_LDInst_LLN0_F_fcda5 = {
  "LDInst",
  false,
  "IBRK1$MX$U$analogs$ac6",
  -1,
  NULL,
  NULL,
  &ds_LDInst_LLN0_F_fcda6
};

DataSetEntry ds_LDInst_LLN0_F_fcda6 = {
  "LDInst",
  false,
  "IBRK1$MX$U$analogs$ac7",
  -1,
  NULL,
  NULL,
  &ds_LDInst_LLN0_F_fcda7
};

DataSetEntry ds_LDInst_LLN0_F_fcda7 = {
  "LDInst",
  false,
  "IBRK1$MX$U$analogs$ac8",
  -1,
  NULL,
  NULL,
  &ds_LDInst_LLN0_F_fcda8
};

DataSetEntry ds_LDInst_LLN0_F_fcda8 = {
  "LDInst",
  false,
  "IBRK1$MX$U$analogs$dc1",
  -1,
  NULL,
  NULL,
  &ds_LDInst_LLN0_F_fcda9
};

DataSetEntry ds_LDInst_LLN0_F_fcda9 = {
  "LDInst",
  false,
  "IBRK1$MX$U$analogs$dc2",
  -1,
  NULL,
  NULL,
  &ds_LDInst_LLN0_F_fcda10
};

DataSetEntry ds_LDInst_LLN0_F_fcda10 = {
  "LDInst",
  false,
  "IBRK1$MX$U$analogs$dc3",
  -1,
  NULL,
  NULL,
  &ds_LDInst_LLN0_F_fcda11
};

DataSetEntry ds_LDInst_LLN0_F_fcda11 = {
  "LDInst",
  false,
  "IBRK1$ST$U$contactInputs",
  -1,
  NULL,
  NULL,
  &ds_LDInst_LLN0_F_fcda12
};

DataSetEntry ds_LDInst_LLN0_F_fcda12 = {
  "LDInst",
  false,
  "IBRK1$ST$U$sharedInputs",
  -1,
  NULL,
  NULL,
  &ds_LDInst_LLN0_F_fcda13
};

DataSetEntry ds_LDInst_LLN0_F_fcda13 = {
  "LDInst",
  false,
  "IBRK1$ST$U$outputMonitors",
  -1,
  NULL,
  NULL,
  NULL
};

DataSet ds_LDInst_LLN0_F = {
  "LDInst",
  "LLN0$F",
  14,
  &ds_LDInst_LLN0_F_fcda0,
  &ds_LDInst_LLN0_S
};

extern DataSetEntry ds_LDInst_LLN0_S_fcda0;
extern DataSetEntry ds_LDInst_LLN0_S_fcda1;
extern DataSetEntry ds_LDInst_LLN0_S_fcda2;

DataSetEntry ds_LDInst_LLN0_S_fcda0 = {
  "LDInst",
  false,
  "IBRK1$CF$U$model",
  -1,
  NULL,
  NULL,
  &ds_LDInst_LLN0_S_fcda1
};

DataSetEntry ds_LDInst_LLN0_S_fcda1 = {
  "LDInst",
  false,
  "IBRK1$ST$U$smpNum",
  -1,
  NULL,
  NULL,
  &ds_LDInst_LLN0_S_fcda2
};

DataSetEntry ds_LDInst_LLN0_S_fcda2 = {
  "LDInst",
  false,
  "IBRK1$ST$U$diagnostics",
  -1,
  NULL,
  NULL,
  NULL
};

DataSet ds_LDInst_LLN0_S = {
  "LDInst",
  "LLN0$S",
  3,
  &ds_LDInst_LLN0_S_fcda0,
  NULL
};

LogicalDevice iedModel_LDInst = {
    LogicalDeviceModelType,
    "LDInst",
    (ModelNode*) &iedModel,
    NULL,
    (ModelNode*) &iedModel_LDInst_LLN0
};

LogicalNode iedModel_LDInst_LLN0 = {
    LogicalNodeModelType,
    "LLN0",
    (ModelNode*) &iedModel_LDInst,
    (ModelNode*) &iedModel_LDInst_LPHD1,
    (ModelNode*) &iedModel_LDInst_LLN0_Mod,
};

DataObject iedModel_LDInst_LLN0_Mod = {
    DataObjectModelType,
    "Mod",
    (ModelNode*) &iedModel_LDInst_LLN0,
    (ModelNode*) &iedModel_LDInst_LLN0_Beh,
    (ModelNode*) &iedModel_LDInst_LLN0_Mod_stVal,
    0
};

DataAttribute iedModel_LDInst_LLN0_Mod_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LDInst_LLN0_Mod,
    (ModelNode*) &iedModel_LDInst_LLN0_Mod_q,
    NULL,
    0,
    ST,
    ENUMERATED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDInst_LLN0_Mod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDInst_LLN0_Mod,
    (ModelNode*) &iedModel_LDInst_LLN0_Mod_t,
    NULL,
    0,
    ST,
    QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDInst_LLN0_Mod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDInst_LLN0_Mod,
    (ModelNode*) &iedModel_LDInst_LLN0_Mod_ctlModel,
    NULL,
    0,
    ST,
    TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LDInst_LLN0_Mod_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &iedModel_LDInst_LLN0_Mod,
    NULL,
    NULL,
    0,
    CF,
    ENUMERATED,
    0,
    NULL,
    0};

DataObject iedModel_LDInst_LLN0_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &iedModel_LDInst_LLN0,
    (ModelNode*) &iedModel_LDInst_LLN0_Health,
    (ModelNode*) &iedModel_LDInst_LLN0_Beh_stVal,
    0
};

DataAttribute iedModel_LDInst_LLN0_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LDInst_LLN0_Beh,
    (ModelNode*) &iedModel_LDInst_LLN0_Beh_q,
    NULL,
    0,
    ST,
    ENUMERATED,
    0,
    NULL,
    0};

DataAttribute iedModel_LDInst_LLN0_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDInst_LLN0_Beh,
    (ModelNode*) &iedModel_LDInst_LLN0_Beh_t,
    NULL,
    0,
    ST,
    QUALITY,
    0,
    NULL,
    0};

DataAttribute iedModel_LDInst_LLN0_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDInst_LLN0_Beh,
    NULL,
    NULL,
    0,
    ST,
    TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LDInst_LLN0_Health = {
    DataObjectModelType,
    "Health",
    (ModelNode*) &iedModel_LDInst_LLN0,
    (ModelNode*) &iedModel_LDInst_LLN0_NamPlt,
    (ModelNode*) &iedModel_LDInst_LLN0_Health_stVal,
    0
};

DataAttribute iedModel_LDInst_LLN0_Health_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LDInst_LLN0_Health,
    (ModelNode*) &iedModel_LDInst_LLN0_Health_q,
    NULL,
    0,
    ST,
    ENUMERATED,
    0,
    NULL,
    0};

DataAttribute iedModel_LDInst_LLN0_Health_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDInst_LLN0_Health,
    (ModelNode*) &iedModel_LDInst_LLN0_Health_t,
    NULL,
    0,
    ST,
    QUALITY,
    0,
    NULL,
    0};

DataAttribute iedModel_LDInst_LLN0_Health_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDInst_LLN0_Health,
    NULL,
    NULL,
    0,
    ST,
    TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LDInst_LLN0_NamPlt = {
    DataObjectModelType,
    "NamPlt",
    (ModelNode*) &iedModel_LDInst_LLN0,
    NULL,
    (ModelNode*) &iedModel_LDInst_LLN0_NamPlt_vendor,
    0
};

DataAttribute iedModel_LDInst_LLN0_NamPlt_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &iedModel_LDInst_LLN0_NamPlt,
    (ModelNode*) &iedModel_LDInst_LLN0_NamPlt_swRev,
    NULL,
    0,
    DC,
    VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_LDInst_LLN0_NamPlt_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &iedModel_LDInst_LLN0_NamPlt,
    (ModelNode*) &iedModel_LDInst_LLN0_NamPlt_d,
    NULL,
    0,
    DC,
    VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_LDInst_LLN0_NamPlt_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &iedModel_LDInst_LLN0_NamPlt,
    (ModelNode*) &iedModel_LDInst_LLN0_NamPlt_configRev,
    NULL,
    0,
    DC,
    VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_LDInst_LLN0_NamPlt_configRev = {
    DataAttributeModelType,
    "configRev",
    (ModelNode*) &iedModel_LDInst_LLN0_NamPlt,
    NULL,
    NULL,
    0,
    DC,
    VISIBLE_STRING_255,
    0,
    NULL,
    0};

LogicalNode iedModel_LDInst_LPHD1 = {
    LogicalNodeModelType,
    "LPHD1",
    (ModelNode*) &iedModel_LDInst,
    (ModelNode*) &iedModel_LDInst_IBRK1,
    (ModelNode*) &iedModel_LDInst_LPHD1_PhyHealth,
};

DataObject iedModel_LDInst_LPHD1_PhyHealth = {
    DataObjectModelType,
    "PhyHealth",
    (ModelNode*) &iedModel_LDInst_LPHD1,
    (ModelNode*) &iedModel_LDInst_LPHD1_Proxy,
    (ModelNode*) &iedModel_LDInst_LPHD1_PhyHealth_stVal,
    0
};

DataAttribute iedModel_LDInst_LPHD1_PhyHealth_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LDInst_LPHD1_PhyHealth,
    (ModelNode*) &iedModel_LDInst_LPHD1_PhyHealth_q,
    NULL,
    0,
    ST,
    ENUMERATED,
    0,
    NULL,
    0};

DataAttribute iedModel_LDInst_LPHD1_PhyHealth_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDInst_LPHD1_PhyHealth,
    (ModelNode*) &iedModel_LDInst_LPHD1_PhyHealth_t,
    NULL,
    0,
    ST,
    QUALITY,
    0,
    NULL,
    0};

DataAttribute iedModel_LDInst_LPHD1_PhyHealth_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDInst_LPHD1_PhyHealth,
    NULL,
    NULL,
    0,
    ST,
    TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LDInst_LPHD1_Proxy = {
    DataObjectModelType,
    "Proxy",
    (ModelNode*) &iedModel_LDInst_LPHD1,
    (ModelNode*) &iedModel_LDInst_LPHD1_PhyNam,
    (ModelNode*) &iedModel_LDInst_LPHD1_Proxy_stVal,
    0
};

DataAttribute iedModel_LDInst_LPHD1_Proxy_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LDInst_LPHD1_Proxy,
    (ModelNode*) &iedModel_LDInst_LPHD1_Proxy_q,
    NULL,
    0,
    ST,
    BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDInst_LPHD1_Proxy_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDInst_LPHD1_Proxy,
    (ModelNode*) &iedModel_LDInst_LPHD1_Proxy_t,
    NULL,
    0,
    ST,
    QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDInst_LPHD1_Proxy_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDInst_LPHD1_Proxy,
    NULL,
    NULL,
    0,
    ST,
    TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LDInst_LPHD1_PhyNam = {
    DataObjectModelType,
    "PhyNam",
    (ModelNode*) &iedModel_LDInst_LPHD1,
    NULL,
    (ModelNode*) &iedModel_LDInst_LPHD1_PhyNam_vendor,
    0
};

DataAttribute iedModel_LDInst_LPHD1_PhyNam_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &iedModel_LDInst_LPHD1_PhyNam,
    (ModelNode*) &iedModel_LDInst_LPHD1_PhyNam_swRev,
    NULL,
    0,
    DC,
    VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_LDInst_LPHD1_PhyNam_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &iedModel_LDInst_LPHD1_PhyNam,
    (ModelNode*) &iedModel_LDInst_LPHD1_PhyNam_serNum,
    NULL,
    0,
    DC,
    VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_LDInst_LPHD1_PhyNam_serNum = {
    DataAttributeModelType,
    "serNum",
    (ModelNode*) &iedModel_LDInst_LPHD1_PhyNam,
    (ModelNode*) &iedModel_LDInst_LPHD1_PhyNam_model,
    NULL,
    0,
    DC,
    VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_LDInst_LPHD1_PhyNam_model = {
    DataAttributeModelType,
    "model",
    (ModelNode*) &iedModel_LDInst_LPHD1_PhyNam,
    (ModelNode*) &iedModel_LDInst_LPHD1_PhyNam_location,
    NULL,
    0,
    DC,
    VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_LDInst_LPHD1_PhyNam_location = {
    DataAttributeModelType,
    "location",
    (ModelNode*) &iedModel_LDInst_LPHD1_PhyNam,
    NULL,
    NULL,
    0,
    DC,
    VISIBLE_STRING_255,
    0,
    NULL,
    0};

LogicalNode iedModel_LDInst_IBRK1 = {
    LogicalNodeModelType,
    "IBRK1",
    (ModelNode*) &iedModel_LDInst,
    NULL,
    (ModelNode*) &iedModel_LDInst_IBRK1_Mod,
};

DataObject iedModel_LDInst_IBRK1_Mod = {
    DataObjectModelType,
    "Mod",
    (ModelNode*) &iedModel_LDInst_IBRK1,
    (ModelNode*) &iedModel_LDInst_IBRK1_Beh,
    (ModelNode*) &iedModel_LDInst_IBRK1_Mod_stVal,
    0
};

DataAttribute iedModel_LDInst_IBRK1_Mod_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LDInst_IBRK1_Mod,
    (ModelNode*) &iedModel_LDInst_IBRK1_Mod_q,
    NULL,
    0,
    ST,
    ENUMERATED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDInst_IBRK1_Mod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDInst_IBRK1_Mod,
    (ModelNode*) &iedModel_LDInst_IBRK1_Mod_t,
    NULL,
    0,
    ST,
    QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDInst_IBRK1_Mod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDInst_IBRK1_Mod,
    (ModelNode*) &iedModel_LDInst_IBRK1_Mod_ctlModel,
    NULL,
    0,
    ST,
    TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LDInst_IBRK1_Mod_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &iedModel_LDInst_IBRK1_Mod,
    NULL,
    NULL,
    0,
    CF,
    ENUMERATED,
    0,
    NULL,
    0};

DataObject iedModel_LDInst_IBRK1_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &iedModel_LDInst_IBRK1,
    (ModelNode*) &iedModel_LDInst_IBRK1_Health,
    (ModelNode*) &iedModel_LDInst_IBRK1_Beh_stVal,
    0
};

DataAttribute iedModel_LDInst_IBRK1_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LDInst_IBRK1_Beh,
    (ModelNode*) &iedModel_LDInst_IBRK1_Beh_q,
    NULL,
    0,
    ST,
    ENUMERATED,
    0,
    NULL,
    0};

DataAttribute iedModel_LDInst_IBRK1_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDInst_IBRK1_Beh,
    (ModelNode*) &iedModel_LDInst_IBRK1_Beh_t,
    NULL,
    0,
    ST,
    QUALITY,
    0,
    NULL,
    0};

DataAttribute iedModel_LDInst_IBRK1_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDInst_IBRK1_Beh,
    NULL,
    NULL,
    0,
    ST,
    TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LDInst_IBRK1_Health = {
    DataObjectModelType,
    "Health",
    (ModelNode*) &iedModel_LDInst_IBRK1,
    (ModelNode*) &iedModel_LDInst_IBRK1_NamPlt,
    (ModelNode*) &iedModel_LDInst_IBRK1_Health_stVal,
    0
};

DataAttribute iedModel_LDInst_IBRK1_Health_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LDInst_IBRK1_Health,
    (ModelNode*) &iedModel_LDInst_IBRK1_Health_q,
    NULL,
    0,
    ST,
    ENUMERATED,
    0,
    NULL,
    0};

DataAttribute iedModel_LDInst_IBRK1_Health_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDInst_IBRK1_Health,
    (ModelNode*) &iedModel_LDInst_IBRK1_Health_t,
    NULL,
    0,
    ST,
    QUALITY,
    0,
    NULL,
    0};

DataAttribute iedModel_LDInst_IBRK1_Health_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDInst_IBRK1_Health,
    NULL,
    NULL,
    0,
    ST,
    TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LDInst_IBRK1_NamPlt = {
    DataObjectModelType,
    "NamPlt",
    (ModelNode*) &iedModel_LDInst_IBRK1,
    (ModelNode*) &iedModel_LDInst_IBRK1_U,
    (ModelNode*) &iedModel_LDInst_IBRK1_NamPlt_vendor,
    0
};

DataAttribute iedModel_LDInst_IBRK1_NamPlt_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &iedModel_LDInst_IBRK1_NamPlt,
    (ModelNode*) &iedModel_LDInst_IBRK1_NamPlt_swRev,
    NULL,
    0,
    DC,
    VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_LDInst_IBRK1_NamPlt_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &iedModel_LDInst_IBRK1_NamPlt,
    (ModelNode*) &iedModel_LDInst_IBRK1_NamPlt_d,
    NULL,
    0,
    DC,
    VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_LDInst_IBRK1_NamPlt_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &iedModel_LDInst_IBRK1_NamPlt,
    (ModelNode*) &iedModel_LDInst_IBRK1_NamPlt_configRev,
    NULL,
    0,
    DC,
    VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_LDInst_IBRK1_NamPlt_configRev = {
    DataAttributeModelType,
    "configRev",
    (ModelNode*) &iedModel_LDInst_IBRK1_NamPlt,
    NULL,
    NULL,
    0,
    DC,
    VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject iedModel_LDInst_IBRK1_U = {
    DataObjectModelType,
    "U",
    (ModelNode*) &iedModel_LDInst_IBRK1,
    NULL,
    (ModelNode*) &iedModel_LDInst_IBRK1_U_smpNum,
    0
};

DataAttribute iedModel_LDInst_IBRK1_U_smpNum = {
    DataAttributeModelType,
    "smpNum",
    (ModelNode*) &iedModel_LDInst_IBRK1_U,
    (ModelNode*) &iedModel_LDInst_IBRK1_U_model,
    NULL,
    0,
    ST,
    INT32U,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDInst_IBRK1_U_model = {
    DataAttributeModelType,
    "model",
    (ModelNode*) &iedModel_LDInst_IBRK1_U,
    (ModelNode*) &iedModel_LDInst_IBRK1_U_serNum,
    NULL,
    0,
    CF,
    VISIBLE_STRING_32,
    0,
    NULL,
    0};

DataAttribute iedModel_LDInst_IBRK1_U_serNum = {
    DataAttributeModelType,
    "serNum",
    (ModelNode*) &iedModel_LDInst_IBRK1_U,
    (ModelNode*) &iedModel_LDInst_IBRK1_U_outputs,
    NULL,
    0,
    CF,
    VISIBLE_STRING_32,
    0,
    NULL,
    0};

DataAttribute iedModel_LDInst_IBRK1_U_outputs = {
    DataAttributeModelType,
    "outputs",
    (ModelNode*) &iedModel_LDInst_IBRK1_U,
    (ModelNode*) &iedModel_LDInst_IBRK1_U_analogs,
    NULL,
    0,
    CO,
    GENERIC_BITSTRING,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDInst_IBRK1_U_analogs = {
    DataAttributeModelType,
    "analogs",
    (ModelNode*) &iedModel_LDInst_IBRK1_U,
    (ModelNode*) &iedModel_LDInst_IBRK1_U_contactInputs,
    (ModelNode*) &iedModel_LDInst_IBRK1_U_analogs_ac1,
    0,
    MX,
    CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute iedModel_LDInst_IBRK1_U_analogs_ac1 = {
    DataAttributeModelType,
    "ac1",
    (ModelNode*) &iedModel_LDInst_IBRK1_U_analogs,
    (ModelNode*) &iedModel_LDInst_IBRK1_U_analogs_ac2,
    NULL,
    0,
    MX,
    INT32U,
    0,
    NULL,
    0};

DataAttribute iedModel_LDInst_IBRK1_U_analogs_ac2 = {
    DataAttributeModelType,
    "ac2",
    (ModelNode*) &iedModel_LDInst_IBRK1_U_analogs,
    (ModelNode*) &iedModel_LDInst_IBRK1_U_analogs_ac3,
    NULL,
    0,
    MX,
    INT32U,
    0,
    NULL,
    0};

DataAttribute iedModel_LDInst_IBRK1_U_analogs_ac3 = {
    DataAttributeModelType,
    "ac3",
    (ModelNode*) &iedModel_LDInst_IBRK1_U_analogs,
    (ModelNode*) &iedModel_LDInst_IBRK1_U_analogs_ac4,
    NULL,
    0,
    MX,
    INT32U,
    0,
    NULL,
    0};

DataAttribute iedModel_LDInst_IBRK1_U_analogs_ac4 = {
    DataAttributeModelType,
    "ac4",
    (ModelNode*) &iedModel_LDInst_IBRK1_U_analogs,
    (ModelNode*) &iedModel_LDInst_IBRK1_U_analogs_ac5,
    NULL,
    0,
    MX,
    INT32U,
    0,
    NULL,
    0};

DataAttribute iedModel_LDInst_IBRK1_U_analogs_ac5 = {
    DataAttributeModelType,
    "ac5",
    (ModelNode*) &iedModel_LDInst_IBRK1_U_analogs,
    (ModelNode*) &iedModel_LDInst_IBRK1_U_analogs_ac6,
    NULL,
    0,
    MX,
    INT32U,
    0,
    NULL,
    0};

DataAttribute iedModel_LDInst_IBRK1_U_analogs_ac6 = {
    DataAttributeModelType,
    "ac6",
    (ModelNode*) &iedModel_LDInst_IBRK1_U_analogs,
    (ModelNode*) &iedModel_LDInst_IBRK1_U_analogs_ac7,
    NULL,
    0,
    MX,
    INT32U,
    0,
    NULL,
    0};

DataAttribute iedModel_LDInst_IBRK1_U_analogs_ac7 = {
    DataAttributeModelType,
    "ac7",
    (ModelNode*) &iedModel_LDInst_IBRK1_U_analogs,
    (ModelNode*) &iedModel_LDInst_IBRK1_U_analogs_ac8,
    NULL,
    0,
    MX,
    INT32U,
    0,
    NULL,
    0};

DataAttribute iedModel_LDInst_IBRK1_U_analogs_ac8 = {
    DataAttributeModelType,
    "ac8",
    (ModelNode*) &iedModel_LDInst_IBRK1_U_analogs,
    (ModelNode*) &iedModel_LDInst_IBRK1_U_analogs_dc1,
    NULL,
    0,
    MX,
    INT32U,
    0,
    NULL,
    0};

DataAttribute iedModel_LDInst_IBRK1_U_analogs_dc1 = {
    DataAttributeModelType,
    "dc1",
    (ModelNode*) &iedModel_LDInst_IBRK1_U_analogs,
    (ModelNode*) &iedModel_LDInst_IBRK1_U_analogs_dc2,
    NULL,
    0,
    MX,
    INT32U,
    0,
    NULL,
    0};

DataAttribute iedModel_LDInst_IBRK1_U_analogs_dc2 = {
    DataAttributeModelType,
    "dc2",
    (ModelNode*) &iedModel_LDInst_IBRK1_U_analogs,
    (ModelNode*) &iedModel_LDInst_IBRK1_U_analogs_dc3,
    NULL,
    0,
    MX,
    INT32U,
    0,
    NULL,
    0};

DataAttribute iedModel_LDInst_IBRK1_U_analogs_dc3 = {
    DataAttributeModelType,
    "dc3",
    (ModelNode*) &iedModel_LDInst_IBRK1_U_analogs,
    NULL,
    NULL,
    0,
    MX,
    INT32U,
    0,
    NULL,
    0};

DataAttribute iedModel_LDInst_IBRK1_U_contactInputs = {
    DataAttributeModelType,
    "contactInputs",
    (ModelNode*) &iedModel_LDInst_IBRK1_U,
    (ModelNode*) &iedModel_LDInst_IBRK1_U_sharedInputs,
    NULL,
    0,
    ST,
    GENERIC_BITSTRING,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDInst_IBRK1_U_sharedInputs = {
    DataAttributeModelType,
    "sharedInputs",
    (ModelNode*) &iedModel_LDInst_IBRK1_U,
    (ModelNode*) &iedModel_LDInst_IBRK1_U_outputMonitors,
    NULL,
    0,
    ST,
    GENERIC_BITSTRING,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDInst_IBRK1_U_outputMonitors = {
    DataAttributeModelType,
    "outputMonitors",
    (ModelNode*) &iedModel_LDInst_IBRK1_U,
    (ModelNode*) &iedModel_LDInst_IBRK1_U_diagnostics,
    NULL,
    0,
    ST,
    GENERIC_BITSTRING,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDInst_IBRK1_U_diagnostics = {
    DataAttributeModelType,
    "diagnostics",
    (ModelNode*) &iedModel_LDInst_IBRK1_U,
    (ModelNode*) &iedModel_LDInst_IBRK1_U_lnNs,
    (ModelNode*) &iedModel_LDInst_IBRK1_U_diagnostics_diagnosticFlags,
    0,
    ST,
    CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute iedModel_LDInst_IBRK1_U_diagnostics_diagnosticFlags = {
    DataAttributeModelType,
    "diagnosticFlags",
    (ModelNode*) &iedModel_LDInst_IBRK1_U_diagnostics,
    (ModelNode*) &iedModel_LDInst_IBRK1_U_diagnostics_adcTemp,
    NULL,
    0,
    ST,
    GENERIC_BITSTRING,
    0,
    NULL,
    0};

DataAttribute iedModel_LDInst_IBRK1_U_diagnostics_adcTemp = {
    DataAttributeModelType,
    "adcTemp",
    (ModelNode*) &iedModel_LDInst_IBRK1_U_diagnostics,
    (ModelNode*) &iedModel_LDInst_IBRK1_U_diagnostics_transceiverTemp,
    NULL,
    0,
    ST,
    INT16,
    0,
    NULL,
    0};

DataAttribute iedModel_LDInst_IBRK1_U_diagnostics_transceiverTemp = {
    DataAttributeModelType,
    "transceiverTemp",
    (ModelNode*) &iedModel_LDInst_IBRK1_U_diagnostics,
    (ModelNode*) &iedModel_LDInst_IBRK1_U_diagnostics_transceiverVolts,
    NULL,
    0,
    ST,
    INT16,
    0,
    NULL,
    0};

DataAttribute iedModel_LDInst_IBRK1_U_diagnostics_transceiverVolts = {
    DataAttributeModelType,
    "transceiverVolts",
    (ModelNode*) &iedModel_LDInst_IBRK1_U_diagnostics,
    (ModelNode*) &iedModel_LDInst_IBRK1_U_diagnostics_transceiverCurrent,
    NULL,
    0,
    ST,
    INT16,
    0,
    NULL,
    0};

DataAttribute iedModel_LDInst_IBRK1_U_diagnostics_transceiverCurrent = {
    DataAttributeModelType,
    "transceiverCurrent",
    (ModelNode*) &iedModel_LDInst_IBRK1_U_diagnostics,
    (ModelNode*) &iedModel_LDInst_IBRK1_U_diagnostics_transceiverTxPower,
    NULL,
    0,
    ST,
    INT16,
    0,
    NULL,
    0};

DataAttribute iedModel_LDInst_IBRK1_U_diagnostics_transceiverTxPower = {
    DataAttributeModelType,
    "transceiverTxPower",
    (ModelNode*) &iedModel_LDInst_IBRK1_U_diagnostics,
    (ModelNode*) &iedModel_LDInst_IBRK1_U_diagnostics_transceiverRxPower,
    NULL,
    0,
    ST,
    INT16,
    0,
    NULL,
    0};

DataAttribute iedModel_LDInst_IBRK1_U_diagnostics_transceiverRxPower = {
    DataAttributeModelType,
    "transceiverRxPower",
    (ModelNode*) &iedModel_LDInst_IBRK1_U_diagnostics,
    NULL,
    NULL,
    0,
    ST,
    INT16,
    0,
    NULL,
    0};

DataAttribute iedModel_LDInst_IBRK1_U_lnNs = {
    DataAttributeModelType,
    "lnNs",
    (ModelNode*) &iedModel_LDInst_IBRK1_U,
    NULL,
    NULL,
    0,
    EX,
    VISIBLE_STRING_255,
    0,
    NULL,
    0};






IedModel iedModel = {
    "IEDName",
    &iedModel_LDInst,
    &ds_LDInst_LLN0_F,
    NULL,
    NULL,
    NULL,
    initializeValues
};

static void
initializeValues()
{

iedModel_LDInst_LPHD1_PhyNam_vendor.mmsValue = MmsValue_newVisibleString("GE Multilin");

iedModel_LDInst_LPHD1_PhyNam_swRev.mmsValue = MmsValue_newVisibleString("5.601");
}
