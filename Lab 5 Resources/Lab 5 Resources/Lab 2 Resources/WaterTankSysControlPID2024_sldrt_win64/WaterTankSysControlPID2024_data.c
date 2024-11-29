/*
 * WaterTankSysControlPID2024_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "WaterTankSysControlPID2024".
 *
 * Model version              : 9.8
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Mon Nov 18 17:27:55 2024
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "WaterTankSysControlPID2024.h"

/* Block parameters (default storage) */
P_WaterTankSysControlPID2024_T WaterTankSysControlPID2024_P = {
  /* Variable: u_offset
   * Referenced by: '<Root>/Constant4'
   */
  2.5,

  /* Variable: y_offset
   * Referenced by:
   *   '<Root>/Constant1'
   *   '<Root>/Constant5'
   */
  2.7657708088871304,

  /* Mask Parameter: DiscretePIDController_D
   * Referenced by: '<S29>/Derivative Gain'
   */
  0.0,

  /* Mask Parameter: AnalogOutput1_FinalValue
   * Referenced by: '<S3>/Analog Output1'
   */
  0.0,

  /* Mask Parameter: AnalogOutput2_FinalValue
   * Referenced by: '<S3>/Analog Output2'
   */
  0.0,

  /* Mask Parameter: DiscretePIDController_I
   * Referenced by: '<S32>/Integral Gain'
   */
  0.029,

  /* Mask Parameter: DiscretePIDController_InitialConditionForFilter
   * Referenced by: '<S30>/Filter'
   */
  0.0,

  /* Mask Parameter: DiscretePIDController_InitialConditionForIntegrator
   * Referenced by: '<S35>/Integrator'
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

  /* Mask Parameter: DiscretePIDController_N
   * Referenced by: '<S38>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: RepeatingSequenceStair2_OutValues
   * Referenced by: '<S2>/Vector'
   */
  { 0.7, 0.2, -0.5, 0.0 },

  /* Mask Parameter: DiscretePIDController_P
   * Referenced by: '<S40>/Proportional Gain'
   */
  0.56,

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
   * Referenced by: '<S54>/FixPt Switch'
   */
  3U,

  /* Expression: 0
   * Referenced by: '<Root>/Rate Transition2'
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

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S35>/Integrator'
   */
  0.75,

  /* Computed Parameter: Filter_gainval
   * Referenced by: '<S30>/Filter'
   */
  0.75,

  /* Expression: 1
   * Referenced by: '<Root>/Activation Gain TANK#1'
   */
  1.0,

  /* Expression: 3
   * Referenced by: '<Root>/Saturation TANK#1'
   */
  3.0,

  /* Expression: 2
   * Referenced by: '<Root>/Saturation TANK#1'
   */
  2.0,

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
   * Referenced by: '<S54>/Constant'
   */
  0U,

  /* Computed Parameter: Output_InitialCondition
   * Referenced by: '<S52>/Output'
   */
  0U,

  /* Computed Parameter: FixPtConstant_Value
   * Referenced by: '<S53>/FixPt Constant'
   */
  1U
};
