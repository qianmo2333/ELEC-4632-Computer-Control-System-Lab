/*
 * WaterTankSysIden2024_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "WaterTankSysIden2024".
 *
 * Model version              : 9.3
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Mon Nov  4 15:20:41 2024
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(int32_T),
  sizeof(int64_T),
  sizeof(uint64_T),
  sizeof(uint64_T),
  sizeof(int64_T),
  sizeof(uint_T),
  sizeof(char_T),
  sizeof(uchar_T),
  sizeof(time_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "physical_connection",
  "int64_T",
  "uint64_T",
  "uint64_T",
  "int64_T",
  "uint_T",
  "char_T",
  "uchar_T",
  "time_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&WaterTankSysIden2024_B.OriginalOutput), 0, 0, 6 },

  { (char_T *)(&WaterTankSysIden2024_B.FixPtSwitch), 3, 0, 1 }
  ,

  { (char_T *)(&WaterTankSysIden2024_DW.DiscreteFIRFilter1_states[0]), 0, 0, 5 },

  { (char_T *)(&WaterTankSysIden2024_DW.AnalogInput1_PWORK), 11, 0, 6 },

  { (char_T *)(&WaterTankSysIden2024_DW.DiscreteFIRFilter1_circBuf), 6, 0, 1 },

  { (char_T *)(&WaterTankSysIden2024_DW.Output_DSTATE), 3, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  6U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&WaterTankSysIden2024_P.AnalogOutput1_FinalValue), 0, 0, 15 },

  { (char_T *)(&WaterTankSysIden2024_P.AnalogInput1_Channels), 6, 0, 12 },

  { (char_T *)(&WaterTankSysIden2024_P.LimitedCounter_uplimit), 3, 0, 1 },

  { (char_T *)(&WaterTankSysIden2024_P.Gain_Gain), 0, 0, 18 },

  { (char_T *)(&WaterTankSysIden2024_P.Constant_Value), 3, 0, 4 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  5U,
  rtPTransitions
};

/* [EOF] WaterTankSysIden2024_dt.h */
