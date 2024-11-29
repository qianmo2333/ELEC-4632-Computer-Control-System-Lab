/*
 * WaterTankSysControl2024_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "WaterTankSysControl2024".
 *
 * Model version              : 9.8
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Mon Nov  4 17:48:07 2024
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "WaterTankSysControl2024.h"

/* Block parameters (default storage) */
P_WaterTankSysControl2024_T WaterTankSysControl2024_P = {
  /* Variable: C_obs
   * Referenced by: '<S1>/Gain1'
   */
  { 0.0, 1.0 },

  /* Variable: G_obs
   * Referenced by: '<S1>/Gain2'
   */
  { 0.0, 1.0, -0.647893865721052, 1.6380251050111596 },

  /* Variable: Gcl_1
   * Referenced by: '<Root>/DC Gain  Compensation'
   */
  0.41726626469733519,

  /* Variable: H_obs
   * Referenced by: '<S1>/Gain'
   */
  { 0.025572996916508828, -0.0016074841347517577 },

  /* Variable: K
   * Referenced by: '<S1>/Gain3'
   */
  { -0.647893865721052, 1.6380251050111596 },

  /* Variable: L
   * Referenced by: '<S1>/Gain4'
   */
  { -6.5978145327321025, -4.199727740054688 },

  /* Variable: u_offset
   * Referenced by: '<Root>/Constant2'
   */
  2.5,

  /* Variable: y_offset
   * Referenced by:
   *   '<Root>/Constant'
   *   '<Root>/Constant3'
   */
  3.229229317843568,

  /* Mask Parameter: AnalogOutput1_FinalValue
   * Referenced by: '<S3>/Analog Output1'
   */
  0.0,

  /* Mask Parameter: AnalogOutput2_FinalValue
   * Referenced by: '<S3>/Analog Output2'
   */
  0.0,

  /* Mask Parameter: AnalogOutput1_InitialValue
   * Referenced by: '<S3>/Analog Output1'
   */
  0.0,

  /* Mask Parameter: AnalogOutput2_InitialValue
   * Referenced by: '<S3>/Analog Output2'
   */
  0.0,

  /* Mask Parameter: AnalogInput1_MaxMissedTicks
   * Referenced by: '<S3>/Analog Input1'
   */
  10.0,

  /* Mask Parameter: AnalogInput2_MaxMissedTicks
   * Referenced by: '<S3>/Analog Input2'
   */
  10.0,

  /* Mask Parameter: AnalogOutput1_MaxMissedTicks
   * Referenced by: '<S3>/Analog Output1'
   */
  10.0,

  /* Mask Parameter: AnalogOutput2_MaxMissedTicks
   * Referenced by: '<S3>/Analog Output2'
   */
  10.0,

  /* Mask Parameter: RepeatingSequenceStair1_OutValues
   * Referenced by: '<S2>/Vector'
   */
  { 0.7, 0.2, -0.5, 0.0 },

  /* Mask Parameter: AnalogInput1_YieldWhenWaiting
   * Referenced by: '<S3>/Analog Input1'
   */
  0.0,

  /* Mask Parameter: AnalogInput2_YieldWhenWaiting
   * Referenced by: '<S3>/Analog Input2'
   */
  0.0,

  /* Mask Parameter: AnalogOutput1_YieldWhenWaiting
   * Referenced by: '<S3>/Analog Output1'
   */
  0.0,

  /* Mask Parameter: AnalogOutput2_YieldWhenWaiting
   * Referenced by: '<S3>/Analog Output2'
   */
  0.0,

  /* Mask Parameter: AnalogInput1_Channels
   * Referenced by: '<S3>/Analog Input1'
   */
  0,

  /* Mask Parameter: AnalogInput2_Channels
   * Referenced by: '<S3>/Analog Input2'
   */
  1,

  /* Mask Parameter: AnalogOutput1_Channels
   * Referenced by: '<S3>/Analog Output1'
   */
  0,

  /* Mask Parameter: AnalogOutput2_Channels
   * Referenced by: '<S3>/Analog Output2'
   */
  1,

  /* Mask Parameter: AnalogInput1_RangeMode
   * Referenced by: '<S3>/Analog Input1'
   */
  0,

  /* Mask Parameter: AnalogInput2_RangeMode
   * Referenced by: '<S3>/Analog Input2'
   */
  0,

  /* Mask Parameter: AnalogOutput1_RangeMode
   * Referenced by: '<S3>/Analog Output1'
   */
  0,

  /* Mask Parameter: AnalogOutput2_RangeMode
   * Referenced by: '<S3>/Analog Output2'
   */
  0,

  /* Mask Parameter: AnalogInput1_VoltRange
   * Referenced by: '<S3>/Analog Input1'
   */
  0,

  /* Mask Parameter: AnalogInput2_VoltRange
   * Referenced by: '<S3>/Analog Input2'
   */
  0,

  /* Mask Parameter: AnalogOutput1_VoltRange
   * Referenced by: '<S3>/Analog Output1'
   */
  0,

  /* Mask Parameter: AnalogOutput2_VoltRange
   * Referenced by: '<S3>/Analog Output2'
   */
  0,

  /* Mask Parameter: LimitedCounter_uplimit
   * Referenced by: '<S6>/FixPt Switch'
   */
  3U,

  /* Expression: 0
   * Referenced by: '<Root>/Rate Transition1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S3>/Discrete FIR Filter1'
   */
  0.0,

  /* Expression: [0.2 0.2 0.2 0.2 0.2]
   * Referenced by: '<S3>/Discrete FIR Filter1'
   */
  { 0.2, 0.2, 0.2, 0.2, 0.2 },

  /* Expression: [0;0]
   * Referenced by: '<S1>/Delay'
   */
  { 0.0, 0.0 },

  /* Expression: 1
   * Referenced by: '<Root>/Activation Gain TANK#3'
   */
  1.0,

  /* Expression: 3.0
   * Referenced by: '<Root>/Saturation TANK#3'
   */
  3.0,

  /* Expression: 1.5
   * Referenced by: '<Root>/Saturation TANK#3'
   */
  1.5,

  /* Expression: 0
   * Referenced by: '<Root>/Activation Gain TANK#4'
   */
  0.0,

  /* Expression: 5
   * Referenced by: '<Root>/Saturation TANK#4'
   */
  5.0,

  /* Expression: 0
   * Referenced by: '<Root>/Saturation TANK#4'
   */
  0.0,

  /* Computed Parameter: Constant_Value
   * Referenced by: '<S6>/Constant'
   */
  0U,

  /* Computed Parameter: Output_InitialCondition
   * Referenced by: '<S4>/Output'
   */
  0U,

  /* Computed Parameter: FixPtConstant_Value
   * Referenced by: '<S5>/FixPt Constant'
   */
  1U
};
