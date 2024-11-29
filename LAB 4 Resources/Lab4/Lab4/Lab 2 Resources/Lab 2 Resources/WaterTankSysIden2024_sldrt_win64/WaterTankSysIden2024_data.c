/*
 * WaterTankSysIden2024_data.c
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

#include "WaterTankSysIden2024.h"

/* Block parameters (default storage) */
P_WaterTankSysIden2024_T WaterTankSysIden2024_P = {
  /* Mask Parameter: AnalogOutput1_FinalValue
   * Referenced by: '<S2>/Analog Output1'
   */
  0.0,

  /* Mask Parameter: AnalogOutput2_FinalValue
   * Referenced by: '<S2>/Analog Output2'
   */
  0.0,

  /* Mask Parameter: AnalogOutput1_InitialValue
   * Referenced by: '<S2>/Analog Output1'
   */
  0.0,

  /* Mask Parameter: AnalogOutput2_InitialValue
   * Referenced by: '<S2>/Analog Output2'
   */
  0.0,

  /* Mask Parameter: AnalogInput1_MaxMissedTicks
   * Referenced by: '<S2>/Analog Input1'
   */
  10.0,

  /* Mask Parameter: AnalogInput2_MaxMissedTicks
   * Referenced by: '<S2>/Analog Input2'
   */
  10.0,

  /* Mask Parameter: AnalogOutput1_MaxMissedTicks
   * Referenced by: '<S2>/Analog Output1'
   */
  10.0,

  /* Mask Parameter: AnalogOutput2_MaxMissedTicks
   * Referenced by: '<S2>/Analog Output2'
   */
  10.0,

  /* Mask Parameter: RepeatingSequenceStair_OutValues
   * Referenced by: '<S1>/Vector'
   */
  { -0.3, 0.2, 0.0 },

  /* Mask Parameter: AnalogInput1_YieldWhenWaiting
   * Referenced by: '<S2>/Analog Input1'
   */
  0.0,

  /* Mask Parameter: AnalogInput2_YieldWhenWaiting
   * Referenced by: '<S2>/Analog Input2'
   */
  0.0,

  /* Mask Parameter: AnalogOutput1_YieldWhenWaiting
   * Referenced by: '<S2>/Analog Output1'
   */
  0.0,

  /* Mask Parameter: AnalogOutput2_YieldWhenWaiting
   * Referenced by: '<S2>/Analog Output2'
   */
  0.0,

  /* Mask Parameter: AnalogInput1_Channels
   * Referenced by: '<S2>/Analog Input1'
   */
  0,

  /* Mask Parameter: AnalogInput2_Channels
   * Referenced by: '<S2>/Analog Input2'
   */
  1,

  /* Mask Parameter: AnalogOutput1_Channels
   * Referenced by: '<S2>/Analog Output1'
   */
  0,

  /* Mask Parameter: AnalogOutput2_Channels
   * Referenced by: '<S2>/Analog Output2'
   */
  1,

  /* Mask Parameter: AnalogInput1_RangeMode
   * Referenced by: '<S2>/Analog Input1'
   */
  0,

  /* Mask Parameter: AnalogInput2_RangeMode
   * Referenced by: '<S2>/Analog Input2'
   */
  0,

  /* Mask Parameter: AnalogOutput1_RangeMode
   * Referenced by: '<S2>/Analog Output1'
   */
  0,

  /* Mask Parameter: AnalogOutput2_RangeMode
   * Referenced by: '<S2>/Analog Output2'
   */
  0,

  /* Mask Parameter: AnalogInput1_VoltRange
   * Referenced by: '<S2>/Analog Input1'
   */
  0,

  /* Mask Parameter: AnalogInput2_VoltRange
   * Referenced by: '<S2>/Analog Input2'
   */
  0,

  /* Mask Parameter: AnalogOutput1_VoltRange
   * Referenced by: '<S2>/Analog Output1'
   */
  0,

  /* Mask Parameter: AnalogOutput2_VoltRange
   * Referenced by: '<S2>/Analog Output2'
   */
  0,

  /* Mask Parameter: LimitedCounter_uplimit
   * Referenced by: '<S5>/FixPt Switch'
   */
  2U,

  /* Expression: 2.5
   * Referenced by: '<Root>/Gain'
   */
  2.5,

  /* Expression: 0
   * Referenced by: '<S2>/Discrete FIR Filter1'
   */
  0.0,

  /* Expression: [0.2 0.2 0.2 0.2 0.2]
   * Referenced by: '<S2>/Discrete FIR Filter1'
   */
  { 0.2, 0.2, 0.2, 0.2, 0.2 },

  /* Expression: 2.5
   * Referenced by: '<Root>/u_offset'
   */
  2.5,

  /* Expression: 0
   * Referenced by: '<Root>/Rate Transition'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Step'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Step'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Step'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<Root>/Activation Gain TANK#1'
   */
  1.0,

  /* Expression: 3
   * Referenced by: '<Root>/Saturation TANK#1'
   */
  3.0,

  /* Expression: 0
   * Referenced by: '<Root>/Saturation TANK#1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Activation Gain TANK#2'
   */
  0.0,

  /* Expression: 5
   * Referenced by: '<Root>/Saturation TANK#2'
   */
  5.0,

  /* Expression: 0
   * Referenced by: '<Root>/Saturation TANK#2'
   */
  0.0,

  /* Computed Parameter: Constant_Value
   * Referenced by: '<S5>/Constant'
   */
  0U,

  /* Computed Parameter: ManualSwitch_CurrentSetting
   * Referenced by: '<Root>/Manual Switch'
   */
  1U,

  /* Computed Parameter: Output_InitialCondition
   * Referenced by: '<S3>/Output'
   */
  0U,

  /* Computed Parameter: FixPtConstant_Value
   * Referenced by: '<S4>/FixPt Constant'
   */
  1U
};
